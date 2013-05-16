/**************************************************************************
**                                                                        *
**  FILE        :  cstart.c                                               *
**                                                                        *
**  DESCRIPTION :                                                         *
**      The system startup code initializes the processor's registers     *
**      and the application C variables.                                  *
**                                                                        *
**  Copyright 1996-2010 Altium BV                                         *
**                                                                        *
**************************************************************************/

#include "cstart.h"                             /* include configuration */

#include <stdlib.h>
#include <stdbool.h>

#ifdef __CPU__
#include __SFRFILE__(__CPU__)
#endif

#pragma weak   exit
#pragma extern _Exit
#pragma profiling off                           /* prevent profiling information on cstart */
#pragma tradeoff 4                              /* preset tradeoff level (for size) */
#pragma runtime BCM                             /* disable runtime error checking for cstart */
#pragma nomisrac                                /* disable MISRA-C checking */

#if __USE_ARGC_ARGV
static char argcv[__ARGCV_BUFSIZE];
extern int _argcv( const char *, size_t );
#endif

/* linker definitions */
extern __far void _lc_ue_ustack[];      /* user stack end */
extern __far void _lc_ue_istack[];      /* interrupt stack end */
extern __far void _lc_u_int_tab[];      /* interrupt table */
extern __far void _lc_u_trap_tab[];     /* trap table */
extern __far void _SMALL_DATA_[];       /* centre of A0 addressable area */
extern __far void _LITERAL_DATA_[];     /* centre of A1 addressable area */
extern __far void _A8_DATA_[];          /* centre of A8 addressable area */
extern __far void _A9_DATA_[];          /* centre of A9 addressable area */

/* external functions */
extern void _c_init(void);              /* C initialization function */
extern void _call_init(void);           /* call a user function before main() */
extern void _endinit(void);             /* call a user function with protection switched off */

/* library references */
#pragma extern main
extern int main( int argc, char *argv[] );

/* prototype */
extern void inline _endinit_clear(void);
extern void inline _endinit_set  (void);

#if __PROF_ENABLE__
extern void __prof_init( void );
#endif

#if __CLOCKS_PER_SEC_INIT
static void setclockpersec( void );
extern unsigned long long setfoschz( unsigned long long );
#endif

/*********************************************************************************
 * _reset() - reset vector
 *********************************************************************************/
#pragma section code libc.reset

void _START( void )
{

        /* temporarily switch off the workaround for si-bug cpu_tc065,
           this can safely be done, since this function is not called
           normally anyhow
        */
        __asm(".if\t@DEF('__CPU_TC065__')\n$CPU_TC065\tOFF\n\t.endif" );
        
        __asm("j\t__init_sp");

        __asm(".if\t@DEF('__CPU_TC065__')\n$CPU_TC065\tON\n\t.endif" );

        /*
         * Set default Boot Configuration Value
         */
#ifndef __EBU_BOOTCFG_VALUE
#  define __EBU_BOOTCFG_VALUE  0x800C
#endif

        /*
         * Set address for the Boot Configuration Value
         * to 'Boot memory Offset Address + alignment'
         */
#if     !(__EBU_BOOTCFG_VALUE & 0x1)
        /*
         * Address Alignment is off
         */
        __asm(".align\t4");
#else
        /*                        
         * Address Alignment is on and 16 bit wide memory
         */
#if     ( !(__EBU_BOOTCFG_VALUE & 0x8000) )
        __asm(".align\t8");
#else
        /*                        
         * Address Alignment is on and 32 bit wide memory
         */
        __asm(".align\t16");
#endif
#endif                
        __asm(".word\t%0"::"i"(__EBU_BOOTCFG_VALUE));

        /* add a nop if necessary to avoid a warning by the assembler
           actually this code will never be reached
        */
        __asm(".if\t@DEF('__CPU_TC048__')\n\tnop\n\t.endif" );
}

/*********************************************************************************
 * _cstart() - initialize stackpointer
 *********************************************************************************/
#pragma section code restore

void __init_sp( void )
{
        /* The initialization of the stackpointer is done in a seperate function, 
           because it must be executed in a function which has no stack use.
           
           When a function uses a stack it will be updated at the start of the 
           function. In this function, however, the stackpointer has an irrelevant
           value at the start of the function. A starting value for the stackpointer
           is determined and written in this function. The update to the 
           stackpointer at the start of the function would therefore be undone.
         */
         
        /* 
         * CPU_TC.033 workaround:
         * The stack pointers are aligned to quad-word boundary to workaround these 
         * functional problems CPU_TC.033.
         * Also the C compiler workaround for the appropriate CPU function problem
         * need to be enabled with --silicon-bug=cpu-tc033, to align circular
         * buffers on a quad-word boundary and to size all stack frames to an integral 
         * number of quad-words.
         */
#if      __CPU_TC033_INITIAL__
# define STACK_ALIGN    0xfffffff0
#else
# define STACK_ALIGN    0xfffffff8
#endif

        /* 
         * Load user stack pointer.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if  __USP_INIT
        unsigned int sp = (unsigned int)(_lc_ue_ustack) & STACK_ALIGN;
        __asm("mov.a\tsp,%0"::"d"(sp));
#endif
        __asm("j\t_start");
}

/*********************************************************************************
 * _cstart() - startup code
 *********************************************************************************/

void _start( void )
{
        /* Do a dsync before changing any of the csfr values, thus any previous
         * background state gets flushed first. Required for applications that jump
         * to the reset address.
         */
        __dsync();
        
        /* Set the PSW to its reset value in case of a warm start */
#if __USER_STACK
        __mtcr(PSW, 0x00000980);        /* clear PSW.IS */
#else
        __mtcr(PSW, 0x00000b80);
#endif

        /* Set the PCXS and PCXO to its reset value in case of a warm start */
        unsigned int pcxi = __mfcr(PCXI);
        pcxi &= 0xfff00000;
        __mtcr(PCXI, pcxi);

        /*
         * Clear the ENDINIT bit in the WDT_CON0 register in order
         * to disable the write-protection for registers protected 
         * via the EndInit feature (for example: WDT_CON1).
         */
        _endinit_clear();
        
        /*
         * Disable the Watchdog if requested. Watchdog is enabled by default.
         * The Watchdog is disabled after ENDINIT is set by _endinit_set().
         */       
#if __WATCHDOG_DISABLE
        WDT_CON1.U |= 0x8;
        _endinit_set();
        _endinit_clear();
#endif

        /*
         * PMI_TC.003 workaround:
         * The TLB-A and TLB-B mappings are set to a page size of 16KB.
         */
#if __PMI_TC003_INITIAL__  && defined MMU_CON
        unsigned int mmu_con = __mfcr(MMU_CON);
        mmu_con &= 0xffffffe1;      /* clear SZA and SZB */
        mmu_con |= 0x00000014;      /* set SZA=SZB=16k   */       
        __mtcr(MMU_CON, mmu_con);
#endif

        /*
         * Load Base Address of Trap Vector Table.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if __BTV_INIT
        __mtcr(BTV,  (unsigned int)_lc_u_trap_tab);
#endif

        /*
         * Load Base Address of Interrupt Vector Table.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if __BIV_INIT
        __mtcr(BIV, (unsigned int)(_lc_u_int_tab));
#endif

        /*
         * Load interupt stack pointer.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if __ISP_INIT
        unsigned int isp = (unsigned int)(_lc_ue_istack) & STACK_ALIGN;
        __mtcr(ISP, isp);
#endif
                                                          
        /*
         * PMU/PMI configuration.
         */
#if defined PMI_CON0 && defined __PMI_CON0_VALUE
        if(__PMI_CON0_INIT)  PMI_CON0.U = __PMI_CON0_VALUE;        
#endif
#if defined PMI_CON1 && defined __PMI_CON1_VALUE
        if(__PMI_CON1_INIT)  PMI_CON1.U = __PMI_CON1_VALUE;        
#endif  
#if     defined PMI_CON2 && defined __PMI_CON2_VALUE && \
        (  defined _REGTC1337_H || defined _REGTC1367_H || defined _REGTC1387_H || defined _REGTC1728_H \
        || defined _REGTC1746_H || defined _REGTC1747_H || defined _REGTC1768_H || defined _REGTC1782_H \
        || defined _REGTC1784_H || defined _REGTC1184_H || defined _REGTC1797_H || defined _REGTC1197_H \
        || defined _REGTC1734_H || defined _REGTC1767_H || defined _REGTC1736_H || defined _REGTC1732_H \
        || defined _REGTC1738_H || defined _REGTC1167_H || defined _REGTC1735_H || defined _REGTC1724_H )
        if(__PMI_CON2_INIT)  PMI_CON2.U = __PMI_CON2_VALUE;        
#endif
        
#if defined PMU_EIFCON && defined __PMU_EIFCON_VALUE
        if(__PMU_EIFCON_INIT)  PMU_EIFCON.U = __PMU_EIFCON_VALUE;
#endif

        /*
         * DMI configuration.
         */
#if     defined DMI_CON && defined __DMI_CON_VALUE && \
        (  defined _REGTC1167_H || defined _REGTC1197_H || defined _REGTC1337_H || defined _REGTC1367_H \
        || defined _REGTC1387_H || defined _REGTC1728_H || defined _REGTC1734_H || defined _REGTC1738_H \
        || defined _REGTC1746_H || defined _REGTC1747_H || defined _REGTC1767_H || defined _REGTC1768_H \
        || defined _REGTC1782_H || defined _REGTC1784_H || defined _REGTC1184_H || defined _REGTC1797_H \
        || defined _REGTC1724_H )
        if(__DMI_CON_INIT)  DMI_CON.U = __DMI_CON_VALUE;        
#endif
        
        /*
         * Data cache control (Reset 0H).
         * CPU_TC013 workaround:
         * The 16KB D-Cache is enabled to workaround
         * the CPU_TC013 functional problem.     
         * NOTE: Setting the D-Cache size must be done at the
         *       very beginning of the startup code.
         */
#if defined  DMU_CON
#  if __CPU_TC013_INITIAL__ 
        DMU_CON.U = 0x1;
#  endif
#endif

        /*
         * Bus configuration EBU_CLC within endinit.
         */
#  if defined EBU_CLC && defined __EBU_CLC_VALUE
        if(__EBU_CLC_INIT)  EBU_CLC.U = __EBU_CLC_VALUE;
#  endif

        /*
         *      Setting up the PLL after Reset.
         *
         *      After reset, the system clock will be running at the VCO
         *      base frequency devided by a factor KDIV. To set up the PLL
         *      ater resert, next action must be executed.
         */
#if defined PLL_CLC && defined __PLL_CLC_VALUE
#if     __PLL_CLC_INIT
#if     ( defined _REGTC11IB_H )
#define __PLLBYP        PLL1_BP
#define __LOCK          PLL1_LOCK
        if ( PLL_CLC.B.__PLLBYP == 0 )
        {
                PLL_CLC.U = __PLL_CLC_VALUE;
                while( PLL_CLC.B.__LOCK==0);                      /* Wait until the PLL becomes locked */
        }
#else
#define __PLL_CLC_SYSFS_VALUE   ((__PLL_CLC_VALUE>>2)&0x1)
#define __PLL_CLC_VCOBYP_VALUE  ((__PLL_CLC_VALUE>>5)&0x1)
#define __PLL_CLC_VCOSEL_VALUE  ((__PLL_CLC_VALUE>>6)&0x3)
#define __PLL_CLC_KDIV_VALUE    ((__PLL_CLC_VALUE>>8)&0xf)
#define __PLL_CLC_PDIV_VALUE    ((__PLL_CLC_VALUE>>13)&0x3)
#define __PLL_CLC_NDIV_VALUE    ((__PLL_CLC_VALUE>>16)&0x7f)
        if ( PLL_CLC.B.BYPPIN == 0 )
        {
#if     ( defined _REGTC1100_H || defined _REGTC1115_H || defined _REGTC1130_H )
                while (OSC_CON.B.OSCR==1);                      /* Wait until the oscillator is running */
#else
                while (OSC_CON.B.OSCR==0);                      /* Wait until the oscillator is running */
#endif
                PLL_CLC.B.VCOBYP = 1;                           /* Enabled the VCO Bypass Mode */
                PLL_CLC.B.VCOSEL = __PLL_CLC_VCOSEL_VALUE;      /* Select the VCO band */
                PLL_CLC.B.PDIV = __PLL_CLC_PDIV_VALUE;
                PLL_CLC.B.KDIV = __PLL_CLC_KDIV_VALUE;
                PLL_CLC.B.NDIV = __PLL_CLC_NDIV_VALUE;
#if __PLL_CLC_VCOBYP_VALUE==0
                PLL_CLC.B.OSCDISC = 0;                          /* Connect the oscillator to the PLL */
                while( PLL_CLC.B.LOCK==0);                      /* Wait until the PLL becomes locked */
                PLL_CLC.B.VCOBYP = 0;                           /* Disabled the VCO Bypass Mode */
#endif
        }
#if     ( defined _REGTC1100_H || defined _REGTC1115_H  || defined _REGTC1130_H )
        PLL_CLC.B.SYSFSL = __PLL_CLC_SYSFS_VALUE;                /* System frequency select */
#else
#if     (  defined _REGTC1762_H || defined _REGTC1764_H || defined _REGTC1766B_H || defined _REGTC1161_H \
        || defined _REGTC1162_H || defined _REGTC1163_H || defined _REGTC1164_H || defined _REGTC1165_H \
        || defined _REGTC1166_H )
        PLL_CLC.B.RSV = __PLL_CLC_SYSFS_VALUE;                  /* System frequency select */
#else
        PLL_CLC.B.SYSFS = __PLL_CLC_SYSFS_VALUE;                /* System frequency select */
#endif
#endif
#endif
#endif
#endif

        /*
         * System Oscillator configuration
         */
#if defined SCU_OSCCON && defined __SCU_OSCCON_VALUE
#if __SCU_OSCCON_INIT
        SCU_OSCCON.U=__SCU_OSCCON_VALUE;
        
        while(SCU_OSCCON.B.PLLLV==0);           /* Oscillator not too low */
        while(SCU_OSCCON.B.PLLHV==0);           /* Oscillator not too high */
#endif
#endif

        /*
         * Configure PLL Prescaler Mode.
         */
#if defined SCU_PLLCON1 && defined __SCU_PLLCON1_VALUE
#if __SCU_PLLCON1_INIT
#define __SCU_PLLCON1__K1DIV_VALUE      ((__SCU_PLLCON1_VALUE>>16)&0x3f)
        SCU_PLLCON1.B.K1DIV=__SCU_PLLCON1__K1DIV_VALUE;
        while(SCU_PLLSTAT.B.K1RDY==0);          /* Wait until K1-Divider is ready to operate */
#endif
#endif

#if defined SCU_PLLCON0 && defined __SCU_PLLCON0_VALUE
#if     __SCU_PLLCON0_INIT
        SCU_PLLCON0.B.VCOBYP=1;                 /* Enabled the VCO Bypass Mode */
        while(SCU_PLLSTAT.B.VCOBYST==0);        /* Wait until prescaler mode is entered */

#define __SCU_PLLCON0__VCOPWD_VALUE     ((__SCU_PLLCON0_VALUE>>1)&0x1)
#define __SCU_PLLCON0__NDIV_VALUE       ((__SCU_PLLCON0_VALUE>>9)&0x7f)
#define __SCU_PLLCON0__PDIV_VALUE       ((__SCU_PLLCON0_VALUE>>24)&0xf)
        SCU_PLLCON0.B.PDIV=__SCU_PLLCON0__PDIV_VALUE;
        SCU_PLLCON0.B.NDIV=__SCU_PLLCON0__NDIV_VALUE;
        SCU_PLLCON0.B.VCOPWD=__SCU_PLLCON0__VCOPWD_VALUE; /* power down VCO */

#if __SCU_PLLCON0__VCOPWD_VALUE==0
        /*
         * Configure PLL normal mode.
         */
        SCU_PLLCON0.B.CLRFINDIS=1;              /* Connect VCO to the oscillator */
        while(SCU_PLLSTAT.B.FINDIS==1);         /* Wait until oscillator is connected to the VCO */
        SCU_PLLCON0.B.RESLD=1;                  /* Restart VCO lock detection */
        while(SCU_PLLSTAT.B.VCOLOCK==0);        /* Wait until the VCO becomes locked */
        SCU_PLLCON0.B.VCOBYP=0;                 /* Disable the VCO Bypass Mode */
        while(SCU_PLLSTAT.B.VCOBYST==1);        /* Wait until normal mode is entered */
#endif
#endif
#endif

#if defined SCU_PLLCON1 && defined __SCU_PLLCON1_VALUE
#if __SCU_PLLCON1_INIT
#define __SCU_PLLCON1__K2DIV_VALUE      ((__SCU_PLLCON1_VALUE>>0)&0x3f)
        SCU_PLLCON1.B.K2DIV=__SCU_PLLCON1__K2DIV_VALUE;
#endif
#endif

        /*
         * Configure system clock register.
         */
#if defined STM_CLC && defined __STM_CLC_VALUE
        if(__STM_CLC_INIT)  STM_CLC.U = __STM_CLC_VALUE;        
#endif
        
        /*
         * Set the ENDINIT bit in the WDT_CON0 register again
         * to enable the write-protection and to prevent a time-out. 
         */
        _endinit_set();
        
        /*
         * Initialize Bus configuration registers:
         * Set register-values according to define's created by the GUI
         * 
         * The recommended sequence of setting registers is as follows:
         * 1.EBUCON
         * 2.All other EBU registers except SDRAM specific registers
         * 3.SDRMCON0
         * 4.SDRMMOD0
         * 5.SDRMREF0
         * 6.SDRMCON1
         * 7.SDRMMOD1
         * 8.SDRMREF1
         */
#if defined EBU_CON && defined __EBU_CON_VALUE
        if(__EBU_CON_INIT)  EBU_CON.U = __EBU_CON_VALUE;
#endif
#if defined EBU_ADDRSEL0 && defined __EBU_ADDRSEL0_VALUE
        if(__EBU_ADDRSEL0_INIT)  EBU_ADDRSEL0.U = __EBU_ADDRSEL0_VALUE;
#endif
#if defined EBU_ADDRSEL1 && defined __EBU_ADDRSEL1_VALUE
        if(__EBU_ADDRSEL1_INIT)  EBU_ADDRSEL1.U = __EBU_ADDRSEL1_VALUE;
#endif
#if defined EBU_ADDRSEL2 && defined __EBU_ADDRSEL2_VALUE
        if(__EBU_ADDRSEL2_INIT)  EBU_ADDRSEL2.U = __EBU_ADDRSEL2_VALUE;
#endif
#if defined EBU_ADDRSEL3 && defined __EBU_ADDRSEL3_VALUE
        if(__EBU_ADDRSEL3_INIT)  EBU_ADDRSEL3.U = __EBU_ADDRSEL3_VALUE;
#endif
#if defined EBU_ADDRSEL4 && defined __EBU_ADDRSEL4_VALUE
        if(__EBU_ADDRSEL4_INIT)  EBU_ADDRSEL4.U = __EBU_ADDRSEL4_VALUE;
#endif
#if defined EBU_ADDRSEL5 && defined __EBU_ADDRSEL5_VALUE
        if(__EBU_ADDRSEL5_INIT)  EBU_ADDRSEL5.U = __EBU_ADDRSEL5_VALUE;
#endif
#if defined EBU_ADDRSEL6 && defined __EBU_ADDRSEL6_VALUE
        if(__EBU_ADDRSEL6_INIT)  EBU_ADDRSEL6.U = __EBU_ADDRSEL6_VALUE;
#endif
#if defined EBU_BFCON && defined __EBU_BFCON_VALUE
        if(__EBU_BFCON_INIT)  EBU_BFCON.U = __EBU_BFCON_VALUE;
#endif
#if defined EBU_BUSAP0 && defined __EBU_BUSAP0_VALUE
        if(__EBU_BUSAP0_INIT)  EBU_BUSAP0.U = __EBU_BUSAP0_VALUE;
#endif
#if defined EBU_BUSAP1 && defined __EBU_BUSAP1_VALUE
        if(__EBU_BUSAP1_INIT)  EBU_BUSAP1.U = __EBU_BUSAP1_VALUE;
#endif
#if defined EBU_BUSAP2 && defined __EBU_BUSAP2_VALUE
        if(__EBU_BUSAP2_INIT)  EBU_BUSAP2.U = __EBU_BUSAP2_VALUE;
#endif
#if defined EBU_BUSAP3 && defined __EBU_BUSAP3_VALUE
        if(__EBU_BUSAP3_INIT)  EBU_BUSAP3.U = __EBU_BUSAP3_VALUE;
#endif
#if defined EBU_BUSAP4 && defined __EBU_BUSAP4_VALUE
        if(__EBU_BUSAP4_INIT)  EBU_BUSAP4.U = __EBU_BUSAP4_VALUE;
#endif
#if defined EBU_BUSAP5 && defined __EBU_BUSAP5_VALUE
        if(__EBU_BUSAP5_INIT)  EBU_BUSAP5.U = __EBU_BUSAP5_VALUE;
#endif
#if defined EBU_BUSAP6 && defined __EBU_BUSAP6_VALUE
        if(__EBU_BUSAP6_INIT)  EBU_BUSAP6.U = __EBU_BUSAP6_VALUE;
#endif
#if defined EBU_BUSCON0 && defined __EBU_BUSCON0_VALUE
        if(__EBU_BUSCON0_INIT)  EBU_BUSCON0.U = __EBU_BUSCON0_VALUE;
#endif
#if defined EBU_BUSCON1 && defined __EBU_BUSCON1_VALUE
        if(__EBU_BUSCON1_INIT)  EBU_BUSCON1.U = __EBU_BUSCON1_VALUE;
#endif
#if defined EBU_BUSCON2 && defined __EBU_BUSCON2_VALUE
        if(__EBU_BUSCON2_INIT)  EBU_BUSCON2.U = __EBU_BUSCON2_VALUE;
#endif
#if defined EBU_BUSCON3 && defined __EBU_BUSCON3_VALUE
        if(__EBU_BUSCON3_INIT)  EBU_BUSCON3.U = __EBU_BUSCON3_VALUE;
#endif
#if defined EBU_BUSCON4 && defined __EBU_BUSCON4_VALUE
        if(__EBU_BUSCON4_INIT)  EBU_BUSCON4.U = __EBU_BUSCON4_VALUE;
#endif
#if defined EBU_BUSCON5 && defined __EBU_BUSCON5_VALUE
        if(__EBU_BUSCON5_INIT)  EBU_BUSCON5.U = __EBU_BUSCON5_VALUE;
#endif
#if defined EBU_BUSCON6 && defined __EBU_BUSCON6_VALUE
        if(__EBU_BUSCON6_INIT)  EBU_BUSCON6.U = __EBU_BUSCON6_VALUE;
#endif
#if defined EBU_EMUAS && defined __EBU_EMUAS_VALUE
        if(__EBU_EMUAS_INIT)  EBU_EMUAS.U = __EBU_EMUAS_VALUE;
#endif
#if defined EBU_EMUBAP && defined __EBU_EMUBAP_VALUE
        if(__EBU_EMUBAP_INIT)  EBU_EMUBAP.U = __EBU_EMUBAP_VALUE;
#endif
#if defined EBU_EMUBC && defined __EBU_EMUBC_VALUE
        if(__EBU_EMUBC_INIT)  EBU_EMUBC.U = __EBU_EMUBC_VALUE;
#endif
#if defined EBU_EMUCON && defined __EBU_EMUCON_VALUE
        if(__EBU_EMUCON_INIT)  EBU_EMUCON.U = __EBU_EMUCON_VALUE;
#endif
#if defined EBU_EMUOVL && defined __EBU_EMUOVL_VALUE
        if(__EBU_EMUOVL_INIT)  EBU_EMUOVL.U = __EBU_EMUOVL_VALUE;
#endif
#if defined EBU_SDRMCON0 && defined __EBU_SDRMCON0_VALUE
        if(__EBU_SDRMCON0_INIT)  EBU_SDRMCON0.U = __EBU_SDRMCON0_VALUE;
#endif
#if defined EBU_SDRMOD0 && defined __EBU_SDRMOD0_VALUE
        if(__EBU_SDRMOD0_INIT)  EBU_SDRMOD0.U = __EBU_SDRMOD0_VALUE;
#endif
#if defined EBU_SDRMREF0 && defined __EBU_SDRMREF0_VALUE
        if(__EBU_SDRMREF0_INIT)  EBU_SDRMREF0.U = __EBU_SDRMREF0_VALUE;
#endif
#if defined EBU_SDRMCON1 && defined __EBU_SDRMCON1_VALUE
        if(__EBU_SDRMCON1_INIT)  EBU_SDRMCON1.U = __EBU_SDRMCON1_VALUE;
#endif
#if defined EBU_SDRMOD1 && defined __EBU_SDRMOD1_VALUE
        if(__EBU_SDRMOD1_INIT)  EBU_SDRMOD1.U = __EBU_SDRMOD1_VALUE;
#endif
#if defined EBU_SDRMREF1 && defined __EBU_SDRMREF1_VALUE
        if(__EBU_SDRMREF1_INIT)  EBU_SDRMREF1.U = __EBU_SDRMREF1_VALUE;
#endif
#if defined CBS_MCDBBS && defined __CBS_MCDBBS_VALUE
        if(__CBS_MCDBBS_INIT)  CBS_MCDBBS .U = __CBS_MCDBBS_VALUE;
#endif
#if defined SBCU_CON && defined __SBCU_CON_VALUE
        if(__SBCU_CON_INIT)  SBCU_CON.U = __SBCU_CON_VALUE;
#endif
#if defined EBU_BUSRAP1 && defined __EBU_BUSRAP1_VALUE
        if(__EBU_BUSRAP1_INIT)  EBU_BUSRAP1.U = __EBU_BUSRAP1_VALUE;
#endif
#if defined EBU_BUSRAP0 && defined __EBU_BUSRAP0_VALUE
        if(__EBU_BUSRAP0_INIT)  EBU_BUSRAP0.U = __EBU_BUSRAP0_VALUE;
#endif
#if defined EBU_BUSRAP2 && defined __EBU_BUSRAP2_VALUE
        if(__EBU_BUSRAP2_INIT)  EBU_BUSRAP2.U = __EBU_BUSRAP2_VALUE;
#endif
#if defined EBU_BUSRAP3 && defined __EBU_BUSRAP3_VALUE
        if(__EBU_BUSRAP3_INIT)  EBU_BUSRAP3.U = __EBU_BUSRAP3_VALUE;
#endif
#if defined EBU_BUSRCON0 && defined __EBU_BUSRCON0_VALUE
        if(__EBU_BUSRCON0_INIT)  EBU_BUSRCON0.U = __EBU_BUSRCON0_VALUE;
#endif
#if defined EBU_BUSRCON1 && defined __EBU_BUSRCON1_VALUE
        if(__EBU_BUSRCON1_INIT)  EBU_BUSRCON1.U = __EBU_BUSRCON1_VALUE;
#endif
#if defined EBU_BUSRCON2 && defined __EBU_BUSRCON2_VALUE
        if(__EBU_BUSRCON2_INIT)  EBU_BUSRCON2.U = __EBU_BUSRCON2_VALUE;
#endif
#if defined EBU_BUSRCON3 && defined __EBU_BUSRCON3_VALUE
        if(__EBU_BUSRCON3_INIT)  EBU_BUSRCON3.U = __EBU_BUSRCON3_VALUE;
#endif
#if defined EBU_BUSWAP0 && defined __EBU_BUSWAP0_VALUE
        if(__EBU_BUSWAP0_INIT)  EBU_BUSWAP0.U = __EBU_BUSWAP0_VALUE;
#endif
#if defined EBU_BUSWAP1 && defined __EBU_BUSWAP1_VALUE
        if(__EBU_BUSWAP1_INIT)  EBU_BUSWAP1.U = __EBU_BUSWAP1_VALUE;
#endif
#if defined EBU_BUSWAP2 && defined __EBU_BUSWAP2_VALUE
        if(__EBU_BUSWAP2_INIT)  EBU_BUSWAP2.U = __EBU_BUSWAP2_VALUE;
#endif
#if defined EBU_BUSWAP3 && defined __EBU_BUSWAP3_VALUE
        if(__EBU_BUSWAP3_INIT)  EBU_BUSWAP3.U = __EBU_BUSWAP3_VALUE;
#endif
#if defined EBU_BUSWCON0 && defined __EBU_BUSWCON0_VALUE
        if(__EBU_BUSWCON0_INIT)  EBU_BUSWCON0.U = __EBU_BUSWCON0_VALUE;
#endif
#if defined EBU_BUSWCON1 && defined __EBU_BUSWCON1_VALUE
        if(__EBU_BUSWCON1_INIT)  EBU_BUSWCON1.U = __EBU_BUSWCON1_VALUE;
#endif
#if defined EBU_BUSWCON2 && defined __EBU_BUSWCON2_VALUE
        if(__EBU_BUSWCON2_INIT)  EBU_BUSWCON2.U = __EBU_BUSWCON2_VALUE;
#endif
#if defined EBU_BUSWCON3 && defined __EBU_BUSWCON3_VALUE
        if(__EBU_BUSWCON3_INIT)  EBU_BUSWCON3.U = __EBU_BUSWCON3_VALUE;
#endif
#if defined EBU_EXTBOOT && defined __EBU_EXTBOOT_VALUE
        if(__EBU_EXTBOOT_INIT)  EBU_EXTBOOT.U = __EBU_EXTBOOT_VALUE;
#endif
#if defined EBU_MODCON && defined __EBU_MODCON_VALUE
        if(__EBU_MODCON_INIT)  EBU_MODCON.U = __EBU_MODCON_VALUE;
#endif
#if defined EBU_DDRNCON && defined __EBU_DDRNCON_VALUE
        if(__EBU_DDRNCON_INIT)  EBU_DDRNCON.U = __EBU_DDRNCON_VALUE;
#endif
#if defined EBU_DDRNMOD && defined __EBU_DDRNMOD_VALUE
        if(__EBU_DDRNMOD_INIT)  EBU_DDRNMOD.U = __EBU_DDRNMOD_VALUE;
#endif
#if defined EBU_DDRNMOD2 && defined __EBU_DDRNMOD2_VALUE
        if(__EBU_DDRNMOD2_INIT)  EBU_DDRNMOD2.U = __EBU_DDRNMOD2_VALUE;
#endif
#if defined EBU_DDRNPRLD && defined __EBU_DDRNPRLD_VALUE
        if(__EBU_DDRNPRLD_INIT)  EBU_DDRNPRLD.U = __EBU_DDRNPRLD_VALUE;
#endif
#if defined EBU_DDRNTAG0 && defined __EBU_DDRNTAG0_VALUE
        if(__EBU_DDRNTAG0_INIT)  EBU_DDRNTAG0.U = __EBU_DDRNTAG0_VALUE;
#endif
#if defined EBU_DDRNTAG1 && defined __EBU_DDRNTAG1_VALUE
        if(__EBU_DDRNTAG1_INIT)  EBU_DDRNTAG1.U = __EBU_DDRNTAG1_VALUE;
#endif
#if defined EBU_DDRNTAG2 && defined __EBU_DDRNTAG2_VALUE
        if(__EBU_DDRNTAG2_INIT)  EBU_DDRNTAG2.U = __EBU_DDRNTAG2_VALUE;
#endif
#if defined EBU_DDRNTAG3 && defined __EBU_DDRNTAG3_VALUE
        if(__EBU_DDRNTAG3_INIT)  EBU_DDRNTAG3.U = __EBU_DDRNTAG3_VALUE;
#endif
#if defined EBU_DLLCON && defined __EBU_DLLCON_VALUE
        if(__EBU_DLLCON_INIT)  EBU_DLLCON.U = __EBU_DLLCON_VALUE;
#endif
#if defined EBU_SDRMCON && defined __EBU_SDRMCON_VALUE
        if(__EBU_SDRMCON_INIT)  EBU_SDRMCON.U = __EBU_SDRMCON_VALUE;
#endif
#if defined EBU_SDRMOD && defined __EBU_SDRMOD_VALUE
        if(__EBU_SDRMOD_INIT)  EBU_SDRMOD.U = __EBU_SDRMOD_VALUE;
#endif
#if defined EBU_SDRMREF && defined __EBU_SDRMREF_VALUE
        if(__EBU_SDRMREF_INIT)  EBU_SDRMREF.U = __EBU_SDRMREF_VALUE;
#endif
#if defined EBU_SDRSTAT && defined __EBU_SDRSTAT_VALUE
        if(__EBU_SDRSTAT_INIT)  EBU_SDRSTAT.U = __EBU_SDRSTAT_VALUE;
#endif

        /*
         * Inititialize global address registers a0/a1 to support
         * __a0/__a1 storage qualifiers of the C compiler.
         */
#if __A0A1_INIT
        void * a0 = _SMALL_DATA_;        
        __asm( "mov.aa\ta0,%0"::"a"(a0) );

        void * a1 = _LITERAL_DATA_;        
        __asm( "mov.aa\ta1,%0"::"a"(a1) );
#endif

        /*
         * Inititialize global address registers a8/a9 to support
         * __a8/__a9 storage qualifiers of the C compiler. A8 and A9
         * are reserved for OS use, or for application use in cases 
         * where the application ans OS are tightly coupled.
         */
#if __A8A9_INIT
        void * a8 = _A8_DATA_;        
        __asm( "mov.aa\ta8,%0"::"a"(a8) );

        void * a9 = _A9_DATA_;        
        __asm( "mov.aa\ta9,%0"::"a"(a9) );
#endif
        
        /* Setup the context save area linked list. */
#if __CSA_INIT
        
        // Still To be Done
        //    - these pointer arrays csa_area_begin/end should be placed in memory, not on the stack
        //      the simulator, however, will generate an error if 'static' is placed in front of the declarations
#  if !__CPU_TC051_INITIAL__
#  define MAX_NR_OF_CSA_AREAS     1
extern int _lc_ub_csa_01[];    /* context save area 1 begin */
extern int _lc_ue_csa_01[];    /* context save area 1 end   */
        int * csa_area_begin[] = { _lc_ub_csa_01 };        
        int * csa_area_end[]   = { _lc_ue_csa_01 };
#  else
#  define MAX_NR_OF_CSA_AREAS     3
extern int _lc_ub_csa_01[];    /* context save area 1 begin */
extern int _lc_ue_csa_01[];    /* context save area 1 end   */
extern int _lc_ub_csa_02[];    /* context save area 2 begin */
extern int _lc_ue_csa_02[];    /* context save area 2 end   */
extern int _lc_ub_csa_03[];    /* context save area 3 begin */
extern int _lc_ue_csa_03[];    /* context save area 3 end   */
        int * csa_area_begin[] = { _lc_ub_csa_01, _lc_ub_csa_02, _lc_ub_csa_03 };        
        int * csa_area_end[]   = { _lc_ue_csa_01, _lc_ue_csa_02, _lc_ue_csa_03 };
#  endif

        int  i, k;
        int  no_of_csas;
        int * csa;
        unsigned int  seg_nr, seg_idx, pcxi_val=0;
        _Bool first=true;
        
        for (i=0; i < MAX_NR_OF_CSA_AREAS; i++)
        {
                /* first calculate nr of CSAs in this area */
                no_of_csas = (csa_area_end[i] - csa_area_begin[i]) >> 4;
                
                for (k=0; k < no_of_csas; k++)
                {                        
                        csa = csa_area_begin[i] + k*16;
                        /* Store null pointer in last CSA (= very first time!) */
                        *csa = pcxi_val;                        

                        seg_nr  = __extru( (int) csa, 28, 4) << 16;
                        seg_idx = __extru( (int) csa, 6, 16);
                        pcxi_val = seg_nr | seg_idx;
                        if (first)
                        {
                                first = false;                                
                                __mtcr(LCX, pcxi_val);
                        }                        
                }
                __mtcr(FCX, pcxi_val);
        }
#endif
        
        /*
         * PMU_TC.004 workaround:
         * The split mode is disabled on the LMB bus to workaround.
         */
#if __PMU_TC004_INITIAL__  && defined LFI_CON
        LFI_CON.U &= 0xfffffffe;        
#endif
        
        /*
         * Initialize and clear C variables.
         */
#if __C_INIT
        _c_init();      /* initialize data */
#endif  

        /*
         * initialize __clocks_per_sec,
         * the oscillator frequency is defined by __fOSC.
         */
#if __CLOCKS_PER_SEC_INIT
        setclockpersec();
#endif  

        /* initialize profiling if required 
         */        
#if __PROF_ENABLE__
        __prof_init();
#endif

        /*
         * Call a user function within one can initialize the 
         * registers protected via the EndInit feature.
         * Beware that protected registers are unlocked 
         * for the duration of the Time-out Period only!
         */
#ifdef _CALL_ENDINIT
        _endinit_clear();  /* disable the write-protection */
        _endinit();        
        _endinit_set();    /* enable the write-protection  */
#endif
        
        /*
         * Call a user function before starting main().
         */
#if defined __CALL_INIT
        _call_init();        
#endif

        /*
         * Call C main program.
         */
#if __USE_ARGC_ARGV
        exit( main( _argcv( argcv, __ARGCV_BUFSIZE ), (char **)argcv ) );
#else
        exit( main( 0, NULL ) );                /* argc is 0 */
#endif

        /*
         * Default trap vectors are resolved from the C-library.
         */
#if __BTV_INIT
#  if __RESOLVE_TRAP_0
#    pragma extern  _trapmmu
#  endif
#  if __RESOLVE_TRAP_1
#    pragma extern  _trapprotection
#  endif
#  if __RESOLVE_TRAP_2
#    pragma extern  _trapinstruction
#  endif
#  if __RESOLVE_TRAP_3
#    pragma extern  _trapcontext
#  endif
#  if __RESOLVE_TRAP_4
#    pragma extern  _trapbus
#  endif
#  if __RESOLVE_TRAP_5
#    pragma extern  _trapassertion
#  endif
#  if __RESOLVE_TRAP_6
#    pragma extern  _trapsystem
#  endif
#  if __RESOLVE_TRAP_7
#    pragma extern  _trapnmi
#  endif
#endif
        
}

/**************************************************************************
 *
 * FUNCTION:     _endinit_clear
 *
 * DESCRIPTION:  Clears the ENDINIT bit in the WDT_CON0 register in order
 *               to disable the write-protection for registers protected
 *               via the EndInit feature (ie. WDT_CON1, BTV, BIV, ISP,
 *               mod_CLC).
 *
 *************************************************************************/
void inline _endinit_clear()
{
        unsigned int wdt_con0, wdt_con1;

        /*
         * 1st step: Password access (create password and send to WDT_CON0)
         */        
        wdt_con0 = WDT_CON0.U;
        wdt_con1 = WDT_CON1.U;

        wdt_con0 &= 0xffffff01;         /* clear WDTLCK, WDTHPW0, WDTHPW1 */
        wdt_con0 |= 0xf0;               /* set WDTHPW1 to 0xf */
        wdt_con1 &= 0x0c;               /* copy of WDT_CON1_WDTDR and WDT_CON1_WDTIR (d1) */
        wdt_con0 |= wdt_con1;           /* set WDTHPW1 to 0xf */
        WDT_CON0.U = wdt_con0;

        /*
         * 2nd step: Modify access, set the bit ENDINIT to 0 to allow access to
         *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
         */
        wdt_con0 &= 0xfffffff0;         /* clear WDTHPW0, WDTLCK, ENDINIT  */
        wdt_con0 |= 0x02;               /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
        __isync();
        WDT_CON0.U = wdt_con0;          
        WDT_CON0.U;                     /* read is required */
}

/**************************************************************************
 *
 * FUNCTION:     _endinit_set
 *
 * DESCRIPTION:  Sets the ENDINIT bit in the WDT_CON0 register in order
 *               to enable the write-protection for registers protected
 *               via the EndInit feature (ie. WDT_CON1, BTV, BIV, ISP,
 *               mod_CLC).
 *
 *************************************************************************/
void inline _endinit_set()
{
        unsigned int wdt_con0, wdt_con1;

        /*
         * 1st step: Password access (create password and send to WDT_CON0)
         */        
        wdt_con0 = WDT_CON0.U;
        wdt_con1 = WDT_CON1.U;

        wdt_con0 &= 0xffffff01;         /* clear WDTLCK, WDTHPW0, WDTHPW1 */
        wdt_con0 |= 0xf0;               /* set WDTHPW1 to 0xf */
        wdt_con1 &= 0x0c;               /* copy of WDT_CON1_WDTDR and WDT_CON1_WDTIR (d1) */
        wdt_con0 |= wdt_con1;           /* set WDTHPW1 to 0xf */
        WDT_CON0.U = wdt_con0;

        /*
         * 2nd step: Modify access, set the bit ENDINIT to 1
         */
        wdt_con0 &= 0xfffffff0;         /* clear WDTHPW0, WDTLCK, ENDINIT  */
        wdt_con0 |= 0x03;               /* WDTHPW0=0, WDTLCK=1, ENDINIT=1 */
        __isync();
        WDT_CON0.U = wdt_con0;
}

#if     __CLOCKS_PER_SEC_INIT
static void setclockpersec(void)
{
        unsigned long long hz = 0;

#if defined PLL_CLC && defined __fOSC
#if ( defined _REGTC11IB_H )
#define K       (PLL_CLC.B.PLL1_KDIV+1)
        if ( PLL_CLC.B.PLL1_BP )                 /* PLL Bypass Operation */
        {
                hz = __fOSC;
        }
        else
        {
                if ( PLL_CLC.B.PLL1_VCOBP )         /* VCO Bypass Operation */
                {
                        hz = __fOSC/K;
                }
                else                            /* PLL Operation */
                {
                        hz = (16*__fOSC)/K;
                }
        }
#endif

#if     (  defined _REGTC1100_H || defined _REGTC1115_H || defined _REGTC1130_H || defined _REGTC1161_H \
        || defined _REGTC1162_H || defined _REGTC1163_H || defined _REGTC1164_H || defined _REGTC1165_H \
        || defined _REGTC1166_H || defined _REGTC1762_H || defined _REGTC1764_H || defined _REGTC1766_H \
        || defined _REGTC1766B_H || defined _REGTC1792_H || defined _REGTC1796_H || defined _REGTC1796B_H )
#define P               (PLL_CLC.B.PDIV+1)
#define N               (PLL_CLC.B.NDIV+1)
#define K               (PLL_CLC.B.KDIV+1)
#if     ( defined _REGTC1100_H || defined _REGTC1115_H  || defined _REGTC1130_H )
#define __SYSFS__       SYSFSL
#else
#if     (  defined _REGTC1762_H || defined _REGTC1764_H || defined _REGTC1766B_H || defined _REGTC1161_H \
        || defined _REGTC1162_H || defined _REGTC1163_H || defined _REGTC1164_H || defined _REGTC1165_H \
        || defined _REGTC1166_H )
#define __SYSFS__       RSV
#else
#define __SYSFS__       SYSFS
#endif
#endif
#define SYSCLK(CPUCLK)  (CPUCLK/(2-PLL_CLC.B.__SYSFS__))
#define STMCLK(CPUCLK)  (SYSCLK(CPUCLK)/STM_CLC.B.RMC)
#define FVCOBASE        __fOSC
        if ( PLL_CLC.B.BYPPIN )                                                         /* Direct drive */
        {
                hz = STMCLK(__fOSC);
        }
        else
        {
                if ( PLL_CLC.B.VCOBYP )                                                 /* VCO Bypass Mode */
                {
                        hz = STMCLK(__fOSC/(P*K));
                }
                else
                {
                        if ( !PLL_CLC.B.OSCDISC && PLL_CLC.B.LOCK )     /* PLL Mode */
                        {
                                hz = STMCLK((N*__fOSC)/(P*K));
                        }
                        else                                                                            /* PLL base mode */
                        {
                                hz = STMCLK(FVCOBASE/K);
                        }
                }
        }
#endif
#endif

#if defined SCU_PLLSTAT && defined __fOSC
#if     (  defined _REGTC1167_H || defined _REGTC1197_H || defined _REGTC1337_H || defined _REGTC1367_H \
        || defined _REGTC1387_H || defined _REGTC1732_H || defined _REGTC1728_H || defined _REGTC1734_H \
        || defined _REGTC1735_H || defined _REGTC1736_H || defined _REGTC1738_H || defined _REGTC1746_H \
        || defined _REGTC1747_H || defined _REGTC1748_H || defined _REGTC1767_H || defined _REGTC1768_H \
        || defined _REGTC1782_H || defined _REGTC1784_H || defined _REGTC1184_H || defined _REGTC1797_H \
        || defined _REGTC1791_H || defined _REGTC1793_H || defined _REGTC1798_H || defined _REGTC1724_H )
#define P               (SCU_PLLCON0.B.PDIV+1)
#define N               (SCU_PLLCON0.B.NDIV+1)
#define K1              (SCU_PLLCON1.B.K1DIV+1)
#define K2              (SCU_PLLCON1.B.K2DIV+1)
#if     ( defined _REGTC1337_H || defined _REGTC1367_H || defined _REGTC1387_H || defined _REGTC1768_H )
#define SYSCLK(CPUCLK)  (CPUCLK)
#else
#define SYSCLK(CPUCLK)  (CPUCLK/(SCU_CCUCON0.B.FPIDIV+1))       
#endif
#define STMCLK(CPUCLK)  (SYSCLK(CPUCLK)/STM_CLC.B.RMC)
#define FVCOBASE        __fOSC
        if ( SCU_PLLSTAT.B.VCOBYST )    /* Prescaler mode */
        {
                hz = STMCLK(__fOSC/K1);
        }
        else
        {
                if ( SCU_PLLSTAT.B.FINDIS )     /* Free running mode */
                {
                        hz = STMCLK(FVCOBASE/K2);
                }
                else                                            /* Normal mode */
                {
                        hz = STMCLK((N*__fOSC)/(P*K2));
                }
        }
#endif
#endif
        setfoschz ( hz );
}
#endif

/**************************************************************************
**                                                                        *
**  FILE        :  cstart.c                                               *
**                                                                        *
**  VERSION     :  @(#)cstart.c 1.42                                                      *
**                                                                        *
**  DESCRIPTION :                                                         *
**                                                                        *
**      The system startup code initializes the processor's registers     *
**      and the application C variables.                                  *
**      SFR initializations for any device are included. But only when a  *
**      SFR is actually defined in the SFR file it can be initialized.    *
**      The initialization values are defined in cstart.h as well as      *
**      a macro to enable/disable initialization of an SFR.               *
**                                                                        *
**  Copyright 1996-2011 Altium BV                                         *
**                                                                        *
**************************************************************************/

#ifndef __LITE__                                /* the Lite edition does not support MISRA-C */
# pragma nomisrac                               /* Suppress MISRA-C checking */
#endif

#include <stdlib.h>
#include <_cptable.h>
#ifdef __CPU__
#include __SFRFILE__(__CPU__)                   /* include SFR file for selected CPU */
                                                /* (gives indexer warnings in Eclipse) */
#endif
#include "cstart.h"                             /* include configuration */

/*
 * library references
 */
#if     __PROF_ENABLE__
extern  void    __prof_init( void );
#endif
#pragma extern main
extern  int     main( int argc, char *argv[] );

#pragma weak exit
#pragma extern _Exit
#ifndef __LITE__                                /* these pragmas are not available in Lite edition */
# pragma profiling off                          /* prevent profiling information on cstart */
# pragma optimize abcefgIKlpoRsy                /* preset optimizations */
# pragma runtime BCM                            /* disable runtime error checking for cstart */
#endif
#pragma tradeoff 4                              /* preset tradeoff level */

#if __USE_ARGC_ARGV
static char argcv[__ARGCV_BUFSIZE];
extern  int     _argcv( const char *, size_t );
#endif


/*
 * locator defined symbols
 */
extern __near   char    _lc_ub_user_stack[];
extern __near   char    _lc_ub_user_stack1[];
extern __near   char    _lc_ub_user_stack2[];
extern __near   char    _lc_ub_user_stack3[];
extern __huge   char    _lc_ub_system_stack[];
extern __huge   char    _lc_ue_system_stack[];
extern __huge   char    _lc_base_dpp0[];
extern __huge   char    _lc_base_dpp1[];
extern __huge   char    _lc_base_dpp2[];
extern __huge   char    _lc_vector_table[];
extern          cptab_t _lc_copy_table[];

/*********************************************************************************
 * _cstart() - startup code, invoked from the RESET vector
 *********************************************************************************/
void __interrupt(0)  __registerbank( cstart_rb ) _cstart( void )
{
#if !__WDT_ENABLED
        __diswdt();                             /* disable watchdog timer */
#endif

        /*
         * Initialize registers
         */
#ifdef __WDTCON
        if (__WDTCON_INIT)      __WDTCON.U = __WDTCON_VALUE;
#else  /* when no WDTCON available, use WDTREL and WDTCS */
# ifdef __WDTREL
        if (__WDTREL_INIT)      __WDTREL.U = __WDTREL_VALUE;
# endif
# ifdef __WDTCS
        if (__WDTCS_INIT)       __WDTCS.U = (__WDTCS.U & ~__WDTCS_MASK) | (__WDTCS_VALUE & __WDTCS_MASK);
# endif
#endif
#if __WDT_ENABLED
        __srvwdt();                             /* serve watchdog timer */
#endif

#ifdef __XPERCON
        if (__XPERCON_INIT)     __XPERCON.U = __XPERCON_VALUE;
#endif

#ifdef __SYSCON
# if __SYSCON_DO_MASK
        if ( __SYSCON_INIT)     __bfld( &__SYSCON.U, ~__SYSCON_MASK,  __SYSCON_VALUE & ~__SYSCON_MASK );
# else
        if ( __SYSCON_INIT)     __SYSCON.U = __SYSCON_VALUE;
# endif
#endif

#if defined(XPEREMU) && defined(XPERCON) && defined(SYSCON)
# if (__XPERCON_VALUE & 0x07D3) && (__SYSCON_VALUE & 0x0004) && __XPEREMU_INIT
        __XPEREMU.U = __XPEREMU_VALUE;
# endif
#endif

#ifdef __RSTCON
# if __RSTCON_DO_MASK
        if ( __RSTCON_INIT)     __RSTCON.U = (__RSTCON.U & ~__RSTCON_MASK) | (__RSTCON_MASK & __RSTCON_VALUE);
# else
        if ( __RSTCON_INIT)     __RSTCON.U = __RSTCON_VALUE;
# endif 
#endif  

#ifdef __CPUCON1
        if ( __CPUCON1_INIT)    __CPUCON1.U = __CPUCON1_VALUE;
#endif

#ifdef __CPUCON2
        if ( __CPUCON2_INIT)    __CPUCON2.U = __CPUCON2_VALUE;
#endif

#ifdef __SYSCON0
        if(__SYSCON0_INIT)      __SYSCON0.U = __SYSCON0_VALUE;
#endif

#ifdef __SYSCON1
        if(__SYSCON1_INIT)      __SYSCON1.U = __SYSCON1_VALUE;
#endif

#ifdef __SYSCON2
        if(__SYSCON2_INIT)      __bfld( &__SYSCON2.U, 0x04,__SYSCON2_VALUE & 0x4 );
#endif

#ifdef __SYSCON3
        if(__SYSCON3_INIT)      __SYSCON3.U = __SYSCON3_VALUE;
#endif

#ifdef __PLLCON
        if(__PLLCON_INIT)       __PLLCON.U = __PLLCON_VALUE;
#endif

        /*
         * Bus configuration
         */
#ifdef __EBCMOD0
# if __EBCMOD0_DO_MASK
        if ( __EBCMOD0_INIT)    __EBCMOD0.U |= __EBCMOD0_VALUE & ~__EBCMOD0_MASK;
# else
        if ( __EBCMOD0_INIT)    __EBCMOD0.U = __EBCMOD0_VALUE;
# endif
#endif

#ifdef __EBCMOD1
        if(__EBCMOD1_INIT)      __EBCMOD1.U = __EBCMOD1_VALUE;
#endif

#ifdef __BUSCON0
# if __BUSCON0_DO_MASK
        if ( __BUSCON0_INIT)    __bfld( &__BUSCON0.U, ~__BUSCON0_MASK,  __BUSCON0_VALUE & ~__BUSCON0_MASK );
# else
        if ( __BUSCON0_INIT)    __BUSCON0.U = __BUSCON0_VALUE;
# endif
#endif

#ifdef __BUSCON1
        if(__ADDRSEL1_INIT)     __ADDRSEL1.U = __ADDRSEL1_VALUE;
        if(__BUSCON1_INIT)      __BUSCON1.U = __BUSCON1_VALUE;
#endif

#ifdef __BUSCON2
        if(__ADDRSEL2_INIT)     __ADDRSEL2.U = __ADDRSEL2_VALUE;
        if(__BUSCON2_INIT)      __BUSCON2.U = __BUSCON2_VALUE;
#endif

#ifdef __BUSCON3
        if(__ADDRSEL3_INIT)     __ADDRSEL3.U = __ADDRSEL3_VALUE;
        if(__BUSCON3_INIT)      __BUSCON3.U = __BUSCON3_VALUE;
#endif

#ifdef __BUSCON4
        if(__ADDRSEL4_INIT)     __ADDRSEL4.U = __ADDRSEL4_VALUE;
        if(__BUSCON4_INIT)      __BUSCON4.U = __BUSCON4_VALUE;
#endif

#ifdef __XBCON1
        if(__XBCON1_INIT)       __bfld( &__XBCON1.U, 0x1fff, __XBCON1_VALUE & 0x1fff);
#endif
#ifdef __XADRS1
        if(__XADRS1_INIT)       __XADRS1.U = __XADRS1_VALUE;
#endif

#ifdef __XBCON2
        if(__XBCON2_INIT)       __bfld( &__XBCON2.U, 0x1fff, __XBCON2_VALUE & 0x1fff);
#endif
#ifdef __XADRS2
        if(__XADRS2_INIT)       __XADRS2.U = __XADRS2_VALUE;
#endif

#ifdef __XBCON3
        if(__XBCON3_INIT)       __bfld( &__XBCON3.U, 0x1fff, __XBCON3_VALUE & 0x1fff);
        if(__XADRS3_INIT)       __XADRS3.U = __XADRS3_VALUE;
#endif

#ifdef __XBCON4
        if(__XBCON4_INIT)       __bfld( &__XBCON4.U, 0x1fff, __XBCON4_VALUE & 0x1fff);
        if(__XADRS4_INIT)       __XADRS4.U = __XADRS4_VALUE;
#endif

#ifdef __XBCON5
        if(__XBCON5_INIT)       __bfld( &__XBCON5.U, 0x1fff, __XBCON5_VALUE & 0x1fff);
        if(__XADRS5_INIT)       __XADRS5.U = __XADRS5_VALUE;
#endif

#ifdef __XBCON6
        if(__XBCON6_INIT)       __bfld( &__XBCON6.U, 0x1fff, __XBCON6_VALUE & 0x1fff);
        if(__XADRS6_INIT)       __XADRS6.U = __XADRS6_VALUE;
#endif

#ifdef __TCONBURSTCS0
        if(__TCONBURSTCS0_INIT) TCONBURSTCS0 = __TCONBURSTCS0_VALUE;
#endif
#ifdef __TCONCS0
        if(__TCONCS0_INIT)      __TCONCS0.U = __TCONCS0_VALUE;
# if __FCONCS0_DO_MASK
        if ( __FCONCS0_INIT)    __FCONCS0.U |= __FCONCS0_VALUE & ~__FCONCS0_MASK;
# else
        if ( __FCONCS0_INIT)    __FCONCS0.U = __FCONCS0_VALUE;
# endif 
#endif

#ifdef __TCONBURSTCS0
        if(__TCONBURSTCS0_INIT) __TCONBURSTCS0.U = __TCONBURSTCS0_VALUE;
#endif
#ifdef __TCONCS0
        if(__TCONCS0_INIT)      __TCONCS0.U = __TCONCS0_VALUE;
        if(__FCONCS0_INIT)      __FCONCS0.U = __FCONCS0_VALUE;
#endif

#ifdef __TCONBURSTCS1
        if(__TCONBURSTCS1_INIT) __TCONBURSTCS1.U = __TCONBURSTCS1_VALUE;
#endif
#ifdef __TCONCS1
        if(__ADDRSEL1_INIT)     __ADDRSEL1.U = __ADDRSEL1_VALUE;
        if(__TCONCS1_INIT)      __TCONCS1.U = __TCONCS1_VALUE;
        if(__FCONCS1_INIT)      __FCONCS1.U = __FCONCS1_VALUE;
#endif

#ifdef __TCONBURSTCS2
        if(__TCONBURSTCS2_INIT) __TCONBURSTCS2.U = __TCONBURSTCS2_VALUE;
#endif
#ifdef __TCONCS2
        if(__ADDRSEL2_INIT)     __ADDRSEL2.U = __ADDRSEL2_VALUE;
        if(__TCONCS2_INIT)      __TCONCS2.U = __TCONCS2_VALUE;
        if(__FCONCS2_INIT)      __FCONCS2.U = __FCONCS2_VALUE;
#endif

#ifdef __TCONBURSTCS3
        if(__TCONBURSTCS3_INIT) __TCONBURSTCS3.U = __TCONBURSTCS3_VALUE;
#endif
#ifdef __TCONCS3
        if(__ADDRSEL3_INIT)     __ADDRSEL3.U = __ADDRSEL3_VALUE;
        if(__TCONCS3_INIT)      __TCONCS3.U = __TCONCS3_VALUE;
        if(__FCONCS3_INIT)      __FCONCS3.U = __FCONCS3_VALUE;
#endif

#ifdef __TCONBURSTCS4
        if(__TCONBURSTCS4_INIT) __TCONBURSTCS4.U = __TCONBURSTCS4_VALUE;
#endif
#ifdef __TCONCS4
        if(__ADDRSEL4_INIT)     __ADDRSEL4.U = __ADDRSEL4_VALUE;
        if(__TCONCS4_INIT)      __TCONCS4.U = __TCONCS4_VALUE;
        if(__FCONCS4_INIT)      __FCONCS4.U = __FCONCS4_VALUE;
#endif

#ifdef __TCONBURSTCS5
        if(__TCONBURSTCS5_INIT) __TCONBURSTCS5.U = __TCONBURSTCS5_VALUE;
#endif
#ifdef __TCONCS5
        if(__ADDRSEL5_INIT)     __ADDRSEL5.U = __ADDRSEL5_VALUE;
        if(__TCONCS5_INIT)      __TCONCS5.U = __TCONCS5_VALUE;
        if(__FCONCS5_INIT)      __FCONCS5.U = __FCONCS5_VALUE;
#endif

#ifdef __TCONBURSTCS6
        if(__TCONBURSTCS6_INIT) __TCONBURSTCS6.U = __TCONBURSTCS6_VALUE;
#endif
#ifdef __TCONCS6
        if(__ADDRSEL6_INIT)     __ADDRSEL6.U = __ADDRSEL6_VALUE;
        if(__TCONCS6_INIT)      __TCONCS6.U = __TCONCS6_VALUE;
        if(__FCONCS6_INIT)      __FCONCS6.U = __FCONCS6_VALUE;
#endif

#ifdef __TCONBURSTCS7
        if(__TCONBURSTCS7_INIT) __TCONBURSTCS7.U = __TCONBURSTCS7_VALUE;
#endif
#ifdef __TCONCS7
        if(__ADDRSEL7_INIT)     __ADDRSEL7.U = __ADDRSEL7_VALUE;
        if(__TCONCS7_INIT)      __TCONCS7.U = __TCONCS7_VALUE;
        if(__FCONCS7_INIT)      __FCONCS7.U = __FCONCS7_VALUE;
#endif

        /*
         * Miscellaneous
         */
#ifdef __EXICON
        if(__EXICON_INIT)       __EXICON.U = __EXICON_VALUE;
#endif

#ifdef __EXISEL0
        if(__EXISEL0_INIT)      __EXISEL0.U = __EXISEL0_VALUE;
#endif

#ifdef __EXISEL1
        if(__EXISEL1_INIT)      __EXISEL1.U = __EXISEL1_VALUE;
#endif

#ifdef __IMBCTR
        if(__IMBCTR_INIT)       __IMBCTR.U = __IMBCTR_VALUE;
#endif
#ifdef __IMB_IMBCTRL
        if(__IMB_IMBCTRL_INIT)  __IMB_IMBCTRL.U = __IMB_IMBCTRL_VALUE;
#endif
#ifdef __IMB_IMBCTRH
        if(__IMB_IMBCTRH_INIT)  __IMB_IMBCTRH.U = __IMB_IMBCTRH_VALUE;
#endif

#ifdef __ADC_EVS
        if(__ADC_EVS_INIT)      __ADC_EVS.U = __ADC_EVS_VALUE;
#endif

#ifdef __CAPCOM_EVS
        if(__CAPCOM_EVS_INIT)   __CAPCOM_EVS.U = __CAPCOM_EVS_VALUE;
#endif

#ifdef __CLK_CONF
        if(__CLK_CONF_INIT)     __CLK_CONF.U = __CLK_CONF_VALUE;
#endif

#ifdef __CMCTR
        if(__CMCTR_INIT)        __CMCTR.U = __CMCTR_VALUE;
#endif

#ifdef __EBCCSEN
        if(__EBCCSEN_INIT)      __EBCCSEN.U = __EBCCSEN_VALUE;
#endif

#ifdef __EMUPCON
        if(__EMUPCON_INIT)      __EMUPCON.U = __EMUPCON_VALUE;
#endif

#ifdef __EMU_XPCON
        if(__EMU_XPCON_INIT)    __EMU_XPCON.U = __EMU_XPCON_VALUE;
#endif

#ifdef __EXISEL
        if(__EXISEL_INIT)       __EXISEL.U = __EXISEL_VALUE;
#endif

#ifdef __FOCON
        if(__FOCON_INIT)        __FOCON.U = __FOCON_VALUE;
#endif

#ifdef __GPT_EVS
        if(__GPT_EVS_INIT)      __GPT_EVS.U = __GPT_EVS_VALUE;
#endif

#ifdef __OPSEN
        if(__OPSEN_INIT)        __OPSEN.U = __OPSEN_VALUE;
#endif

#ifdef __PLL_CONF
        if(__PLL_CONF_INIT)     __PLL_CONF.U = __PLL_CONF_VALUE;
#endif

#ifdef __SYS_MEM
        if(__SYS_MEM_INIT)      __SYS_MEM.U = __SYS_MEM_VALUE;
#endif

#ifdef __SYS_PALT
        if(__SYS_PALT_INIT)     __SYS_PALT.U = __SYS_PALT_VALUE;
#endif

#ifdef __TCONCSMM
        if(__TCONCSMM_INIT)     __TCONCSMM.U = __TCONCSMM_VALUE;
#endif

#ifdef __TCONCSSM
        if(__TCONCSSM_INIT)     __TCONCSSM.U = __TCONCSSM_VALUE;
#endif

#ifdef __VREG_CONF
        if(__VREG_CONF_INIT)    __VREG_CONF.U = __VREG_CONF_VALUE;
#endif

#ifdef __XPERCONC
        if(__XPERCONC_INIT)     __XPERCONC.U = __XPERCONC_VALUE;
#endif

#ifdef __XPERCONS
        if(__XPERCONS_INIT)     __XPERCONS.U = __XPERCONS_VALUE;
#endif


        /*
         * Kernel State Configuration Registers
         */
#ifdef __RTC_KSCCFG
        if(__RTC_KSCCFG_INIT)   __RTC_KSCCFG.U = __RTC_KSCCFG_VALUE;
#endif

#ifdef __GPT12E_KSCCFG
        if(__GPT12E_KSCCFG_INIT)__GPT12E_KSCCFG.U = __GPT12E_KSCCFG_VALUE;
#endif

#ifdef __CC2_KSCCFG
        if(__CC2_KSCCFG_INIT)   __CC2_KSCCFG.U = __CC2_KSCCFG_VALUE;
#endif

#ifdef __MEM_KSCCFG
        if(__MEM_KSCCFG_INIT)   __MEM_KSCCFG.U = __MEM_KSCCFG_VALUE;
#endif

#ifdef __FL_KSCCFG
        if(__FL_KSCCFG_INIT)    __FL_KSCCFG.U = __FL_KSCCFG_VALUE;
#endif

#ifdef __MCAN_KSCCFG
        if(__MCAN_KSCCFG_INIT)  __MCAN_KSCCFG.U = __MCAN_KSCCFG_VALUE;
#endif
        /*
         * ICACHE
         */
#ifdef __ICACHE_CTRL
# if __ICACHE_CTRL_DO_MASK
        if ( __ICACHE_CTRL_INIT) __ICACHE_CTRL.U |= __ICACHE_CTRL_VALUE & ~__ICACHE_CTRL_MASK;
# else
        if(__ICACHE_CTRL_INIT)  __ICACHE_CTRL.U = __ICACHE_CTRL_VALUE;
# endif 
#endif
#ifdef __ICACHE_EDCON
        if(__ICACHE_EDCON_INIT) __ICACHE_EDCON.U = __ICACHE_EDCON_VALUE;
#endif
#ifdef __ICACHE_DACON
# if __ICACHE_DACON_DO_MASK
        if ( __ICACHE_DACON_INIT) __ICACHE_DACON.U |= __ICACHE_DACON_VALUE & ~__ICACHE_DACON_MASK;
# else
        if(__ICACHE_DACON_INIT) __ICACHE_DACON.U = __ICACHE_DACON_VALUE;
# endif 
#endif
        /*
         * Vector table segment
         */
#if __SET_VECSEG
        __VECSEG.U = __seg( _lc_vector_table ); /* use linker symbol */
#endif


        
        /*
         * Initialize system stack pointer and underflow and overflow registers
         */
         __asm("$nowarning(735)" );             /* do not complain about the labels in the atomic sequence */
#if __SET_SPSEG
        __asm( "atomic #4" );
        __SPSEG.U = __seg( _lc_ub_system_stack );       /* use linker symbol */
#else
        __asm( "atomic #3" );
#endif
        __SP.U    = (int)_lc_ub_system_stack;
        __STKOV.U = (int)(_lc_ue_system_stack + 6 * 2);
        __STKUN.U = (int)_lc_ub_system_stack;


        /*
         * einit: end-of-initialization, set reset output pin /RSTOUT high
         */
#if __EXECUTE_EINIT
        __einit();
#endif

#if __WDT_ENABLED
        __srvwdt();
#endif

        /*
         * Initialize user stack pointer
         */
        __setsp( _lc_ub_user_stack );
        

        /*
         * Initialize user stack pointers in local register banks 
         */
#if     defined(__CORE_XC16X__) || defined(__CORE_SUPER10__)
#ifndef BANK                                    /* BANK not defined in new style SFR files */
#define BANK            __PSW.B.BANK
#endif
# if __INIT_USER_STACK1
        BANK = 2;                               /* local registerbank 1 */
        __setsp( _lc_ub_user_stack1 );          /* initialize user stack pointer */
# endif
# if __INIT_USER_STACK2
        BANK = 3;                               /* local registerbank 2 */
        __setsp( _lc_ub_user_stack2 );          /* initialize user stack pointer */
# endif
# if __INIT_USER_STACK1 || __INIT_USER_STACK2
        BANK = 0;                               /* back to global registerbank */
# endif
#endif



        /*
         * DPPs for near __addressing
         */
        __DPP0.U = __pag(_lc_base_dpp0);
        __DPP1.U = __pag(_lc_base_dpp1);
        __DPP2.U = __pag(_lc_base_dpp2);



        /*
         * Initialize C variables
         */
        if( _lc_copy_table[0].action != ac_stop )       /* only initialize if copy table contains data */
                _init( __WDT_ENABLED );                 /* library routine: initialize C variables */



        /*
         * Set up profiling
         */
#if  __PROF_ENABLE__
        __prof_init();
#endif


#ifndef IEN                                     /* IEN not defined in new style SFR files */
#define IEN             __PSW.B.IEN
#endif
        if( __ENABLE_INTERRUPTS )
                IEN = 1;                        /* enable interrupts */


#if __WDT_ENABLED
        __srvwdt();                             /* serve watchdog timer */
#endif

        
#if __USE_ARGC_ARGV
        exit( main( _argcv( argcv, __ARGCV_BUFSIZE ), (char **)argcv ) );
#else
        exit( main( 0, NULL ) );                /* argc is 0 */
#endif
} 



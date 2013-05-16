/**************************************************************************
**                                                                        *
**  FILE        :  cstart.h                                               *
**                                                                        *
**  VERSION     :  @(#)cstart.h 1.20                                                      *
**                                                                        *
**  DESCRIPTION :                                                         *
**                                                                        *
**      Header file to control the system startup code's general settings *
**      and register initializations. The cstart.c file must be part of   *
**      your project to make use of this cstart.h.                        *
**                                                                        *
**      In the Eclipse environment this file can be modified using the    *
**      C startup code editor, which provides a GUI to modify the         *
**      Configuration settings and register initialization.               *
**                                                                        *
**  Copyright 1996-2011 Altium BV                                         *
**                                                                        *
**************************************************************************/

#ifndef CSTART_H
#define CSTART_H        1


/*
 * These items are shown on in Eclipse on the C Start Configuration page
 */

#ifndef __NO_CSTART_DEFAULT_CONFIG

/* C Startup settings */
#define __ENABLE_INTERRUPTS     1       /* Enable interrupts */
#define __EXECUTE_EINIT         1       /* Execute EINIT instruction */
#define __USE_ARGC_ARGV         0       /* Enable passing argc/argv to main() */
#define __ARGCV_BUFSIZE         256     /* Buffer size for argv */

/* Special registers */
#if     defined(__CORE_XC16X__) || defined(__CORE_SUPER10__) 
#define __SET_VECSEG            1       /* Set VECSEG to the segment of the vector table in the LSL file */
#define __SET_SPSEG             1       /* Set SPSEG to the segment of the system stack in the LSL file */
# define __INIT_USER_STACK1     0       /* Initialize user stack pointer of local registerbank 1 */
# define __INIT_USER_STACK2     0       /* Initialize user stack pointer of local registerbank 2 */
#endif
#endif /* __NO_CSTART_DEFAULT_CONFIG */




/*
 * Control of initialization registers
 *
 * The *_VALUE macros define the value of the register
 * The *_INIT macros must be defined to 0 or 1, specifying whether
 * or not it will be intialized by the cstart.c code.
 * The *_MASK macros define a mask to be used for initializing the register
 * The *_DO_MASK macros must be define to 0 or 1, specifying whether or 
 * not the mask is applied when initializing the register.
 *
 * Initially NO registers are set to be initialized, which means that
 * the CPU's defaults are used. Also all values are set to 0x0000
 * initially, which does not match the CPU's defaults for all registers.
 * The Eclipse environment will automatically apply the CPU default
 * values to the registers. These defaults are defined in the SFR files
 * from the include/sfr directory of the product.
 *
 */
#ifndef __NO_CSTART_REGISTER_CONFIG
#define __ADC_EVS_INIT          0
#define __ADC_EVS_VALUE         0x0000

#define __ADDRSEL1_INIT         0
#define __ADDRSEL1_VALUE        0x0000
#define __ADDRSEL2_INIT         0
#define __ADDRSEL2_VALUE        0x0000
#define __ADDRSEL3_INIT         0
#define __ADDRSEL3_VALUE        0x0000
#define __ADDRSEL4_INIT         0
#define __ADDRSEL4_VALUE        0x0000
#define __ADDRSEL5_INIT         0
#define __ADDRSEL5_VALUE        0x0000
#define __ADDRSEL6_INIT         0
#define __ADDRSEL6_VALUE        0x0000
#define __ADDRSEL7_INIT         0
#define __ADDRSEL7_VALUE        0x0000

#define __BUSCON0_INIT          0
#define __BUSCON0_DO_MASK       0
#define __BUSCON0_VALUE         0x0000
#define __BUSCON1_INIT          0
#define __BUSCON1_VALUE         0x0000
#define __BUSCON2_INIT          0
#define __BUSCON2_VALUE         0x0000
#define __BUSCON3_INIT          0
#define __BUSCON3_VALUE         0x0000
#define __BUSCON4_INIT          0
#define __BUSCON4_VALUE         0x0000

#define __CAPCOM_EVS_INIT       0
#define __CAPCOM_EVS_VALUE      0x0000

#define __CLK_CONF_INIT         0
#define __CLK_CONF_VALUE        0x0000

#define __CMCTR_INIT            0
#define __CMCTR_VALUE           0x4000

#define __CPUCON1_INIT          0
#define __CPUCON1_VALUE         0x0007

#define __CPUCON2_INIT          0
#define __CPUCON2_VALUE         0x8fbb

#define __EBCCSEN_INIT          0
#define __EBCCSEN_VALUE         0x0000

#define __EBCMOD0_INIT          0
#define __EBCMOD0_DO_MASK       0
#define __EBCMOD0_VALUE         0x5400
#define __EBCMOD1_INIT          0
#define __EBCMOD1_VALUE         0x003f

#define __EMUPCON_INIT          0
#define __EMUPCON_VALUE         0x0000

#define __EMU_XPCON_INIT        0
#define __EMU_XPCON_VALUE       0x0000

#define __EXICON_INIT           0
#define __EXICON_VALUE          0x0000
#define __EXISEL0_INIT          0
#define __EXISEL0_VALUE         0x0000
#define __EXISEL1_INIT          0
#define __EXISEL1_VALUE         0x0000
#define __EXISEL_INIT           0
#define __EXISEL_VALUE          0x0000

#define __FCONCS0_INIT          0
#define __FCONCS0_DO_MASK       0
#define __FCONCS0_VALUE         0x0011
#define __FCONCS1_INIT          0
#define __FCONCS1_VALUE         0x0000
#define __FCONCS2_INIT          0
#define __FCONCS2_VALUE         0x0000
#define __FCONCS3_INIT          0
#define __FCONCS3_VALUE         0x0000
#define __FCONCS4_INIT          0
#define __FCONCS4_VALUE         0x0000
#define __FCONCS5_INIT          0
#define __FCONCS5_VALUE         0x0000
#define __FCONCS6_INIT          0
#define __FCONCS6_VALUE         0x0000
#define __FCONCS7_INIT          0
#define __FCONCS7_VALUE         0x0000

#define __FOCON_INIT            0
#define __FOCON_VALUE           0x0000

#define __GPT_EVS_INIT          0
#define __GPT_EVS_VALUE         0x0000

#define __IMBCTR_INIT           0
#define __IMBCTR_VALUE          0x0000
#define __IMB_IMBCTRL_INIT      0
#define __IMB_IMBCTRL_VALUE     0x55ac
#define __IMB_IMBCTRH_INIT      0
#define __IMB_IMBCTRH_VALUE     0x0005

#define __OPSEN_INIT            0
#define __OPSEN_VALUE           0x0000

#define __PLLCON_INIT           0
#define __PLLCON_VALUE          0x0000
#define __PLL_CONF_INIT         0
#define __PLL_CONF_VALUE        0x0000

#define __RSTCON_INIT           0
#define __RSTCON_DO_MASK        0
#define __RSTCON_VALUE          0x0000

#define __SYSCON0_INIT          0
#define __SYSCON0_VALUE         0x0000
#define __SYSCON1_INIT          0
#define __SYSCON1_VALUE         0x0000
#define __SYSCON2_INIT          0
#define __SYSCON2_VALUE         0x0000
#define __SYSCON3_INIT          0
#define __SYSCON3_VALUE         0x0000

#define __SYSCON_INIT           0
#define __SYSCON_DO_MASK        0
#define __SYSCON_VALUE          0x0000

#define __SYS_MEM_INIT          0
#define __SYS_MEM_VALUE         0x0000

#define __SYS_PALT_INIT         0
#define __SYS_PALT_VALUE        0x0000

#define __TCONBURSTCS0_INIT     0
#define __TCONBURSTCS0_VALUE    0x0000
#define __TCONBURSTCS1_INIT     0
#define __TCONBURSTCS1_VALUE    0x0000
#define __TCONBURSTCS2_INIT     0
#define __TCONBURSTCS2_VALUE    0x0000
#define __TCONBURSTCS3_INIT     0
#define __TCONBURSTCS3_VALUE    0x0000
#define __TCONBURSTCS4_INIT     0
#define __TCONBURSTCS4_VALUE    0x0000
#define __TCONBURSTCS5_INIT     0
#define __TCONBURSTCS5_VALUE    0x0000
#define __TCONBURSTCS6_INIT     0
#define __TCONBURSTCS6_VALUE    0x0000
#define __TCONBURSTCS7_INIT     0
#define __TCONBURSTCS7_VALUE    0x0000

#define __TCONCS0_INIT          0
#define __TCONCS0_VALUE         0x7c3d
#define __TCONCS1_INIT          0
#define __TCONCS1_VALUE         0x0000
#define __TCONCS2_INIT          0
#define __TCONCS2_VALUE         0x0000
#define __TCONCS3_INIT          0
#define __TCONCS3_VALUE         0x0000
#define __TCONCS4_INIT          0
#define __TCONCS4_VALUE         0x0000
#define __TCONCS5_INIT          0
#define __TCONCS5_VALUE         0x0000
#define __TCONCS6_INIT          0
#define __TCONCS6_VALUE         0x0000
#define __TCONCS7_INIT          0
#define __TCONCS7_VALUE         0x0000
#define __TCONCSMM_INIT         0
#define __TCONCSMM_VALUE        0x0000
#define __TCONCSSM_INIT         0
#define __TCONCSSM_VALUE        0x0000

#define __VREG_CONF_INIT        0
#define __VREG_CONF_VALUE       0x0000

#define __WDTCON_INIT           0
#define __WDTCON_VALUE          0x0000
#define __WDTREL_INIT           0
#define __WDTREL_VALUE          0xfffc
#define __WDTCS_INIT            0
#define __WDTCS_VALUE           0x0000
#define __WDTCS_MASK            0x0000

#define __XADRS1_INIT           0
#define __XADRS1_VALUE          0x0000
#define __XADRS2_INIT           0
#define __XADRS2_VALUE          0x0000
#define __XADRS3_INIT           0
#define __XADRS3_VALUE          0x0000
#define __XADRS4_INIT           0
#define __XADRS4_VALUE          0x0000
#define __XADRS5_INIT           0
#define __XADRS5_VALUE          0x0000
#define __XADRS6_INIT           0
#define __XADRS6_VALUE          0x0000

#define __XBCON1_INIT           0
#define __XBCON1_VALUE          0x0000
#define __XBCON2_INIT           0
#define __XBCON2_VALUE          0x0000
#define __XBCON3_INIT           0
#define __XBCON3_VALUE          0x0000
#define __XBCON4_INIT           0
#define __XBCON4_VALUE          0x0000
#define __XBCON5_INIT           0
#define __XBCON5_VALUE          0x0000
#define __XBCON6_INIT           0
#define __XBCON6_VALUE          0x0000

#define __XPERCONC_INIT         0
#define __XPERCONC_VALUE        0x0000
#define __XPERCONS_INIT         0
#define __XPERCONS_VALUE        0x0000

#define __XPERCON_INIT          0
#define __XPERCON_VALUE         0x0000

#define __RTC_KSCCFG_INIT       0
#define __RTC_KSCCFG_VALUE      0x0001
#define __GPT12E_KSCCFG_INIT    0
#define __GPT12E_KSCCFG_VALUE   0x0000
#define __CC2_KSCCFG_INIT       0
#define __CC2_KSCCFG_VALUE      0x0000
#define __MEM_KSCCFG_INIT       0
#define __MEM_KSCCFG_VALUE      0x0001
#define __FL_KSCCFG_INIT        0
#define __FL_KSCCFG_VALUE       0x0001
#define __MCAN_KSCCFG_INIT      0
#define __MCAN_KSCCFG_VALUE     0x0000

#define __ICACHE_CTRL_INIT      0
#define __ICACHE_CTRL_VALUE     0x0000
#define __ICACHE_CTRL_MASK      0x0005
#define __ICACHE_CTRL_DO_MASK   0
#define __ICACHE_EDCON_INIT     0
#define __ICACHE_EDCON_VALUE    0x0000
#define __ICACHE_DACON_INIT     0
#define __ICACHE_DACON_VALUE    0x0000
#define __ICACHE_DACON_MASK     0xFCFD
#define __ICACHE_DACON_DO_MASK  0

#endif /*__NO_CSTART_REGISTER_CONFIG */


/*
 * Define masks for some registrers
 */

#if defined(__CORE_C16X__) || defined(__CORE_ST10__) || defined(__CORE_ST10MAC__)

# define __SYSCON_MASK          0x0480
# define __BUSCON0_MASK         0x06C0

#endif

#if defined(__CORE_XC16X__) || defined(__CORE_SUPER10__) || defined( __CORE_SUPER10M345__ )

# define __EBCMOD0_MASK         0x08FF
# define __FCONCS0_MASK         0x0030

#endif

#define __RSTCON_MASK           0x0020


/*
 * detect if WDT must be enabled
 */
#ifdef WDTCON
# if __WDTCON_INIT
#  define __WDT_ENABLED 1
# else
#  define __WDT_ENABLED 0
# endif
#else
# ifdef WDTREL
#  if __WDTREL_INIT
#   define __WDT_ENABLED 1
#  else
#   define __WDT_ENABLED 0
#  endif
# else
#  define __WDT_ENABLED 0
# endif
#endif


#endif /* CSTART_H*/

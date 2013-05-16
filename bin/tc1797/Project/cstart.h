/**************************************************************************
**                                                                        *
**  FILE        :  cstart.h                                               *
**                                                                        *
**  DESCRIPTION :                                                         *
**      Header file to control the system startup code's general settings *
**      and register initializations. The cstart.c file must be part of   *
**      your project to make use of this cstart.h.                        *
**                                                                        *
**      In the Eclipse environment this file can be modified using the    *
**      C startup code editor, which provides a GUI to modify the         *
**      Configuration settings and register initialization.               *
**                                                                        *
**  Copyright 1996-2010 Altium BV                                         *
**                                                                        *
**************************************************************************/

#ifndef CSTART_H
#define CSTART_H

/*
 * These items are shown on in Eclipse on the C Start Configuration page
 */

#ifndef __NO_CSTART_DEFAULT_CONFIG

/* C Startup settings */
#define __BIV_INIT              1       /* Initialize base address of interrupt vector table */
#define __BTV_INIT              1       /* Initialize base address of trap vector table */
#define __CSA_INIT              1       /* Initialize CSA lists */
#define __C_INIT                1       /* Initialize and clear C variables */
#define __USP_INIT              1       /* Initialize user stack pointer */
#define __ISP_INIT              1       /* Initialize interrupt stack pointer */
#define __A0A1_INIT             1       /* Initialize a0 and a1 for _a0/_a1 addressing */
#define __A8A9_INIT             1       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */

#define __USER_STACK            1       /* Use the user stack (clear PSW.IS) */
#define __WATCHDOG_DISABLE      1       /* Watchdog disable */
#define __USE_ARGC_ARGV         0       /* Enable passing argc/argv to main() */
#define __ARGCV_BUFSIZE       256       /* Buffer size for argv */
#define __CLOCKS_PER_SEC_INIT   0       /* Initialize clocks per sec */
#define __fOSC           20000000       /* Oscillator frequency Hz */

/* Trap Vectors */
#define __RESOLVE_TRAP_0        1       /* Class 0: MMU */
#define __RESOLVE_TRAP_1        1       /* Class 1: Internal protection */
#define __RESOLVE_TRAP_2        1       /* Class 2: Instruction error */
#define __RESOLVE_TRAP_3        1       /* Class 3: Context management */
#define __RESOLVE_TRAP_4        1       /* Class 4: System bus and peripheral errors */
#define __RESOLVE_TRAP_5        1       /* Class 5: Assertion */
#define __RESOLVE_TRAP_6        1       /* Class 6: System call */
#define __RESOLVE_TRAP_7        1       /* Class 7: Non-maskable interrupt */

#endif /* __NO_CSTART_DEFAULT_CONFIG */


/*
 * Control of initialization registers
 *
 * The *_VALUE macros define the value of the register
 * The *_INIT macros must be defined to 0 or 1, specifying whether
 * or not it will be intialized by the cstart.c code.
 *
 * Most registers are not set to be initialized, which means that
 * the CPU's defaults are used. The bus configuration registers will be
 * set by running the 'Target Board Configuration' wizard.
 * The Eclipse environment will automatically apply the CPU default
 * values to the registers. These defaults are defined in the SFR files
 * from the include/sfr directory of the product.
 *
 */
#ifndef __NO_CSTART_REGISTER_CONFIG
/* Non-bus configuration: */
#define __EBU_BOOTCFG_INIT      1
#define __EBU_BOOTCFG_VALUE     0x0000800c
#define __PMI_CON0_INIT         1
#define __PMI_CON0_VALUE        0x00000000
#define __PMI_CON1_INIT         0
#define __PMI_CON1_VALUE        0x00000000
#define __PMI_CON2_INIT         1
#define __PMI_CON2_VALUE        0x02840284
#define __PMU_EIFCON_INIT       0
#define __PMU_EIFCON_VALUE      0x00000000
#define __DMI_CON_INIT          1
#define __DMI_CON_VALUE         0x08020802
#define __PLL_CLC_INIT          0
#define __PLL_CLC_VALUE         0x00000000
#define __SCU_PLLCON0_INIT      0
#define __SCU_PLLCON0_VALUE     0x00000000
#define __SCU_PLLCON1_INIT      0
#define __SCU_PLLCON1_VALUE     0x00000000
#define __SCU_OSCCON_INIT       0
#define __SCU_OSCCON_VALUE      0x00000000
#define __STM_CLC_INIT          0
#define __STM_CLC_VALUE         0x00000000
/* Bus configuration: (set by 'Target Board Configuration' wizard) */
#define __EBU_ADDRSEL0_INIT     0
#define __EBU_ADDRSEL0_VALUE    0x00000000
#define __EBU_ADDRSEL1_INIT     0
#define __EBU_ADDRSEL1_VALUE    0x00000000
#define __EBU_ADDRSEL2_INIT     0
#define __EBU_ADDRSEL2_VALUE    0x00000000
#define __EBU_ADDRSEL3_INIT     0
#define __EBU_ADDRSEL3_VALUE    0x00000000
#define __EBU_ADDRSEL4_INIT     0
#define __EBU_ADDRSEL4_VALUE    0x00000000
#define __EBU_ADDRSEL5_INIT     0
#define __EBU_ADDRSEL5_VALUE    0x00000000
#define __EBU_ADDRSEL6_INIT     0
#define __EBU_ADDRSEL6_VALUE    0x00000000
#define __EBU_BFCON_INIT        0
#define __EBU_BFCON_VALUE       0x00000000
#define __EBU_BUSAP0_INIT       0
#define __EBU_BUSAP0_VALUE      0x00000000
#define __EBU_BUSAP1_INIT       0
#define __EBU_BUSAP1_VALUE      0x00000000
#define __EBU_BUSAP2_INIT       0
#define __EBU_BUSAP2_VALUE      0x00000000
#define __EBU_BUSAP3_INIT       0
#define __EBU_BUSAP3_VALUE      0x00000000
#define __EBU_BUSAP4_INIT       0
#define __EBU_BUSAP4_VALUE      0x00000000
#define __EBU_BUSAP5_INIT       0
#define __EBU_BUSAP5_VALUE      0x00000000
#define __EBU_BUSAP6_INIT       0
#define __EBU_BUSAP6_VALUE      0x00000000
#define __EBU_BUSCON0_INIT      0
#define __EBU_BUSCON0_VALUE     0x00000000
#define __EBU_BUSCON1_INIT      0
#define __EBU_BUSCON1_VALUE     0x00000000
#define __EBU_BUSCON2_INIT      0
#define __EBU_BUSCON2_VALUE     0x00000000
#define __EBU_BUSCON3_INIT      0
#define __EBU_BUSCON3_VALUE     0x00000000
#define __EBU_BUSCON4_INIT      0
#define __EBU_BUSCON4_VALUE     0x00000000
#define __EBU_BUSCON5_INIT      0
#define __EBU_BUSCON5_VALUE     0x00000000
#define __EBU_BUSCON6_INIT      0
#define __EBU_BUSCON6_VALUE     0x00000000
#define __EBU_CLC_INIT          0
#define __EBU_CLC_VALUE         0x00000000
#define __EBU_CON_INIT          0
#define __EBU_CON_VALUE         0x00000000
#define __EBU_EMUAS_INIT        0
#define __EBU_EMUAS_VALUE       0x00000000
#define __EBU_EMUBAP_INIT       0
#define __EBU_EMUBAP_VALUE      0x00000000
#define __EBU_EMUBC_INIT        0
#define __EBU_EMUBC_VALUE       0x00000000
#define __EBU_EMUCON_INIT       0
#define __EBU_EMUCON_VALUE      0x00000000
#define __EBU_EMUOVL_INIT       0
#define __EBU_EMUOVL_VALUE      0x00000000
#define __EBU_SDRMCON0_INIT     0
#define __EBU_SDRMCON0_VALUE    0x00000000
#define __EBU_SDRMCON1_INIT     0
#define __EBU_SDRMCON1_VALUE    0x00000000
#define __EBU_SDRMOD0_INIT      0
#define __EBU_SDRMOD0_VALUE     0x00000000
#define __EBU_SDRMOD1_INIT      0
#define __EBU_SDRMOD1_VALUE     0x00000000
#define __EBU_SDRMREF0_INIT     0
#define __EBU_SDRMREF0_VALUE    0x00000000
#define __EBU_SDRMREF1_INIT     0
#define __EBU_SDRMREF1_VALUE    0x00000000
#define __CBS_MCDBBS_INIT       0
#define __CBS_MCDBBS_VALUE      0x00000000
#define __SBCU_CON_INIT         0
#define __SBCU_CON_VALUE        0x00000000
#define __EBU_BUSRAP1_INIT      0
#define __EBU_BUSRAP1_VALUE     0x00000000
#define __EBU_BUSRAP0_INIT      0
#define __EBU_BUSRAP0_VALUE     0x00000000
#define __EBU_BUSRAP2_INIT      0
#define __EBU_BUSRAP2_VALUE     0x00000000
#define __EBU_BUSRAP3_INIT      0
#define __EBU_BUSRAP3_VALUE     0x00000000
#define __EBU_BUSRCON0_INIT     0
#define __EBU_BUSRCON0_VALUE    0x00000000
#define __EBU_BUSRCON1_INIT     0
#define __EBU_BUSRCON1_VALUE    0x00000000
#define __EBU_BUSRCON2_INIT     0
#define __EBU_BUSRCON2_VALUE    0x00000000
#define __EBU_BUSRCON3_INIT     0
#define __EBU_BUSRCON3_VALUE    0x00000000
#define __EBU_BUSWAP0_INIT      0
#define __EBU_BUSWAP0_VALUE     0x00000000
#define __EBU_BUSWAP1_INIT      0
#define __EBU_BUSWAP1_VALUE     0x00000000
#define __EBU_BUSWAP2_INIT      0
#define __EBU_BUSWAP2_VALUE     0x00000000
#define __EBU_BUSWAP3_INIT      0
#define __EBU_BUSWAP3_VALUE     0x00000000
#define __EBU_BUSWCON0_INIT     0
#define __EBU_BUSWCON0_VALUE    0x00000000
#define __EBU_BUSWCON1_INIT     0
#define __EBU_BUSWCON1_VALUE    0x00000000
#define __EBU_BUSWCON2_INIT     0
#define __EBU_BUSWCON2_VALUE    0x00000000
#define __EBU_BUSWCON3_INIT     0
#define __EBU_BUSWCON3_VALUE    0x00000000
#define __EBU_EXTBOOT_INIT      0
#define __EBU_EXTBOOT_VALUE     0x00000000
#define __EBU_MODCON_INIT       0
#define __EBU_MODCON_VALUE      0x00000000
#define __EBU_DDRNCON_INIT      0
#define __EBU_DDRNCON_VALUE     0x00000000
#define __EBU_DDRNMOD_INIT      0
#define __EBU_DDRNMOD_VALUE     0x00000000
#define __EBU_DDRNMOD2_INIT     0
#define __EBU_DDRNMOD2_VALUE    0x00000000
#define __EBU_DDRNPRLD_INIT     0
#define __EBU_DDRNPRLD_VALUE    0x00000000
#define __EBU_DDRNTAG0_INIT     0
#define __EBU_DDRNTAG0_VALUE    0x00000000
#define __EBU_DDRNTAG1_INIT     0
#define __EBU_DDRNTAG1_VALUE    0x00000000
#define __EBU_DDRNTAG2_INIT     0
#define __EBU_DDRNTAG2_VALUE    0x00000000
#define __EBU_DDRNTAG3_INIT     0
#define __EBU_DDRNTAG3_VALUE    0x00000000
#define __EBU_DLLCON_INIT       0
#define __EBU_DLLCON_VALUE      0x00000000
#define __EBU_SDRMCON_INIT      0
#define __EBU_SDRMCON_VALUE     0x00000000
#define __EBU_SDRMOD_INIT       0
#define __EBU_SDRMOD_VALUE      0x00000000
#define __EBU_SDRMREF_INIT      0
#define __EBU_SDRMREF_VALUE     0x00000000
#define __EBU_SDRSTAT_INIT      0
#define __EBU_SDRSTAT_VALUE     0x00000000

#endif /*__NO_CSTART_REGISTER_CONFIG */

#endif /* CSTART_H*/

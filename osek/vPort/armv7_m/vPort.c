/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine China
 * Open Source Society; either version 1 of the License, or (at developer option)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the U-License for more details.
 * Developer should have received a copy of the U-Licensealong with this program;
 * if not, download from www.tecoss.org(the web page of the T-Engine China Open
 * Source Society).
 *
 * GaInOS-TK is a static configured RTOS, which conformed to OSEK OS 2.2.3 Specification
 * and it is based on uTenux(http://www.uloong.cc).
 *
 * Email: parai@foxmail.com
 * Sourrce Open At: https://github.com/parai/gainos-tk/
 */
#include "vPort.h"
#include "osek_os.h"
#include <stdio.h>

EXPORT 	UB	knl_tmp_stack[cfgTMP_STACK_SZ];

EXPORT void knl_start_hw_timer( void )
{
    /* Setup SysTick Timer for 1 msec interrupts.
     ------------------------------------------
    1. The SysTick_Config() function is a CMSIS function which configure:
       - The SysTick Reload register with value passed as function parameter.
       - Configure the SysTick IRQ priority to the lowest value (0x0F).
       - Reset the SysTick Counter register.
       - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
       - Enable the SysTick Interrupt.
       - Start the SysTick Counter.
    
    2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
       SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
       SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
       inside the misc.c file.

    3. You can change the SysTick IRQ priority by calling the
       NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function 
       call. The NVIC_SetPriority() is defined inside the core_cm3.h file.

    4. To adjust the SysTick time base, use the following formula:
                            
         Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
    
       - Reload Value is the parameter to be passed for SysTick_Config() function
       - Reload Value should not exceed 0xFFFFFF
   */
  if (SysTick_Config(CPU_FREQUENCY / 1000))
  { 
    /* Capture error */ 
    while (1);
  }
}
EXPORT void knl_setup_context( TCB *tcb )
{
    UW pc, xpsr;
    SStackFrame *ssp;

    ID tskid = tcb - knl_tcb_table;
    ssp = knl_gtsk_table[tskid].isstack;
    ssp--;

	pc = (UW)knl_gtsk_table[tskid].task;
	xpsr = TS_PSR_T;                             /* Thumb mode */

    /* CPU context initialization */
    ssp->taskmode  = 0;                          /* Initial taskmode */
    ssp->xpsr = xpsr;                            /* Initial SR */
    ssp->pc = (VP)pc;                            /* Task startup address */
    tcb->tskctxb.ssp = ssp;                      /* System stack */ 
}
#if(cfgCORTEX_M3_ISR == ISR_IN_C) 
/* NOTE: not supported */
EXPORT ISR(SystemTick)
{
    EnterISR();
    knl_timer_handler();
    (void)IncrementCounter(0);
    ExitISR();
} 
#endif

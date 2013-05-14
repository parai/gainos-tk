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
#include "knl_timer.h"

LOCAL 	UB	knl_tmp_stack[cfgTMP_STACK_SZ];
/*
 *    Function Name : disint
 *    Description   : Disable external interrupt,CPSR interrupt flag is in  disabled status.
 */
EXPORT imask_t disint()
{
	__asm("movw r2,PSW");
	__asm("BCLR PSW_IEN");
}

/*
 *    Function Name : enaint
 *    Description   : Enable external interrupt (restore to original state),
 *                    Updates CPSR interrupt disabled flag with the intsts interrupt flag.
 */
EXPORT void enaint(imask_t mask)
{
	__asm("movw PSW,r2");
}

EXPORT imask_t knl_getPRIMASK ( void )
{
	__asm("movw r2,PSW");
}
EXPORT void knl_start_hw_timer( void )
{
}
EXPORT void knl_setup_context( TCB *tcb )
{
    SStackFrame     *ssp;
    UW pc;
    ID tskid = tcb - knl_tcb_table;
    ssp = knl_gtsk_table[tskid].isstack;
    ssp--;
    pc = (UW)knl_gtsk_table[tskid].task;
    ssp->CSP = (UH)(pc>>16);
    ssp->IP = (UH)pc;
    ssp->PSW = 1<<11; /* Global Register Bank, Interrupt Enable. */
    tcb->tskctxb.ssp = ssp;         /* System stack */
}
static void l_dispatch0(void)
{
}
void knl_force_dispatch(void)
{
}

void knl_dispatch_entry(void)
{

}
ISR(SystemTick)
{ 
    EnterISR(); 
	knl_timer_handler();
	(void)IncrementCounter(0);
	ExitISR();	
}

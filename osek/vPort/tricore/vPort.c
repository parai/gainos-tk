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
#include "knl_task.h"

EXPORT void knl_start_hw_timer( void )
{
}
EXPORT void knl_setup_context( TCB *tcb )
{
    SStackFrame     *ssp;
    UW pc;
    ID tskid;

    tskid = tcb - knl_tcb_table;
    /* half of the Stack Space for system stack and the other for user stack */
    ssp = knl_gtsk_table[tskid].isstack;
    ssp--;

    pc = (UW)knl_gtsk_table[tskid].task;
    ssp->taskmode  = 0;             /* Initial taskmode */

    tcb->tskctxb.ssp = ssp;         /* System stack */
}

/* use RTC as system tick, only enable counter T14 overflow interrupt.
 * configured by DAVE
 */
ISR(SystemTick,0x6E)
{ 
    EnterISR(); 
	knl_timer_handler();
	(void)IncrementCounter(0);
	ExitISR();	
}

EXPORT void enaint(imask_t mask)
{
}

EXPORT imask_t disint()
{
	return 0;
}
EXPORT void knl_force_dispatch(void)
{

}
EXPORT void knl_dispatch_entry(void)
{

}

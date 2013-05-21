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
/*
 * This vPort is For TASKING VX-toolset C166.
 * Run OK on XC2300 family chip.
 */
#include "portable.h"
#include "knl_timer.h"
#include "knl_task.h"

EXPORT void knl_start_hw_timer( void )
{
}

EXPORT void knl_setup_context( TCB *tcb )
{
    tcb->tskctxb.ssp = tcb->isstack;
    tcb->tskctxb.usp = (VP)((UW)(tcb->isstack)-tcb->stksz);
    tcb->tskctxb.dispatcher = 1;
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

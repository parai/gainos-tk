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
#include "knl_wait.h"
#include "knl_task.h"
#include "knl_queue.h"
#include "knl_timer.h"
#if(cfgOS_TK_EXTEND == STD_ON)
EXPORT WSPEC    knl_wspec_slp = { TTW_SLP};//,NULL,NULL};
/*
 * Change the active task state to wait state and connect to the
 * timer event queue.
 *	Normally, 'knl_ctxtsk' is in the RUN state, but when an interrupt
 *	occurs during executing system call, 'knl_ctxtsk' may become the
 *	other state by system call called in the interrupt handler.
 *	However, it does not be in WAIT state.
 *
 *	"include/tk/typedef.h"
 *	typedef	W		TMO;
 *	typedef UW		RELTIM;
 *	#define TMO_FEVR	(UINT_MAX)
 */
EXPORT void knl_make_wait( TickType tmout)
{
	switch ( knl_ctxtsk->state ) {
	  case TS_READY:
		// knl_make_non_ready(knl_ctxtsk);
		knl_ctxtsk->state = TS_WAIT;
		knl_search_schedtsk();
		break;
	  case TS_SUSPEND:
		knl_ctxtsk->state = TS_WAITSUS;
		break;
	}
	knl_timer_insert(&knl_ctxtsk->wtmeb, tmout,(CBACK)knl_wait_release_tmout, knl_ctxtsk);
}

EXPORT void knl_wait_release( TCB *tcb )
{
	knl_timer_delete(&tcb->wtmeb);
	QueRemove(&tcb->tskque);
	knl_make_non_wait(tcb);
}

EXPORT void knl_wait_release_ok( TCB *tcb )
{
	knl_wait_release(tcb);
	*tcb->wercd = E_OK;
}

EXPORT void knl_wait_release_tmout( TCB *tcb )
{
	QueRemove(&tcb->tskque);
	knl_make_non_wait(tcb);
    //if ( tcb->wspec->rel_wai_hook != NULL ) {
	//	(*tcb->wspec->rel_wai_hook)(tcb);
	//}
}

/*
 * Update the task state to release wait. When it becomes ready state,
 * connect to the ready queue.
 * Call when the task is in the wait state (including double wait).
 */
EXPORT void knl_make_non_wait( TCB *tcb )
{
	if ( tcb->state == TS_WAIT ) {
	    tcb->state = TS_READY;
		knl_make_runnable(tcb);
	} else {
		tcb->state = TS_SUSPEND;
	}
}
#endif /* cfgOS_TK_EXTEND */

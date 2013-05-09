/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#include "knl_task.h"
#include "knl_timer.h"
#include "vPort.h"

EXPORT INT	knl_dispatch_disabled;
EXPORT TCB	*knl_ctxtsk;
EXPORT TCB	*knl_schedtsk;
EXPORT RDYQUE	knl_ready_queue;
EXPORT	INT	    knl_taskindp = 0;
EXPORT	UINT	knl_taskmode;
EXPORT TCB	    knl_tcb_table[cfgOSEK_TASK_NUM];

/*
 * TCB Initialization
 */
EXPORT void knl_task_initialize( void )
{
	/* Initialize task execution control information */
	knl_ctxtsk = knl_schedtsk = NULL;
	knl_ready_queue_initialize(&knl_ready_queue);
	knl_dispatch_disabled = DDS_ENABLE;
}

EXPORT void knl_reschedule( void )
{
	TCB	*toptsk;

	toptsk = knl_ready_queue_top(&knl_ready_queue);
	if ( knl_schedtsk != toptsk ) {
		knl_schedtsk = toptsk;
		knl_dispatch_request();
	}
}

/*
 * Prepare task execution.
 */
EXPORT void knl_make_dormant( TCB *tcb )
{
    ID tskid = tcb - knl_tcb_table;
	/* Initialize variables which should be reset at DORMANT state */
	tcb->state	= TS_DORMANT;
	tcb->priority = knl_gtsk_table[tskid].itskpri;

	tcb->klockwait	= FALSE;
	tcb->klocked	= FALSE;

    QueInit(&tcb->resque);

	/* Set context to start task */
	knl_setup_context(tcb);
}

/*
 * Set task to READY state.
 *	Update the task state and insert in the ready queue. If necessary, 
 *	update 'knl_schedtsk' and request to start task dispatcher. 
 */
EXPORT void knl_make_ready( TCB *tcb )
{
	tcb->state = TS_READY;
	if ( knl_ready_queue_insert(&knl_ready_queue, tcb) ) {
		knl_schedtsk = tcb;
		knl_dispatch_request();
	}
}
/*
 * Set task to non-executable state.
 *	Delete the task from the ready queue.
 *	If the deleted task is 'knl_schedtsk', set 'knl_schedtsk' to the
 *	highest priority task in the ready queue. 
 *	'tcb' task must be READY.
 */
EXPORT void knl_make_non_ready( TCB *tcb )
{
	knl_ready_queue_delete(&knl_ready_queue, tcb);
	if ( knl_schedtsk == tcb ) {
		knl_schedtsk = knl_ready_queue_top(&knl_ready_queue);
		knl_dispatch_request();
	}
}

/* Start all the tasks configured in autosatrt */
EXPORT void knl_tasks_autostart(void)
{
    TaskType i;
    TCB* tcb;
    knl_task_initialize();
    for(i=0,tcb=knl_tcb_table; i < cfgOSEK_TASK_NUM; i++,tcb++)
    {
        knl_make_dormant(tcb);
        if((knl_gtsk_table[i].tskatr) & AUTOSTART)
        { 
            knl_make_ready(tcb);
        }
    }
}

/*
 * Change task priority.
 */
EXPORT void knl_change_task_priority( TCB *tcb, PRI priority )
{
//	if ( tcb->state == TS_READY ) {
		/*
		 * When deleting a task from the ready queue, 
		 * a value in the 'priority' field in TCB is needed. 
		 * Therefore you need to delete the task from the
		 * ready queue before changing 'tcb->priority.'
		 */
		knl_ready_queue_delete(&knl_ready_queue, tcb);
		tcb->priority = (UB)priority;
		knl_ready_queue_insert(&knl_ready_queue, tcb);
		knl_reschedule();
//	}
}

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
 *	#define TMO_FEVR	(-1)
 */
EXPORT void knl_make_wait( TickType tmout)
{
	switch ( knl_ctxtsk->state ) {
	  case TS_READY:
		knl_make_non_ready(knl_ctxtsk);
		knl_ctxtsk->state = TS_WAIT;
		break;
	  case TS_SUSPEND:
		knl_ctxtsk->state = TS_WAITSUS;
		break;
	}
	knl_timer_insert(&knl_ctxtsk->wtmeb, tmout,(CBACK)knl_wait_release_tmout, knl_ctxtsk);
}

EXPORT void knl_wait_release_ok( TCB *tcb )
{
	knl_wait_release(tcb);
	*tcb->wercd = E_OK;
}

/*
 * Update the task state to release wait. When it becomes ready state,
 * connect to the ready queue.
 * Call when the task is in the wait state (including double wait).
 */
EXPORT void knl_make_non_wait( TCB *tcb )
{
	if ( tcb->state == TS_WAIT ) {
		knl_make_ready(tcb);
	} else {
		tcb->state = TS_SUSPEND;
	}
}

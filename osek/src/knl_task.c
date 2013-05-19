/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine Chin a
 * Open Source Society; either version 1 of the License, or (at developer opti on)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES S FOR
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
#include "knl_task.h"
#include "knl_timer.h"
#include "knl_queue.h"
#include "portable.h"

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
    // remove it for C166(USP and SSP)
	//tcb->state	= TS_DORMANT;
	tcb->priority = knl_gtsk_table[tskid].itskpri;

//	tcb->klockwait	= FALSE;
//	tcb->klocked	= FALSE;

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
EXPORT void knl_task_init(void)
{
    TaskType i;
    TCB* tcb;
    knl_task_initialize();
    for(i=0,tcb=knl_tcb_table; i < cfgOSEK_TASK_NUM; i++,tcb++)
    {
        if((knl_gtsk_table[i].tskatr) & AUTOSTART)
        { 
        	knl_make_dormant(tcb);
            knl_make_ready(tcb);
        }
        else
        {
        	tcb->state = TS_SUSPEND;
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


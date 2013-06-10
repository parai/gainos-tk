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
#include "knl_event.h"
#include "portable.h"

EXPORT INT	knl_dispatch_disabled;
EXPORT TCB	*knl_ctxtsk;
EXPORT TCB	*knl_schedtsk;
EXPORT RDYQUE	knl_ready_queue;
EXPORT	INT	    knl_taskindp = 0;
EXPORT	UINT	knl_taskmode;
EXPORT TCB	    knl_tcb_table[cfgOSEK_TASK_NUM];
EXPORT AppModeType knl_app_mode;

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
	if ( knl_schedtsk != toptsk ){
	    knl_ready_queue_delete(&knl_ready_queue, toptsk);
	    knl_ready_queue_insert_top(&knl_ready_queue, knl_schedtsk);
		knl_schedtsk = toptsk;
		knl_dispatch_request();
	}
}

/*
 * Prepare task execution.
 */
EXPORT void knl_make_active( TCB *tcb )
{
	tcb->priority = knl_gtsk_table[tcb->tskid].itskpri;
	#if(cfgOSEK_EVENTFLAG_NUM > 0)
    {
        ID flgid;
        flgid = knl_gtsk_table[tcb->tskid].flgid;
        if(flgid != INVALID_EVENT)
        {
            knl_flgcb_table[flgid].flgptn=NO_EVENT;
            knl_flgcb_table[flgid].waipth=NO_EVENT;
        }
    }
    #endif

    QueInit(&tcb->resque);

	/* Set context to start task */
	knl_setup_context(tcb);

	knl_make_runnable(tcb);
}
/*
 * Set task to runnable state.
 *	Update the task state and insert in the ready queue. If necessary,
 *	update 'knl_schedtsk' and request to start task dispatcher.
 */
EXPORT void knl_make_runnable( TCB *tcb )
{
	tcb->state = TS_READY;
	if(NULL != knl_schedtsk)
	{
	    if(tcb->priority < knl_schedtsk->priority)
	    {   /* tcb has higher priority */
	        //when task is non-preemtable,its priority will be the highest when run.
            knl_ready_queue_insert_top(&knl_ready_queue, knl_schedtsk);
	    }
	    else
	    {   /* tcb has lower priority */
	        knl_ready_queue_insert(&knl_ready_queue, tcb);
	        return;
	    }
	}
	knl_schedtsk = tcb;
	knl_dispatch_request();
}

/*
 * search the next high ready schedtsk
 * and then detach it from the ready queue, as it is able to run
 */
EXPORT void knl_search_schedtsk(void)
{
    knl_schedtsk = knl_ready_queue_top(&knl_ready_queue);
    if(NULL != knl_schedtsk)
    {
        knl_ready_queue_delete(&knl_ready_queue, knl_schedtsk);
    }
}
/* put current running task into ready queue,and find the next high ready task.*/
EXPORT void knl_preempt(void)
{
    knl_ready_queue_insert_top(&knl_ready_queue, knl_schedtsk);
    knl_search_schedtsk();
    knl_dispatch_request();
}

/* 	Initialize all the  tasks */
EXPORT void knl_task_init(void)
{
    TaskType i;
    TCB* tcb;
    knl_task_initialize();
    for(i=0,tcb=knl_tcb_table; i < cfgOSEK_TASK_NUM; i++,tcb++)
    {
        tcb->tskid = i;
        tcb->tskatr = knl_gtsk_table[i].tskatr;
        QueInit(&tcb->tskque);
        tcb->task = knl_gtsk_table[i].task; /* save task entry */
        tcb->isstack = knl_gtsk_table[i].isstack; /* save task stack buffer */
        tcb->stksz  = knl_gtsk_table[i].stksz;
        tcb->runpri = knl_gtsk_table[i].runpri;
        tcb->actcnt = 0;
        if((tcb->tskatr&APPMODEMASK) == knl_app_mode)
        {
        	knl_make_active(tcb);
        }
        else
        {
        	tcb->state = TS_DORMANT;
        }
    }
}


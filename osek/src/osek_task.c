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
#include "osek_os.h"
#include "knl_task.h"
#include "knl_timer.h"
#include "knl_queue.h"
#include "knl_wait.h"
#include "portable.h"
/* |------------------+------------------------------------------------------------| */
/* | Syntax:          | StatusType ActivateTask ( TaskType <TaskID> )              | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (In):  | TaskID: Task reference                                     | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (Out): | none                                                       | */
/* |------------------+------------------------------------------------------------| */
/* | Description:     | The task <TaskID> is transferred from the suspended state  | */
/* |                  | into the ready state. The operating system ensures that    | */
/* |                  | the task code is being executed from the first statement.  | */
/* |------------------+------------------------------------------------------------| */
/* | Particularities: | 1) The service may be called from interrupt level and from | */
/* |                  | task level (see Figure 12-1(os223.doc)).                   | */
/* |                  | 2) Rescheduling after the call to ActivateTask depends on  | */
/* |                  | the place it is called from (ISR, non preemptable task,    | */
/* |                  | preemptable task).                                         | */
/* |                  | 3)If E_OS_LIMIT is returned the activation is ignored.     | */
/* |                  | 4)When an extended task is transferred from suspended      | */
/* |                  | state into ready state all its events are cleared.         | */
/* |------------------+------------------------------------------------------------| */
/* | Status:          | Standard:                                                  | */
/* |                  | 1) No error, E_OK                                          | */
/* |                  | 2) Too many task activations of <TaskID>, E_OS_LIMIT       | */
/* |                  | Extended:                                                  | */
/* |                  | 1) Task <TaskID> is invalid, E_OS_ID                       | */
/* |------------------+------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                     | */
/* |------------------+------------------------------------------------------------| */
StatusType ActivateTask ( TaskType TaskID )
{
	StatusType ercd = E_OK;
	TCB *tcb;
	TSTAT	state;
	OS_CHECK((TaskID<cfgOSEK_TASK_NUM),E_OS_ID);
	tcb = &knl_tcb_table[TaskID];
	BEGIN_CRITICAL_SECTION;
	state = (TSTAT)tcb->state;
	if (TS_DORMANT == state) {
        knl_make_active(tcb);
	} else {
	    #if((cfgOS_CONFORMANCE_CLASS == ECC2) || (cfgOS_CONFORMANCE_CLASS == BCC2))
	    if(tcb->actcnt < knl_gtsk_table[TaskID].maxact)
	    {
	        tcb->actcnt += 1;
	    }
	    else
	    #endif
	    {
	    	ercd = E_OS_LIMIT;
		}
	}
	END_CRITICAL_SECTION;

	Error_Exit:
	return ercd;
}

/* |------------------+--------------------------------------------------------------| */
/* | Syntax:          | StatusType TerminateTask ( void )                            | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (In):  | none                                                         | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (Out): | none                                                         | */
/* |------------------+--------------------------------------------------------------| */
/* | Description:     | This service causes the termination of the calling task. The | */
/* |                  | calling task is transferred from the running state into the  | */
/* |                  | suspended state.                                             | */
/* |------------------+--------------------------------------------------------------| */
/* | Particularities: | 1) An internal resource assigned to the calling task is      | */
/* |                  | automatically released. Other resources occupied by the task | */
/* |                  | shall have been released before the call to TerminateTask.   | */
/* |                  | If a resource is still occupied in standard status the       | */
/* |                  | behaviour is undefined.                                      | */
/* |                  | 2) If the call was successful, TerminateTask does not return | */
/* |                  | to the call level and the status can not be evaluated.       | */
/* |                  | 3) If the version with extended status is used, the service  | */
/* |                  | returns in case of error, and provides a status which can be | */
/* |                  | evaluated in the application.                                | */
/* |                  | 4) If the service TerminateTask is called successfully, it   | */
/* |                  | enforces a rescheduling.                                     | */
/* |                  | 5) Ending a task function without call to TerminateTask or   | */
/* |                  | ChainTask is strictly forbidden and may leave the system in  | */
/* |                  | an undefined state.                                          | */
/* |------------------+--------------------------------------------------------------| */
/* | Status:          | Standard:                                                    | */
/* |                  | 1)No return to call level                                    | */
/* |                  | Extended:                                                    | */
/* |                  | 1) Task still occupies resources, E_OS_RESOURCE              | */
/* |                  | 2) Call at interrupt level, E_OS_CALLEVEL                    | */
/* |------------------+--------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                       | */
/* |------------------+--------------------------------------------------------------| */
StatusType TerminateTask ( void )
{
	StatusType ercd = E_NOT_OK;
	OS_CHECK_EXT(!in_indp(),E_OS_CALLEVEL);
	OS_CHECK_EXT(isQueEmpty(&knl_ctxtsk->resque),E_OS_RESOURCE);
	DISABLE_INTERRUPT;

	knl_ctxtsk->state = TS_DORMANT;
	knl_search_schedtsk();
	#if((cfgOS_CONFORMANCE_CLASS == ECC2) || (cfgOS_CONFORMANCE_CLASS == BCC2))
	if(knl_ctxtsk->actcnt > 0)
	{
	    knl_ctxtsk->actcnt -= 1;
	    knl_make_active(knl_ctxtsk);
	}
    #endif
	knl_force_dispatch();
	/* No return */

	Error_Exit:
	return ercd;
}

/* |------------------+-------------------------------------------------------------| */
/* | Syntax:          | StatusType ChainTask ( TaskType <TaskID> )                  | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (In):  | TaskID Reference to the sequential succeeding task to       | */
/* |                  | be activated.                                               | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (Out): | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Description:     | This service causes the termination of the calling task.    | */
/* |                  | After termination of the calling task a succeeding task     | */
/* |                  | <TaskID> is activated. Using this service, it ensures       | */
/* |                  | that the succeeding task starts to run at the earliest      | */
/* |                  | after the calling task has been terminated.                 | */
/* |------------------+-------------------------------------------------------------| */
/* | Particularities: | 1. If the succeeding task is identical with the current     | */
/* |                  | task, this does not result in multiple requests. The task   | */
/* |                  | is not transferred to the suspended state, but will         | */
/* |                  | immediately become ready again.                             | */
/* |                  | 2. An internal resource assigned to the calling task is     | */
/* |                  | automatically released, even if the succeeding task is      | */
/* |                  | identical with the current task. Other resources occupied   | */
/* |                  | by the calling shall have been released before ChainTask    | */
/* |                  | is called. If a resource is still occupied in standard      | */
/* |                  | status the behaviour is undefined.                          | */
/* |                  | 3. If called successfully, ChainTask does not return to     | */
/* |                  | the call level and the status can not be evaluated.         | */
/* |                  | 4. In case of error the service returns to the calling      | */
/* |                  | task and provides a status which can then be evaluated      | */
/* |                  | in the application.                                         | */
/* |                  | 5.If the service ChainTask is called successfully, this     | */
/* |                  | enforces a rescheduling.                                    | */
/* |                  | 6. Ending a task function without call to TerminateTask     | */
/* |                  | or ChainTask is strictly forbidden and may leave the system | */
/* |                  | in an undefined state.                                      | */
/* |                  | 7. If E_OS_LIMIT is returned the activation is ignored.     | */
/* |                  | 8. When an extended task is transferred from suspended      | */
/* |                  | state into ready state all its events are cleared.          | */
/* |------------------+-------------------------------------------------------------| */
/* | Status:          | Standard:                                                   | */
/* |                  | 1. No return to call level                                  | */
/* |                  | 2. Too many task activations of <TaskID>, E_OS_LIMIT        | */
/* |                  | Extended:                                                   | */
/* |                  | 1. Task <TaskID> is invalid, E_OS_ID                        | */
/* |                  | 2. Calling task still occupies resources, E_OS_RESOURCE     | */
/* |                  | 3. Call at interrupt level, E_OS_CALLEVEL                   | */
/* |------------------+-------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                      | */
/* |------------------+-------------------------------------------------------------| */
StatusType ChainTask ( TaskType TaskID )
{
	StatusType ercd = E_NOT_OK;
	TCB * tcb;
	TSTAT state;

	OS_CHECK((TaskID<cfgOSEK_TASK_NUM),E_OS_ID);
    OS_CHECK_EXT(!in_indp(),E_OS_CALLEVEL);
	OS_CHECK_EXT(isQueEmpty(&knl_ctxtsk->resque),E_OS_RESOURCE);
	DISABLE_INTERRUPT;
    if(TaskID == knl_ctxtsk->tskid){
        /* chain to itself */
        knl_search_schedtsk();
        knl_make_active(knl_ctxtsk);
    }
    else{
        /* firstly terminate current running task knl_ctxtsk,
         * and then activate TaskID */
      	tcb = &knl_tcb_table[TaskID];
        state = (TSTAT)tcb->state;
    	if (TS_DORMANT != state) {
    	    #if((cfgOS_CONFORMANCE_CLASS == ECC2) || (cfgOS_CONFORMANCE_CLASS == BCC2))
    	    if(tcb->actcnt < knl_gtsk_table[TaskID].maxact)
    	    {
    	        tcb->actcnt += 1;
    	    }
    	    else
    	    #endif
    	    {
    	    	ercd = E_OS_LIMIT;
    	    	goto Error_Exit;
    		}
    	}
    	
    	knl_ctxtsk->state = TS_DORMANT;
    	knl_search_schedtsk();
    	#if((cfgOS_CONFORMANCE_CLASS == ECC2) || (cfgOS_CONFORMANCE_CLASS == BCC2))
    	if(knl_ctxtsk->actcnt > 0)
    	{
    	    knl_ctxtsk->actcnt -= 1;
    	    knl_make_active(knl_ctxtsk);
    	}
        #endif
        if (TS_DORMANT == state) {
            knl_make_active(tcb);
    	}
    }
    knl_force_dispatch();

	/* No return */
	Error_Exit:
    return ercd;
}

/* |------------------+-------------------------------------------------------------| */
/* | Syntax:          | StatusType Schedule ( void )                                | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (In):  | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (Out): | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Description:     | If a higher-priority task is ready, the internal resource   | */
/* |                  | of the task is released, the current task is put into the   | */
/* |                  | ready state, its context is saved and the higher-priority   | */
/* |                  | task is executed. Otherwise the calling task is continued.  | */
/* |------------------+-------------------------------------------------------------| */
/* | Particularities: | Rescheduling only takes place if the task an internal       | */
/* |                  | resource is assigned to the calling task during             | */
/* |                  | system generation. For these tasks, Schedule enables a      | */
/* |                  | processor assignment to other tasks with lower or equal     | */
/* |                  | priority than the ceiling priority of the internal resource | */
/* |                  | and higher priority than the priority of the calling task   | */
/* |                  | in application-specific locations. When returning from      | */
/* |                  | Schedule, the internal resource has been taken again.       | */
/* |                  | This service has no influence on tasks with no internal     | */
/* |                  | resource assigned (preemptable tasks).                      | */
/* |------------------+-------------------------------------------------------------| */
/* | Status:          | Standard:                                                   | */
/* |                  | 1. No error, E_OK                                           | */
/* |                  | Extended:                                                   | */
/* |                  | 1. Call at interrupt level, E_OS_CALLEVEL                   | */
/* |                  | 2. Calling task occupies resources, E_OS_RESOURCE           | */
/* |------------------+-------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                      | */
/* |------------------+-------------------------------------------------------------| */
StatusType Schedule ( void )
{
    StatusType ercd = E_NOT_OK;
	OS_CHECK_EXT(!in_indp(),E_OS_CALLEVEL);
	OS_CHECK_EXT(isQueEmpty(&knl_ctxtsk->resque),E_OS_RESOURCE);
	//As Internal Resource was not supported,So in fact this API only has effect on
	//Non-preemtable Task.
	BEGIN_CRITICAL_SECTION;
    knl_reschedule();
	END_CRITICAL_SECTION;
	Error_Exit:
    return ercd;
}

/* |------------------+---------------------------------------------------------| */
/* | Syntax:          | StatusType GetTaskID ( TaskRefType <TaskID> )           | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (In):  | none                                                    | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (Out): | TaskID Reference to the task which is currently running | */
/* |------------------+---------------------------------------------------------| */
/* | Description:     | GetTaskID returns the information about the TaskID of   | */
/* |                  | the task which is currently running.                    | */
/* |------------------+---------------------------------------------------------| */
/* | Particularities: | 1. Allowed on task level, ISR level and in several hook | */
/* |                  | routines (see Figure 12-1(os223)).                      | */
/* |                  | 2. This service is intended to be used by library       | */
/* |                  | functions and hook routines.                            | */
/* |                  | 3. If <TaskID> can't be evaluated (no task currently    | */
/* |                  | running), the service returns INVALID_TASK as TaskType. | */
/* |------------------+---------------------------------------------------------| */
/* | Status:          | Standard:  No error, E_OK                               | */
/* |                  | Extended:  No error, E_OK                               | */
/* |------------------+---------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                  | */
/* |------------------+---------------------------------------------------------| */
StatusType GetTaskID ( TaskRefType TaskID )
{
	if(NULL != knl_ctxtsk)
	{
	    *TaskID = knl_ctxtsk-knl_tcb_table;
	}
	else
	{
	    *TaskID = INVALID_TASK;
	}
	return E_OK;
}

/* |------------------+-------------------------------------------------------| */
/* | Syntax:          | StatusType GetTaskState ( TaskType <TaskID>,          | */
/* |                  | TaskStateRefType <State> )                            | */
/* |------------------+-------------------------------------------------------| */
/* | Parameter (In):  | TaskID: Task reference                                | */
/* |------------------+-------------------------------------------------------| */
/* | Parameter (Out): | State: Reference to the state of the task <TaskID>    | */
/* |------------------+-------------------------------------------------------| */
/* | Description:     | Returns the state of a task (running, ready, waiting, | */
/* |                  | suspended) at the time of calling GetTaskState.       | */
/* |------------------+-------------------------------------------------------| */
/* | Particularities: | The service may be called from interrupt service      | */
/* |                  | routines, task level, and some hook routines (see     | */
/* |                  | Figure 12-1(os223.doc)). When a call is made from a   | */
/* |                  | task in a full preemptive system, the result may      | */
/* |                  | already be incorrect at the time of evaluation.       | */
/* |                  | When the service is called for a task, which is       | */
/* |                  | activated more than once, the state is set to         | */
/* |                  | running if any instance of the task is running.       | */
/* |------------------+-------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                              | */
/* |                  | Extended: Task <TaskID> is invalid, E_OS_ID           | */
/* |------------------+-------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                | */
/* |------------------+-------------------------------------------------------| */
StatusType GetTaskState ( TaskType TaskID,TaskStateRefType State )
{
	StatusType ercd = E_OK;
	TCB* tcb;
	TSTAT state;
	OS_CHECK((TaskID<cfgOSEK_TASK_NUM),E_OS_ID);
	tcb = &knl_tcb_table[TaskID];
	state = (TSTAT)tcb->state;
	if(TS_READY== state)
	{
	    if(knl_ctxtsk == tcb)
	    {
	        *State = RUNNING;
	    }
	    else
	    {
	        *State = READY;
	    }
	}
	else if(TS_WAIT == state)
	{
	    *State = WAITING;
	}
	else
	{
	    *State = SUSPENDED;
	}
Error_Exit:
	return ercd;
}

#if(cfgOS_TK_EXTEND == STD_ON)
//Extended Task: SleepTask
//Sleep current running task for a period of time determined by parameter <Timeout>
//but if <Timeout> == TMO_FEVR, the current running task will sleep forever.
//when task is in sleeping state, you can wake up it by calling WakeUpTask(TaskID).
//But this API is really not advised, as it is "»­ÉßÌí×ã" for OSEK os.
//And also may it be conflict with WaitEvent/SetEvent.
//File related: knl_timer.h/c, knl_wait.h/c
StatusType SleepTask ( TickType Timeout )
{
    StatusType ercd = E_OK;
    OS_CHECK_EXT(!in_indp(),E_OS_CALLEVEL);
	OS_CHECK_EXT(isQueEmpty(&knl_ctxtsk->resque),E_OS_RESOURCE);

	BEGIN_CRITICAL_SECTION;

    if ( knl_ctxtsk->wupcnt > 0 ) {
        knl_ctxtsk->wupcnt--;
    } else {
        ercd = E_OS_TMOUT;
        if ( Timeout != 0 ) {
            knl_ctxtsk->wspec = &knl_wspec_slp;
            knl_ctxtsk->wid = 0;
            knl_ctxtsk->wercd = &ercd;
            knl_make_wait(Timeout);
            QueInit(&knl_ctxtsk->tskque);
        }
    }

    END_CRITICAL_SECTION;
Error_Exit:
	return ercd;
}

//Extended Task: WakeUpTask
//Wake up the task which is in sleeping state so that the sleeping task 
//can prepare to resume to run.
//But this API is really not advised, as it is "»­ÉßÌí×ã" for OSEK os.
//And also may it be conflict with WaitEvent/SetEvent.
//File related: knl_timer.h/c, knl_wait.h/c
StatusType WakeUpTask ( TaskType TaskID )
{
    StatusType ercd = E_OK;
    TCB	*tcb;
	TSTAT	state;
    OS_CHECK((TaskID<cfgOSEK_TASK_NUM),E_OS_ID);
    OS_CHECK((TaskID != knl_ctxtsk->tskid),E_OS_ID);

    tcb = &knl_tcb_table[TaskID];
	BEGIN_CRITICAL_SECTION;
	state = (TSTAT)tcb->state;
	if ( !knl_task_alive(state) ) {
		ercd = E_OS_ID;

	} else if ( (state & TS_WAIT) != 0 && tcb->wspec == &knl_wspec_slp ) {
		knl_wait_release_ok(tcb);

	} else if ( tcb->wupcnt == UINT_MAX ) {
		ercd = E_OS_QOVR;
	} else {
		++tcb->wupcnt;
	}
	END_CRITICAL_SECTION;

Error_Exit:
	return ercd;
}
#endif /* cfgOS_TK_EXTEND */

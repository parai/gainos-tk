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
#include "knl_event.h"
#include "knl_queue.h"
#include "portable.h"
#if(cfgOSEK_EVENTFLAG_NUM > 0)
EXPORT FLGCB knl_flgcb_table[cfgOSEK_EVENTFLAG_NUM];
/* |------------------+----------------------------------------------------------| */
/* | Syntax:          | StatusType SetEvent ( TaskType <TaskID>                  | */
/* |                  | EventMaskType <Mask> )                                   | */
/* |------------------+----------------------------------------------------------| */
/* | Parameter (In):  | TaskID:Reference to the task for which one or several    | */
/* |                  | events are to be set.                                    | */
/* |                  | Mask:Mask of the events to be set                        | */
/* |------------------+----------------------------------------------------------| */
/* | Parameter (Out): | none                                                     | */
/* |------------------+----------------------------------------------------------| */
/* | Description:     | 1.The service may be called from an interrupt service    | */
/* |                  | routine and from the task level, but not from hook       | */
/* |                  | routines.                                                | */
/* |                  | 2.The events of task <TaskID> are set according to the   | */
/* |                  | event mask <Mask>. Calling SetEvent causes the task      | */
/* |                  | <TaskID> to be transferred to the ready state, if it     | */
/* |                  | was waiting for at least one of the events specified     | */
/* |                  | in <Mask>.                                               | */
/* |------------------+----------------------------------------------------------| */
/* | Particularities: | Any events not set in the event mask remain unchanged.   | */
/* |------------------+----------------------------------------------------------| */
/* | Status:          | Standard: 1.No error, E_OK                               | */
/* |                  | Extended: 2.Task <TaskID> is invalid, E_OS_ID            | */
/* |                  | 3.Referenced task is no extended task, E_OS_ACCESS       | */
/* |                  | 4.Events can not be set as the referenced task is in the | */
/* |                  | suspended state, E_OS_STATE                              | */
/* |------------------+----------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                               | */
/* |------------------+----------------------------------------------------------| */
StatusType SetEvent ( TaskType TaskID , EventMaskType Mask )
{
	StatusType ercd = E_OK;
    ID flgid;
    FLGCB *flgcb;
    TCB *tcb;
    OS_CHECK_EXT((TaskID < cfgOSEK_TASK_NUM),E_OS_ID);
    flgid = knl_gtsk_table[TaskID].flgid;
    OS_CHECK_EXT((flgid != INVALID_EVENT),E_OS_ACCESS);
    tcb = &knl_tcb_table[TaskID];
    OS_CHECK_EXT(((tcb->state & (TS_READY | TS_WAIT)) != 0),E_OS_STATE);
    
    flgcb = &knl_flgcb_table[flgid];
    BEGIN_CRITICAL_SECTION;
    flgcb->flgptn |= Mask;
    if((flgcb->flgptn & flgcb->waipth) != NO_EVENT)
    {
        flgcb->waipth = NO_EVENT;
        tcb->state = TS_READY;
        knl_make_runnable(tcb);
    }
    END_CRITICAL_SECTION;
       
  Error_Exit:
    #if(cfgOS_ERROR_HOOK == STD_ON)
	if(E_OK != ercd)
	{
    	BEGIN_CRITICAL_SECTION;
    	_errorhook_svcid = OSServiceId_SetEvent;
    	_errorhook_par1.tskid = TaskID;
    	_errorhook_par2.mask = Mask;
    	ErrorHook(ercd);
    	END_CRITICAL_SECTION;
    }
	#endif /* cfgOS_ERROR_HOOK */
	return ercd;
}

/* |------------------+---------------------------------------------------------| */
/* | Syntax:          | StatusType ClearEvent ( EventMaskType <Mask> )          | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (In)   | Mask:Mask of the events to be cleared                   | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (Out)  | none                                                    | */
/* |------------------+---------------------------------------------------------| */
/* | Description:     | The events of the extended task calling ClearEvent are  | */
/* |                  | cleared according to the event mask <Mask>.             | */
/* |------------------+---------------------------------------------------------| */
/* | Particularities: | The system service ClearEvent is restricted to extended | */
/* |                  | tasks which own the event.                              | */
/* |------------------+---------------------------------------------------------| */
/* | Status:          | Standard: 1.No error, E_OK                              | */
/* |                  | Extended: 1.Call not from extended task, E_OS_ACCESS    | */
/* |                  | 2.Call at interrupt level, E_OS_CALLEVEL                | */
/* |------------------+---------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                              | */
/* |------------------+---------------------------------------------------------| */
StatusType ClearEvent ( EventMaskType Mask )
{
	StatusType ercd = E_OK;
    ID flgid;
    FLGCB *flgcb;
    OS_CHECK_EXT(!in_indp(),E_OS_CALLEVEL);
    flgid = knl_ctxtsk - knl_tcb_table;
    flgid = knl_gtsk_table[flgid].flgid;
    OS_CHECK_EXT((flgid != INVALID_EVENT),E_OS_ACCESS);
    
    flgcb = &knl_flgcb_table[flgid];
    BEGIN_DISABLE_INTERRUPT;
    flgcb->flgptn &= ~Mask;
    END_DISABLE_INTERRUPT;
       
  Error_Exit:
    #if(cfgOS_ERROR_HOOK == STD_ON)
	if(E_OK != ercd)
	{
    	BEGIN_CRITICAL_SECTION;
    	_errorhook_svcid = OSServiceId_ClearEvent;
    	_errorhook_par1.mask = Mask;
    	ErrorHook(ercd);
    	END_CRITICAL_SECTION;
    }
	#endif /* cfgOS_ERROR_HOOK */
	return ercd;
}

/* |------------------+--------------------------------------------------------------| */
/* | Syntax:          | StatusType GetEvent ( TaskType <TaskID>                      | */
/* |                  | EventMaskRefType <Event> )                                   | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (In):  | TaskID:Task whose event mask is to be returned.              | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (Out): | Event:Reference to the memory of the return data.            | */
/* |------------------+--------------------------------------------------------------| */
/* | Description:     | 1.This service returns the current state of all event bits   | */
/* |                  | of the task <TaskID>, not the events that the task is        | */
/* |                  | waiting for.                                                 | */
/* |                  | 2.The service may be called from interrupt service routines, | */
/* |                  | task level and some hook routines (see Figure 12-1).         | */
/* |                  | 3.The current status of the event mask of task <TaskID> is   | */
/* |                  | copied to <Event>.                                           | */
/* |------------------+--------------------------------------------------------------| */
/* | Particularities: | The referenced task shall be an extended task.               | */
/* |------------------+--------------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                                     | */
/* |                  | Extended: Task <TaskID> is invalid, E_OS_ID                  | */
/* |                  | Referenced task <TaskID> is not an extended task,            | */
/* |                  | E_OS_ACCESS                                                  | */
/* |                  | Referenced task <TaskID> is in the suspended state,          | */
/* |                  | E_OS_STATE                                                   | */
/* |------------------+--------------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                                   | */
/* |------------------+--------------------------------------------------------------| */
StatusType GetEvent ( TaskType TaskID , EventMaskRefType Event )
{
	StatusType ercd = E_OK;
    ID flgid;
    FLGCB *flgcb;
    TCB* tcb;
    OS_CHECK_EXT((TaskID < cfgOSEK_TASK_NUM),E_OS_ID);
    flgid = knl_gtsk_table[TaskID].flgid;
    OS_CHECK_EXT((flgid != INVALID_EVENT),E_OS_ACCESS);
    tcb = &knl_tcb_table[TaskID];
    OS_CHECK_EXT(((tcb->state & (TS_READY | TS_WAIT)) != 0),E_OS_STATE);
    
    flgcb = &knl_flgcb_table[flgid];
    BEGIN_DISABLE_INTERRUPT;
    *Event = flgcb->flgptn;
    END_DISABLE_INTERRUPT;
       
  Error_Exit:
    #if(cfgOS_ERROR_HOOK == STD_ON)
	if(E_OK != ercd)
	{
    	BEGIN_CRITICAL_SECTION;
    	_errorhook_svcid = OSServiceId_GetEvent;
    	_errorhook_par1.tskid = TaskID;
    	_errorhook_par2.p_mask = Event;
    	ErrorHook(ercd);
    	END_CRITICAL_SECTION;
    }
	#endif /* cfgOS_ERROR_HOOK */
	return ercd;
}


/* |------------------+------------------------------------------------------------| */
/* | Syntax:          | StatusType WaitEvent ( EventMaskType <Mask> )              | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (In):  | Mask:Mask of the events waited for.                        | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (Out): | none                                                       | */
/* |------------------+------------------------------------------------------------| */
/* | Description:     | The state of the calling task is set to waiting, unless    | */
/* |                  | at least one of the events specified in <Mask> has         | */
/* |                  | already been set.                                          | */
/* |------------------+------------------------------------------------------------| */
/* | Particularities: | 1.This call enforces rescheduling, if the wait condition   | */
/* |                  | occurs. If rescheduling takes place, the internal resource | */
/* |                  | of the task is released while the task is in the waiting   | */
/* |                  | state.                                                     | */
/* |                  | 2.This service shall only be called from the extended task | */
/* |                  | owning the event.                                          | */
/* |------------------+------------------------------------------------------------| */
/* | Status:          | Standard:No error, E_OK                                    | */
/* |                  | Extended:Calling task is not an extended task, E_OS_ACCESS | */
/* |                  | Calling task occupies resources, E_OS_RESOURCE             | */
/* |                  | Call at interrupt level, E_OS_CALLEVEL                     | */
/* |------------------+------------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                                 | */
/* |------------------+------------------------------------------------------------| */
StatusType WaitEvent( EventMaskType Mask )
{
	StatusType ercd = E_OK;
    ID flgid;
    FLGCB *flgcb;
    OS_CHECK_EXT(!in_indp(),E_OS_CALLEVEL);
    OS_CHECK_EXT(isQueEmpty(&knl_ctxtsk->resque),E_OS_RESOURCE);
    flgid = knl_ctxtsk - knl_tcb_table;
    flgid = knl_gtsk_table[flgid].flgid;
    OS_CHECK_EXT((flgid != INVALID_EVENT),E_OS_ACCESS);
    
    flgcb = &knl_flgcb_table[flgid];
    BEGIN_CRITICAL_SECTION;
    if((flgcb->flgptn & Mask) == NO_EVENT)
    {
        flgcb->waipth = Mask;
        knl_ctxtsk->state = TS_WAIT;
        //release internal resource or for Non-Preemtable Task
        knl_ctxtsk->priority = knl_ctxtsk->itskpri; 
        knl_search_schedtsk();
    }
    END_CRITICAL_SECTION;
    //re-get internal resource or for Non-Preemtable task
    knl_ctxtsk->priority = knl_ctxtsk->runpri;
       
  Error_Exit:
    #if(cfgOS_ERROR_HOOK == STD_ON)
	if(E_OK != ercd)
	{
    	BEGIN_CRITICAL_SECTION;
    	_errorhook_svcid = OSServiceId_WaitEvent;
    	_errorhook_par1.mask = Mask;
    	ErrorHook(ercd);
    	END_CRITICAL_SECTION;
    }
	#endif /* cfgOS_ERROR_HOOK */
	return ercd;
}

#endif /* (cfgOSEK_EVENTFLAG_NUM > 0) */

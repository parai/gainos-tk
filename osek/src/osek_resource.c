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
#include "knl_resource.h"
#include "knl_task.h"
#include "knl_queue.h"
#include "portable.h"

#if(cfgOSEK_RESOURCE_NUM > 0)
EXPORT RESCB knl_rescb_table[cfgOSEK_RESOURCE_NUM];

EXPORT void knl_resource_init(void)
{
    ID i;
    for(i=0;i<cfgOSEK_RESOURCE_NUM;i++)
    {
        QueInit(&(knl_rescb_table[i].resque));
    }
}
/* |------------------+-----------------------------------------------------------| */
/* | Syntax:          | StatusType GetResource ( ResourceType <ResID> )           | */
/* |------------------+-----------------------------------------------------------| */
/* | Parameter (In):  | ResID:Reference to resource                               | */
/* |------------------+-----------------------------------------------------------| */
/* | Parameter (Out): | none                                                      | */
/* |------------------+-----------------------------------------------------------| */
/* | Description:     | This call serves to enter critical sections in the code   | */
/* |                  | that are assigned to the resource referenced by <ResID>.  | */
/* |                  | A critical section shall always be left using             | */
/* |                  | ReleaseResource.                                          | */
/* |------------------+-----------------------------------------------------------| */
/* | Particularities: | 1.The OSEK priority ceiling protocol for resource         | */
/* |                  | management is described in chapter 8.5.                   | */
/* |                  | 2.Nested resource occupation is only allowed if the       | */
/* |                  | inner critical sections are completely executed within    | */
/* |                  | the surrounding critical section (strictly stacked,       | */
/* |                  | see chapter 8.2, Restrictions when using resources).      | */
/* |                  | Nested occupation of one and the same resource is         | */
/* |                  | also forbidden!                                           | */
/* |                  | 3.It is recommended that corresponding calls to           | */
/* |                  | GetResource and ReleaseResource appear within the         | */
/* |                  | same function.                                            | */
/* |                  | 4.It is not allowed to use services which are points      | */
/* |                  | of rescheduling for non preemptable tasks (TerminateTask, | */
/* |                  | ChainTask, Schedule and WaitEvent, see chapter 4.6.2)     | */
/* |                  | in critical sections. Additionally, critical sections     | */
/* |                  | are to be left before completion of an interrupt service  | */
/* |                  | routine.                                                  | */
/* |                  | 5.Generally speaking, critical sections should be short.  | */
/* |                  | 6.The service may be called from an ISR and from task     | */
/* |                  | level (see Figure 12-1).                                  | */
/* |------------------+-----------------------------------------------------------| */
/* | Status:          | Standard:1.No error, E_OK                                 | */
/* |                  | Extended:1.Resource <ResID> is invalid, E_OS_ID           | */
/* |                  | 2.Attempt to get a resource which is already occupied     | */
/* |                  | by any task or ISR, or the statically assigned priority   | */
/* |                  | of the calling task or interrupt routine is higher than   | */
/* |                  | the calculated ceiling priority, E_OS_ACCESS              | */
/* |------------------+-----------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                    | */
/* |------------------+-----------------------------------------------------------| */
StatusType GetResource (ResourceType ResID)
{
	StatusType ercd = E_OK;
	RESCB *rescb;
	PRI newpri,oldpri;
	OS_CHECK_EXT((ResID < cfgOSEK_RESOURCE_NUM),E_OS_ID);
	rescb = &knl_rescb_table[ResID];
    OS_CHECK_EXT((isQueEmpty(&rescb->resque)),E_OS_ACCESS);	
    if(in_indp())  /* Interrupt level */
    {
        /* not supported */
    }
    else
    {
        oldpri = knl_ctxtsk->priority;
        newpri = knl_gres_table[ResID];
        OS_CHECK_EXT((newpri < oldpri),E_OS_ACCESS);
        BEGIN_DISABLE_INTERRUPT;
        if(newpri < 0)
        {
            //TODO: share resourse with OSR
            /* Task share resource with ISR */
            /* should change IPL */
            /* not supported */
        }
        else
        {
            knl_ctxtsk->priority = newpri; 
            rescb->tskpri = oldpri;
            QueInsert(&rescb->resque,&knl_ctxtsk->resque);  
        }
        END_DISABLE_INTERRUPT;	
    }
Error_Exit:
    #if(cfgOS_ERROR_HOOK == STD_ON)
	if(E_OK != ercd)
	{
    	BEGIN_CRITICAL_SECTION;
    	_errorhook_svcid = OSServiceId_GetResource;
    	_errorhook_par1.resid = ResID;
    	ErrorHook(ercd);
    	END_CRITICAL_SECTION;
    }
	#endif /* cfgOS_ERROR_HOOK */
	return ercd;
}

/* |------------------+------------------------------------------------------------| */
/* | Syntax:          | StatusType ReleaseResource ( ResourceType <ResID> )        | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (In):  | ResID:Reference to resource                                | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (Out): | none                                                       | */
/* |------------------+------------------------------------------------------------| */
/* | Description:     | ReleaseResource is the counterpart of GetResource and      | */
/* |                  | serves to leave critical sections in the code that are     | */
/* |                  | assigned to the resource referenced by <ResID>.            | */
/* |------------------+------------------------------------------------------------| */
/* | Particularities: | For information on nesting conditions, see particularities | */
/* |                  | of GetResource.                                            | */
/* |                  | The service may be called from an ISR and from task level  | */
/* |                  | (see Figure 12-1).                                         | */
/* |------------------+------------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                                   | */
/* |                  | Extended: Resource <ResID> is invalid, E_OS_ID             | */
/* |                  | Attempt to release a resource which is not occupied by     | */
/* |                  | any task or ISR, or another resource shall be released     | */
/* |                  | before, E_OS_NOFUNC                                        | */
/* |                  | Attempt to release a resource which has a lower ceiling    | */
/* |                  | priority than the statically assigned priority of the      | */
/* |                  | calling task or interrupt routine, E_OS_ACCESS             | */
/* |------------------+------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                     | */
/* |------------------+------------------------------------------------------------| */
StatusType ReleaseResource ( ResourceType ResID )
{
	StatusType ercd = E_OK;
	RESCB *rescb;
	PRI newpri,oldpri;
	OS_CHECK_EXT((ResID < cfgOSEK_RESOURCE_NUM),E_OS_ID);
	rescb = &knl_rescb_table[ResID];
    	
    if(in_indp())  /* Interrupt level */
    {
        /* not supported */
    }
    else
    {
        OS_CHECK_EXT((knl_ctxtsk->resque.prev == &rescb->resque),E_OS_NOFUNC);
        oldpri = knl_gres_table[ResID];
        newpri = rescb->tskpri;
         
        OS_CHECK_EXT((newpri > oldpri),E_OS_ACCESS);
        
        BEGIN_CRITICAL_SECTION;
        if(oldpri < 0)
        {
            /* Task share resource with ISR */
            /* should change IPL */
            /* not supported */           
        }
        else
        {
            knl_ctxtsk->priority = newpri; 
            QueRemove(&rescb->resque);
            QueInit(&rescb->resque);    
            if(newpri > knl_ready_queue.top_priority)
            {
                knl_preempt();
            }
        }
        END_CRITICAL_SECTION;	
    }
Error_Exit:
    #if(cfgOS_ERROR_HOOK == STD_ON)
	if(E_OK != ercd)
	{
    	BEGIN_CRITICAL_SECTION;
    	_errorhook_svcid = OSServiceId_ReleaseResource;
    	_errorhook_par1.resid = ResID;
    	ErrorHook(ercd);
    	END_CRITICAL_SECTION;
    }
	#endif /* cfgOS_ERROR_HOOK */
	return ercd;
}
#endif /* (cfgOSEK_RESOURCE_NUM > 0) */

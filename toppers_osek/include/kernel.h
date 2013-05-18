/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
 * 
 *  Copyright (C) 2013 by Fan Wang(parai), China
 * 
 * The above copyright holders grant permission gratis to use,
 * duplicate, modify, or redistribute (hereafter called use) this
 * software (including the one made by modifying this software),
 * provided that the following four conditions (1) through (4) are
 * satisfied.
 * 
 * (1) When this software is used in the form of source code, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be retained in the source code without modification.
 *
 * (2) When this software is redistributed in the forms usable for the
 *    development of other software, such as in library form, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be shown without modification in the document provided
 *    with the redistributed software, such as the user manual.
 *
 * (3) When this software is redistributed in the forms unusable for the
 *    development of other software, such as the case when the software
 *    is embedded in a piece of equipment, either of the following two
 *    conditions must be satisfied:
 *
 *  (a) The above copyright notice, this use conditions, and the
 *      disclaimer shown below must be shown without modification in
 *      the document provided with the redistributed software, such as
 *      the user manual.
 *
 *  (b) How the software is to be redistributed must be reported to the
 *      TOPPERS Project according to the procedure described
 *      separately.
 *
 * (4) The above copyright holders and the TOPPERS Project are exempt
 *    from responsibility for any type of damage directly or indirectly
 *    caused from the use of this software and are indemnified by any
 *    users or end users of this software from any and all causes of
 *    action whatsoever.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 * THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 * TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 * INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

#ifndef _KERNEL_H_
#define _KERNEL_H_

/*
 *  includes
 */

#include "osek.h"


/*
 *  OSEK OS Types
 */
#ifndef _MACRO_ONLY

typedef UINT8			TaskType;			/* Task ID */
typedef UINT8			TaskStateType;		/* Task State */
typedef UINT8			ResourceType;		/* Resource ID */
typedef UINT32			EventMaskType;		/* Event Mask in bit */
typedef UINT32			TickType;			/* Time Tick */
typedef UINT8			AlarmType;			/* Alarm ID */
typedef UINT8			AppModeType;		/* OS Application Mode */
typedef UINT8			OSServiceIdType;	/* OS service API ID */
typedef UINT8			IsrType;			/* ISR ID */
typedef UINT8			CounterType;		/* Counter ID */

typedef struct {
	TickType maxallowedvalue;	/* Maximum possible allowed count value in ticks */
	TickType ticksperbase;		/* Number of ticks required to reach a counter-specific (significant) unit. */
	TickType mincycle;			/* Smallest allowed value for the cycle-parameter of SetRelAlarm/SetAbsAlarm) (only for systems with extended status). */
} AlarmBaseType;

typedef TaskType		*TaskRefType;
typedef TaskStateType	*TaskStateRefType;
typedef EventMaskType	*EventMaskRefType;
typedef TickType		*TickRefType;
typedef AlarmBaseType	*AlarmBaseRefType;

/*
 *  Macros for declare a object 
 */
#define DeclareTask(TaskName)		extern const TaskType TaskName
#define DeclareResource(ResName)	extern const ResourceType ResName
#define DeclareEvent(EventName)		extern const EventMaskType EventName
#define DeclareAlarm(AlarmName)		extern const AlarmType AlarmName
/* declare a Counter	*/
#define DeclareCounter(CounterName)	extern const CounterType CounterName

/*
 *  Macro for declare Task/Alarm/ISR Entry
 */
#define TASKNAME(TaskName)	TaskMain##TaskName
#define TASK(TaskName)		void TaskMain##TaskName(void)
#define ISRNAME(ISRName)	ISRMain##ISRName
#define ISR(ISRName)		void ISRMain##ISRName(void)
#define ALARMCALLBACKNAME(AlarmCallBackName) 	\
							AlarmMain##AlarmCallBackName
#define ALARMCALLBACK(AlarmCallBackName)	\
							void AlarmMain##AlarmCallBackName(void)

/*
 *  OSEK OS APIs
 */

/*
 *  Task APIs
 */
extern StatusType ActivateTask(TaskType tskid);
extern StatusType TerminateTask(void);
extern StatusType ChainTask(TaskType tskid);
extern StatusType Schedule(void);
extern StatusType GetTaskID(TaskRefType p_tskid);
extern StatusType GetTaskState(TaskType tskid, TaskStateRefType p_state);

/*
 *  Interrupt APIs
 */
extern void EnableAllInterrupts(void);
extern void DisableAllInterrupts(void);
extern void ResumeAllInterrupts(void);
extern void SuspendAllInterrupts(void);
extern void ResumeOSInterrupts(void);
extern void SuspendOSInterrupts(void);

/*
 *  Resource APIs
 */
extern StatusType GetResource(ResourceType resid);
extern StatusType ReleaseResource(ResourceType resid);

/*
 *  Event APIs
 */
extern StatusType SetEvent(TaskType tskid, EventMaskType mask);
extern StatusType ClearEvent(EventMaskType mask);
extern StatusType GetEvent(TaskType tskid, EventMaskRefType p_mask);
extern StatusType WaitEvent(EventMaskType mask);

/*
 *  Alarm APIs
 */
extern StatusType GetAlarmBase(AlarmType almid, AlarmBaseRefType p_info);
extern StatusType GetAlarm(AlarmType almid, TickRefType p_tick);
extern StatusType SetRelAlarm(AlarmType almid, TickType incr, TickType cycle);
extern StatusType SetAbsAlarm(AlarmType almid, TickType start, TickType cycle);
extern StatusType CancelAlarm(AlarmType almid);

/*
 *  OS Control APIs
 */
extern AppModeType GetActiveApplicationMode(void);
extern void StartOS(AppModeType mode);
extern void ShutdownOS(StatusType ercd);

/*
 *  Signal a Counter increment
 */
extern StatusType SignalCounter(CounterType cntid);

/*
 *  Hooks
 */
extern void ErrorHook(StatusType ercd);
extern void PreTaskHook(void);
extern void PostTaskHook(void);
extern void StartupHook(void);
extern void ShutdownHook(StatusType ercd);

#endif /* _MACRO_ONLY */

/*
 *  OS Status (error code)
 */
#define E_OS_ACCESS		((StatusType) 1)
#define E_OS_CALLEVEL	((StatusType) 2)
#define E_OS_ID			((StatusType) 3)
#define E_OS_LIMIT		((StatusType) 4)
#define E_OS_NOFUNC		((StatusType) 5)
#define E_OS_RESOURCE	((StatusType) 6)
#define E_OS_STATE		((StatusType) 7)
#define E_OS_VALUE		((StatusType) 8)

/*
 *  Macros for Task 
 */
#define INVALID_TASK		((TaskType) UINT8_INVALID)

#define SUSPENDED			((StatusType) 0)
#define RUNNING				((StatusType) 1)
#define READY				((StatusType) 2)
#define WAITING				((StatusType) 3)

#define RES_SCHEDULER		((ResourceType) 0)	/* Constant of data type ResourceType (see (osek)chapter 8, Resource management). */

#define OSDEFAULTAPPMODE	((AppModeType) 0x01)
									/* Default application mode, always a valid parameter to StartOS */

/*
 *  OS service API IDs
 */
#define OSServiceId_ActivateTask				((OSServiceIdType) 0)
#define OSServiceId_TerminateTask				((OSServiceIdType) 1)
#define OSServiceId_ChainTask					((OSServiceIdType) 2)
#define OSServiceId_Schedule					((OSServiceIdType) 3)
#define OSServiceId_GetTaskID					((OSServiceIdType) 4)
#define OSServiceId_GetTaskState				((OSServiceIdType) 5)
#define OSServiceId_EnableAllInterrupts			((OSServiceIdType) 6)
#define OSServiceId_DisableAllInterrupts		((OSServiceIdType) 7)
#define OSServiceId_ResumeAllInterrupts			((OSServiceIdType) 8)
#define OSServiceId_SuspendAllInterrupts		((OSServiceIdType) 9)
#define OSServiceId_ResumeOSInterrupts			((OSServiceIdType) 10)
#define OSServiceId_SuspendOSInterrupts			((OSServiceIdType) 11)
#define OSServiceId_GetResource					((OSServiceIdType) 12)
#define OSServiceId_ReleaseResource				((OSServiceIdType) 13)
#define OSServiceId_SetEvent					((OSServiceIdType) 14)
#define OSServiceId_ClearEvent					((OSServiceIdType) 15)
#define OSServiceId_GetEvent					((OSServiceIdType) 16)
#define OSServiceId_WaitEvent					((OSServiceIdType) 17)
#define OSServiceId_GetAlarmBase				((OSServiceIdType) 18)
#define OSServiceId_GetAlarm					((OSServiceIdType) 19)
#define OSServiceId_SetRelAlarm					((OSServiceIdType) 20)
#define OSServiceId_SetAbsAlarm					((OSServiceIdType) 21)
#define OSServiceId_CancelAlarm					((OSServiceIdType) 22)
#define OSServiceId_GetActiveApplicationMode	((OSServiceIdType) 23)
#define OSServiceId_StartOS						((OSServiceIdType) 24)
#define OSServiceId_ShutdownOS					((OSServiceIdType) 25)
#define OSServiceId_SignalCounter				((OSServiceIdType) 26)

/*
 *  OSEK Error Store Types
 */
#ifndef _MACRO_ONLY

typedef union {
		TaskType			tskid;
		TaskRefType			p_tskid;
		TaskStateRefType	p_state;
		ResourceType		resid;
		EventMaskType		mask;
		EventMaskRefType	p_mask;
		AlarmType			almid;
		AlarmBaseRefType	p_info;
		TickRefType			p_tick;
		TickType			incr;
		TickType			cycle;
		TickType			start;
		AppModeType			mode;
		CounterType			cntid;
	} _ErrorHook_Par;

extern OSServiceIdType	_errorhook_svcid;
extern _ErrorHook_Par	_errorhook_par1, _errorhook_par2, _errorhook_par3;

#endif /* _MACRO_ONLY */

/*
 *  OS Error Process Macors
 */
#define OSErrorGetServiceId()				(_errorhook_svcid)

#define OSError_ActivateTask_TaskID()		(_errorhook_par1.tskid)
#define OSError_ChainTask_TaskID()			(_errorhook_par1.tskid)
#define OSError_GetTaskID_TaskID()			(_errorhook_par1.p_tskid)
#define OSError_GetTaskState_TaskID()		(_errorhook_par1.tskid)
#define OSError_GetTaskState_State()		(_errorhook_par2.p_state)
#define OSError_GetResource_ResID()			(_errorhook_par1.resid)
#define OSError_ReleaseResource_ResID()		(_errorhook_par1.resid)
#define OSError_SetEvent_TaskID()			(_errorhook_par1.tskid)
#define OSError_SetEvent_Mask()				(_errorhook_par2.mask)
#define OSError_ClearEvent_Mask()			(_errorhook_par1.mask)
#define OSError_GetEvent_TaskID()			(_errorhook_par1.tskid)
#define OSError_GetEvent_Mask()				(_errorhook_par2.p_mask)
#define OSError_WaitEvent_Mask()			(_errorhook_par1.mask)
#define OSError_GetAlarmBase_AlarmID()		(_errorhook_par1.almid)
#define OSError_GetAlarmBase_Info()			(_errorhook_par2.p_info)
#define OSError_GetAlarm_AlarmID()			(_errorhook_par1.almid)
#define OSError_GetAlarm_Tick()				(_errorhook_par2.p_tick)
#define OSError_SetRelAlarm_AlarmID()		(_errorhook_par1.almid)
#define OSError_SetRelAlarm_increment()		(_errorhook_par2.incr)
#define OSError_SetRelAlarm_cycle()			(_errorhook_par3.cycle)
#define OSError_SetAbsAlarm_AlarmID()		(_errorhook_par1.almid)
#define OSError_SetAbsAlarm_start()			(_errorhook_par2.start)
#define OSError_SetAbsAlarm_cycle()			(_errorhook_par3.cycle)
#define OSError_CancelAlarm_AlarmID()		(_errorhook_par1.almid)
#define OSError_SignalCounter_CounterID()	(_errorhook_par1.cntid)

#include "os_cfg.h"

#endif /* _KERNEL_H_ */

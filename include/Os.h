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

#ifndef OS_H_H_H
#define OS_H_H_H
/* ============================ INCLUDEs ========================================== */
#include "Std_Types.h" 

/* ============================ MACROs   ========================================== */
#define INVALID_TASK (-1)

#define OS_STATUS_STANDARD 0
#define OS_STATUS_EXTENDED  1

/* Info About Conformance Class of OS */
#define BCC1 1
#define BCC2 2
#define ECC1 3
#define ECC2 4

/* Attribute for task */
// use the atr[7:0] to store the appmode for each task
// each bit correspond to one
/* Default application mode, always a valid parameter to StartOS */
#define APPMODEMASK      (0x000000FFu)
#define OSDEFAULTAPPMODE (0x00000001u)
#define OSNONEAPPMODE    (0x00000000u)
//Is Task Preemtable
#define PREEMTABLE       (0x00000000u)
#define NON_PREEMTABLE   (0x00000100u) 
//Is Task Autostart
#define AUTOSTART        (0x00000200u)
#define NON_AUTOSTART    (0x00000000u) 
#define OS_HIGHEST_PRIORITY 0     

#define TMO_FEVR (TickType)(UINT_MAX)

/* Values for TaskStateType */
#define SUSPENDED (0x00u)
#define RUNNING   (0x01u)
#define READY     (0x02u)
#define WAITING   (0x03u)


#define E_OS_ACCESS     (1u)
#define E_OS_CALLEVEL   (2u)
#define E_OS_ID         (3u)
#define E_OS_LIMIT      (4u)
#define E_OS_NOFUNC     (5u)
#define E_OS_RESOURCE   (6u)
#define E_OS_STATE      (7u)
#define E_OS_VALUE      (8u)
// tk_extend macros
#define E_OS_TMOUT      (9u)
#define E_OS_QOVR       (10u)


/*  Constant of data type ResourceType (see (osek)chapter 8, Resource management).*/
#define RES_SCHEDULER 0

#define TASK(TaskName) void TaskMain##TaskName(void)
#define ALARM(AlarmName)     \
    void AlarmMain##AlarmName(void)  

//----------------------- OS Error Process -----------
/*
 *  OS Error Process Macors
 */
#define OSServiceId_ActivateTask    0
#define OSServiceId_TerminateTask   1
#define OSServiceId_ChainTask       2
#define OSServiceId_Schedule        3
#define OSServiceId_GetTaskID       4
#define OSServiceId_GetTaskState    5
#define OSServiceId_GetAlarmBase    6
#define OSServiceId_GetAlarm        7
#define OSServiceId_SetRelAlarm     8
#define OSServiceId_SetAbsAlarm     9
#define OSServiceId_CancelAlarm     10
#define OSServiceId_SetEvent        11 
#define OSServiceId_ClearEvent      12
#define OSServiceId_GetEvent        13
#define OSServiceId_WaitEvent       14
#define OSServiceId_GetResource     15
#define OSServiceId_ReleaseResource 16
#define OSServiceId_StartOS         17
#define OSServiceId_ShutdownOS      18
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

/* ============================ TYPEs   ========================================== */
/* This data type identifies a task. */
typedef ID TaskType;
/* This data type points to a variable of TaskType. */
typedef TaskType* TaskRefType;
/* This data type identifies the state of a task. */
typedef uint8   TaskStateType;
/* This data type points to a variable of the data type TaskStateType. */
typedef TaskStateType * TaskStateRefType;
/* This data type represents count values in ticks. */
typedef UINT TickType;
/* This data type points to the data type TickType. */
typedef TickType* TickRefType;
/* This data type represents a structure for storage of counter characteristics. 
 * The individual elements of the structure are: */
typedef struct
{
    /* Maximum possible allowed count value in ticks */
    TickType MaxAllowedValue;
    /*  Number of ticks required to reach a counter-specific (significant) unit. */
    TickType TicksPerBase;
    /* Smallest allowed value for the cycle-parameter of */
    /* SetRelAlarm/SetAbsAlarm) (only for systems with extended status). */
    TickType MinCycle;
}AlarmBaseType;
/* This data type points to the data type AlarmBaseType. */
typedef AlarmBaseType * AlarmBaseRefType;
/* This data type represents an alarm object. */
typedef ID AlarmType;
/* This data type represents an Counter object. */
typedef ID CounterType;
/* Data type of the event mask. */
typedef uint32 EventMaskType;
/* Reference to an event mask. */
typedef EventMaskType* EventMaskRefType;
typedef uint8 ResourceType;
typedef uint8 StatusType;
typedef uint8 AppModeType;
/* This data type represents the identification of system services. */
typedef uint8 OSServiceIdType;

//this is a copy and paste from nxtOSEK
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

/* ============================ INCLUDEs ========================================== */
#include "osek_cfg.h"
#include "osek_check.h"

/* ============================ FUNCTIONs   ========================================== */
StatusType GetCounterValue(CounterType CounterID,TickRefType Value);
StatusType GetElapsedCounterValue(CounterType CounterID,
                                  TickRefType Value,TickRefType ElapsedValue);
StatusType IncrementCounter(CounterType CounterID);

StatusType GetAlarmBase( AlarmType AlarmID, AlarmBaseRefType pInfo );
StatusType GetAlarm ( AlarmType AlarmID ,TickRefType Tick );
StatusType SetRelAlarm ( AlarmType AlarmID , TickType Increment ,TickType Cycle );
StatusType SetAbsAlarm ( AlarmType AlarmID , TickType Start ,TickType Cycle );
StatusType CancelAlarm ( AlarmType AlarmID ); 

StatusType ActivateTask ( TaskType TaskID );
StatusType TerminateTask( void );
StatusType ChainTask    ( TaskType TaskID );
StatusType SleepTask    ( TickType Timeout );
StatusType WakeUpTask   ( TaskType TaskID );
StatusType Schedule     ( void );
StatusType GetTaskID    ( TaskRefType TaskID );
StatusType GetTaskState ( TaskType TaskID,TaskStateRefType State );

StatusType SetEvent  ( TaskType TaskID , EventMaskType Mask );
StatusType ClearEvent( EventMaskType Mask );
StatusType GetEvent  ( TaskType TaskID , EventMaskRefType Event );
StatusType WaitEvent ( EventMaskType Mask );

StatusType GetActiveApplicationMode(AppModeType* Mode);

void EnterISR(void);
void ExitISR(void);
#define LeaveISR() ExitISR()
void DisableAllInterrupts( void );
void EnableAllInterrupts ( void );
void SuspendAllInterrupts( void );
void ResumeAllInterrupts ( void );
void SuspendOSInterrupts( void );
void ResumeOSInterrupts ( void );

StatusType GetResource (ResourceType xResID);
StatusType ReleaseResource ( ResourceType xResID );

void StartOS ( AppModeType xMode );
void ShutdownOS( StatusType xError );

void ShutdownHook ( StatusType xError);
void StartupHook(void);
void ErrorHook(StatusType xError);
void PreTaskHook(void);
void PostTaskHook(void);
#endif
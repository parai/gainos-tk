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
#define OS_STATUS_EXTEND  1

/* Attribute for task */
/* Info About Conformance Class of Task, Refer <Task.k> */
#define BCC1 0x00000001
#define BCC2 0x00000002
#define ECC1 0x00000004
#define ECC2 0x00000008

#define AUTOSTART  0x00000010

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
/* Default application mode, always a valid parameter to StartOS */
#define OSDEFAULTAPPMODE (0x01u)

#define TASK(TaskName) void TaskMain##TaskName(void)
#define ALARM(AlarmName)     \
    void AlarmMain##AlarmName(void)             
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

/* ============================ INCLUDEs ========================================== */
#include "osek_cfg.h"
#include "osek_check.h"

/* ============================ FUNCTIONs   ========================================== */
StatusType GetCounterValue(CounterType CounterID,TickRefType pxValue);
StatusType GetElapsedCounterValue(CounterType CounterID,
                                  TickRefType Value,TickRefType ElapsedValue);
StatusType IncrementCounter(CounterType CounterID);

StatusType GetAlarmBase( AlarmType xAlarmID, AlarmBaseRefType pxInfo );
StatusType GetAlarm ( AlarmType xAlarmID ,/* (SYSTIM*) */ TickRefType pxTick );
StatusType SetRelAlarm ( AlarmType xAlarmID , TickType xIncrement ,TickType xCycle );
StatusType SetAbsAlarm ( AlarmType xAlarmID , TickType xStart ,TickType xCycle );
StatusType CancelAlarm ( AlarmType xAlarmID ); 

StatusType ActivateTask ( TaskType xTaskID );
StatusType TerminateTask( void );
StatusType ChainTask    ( TaskType xTaskID );
StatusType SleepTask    ( TickType Timeout );
StatusType WakeUpTask   ( TaskType TaskID );
StatusType Schedule     ( void );
StatusType GetTaskID    ( TaskRefType pxTaskType );
StatusType GetTaskState ( TaskType xTaskID,TaskStateRefType pxState );

StatusType SetEvent  ( TaskType xTaskID , EventMaskType pxMask );
StatusType ClearEvent( EventMaskType xMask );
StatusType GetEvent  ( TaskType xTaskID , EventMaskRefType pxEvent );
StatusType WaitEvent ( EventMaskType xMask );

void EnterISR(void);
void ExitISR(void);
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
#endif
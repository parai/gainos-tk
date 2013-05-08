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

#ifndef OS_H_H_H
#define OS_H_H_H
/* ============================ INCLUDEs ========================================== */
#include "Std_Types.h" 

/* ============================ MACROs   ========================================== */
/* Scheduling Policy */
#define FULL_PREEMPTIVE_SCHEDULE  0
#define NONE_PREEMPTIVE_SCHEDULE  1
#define MIXED_PREEMPTIVE_SCHEDULE 2

/* Task's Policy Per Priority */
#define ONLY_ONE_TASK_PER_PRIORITY 0
#define SEVERAL_TASKS_PER_PRIORITY 1


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

/* Values for TaskStateType */
#define RUNNING   (0x00u)
#define READY     (0x01u)
#define WAITING   (0x02u)
#define SUSPENDED (0x03u)

#define E_OS_CALLEVEL   (2u)
#define E_OS_ID         (3u)
#define E_OS_LIMIT      (4u)
#define E_OS_NOFUNC     (5u)
#define E_OS_RESOURCE   (6u)
#define E_OS_STATE      (7u)
#define E_OS_VALUE      (8u)
#define E_OS_ACCESS     (9u)

/* Extended for autosar */  
/* An invalid adress is given as a paraimeter to a service */
#define E_OS_ILLEGAL_ADDRESS        (10u)
/* Tasks terminates without a TerminateTask() or ChainTask() call. */
#define E_OS_MISSINGEND             (11u)     
/* a service of the os is called inside an interrupt  disable/enable pair. */
#define E_OS_DISABLEDINT            (12u)
/* a stack fault detected via stack monitoring by the os */
#define E_OS_STACKFAULT             (13u)
/* a memory access violation occurred */
#define E_OS_PROTECTION_MEMORY      (14u)
/* A Task exceeds its execution time budget &&
   A Category 2 OsIsr exceeds its execution time budget  */
#define E_OS_PROTECTION_TIME        (15U)
/* A Task/Category 2 arrives before its timeframe has expired  */
#define E_OS_PROTECTION_ARRIVAL     (16u)
/* A Task/Category 2 OsIsr blocks for too long  */
#define E_OS_PROTECTION_LOCKED      (17u)
/* service can not be called */
#define E_OS_SERVICEID              (18u)  
/* A trap occurred  */
#define E_OS_PROTECTION_EXCEPTION   (19u)
/* Self define for implementation */
#define E_OS_SYS_NOT_OK (20u)

/* autosar:These macros return a value not equal to zero if the memory is 
   readable/writable/executable or stack space. */
#define OSMEMORY_IS_READABLE   ((AccessType)1u)
#define OSMEMORY_IS_WRITEABLE  ((AccessType)2u)
#define OSMEMORY_IS_EXECUTABLE ((AccessType)3u)
#define OSMEMORY_IS_STACKSPACE ((AccessType)4u)

/*  Constant of data type ResourceType (see (osek)chapter 8, Resource management).*/
#define RES_SCHEDULER 0
/* Default application mode, always a valid parameter to StartOS */
#define OSDEFAULTAPPMODE (0u)
/* for autosar */
#define INVALID_OSAPPLICATION  (ApplicationType)(-1)
#define INVALID_ISR            (ISRType)(-1)
#define INVALID_SCHEDULE_TABLE (ScheduleTableType)(-1)
#define ACCESS    (ObjectAccessType)0u
#define NO_ACCESS (ObjectAccessType)1u
#define OBJECT_TASK          (ObjectTypeType)0u
#define OBJECT_ISR           (ObjectTypeType)1u
#define OBJECT_ALARM         (ObjectTypeType)2u
#define OBJECT_RESOURCE      (ObjectTypeType)3u
#define OBJECT_COUNTER       (ObjectTypeType)4u
#define OBJECT_SCHEDULETABLE (ObjectTypeType)5u
#define SCHEDULETABLE_STOPPED                 (ScheduleTableStatusType)0u
#define SCHEDULETABLE_NEXT                    (ScheduleTableStatusType)1u
#define SCHEDULETABLE_WAITING                 (ScheduleTableStatusType)2u
#define SCHEDULETABLE_RUNNING                 (ScheduleTableStatusType)3u
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS (ScheduleTableStatusType)4u
#define PRO_IGNORE                (ProtectionReturnType)0u
#define PRO_TERMINATETASKISR      (ProtectionReturnType)1u
#define PRO_TERMINATEAPPL         (ProtectionReturnType)2u
#define PRO_TERMINATEAPPL_RESTART (ProtectionReturnType)3u
#define PRO_SHUTDOWN              (ProtectionReturnType)4u
#define RESTART    (RestartType)0u
#define NO_RESTART (RestartType)1u
/* The schedule table is started during startup with the
   StartScheduleTableAbs() service. */
#define ABSOLUTE (OsScheduleTableAutostartType)0u
/* The schedule table is started during startup with the
   StartScheduleTableRel() service. */
#define RELATIVE (OsScheduleTableAutostartType)1u
/* The schedule table is started during startup with the
   StartScheduleTableSynchron() service. */
#define SYNCHRON (OsScheduleTableAutostartType)2u
/* The schedule table is driven by an OS counter but
   processing needs to be synchronized with a different
   counter which is not an OS counter object.*/
#define EXPLICIT (OsScheduleTblSyncStrategyType)0u
/* The counter driving the schedule table is the counter
   with which synchronisation is required.*/
#define IMPLICIT (OsScheduleTblSyncStrategyType)1u
/* No support for synchronisation. (default) */
#define NONE     (OsScheduleTblSyncStrategyType)2u

#define TASK(TaskName) void TaskMain##TaskName(void)
#define ALARM(AlarmName)     \
    void AlarmMain##AlarmName(void)
/* ============================ TYPEs   ========================================== */
/* ============ OSEK STD TYPEs ===================== */
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

/* ============ AUTOSAR STD TYPEs ===================== */
/* This data type identifies the OS-Application. */
typedef uint8 ApplicationType;
/* This data type identifies a trusted function. */
typedef uint8 TrustedFunctionIndexType;
/* This data type points to a structure which holds the arguments for a call to a
   trusted function. */
typedef void* TrustedFunctionParameterRefType;
/* This type holds information how a specific memory region can be accessed. */
typedef uint8 AccessType;
/* This data type identifies if an OS-Application has access to an object. */
typedef uint8 ObjectAccessType;
/* This data type identifies an object. */
typedef uint8 ObjectTypeType;
/* This data type is a pointer which is able to point to any location in the MCU */
/* address space. */
typedef uint8* MemoryStartAddressType;
/* This data type holds the size (in bytes) of a memory region. */
typedef uint32 MemorySizeType;
/* This data type identifies an interrupt service routine (OsIsr). */
typedef uint8 ISRType;
/* This data type identifies a schedule table. */
typedef uint8 ScheduleTableType;
/*
  This type describes the status of a schedule. The status can be one of the
  following:
  1. The schedule table is not started (SCHEDULETABLE_STOPPED)
  2. The schedule table will be started after the end of currently running schedule
  table (schedule table was used in NextScheduleTable() service)
  (SCHEDULETABLE_NEXT)
  3. The schedule table uses implicit synchronization, has been started and is
  waiting for the global time. (SCHEDULETABLE_WAITING)
  4. The schedule table is running, but is currently not synchronous to a global
  time source (SCHEDULETABLE_RUNNING)
  5. The schedule table is running and is synchronous to a global time source
  (SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
*/
typedef uint8 ScheduleTableStatusType;
/* This data type points to a variable of the data type ScheduleTableStatusType. */
typedef ScheduleTableStatusType* ScheduleTableStatusRefType;
/* This data type identifies a value which controls further actions of the OS on return
   from the protection hook. */
typedef uint8 ProtectionReturnType;
/* This data type defines the use of a Restart Task after terminating an OS-
   Application.*/
typedef uint8 RestartType;
/* This data type is used for values returned by the conversion macro (see OS393())
   OS_TICKS2<Unit>_<Counter>(). */
typedef uint8 PhysicalTimeType;
typedef uint8 OsScheduleTableAutostartType;
typedef uint8 OsScheduleTblSyncStrategyType; 

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
StatusType Schedule     ( void );
StatusType GetTaskID    ( TaskRefType pxTaskType );
StatusType GetTaskState ( TaskType xTaskID,TaskStateRefType pxState );

StatusType SetEvent  ( TaskType xTaskID , EventMaskType pxMask );
StatusType ClearEvent( EventMaskType xMask );
StatusType GetEvent  ( TaskType xTaskID , EventMaskRefType pxEvent );
StatusType WaitEvent ( EventMaskType xMask );

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
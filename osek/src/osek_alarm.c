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
#include "knl_alarm.h"
#include "knl_queue.h"
#include "portable.h"
#if(cfgOSEK_ALARM_NUM >0)
/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | StatusType GetAlarmBase (AlarmType <AlarmID>,                    | */
/* |                  | AlarmBaseRefType <Info> )                                        | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | AlarmID: Reference to alarm                                      | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | Info: Reference to structure with constants of the alarm base.   | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     | The system service GetAlarmBase reads the alarm base             | */
/* |                  | characteristics. The return value <Info> is a structure in which | */
/* |                  | the information of data type AlarmBaseType is stored.            | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | Allowed on task level, ISR, and in several hook routines (see    | */
/* |                  | Figure 12-1).                                                    | */
/* |------------------+------------------------------------------------------------------| */
/* | Status:          | Standard:No error, E_OK                                          | */
/* |                  | Extended:Alarm <AlarmID> is invalid, E_OS_ID                     | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
StatusType GetAlarmBase ( AlarmType AlarmID, AlarmBaseRefType Info )
{
	StatusType ercd = E_OK;
    CounterType cntid;
    CHECK_COMMON_EXT((AlarmID < cfgOSEK_ALARM_NUM),E_OS_ID);
    cntid = knl_galm_table[AlarmID].owner;
    Info->MaxAllowedValue = knl_almbase_table[cntid].MaxAllowedValue;
    Info->MinCycle = knl_almbase_table[cntid].MinCycle;
    Info->TicksPerBase = knl_almbase_table[cntid].TicksPerBase;
    
Error_Exit:
    	return ercd;
}

/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | StatusType GetAlarm ( AlarmType <AlarmID>,TickRefType <Tick>)    | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | AlarmID:Reference to an alarm                                    | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | Tick:Relative value in ticks before the alarm <AlarmID> expires. | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     | The system service GetAlarm returns the relative value in ticks  | */
/* |                  | before the alarm <AlarmID> expires.                              | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | 1.It is up to the application to decide whether for example a    | */
/* |                  | CancelAlarm may still be useful.                                 | */
/* |                  | 2.If <AlarmID> is not in use, <Tick> is not defined.             | */
/* |                  | 3.Allowed on task level, ISR, and in several hook routines (see  | */
/* |                  | Figure 12-1).                                                    | */
/* |------------------+------------------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                                         | */
/* |                  | Alarm <AlarmID> is not used, E_OS_NOFUNC                         | */
/* |                  | Extended:  Alarm <AlarmID> is invalid, E_OS_ID                   | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
StatusType GetAlarm ( AlarmType AlarmID ,TickRefType Tick )
{
	StatusType ercd = E_OK;
    ALMCB* almcb;
    CCB *ccb;
    CounterType cntid;
    TickType max;
    CHECK_COMMON_EXT((AlarmID < cfgOSEK_ALARM_NUM),E_OS_ID);
    almcb = &knl_almcb_table[AlarmID];
    CHECK_COMMON_STD((!isQueEmpty(&almcb->almque)),E_OS_NOFUNC);
    cntid = knl_galm_table[AlarmID].owner;
    ccb = &knl_ccb_table[cntid];
    max = knl_almbase_table[cntid].MaxAllowedValue;
    
    BEGIN_DISABLE_INTERRUPT;
    *Tick = knl_diff_tick(ccb->curvalue,almcb->time,max*2);
    END_DISABLE_INTERRUPT;
    
    Error_Exit:
    	return ercd;
}

/* |------------------+-----------------------------------------------------------------| */
/* | Syntax:          | StatusType SetRelAlarm ( AlarmType <AlarmID>,                   | */
/* |                  | TickType <increment>,                                           | */
/* |                  | TickType <cycle> )                                              | */
/* |------------------+-----------------------------------------------------------------| */
/* | Parameter (In):  | AlarmID:Reference to the alarm element                          | */
/* |                  | increment:Relative value in ticks                               | */
/* |                  | cycle:Cycle value in case of cyclic alarm. In case of single    | */
/* |                  | alarms, cycle shall be zero.                                    | */
/* |------------------+-----------------------------------------------------------------| */
/* | Parameter (Out): | none                                                            | */
/* |------------------+-----------------------------------------------------------------| */
/* | Description:     | The system service occupies the alarm <AlarmID> element.        | */
/* |                  | After <increment> ticks have elapsed, the task assigned         | */
/* |                  | to the alarm <AlarmID> is activated or the assigned event       | */
/* |                  | (only for extended tasks) is set or the alarm-callback          | */
/* |                  | routine is called.                                              | */
/* |------------------+-----------------------------------------------------------------| */
/* | Particularities: | 1.The behaviour of <increment> equal to 0 is up to the          | */
/* |                  | implementation.                                                 | */
/* |                  | 2.If the relative value <increment> is very small, the alarm    | */
/* |                  | may expire, and the task may become ready or the alarm-callback | */
/* |                  | may be called before the system service returns to the user.    | */
/* |                  | 3.If <cycle> is unequal zero, the alarm element is logged on    | */
/* |                  | again immediately after expiry with the relative value <cycle>. | */
/* |                  | 4.The alarm <AlarmID> must not already be in use.               | */
/* |                  | 5.To change values of alarms already in use the alarm shall be  | */
/* |                  | cancelled first.                                                | */
/* |                  | 6.If the alarm is already in use, this call will be ignored and | */
/* |                  | the error E_OS_STATE is returned.                               | */
/* |                  | 7.Allowed on task level and in ISR, but not in hook routines.   | */
/* |------------------+-----------------------------------------------------------------| */
/* | Status:          | Standard:                                                       | */
/* |                  | 1.No error, E_OK                                                | */
/* |                  | 2.Alarm <AlarmID> is already in use, E_OS_STATE                 | */
/* |                  | Extended:                                                       | */
/* |                  | 1.Alarm <AlarmID> is invalid, E_OS_ID                           | */
/* |                  | 2.Value of <increment> outside of the admissible limits         | */
/* |                  | (lower than zero or greater than maxallowedvalue), E_OS_VALUE   | */
/* |                  | 3.Value of <cycle> unequal to 0 and outside of the admissible   | */
/* |                  | counter limits (less than mincycle or greater than              | */
/* |                  | maxallowedvalue), E_OS_VALUE                                    | */
/* |                  | 4.E_OS_LIMIT,extended by tkernel                                | */
/* |------------------+-----------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2; Events only ECC1, ECC2                  | */
/* |------------------+-----------------------------------------------------------------| */
StatusType SetRelAlarm ( AlarmType AlarmID , TickType Increment ,TickType Cycle )
{
	StatusType ercd = E_OK;
    ALMCB *almcb;
    CCB *ccb;
    CounterType cntid;
    TickType max;
    CHECK_COMMON_EXT((AlarmID < cfgOSEK_ALARM_NUM),E_OS_ID);
    almcb = &knl_almcb_table[AlarmID];
    CHECK_COMMON_STD((isQueEmpty(&almcb->almque)),E_OS_STATE);
    cntid = knl_galm_table[AlarmID].owner;
    max = knl_almbase_table[cntid].MaxAllowedValue;
    CHECK_COMMON_EXT((max > Increment),E_OS_VALUE);
    CHECK_COMMON_EXT((max > Cycle),E_OS_VALUE);
    CHECK_COMMON_EXT(((knl_almbase_table[cntid].MinCycle < Cycle) || (0 == Cycle)),E_OS_VALUE);
    ccb = &knl_ccb_table[cntid];
    
    BEGIN_DISABLE_INTERRUPT;
    almcb->time = knl_add_ticks(ccb->curvalue,Increment,max*2);
    almcb->cycle = Cycle;
    knl_alm_insert(almcb,ccb);
    END_DISABLE_INTERRUPT;
    
Error_Exit:
    return ercd;
}

/* |------------------+-----------------------------------------------------------------| */
/* | Syntax:          | StatusType SetAbsAlarm (AlarmType <AlarmID>,                    | */
/* |                  | TickType <start>,                                               | */
/* |                  | TickType <cycle> )                                              | */
/* |------------------+-----------------------------------------------------------------| */
/* | Parameter (In):  | AlarmID:Reference to the alarm element                          | */
/* |                  | start:Absolute value in ticks                                   | */
/* |                  | cycle:Cycle value in case of cyclic alarm. In case of           | */
/* |                  | single alarms, cycle shall be zero.                             | */
/* |------------------+-----------------------------------------------------------------| */
/* | Parameter (Out): | none                                                            | */
/* |------------------+-----------------------------------------------------------------| */
/* | Description:     | The system service occupies the alarm <AlarmID> element.        | */
/* |                  | When <start> ticks are reached, the task assigned to the alarm  | */
/* |                  | <AlarmID> is activated or the assigned event (only for extended | */
/* |                  | tasks) is set or the alarm-callback routine is called.          | */
/* |------------------+-----------------------------------------------------------------| */
/* | Particularities: | 1.If the absolute value <start> is very close to the current    | */
/* |                  | counter value, the alarm may expire, and the task may become    | */
/* |                  | ready or the alarm-callback may be called before the system     | */
/* |                  | service returns to the user.                                    | */
/* |                  | 2.If the absolute value <start> already was reached before      | */
/* |                  | the system call, the alarm shall only expire when the           | */
/* |                  | absolute value <start> is reached again, i.e. after the next    | */
/* |                  | overrun of the counter.                                         | */
/* |                  | 3.If <cycle> is unequal zero, the alarm element is logged on    | */
/* |                  | again immediately after expiry with the relative value <cycle>. | */
/* |                  | 4.The alarm <AlarmID> shall not already be in use.              | */
/* |                  | 5.To change values of alarms already in use the alarm shall be  | */
/* |                  | cancelled first.                                                | */
/* |                  | 6.If the alarm is already in use, this call will be ignored and | */
/* |                  | the error E_OS_STATE is returned.                               | */
/* |                  | 7.Allowed on task level and in ISR, but not in hook routines.   | */
/* |------------------+-----------------------------------------------------------------| */
/* | Status:          | Standard:                                                       | */
/* |                  | 1.No error, E_OK                                                | */
/* |                  | 2.Alarm <AlarmID> is already in use, E_OS_STATE                 | */
/* |                  | Extended:                                                       | */
/* |                  | 1.Alarm <AlarmID> is invalid, E_OS_ID                           | */
/* |                  | 2.Value of <start> outside of the admissible counter limit      | */
/* |                  | (less than zero or greater than maxallowedvalue), E_OS_VALUE    | */
/* |                  | 3.Value of <cycle> unequal to 0 and outside of the admissible   | */
/* |                  | counter limits (less than mincycle or greater than              | */
/* |                  | maxallowedvalue), E_OS_VALUE                                    | */
/* |------------------+-----------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2; Events only ECC1, ECC2                  | */
/* |------------------+-----------------------------------------------------------------| */
StatusType SetAbsAlarm ( AlarmType AlarmID , TickType Start ,TickType Cycle )
{
	StatusType ercd = E_OK;
    ALMCB *almcb;
    CCB *ccb;
    CounterType cntid;
    TickType max;
    CHECK_COMMON_EXT((AlarmID < cfgOSEK_ALARM_NUM),E_OS_ID);
    almcb = &knl_almcb_table[AlarmID];
    CHECK_COMMON_STD((isQueEmpty(&almcb->almque)),E_OS_STATE);
    cntid = knl_galm_table[AlarmID].owner;
    max = knl_almbase_table[cntid].MaxAllowedValue;
    CHECK_COMMON_EXT((max > Start),E_OS_VALUE);
    CHECK_COMMON_EXT((max > Cycle),E_OS_VALUE);
    CHECK_COMMON_EXT(((knl_almbase_table[cntid].MinCycle < Cycle) || (0 == Cycle)),E_OS_VALUE);
    ccb = &knl_ccb_table[cntid];
    
    BEGIN_DISABLE_INTERRUPT;
    almcb->time = Start;
    almcb->cycle = Cycle;
    knl_alm_insert(almcb,ccb);
    END_DISABLE_INTERRUPT;
Error_Exit:
    return ercd;
}

/* |------------------+-------------------------------------------------------------| */
/* | Syntax:          | StatusType CancelAlarm ( AlarmType <AlarmID> )              | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (In):  | AlarmID:Reference to an alarm                               | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (Out): | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Description:     | The system service cancels the alarm <AlarmID>.             | */
/* |------------------+-------------------------------------------------------------| */
/* | Particularities: | Allowed on task level and in ISR, but not in hook routines. | */
/* |------------------+-------------------------------------------------------------| */
/* | Status:          | Standard:                                                   | */
/* |                  | 1.No error, E_OK                                            | */
/* |                  | 2.Alarm <AlarmID> not in use, E_OS_NOFUNC                   | */
/* |                  | Extended: 1.Alarm <AlarmID> is invalid, E_OS_ID             | */
/* |------------------+-------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                      | */
/* |------------------+-------------------------------------------------------------| */
StatusType CancelAlarm ( AlarmType AlarmID )
{
    StatusType ercd = E_OK;
    ALMCB* almcb;
    CHECK_COMMON_EXT((AlarmID < cfgOSEK_ALARM_NUM),E_OS_ID);
    almcb = &knl_almcb_table[AlarmID];
    CHECK_COMMON_STD((!isQueEmpty(&almcb->almque)),E_OS_NOFUNC);

    BEGIN_DISABLE_INTERRUPT;
    QueRemove(&almcb->almque);
    QueInit(&almcb->almque);
    END_DISABLE_INTERRUPT;
    Error_Exit:
    	return ercd;
}

#endif /* (cfgOSEK_ALARM_NUM >0) */

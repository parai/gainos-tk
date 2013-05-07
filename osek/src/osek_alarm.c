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
#include "osek_os.h"
#include "knl_alarm.h"
#include "vPort.h"
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
	return E_OK;
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
    BEGIN_CRITICAL_SECTION;
    almcb->time = knl_add_ticks(ccb->curvalue,Increment,max*2);
    almcb->cycle = Cycle;
    knl_alm_insert(almcb,ccb);
    END_CRITICAL_SECTION;
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
    BEGIN_CRITICAL_SECTION;
    almcb->time = Start;
    almcb->cycle = Cycle;
    knl_alm_insert(almcb,ccb);
    END_CRITICAL_SECTION;
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
	Error_Exit:
		return ercd;
}

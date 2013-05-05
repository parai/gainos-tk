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
#include "knl_queue.h"
#include "vPort.h"

/* |-------------------+-----------------------------------------------------------------| */
/* | Service name:     | GetCounterValue                                                 | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Syntax:           | StatusType GetCounterValue(CounterType CounterID,               | */
/* |                   | TickRefType Value)                                              | */
/* | Service ID:       | OSServiceId_GetCounterValue                                     | */
/* | Sync/Async:       | Sync                                                            | */
/* | Reentrancy:       | Yes                                                             | */
/* | Parameters (in):  | CounterID:The Counter which tick value should be read           | */
/* | Parameters (out): | Value:Contains the current tick value of the counter            | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Return value:     | E_OK:no error                                                   | */
/* |                   | E_OS_ID(only in extended status):The <CounterID> was not valid. | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Description:      | OS376: If the input parameter <CounterID> is not valid, the     | */
/* |                   | service should return E_OS_ID.                                  | */
/* |                   | OS377: If its input parameter is valid, GetCounterValue() shall | */
/* |                   | return the current tick value of the counter via <Value> and    | */
/* |                   | return E_OK.                                                    | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Caveats:          | Note that for counters of OsCounterType = HARDWARE the real     | */
/* |                   | timer value (the ¨C possibly adjusted - hardware value, see      | */
/* |                   | OS384) is returned, whereas for counters of OsCounterType =     | */
/* |                   | SOFTWARE the current ¡°software¡± tick value is returned.         | */
/* | Configuration:    | Available in all Scalability Classes.                           | */
/* |-------------------+-----------------------------------------------------------------| */
StatusType GetCounterValue(CounterType CounterID,TickRefType Value)
{
    StatusType ercd = E_OK;
    CHECK_COMMON_EXT((CounterID < cfgOSEK_COUNTER_NUM),E_OS_ID);
    
    Error_Exit:
    return ercd;
}
/* |-------------------+-------------------------------------------------------------------| */
/* | Service name:     | GetElapsedCounterValue                                            | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Syntax:           | StatusType GetElapsedCounterValue(CounterType CounterID,          | */
/* |                   | TickRefType Value,TickRefType ElapsedValue)                       | */
/* | Service ID:       | OSServiceId_GetElapsedCounterValue                                | */
/* | Sync/Async:       | Sync                                                              | */
/* | Reentrancy:       | Yes                                                               | */
/* | Parameters (in):  | CounterID:The Counter to be read                                  | */
/* |                   | Value:The previously read tick value of the counter               | */
/* | Parameters (out): | Value:Contains the current tick value of the counter              | */
/* |                   | ElapsedValue:The difference to the previous read value            | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Return value:     | E_OK:No error                                                     | */
/* |                   | E_OS_ID(only in extended status):The CounterID was not valid      | */
/* |                   | E_OS_VALUE(only in extended status):The given Value was not valid | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Description:      | OS381: If the input parameter <CounterID> is not valid the        | */
/* |                   | service will return E_OS_ID.                                      | */
/* |                   | OS391: If the <Value> is larger than the max allowed value        | */
/* |                   | of the <CounterID>, the service will return E_OS_VALUE.           | */
/* |                   | OS382: If its input parameter are valid, GetElapsedCounterValue() | */
/* |                   | shall return the number of elapsed ticks since the given <Value>  | */
/* |                   | value via <ElapsedValue> and shall return E_OK.                   | */
/* |                   | OS460: In the <Value> parameter the current tick value of the     | */
/* |                   | counter is returned.                                              | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Caveats:          | If the timer already passed the <Value> value a second            | */
/* |                   | (or multiple) time, the result returned is wrong. The reason      | */
/* |                   | is that the service can not detect such a relative overflow.      | */
/* | Configuration:    | Available in all Scalability Classes.                             | */
/* |-------------------+-------------------------------------------------------------------| */
StatusType GetElapsedCounterValue(CounterType CounterID,
                                  TickRefType Value,TickRefType ElapsedValue)
{
    StatusType ercd = E_OK;
    CHECK_COMMON_EXT((CounterID < cfgOSEK_COUNTER_NUM),E_OS_ID);
    
    Error_Exit:
    return E_OK;
}


/* |-------------------+----------------------------------------------------------------| */
/* | Service name:     | IncrementCounter                                               | */
/* |-------------------+----------------------------------------------------------------| */
/* | Syntax:           | StatusType IncrementCounter(CounterType CounterID)             | */
/* | Service ID:       | OSServiceId_IncrementCounter                                   | */
/* | Sync/Async:       | Sync, may cause rescheduling.                                  | */
/* | Reentrancy:       | Yes                                                            | */
/* | Parameters (in):  | CounterID:The Counter to be incremented                        | */
/* | Parameters (out): | None                                                           | */
/* |-------------------+----------------------------------------------------------------| */
/* | Return value:     | E_OK:No errors                                                 | */
/* |                   | E_OS_ID (only in EXTENDED status):The CounterID was not valid  | */
/* |                   | or counter is implemented in hardware and can not be           | */
/* |                   | incremented by software.                                       | */
/* |-------------------+----------------------------------------------------------------| */
/* | Description:      | OS285: If the input parameter <CounterID> is not valid OR the  | */
/* |                   | counter is a hardware counter, IncrementCounter() shall return | */
/* |                   | E_OS_ID.                                                       | */
/* |                   | OS286: If its input parameter is valid, IncrementCounter()     | */
/* |                   | shall increment the counter <CounterID> by one (if any alarm   | */
/* |                   | connected to this counter expires, the given action, e.g. task | */
/* |                   | activation, is done) and shall return E_OK.                    | */
/* |                   | OS321: If an error happens during the execution of an alarm    | */
/* |                   | action, e.g. E_OS_LIMIT caused by a task activation, the error | */
/* |                   | hook(s) are called, but the IncrementCounter() service itself  | */
/* |                   | will return E_OK.                                              | */
/* |-------------------+----------------------------------------------------------------| */
/* | Caveats:          | if called from a task, rescheduling may take place.            | */
/* | Configuration:    | Available in all Scalability Classes.                          | */
/* |-------------------+----------------------------------------------------------------| */
StatusType IncrementCounter(CounterType CounterID)
{
    StatusType ercd = E_OK;
    
    CHECK_COMMON_EXT((CounterID < cfgOSEK_COUNTER_NUM),E_OS_ID);
    
	BEGIN_CRITICAL_SECTION;

	END_CRITICAL_SECTION;
    Error_Exit:
    return E_OK;
}

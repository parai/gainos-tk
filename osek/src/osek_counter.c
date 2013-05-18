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
#include "knl_queue.h"
#include "knl_alarm.h"
#include "vPort.h"

#if(cfgOSEK_COUNTER_NUM > 0)
EXPORT CCB knl_ccb_table[cfgOSEK_COUNTER_NUM];
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
    *Value = knl_ccb_table[CounterID].curvalue;
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
    *ElapsedValue = knl_ccb_table[CounterID].curvalue -*Value;
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
    TickType max,curvalue;
    CCB* ccb;
    CHECK_COMMON_EXT((CounterID < cfgOSEK_COUNTER_NUM),E_OS_ID);
	BEGIN_DISABLE_INTERRUPT;
    ccb = &knl_ccb_table[CounterID];
    max = knl_almbase_table[CounterID].MaxAllowedValue;
    /* here I see the difference between arccore and nxtOSEK.
       in nxtOSEK, max allowed value allowed for counter and alarm are both the MaxAllowedValue*2,
       as it has implemented the TicksPerBase. So the method used by nxtOSEK is prefered.
    */
    ccb->curvalue = knl_add_ticks(ccb->curvalue,knl_almbase_table[CounterID].TicksPerBase,max*2);
    /* Execute alarm that passed occurring time. */
	while ( !isQueEmpty(&ccb->almque) ) {
	    ALMCB *almcb =  (ALMCB *)ccb->almque.next;
	    if(knl_diff_tick(ccb->curvalue,almcb->time,max*2) > max)
	    {  /* It seems so complicated, but refer OSEK OS specification.
              you will find out the reason. */
	        break;
	    }
	    QueRemove(&almcb->almque);
	    {  /* do alarm callback */
	        ID i = almcb - knl_almcb_table;
	        knl_galm_table[i].almhdr();     
	    }
	    if(almcb->cycle > 0)
	    {
	        almcb->time = knl_add_ticks(almcb->time,almcb->cycle,max*2);
	        knl_alm_insert(almcb,ccb);
	    }
	    else
	    {
	        QueInit(&ccb->almque);
	    }
	}
	END_DISABLE_INTERRUPT;
    Error_Exit:
    return E_OK;
}
#endif /* (cfgOSEK_COUNTER_NUM > 0) */


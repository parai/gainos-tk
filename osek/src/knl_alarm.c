/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine Chin a
 * Open Source Society; either version 1 of the License, or (at developer opti on)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES S FOR
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
#include "knl_alarm.h"
#include "knl_queue.h"

EXPORT CCB knl_ccb_table[cfgOSEK_COUNTER_NUM];
EXPORT ALMCB knl_almcb_table[cfgOSEK_ALARM_NUM];

EXPORT void knl_cntalm_init(void)
{
    INT i;
    CCB* ccb;
    ALMCB* almcb;
    for(i=0;i<cfgOSEK_COUNTER_NUM;i++)
    {
        ccb = &knl_ccb_table[i];
        QueInit(&ccb->almque); 
        ccb->curvalue = 0;
    }
    
    for(i=0;i<cfgOSEK_ALARM_NUM;i++)
    {
        almcb = &knl_almcb_table[i];
        QueInit(&almcb->almque); 
    }
}

EXPORT TickType knl_add_ticks(TickType almval,TickType incr,TickType maxval2)
{
    if(incr <= (maxval2 - almval))
    {
        return (almval+incr);
    }
    else
    {
        return (incr - (maxval2 - almval));
    }
}

EXPORT TickType knl_diff_tick(TickType curval, TickType almval, TickType maxval2)
{
	if (curval >= almval) {
		return(curval - almval);
	}
	else {
		return(maxval2 - almval + curval);
	}
}

EXPORT void knl_alm_insert(ALMCB *almcb,CCB* ccb)
{
    QUEUE* q = ccb->almque.next;
    if(almcb->time < ccb->curvalue)
    {   /* It's an overflowed alarm,So Skip all the no overflowed one*/
        for ( ; q != &ccb->almque; q = q->next ) {
    		if ( ccb->curvalue < ((ALMCB*)q)->time ) {
    			break;
    		}
	    }
    }
    for ( ; q != &ccb->almque; q = q->next ) {
		if ( almcb->time < ((ALMCB*)q)->time ) {
			break;
		}
    }
    QueInsert(&almcb->almque,q);
}
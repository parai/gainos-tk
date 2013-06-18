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
#if(cfgOSEK_ALARM_NUM >0)
EXPORT ALMCB knl_almcb_table[cfgOSEK_ALARM_NUM];

//initialise the counter and alarm table
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
        almcb->almid = i; 
    }
}

//add the alarm value by incr
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

//calculate the difference between counter current value and alarm
//next expiry value.
//if the diff < maxval, it really means the alarm has expiried and 
//should be processed.
EXPORT TickType knl_diff_tick(TickType curval, TickType almval, TickType maxval2)
{
	if (curval >= almval) {
		return(curval - almval);
	}
	else {
		return(maxval2 - almval + curval + 1);
	}
}

//Insert the alarm <almcb> at the proper position at the alarm queue of
//the counter <ccb>.
//The alarm queue is sorted by the alarm next expiry value, from min to max
//NOTE:the overflowed alarm next expiry value(whose time < ccb->curvalue) shoud treat
//bigger than the non-overflowed one.
EXPORT void knl_alm_insert(ALMCB *almcb,CCB* ccb)
{
    QUEUE* q;
    if(almcb->time < ccb->curvalue)
    {   /* It's an overflowed alarm,search from previous */
        for ( q = ccb->almque.prev; q != &ccb->almque; q = q->prev ) {
    		if ( ((almcb->time > ((ALMCB*)q)->time)) || (ccb->curvalue <= ((ALMCB*)q)->time) ) {
    			break;
    		}
	    }
	    q = q->next;
    }
    else
    {
        for ( q = ccb->almque.next; q != &ccb->almque; q = q->next ) {
    		if ( (almcb->time < ((ALMCB*)q)->time) || (ccb->curvalue > ((ALMCB*)q)->time) ) {
    			break;
    		}
        }
    }
    QueInsert(&almcb->almque,q);
}

#endif /* (cfgOSEK_ALARM_NUM >0) */



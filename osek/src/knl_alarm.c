#include "knl_alarm.h"

EXPORT CCB knl_ccb_table[cfgOSEK_COUNTER_NUM];
EXPORT ALMCB knl_almcb_table[cfgOSEK_ALARM_NUM];

EXPORT void knl_counter_init(void)
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
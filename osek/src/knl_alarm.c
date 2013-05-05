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
    
    for(i=0;i<cfgOSEK_COUNTER_NUM;i++)
    {
        almcb = &knl_almcb_table[i];
        QueInit(&almcb->almque); 
    }
}
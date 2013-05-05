#ifndef KNL_ALARM_H_H
#define KNL_ALARM_H_H
#include "osek_os.h"
#include "knl_queue.h"
/* Alarm Control Block */
typedef struct AlmCtrlBlk
{
    QUEUE           almque;
    TickType        xAlarmValue; /* The Time It will expire */
    TickType        xCycle;
}ALMCB;

#endif /* KNL_ALARM_H_H */
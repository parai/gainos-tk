#ifndef KNL_ALARM_H_H
#define KNL_ALARM_H_H

/* ============================ INCLUDEs =============================== */
#include "osek_os.h"
#include "knl_queue.h"

/* ============================ TYPEs    =============================== */
typedef struct counter_control_block
{
    QUEUE  almque;
    TickType  curvalue; /* current value of the Counter */
}CCB;

typedef struct alarm_generate_info
{
    CounterType owner; /* Alarm Owner -> Counter */
    FP          almhdr;  /* Alarm handler */
}T_GALM;

/* Alarm Control Block */
typedef struct AlmCtrlBlk
{
    QUEUE           almque;
    TickType        time; /* The Time It will expire */
    TickType        cycle;
}ALMCB;

/* ============================ DATAs    =============================== */
IMPORT CCB knl_ccb_table[];
IMPORT ALMCB knl_almcb_table[];
IMPORT const T_GALM  knl_galm_table[];
IMPORT const AlarmBaseType knl_almbase_table[];

/* ============================ FUNCTIONs =============================== */
IMPORT void knl_counter_init(void);
IMPORT TickType knl_add_ticks(TickType almval,TickType incr,TickType maxval2);
IMPORT void knl_alm_insert(ALMCB *almcb,CCB* ccb);
#endif /* KNL_ALARM_H_H */
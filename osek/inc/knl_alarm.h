#ifndef KNL_ALARM_H_H
#define KNL_ALARM_H_H

/* ============================ INCLUDEs =============================== */
#include "osek_os.h"


/* ============================ DATAs    =============================== */
IMPORT CCB knl_ccb_table[];
IMPORT ALMCB knl_almcb_table[];
IMPORT const T_GALM  knl_galm_table[];
IMPORT const AlarmBaseType knl_almbase_table[];

/* ============================ FUNCTIONs =============================== */
IMPORT void knl_cntalm_init(void);
IMPORT TickType knl_add_ticks(TickType almval,TickType incr,TickType maxval2);
IMPORT void knl_alm_insert(ALMCB *almcb,CCB* ccb);
IMPORT TickType knl_diff_tick(TickType curval, TickType almval, TickType maxval2);
#endif /* KNL_ALARM_H_H */
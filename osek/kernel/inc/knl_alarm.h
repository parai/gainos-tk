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
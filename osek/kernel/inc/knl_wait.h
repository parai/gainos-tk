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
#ifndef KNL_WAIT_H_H
#define KNL_WAIT_H_H
#include "osek_os.h"

IMPORT WSPEC    knl_wspec_slp;

#define knl_timer_delete(__event)   \
    QueRemove(&((TMEB *)__event)->queue)
      
IMPORT void knl_make_non_wait( TCB *tcb );
IMPORT void knl_make_wait( TickType tmout);
IMPORT void knl_wait_release_ok( TCB *tcb );
IMPORT void knl_wait_release_tmout( TCB *tcb );
IMPORT void knl_wait_release_tmout( TCB *tcb );

#endif /* KNL_WAIT_H_H */
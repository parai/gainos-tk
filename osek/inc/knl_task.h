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

#ifndef KNL_TASK_H_H
#define KNL_TASK_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h"

/* ============================ MACROs    ========================================== */
/*
 * Task dispatch disable state
 *	0 = DDS_ENABLE		 : ENABLE
 *	1 = DDS_DISABLE_IMPLICIT : DISABLE with implicit process
 *	2 = DDS_DISABLE		 : DISABLE with tk_dis_dsp()
 *	|	|
 *	|	use in *.c
 *	use in *.S
 *	  --> Do NOT change these literals, because using in assembler code
 *
 *	'dispatch_disabled' records dispatch disable status set by tk_dis_dsp()
 *	for some CPU, that accepts delayed interrupt.
 *	In this case, you can NOT refer the dispatch disabled status
 *	only by 'dispatch_disabled'.
 *	Use 'in_ddsp()' to refer the task dispatch status.
 *	'in_ddsp()' is a macro definition in CPU-dependent definition files.
 */
#define DDS_ENABLE		(0)
#define DDS_DISABLE_IMPLICIT	(1)	/* set with implicit process */
#define DDS_DISABLE		(2)	/* set by tk_dis_dsp() */

#define knl_task_alive( __state )   \
    ((BOOL)( (( __state ) & (TS_READY|TS_WAIT|TS_SUSPEND)) != 0 ))
    
/*
 * Return the priority of the highest priority task in the ready queue
 */
#define  knl_ready_queue_top_priority(__rq) ((INT) ((__rq)->top_priority))

/* ============================ DATAs    ========================================== */
IMPORT INT	knl_dispatch_disabled;
IMPORT TCB	*knl_ctxtsk;
IMPORT TCB	*knl_schedtsk;
IMPORT RDYQUE	knl_ready_queue;
IMPORT TCB	knl_tcb_table[cfgOSEK_TASK_NUM];
IMPORT const T_GTSK	knl_gtsk_table[cfgOSEK_TASK_NUM];
IMPORT	INT  	knl_taskindp;
IMPORT	UINT	knl_taskmode;

/* ============================ FUNCTIONs    ====================================== */
IMPORT void knl_task_init(void);
IMPORT void knl_ready_queue_initialize( RDYQUE *rq );
IMPORT TCB* knl_ready_queue_top( RDYQUE *rq );
IMPORT void knl_ready_queue_insert( RDYQUE *rq, TCB *tcb );
IMPORT void knl_ready_queue_insert_top( RDYQUE *rq, TCB *tcb );
IMPORT void knl_ready_queue_delete( RDYQUE *rq, TCB *tcb );
IMPORT void knl_reschedule( void );
IMPORT void knl_make_active( TCB *tcb );
IMPORT void knl_make_runnable( TCB *tcb );
IMPORT void knl_search_schedtsk(void);

#endif /* KNL_TASK_H_H */
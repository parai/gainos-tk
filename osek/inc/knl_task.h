/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */

#ifndef KNL_TASK_H_H
#define KNL_TASK_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h"
#include "knl_queue.h"
#include "knl_resource.h"

/* ============================ MACROs    ========================================== */
#define BITMAPSZ	( sizeof(UINT) * 8 )
#define NUM_BITMAP	( ((cfgOSEK_MAX_PRIO+1) + BITMAPSZ - 1) / BITMAPSZ )
#define NUM_PRI     (cfgOSEK_MAX_PRIO+1)

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
/* ============================ TYPEs    ========================================== */
/*
 * Internal expression of task state
 *	Can check with 'state & TS_WAIT' whether the task is in the wait state.
 *	Can check with 'state & TS_SUSPEND' whether the task is in the forced 
 *	wait state.
 */
typedef enum {
	TS_NONEXIST	= 0,	/* Unregistered state */
	TS_READY	= 1,	/* RUN or READY state */
	TS_WAIT		= 2,	/* WAIT state */
	TS_SUSPEND	= 4,	/* SUSPEND state */
	TS_WAITSUS	= 6,	/* Both WAIT and SUSPEND state */
	TS_DORMANT	= 8	    /* DORMANT state */
} TSTAT;

/*
 * Task gerneration information
 */
typedef struct t_gtsk {
	ATR	tskatr;		/* Task attribute */
	FP	task;		/* Task startup address */
	PRI	itskpri;	/* Priority at task startup */
	UINT	stksz;		/* User stack size (byte) */
	VP	isstack;	/* User stack top pointer */
    ID  flgid;      /* Event Id occupied by task */
} T_GTSK;

typedef struct task_control_block{
    QUEUE	    tskque;		/* Task queue */
    CTXB     	tskctxb;	/* Task context block */
	PRI	        priority;	/* Current priority */
	BOOL	    klockwait:1;	/* TRUE at wait kernel lock */
	BOOL     	klocked:1;	    /* TRUE at hold kernel lock */	
	UB /*TSTAT*/	state;	/* Task state (Int. expression) */			
	QUEUE resque;	/* queue to hold resources */		 
}TCB;

/*
 * Definition of ready queue structure 
 *	In the ready queue, the task queue 'tskque' is provided per priority.
 *	The task TCB is registered onto queue with the applicable priority.
 *	For effective ready queue search, the bitmap area 'bitmap' is provided
 *	to indicate whether there are tasks in task queue per priority.
 *	
 *	Also, to search a task at the highest priority in the ready queue  
 *    	effectively, put the highest task priority in the 'top_priority' field.
 *	If the ready queue is empty, set the value in this field to NUM_PRI. 
 *	In this case, to return '0' with refering 'tskque[top_priority]',
 *      there is 'null' field which is always '0'.
 *
 *	Multiple READY tasks with kernel lock do not exist at the same time.
 */
typedef	struct ready_queue {
	INT	top_priority;		/* Highest priority in ready queue */
	QUEUE	tskque[NUM_PRI];	/* Task queue per priority */
	TCB	*   null;			/* When the ready queue is empty, */
	UINT	bitmap[NUM_BITMAP];	/* Bitmap area per priority */
	TCB	*klocktsk;	/* READY task with kernel lock */
} RDYQUE;

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
IMPORT void knl_tasks_autostart(void);
IMPORT void knl_ready_queue_initialize( RDYQUE *rq );
IMPORT TCB* knl_ready_queue_top( RDYQUE *rq );
IMPORT BOOL knl_ready_queue_insert( RDYQUE *rq, TCB *tcb );
IMPORT void knl_ready_queue_insert_top( RDYQUE *rq, TCB *tcb );
IMPORT void knl_ready_queue_delete( RDYQUE *rq, TCB *tcb );
IMPORT void knl_ready_queue_rotate( RDYQUE *rq, INT priority );
IMPORT TCB* knl_ready_queue_move_last( RDYQUE *rq, TCB *tcb );
IMPORT void knl_reschedule( void );
IMPORT void knl_make_dormant( TCB *tcb );
IMPORT void knl_make_ready( TCB *tcb );
IMPORT void knl_make_non_ready( TCB *tcb );
IMPORT void knl_change_task_priority( TCB *tcb, PRI priority );

#endif /* KNL_TASK_H_H */
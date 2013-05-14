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
#include  "knl_timer.h" 
#include "knl_queue.h"
#include "vPort.h"             

EXPORT LSYSTIM  knl_current_time = 0 ;
EXPORT QUEUE	knl_timer_queue;

/*
 * Insert timer event to timer event queue
 */
LOCAL void knl_enqueue_tmeb( TMEB *event )
{
	QUEUE	*q;

	for ( q = knl_timer_queue.next; q != &knl_timer_queue; q = q->next ) {
		if ( event->time < ((TMEB*)q)->time) {
			break;
		}
	}
	QueInsert(&event->queue, q);
}

EXPORT void knl_timer_init(void)
{
    QueInit(&knl_timer_queue);
    knl_start_hw_timer();
}
/*
 * Set timeout event
 *	Register the timer event 'event' onto the timer queue to
 *	start after the timeout 'tmout'. At timeout, start with the
 *	argument 'arg' on the callback function 'callback'.
 *	When 'tmout' is TMO_FEVR, do not register onto the timer
 *	queue, but initialize queue area in case 'timer_delete' 
 *	is called later.
 *
 *	"include/tk/typedef.h"
 *	typedef	W		TMO;
 *	typedef UW		RELTIM;
 *	#define TMO_FEVR	(-1)
 */
EXPORT void knl_timer_insert( TMEB *event, TickType tmout, CBACK callback, VP arg )
{
	event->callback = callback;
	event->arg = arg;

	if ( tmout == TMO_FEVR ) {
		QueInit(&event->queue);
	} else {
		/* To guarantee longer wait time specified by 'tmout',
		   add TIMER_PERIOD on wait time */
		event->time = knl_current_time + tmout;
		knl_enqueue_tmeb(event);
	}
}

/* ------------------------------------------------------------------------ */

/*
 * Timer interrupt handler
 *	Timer interrupt handler starts every TIMER_PERIOD millisecond 
 *	interval by hardware timer. Update the software clock and start the 
 *	timer event upon arriving at start time.
 */

EXPORT void knl_timer_handler( void )
{
	TMEB	*event;

	BEGIN_DISABLE_INTERRUPT;
	knl_current_time++;
	/* Execute event that passed occurring time. */
	while ( !isQueEmpty(&knl_timer_queue) ) {
		event = (TMEB*)knl_timer_queue.next;

		if ( event->time > knl_current_time ) {
			break;
		}

		QueRemove(&event->queue);
		if ( event->callback != NULL_FP ) {
			(*event->callback)(event->arg);
		}
	}
	END_DISABLE_INTERRUPT;
}

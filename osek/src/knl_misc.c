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
#include "knl_queue.h"
#include "knl_task.h"
#include "knl_bitop.h"
#include <string.h>

EXPORT QUEUE* QueRemoveNext( QUEUE *que )
{
	QUEUE	*entry;

	if ( que->next == que ) {
		return NULL;
	}

	entry = que->next;
	que->next = (struct queue*)entry->next;
	entry->next->prev = que;

	return entry;
}

EXPORT void knl_ready_queue_initialize( RDYQUE *rq )
{
	INT	i;

	rq->top_priority = NUM_PRI;
	for ( i = 0; i < NUM_PRI; i++ ) {
		QueInit(&rq->tskque[i]);
	}
	rq->null = NULL;
	rq->klocktsk = NULL;
	(void)memset(rq->bitmap, 0, sizeof(rq->bitmap));
}
/*
 * Return the highest priority task in ready queue
 */
EXPORT TCB* knl_ready_queue_top( RDYQUE *rq )
{
	/* If there is a task at kernel lock, that is the highest priority task */
	if ( rq->klocktsk != NULL ) {
		return rq->klocktsk;
	}

	return (TCB*)rq->tskque[rq->top_priority].next;
}
/*
 * Insert task in ready queue
 *	Insert it at the end of the same priority tasks with task priority 
 *	indicated with 'tcb'. Set the applicable bit in the bitmap area and 
 *	update 'top_priority' if necessary. When updating 'top_priority,' 
 *	return TRUE, otherwise FALSE.
 */
EXPORT BOOL knl_ready_queue_insert( RDYQUE *rq, TCB *tcb )
{
	INT	priority = tcb->priority;

	QueInsert(&tcb->tskque, &rq->tskque[priority]);
	knl_tstdlib_bitset(rq->bitmap, priority);

	if ( tcb->klocked ) {
		rq->klocktsk = tcb;
	}

	if ( priority < rq->top_priority ) {
		rq->top_priority = priority;
		return TRUE;
	}
	return FALSE;
}

/*
 * Insert task at head in ready queue 
 */
EXPORT void knl_ready_queue_insert_top( RDYQUE *rq, TCB *tcb )
{
	INT	priority = tcb->priority;

	QueInsert(&tcb->tskque, rq->tskque[priority].next);
	knl_tstdlib_bitset(rq->bitmap, priority);

	if ( tcb->klocked ) {
		rq->klocktsk = tcb;
	}

	if ( priority < rq->top_priority ) {
		rq->top_priority = priority;
	}
}
/*
 * Delete task from ready queue
 *	Take out TCB from the applicable priority task queue, and if the task 
 *	queue becomes empty, clear the applicable bit from the bitmap area.
 *	In addition, update 'top_priority' if the deleted task had the highest 
 *	priority. In such case, use the bitmap area to search the second
 *	highest priority task.
 */
EXPORT void knl_ready_queue_delete( RDYQUE *rq, TCB *tcb )
{
	INT	priority = tcb->priority;
	INT	i;

	if ( rq->klocktsk == tcb ) {
		rq->klocktsk = NULL;
	}

	QueRemove(&tcb->tskque);
	if ( tcb->klockwait ) {
		/* Delete from kernel lock wait queue */
		tcb->klockwait = FALSE;
		return;
	}
	if ( !isQueEmpty(&rq->tskque[priority]) ) {
		return;
	}

	knl_tstdlib_bitclr(rq->bitmap, priority);
	if ( priority != rq->top_priority ) {
		return;
	}

	i = knl_tstdlib_bitsearch1(rq->bitmap, priority, NUM_PRI - priority);
	if ( i >= 0 ) {
		rq->top_priority = priority + i;
	} else {
		rq->top_priority = NUM_PRI;
	}
}
/*
 * Move the task, whose ready queue priority is 'priority', at head of
 * queue to the end of queue. Do nothing, if the queue is empty.
 */
EXPORT void knl_ready_queue_rotate( RDYQUE *rq, INT priority )
{
	QUEUE	*tskque = &rq->tskque[priority];
	TCB	*tcb;

	tcb = (TCB*)QueRemoveNext(tskque);
	if ( tcb != NULL ) {
		QueInsert((QUEUE*)tcb, tskque);
	}
}
/*
 * Put 'tcb' to the end of ready queue. 
 */
IMPORT TCB* knl_ready_queue_move_last( RDYQUE *rq, TCB *tcb )
{
	QUEUE	*tskque = &rq->tskque[tcb->priority];

	QueRemove(&tcb->tskque);
	QueInsert(&tcb->tskque, tskque);

	return (TCB*)tskque->next;	/* New task at head of queue */
}
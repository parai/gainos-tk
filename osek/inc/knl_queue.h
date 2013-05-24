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

#ifndef KNL_QUEUE_H_H
#define KNL_QUEUE_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h"

/* ============================ MACROs    ========================================== */
/*
 * Queue initialization
 */
Inline void  QueInit(QUEUE* que)
{
	que->next = (struct queue *)que;
	que->prev = (struct queue *)que;
}

/*
 * TRUE if the queue is empty
 */
#define isQueEmpty(__que)   ((boolean)(( (__que)->next == (__que) )))

/*
 * Insert in queue
 *	Inserts entry directly prior to que
 */
Inline void QueInsert(QUEUE* entry,QUEUE* que) 
{
	entry->prev = (struct queue*) que->prev;
	entry->next = que;
	que->prev->next = entry;
	que->prev = entry; 
}

/*
 * Delete from queue
 *	Deletes entry from queue
 *	No action is performed if entry is empty.
 */
#define QueRemove(__entry)                                          \
do                                                                  \
{                                                                   \
     	if ( (__entry)->next != (__entry) ) {                       \
		(__entry)->prev->next = (struct queue*) (__entry)->next;    \
		(__entry)->next->prev = (struct queue*) (__entry)->prev;    \
	}                                                               \
}while(0)

/* ============================ FUNCTIONs    ========================================== */
/*
 * Remove top entry
 *	Deletes the entry directly after que from the queue,
 *	and returns the deleted entry.
 *	Returns NULL if que is empty.
 */
IMPORT QUEUE* QueRemoveNext( QUEUE *que );

#endif /* KNL_QUEUE_H_H */

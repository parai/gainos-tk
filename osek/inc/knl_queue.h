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
#if 0
/* Yeah, I think the Macro QueInit() is ok. It really works ok on codewarrior.
 * But for Tasking for TriCore, shit.
 */
#define QueInit(__que)                              \
do                                                  \
{                                                   \
     (__que)->next = (struct queue *)(__que);       \
     (__que)->prev = (struct queue *)(__que);       \
}while(0);
#else
Inline void  QueInit(QUEUE* que)
{
	que->next = (struct queue *)que;
	que->prev = (struct queue *)que;
}
#endif

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
#if 0    /* make consistant with QueInit() ... */
#define QueRemove(__entry)                                          \
do                                                                  \
{                                                                   \
     	if ( (__entry)->next != (__entry) ) {                       \
		(__entry)->prev->next = (struct queue*) (__entry)->next;    \
		(__entry)->next->prev = (struct queue*) (__entry)->prev;    \
	}                                                               \
}while(0)
#else
Inline void QueRemove(QUEUE* entry)                                                                                            
{                                                                   
 	if ( entry->next != entry ) {                      
    	entry->prev->next = (struct queue*) entry->next;    
    	entry->next->prev = (struct queue*) entry->prev;  
	} 
}                                                             
#endif

#if 0
/*
 * Remove top entry
 *	Deletes the entry directly after que from the queue,
 *	and returns the deleted entry.
 *	Returns NULL if que is empty.
 */
Inline QUEUE* QueRemoveNext( QUEUE *que )
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
#endif

Inline void  FifoQueInit(FIFOQUE* que)
{
	que->tail = que->head = 0;
}

/* push the element entry to the tail of the fifo queue */
Inline void FifoQuePush(VP entry,FIFOQUE* que) 
{
    que->fifoque[que->tail] = entry;
	/* no care of overflow */
	if((que->tail+1) < que->length)
	{
		que->tail++;
	}
	else
	{
		que->tail = 0;
	}	
}
/* push the element entry to the head of the fifo queue */
Inline void FifoQueAltPush(VP entry,FIFOQUE* que) 
{
	/* no care of overflow */
	if((que->head-1) < 0)
	{
		que->head = que->length - 1;
	}
	else
	{
		que->head--;
	}
	que->fifoque[que->head] = entry;
}
/* pop the head element from the fifo queue */
Inline void FifoQuePop(FIFOQUE* que) 
{
	/* no care of overflow */
	if(que->head == que->tail)
	{
		return;
	}
		
    //que->fifoque[que->head] = NULL; //for debug purpose
	
	if((que->head+1) < que->length)
	{
		que->head++;
	}
	else
	{
		que->head = 0;
	}
}
/* polling the head element from the fifo queue */
Inline VP FifoQuePoll(FIFOQUE* que) 
{
	if(que->head == que->tail)
	{
		return NULL;
	}
	return que->fifoque[que->head];
}

#define isFifoQueEmpty(__que)   ((boolean)(( (__que)->head == (__que)->tail )))

#endif /* KNL_QUEUE_H_H */

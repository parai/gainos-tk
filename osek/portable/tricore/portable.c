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
/*
 * This vPort is For TASKING VX-toolset TriCore.
 * Run OK on TriCore(TC1797) family chip.
 */
#include "portable.h"
#include "knl_timer.h"
#include "knl_task.h"

EXPORT void knl_start_hw_timer( void )
{
	/* Do nothing, as DAVE has done this. */
}
EXPORT void knl_setup_context( TCB *tcb )
{
	tcb->tskctxb.ssp = tcb->isstack;
	tcb->tskctxb.dispatcher = 1;
}

/*
 * When a task is deleted, it is yielded permanently until the IDLE task
 * has an opportunity to reclaim the memory that that task was using.
 * Typically, the memory used by a task is the TCB and Stack but in the
 * TriCore this includes the CSAs that were consumed as part of the Call
 * Stack. These CSAs can only be returned to the Globally Free Pool when
 * they are not part of the current Call Stack, hence, delaying the
 * reclamation until the IDLE task is freeing the task's other resources.
 * This function uses the head of the linked list of CSAs (from when the
 * task yielded for the last time) and finds the tail (the very bottom of
 * the call stack) and inserts this list at the head of the Free list,
 * attaching the existing Free List to the tail of the reclaimed call stack.
 *
 * NOTE: the IDLE task needs processing time to complete this function
 * and in heavily loaded systems, the Free CSAs may be consumed faster
 * than they can be freed assuming that tasks are being spawned and
 * deleted frequently.
 */
/* In FreeRTOS,This API is called when in idle task.*/
LOCAL void vPortReclaimCSA( unsigned long pxHeadCSA )
{
    unsigned long  pxTailCSA, pxFreeCSA;
    unsigned long *pulNextCSA;

	pxHeadCSA = pxHeadCSA & 0x000FFFFFUL;

	/* Mask off everything in the CSA link field other than the address.  If
       the	address is NULL, then the CSA is not linking anywhere and there is
       nothing	to do. */
	pxTailCSA = pxHeadCSA;

	/* Convert the link value to contain just a raw address and store this
       in a local variable. */
	pulNextCSA = vPortCSA_TO_ADDRESS( pxTailCSA );

	/* Iterate over the CSAs that were consumed as part of the task.  The
       first field in the CSA is the pointer to then next CSA.  Mask off
       everything in the pointer to the next CSA, other than the link address.
       If this is NULL, then the CSA currently being pointed to is the last in
       the chain. */
	while( 0UL != ( pulNextCSA[ 0 ] & 0x000FFFFFUL ) )
	{
		/* Clear all bits of the pointer to the next in the chain, other
           than the address bits themselves. */
		pulNextCSA[ 0 ] = pulNextCSA[ 0 ] & 0x000FFFFFUL;

		/* Move the pointer to point to the next CSA in the list. */
		pxTailCSA = pulNextCSA[ 0 ];

		/* Update the local pointer to the CSA. */
		pulNextCSA = vPortCSA_TO_ADDRESS( pxTailCSA );
	}

	{
		/* Look up the current free CSA head. */
		__dsync();
		pxFreeCSA = __mfcr( FCX );

		/* Join the current Free onto the Tail of what is being reclaimed. */
		pulNextCSA[ 0 ] = pxFreeCSA;

		/* Move the head of the reclaimed into the Free. */
		__dsync();
		__mtcr( FCX, pxHeadCSA );
		__isync();
	}
	/* Here When return,the link info in PCXI is of no use.
	 * It has been put to FCX*/
}

EXPORT void enaint(imask_t mask)
{
	__mtcr(ICR,mask);
}

EXPORT imask_t disint()
{
	imask_t mask;
	mask = __mfcr(ICR);
	__disable();
	return mask;
}
void knl_activate_r(void)
{
	unsigned long sp = (unsigned long)(knl_ctxtsk->isstack);
	__asm("mov.a\tsp,%0"::"d"(sp));
	/* Supervisor Mode, IS = 0 User Stack and Call Depth Counting disabled. */
	__mtcr(PSW,0x000008FFUL);
	{//lower cpu IPL
		unsigned long ulICR;
		ulICR = __mfcr( ICR );
		ulICR &= ~0x000000FFUL;
		__mtcr(ICR,ulICR);
	}
	__enable();
	knl_ctxtsk->task();
}
void knl_dispatch_r(void)
{
	/* Clear the PSW.CDC to enable the use of an RFE without it generating an
		exception because this code is not genuinely in an exception. */
//	{
//		unsigned long ulMFCR = 0UL;
//		ulMFCR = __mfcr( PSW );
//		ulMFCR &= ( ~( 0x000000FFUL ) );
//		__dsync();
//		__mtcr( PSW, ulMFCR );
//		__isync();
//	}
	__dsync();
	__mtcr( PCXI, (UW)(knl_ctxtsk->tskctxb.ssp) );
	__isync();
	__nop();
	__rslcx();
	__nop();

	/* Return to the first task selected to execute. */
	__asm volatile( "rfe" );
}
void l_dispatch0(void)
{
	/* lower CPU IPL to 0*/
	__mtcr(ICR,((__mfcr(ICR)&(0xFFFFFF00))));
l_dispatch1:
	__disable();
	if(NULL == knl_schedtsk)
	{
		__enable();
		__nop();
		__nop();
		__nop();
		__nop();
		goto l_dispatch1;
	}
//l_dispatch2:
	knl_ctxtsk = knl_schedtsk;
	knl_dispatch_disabled=0;    /* Dispatch enable */

	if(1 == knl_ctxtsk->tskctxb.dispatcher)
	{
		__asm("j knl_activate_r");
	}
	else
	{
		__asm("j knl_dispatch_r");
	}
}
extern __far void _lc_ue_istack[];      /* interrupt stack end */
EXPORT void knl_force_dispatch(void)
{
	/* load tmp stack(share the ISP,see the linker file) */
	 unsigned int sp = (unsigned int)(_lc_ue_istack);
	 __asm("mov.a\tsp,%0"::"d"(sp));

	knl_dispatch_disabled = 1;    /* Dispatch disable */
	knl_ctxtsk = NULL;
	__disable();	//disable interrupt

	/* Free the csa used by knl_ctxtsk */
	// TODO: BUG here
	// vPortReclaimCSA(__mfcr(PCXI));
	/* Don't consume CSA.So just Jump*/
	__asm("j l_dispatch0");
}
EXPORT __trap(3) void knl_context_trap(void)
{
	/* If Context Error, Deadloop. */
	for(;;);
}
EXPORT __trap(6) void knl_dispatch_entry(void)
{
	knl_dispatch_disabled = 1;    /* Dispatch disable */
	__disable();
	__dsync();
	__svlcx(); /* save lower contex */
	knl_ctxtsk->tskctxb.ssp = __mfcr( PCXI );
	knl_ctxtsk->tskctxb.dispatcher = 0;
	knl_ctxtsk = NULL;
	__isync();

	/* Don't consume CSA.So just Jump*/
	__asm("j l_dispatch0");
}

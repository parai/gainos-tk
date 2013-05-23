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
 * This portable is For TASKING VX-toolset TriCore.
 * TODO:still not finshed, trap context will be generated
 */
#include "portable.h"
#include "knl_timer.h"
#include "knl_task.h"
#include "INT.h"

EXPORT void knl_start_hw_timer( void )
{
	/* Do nothing, as DAVE has done this. */
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
EXPORT void knl_reclaim_csa( unsigned long pxHeadCSA )
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
	pulNextCSA = CSA_TO_ADDRESS( pxTailCSA );

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
		pulNextCSA = CSA_TO_ADDRESS( pxTailCSA );
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
EXPORT void knl_set_ipl(UINT ipl)
{
	UW ulICR;
	ulICR = __mfcr( ICR );
	ulICR &= ~0x000000FFUL;
	ulICR |= ipl;
	__mtcr(ICR,ulICR);
}
#define cfgUSE_FREERTOS_PORT STD_OFF
#if(cfgUSE_FREERTOS_PORT == STD_ON)
EXPORT void knl_setup_context( TCB *tcb )
{
    UpperCSA *pulUpperCSA = NULL;
    LowerCSA *pulLowerCSA = NULL;
    ID tskid = tcb - knl_tcb_table;
    /* 16 Address Registers (4 Address registers are global), 16 Data
    	Registers, and 3 System Registers.

    	There are 3 registers that track the CSAs.
    		FCX points to the head of globally free set of CSAs.
    		PCX for the task needs to point to Lower->Upper->NULL arrangement.
    		LCX points to the last free CSA so that corrective action can be taken.

    	Need two CSAs to store the context of a task.
    		The upper context contains D8-D15, A10-A15, PSW and PCXI->NULL.
    		The lower context contains D0-D7, A2-A7, A11 and PCXI->UpperContext.
    		The pxCurrentTCB->pxTopOfStack points to the Lower Context RSLCX matching the initial BISR.
    		The Lower Context points to the Upper Context ready for the return from the interrupt handler.

    	 The Real stack pointer for the task is stored in the A10 which is restored
    	 with the upper context. */
    /* DSync to ensure that buffering is not a problem. */
    __dsync();
    /* Consume two free CSAs. */
    pulLowerCSA = (LowerCSA*)CSA_TO_ADDRESS( __mfcr( FCX ) );
    if( NULL != pulLowerCSA )
	{
		/* The Lower Links to the Upper. */
		pulUpperCSA = (UpperCSA*)CSA_TO_ADDRESS( pulLowerCSA->pcxi );
	}
    /* Check that we have successfully reserved two CSAs. */
	if( ( NULL != pulLowerCSA ) && ( NULL != pulUpperCSA ) )
	{
		/* Remove the two consumed CSAs from the free CSA list. */
		__dsync();
		__mtcr( FCX, pulUpperCSA->pcxi );
		__isync();
	}
	else
	{
		/* Simply trigger a context list depletion trap. */
		__svlcx();
	}
	pulUpperCSA->SP = (UW)(tcb->isstack);
	pulUpperCSA->psw = 0x000008FFUL; /* Supervisor Mode, IS = 0 User Stack and Call Depth Counting disabled. */

	pulLowerCSA->RA = (UW)(tcb->task);

	/* PCXI pointing to the Upper context and PIE = 1, So interrupt enabled */
	pulLowerCSA->pcxi = ( ( 0x00C00000UL ) | ( unsigned long ) ADDRESS_TO_CSA( pulUpperCSA ) );
	pulUpperCSA->pcxi = 0; /* NULL */
	tcb->tskctxb.ssp = (unsigned long * ) ADDRESS_TO_CSA( pulLowerCSA );
}
void l_dispatch0(void)
{
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

	/* Finally, perform the equivalent of a portRESTORE_CONTEXT() */

	__dsync();
	__mtcr( PCXI, (UW)(knl_ctxtsk->tskctxb.ssp) );
	__isync();
	__nop();
	__rslcx();
	__nop();

	/* Return to the first task selected to execute. */
	__asm volatile( "rfe" );
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
	knl_reclaim_csa(__mfcr(PCXI));

	/* Clear the PSW.CDC to enable the use of an RFE without it generating an
	exception because this code is not genuinely in an exception. */
	{
		unsigned long ulMFCR = 0UL;
		ulMFCR = __mfcr( PSW );
		ulMFCR &= ( ~( 0x000000FFUL ) );
		__dsync();
		__mtcr( PSW, ulMFCR );
		__mtcr( PCXI,0);
		__isync();
	}

	/* Don't consume CSA.So just Jump*/
	__asm("j l_dispatch0");
}
EXPORT __interrupt (CPU0INT) void knl_dispatch_entry(void)
{
	knl_dispatch_disabled = 1;    /* Dispatch disable */
	__disable();
	__dsync();
	__svlcx(); /* save lower contex */
	knl_ctxtsk->tskctxb.ssp = __mfcr( PCXI );
	knl_ctxtsk = NULL;
	__isync();

	/* Don't consume CSA.So just Jump*/
	__asm("j l_dispatch0");
}

#else /* cfgUSE_FREERTOS_PORT */
void knl_activate_r(void);
EXPORT void knl_setup_context( TCB *tcb )
{
	tcb->tskctxb.ssp = tcb->isstack;
	tcb->tskctxb.dispatcher = knl_activate_r;
}


#if 0
void knl_activate_r(void)
{
	UW *pulUpperCSA = CSA_TO_ADDRESS(__mfcr(FCX));
	/* Check that we have successfully reserved two CSAs. */
	if( NULL != pulUpperCSA )
	{
		/* Remove the two consumed CSAs from the free CSA list. */
		__disable();
		__dsync();
		__mtcr( FCX, pulUpperCSA[ 0 ] );
		__isync();
		__enable();
	}
	else
	{
		/* Simply trigger a context list depletion trap. */
		__svlcx();
	}
	/* Upper Context. */
	pulUpperCSA[ 2 ] = (UW)knl_ctxtsk->isstack;		/* A10;	Stack Return aka Stack Pointer */
	pulUpperCSA[ 1 ] = 0x000008FFUL;				/* PSW	*/
	pulUpperCSA[ 0 ] = 0x00000000UL;				/* PCXI */
	__dsync();
	__mtcr(PCXI,(0x00C00000UL | (UW)ADDRESS_TO_CSA(pulUpperCSA)));
	__isync();
	__asm("mov.a\ta11,%0"::"d"((UW)knl_ctxtsk->task));
	__asm("rfe");
}
#else
void knl_activate_r(void)
{
	UW sp = (UW)(knl_ctxtsk->tskctxb.ssp);
	__asm("mov.a\tsp,%0"::"d"(sp));
	__dsync();
	/* Supervisor Mode, IS = 0 User Stack and Call Depth Counting disabled. */
	__mtcr(PSW,0x000008FFUL);
	__mtcr( PCXI, 0 );
	__isync();
	knl_set_ipl(0);
	__enable();
	{	//jump to task
		UW task = (UW)knl_ctxtsk->task;
		__asm("mov.a\ta15,%0"::"d"(task));
		__asm("ji a15");
	}
}
#endif
void knl_dispatch_r(void)
{
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
	knl_set_ipl(0);
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
	{
		UW dispatcher = (UW)knl_ctxtsk->tskctxb.dispatcher;
		__asm("mov.a\ta15,%0"::"d"(dispatcher));
		__asm("ji a15");
	}
}
extern __far void _lc_ue_istack[];      /* interrupt stack end */
EXPORT void knl_force_dispatch(void)
{
	UW sp = (UW)(_lc_ue_istack);
	__asm("mov.a\tsp,%0"::"d"(sp));
	knl_dispatch_disabled = 1;    /* Dispatch disable */
	knl_ctxtsk = NULL;
	__disable();	//disable interrupt

	/* Free the csa used by knl_ctxtsk */
	knl_reclaim_csa(__mfcr(PCXI));

	/* Don't consume CSA.So just Jump*/
	__asm("j l_dispatch0");
}
EXPORT __trap(2) void knl_instruction_trap(void)
{
	/* If Instruction Error, Deadloop. */
	__debug();
	for(;;);
}
EXPORT __trap(3) void knl_context_trap(void)
{
	/* If Context Error, Deadloop. */
	__debug();
	for(;;);
}
/* This is a CPU_SRC0 pending ISR used for context switch */
EXPORT void __interrupt (CPU0INT) knl_dispatch_entry(void)
{
	knl_dispatch_disabled = 1;    /* Dispatch disable */
	__disable();
	__svlcx(); /* save lower contex */
	knl_ctxtsk->tskctxb.ssp = __mfcr( PCXI );
	knl_ctxtsk->tskctxb.dispatcher = knl_dispatch_r;
	knl_ctxtsk = NULL;

	/* Don't consume CSA.So just Jump*/
	__asm("j l_dispatch0");
}
#if 0
EXPORT __trap(6) void knl_syscall_entry(void)
{
	UINT syscall_nr;
	__asm("mov %0,d15":"=d"(syscall_nr):);
	switch(syscall_nr)
	{
		case 0:
			__asm("j knl_dispatch_entry");
			break;
		case 1:
			__asm("j knl_force_dispatch_impl");
			break;
		default:
			break;
	}
}
#endif
#endif /* cfgUSE_FREERTOS_PORT */

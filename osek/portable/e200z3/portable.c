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
#include "portable.h"

//system stack malloc
LOCAL 	UB	knl_system_stack[cfgOS_SYSTEM_STACK_SIZE];

//save the old cpu status register and disable the interrupt
EXPORT asm imask_t disint(void)
{
nofralloc
   mfmsr   r3
   wrteei  0
   blr
}

//restore the cpu status register value <MSR> saved by disint
EXPORT asm void enaint(imask_t mask)
 {
 nofralloc
	mtmsr   r3;
	blr
 }

 //get cpu status register <MSR>
EXPORT asm imask_t knl_getPRIMASK ( void )
{
nofralloc
	mfmsr   r3
	blr		
}
#if (configTickSrc==configRTI)
void knl_clear_hw_timer_interrupt(void)
{
	PIT.RTI.TFLG.B.TIF=1;			// clear the interrupt flag
}
void TickTimer_SetFreqHz(int Freq)
{
	PIT.PITMCR.B.MDIS_RTI=0;/*turn on PIT just for RTI*/
	PIT.RTI.LDVAL.R=OSC_FREQUENCY*1000000/Freq-1;
	PIT.RTI.TCTRL.B.TIE=1;	/*enable interrupt*/
	PIT.RTI.TCTRL.B.TEN=1;/*turn on RTI*/
	INTC_InstallINTCInterruptHandler(ISREntry(SystemTick),305,1);       
	INTC.CPR.B.PRI = 0;/* Lower INTC's current priority */
}
#elif (configTickSrc==configDEC)
LOCAL void knl_systick_handler(void);
void TickTimer_SetFreqHz(int Freq)
{	
	int  decr=CPU_FREQUENCY*1000000/Freq;
	asm
	{
/**/
		li		r0, 0x0000	
		mthid0	r0
/*Set the gap time between tick and tick*/		
		lwz      r0,decr
		mtdec		r0
		mtdecar	r0			
/*Set TCR[DIE]=1,TCR[ARE]=1,that is to enable DEC interrupt and enable auto-reload*/
		lis		r0, 0x0440	
		mftcr     r3
		or        r0,r0,r3	
		mttcr		r0		
/*Set HID0[TBEN]=1,Time base enable*/			
		li		r0, 0x4000		
		mthid0	r0
	}
	asm
	{
	    lis     r0, knl_systick_handler@h
	    ori     r0, r0, knl_systick_handler@l
	    /* IVOR10 Decrementer interrupt (SPR 410) */
	    mtivor10 r0
	}		
}
#endif /* configTickSrc */


//mean start the SystemTick ISR timer.
EXPORT void knl_start_hw_timer( void )
{
	asm
	{
		/* IVOR8 System call interrupt (SPR 408) */
		lis     r0, knl_dispatch_entry@h
		ori     r0, r0, knl_dispatch_entry@l
		mtivor8 r0
	}
	TickTimer_SetFreqHz(1000);
}

#define  configUSE_FPU	0
/* Definitions to set the initial MSR of each task. */
#define portCRITICAL_INTERRUPT_ENABLE	( 1UL << 17UL )
#define portEXTERNAL_INTERRUPT_ENABLE	( 1UL << 15UL )
#define portMACHINE_CHECK_ENABLE		( 1UL << 12UL )

#if configUSE_FPU == 1
#define portAPU_PRESENT				( 1UL << 25UL )
#define portFCM_FPU_PRESENT			( 1UL << 13UL )
#else
#define portAPU_PRESENT				( 0UL )
#define portFCM_FPU_PRESENT			( 0UL )
#endif

#define portINITIAL_MSR		( portCRITICAL_INTERRUPT_ENABLE | portEXTERNAL_INTERRUPT_ENABLE | \
                              portMACHINE_CHECK_ENABLE | portAPU_PRESENT | portFCM_FPU_PRESENT )
extern const unsigned _SDA_BASE_;
extern const unsigned _SDA2_BASE_;
//when task need starting to run, prepare its context.
//as for ucos and freeRTOS,task start policy is asynchronous,
//so need to prepare its really running environment firstly
//and the start to dispatch it(just like resume to run).
//But for OSEK os, the much more real time consideration, treat 
//start to run and resume to run differently...
EXPORT void knl_setup_context( TCB *tcb )
{
	#if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF)
	tcb->tskctxb.ssp = tcb->isstack;
	#endif
    tcb->tskctxb.dispatcher = knl_activate_r;
}

//default SystemTick ISR handler,which also is an example for other ISR
//the system counter whose id is 0 will be processed.
EXPORT ISR(SystemTick)
{
	EnterISR();
	#if(cfgOS_TK_EXTEND == STD_ON)
	//really, the extended feature for OSEK is not advised to be used.
	knl_timer_handler();
	#endif
	(void)IncrementCounter(0);
	ExitISR();
}

//when task start to run
EXPORT void knl_activate_r(void)
{
	/* This is the most easiest Way to get Internal Resourse and
     * to make a task non-preemtable I think */
    knl_ctxtsk->priority = knl_ctxtsk->runpri;
	enaint(portINITIAL_MSR); // enable interrupt
    knl_ctxtsk->task();
}

//when task resume to run
EXPORT __asm void knl_dispatch_r(void)
{
nofralloc
	#if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
	lwz   r1, SP_OFFSET(r8);     /* Restore 'ssp' from TCB */	
	#endif
	lwz    r11,XTMODE(r1);
	lis    r12,knl_taskmode@h;
	stw    r11,knl_taskmode@l(r12);  /* restore taskmode */  
	  
	OS_RESTORE_R2_TO_R31();   /* all GPRs restored */
	OS_RESTORE_SPFRS();        /* all SPFRs restored */	
	/* restore R0 */
	lwz   r0,XR0(r1);
    addi  r1,r1, STACK_FRAME_SIZE
  	rfi
}

#pragma section RX ".__exception_handlers"
#pragma push /* Save the current state */
__declspec (section ".__exception_handlers") extern long EXCEPTION_HANDLERS;  
#pragma force_active on
#pragma function_align 16 /* We use 16 bytes alignment for Exception handlers */
__declspec(interrupt)
__declspec (section ".__exception_handlers")
LOCAL void l_dispatch0(void);

//knl_force_dispatch() will be called when the current running task terminate,
//then the next high ready task can start to run.
EXPORT __asm void knl_force_dispatch(void)
{
nofralloc
	wrteei  0;		/* Interrupt disable */
	#if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF) 
	lis		r1,knl_system_stack@h			
	ori     r1,r1,knl_system_stack@l
	addi	r1,r1,cfgOS_SYSTEM_STACK_SIZE	/* Set temporal stack */
	#endif
	/* as curtsk is no longer running,so no need to care about the context */
	li     r11,1
	lis    r12,knl_dispatch_disabled@h
	stw    r11,knl_dispatch_disabled@l(r12)  /* Dispatch disable */
	li	   r11,0
	lis	   r12,knl_ctxtsk@h
	stw    r11,knl_ctxtsk@l(r12)             /* ctxtsk = NULL */
	wrteei  1;		                         /* Interrupt enable */ 
	b	   l_dispatch0  	  
}

#if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
//load the system stack which is shared by tasks,ISRs and also the os dispatcher
//just before start the dispatcher.
EXPORT __asm void knl_start_dispatch(void)
{
    lis		r1,knl_system_stack@h			
	ori     r1,r1,knl_system_stack@l
	addi	r1,r1,cfgOS_SYSTEM_STACK_SIZE   /* Set system stack */
    b knl_force_dispatch
}
#endif

EXPORT __asm void knl_dispatch_entry(void)
{
nofralloc
	subi  r1,r1,STACK_FRAME_SIZE
	stw   r0,XR0(r1);
	stw   r2,XR2(r1);
	stw   r3,XR3(r1);
	OS_SAVE_SPFRS();        /* all SPFRs saved */
_ret_int_dispatch:
	li     r0,1
	lis    r3,knl_dispatch_disabled@h
	stw    r0,knl_dispatch_disabled@l(r3)  /* Dispatch disable */

	wrteei  1;		                        /* Interrupt enable */ 	 
	OS_SAVE_R4_TO_R31();   /* all GPRs saved */

	lis    r0,knl_taskmode@h;
	lwz    r0,knl_taskmode@l(r0);
	stw    r0,XTMODE(r1);    /* save taskmode */

	lis  r5,knl_ctxtsk@h;
	lwz  r5,knl_ctxtsk@l(r5);
			
	stw   r1, SP_OFFSET(r5);     /* Save 'ssp' to TCB */
	
	//tcb->tskctxb.dispatcher = knl_dispatch_r;
	lis    r11,knl_dispatch_r@h
	ori    r11,r11,knl_dispatch_r@l
	stw    r11,12(r5)
	   		
	li	   r11,0
	lis	   r12,knl_ctxtsk@h
	stw    r11,knl_ctxtsk@l(r12)             /* ctxtsk = NULL */
	b	   l_dispatch0  	  		    	
}
LOCAL __asm void l_dispatch0(void)
{
nofralloc
  	lis  r5,knl_schedtsk@h;    
  	ori  r5,r5,knl_schedtsk@l;  /* R5 = &schedtsk */
	
	#if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
	wrteei  0;		/* Interrupt disable */
	lwz   r8,0(r5)
  	cmpwi r8,0; 	/* Is there 'schedtsk'? */
  	bne	 l_dispatch2;
    //if(knl_schedtsk==(void *)0)
    //{   //only reload system stack when os idle.
        lis		r1,knl_system_stack@h			
		ori     r1,r1,knl_system_stack@l
		addi	r1,r1,cfgOS_SYSTEM_STACK_SIZE /* Set system stack */    	
    #endif
    
l_dispatch1:
	wrteei  0;		/* Interrupt disable */ 
	
	lwz   r8,0(r5)
  	cmpwi r8,0; 	/* Is there 'schedtsk'? */
  	bne	 l_dispatch2;
	
  	wrteei  1;		/* Interrupt enable */ 
  	nop
  	nop
  	nop
  	b	 l_dispatch1 
	//}
l_dispatch2:                   /* Switch to 'schedtsk' */
	lis  r6,knl_ctxtsk@h;
	stw  r8,knl_ctxtsk@l(r6);  /* ctxtsk = schedtsk */
	
	#if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF)
	lwz   r1, SP_OFFSET(r8);     /* Restore 'ssp' from TCB */	
	#endif
	
	li     r11,0
	lis    r12,knl_dispatch_disabled@h
	stw    r11,knl_dispatch_disabled@l(r12)  /* Dispatch enable */
	
	//knl_ctxtsk->tskctxb.dispatcher();
	lwz   r12, 12(r8);     /* Restore 'dispatcher' from TCB */
	mtctr    r12
	se_bctrl	
}

#if (configTickSrc==configDEC)
LOCAL __asm void knl_systick_handler(void)
{
nofralloc
prolog:
    stwu    r1, -0x50 (r1)    /* Create stack frame */
    stw r0,  0x24 (r1)        /* Store r0 working register  */

    /* Save SRR0 and SRR1 */
    mfsrr1  r0                /* Store SRR1 (must be done before enabling EE) */
    stw     r0,  0x10 (r1)
    mfsrr0  r0                /* Store SRR0 (must be done before enabling EE) */
    stw     r0,  0x0C (r1)

    /* Clear request to processor; r3 contains the address of the ISR */
    stw     r3,  0x28 (r1)    /* Store r3 */
    
	lis    r3, 0x0800;        // load r3 with TSR[DIS] bit (0x08000000)
    mtspr  TSR,r3;            // clear TSR[DIS] bit
    
    lis     r3,ISREntry(SystemTick)@h;       /* Load INTC_IACKR, which clears request to processor   */
    ori     r3,r3,ISREntry(SystemTick)@l;      /* Read ISR address from ISR Vector Table using pointer */
    /* Enable processor recognition of interrupts */
    wrteei  1                   /* Set MSR[EE]=1  */

    /* Save rest of context required by EABI */
    stw     r12, 0x4C (r1)      /* Store r12 */
    stw     r11, 0x48 (r1)      /* Store r11 */
    stw     r10, 0x44 (r1)      /* Store r10 */
    stw     r9,  0x40 (r1)      /* Store r9 */
    stw     r8,  0x3C (r1)      /* Store r8 */
    stw     r7,  0x38 (r1)      /* Store r7 */
    stw     r6,  0x34 (r1)      /* Store r6 */
    stw     r5,  0x30 (r1)      /* Store r5 */
    stw     r4,  0x2C (r1)      /* Store r4 */
    mfcr    r0                  /* Store CR */
    stw     r0,  0x20 (r1)
    mfxer   r0                  /* Store XER */
    stw     r0,  0x1C (r1)
    mfctr   r0                  /* Store CTR */
    stw     r0,  0x18 (r1)
    mflr    r0                  /* Store LR */
    stw     r0,  0x14 (r1)

    /* Branch to ISR handler address from SW vector table */
    mtlr    r3                  /* Store ISR address to LR to use for branching later */
    blrl                        /* Branch to ISR, but return here */

epilog:
    /* Restore context required by EABI (except working registers) */
    lwz     r0,  0x14 (r1)      /* Restore LR */
    mtlr    r0
    lwz     r0,  0x18 (r1)      /* Restore CTR */
    mtctr   r0
    lwz     r0,  0x1C (r1)      /* Restore XER */
    mtxer   r0
    lwz     r0,  0x20 (r1)      /* Restore CR */
    mtcrf   0xff, r0
    lwz     r5,  0x30 (r1)      /* Restore r5 */
    lwz     r6,  0x34 (r1)      /* Restore r6 */
    lwz     r7,  0x38 (r1)      /* Restore r7 */
    lwz     r8,  0x3C (r1)      /* Restore r8 */
    lwz     r9,  0x40 (r1)      /* Restore r9 */
    lwz     r10, 0x44 (r1)      /* Restore r10 */
    lwz     r11, 0x48 (r1)      /* Restore r11 */
    lwz     r12, 0x4C (r1)      /* Restore r12 */

    /* Disable processor recognition of interrupts */
    wrteei  0

    /* Restore Working Registers */
    lwz     r3,  0x28 (r1)      /* Restore r3 */
    lwz     r4,  0x2C (r1)      /* Restore r4 */

    /* Retrieve SRR0 and SRR1 */
    lwz     r0,  0x0C (r1)      /* Restore SRR0 */
    mtsrr0  r0
    lwz     r0,  0x10 (r1)      /* Restore SRR1 */
    mtsrr1  r0

    /* Restore Other Working Registers */
    lwz     r0,  0x24 (r1)      /* Restore r0 */

    /* Restore space on stack */
    addi    r1, r1, 0x50

    /* End of Interrupt */
    rfi
}
#endif  /* configTickSrc */

#pragma force_active off
#pragma pop
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
#include "derivative.h"      /* derivative-specific definitions */
#include "knl_timer.h"

LOCAL 	UB	knl_system_stack[cfgOS_SYSTEM_STACK_SIZE];

#define tk_ppage $30  //for MX9S12DP512
//#define tk_ppage $15  //for MX9S12XEP100
/*
 *    Function Name : disint
 *    Description   : Disable external interrupt,CPSR interrupt flag is in  disabled status.
 */
EXPORT imask_t disint()
{
    asm psha;
    asm tpa;
    asm tab; 
    asm sei;
    asm pula;
}

/*
 *    Function Name : enaint
 *    Description   : Enable external interrupt (restore to original state),
 *                    Updates CPSR interrupt disabled flag with the intsts interrupt flag.
 */
EXPORT void enaint(imask_t mask)
{
    (void)mask;
    asm psha;  
    asm tba;
    asm tap;
    asm pula;
}

EXPORT imask_t knl_getPRIMASK ( void )
{
    asm psha; /* sava A */
	asm tpa;
    asm tab;
    asm pula;
}
EXPORT void knl_start_hw_timer( void )
{
    CRGINT_RTIE=1;       //使能实时中断
    RTICTL = 0x70;       //设置实时中断的时间间隔为4.096ms
    //中断周期=1/16 x 10E-6 x （0+1）x 2E（7+9）=0.004096s=4.096ms 
}
EXPORT void knl_activate_r(void)
{
    /* This is the most easiest Way to get Internal Resourse and
     * to make a task non-preemtable I think */
    knl_ctxtsk->priority = knl_ctxtsk->runpri;
    __asm CLI; // enable interrupt
    knl_ctxtsk->task();
}
EXPORT void knl_dispatch_r(void)
{
    #if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
	/* Context restore */
	asm   ldx  knl_ctxtsk;
	asm   lds  SP_OFFSET,x;       /* Restore 'ssp' from TCB */
	#endif
    asm   pula;
    asm   staa	tk_ppage;	      /* restore PPAGE */
    asm   puld;
    asm   std   knl_taskmode  /* restore knl_taskmode */
    asm   rti;   
}
EXPORT void knl_setup_context( TCB *tcb )
{
    #if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF)
    tcb->tskctxb.ssp = tcb->isstack;
    #endif
    tcb->tskctxb.dispatcher = knl_activate_r;
}
#if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
//load the system stack which is shared by tasks,ISRs and also the os dispatcher
//just before start the dispatcher.
EXPORT void knl_start_dispatch(void)
{
    asm  lds #knl_system_stack:cfgOS_SYSTEM_STACK_SIZE   /* Set system stack */
    asm  jmp knl_force_dispatch
}
#endif

#pragma CODE_SEG __NEAR_SEG NON_BANKED
static void l_dispatch0(void)
{
l_dispatch1:
    asm sei;   //disable interrupt
    #if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
    if(knl_schedtsk==(void *)0)
    {   //only reload system stack when os idle.
        asm  lds #knl_system_stack:cfgOS_SYSTEM_STACK_SIZE   /* Set system stack */
    }
    #endif
    if(knl_schedtsk==(void *)0)
    {
        asm cli;  //enable interrupt
        asm nop;
        asm nop;
        asm nop;
        asm nop;
        goto l_dispatch1;
    }
l_dispatch2:
    knl_ctxtsk=knl_schedtsk;
	knl_dispatch_disabled=0;    /* Dispatch enable */
	
	/* Context restore */
	asm   ldx  knl_ctxtsk;
	#if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF) //as task share the system stack 
	asm   lds  SP_OFFSET,x;       /* Restore 'ssp' from TCB */
	#endif
    //knl_ctxtsk->tskctxb.dispatcher();
    asm   jmp  [6,x];
}

//knl_force_dispatch() will be called when the current running task terminate,
//then the next high ready task can start to run.
void knl_force_dispatch(void)
{
    #if(cfgOS_SHARE_SYSTEM_STACK == STD_OFF)  //as task share the system stack 
    asm  lds #knl_system_stack:cfgOS_SYSTEM_STACK_SIZE   /* Set system stack */
    #endif
    knl_dispatch_disabled=1;    /* Dispatch disable */ 
    knl_ctxtsk=(void *)0;
    asm sei; 
    asm jmp l_dispatch0;
}

interrupt 4 void knl_dispatch_entry(void)
{
    knl_dispatch_disabled=1;    /* Dispatch disable */ 
    asm   ldd   knl_taskmode  
    asm   pshd;                 /* save knl_taskmode */
    asm   ldaa	tk_ppage		        
	asm   psha                  /* save ppage */
	asm   ldx  knl_ctxtsk;
	asm   sts  SP_OFFSET,x;            /* save 'ssp' to TCB */
	knl_ctxtsk->tskctxb.dispatcher = knl_dispatch_r;
	knl_ctxtsk=(void*)0;
	asm jmp l_dispatch0;  	    	
}

ISR(SystemTick,7)
{ 
    CRGFLG &=0xEF;			// clear the interrupt flag 
    EnterISR(); 
#if(cfgOS_TK_EXTEND == STD_ON)    
	knl_timer_handler();
#endif	
	(void)IncrementCounter(0);
	ExitISR();	
}
#pragma CODE_SEG DEFAULT
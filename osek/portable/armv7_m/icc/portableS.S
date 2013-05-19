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
#include "portmacro.h"
#include "Compiler.h"

    EXTERN knl_ctxtsk, knl_schedtsk, knl_taskindp
    EXTERN knl_taskmode, knl_tmp_stack,knl_dispatch_disabled
    SECTION .text:CODE
    THUMB
    PUBLIC enaint
//EXPORT void enaint( imask_t intsts );    
enaint:
    mrs     r1, primask
    msr     primask, r0
    mov     r0, r1
    bx      lr

    SECTION .text:CODE
    THUMB
    PUBLIC disint
//EXPORT imask_t disint( void );    
disint:
    mrs     r0, primask
    ldr     r1, =TS_PMK_D
    msr     primask, r1
    bx      lr

    SECTION .text:CODE
    THUMB
    PUBLIC  knl_force_dispatch_impl
knl_force_dispatch_impl:
    /* Interrupt is disabled,during SVC mode */
    ldr     sp, =(knl_tmp_stack + cfgTMP_STACK_SZ)  /* Set temporal stack */

    ldr     r12, =knl_dispatch_disabled
    ldr     r0, =1
    str     r0, [r12]                            /* Dispatch disable */

    ldr     r4, =knl_ctxtsk                /* R4 = &ctxtsk */
    ldr     r0, =0
    str     r0, [r4]                             /* ctxtsk = NULL */
    cpsie   i                                    /* Interrupt enable */
    b       l_dispatch0

    PUBLIC knl_dispatch_entry, knl_dispatch_ret_int
knl_dispatch_entry:
knl_dispatch_ret_int:
    /* Interrupt is disabled,during SVC mode */
    ldr     r12, =knl_dispatch_disabled
    ldr     r0, =1
    str     r0, [r12]                            /* Dispatch disable */
    cpsie   i                                    /* Interrupt enable */
    ldr     r12, =knl_taskmode
    ldr     r0, [r12]
    push    {r0}
    push    {r4-r11}
    ldr     r4, =knl_ctxtsk                /* R4 = &ctxtsk */
    ldr     r0, =0
    ldr     r8, [r4]                             /* R8 = ctxtsk */
    str     sp, [r8, #SP_OFFSET]    /* Save 'ssp' to TCB */
    str     r0, [r4]                             /* ctxtsk = NULL */

l_dispatch0:
    /* During interrupt enable */
    ldr     r5, =knl_schedtsk              /* R5 = &schedtsk */

l_dispatch1:                                     /* Judge if goto 'schedtsk'or'low_pow' */
    cpsid   i
    ldr     r8, [r5]                             /* R8 = schedtsk */
    cmp     r8, #0                               /* Is there 'schedtsk'? */
    bne     l_dispatch2
    /* wait untill a task is ready again. */
    cpsie   i                                    /* Interrupt enable */
    nop
    nop
    nop
    b       l_dispatch1

l_dispatch2:                                     /* Switch to 'schedtsk' */
    /* During interrupt disable */
    str     r8, [r4]                             /* ctxtsk = schedtsk */
    ldr     sp, [r8, #SP_OFFSET]    /* Restore 'ssp' from TCB */

    ldr     r12, =knl_dispatch_disabled
    ldr     r0, =0
    str     r0, [r12]                            /* Dispatch enable */
    /* start to restore task's context */
    pop     {r4-r11}
    ldr     r12, =knl_taskmode
    pop     {r0}
    str     r0, [r12]
    cpsie   i                                    /* just before schedule to next task */
    bx      lr                                   /* lr is EXC_RETURN */

#if (cfgCORTEX_M3_ISR == ISR_IN_ASSEMBLY)
    PUBLIC EnterISR
EnterISR:    
    ldr     r1, =knl_taskindp              /* Enter task independent part */
    ldr     r2, [r1]
    add     r3, r2, #1  /* knl_taskindp++ */
    str     r3, [r1]
    push    {r1, r2}           /* Here I say wonderful Idea, do you know the reason? */
    cpsie   i     /* Enable Interrupr */
    bx      lr

    PUBLIC ExitISR
ExitISR:
    pop     {r1,r2}          /* here same as knl_taskindp--, do you know why? */
    str     r2, [r1]                             /* Leave task independent part */
    pop     {lr}
    cpsid   i

    ldr     r0, =knl_taskindp              /* Is it a nesting interrupt? */
    ldr     r0, [r0]
    cmp     r0, #0
    
    bne     l_nodispatch

    ldr     r0, =knl_dispatch_disabled    /* Is it during dispatch disable? */
    ldr     r0, [r0]
    cmp     r0, #0
    bne     l_nodispatch

    ldr     r0, =knl_ctxtsk                /* Is dispatch required? */
    ldr     r1, =knl_schedtsk
    ldr     r0, [r0]
    ldr     r1, [r1]
    cmp     r0, r1
    bne     knl_dispatch_ret_int                 /* To dispatch processing */

l_nodispatch:
    cpsie   i
    bx      lr

    PUBLIC ISR(SystemTick)
    EXTERN IncrementCounter
    EXTERN knl_timer_handler
/* This is an ISR example for SystemTick.
 * The Entry Code for ISR must be Assemble.
 * The Way to change it to C code is hasn't been found.
 */    
                            //EXPORT ISR(SystemTick)
ISR(SystemTick):
                            //{
    push {lr}
    bl EnterISR             //EnterISR();
    bl knl_timer_handler    //knl_timer_handler();
    mov r0,#0
    bl IncrementCounter     //(void)IncrementCounter(0);
    b  ExitISR              //ExitISR();
                            //} 
#endif  /* ISR_IN_ASSEMBLY */                            
    END


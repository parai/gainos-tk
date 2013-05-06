
#include "vPortMacro.h"

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
    ALIGNROM 2
    PUBLIC  knl_force_dispatch
knl_force_dispatch:
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

    ALIGNROM 2
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

    /* Because there is no task that should be executed, move to the power-saving mode */
    nop
    nop
    nop
    cpsie   i                                    /* Interrupt enable */
    b       l_dispatch1

l_dispatch2:                                     /* Switch to 'schedtsk' */
    /* During interrupt disable */
    str     r8, [r4]                             /* ctxtsk = schedtsk */
    ldr     sp, [r8, #SP_OFFSET]    /* Restore 'ssp' from TCB */

    ldr     r12, =knl_dispatch_disabled
    ldr     r0, =0
    str     r0, [r12]                            /* Dispatch enable */
    mrs     r12,psr
    ldr     r0,=0x1FF
    and     r12,r12,r0
    cmp     r12,#0
    beq     knl_dsp_no_exception
    bgt     knl_dsp_in_exception

knl_dsp_no_exception:
    pop     {r4-r11}
    ldr     r12, =knl_taskmode
    pop     {r0}
    str     r0, [r12]
    ldr     r0, [sp, #24]                        /* load stack's pc to r0 */
    orr     r0, r0, #1
    str     r0, [sp, #24]
    ldr     r0, [sp, #28]                        /* load stack's psr to r0 */
    mov     r1, #(0x01<<9)                       /* test psr bit[9]==1? */
    tst     r0, r1
    beq     knl_dsp_no_8words_stack
    pop     {r0-r3}                              /* yes, exception stack is 9 bytes*/
    pop     {r12}
    pop     {lr}
    add     sp, sp, #12
    cpsie   i                                    /* just before schedule to next task */
    ldr     pc, [sp, #-12]
knl_dsp_no_8words_stack:                         /* no, normal */
    pop     {r0-r3}
    pop     {r12}
    pop     {lr}
    add     sp, sp, #8
    cpsie   i                                    /* just before schedule to next task */
    ldr     pc, [sp, #-8]

knl_dsp_in_exception:
    pop     {r4-r11}
    ldr     r12, =knl_taskmode
    pop     {r0}
    str     r0, [r12]
    cpsie   i                                    /* just before schedule to next task */
    bx      lr                                   /* lr is EXC_RETURN */

    ALIGNROM 2
    PUBLIC knl_enter_isr
knl_enter_isr:    
    ldr     r1, =knl_taskindp              /* Enter task independent part */
    ldr     r2, [r1]
    add     r3, r2, #1
    str     r3, [r1]
    push    {r1, r2}
    bx      lr
    
    ALIGNROM 2
    PUBLIC knl_exit_isr
knl_exit_isr:
    pop     {r1,r2}
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
    
    END


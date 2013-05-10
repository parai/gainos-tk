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
#ifndef  VPORT_H_H
#define  VPORT_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h"
#include "vPortMacro.h"
#include "knl_task.h"
#if  defined(CHIP_STM32F1)
#include "stm32f10x.h"
#elif defined(CHIP_AT91SAM3S)
#include "SAM3S.h"
#endif
/* ============================ MACROs ============================================= */
/*
 * Size of system stack area destroyed by 'make_dormant()'
 * In other words, the size of area required to write by 'setup_context().'
 */
#define DORMANT_STACK_SIZE	( sizeof(VW) * 9 )	/* To 'taskmode' position */

/* ============================ TYPEs ============================================= */
/*
 * System stack configuration at task startup
 */
typedef struct {
        VW      r4;                              /* R4        */
        VW      r5;                              /* R5        */
        VW      r6;                              /* R6        */
        VW      r7;                              /* R7        */
        VW      r8;                              /* R8        */
        VW      r9;                              /* R9        */
        VW      r10;                             /* R10       */
        VW      r11;                             /* R11       */
        UW      taskmode;                        /* used for saving knl_taskmode */
        VW      r0;                              /* R0        */
        VW      r1;                              /* R1        */
        VW      r2;                              /* R2        */
        VW      r3;                              /* R3        */
        UW      r12;                             /* R12       */
        VP      lr;                              /* LR        */
        VP      pc;                              /* PC        */
        VW      xpsr;                            /* PSR       */
} SStackFrame;

/* ============================ FUNCTIONs ========================================= */
/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
#define knl_force_dispatch()  {__asm("cpsie   i");__asm("svc 0");}

/*
 * Start task dispatcher
 */
#define knl_dispatch() { SCB->ICSR = SCB_ICSR_PENDSVSET_Msk; }

IMPORT imask_t disint( void );
IMPORT void enaint( imask_t intsts );
IMPORT void knl_start_hw_timer( void );
/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
IMPORT void knl_setup_context( TCB *tcb );

#endif/* VPORT_H_H */
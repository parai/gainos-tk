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
/* ============================ MACROs ============================================= */
/*
 * Size of system stack area destroyed by 'make_dormant()'
 * In other words, the size of area required to write by 'setup_context().'
 */
#define DORMANT_STACK_SIZE	( sizeof(VW) * 3 )	/* To 'PC' position */

#define SP_OFFSET 4 /* sizeof(QUEUE) */
/* ============================ TYPEs ============================================= */
/*
 * System stack configuration at task startup
 */
typedef struct {
	VH MDH;
	VH MDL;
	VH R[16];
	VH IP;
	VH CSP;
	VH PSW;
} SStackFrame;

/* ============================ FUNCTIONs ========================================= */
/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
IMPORT void knl_force_dispatch(void); 
/*
 * Start task dispatcher
 */
#define knl_dispatch() {__asm("TRAP #1");}

/*
 * Start task dispatcher during ISR
 */
#define knl_isr_dispatch() {__asm("TRAP #1");}

IMPORT imask_t disint( void );
IMPORT void enaint( imask_t intsts );
IMPORT void knl_start_hw_timer( void );
/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
IMPORT void knl_setup_context( TCB *tcb );

#define vPortSaveContext()                      \
    __asm("push    MDH ");                      \
    __asm("push    MDL ");                      \
    __asm("push    r0 ");                       \
    __asm("push    r1 ");                       \
    __asm("push    r2 ");                       \
    __asm("push    r3 ");                       \
    __asm("push    r4 ");                       \
    __asm("push    r5 ");                       \
    __asm("push    r6 ");                       \
    __asm("push    r7 ");                       \
    __asm("push    r8 ");                       \
    __asm("push    r9 ");                       \
    __asm("push    r10 ");                      \
    __asm("push    r11 ");                      \
    __asm("push    r12 ");                      \
    __asm("push    r13 ");                      \
    __asm("push    r14 ");						\
    __asm("push    r15 ");

#define vPortRestoreContext()                   \
	__asm("pop     r15 ");                      \
    __asm("pop     r14 ");                      \
    __asm("pop     r13 ");                      \
    __asm("pop     r12 ");                      \
    __asm("pop     r11 ");                      \
    __asm("pop     r10 ");                      \
    __asm("pop     r9 ");                       \
    __asm("pop     r8 ");                       \
    __asm("pop     r7 ");                       \
    __asm("pop     r6 ");                       \
    __asm("pop     r5 ");                       \
    __asm("pop     r4 ");                       \
    __asm("pop     r3 ");                       \
    __asm("pop     r2 ");                       \
    __asm("pop     r1 ");                       \
    __asm("pop     r0 ");                       \
    __asm("pop     MDL ");                      \
    __asm("pop     MDH ");                      \

#endif/* VPORT_H_H */

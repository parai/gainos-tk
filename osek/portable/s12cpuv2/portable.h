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
#include "portmacro.h"
#include "knl_task.h"
/* ============================ MACROs ============================================= */
#define SP_OFFSET 4 /* sizeof(QUEUE) */

/* ============================ TYPEs ============================================= */
/*
 * System stack configuration at task startup
 */
typedef struct {
    VB ppage;
    VH taskmode;
    VB ccr;
    VB b;   /* exinfL */
    VB a;   /* exinfH */
    VH x;
    VH y;
    VH pc;
    VB rtn[3];  /* dummy return address with ppage */
    VH stacd;
} SStackFrame;

/* ============================ FUNCTIONs ========================================= */
IMPORT void knl_start_dispatch(void);
/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
#pragma CODE_SEG __NEAR_SEG NON_BANKED
IMPORT void knl_force_dispatch(void); 
#pragma CODE_SEG DEFAULT
/*
 * Start task dispatcher
 */
#define knl_dispatch() {asm swi;}

/*
 * Start task dispatcher during ISR
 * You should define "CPU9S12X" for CPU with IPL in CCR in you compiler pre-process
 */
#if !defined(CPU9S12X)  //for CPU without IPL in CCR
#define knl_isr_dispatch() {asm swi;}
#else  //for CPU with IPL in CCR
//lower IPL firstly and then call dispatch
#define knl_isr_dispatch() {asm psha;asm ldaa #0;asm tfr a,ccrh;asm pula;asm swi;}
#endif

IMPORT imask_t disint( void );
IMPORT void enaint( imask_t intsts );
IMPORT void knl_start_hw_timer( void );
/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
IMPORT void knl_setup_context( TCB *tcb );

IMPORT PRI knl_get_ipl(void);
IMPORT void knl_set_ipl(PRI ipl);
#endif/* VPORT_H_H */

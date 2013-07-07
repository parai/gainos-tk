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
/* CSA Manipulation. */
#define CSA_TO_ADDRESS( pCSA )			( ( unsigned long * )( ( ( ( pCSA ) & 0x000F0000 ) << 12 ) | ( ( ( pCSA ) & 0x0000FFFF ) << 6 ) ) )
#define ADDRESS_TO_CSA( pAddress )		( ( unsigned long )( ( ( ( (unsigned long)( pAddress ) ) & 0xF0000000 ) >> 12 ) | ( ( ( unsigned long )( pAddress ) & 0x003FFFC0 ) >> 6 ) ) )

/* ============================ TYPEs ============================================= */
/*
 * System stack configuration at task startup
 */
typedef struct {
	VW	pcxi;
	VW	psw;
	VW	SP;	//A[10] -> Stack Pointer
	VW	RA; //A[11] -> Return Address
	VW	D8;  VW	D9;  VW	D10; VW	D11;
	VW	A12; VW A13; VW A14; VW A15;
	VW	D12; VW D13; VW D14; VW D15;
}UpperCSA;

typedef struct {
	VW	pcxi;
	VW	RA; //A[11] -> Return Address
	VW  A2;  VW A3;
	VW	D0;  VW	D1;  VW	D2; VW	D3;
	VW	A4;  VW A5;  VW A6; VW A7;
	VW	D4;  VW D5;  VW D6; VW D7;
}LowerCSA;

/* ============================ FUNCTIONs ========================================= */
/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
IMPORT void knl_force_dispatch(void);
/*
 * Start task dispatcher, pend a contex swtich ISR
 */
#define knl_dispatch() { CPU_SRC0.B.SETR = 1; }

/*
 * Start task dispatcher during ISR, pend a contex swtich ISR
 */
#define knl_isr_dispatch() { CPU_SRC0.B.SETR = 1; }

IMPORT imask_t disint( void );
IMPORT void enaint( imask_t intsts );
IMPORT void knl_start_hw_timer( void );
IMPORT void knl_setup_context( TCB *tcb );
IMPORT void knl_reclaim_csa( unsigned long pxHeadCSA );
IMPORT void knl_set_ipl(UINT ipl);
IMPORT PRI knl_get_ipl(void);
#endif/* VPORT_H_H */

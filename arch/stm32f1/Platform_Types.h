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
#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_

#define CPU_TYPE            CPU_TYPE_32
#define CPU_ENDIAN          CPU_BIG_ENDIAN 

/* This is a Cpu ISR Mask type <xPSR>*/
typedef unsigned long               imask_t; 
/*
 * Task context block
 */
typedef struct {
	void* ssp;		/* System stack pointer */
    void (*dispatcher)(void);
} CTXB;


#endif /* _PLATFORM_TYPES_H_ */


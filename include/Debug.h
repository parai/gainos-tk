/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.                                           
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

/* Modified && Ported by parai to integrated with GaInOS,which is an open source 
 * AUTOSAR OS based on uTenux(tkernel). 
 * And re-construct a GUI tool named gainos-studio,which is based on python and Qt4.8,
 * for the whole Com Architecture of ArCore.
 * URL:      https://github.com/parai
 * Email:    parai@foxmail.com
 * Name:     parai(Wang Fan)
 * from Date:2013-04-08 to $Date: 2013-04-13 13:51:22 $
 * $Revision: 1.1 $
 */
#ifndef DEBUG_H__H_H
#define DEBUG_H__H_H

/**
 *
 * NOTE!!!!
 * Do not use this in a header file. Should be used in the *.c file like this.
 *
 * #define USE_DEBUG
 * #include "ardebug.h"
 *
 * Macro's for debugging and tracing
 *
 * Define USE_LDEBUG_PRINTF and DBG_LEVEL either globally( e.g. a makefile )
 * or in a specific file.  The DBG_LEVEL macro controls the amount
 * of detail you want in the debug printout.
 * There are 3 levels:
 * DEBUG_LOW    - Used mainly by drivers to get very detailed
 * DEBUG_MEDIUM - Medium detail
 * DEBUG_HIGH   - General init
 *
 * Example:
 * #define DEBUG_LVL	DEBUG_HIGH
 * DEBUG_PRINT0(DEBUG_HIGH,"Starting GPT");
 *
 * TRACE
 *   TODO:
 *
 */

#include <stdio.h>

#define DEBUG_LOW		1
#define DEBUG_MEDIUM	2
#define DEBUG_HIGH		3
#define DEBUG_NONE		4

#ifndef DEBUG_LVL
#define DEBUG_LVL		2
#endif

#define CH_ISR		0
#define CH_PROC		1

#ifdef  USE_DEBUG
#define DEBUG_PRINT0(_level,arg0)    \
	do { \
		if(_level>=DEBUG_LVL) { \
			printf(arg0); \
		}; \
	} while(0);
#define DEBUG_PRINT1(_level,format,arg1)    \
	do { \
		if(_level>=DEBUG_LVL) { \
			printf (format,arg1); \
		}; \
	} while(0);	
#define DEBUG_PRINT2(_level,format,arg1,arg2)    \
	do { \
		if(_level>=DEBUG_LVL) { \
			printf (format,arg1,arg2); \
		}; \
	} while(0);
#define DEBUG_PRINT3(_level,format,arg1,arg2,arg3)    \
	do { \
		if(_level>=DEBUG_LVL) { \
			printf (format,arg1,arg2,args3); \
		}; \
	} while(0);
#define DEBUG_PRINT4(_level,format,arg1,arg2,arg3,arg4)    \
	do { \
		if(_level>=DEBUG_LVL) { \
			printf (format,arg1,arg2,args3,arg4); \
		}; \
	} while(0);
#define DEBUG_PRINT5(_level,format,arg1,arg2,arg3,arg4,arg5)    \
	do { \
		if(_level>=DEBUG_LVL) { \
			printf (format,arg1,arg2,args3,arg4,arg5); \
		}; \
	} while(0);	

#else  /* USE_DEBUG */     
#define DEBUG_PRINT0(_level,arg0)
#define DEBUG_PRINT1(_level,format,arg1)
#define DEBUG_PRINT2(_level,format,arg1,arg2)
#define DEBUG_PRINT3(_level,format,arg1,arg2,arg3)
#define DEBUG_PRINT4(_level,format,arg1,arg2,arg3,arg4)
#define DEBUG_PRINT5(_level,format,arg1,arg2,arg3,arg4,arg5)
#endif /* USE_DEBUG */ 


#endif /*DEBUG_H__H_H*/

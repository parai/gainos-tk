/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_
/* =============================== MACROS FOR CPU =============================== */
#define CPU_TYPE_16    		16
#define CPU_TYPE_32			32
#define CPU_TYPE_64			64

#define CPU_BIG_ENDIAN     0
#define CPU_LITTLE_ENDIAN  1

/* ============================ INCLUDEs ========================================== */
#include "Platform_Types.h"
#include "Compiler.h"

/* ============================ MACROs ============================================ */
#define STD_NULL ((void *) 0)
#define STD_TRUE  (1)
#define STD_FALSE (0)

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/** make compare number... #if version > 10203  ( 1.2.3 ) */
#define STD_GET_VERSION (_major,_minor,_patch) (_major * 10000 + _minor * 100 + _patch)

/** Create Std_VersionInfoType */
#define STD_GET_VERSION_INFO(_vi,_module) \
	if(_vi != STD_NULL) {\
		((_vi)->vendorID =  _module ## _VENDOR_ID);\
		((_vi)->moduleID = _module ## _MODULE_ID);\
		((_vi)->sw_major_version = _module ## _SW_MAJOR_VERSION);\
		((_vi)->sw_minor_version =  _module ## _SW_MINOR_VERSION);\
		((_vi)->sw_patch_version =  _module ## _SW_PATCH_VERSION);\
		((_vi)->ar_major_version =  _module ## _AR_MAJOR_VERSION);\
		((_vi)->ar_minor_version =  _module ## _AR_MINOR_VERSION);\
		((_vi)->ar_patch_version =  _module ## _AR_PATCH_VERSION);\
	}

#ifndef MIN
#define MIN(_x,_y) (((_x) < (_y)) ? (_x) : (_y))
#endif
#ifndef MAX
#define MAX(_x,_y) (((_x) > (_y)) ? (_x) : (_y))
#endif

/* Values for StatusType */
#define E_OK            (0u)
#define E_NOT_OK        (1u)  

#if(CPU_TYPE == CPU_TYPE_16)
#define UINT_MAX 0xFFFFu
#elif(CPU_TYPE == CPU_TYPE_32)
#define UINT_MAX 0xFFFFFFFFu
#endif

/* ============================ TYPEs ============================================= */
typedef unsigned int        boolean;
typedef signed char         sint8;        
typedef unsigned char       uint8;
typedef char				char_t;
typedef signed short        sint16;       
typedef unsigned short      uint16;       
typedef signed long         sint32;       
typedef unsigned long       uint32;
typedef unsigned long long  uint64; /* Yeah, This type may not by supported by 16 bit cpu */
typedef unsigned int        uint8_least;  
typedef unsigned int        uint16_least; 
typedef unsigned long       uint32_least; 
typedef signed int          sint8_least;  
typedef signed int          sint16_least; 
typedef signed long         sint32_least; 
typedef float               float32; 
typedef double              float64;            

/* types for tkernel */
typedef signed char	    B;	    /* Signed 8 bit integer */
typedef signed short	H;	    /* Signed 16 bit integer */
typedef signed long	    W;	    /* Signed 32 bit integer */
typedef unsigned char	UB;	    /* Unsigned 8 bit integer */
typedef unsigned short  UH;	    /* Unsigned 16 bit integer */
typedef unsigned long	UW;	    /* Unsigned 32 bit integer */
typedef signed int          INT;
typedef unsigned int        UINT;
typedef UINT  ID;
typedef UINT		        BOOL;
typedef void*               VP;
typedef uint32  ATR;
typedef INT		PRI;		/* Priority */

typedef void (*FP)(void);

typedef signed char	    VB;	    /* Nonuniform type 8 bit data */
typedef signed short	VH;	    /* Nonuniform type 16 bit data */
typedef signed long  	VW;	    /* Nonuniform type 32 bit data */

typedef struct {
	// TODO: not done!!
	uint16 vendorID;
	uint16 moduleID;
	uint8  instanceID;

	uint8 sw_major_version;    /**< Vendor numbers */
	uint8 sw_minor_version;    /**< Vendor numbers */
	uint8 sw_patch_version;    /**< Vendor numbers */

	uint8 ar_major_version;    /**< Autosar spec. numbers */
	uint8 ar_minor_version;    /**< Autosar spec. numbers */
	uint8 ar_patch_version;    /**< Autosar spec. numbers */
} Std_VersionInfoType;

typedef uint8 Std_ReturnType;



#endif /* _STD_TYPES_H_ */
 

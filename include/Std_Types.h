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

#define STD_ON   1
#define STD_OFF  0

#ifndef NULL
#define NULL ((void*)0)
#endif

#define NULL_FP   ((FP)0)

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

/* Values for Std_ReturnType */
#define E_OK            (Std_ReturnType)0
#define E_NOT_OK        (Std_ReturnType)1  

#define E_NO_DTC_AVAILABLE		(Std_ReturnType)2
#define E_SESSION_NOT_ALLOWED	(Std_ReturnType)4
#define E_PROTOCOL_NOT_ALLOWED	(Std_ReturnType)5
#define E_REQUEST_NOT_ACCEPTED	(Std_ReturnType)8
#define E_REQUEST_ENV_NOK		(Std_ReturnType)9
#define E_PENDING				(Std_ReturnType)10
#define E_COMPARE_KEY_FAILED	(Std_ReturnType)11
#define E_FORCE_RCRRP			(Std_ReturnType)12


#if(CPU_TYPE == CPU_TYPE_16)
#define UINT_MAX 0xFFFFu
#elif(CPU_TYPE == CPU_TYPE_32)
#define UINT_MAX 0xFFFFFFFFu
#endif

#define AR_ASSERT(_true)    \
{                           \
    if(!(_true))            \
    {                       \
        for(;;);            \
    }                       \
}

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

typedef unsigned long long LSYSTIM; /*32 bits for 16 bit cpu and 64 bits for 32 bit cpu */

typedef void (*FP)(void);
typedef void (*CBACK)(VP arg);

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
 

/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
 * 
 *  Copyright (C) 2013 by Fan Wang(parai), China
 * 
 * The above copyright holders grant permission gratis to use,
 * duplicate, modify, or redistribute (hereafter called use) this
 * software (including the one made by modifying this software),
 * provided that the following four conditions (1) through (4) are
 * satisfied.
 * 
 * (1) When this software is used in the form of source code, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be retained in the source code without modification.
 *
 * (2) When this software is redistributed in the forms usable for the
 *    development of other software, such as in library form, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be shown without modification in the document provided
 *    with the redistributed software, such as the user manual.
 *
 * (3) When this software is redistributed in the forms unusable for the
 *    development of other software, such as the case when the software
 *    is embedded in a piece of equipment, either of the following two
 *    conditions must be satisfied:
 *
 *  (a) The above copyright notice, this use conditions, and the
 *      disclaimer shown below must be shown without modification in
 *      the document provided with the redistributed software, such as
 *      the user manual.
 *
 *  (b) How the software is to be redistributed must be reported to the
 *      TOPPERS Project according to the procedure described
 *      separately.
 *
 * (4) The above copyright holders and the TOPPERS Project are exempt
 *    from responsibility for any type of damage directly or indirectly
 *    caused from the use of this software and are indemnified by any
 *    users or end users of this software from any and all causes of
 *    action whatsoever.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 * THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 * TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 * INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

#ifndef _OSEK_H_
#define _OSEK_H_

#ifndef _MACRO_ONLY
typedef int					BOOL;		/* boolean */
typedef	signed char		    INT8;		/* 8 bit integer */
typedef	unsigned char		UINT8;		/* 8 bit unsigned integer */
typedef	signed short		INT16;		/* 16 bit integer */
typedef	unsigned short  	UINT16;	    /* 16 bit unsigned integer */
typedef	signed long	    	INT32;		/* 32 bit integer */
typedef	unsigned long	    UINT32;		/* 32 bit unsigned integer */
typedef	signed long long	INT64;		/* 64 bit unsigned intege */
typedef	unsigned long long  UINT64;		/* 64 bit unsigned intege */
typedef UINT8		StatusType;			
#endif /* _MACRO_ONLY */

#define	E_OK		((StatusType) 0)	

#define UINT8_INVALID		((UINT8)(~0u))
#define UINT16_INVALID		((UINT16)(~0u))

#ifndef TRUE
#define TRUE		((BOOL) 1)			
#define FALSE		((BOOL) 0)			
#endif

#endif /*_OSEK_H_*/

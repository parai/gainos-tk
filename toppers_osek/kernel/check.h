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


#ifndef _CHECK_H_
#define _CHECK_H_

#ifdef EXTENDED_STATUS

#define CHECK_ACCESS(exp) do {			\
	if (!(exp)) {						\
		ercd = E_OS_ACCESS;				\
		goto error_exit;				\
	}									\
} while (0)

#define D_CHECK_ACCESS(exp) do {		\
	if (!(exp)) {						\
		ercd = E_OS_ACCESS;				\
		goto d_error_exit;				\
	}									\
} while (0)

#define CHECK_CALLEVEL(clmask) do {		\
	if ((callevel & (clmask)) == 0) {	\
		ercd = E_OS_CALLEVEL;			\
		goto error_exit;				\
	}									\
} while (0)

#define CHECK_TSKID(tskid) do {			\
	if (!(tskid < tnum_task)) {			\
		ercd = E_OS_ID;					\
		goto error_exit;				\
	}									\
} while (0)

#define CHECK_RESID(resid) do {			\
	if (!(resid < tnum_resource)) {		\
		ercd = E_OS_ID;					\
		goto error_exit;				\
	}									\
} while (0)

#define CHECK_CNTID(cntid) do {			\
	if (!(cntid < tnum_counter)) {		\
		ercd = E_OS_ID;					\
		goto error_exit;				\
	}									\
} while (0)

#define CHECK_ALMID(almid) do {			\
	if (!(almid < tnum_alarm)) {		\
		ercd = E_OS_ID;					\
		goto error_exit;				\
	}									\
} while (0)

#define CHECK_NOFUNC(exp) do {			\
	if (!(exp)) {						\
		ercd = E_OS_NOFUNC;				\
		goto error_exit;				\
	}									\
} while (0)

#define CHECK_RESOURCE(exp) do {		\
	if (!(exp)) {						\
		ercd = E_OS_RESOURCE;			\
		goto error_exit;				\
	}									\
} while (0)

#define D_CHECK_STATE(exp) do {			\
	if (!(exp)) {						\
		ercd = E_OS_STATE;				\
		goto d_error_exit;				\
	}									\
} while (0)

#define CHECK_VALUE(exp) do {			\
	if (!(exp)) {						\
		ercd = E_OS_VALUE;				\
		goto error_exit;				\
	}									\
} while (0)

#else /* EXTENDED_STATUS */

#define CHECK_ACCESS(exp)		((void) 0)
#define D_CHECK_ACCESS(exp)		((void) 0)
#define CHECK_CALLEVEL(clmask)	((void) 0)
#define CHECK_TSKID(tskid)		((void) 0)
#define CHECK_RESID(resid)		((void) 0)
#define CHECK_CNTID(cntid)		((void) 0)
#define CHECK_ALMID(almid)		((void) 0)
#define CHECK_NOFUNC(exp)		((void) 0)
#define CHECK_RESOURCE(exp)		((void) 0)
#define D_CHECK_STATE(exp)		((void) 0)
#define CHECK_VALUE(exp)		((void) 0)

#endif /* EXTENDED_STATUS */
#endif /* _CHECK_H_ */

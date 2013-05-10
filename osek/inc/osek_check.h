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
#ifndef OSEK_CHECK_H_H
#define OSEK_CHECK_H_H


/* ============================ MACROs   ========================================== */
#define CHECK_COMMON_STD(_con,_ercd)    {   \
    if(!(_con))                             \
    {                                       \
        ercd = _ercd;                       \
        goto Error_Exit;                    \
    }                                       \
}
#if(cfgOS_STATUS_LEVEL == OS_STATUS_EXTEND)
#define CHECK_TASKID_EXT(_tskid)         \
{                                   \
    if(_tskid >= cfgOSEK_TASK_NUM)   \
    {                               \
        ercd = E_OS_ID;             \
        goto Error_Exit;            \
    }                               \
}    

#define CHECK_NONSELF_EXT(_tskid) {				            	\
	if (!in_indp() && (_tskid) == (knl_ctxtsk-knl_tcb_table)) {		\
		ercd = E_OS_ID;                                     \
        goto Error_Exit;                                    \
	}						                              	\
}

#define CHECK_COMMON_EXT(_con,_ercd)    {   \
    if(!(_con))                             \
    {                                       \
        ercd = _ercd;                       \
        goto Error_Exit;                    \
    }                                       \
}
#else /* OS_STATUS_STANDARD*/
#define CHECK_TASKID_EXT(_tskid)
#define CHECK_NONSELF_EXT(_tskid)
#define CHECK_COMMON_EXT(_con,_ercd)
#endif /* OS_STATUS_EXTEND */ 


#endif /* OSEK_CHECK_H_H */

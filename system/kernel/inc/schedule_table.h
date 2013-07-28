/* Copyright 2013, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email: parai@foxmail.com
 * Sourrce Open At: https://github.com/parai/gainos-tk/
 */
#ifndef SCHEDULE_TABLE_H_H_H
#define SCHEDULE_TABLE_H_H_H
/* ============================ INCLUDEs ========================================== */
#include "autosar_os.h"

/* ============================ MACROs   ========================================== */
//as I see,There is 2 methods to process schedule table.
//1: the method adopted by alarm in gainos-tk,the running shcedule tables 
// in the order by time in queue.
//2: the method to loop over all the schedule table connected to one counter, 
// and only remove the schedule table when stop and insert it when start.  
//both of the 2 methods I think are good, So I will implement both .
//when there are only several schedule tables, I think menthod 2 should be prefered.
//but when there are many schedule tables, I think menthod 1 should be prefered.
#define SCHEDTBL_IN_ORDER 1
#define SCHEDTBL_IN_LOOP  2

#if(cfgAR_SCHEDTBL_QUEUE_METHOD == SCHEDTBL_IN_ORDER)
#define INSERT_SCHEDTBL(_schedtblcb,_ccb)  knl_schedtbl_insert(_schedtblcb,_ccb)
#else
#define INSERT_SCHEDTBL(_schedtblcb,_ccb)  QueInsert(&(_schedtblcb)->tblque,&(_ccb)->tblque)
#endif
 
/* ============================ DATAs    ========================================== */
IMPORT const T_GSCHEDTBL knl_gschedtbl_table[cfgAR_SCHEDTBL_NUM];
IMPORT SCHEDTBLCB knl_schedtblcb_table[cfgAR_SCHEDTBL_NUM];

/* ============================ FUNCTIONs    ====================================== */
IMPORT void knl_init_schedule_table(void);
IMPORT void knl_signal_schedule_table(SCHEDTBLCB* schedtblcb,CCB* ccb);
#if(cfgAR_SCHEDTBL_QUEUE_METHOD == SCHEDTBL_IN_ORDER)  
IMPORT void knl_schedtbl_insert(SCHEDTBLCB *schedtblcb,CCB* ccb);
#endif
#endif /* SCHEDULE_TABLE_H_H_H */
 

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

/* ============================ DATAs    ========================================== */
IMPORT const T_GSCHEDTBL knl_gschedtbl_table[cfgAUTOSAR_SCHEDULE_TABLE_NUM];
IMPORT SCHEDTBLCB knl_schedtblcb_table[cfgAUTOSAR_SCHEDULE_TABLE_NUM];

/* ============================ FUNCTIONs    ====================================== */
IMPORT void knl_schedtbl_insert(SCHEDTBLCB *schedtblcb,CCB* ccb);
IMPORT void knl_start_schedule_table(SCHEDTBLCB* schedtblcb,CCB *ccb);
IMPORT void knl_init_schedule_table(void);
IMPORT void knl_signal_schedule_table(SCHEDTBLCB* schedtblcb,CCB* ccb);

#endif /* SCHEDULE_TABLE_H_H_H */
 

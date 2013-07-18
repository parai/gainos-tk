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
#ifndef AUTOSAR_OS_H_H_H
#define AUTOSAR_OS_H_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h" 

/* ============================ MACROs   ========================================== */
#define GenSchedTblInfo(name,owner,strategy,length,repeatable,duration,maxadvance,maxretard)  \
{                 \
    owner,        \
    strategy,     \
    /* table = */ name##_ExpiryPointList,   \
    length,       \
    repeatable,   \
    duration,     \
    maxadvance,   \
    maxretard     \
} 
   
/* ============================ TYPEs   ========================================== */
//private types for schedule table
typedef enum
{
    /* The schedule table is started during startup with the
       StartScheduleTableAbs() service. */
    ABSOLUTE,
    /* The schedule table is started during startup with the
       StartScheduleTableRel() service. */
    RELATIVE,
    /* The schedule table is started during startup with the
       StartScheduleTableSynchron() service. */
    SYNCHRON
}ScheduleTableAutostartType;

typedef enum
{
    /* The schedule table is driven by an OS counter but
       processing needs to be synchronized with a different
       counter which is not an OS counter object.*/
    EXPLICIT,
    /* The counter driving the schedule table is the counter
       with which synchronisation is required.*/
    IMPLICIT,
    /* No support for synchronisation. (default) */
    NONE
}ScheduleTableSyncStrategyType;

typedef struct
{
    TickType offset;            /* the relative offset to the previous expiry point */
    FP action;
}ScheduleTableExpiryPointType;

typedef struct _schedule_table_generate_info
{
    CounterType owner;          /* schedule table owner -> counter */
    ScheduleTableSyncStrategyType strategy;
    const ScheduleTableExpiryPointType* table; /* expiry point table */
    uint8 length;                        /* the length of the table */
    uint8/* BOOL */ repeatable;
    TickType duration;
    TickType maxadvance;
    TickType maxretard;
}T_GSCHEDTBL; 

typedef struct _schedule_table_control_block
{
    QUEUE tblque;
    TickType time;              /* the next expiry point time */
    ScheduleTableStatusType status;
    uint8 index;                /* index of the next expiry point on the T_GSCHEDTBL.table */
    ScheduleTableType next;     /* the next schedule table in state SCHEDULETABLE_NEXT or INVALID_SCHEDTBL;
                                 * or the previous schedule table in the state RUNNING and has a next schedule table*/
    INT      deviation;
}SCHEDTBLCB;

#endif /* AUTOSAR_OS_H_H_H */

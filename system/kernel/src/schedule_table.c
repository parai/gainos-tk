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
#include "autosar_os.h" 
#include "schedule_table.h"
#include "knl_alarm.h"
#include "portable.h"

EXPORT SCHEDTBLCB knl_schedtblcb_table[cfgAR_SCHEDTBL_NUM];

/* |-------------------+---------------------------------------------------------------| */
/* | Service name:     | StartScheduleTableRel                                         | */
/* |-------------------+---------------------------------------------------------------| */
/* | Syntax:           | StatusType StartScheduleTableRel                              | */
/* |                   | (ScheduleTableType ScheduleTableID,                           | */
/* |                   | TickType Offset)                                              | */
/* |-------------------+---------------------------------------------------------------| */
/* | Service ID:       | OSServiceId_StartScheduleTableRel                             | */
/* | Sync/Async:       | Sync                                                          | */
/* | Reentrancy:       | Yes                                                           | */
/* | Parameters (in):  | ScheduleTableID:Schedule table to be started                  | */
/* |                   | Offset:Number of ticks on the counter before the the schedule | */
/* |                   | table processing is started                                   | */
/* | Parameters (out): | None                                                          | */
/* |-------------------+---------------------------------------------------------------| */
/* | Return value:     | E_OK:No error                                                 | */
/* |                   | E_OS_ID(only in extended status):ScheduleTableID not valid.   | */
/* |                   | E_OS_VALUE(only in extended status):Offset is greater than    | */
/* |                   | (OsCounterMaxAllowedValue InitialOffset) or is equal to 0.    | */
/* |                   | E_OS_STATE:Schedule table was already started.                | */
/* |-------------------+---------------------------------------------------------------| */
/* | Description:      | OS275: If the schedule table <ScheduleTableID> is not valid,  | */
/* |                   | StartScheduleTableRel() shall return E_OS_ID.                 | */
/* |                   | OS452: If the schedule table <ScheduleTableID> is             | */
/* |                   | implicitely synchronized (OsScheduleTblSyncStrategy =         | */
/* |                   | IMPLICIT), StartScheduleTableRel() shall return E_OS_ID.      | */
/* |                   | OS332: If <Offset> is zero StartScheduleTableRel() shall      | */
/* |                   | return E_OS_VALUE.                                            | */
/* |                   | OS276: If the offset <Offset> is greater than                 | */
/* |                   | OsCounterMaxAllowedValue of the underlying counter minus      | */
/* |                   | the Initial Offset, StartScheduleTableRel() shall return      | */
/* |                   | E_OS_VALUE.                                                   | */
/* |                   | OS277: If the schedule table <ScheduleTableID> is not in the  | */
/* |                   | state SCHEDULETABLE_STOPPED, StartScheduleTableRel() shall    | */
/* |                   | return E_OS_STATE.                                            | */
/* |                   | OS278: If its input parameters are valid and the state of     | */
/* |                   | schedule table <ScheduleTableID> is SCHEDULETABLE_STOPPED,    | */
/* |                   | then StartScheduleTableRel() shall start the processing of a  | */
/* |                   | schedule table <ScheduleTableID>. The Initial Expiry Point    | */
/* |                   | shall be processed after <Offset> + Initial Offset ticks      | */
/* |                   | have elapsed on the underlying counter. The state of          | */
/* |                   | <ScheduleTableID> to SCHEDULETABLE_RUNNING.                   | */
/* |-------------------+---------------------------------------------------------------| */
/* | Caveats:          | None                                                          | */
/* | Configuration:    | Available in all Scalability Classes.                         | */
/* |-------------------+---------------------------------------------------------------| */
StatusType StartScheduleTableRel(ScheduleTableType ScheduleTableID,
                                 TickType Offset)
{
    StatusType ercd = E_OK;
    const T_GSCHEDTBL* gschedtbl;
    SCHEDTBLCB*  schedtblcb;
    CCB* ccb;
    TickType max;              /* max allowed value for counter */
    OS_CHECK_EXT((ScheduleTableID < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    gschedtbl = &knl_gschedtbl_table[ScheduleTableID];
    OS_CHECK_EXT((IMPLICIT != gschedtbl->strategy), E_OS_ID);
    max = knl_almbase_table[gschedtbl->owner].maxallowedvalue;
    OS_CHECK_EXT(((Offset > 0u) && (Offset <= (max - gschedtbl->table[0].offset))),E_OS_VALUE);
    schedtblcb = &knl_schedtblcb_table[ScheduleTableID];
    OS_CHECK((SCHEDULETABLE_STOPPED == schedtblcb->status),E_OS_STATE);
    ccb = &knl_ccb_table[gschedtbl->owner];

    BEGIN_DISABLE_INTERRUPT;
    schedtblcb->time = knl_add_ticks(ccb->curvalue,Offset+gschedtbl->table[0].offset,max*2);
    knl_start_schedule_table(schedtblcb,ccb);
    END_DISABLE_INTERRUPT;
    
  Error_Exit:
    return ercd;
}

/* |-------------------+----------------------------------------------------------------| */
/* | Service name:     | StartScheduleTableAbs                                          | */
/* |-------------------+----------------------------------------------------------------| */
/* | Syntax:           | StatusType StartScheduleTableAbs                               | */
/* |                   | (ScheduleTableType ScheduleTableID,                            | */
/* |                   | TickType Start)                                                | */
/* | Service ID:       | OSServiceId_StartScheduleTableAbs                              | */
/* | Sync/Async:       | Sync                                                           | */
/* | Reentrancy:       | Yes                                                            | */
/* | Parameters (in):  | ScheduleTableID:Schedule table to be started                   | */
/* |                   | Start:Absolute counter tick value at which the                 | */
/* |                   | schedule table is started.                                     | */
/* | Parameters (out): | None                                                           | */
/* |-------------------+----------------------------------------------------------------| */
/* | Return value:     | E_OK:No error                                                  | */
/* |                   | E_OS_ID(only in extended status):ScheduleTableID not valid.    | */
/* |                   | E_OS_VALUE(only in extended status):Tickvalue is greater       | */
/* |                   | than OsCounterMaxAllowedValue.                                 | */
/* |                   | E_OS_STATE:Schedule table was already started.                 | */
/* |-------------------+----------------------------------------------------------------| */
/* | Description:      | OS348: If the schedule table <ScheduleTableID> is not valid,   | */
/* |                   | StartScheduleTableAbs() shall return E_OS_ID.                  | */
/* |                   | OS349: If the <Tickvalue> is greater than the                  | */
/* |                   | OsCounterMaxAllowedValue of the underlying counter,            | */
/* |                   | StartScheduleTableAbs() shall return E_OS_VALUE.               | */
/* |                   | OS350: If the schedule table <ScheduleTableID> is not in the   | */
/* |                   | state SCHEDULETABLE_STOPPED, StartScheduleTableAbs() shall     | */
/* |                   | return E_OS_STATE.                                             | */
/* |                   | OS351: If its input parameters are valid and <ScheduleTableID> | */
/* |                   | is in the state SCHEDULETABLE_STOPPED, StartScheduleTableAbs() | */
/* |                   | shall start the processing of schedule table <ScheduleTableID> | */
/* |                   | at count value <Start> and shall set the state of              | */
/* |                   | <ScheduleTableID> to SCHEDULETABLE_RUNNING. The Initial Expiry | */
/* |                   | Point will be processed when the underlying counter equals     | */
/* |                   | <Start>+Initial Offset.                                        | */
/* |-------------------+----------------------------------------------------------------| */
/* | Caveats:          | None                                                           | */
/* | Configuration:    | Available in all Scalability Classes.                          | */
/* |-------------------+----------------------------------------------------------------| */
StatusType StartScheduleTableAbs(ScheduleTableType ScheduleTableID,
                                 TickType Start)
{
    StatusType ercd = E_OK;
    const T_GSCHEDTBL* gschedtbl;
    SCHEDTBLCB*  schedtblcb;
    CCB* ccb;
    TickType max;              /* max allowed value for counter */
    OS_CHECK_EXT((ScheduleTableID < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    gschedtbl = &knl_gschedtbl_table[ScheduleTableID];
    max = knl_almbase_table[gschedtbl->owner].maxallowedvalue;
    OS_CHECK_EXT((Start <= max),E_OS_VALUE);
    schedtblcb = &knl_schedtblcb_table[ScheduleTableID];
    OS_CHECK((SCHEDULETABLE_STOPPED == schedtblcb->status),E_OS_STATE);
    ccb = &knl_ccb_table[gschedtbl->owner];

    BEGIN_DISABLE_INTERRUPT;
    schedtblcb->time = Start + gschedtbl->table[0].offset;
    knl_start_schedule_table(schedtblcb,ccb);
    END_DISABLE_INTERRUPT;
    
  Error_Exit:
    return ercd;
}
/* |-------------------+---------------------------------------------------------------| */
/* | Service name:     | StopScheduleTable                                             | */
/* |-------------------+---------------------------------------------------------------| */
/* | Syntax:           | StatusType StopScheduleTable                                  | */
/* |                   | (ScheduleTableType ScheduleTableID)                           | */
/* | Service ID:       | OSServiceId_StopScheduleTable                                 | */
/* | Sync/Async:       | Sync                                                          | */
/* | Reentrancy:       | Yes                                                           | */
/* | Parameters (in):  | ScheduleTableID:Schedule table to be stopped None             | */
/* | Parameters (out): | None                                                          | */
/* |-------------------+---------------------------------------------------------------| */
/* | Return value:     | E_OK:no error                                                 | */
/* |                   | E_OS_ID(only in EXTENDED status):ScheduleTableID not valid.   | */
/* |                   | E_OS_NOFUNC:Schedule table was already stopped                | */
/* |-------------------+---------------------------------------------------------------| */
/* | Description:      | OS279: If the schedule table identifier <ScheduleTableID>     | */
/* |                   | is not valid, StopScheduleTable() shall return E_OS_ID.       | */
/* |                   | OS280: If the schedule table with identifier                  | */
/* |                   | <ScheduleTableID> is in state SCHEDULETABLE_STOPPED,          | */
/* |                   | StopScheduleTable() shall return E_OS_NOFUNC.                 | */
/* |                   | OS281: If its input parameters are valid, StopScheduleTable() | */
/* |                   | shall set the state of <ScheduleTableID> to                   | */
/* |                   | SCHEDULETABLE_STOPPED and (stop the schedule table            | */
/* |                   | <ScheduleTableID> from processing any further expiry points   | */
/* |                   | and) shall return E_OK.                                       | */
/* |-------------------+---------------------------------------------------------------| */
/* | Caveats:          | None                                                          | */
/* | Configuration:    | Available in all Scalability Classes.                         | */
/* |-------------------+---------------------------------------------------------------| */
StatusType StopScheduleTable(ScheduleTableType ScheduleTableID)
{
    StatusType ercd = E_OK;
    SCHEDTBLCB*  schedtblcb;
    OS_CHECK_EXT((ScheduleTableID < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    schedtblcb = &knl_schedtblcb_table[ScheduleTableID];
    OS_CHECK((SCHEDULETABLE_STOPPED != schedtblcb->status),E_OS_NOFUNC);
    
    BEGIN_DISABLE_INTERRUPT;
    switch(schedtblcb->status)
    {
        case SCHEDULETABLE_RUNNING:
        case SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS:
        {
            QueRemove(&schedtblcb->tblque);
            if(schedtblcb->next != INVALID_SCHEDTBL)
            {   //@req OS453
                SCHEDTBLCB* cb = &knl_schedtblcb_table[schedtblcb->next];
                cb->status = SCHEDULETABLE_STOPPED;
            }
            break;
        }
        case SCHEDULETABLE_NEXT:
        {   
            SCHEDTBLCB* fromcb = &knl_schedtblcb_table[schedtblcb->next];
            //Assert(fromcb->status == RUNNING)
            fromcb->next =  INVALID_SCHEDTBL;
            break;
        }
        default:
            break;
    }
    schedtblcb->status = SCHEDULETABLE_STOPPED;
    END_DISABLE_INTERRUPT;
  Error_Exit:
    return ercd;
}
/* |-------------------+-----------------------------------------------------------------| */
/* | Service name:     | NextScheduleTable                                               | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Syntax:           | StatusType NextScheduleTable                                    | */
/* |                   | (ScheduleTableType ScheduleTableID_From,                        | */
/* |                   | ScheduleTableType ScheduleTableID_To)                           | */
/* | Service ID:       | OSServiceId_NextScheduleTable                                   | */
/* | Sync/Async:       | Sync                                                            | */
/* | Reentrancy:       | Yes                                                             | */
/* | Parameters (in):  | ScheduleTableID_From:Schedule table                             | */
/* |                   | ScheduleTableID_To:Schedule table that provides its             | */
/* |                   | series of expiry points                                         | */
/* | Parameters (out): | None                                                            | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Return value:     | E_OK:No error                                                   | */
/* |                   | E_OS_ID (only in EXTENDED status):ScheduleTableID_From or       | */
/* |                   | ScheduleTableID_To not valid.                                   | */
/* |                   | E_OS_NOFUNC:ScheduleTableID_From not started.                   | */
/* |                   | E_OS_STATE (only in EXTENDED status):ScheduleTableID_To         | */
/* |                   | is started or next.                                             | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Description:      | OS282: If the input parameter <ScheduleTableID_From> or         | */
/* |                   | <ScheduleTableID_To> is not valid, NextScheduleTable()          | */
/* |                   | shall return E_OS_ID.                                           | */
/* |                   | OS330: If schedule table <ScheduleTableID_To> is driven         | */
/* |                   | by different counter than schedule table                        | */
/* |                   | <ScheduleTableID_From> then NextScheduleTable() shall           | */
/* |                   | return an error E_OS_ID.                                        | */
/* |                   | OS283: If the schedule table <ScheduleTableID_From> is          | */
/* |                   | in state SCHEDULETABLE_STOPPED OR in state                      | */
/* |                   | SCHEDULETABLE_NEXT, NextScheduleTable() shall leave the         | */
/* |                   | state of <ScheduleTable_From> and <ScheduleTable_To>            | */
/* |                   | unchanged and return E_OS_NOFUNC..                              | */
/* |                   | OS309: If the schedule table <ScheduleTableID_To> is not        | */
/* |                   | in state SCHEDULETABLE_STOPPED, NextScheduleTable()             | */
/* |                   | shall leave the state of <ScheduleTable_From> and               | */
/* |                   | <ScheduleTable_To> unchanged and return E_OS_STATE.             | */
/* |                   | OS284: If the input parameters are valid then                   | */
/* |                   | NextScheduleTable() shall start the processing of schedule      | */
/* |                   | table <ScheduleTableID_To> <ScheduleTableID_From>.              | */
/* |                   | FinalDelay ticks after the Final Expiry Point on                | */
/* |                   | <ScheduleTableID_From> is processed and shall return            | */
/* |                   | E_OK. The Initial Expiry Point on <ScheduleTableID_To>          | */
/* |                   | shall be processed at <ScheduleTableID_From>.Final Delay        | */
/* |                   | + <ScheduleTable_To>.Initial Offset ticks after the Final       | */
/* |                   | Expiry Point on <ScheduleTableID_From> is processed .           | */
/* |                   | OS324: If the input parameters are valid AND the                | */
/* |                   | <ScheduleTableID_From> already has a ¡°next¡± schedule            | */
/* |                   | table then the <ScheduleTableID_To> shall replace the           | */
/* |                   | previous ¡°next¡± schedule table and the old ¡°next¡± schedule      | */
/* |                   | table state becomes SCHEDULETABLE_STOPPED.                      | */
/* |                   | OS363: The synchronization strategy of the <ScheduleTableID_To> | */
/* |                   | shall come into effect when the Operating System processes the  | */
/* |                   | first expiry point of <ScheduleTableID_To>.                     | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Caveats:          | OS453: If the <ScheduleTableID_From> is stopped, the ¡°next¡±     | */
/* |                   | schedule table does not start and its state changes to          | */
/* |                   | SCHEDULETABLE_STOPPED.                                          | */
/* |-------------------+-----------------------------------------------------------------| */
/* | Configuration:    | Available in all Scalability Classes.                           | */
/* |-------------------+-----------------------------------------------------------------| */
StatusType NextScheduleTable(ScheduleTableType ScheduleTableID_From,
                             ScheduleTableType ScheduleTableID_To)
{
    StatusType ercd = E_OK;
    const T_GSCHEDTBL *gschedtbl_from,*gschedtbl_to;
    SCHEDTBLCB *schedtblcb_from,*schedtblcb_to;
    OS_CHECK_EXT((ScheduleTableID_From < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    OS_CHECK_EXT((ScheduleTableID_To < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    gschedtbl_from = &knl_gschedtbl_table[ScheduleTableID_From];
    gschedtbl_to = &knl_gschedtbl_table[ScheduleTableID_To];
    OS_CHECK_EXT((gschedtbl_from->owner == gschedtbl_to->owner),E_OS_ID);
    OS_CHECK_EXT((gschedtbl_from->strategy == gschedtbl_to->strategy),E_OS_ID);  //@req OS484
    schedtblcb_from = &knl_schedtblcb_table[ScheduleTableID_From];
    OS_CHECK((schedtblcb_from->status != SCHEDULETABLE_STOPPED)&&(schedtblcb_from->status != SCHEDULETABLE_NEXT),E_OS_NOFUNC); 
    schedtblcb_to = &knl_schedtblcb_table[ScheduleTableID_To];
    OS_CHECK((SCHEDULETABLE_STOPPED == schedtblcb_to->status ),E_OS_STATE); 
    
    BEGIN_DISABLE_INTERRUPT;
    if(schedtblcb_from->next != INVALID_SCHEDTBL)
    {   
        SCHEDTBLCB* cb = &knl_schedtblcb_table[schedtblcb_from->next];
        cb->status = SCHEDULETABLE_STOPPED;
    }
    schedtblcb_from->next = ScheduleTableID_To;
    schedtblcb_to->status = SCHEDULETABLE_NEXT;
    schedtblcb_to->next = ScheduleTableID_From;
    END_DISABLE_INTERRUPT;
  Error_Exit:
    return ercd;
}


/* |-------------------+---------------------------------------------------------| */
/* | Service name:     | StartScheduleTableSynchron                              | */
/* |-------------------+---------------------------------------------------------| */
/* | Syntax:           | StatusType StartScheduleTableSynchron                   | */
/* |                   | (ScheduleTableType ScheduleTableID)                     | */
/* | Sync/Async:       | Sync                                                    | */
/* | Reentrancy:       | Yes                                                     | */
/* | Parameters (in):  | ScheduleTableID:Schedule table to be started            | */
/* | Parameters (out): | None                                                    | */
/* |-------------------+---------------------------------------------------------| */
/* | Return value:     | E_OK:No Error                                           | */
/* |                   | E_OS_ID (only in EXTENDED status):ScheduleTableID       | */
/* |                   | not valid.                                              | */
/* |                   | E_OS_STATE:Schedule table was already started.          | */
/* |-------------------+---------------------------------------------------------| */
/* | Description:      | OS387: If the schedule table <ScheduleTableID> is       | */
/* |                   | not valid OR the schedule table <ScheduleTableID>       | */
/* |                   | is not explicitly synchronized                          | */
/* |                   | (OsScheduleTblSyncStrategy = EXPLICIT)                  | */
/* |                   | StartScheduleTableSynchron() shall return E_OS_ID.      | */
/* |                   | OS388: If the schedule table <ScheduleTableID> is       | */
/* |                   | not in the state SCHEDULETABLE_STOPPED, the service     | */
/* |                   | shall return E_OS_STATE.                                | */
/* |                   | OS389: If <ScheduleTableID> is valid,                   | */
/* |                   | StartScheduleTableSynchron() shall set the state of     | */
/* |                   | <ScheduleTableID> to SCHEDULETABLE_WAITING and start    | */
/* |                   | the processing of schedule table <ScheduleTableID>      | */
/* |                   | after the synchronization count of the schedule table   | */
/* |                   | is set via SyncScheduleTable(). The Initial Expiry      | */
/* |                   | Point shall processed when (Duration-SyncValue)+        | */
/* |                   | InitialOffset ticks have elapsed on the synchronization | */
/* |                   | counter where:                                          | */
/* |                   | ` Duration is <ScheduleTableID>.OsScheduleTableDuration | */
/* |                   | ` SyncValue is the <Value> parameter passed to the      | */
/* |                   | SyncScheduleTable()                                     | */
/* |                   | ` InitialOffset is the shortest expiry point offset in  | */
/* |                   | <ScheduleTableID>                                       | */
/* |-------------------+---------------------------------------------------------| */
/* | Caveats:          | None                                                    | */
/* | Configuration:    | Available in Scalability Classes 2 and 4                | */
/* |-------------------+---------------------------------------------------------| */
StatusType StartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
{
    StatusType ercd = E_OK;
    const T_GSCHEDTBL* gschedtbl;
    SCHEDTBLCB*  schedtblcb;
    OS_CHECK_EXT((ScheduleTableID < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    gschedtbl = &knl_gschedtbl_table[ScheduleTableID];
    OS_CHECK_EXT((EXPLICIT ==  gschedtbl->strategy),E_OS_ID);
    schedtblcb = &knl_schedtblcb_table[ScheduleTableID];
    OS_CHECK((SCHEDULETABLE_STOPPED == schedtblcb->status),E_OS_STATE);
    
    schedtblcb->status = SCHEDULETABLE_WAITING;
    
  Error_Exit:
    return ercd;
}

/* |-------------------+--------------------------------------------------------------| */
/* | Service name:     | SyncScheduleTable                                            | */
/* |-------------------+--------------------------------------------------------------| */
/* | Syntax:           | StatusType SyncScheduleTable                                 | */
/* |                   | (ScheduleTableType ScheduleTableID,                          | */
/* |                   | TickType Value)                                              | */
/* | Service ID:       | OSServiceId_SyncScheduleTable                                | */
/* | Sync/Async:       | Sync                                                         | */
/* | Reentrancy:       | Yes                                                          | */
/* | Parameters (in):  | ScheduleTableID:Schedule table                               | */
/* |                   | Value:The current value of the synchronization counter.      | */
/* | Parameters (out): | None                                                         | */
/* |-------------------+--------------------------------------------------------------| */
/* | Return value:     | E_OK:No errors                                               | */
/* |                   | E_OS_ID (only in EXTENDED status):The ScheduleTableID was    | */
/* |                   | not valid or schedule table can not be synchronized          | */
/* |                   | (OsScheduleTblSyncStrategy not set or                        | */
/* |                   | OsScheduleTblSyncStrategy = IMPLICIT).                       | */
/* |                   | E_OS_VALUE (only in EXETENDED status):The <Value> is out     | */
/* |                   | of range.                                                    | */
/* |                   | E_OS_STATE (only in EXTENDED status):The state of            | */
/* |                   | schedule table <ScheduleTableID> is equal to                 | */
/* |                   | SCHEDULETABLE_STOPPED.                                       | */
/* |-------------------+--------------------------------------------------------------| */
/* | Description:      | OS454: If the <ScheduleTableID> is not valid OR schedule     | */
/* |                   | table can not be explicitely synchronized                    | */
/* |                   | (OsScheduleTblSyncStrategy is not equal to EXPLICIT)         | */
/* |                   | the service shall return E_OS_ID.                            | */
/* |                   | OS455: If the <Value> is greater than the                    | */
/* |                   | OsScheduleTableDuration, SyncScheduleTable() shall           | */
/* |                   | return E_OS_VALUE.                                           | */
/* |                   | OS456: If the state of the schedule table <ScheduleTableID>  | */
/* |                   | is equal to SCHEDULETABLE_STOPPED or SCHEDULETABLE_NEXT the  | */
/* |                   | service shall return E_OS_STATE.                             | */
/* |                   | OS457: If the parameters are valid, the service provides the | */
/* |                   | operating system with the current synchronization count for  | */
/* |                   | the given schedule table. (It is used to synchronize the     | */
/* |                   | processing of the schedule table to the synchronization      | */
/* |                   | counter.)                                                    | */
/* |-------------------+--------------------------------------------------------------| */
/* | Caveats:          | None                                                         | */
/* | Configuration:    | Available in Scalability Classes 2 and 4                     | */
/* |-------------------+--------------------------------------------------------------| */
StatusType SyncScheduleTable(ScheduleTableType ScheduleTableID,TickType Value)
{
    StatusType ercd = E_OK;
    const T_GSCHEDTBL* gschedtbl;
    SCHEDTBLCB*  schedtblcb;
    CCB* ccb;
    TickType max;              /* max allowed value for counter */
    OS_CHECK_EXT((ScheduleTableID < cfgAR_SCHEDTBL_NUM),E_OS_ID);
    gschedtbl = &knl_gschedtbl_table[ScheduleTableID];
    OS_CHECK_EXT((EXPLICIT ==  gschedtbl->strategy),E_OS_ID);
    OS_CHECK_EXT((Value <= gschedtbl->duration),E_OS_VALUE);
    schedtblcb = &knl_schedtblcb_table[ScheduleTableID];
    OS_CHECK_EXT((schedtblcb->status != SCHEDULETABLE_STOPPED)&&(schedtblcb->status != SCHEDULETABLE_NEXT),E_OS_STATE); 
    
    max = knl_almbase_table[gschedtbl->owner].maxallowedvalue;
    ccb = &knl_ccb_table[gschedtbl->owner];
    
    BEGIN_DISABLE_INTERRUPT;
    if(SCHEDULETABLE_WAITING == schedtblcb->status)
    {
        TickType rel = gschedtbl->duration - Value + gschedtbl->table[0].offset;
        schedtblcb->time = knl_add_ticks(ccb->curvalue,rel,max*2);
        knl_start_schedule_table(schedtblcb,ccb);  
    }
    else //running state
    {
    }
    END_DISABLE_INTERRUPT;
  Error_Exit:
    return ercd;
}

/* |-------------------+----------------------------------------------------------------| */
/* | Service name:     | SetScheduleTableAsync                                          | */
/* |-------------------+----------------------------------------------------------------| */
/* | Syntax:           | StatusType SetScheduleTableAsync(                              | */
/* |                   | ScheduleTableType ScheduleTableID)                             | */
/* | Service ID:       | OSServiceId_SetScheduleTableAsync                              | */
/* | Sync/Async:       | Sync                                                           | */
/* | Reentrancy:       | Yes                                                            | */
/* | Parameters (in):  | ScheduleTableID:Name of schedule for which status is requested | */
/* | Parameters (out): | None                                                           | */
/* |-------------------+----------------------------------------------------------------| */
/* | Return value:     | E_OK:no error                                                  | */
/* |                   | E_OS_ID (only in EXTENDED status)):Invalid ScheduleTableID     | */
/* |-------------------+----------------------------------------------------------------| */
/* | Description:      | OS300: If OsScheduleTblSyncStrategy of <ScheduleTableID>       | */
/* |                   | equals to EXPLICIT then SetScheduleTableAsync() shall set      | */
/* |                   | the status of <ScheduleTableID> to SCHEDULETABLE_RUNNING.      | */
/* |                   | OS362: If SetScheduleTableAsync() is called for a running      | */
/* |                   | schedule table the OS shall stop further synchronization       | */
/* |                   | until a SyncScheduleTable() call is made.                      | */
/* |                   | OS323: If SetScheduleTableAsync() is called for a running      | */
/* |                   | schedule table the OS shall continue to process expiry         | */
/* |                   | points on the schedule table.                                  | */
/* |                   | OS458: If OsScheduleTblSyncStrategy of <ScheduleTableID> is    | */
/* |                   | not equal to EXPLICIT then the service call shall return       | */
/* |                   | E_OS_ID                                                        | */
/* |-------------------+----------------------------------------------------------------| */
/* | Caveats:          | None                                                           | */
/* | Configuration:    | Available in Scalability Classes 2 and 4                       | */
/* |-------------------+----------------------------------------------------------------| */
StatusType SetScheduleTableAsync(ScheduleTableType ScheduleTableID)
{
    StatusType ercd = E_OK;
  Error_Exit:
    return ercd;
}

/* |-------------------+-------------------------------------------------------------------| */
/* | Service name:     | GetScheduleTableStatus                                            | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Syntax:           | StatusType GetScheduleTableStatus                                 | */
/* |                   | (ScheduleTableType ScheduleTableID,                               | */
/* |                   | ScheduleTableStatusRefType ScheduleStatus)                        | */
/* | Service ID:       | OSServiceId_GetScheduleTableStatus                                | */
/* | Sync/Async:       | Sync                                                              | */
/* | Reentrancy:       | Yes                                                               | */
/* | Parameters (in):  | ScheduleTableID:Schedule table for which status                   | */
/* |                   | is requested                                                      | */
/* | Parameters (out): | ScheduleStatus:Reference to ScheduleStatusType                    | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Return value:     | E_OK:no error                                                     | */
/* |                   | E_OS_ID(only in extended status):Invalid                          | */
/* |                   | ScheduleTableID                                                   | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Description:      | OS289: If the schedule table <ScheduleTableID> is NOT started,    | */
/* |                   | GetScheduleTableStatus() shall pass back SCHEDULETABLE_STOPPED    | */
/* |                   | via the reference parameter <ScheduleStatus> AND shall return     | */
/* |                   | E_OK.                                                             | */
/* |                   | OS353: If the schedule table <ScheduleTableID> was used in a      | */
/* |                   | NextScheduleTable() call AND waits for the end of the current     | */
/* |                   | schedule table, GetScheduleTableStatus() shall return             | */
/* |                   | SCHEDULETABLE_NEXT via the reference parameter <ScheduleStatus>   | */
/* |                   | AND shall return E_OK.                                            | */
/* |                   | OS354: If the schedule table <ScheduleTableID> is configured with | */
/* |                   | explicit synchronization AND no synchronization count was         | */
/* |                   | provided to the Operating System, GetScheduleTableStatus() shall  | */
/* |                   | return SCHEDULETABLE_WAITING via the reference parameter          | */
/* |                   | <ScheduleStatus> AND shall return E_OK.                           | */
/* |                   | OS290: If the schedule table <ScheduleTableID> is started AND     | */
/* |                   | synchronous, GetScheduleTableStatus() shall pass back             | */
/* |                   | SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS via the reference parameter | */
/* |                   | <ScheduleStatus> AND shall return E_OK.                           | */
/* |                   | OS291: If the schedule table <ScheduleTableID> is started AND NOT | */
/* |                   | synchronous (deviation is not within the precision interval OR    | */
/* |                   | the schedule table has been set asynchronous),                    | */
/* |                   | GetScheduleTableStatus() shall pass back SCHEDULETABLE_RUNNING    | */
/* |                   | via the reference parameter ScheduleStatus AND shall return E_OK. | */
/* |                   | OS293: If the identifier <ScheduleTableID> is NOT valid,          | */
/* |                   | GetScheduleTableStatus() shall return E_OS_ID.                    | */
/* |-------------------+-------------------------------------------------------------------| */
/* | Caveats:          | None                                                              | */
/* | Configuration:    | Available in all Scalability Classes.                             | */
/* |-------------------+-------------------------------------------------------------------| */
StatusType GetScheduleTableStatus(ScheduleTableType ScheduleTableID,
                                  ScheduleTableStatusRefType ScheduleStatus)
{
    StatusType ercd = E_OK;
  Error_Exit:
    return ercd;
}

#if(cfgAR_SCHEDTBL_QUEUE_METHOD == SCHEDTBL_IN_ORDER)
// yes,this API is the same as knl_alm_insert()  
EXPORT void knl_schedtbl_insert(SCHEDTBLCB *schedtblcb,CCB* ccb)
{
    QUEUE* q;
    if(schedtblcb->time < ccb->curvalue)
    {   /* It's an overflowed schedule table,search from previous */
        for ( q = ccb->tblque.prev; q != &ccb->tblque; q = q->prev ) {
    		if ( ((schedtblcb->time > ((SCHEDTBLCB*)q)->time)) || (ccb->curvalue <= ((SCHEDTBLCB*)q)->time) ) {
    			break;
    		}
	    }
	    q = q->next;
    }
    else
    {
        for ( q = ccb->tblque.next; q != &ccb->tblque; q = q->next ) {
    		if ( (schedtblcb->time < ((SCHEDTBLCB*)q)->time) || (ccb->curvalue > ((SCHEDTBLCB*)q)->time) ) {
    			break;
    		}
        }
    }
    QueInsert(&schedtblcb->tblque,q);
}
#endif

EXPORT void knl_start_schedule_table(SCHEDTBLCB* schedtblcb,CCB *ccb)
{
    INSERT_SCHEDTBL(schedtblcb,ccb);
    schedtblcb->index = 0u;
    schedtblcb->status = SCHEDULETABLE_RUNNING;
    schedtblcb->next = INVALID_SCHEDTBL;
}

EXPORT void knl_init_schedule_table(void)
{
    int i;
    SCHEDTBLCB* schedtblcb;
    for(i = 0; i < cfgAR_SCHEDTBL_NUM; i++)
    {
        schedtblcb = &knl_schedtblcb_table[i];
        QueInit(&schedtblcb->tblque);
        schedtblcb->status = SCHEDULETABLE_STOPPED;
        // TODO: process autostart
    }
}

EXPORT void knl_signal_schedule_table(SCHEDTBLCB* schedtblcb,CCB* ccb)
{
    const T_GSCHEDTBL* gschedtbl;
    TickType max;
    uint8 index;
    gschedtbl = &knl_gschedtbl_table[schedtblcb - knl_schedtblcb_table];

    index = schedtblcb->index;
    /* do the action of expiry point */
    gschedtbl->table[index].action();
    if((index + 1) < gschedtbl->length)
    {
        index++;
    }
    else
    {
        index = 0;
    }

    if(0 == index)              /* the final delay has been processed */
    {
        if(schedtblcb->next !=  INVALID_SCHEDTBL)
        {
            ScheduleTableType next =  schedtblcb->next;
            // stop it firstly
            schedtblcb->status = SCHEDULETABLE_STOPPED;
            #if(cfgAR_SCHEDTBL_QUEUE_METHOD == SCHEDTBL_IN_LOOP)
            QueRemove(&schedtblcb->tblque);
            #endif
            // and then replace it by the next
            schedtblcb =  &knl_schedtblcb_table[next];
            gschedtbl = &knl_gschedtbl_table[next];
            max = knl_almbase_table[ccb - knl_ccb_table].maxallowedvalue;
            schedtblcb->time = knl_add_ticks(ccb->curvalue,gschedtbl->table[0].offset,max*2);
            knl_start_schedule_table(schedtblcb,ccb);
            return;
        }
        else if(gschedtbl->repeatable != TRUE)
        {
            schedtblcb->status = SCHEDULETABLE_STOPPED;
            #if(cfgAR_SCHEDTBL_QUEUE_METHOD == SCHEDTBL_IN_LOOP)
            QueRemove(&schedtblcb->tblque);
            #endif
            return;
        }
        else
        {
            /* do nothing */
        }
    }
    
    schedtblcb->index = index;

    max = knl_almbase_table[ccb - knl_ccb_table].maxallowedvalue;
    schedtblcb->time = knl_add_ticks(ccb->curvalue,gschedtbl->table[index].offset,max*2);
    #if(cfgAR_SCHEDTBL_QUEUE_METHOD == SCHEDTBL_IN_ORDER)
    knl_schedtbl_insert(schedtblcb,ccb);
    #endif
}

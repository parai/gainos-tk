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
#ifndef _OSEK_OS_H_
#define _OSEK_OS_H_
/* ============================ INCLUDEs ========================================== */
#include "Std_Types.h"
#include "Os.h"

/* ============================ TYPEs    ========================================== */

/* ============================ MACROs   ========================================== */
#define DeclareTask(TaskName)  TaskType TaskName
#define TASK(TaskName) void TaskMain##TaskName(void)
#define GenTaskStack(TaskName,stksz)  static uint32 TaskStack##TaskName[stksz/4]

#define GenTaskCreInfo(TaskName,Priority,stksz,Attribute)             \
    {                                                           \
    /* tskque */   {NULL,NULL},                               \
        /* tskid */    ID_##TaskName,                           \
        /* tskatr */   Attribute,                               \
        /* task */     TaskMain##TaskName,                      \
        /* sstksz */   stksz,             \
        /* ipriority */Priority,                                \
        /* priority */ Priority,                                \
        /* klockwait */FALSE,                                   \
        /* klocked */  FALSE,                                   \
        /* state */    TS_NONEXIST,                             \
        /* isstack */  &TaskStack##TaskName[stksz/4-1],               \
            /* resque */   {NULL,NULL}}                                                     
   
                               
#define ALARM(AlarmName)     \
    void AlarmCbk##AlarmName(void)

#define GenResourceCreInfo(cerlpri)             \
    {                                           \
    }
/* ============================ INCLUDEs ========================================== */
#include "osek_cfg.h"
#include "osek_check.h"
 


#endif /* _OSEK_OS_H_ */


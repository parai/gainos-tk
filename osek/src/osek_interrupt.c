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
#include "osek_os.h"


/* |------------------+-------------------------------------------------------------------| */
/* | Syntax:          | void EnableAllInterrupts ( void )                                 | */
/* |------------------+-------------------------------------------------------------------| */
/* | Parameter (In):  | none                                                              | */
/* |------------------+-------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                              | */
/* |------------------+-------------------------------------------------------------------| */
/* | Description:     | This service restores the state saved by DisableAllInterrupts.    | */
/* |------------------+-------------------------------------------------------------------| */
/* | Particularities: | The service may be called from an ISR category 1 and category     | */
/* |                  | 2 and from the task level, but not from hook routines.            | */
/* |                  | This service is a counterpart of DisableAllInterrupts service,    | */
/* |                  | which has to be called before, and its aim is the completion of   | */
/* |                  | the critical section of code. No API service calls are allowed    | */
/* |                  | within this critical section.                                     | */
/* |                  | The implementation should adapt this service to the target        | */
/* |                  | hardware providing a minimum overhead. Usually, this service      | */
/* |                  | enables recognition of interrupts by the central processing unit. | */
/* |------------------+-------------------------------------------------------------------| */
/* | Status:          | Standard:none                                                     | */
/* |                  | Extended:none                                                     | */
/* |------------------+-------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                            | */
/* |------------------+-------------------------------------------------------------------| */
void EnableAllInterrupts( void )
{
}
/* |------------------+--------------------------------------------------------------------| */
/* | Syntax:          | void DisableAllInterrupts ( void )                                 | */
/* |------------------+--------------------------------------------------------------------| */
/* | Parameter (In):  | none                                                               | */
/* |------------------+--------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                               | */
/* |------------------+--------------------------------------------------------------------| */
/* | Description:     | This service disables all interrupts for which the hardware        | */
/* |                  | supports disabling. The state before is saved for the              | */
/* |                  | EnableAllInterrupts call.                                          | */
/* |------------------+--------------------------------------------------------------------| */
/* | Particularities: | The service may be called from an ISR category 1 and category      | */
/* |                  | 2 and from the task level, but not from hook routines.             | */
/* |                  | This service is intended to start a critical section of the code.  | */
/* |                  | This section shall be finished by calling the EnableAllInterrupts  | */
/* |                  | service. No API service calls are allowed within this critical     | */
/* |                  | section.                                                           | */
/* |                  | The implementation should adapt this service to the target         | */
/* |                  | hardware providing a minimum overhead. Usually, this service       | */
/* |                  | disables recognition of interrupts by the central processing unit. | */
/* |                  | Note that this service does not support nesting. If nesting is     | */
/* |                  | needed for critical sections e.g. for libraries                    | */
/* |                  | SuspendOSInterrupts/ResumeOSInterrupts or                          | */
/* |                  | SuspendAllInterrupt/ResumeAllInterrupts should be used.            | */
/* |------------------+--------------------------------------------------------------------| */
/* | Status:          | Standard:none                                                      | */
/* |                  | Extended:none                                                      | */
/* |------------------+--------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                             | */
/* |------------------+--------------------------------------------------------------------| */
void DisableAllInterrupts(void)
{
}

/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | void ResumeAllInterrupts ( void )                                | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     | This service restores the recognition status of all interrupts   | */
/* |                  | saved by the SuspendAllInterrupts service.                       | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | The service may be called from an ISR category 1 and category    | */
/* |                  | 2, from alarm-callbacks and from the task level, but not from    | */
/* |                  | all hook routines.                                               | */
/* |                  | This service is the counterpart of SuspendAllInterrupts service, | */
/* |                  | which has to have been called before, and its aim is the         | */
/* |                  | completion of the critical section of code. No API service       | */
/* |                  | calls beside SuspendAllInterrupts/ResumeAllInterrupts pairs      | */
/* |                  | and SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed     | */
/* |                  | within this critical section.                                    | */
/* |                  | The implementation should adapt this service to the target       | */
/* |                  | hardware providing a minimum overhead.                           | */
/* |                  | SuspendAllInterrupts/ResumeAllInterrupts can be nested. In       | */
/* |                  | case of nesting pairs of the calls SuspendAllInterrupts and      | */
/* |                  | ResumeAllInterrupts the interrupt recognition status saved by    | */
/* |                  | the first call of SuspendAllInterrupts is restored by the last   | */
/* |                  | call of the ResumeAllInterrupts service.                         | */
/* |------------------+------------------------------------------------------------------| */
/* | Status:          | Standard:none                                                    | */
/* |                  | Extended:none                                                    | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
void ResumeAllInterrupts ( void )
{
}

/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | void SuspendAllInterrupts ( void )                               | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     | This service saves the recognition status of all interrupts and  | */
/* |                  | disables all interrupts for which the hardware supports          | */
/* |                  | disabling.                                                       | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | 1.The service may be called from an ISR category 1               | */
/* |                  | and category 2, from alarm-callbacks and from the task level,    | */
/* |                  | but not from all hook routines.                                  | */
/* |                  | 2.This service is intended to protect a critical section of code | */
/* |                  | from interruptions of any kind.                                  | */
/* |                  | 3.This section shall be finished by calling the                  | */
/* |                  | ResumeAllInterrupts service. No API service calls beside         | */
/* |                  | SuspendAllInterrupts/ResumeAllInterrupts pairs and               | */
/* |                  | SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed         | */
/* |                  | within this critical section.                                    | */
/* |                  | 4.The implementation should adapt this service to the target     | */
/* |                  | hardware providing a minimum overhead.                           | */
/* |------------------+------------------------------------------------------------------| */
/* | Status:          | Standard:none                                                    | */
/* |                  | Extended:none                                                    | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
void SuspendAllInterrupts( void )
{
}

/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | void ResumeOSInterrupts ( void )                                 | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     |                                                                  | */
/* |                  | This service restores the recognition status of interrupts       | */
/* |                  | saved by the SuspendOSInterrupts service.                        | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | The service may be called from an ISR category 1 and category    | */
/* |                  | 2 and from the task level, but not from hook routines.           | */
/* |                  | This service is the counterpart of SuspendOSInterrupts service,  | */
/* |                  | which has to have been called before, and its aim is the         | */
/* |                  | completion of the critical section of code. No API service calls | */
/* |                  | beside SuspendAllInterrupts/ResumeAllInterrupts pairs and        | */
/* |                  | SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed         | */
/* |                  | within this critical section.                                    | */
/* |                  | The implementation should adapt this service to the target       | */
/* |                  | hardware providing a minimum overhead.                           | */
/* |                  | SuspendOSInterrupts/ResumeOSInterrupts can be nested. In         | */
/* |                  | case of nesting pairs of the calls SuspendOSInterrupts and       | */
/* |                  | ResumeOSInterrupts the interrupt recognition status saved by     | */
/* |                  | the first call of SuspendOSInterrupts is restored by the last    | */
/* |                  | call of the ResumeOSInterrupts service.                          | */
/* |------------------+------------------------------------------------------------------| */
/* | Status:          | Standard:none                                                    | */
/* |                  | Extended:none                                                    | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
void SuspendOSInterrupts( void )
{
}

/* |------------------+-------------------------------------------------------------------| */
/* | Syntax:          | void SuspendOSInterrupts ( void )                                 | */
/* |------------------+-------------------------------------------------------------------| */
/* | Parameter (In):  | none                                                              | */
/* |------------------+-------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                              | */
/* |------------------+-------------------------------------------------------------------| */
/* | Description:     | This service saves the recognition status of interrupts of        | */
/* |                  | category 2 and disables the recognition of these interrupts.      | */
/* |------------------+-------------------------------------------------------------------| */
/* | Particularities: | The service may be called from an ISR and from the task level,    | */
/* |                  | but not from hook routines.                                       | */
/* |                  | This service is intended to protect a critical section of code.   | */
/* |                  | This section shall be finished by calling the ResumeOSInterrupts  | */
/* |                  | service.No API service calls beside                               | */
/* |                  | SuspendAllInterrupts/ResumeAllInterrupts pairs and                | */
/* |                  | SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed          | */
/* |                  | within this critical section.                                     | */
/* |                  | The implementation should adapt this service to the target        | */
/* |                  | hardware providing a minimum overhead.                            | */
/* |                  | It is intended only to disable interrupts of category 2. However, | */
/* |                  | if this is not possible in an efficient way more interrupts may   | */
/* |                  | be disabled.                                                      | */
/* |------------------+-------------------------------------------------------------------| */
/* | Status:          | Standard:none                                                     | */
/* |                  | Extended:none                                                     | */
/* |------------------+-------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                            | */
/* |------------------+-------------------------------------------------------------------| */
void ResumeOSInterrupts( void )
{

}


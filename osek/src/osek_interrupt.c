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


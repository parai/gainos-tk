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
#include "knl_task.h"
#include "knl_alarm.h"
#include "knl_event.h"
#include "knl_resource.h"
#include "knl_timer.h"
#include "vPort.h"
/* |------------------+------------------------------------------------------| */
/* | Syntax:          | void StartOS ( AppModeType <Mode> )                  | */
/* |------------------+------------------------------------------------------| */
/* | Parameter (In):  | Mode:application mode                                | */
/* |------------------+------------------------------------------------------| */
/* | Parameter (Out): | none                                                 | */
/* |------------------+------------------------------------------------------| */
/* | Description:     | The user can call this system service to start the   | */
/* |                  | operating system in a specific mode, see chapter 5   | */
/* |                  | (os223.doc), Application modes.                      | */
/* |------------------+------------------------------------------------------| */
/* | Particularities: | Only allowed outside of the operating system,        | */
/* |                  | therefore implementation specific restrictions may   | */
/* |                  | apply. See also chapter 11.3, System start-up,       | */
/* |                  | especially with respect to systems where OSEK and    | */
/* |                  | OSEKtime coexist. This call does not need to return. | */
/* |------------------+------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                               | */
/* |------------------+------------------------------------------------------| */
void StartOS ( AppModeType xAppMode )
{
    DISABLE_INTERRUPT;
    knl_cntalm_init();
    knl_entflg_init();
    knl_resource_init();
	knl_task_init();

#if(cfgOS_START_UP_HOOK == 1)
	StartupHook();			/* Call Start up hook */
#endif
    /* OS424: The first call to StartOS() (for starting the Operating System) shall not
       return. */
    knl_timer_init();
    knl_force_dispatch();
}

/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | void ShutdownOS ( StatusType <Error> )                           | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | Error:error occurred                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     | 1.The user can call this system service to abort                 | */
/* |                  | the overall system (e.g. emergency off). The                     | */
/* |                  | operating system also calls this function internally,            | */
/* |                  | if it has reached an undefined internal state and is             | */
/* |                  | no longer ready to run.                                          | */
/* |                  | 2.If a ShutdownHook is configured the hook routine               | */
/* |                  | ShutdownHook is always called (with <Error> as argument)         | */
/* |                  | before shutting down the operating system.                       | */
/* |                  | 3.If ShutdownHook returns, further behaviour of ShutdownOS       | */
/* |                  | is implementation specific.                                      | */
/* |                  | 4.In case of a system where OSEK OS and OSEKtime OS coexist,     | */
/* |                  | ShutdownHook has to return. <Error> needs to be a valid          | */
/* |                  | error code supported by OSEK OS.                                 | */
/* |                  | 5.In case of a system where OSEK OS and OSEKtime OS coexist,     | */
/* |                  | <Error> might also be a value accepted by OSEKtime OS.           | */
/* |                  | In this case, if enabled by an OSEKtime configuration parameter, | */
/* |                  | OSEKtime OS will be shut down after OSEK OS shutdown.            | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | After this service the operating system is shut down.            | */
/* |                  | Allowed at task level, ISR level, in ErrorHook and StartupHook,  | */
/* |                  | and also called internally by the operating system.              | */
/* |                  | If the operating system calls ShutdownOS it never uses E_OK      | */
/* |                  | as the passed parameter value.                                   | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
void ShutdownOS( StatusType xError )
{
#if (cfgOS_SHUT_DOWN_HOOK == 1)
	ShutdownHook(xError);
#endif
/* OS425: If ShutdownOS() is called and ShutdownHook() returns then the operating
   system shall disable all interrupts and enter an endless loop. */
	/* tm_printf("Shut down OS because of error %d.\r\n",xError); */
	for ( ; ; )
    {
        /* Dead lopp here */
    }

}

#if (defined(CHIP_MC9S12) || defined(CHIP_MPC54XX) || (cfgCORTEX_M3_ISR ==  ISR_IN_C))
/* This only works OK for s12cpuv2 and e200z3. 
 * For Arm Cortex M3, terrible. So I move them to vPortS.S */
void EnterISR(void)
{
    knl_taskindp++;/* Enter Task Independedt Part */
    ENABLE_INTERRUPT;
}

void ExitISR(void)
{
    DISABLE_INTERRUPT;
    if(knl_taskindp > 0)
    {
        knl_taskindp--;
    }
    if((0 == knl_taskindp)&&
       (!knl_dispatch_disabled))
    {
        if(knl_ctxtsk != knl_schedtsk)
        {
            knl_isr_dispatch();
        }
    }
    ENABLE_INTERRUPT;
}
#endif

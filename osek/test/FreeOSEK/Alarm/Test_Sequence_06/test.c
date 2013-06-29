/** \brief Free OSEK Conformance Test for the Alarms, Test Sequence 6
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_al_06.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_AL Alarms
 ** @{ */
/** \addtogroup FreeOSEK_CT_AL_06 Test Sequence 6
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090420 v0.1.0 MaCe initial version based on old moduletest
 */

/*==================[inclusions]=============================================*/
#include "os.h"				/* include os header file */
#include "test.h"	/* include test header file */
#include "ctest.h"			/* include ctest header file */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
const uint32 SequenceCounterOk = MAX_SEQUENCE;

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

TASK(Task1)
{
	StatusType ret;
	EventMaskType EventMask;
	TaskStateType TaskState;

	Sequence(0);
	ret = ActivateTask(Task2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(1);
	ret = SetRelAlarm(Alarm1, 1, 0);
	ASSERT(OTHER, ret != E_OK);

	Sequence(2);
	/* \treq AL_33 nm B1B2E1E2 se Expiration of alarm wich sets an event
	 * while running task is non-preemptive. Task which owns the event is not
	 * waiting for this event and not suspended
	 *
	 * \result Event is set
	 */
	IncAlarmCounter();
	ASSERT(AL_33, 0);

	Sequence(3);
	ret = GetEvent(Task2, &EventMask);
	ASSERT(OTHER, ret != E_OK);
	ASSERT(OTHER, EventMask != Event1);

	Sequence(4);
	ret = Schedule();
	ASSERT(OTHER, ret != E_OK);

	Sequence(7);
	ret = SetRelAlarm(Alarm1, 1, 0);
	ASSERT(OTHER, ret != E_OK);

	Sequence(8);
	/* \treq AL_34 nm B1B2E1E2 se Expiration of alarm wich sets an event
	 * while running task is non-preemptive. Task which owns the event is
	 * waiting for this event
	 *
	 * \result Event is set. Task which is owner of the event becomes ready.
	 * No preemption of running task
	 */
	IncAlarmCounter();
	ASSERT(AL_34, 0);

	Sequence(9);
	ret = GetTaskState(Task2, &TaskState);
	ASSERT(OTHER, ret != E_OK);
	ASSERT(OTHER, TaskState != READY);

	Sequence(10);
	TerminateTask();
}

TASK(Task2)
{
	StatusType ret;

	Sequence(5);
	ret = ClearEvent(Event1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(6);
	ret = WaitEvent(Event1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(11);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

/* This task is not used, only to change the scheduling police */
TASK(Task3)
{
	TerminateTask();
}
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/




/** \brief Free OSEK Conformance Test for the Task Managment, Test Sequence 5
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_tm_05.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM_05 Test Sequence 5
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090413 v0.1.0 MaCe initial version
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

TASK(Task1)
{
	StatusType ret;
	
	Sequence(0);
	/* \treq TM_07 mf E1E2 se Call ActivateTask() from preemptive task on
	 * suspended extended task which has higher priority than the running
	 * task
	 *
	 * \result Running task is preempted. Activated tasks becomes running and
	 * its events are cleared. Service returns E_OK
	 */
	ret = ActivateTask(Task3);
	ASSERT(TM_07, ret != E_OK);
	
	Sequence(7);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

TASK(Task2)
{
	StatusType ret;
	EventMaskType event;

	Sequence(5);
	ret = GetEvent(Task2, &event);
	ASSERT(OTHER, ret != E_OK);
	ASSERT(OTHER, event != 0);

	Sequence(6);
	TerminateTask();
}

TASK(Task3)
{
	StatusType ret;
	EventMaskType event;

	Sequence(1);
	ret = GetEvent(Task3, &event);
	ASSERT(OTHER, ret != E_OK);
	ASSERT(OTHER, event != 0);

	Sequence(2);
	/* \treq TM_08 mf E1E2 se Call ActivateTask() from preemptive task on
	 * suspended extended task which has lower priority than the running
	 * task
	 *
	 * \result No preemption of running task. Activated tasks becomes ready and
	 * its events are cleared. Service returns E_OK
	 */
	ret = ActivateTask(Task2);
	ASSERT(TM_08, ret != E_OK);
	Sequence(3);
	ret = GetEvent(Task2, &event);
	ASSERT(TM_08, ret != E_OK);
	ASSERT(TM_08, event != 0);

	Sequence(4);
	TerminateTask();
}

/* This task is not used, only to change the scheduling police */
TASK(Task4)
{
	TerminateTask();
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


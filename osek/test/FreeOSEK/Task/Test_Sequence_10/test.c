

/** \brief Free OSEK Conformance Test for the Task Managment, Test Sequence 10
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_tm_10.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM_10 Test Sequence 10
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090412 v0.1.0 MaCe initial version
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

	Sequence(0);
	ret = ActivateTask(Task2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(6);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

TASK(Task2)
{
	StatusType ret;
	EventMaskType EventMask;

	Sequence(1);
	GetEvent(Task1, &EventMask);
	ASSERT(OTHER, EventMask != 0);
	ASSERT(OTHER, ret != E_OK);
	
	Sequence(2);
	/* \treq TM_09 mf E2 s,e Call ActivateTask() from preemptive
	 * task on suspended extended task which has equal priority as running task
	 *
	 * \result Non preemption of running task. Activated task becomes ready and its
	 * events are cleared. Service returns E_OK
	 */
	ret = ActivateTask(Task3);
	ASSERT(TM_09, ret != E_OK);

	Sequence(3);	
	TerminateTask();
}

TASK(Task3)
{
	StatusType ret;
	EventMaskType EventMask;

	Sequence(4);
	GetEvent(Task3, &EventMask);
	ASSERT(OTHER, EventMask != 0);
	ASSERT(OTHER, ret != E_OK);

	Sequence(5);
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


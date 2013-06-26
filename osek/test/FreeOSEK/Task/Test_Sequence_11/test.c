
/** \brief Free OSEK Conformance Test for the Task Managment, Test Sequence 11
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_tm_11.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM_11 Test Sequence 11
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090414 v0.1.0 MaCe initial version
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

	Sequence(2);
	ret = ActivateTask(Task3);
	ASSERT(OTHER, ret != E_OK);

#if (CT_SCHEDULING_Task1 == CT_NON_PREEMPTIVE)
	/* force scheduling */
	Schedule();
#endif /* #if (CT_SCHEDULING_Task1 == CT_NON_PREEMPTIVE) */

	Sequence(8);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

TASK(Task2)
{
	StatusType ret;

	Sequence(0);
	ret = ActivateTask(Task1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(1);
	ret = WaitEvent(Event2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(7);	
	TerminateTask();
}

TASK(Task3)
{
	StatusType ret;

	Sequence(3);
	ret = ActivateTask(Task4);
	ASSERT(OTHER, ret != E_OK);

#if (CT_SCHEDULING_Task3 == CT_NON_PREEMPTIVE)
	/* force scheduling */
	Schedule();
#endif /* #if (CT_SCHEDULING_Task3 == CT_NON_PREEMPTIVE) */

	Sequence(6);
	TerminateTask();
}

TASK(Task4)
{
	StatusType ret;

	Sequence(4);
	ret = SetEvent(Task2, Event2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(5);
	TerminateTask();
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


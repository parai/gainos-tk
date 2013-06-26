
/** \brief Free OSEK Conformance Test for the Task Managment, Test Sequence 13
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_tm_13.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM_13 Test Sequence 13
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

	Sequence(0);
	ret = ActivateTask(Task2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(1);
	ret = ActivateTask(Task3);
	ASSERT(OTHER, ret != E_OK);

	Sequence(2);
	ret = ActivateTask(Task4);
	ASSERT(OTHER, ret != E_OK);

	Sequence(3);
	ret = ActivateTask(Task5);
	ASSERT(OTHER, ret != E_OK);

	Sequence(4);
	ret = ActivateTask(Task6);
	ASSERT(OTHER, ret != E_OK);

	Sequence(5);
	ret = ActivateTask(Task7);
	ASSERT(OTHER, ret != E_OK);

	Sequence(6);
	ret = ActivateTask(Task8);
	ASSERT(OTHER, ret != E_OK);

	Sequence(7);
	TerminateTask();
}

TASK(Task2)
{
	Sequence(8);
	TerminateTask();
}

TASK(Task3)
{
	Sequence(9);
	TerminateTask();
}

TASK(Task4)
{
	Sequence(10);
	TerminateTask();
}

TASK(Task5)
{
	Sequence(11);
	TerminateTask();
}

TASK(Task6)
{
	Sequence(12);
	TerminateTask();
}

TASK(Task7)
{
	Sequence(13);
	TerminateTask();
}

TASK(Task8)
{
	Sequence(14);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


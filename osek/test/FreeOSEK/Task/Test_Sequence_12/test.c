

/** \brief Free OSEK Conformance Test for the Task Managment, Test Sequence 12
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_tm_12.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM_12 Test Sequence 12
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
	ret = ActivateTask(Task2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(3);
	ret = ActivateTask(Task2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(4);
	ret = ActivateTask(Task3);
	ASSERT(OTHER, ret != E_OK);

	Sequence(5);
	ret = ActivateTask(Task3);
	ASSERT(OTHER, ret != E_OK);

	Sequence(6);
	TerminateTask();

}

TASK(Task2)
{
	static uint8 count = 0;

	switch (count)
	{
		case 0:
			/* increment task call counter */
			count++;

			Sequence(7);
			TerminateTask();
			break;
		case 1:
			/* increment task call counter */
			count++;

			Sequence(9);
			TerminateTask();
			break;
		case 2:
			/* increment task call counter */
			count++;

			Sequence(10);
			TerminateTask();
			break;
		default:
			while(1);
			break;
	}
}

TASK(Task3)
{
	static uint8 count = 0;

	switch (count)
	{
		case 0:
			/* increment task call counter */
			count++;

			Sequence(8);
			TerminateTask();
			break;
		case 1:
			/* increment task call counter */
			count++;

			Sequence(11);
			TerminateTask();
			break;
		case 2:
			/* increment task call counter */
			count++;

			Sequence(12);

			/* evaluate conformance tests */
			ConfTestEvaluation();

			/* finish the conformance test */
			ConfTestFinish();
			break;
		default:
			while(1);
			break;
	}
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/



/** \brief Free OSEK Conformance Test for the Task Managment, Test Sequence 7
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_tm_07.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM Task Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_TM_07 Test Sequence 7
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090409 v0.1.0 MaCe initial version
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
	static uint8 count = 0;

	switch (count)
	{
		case 0:
			/* increment task call counter */
			count++;

			Sequence(0);
			ret = ActivateTask(Task2);
			ASSERT(OTHER, ret != E_OK);

			Sequence(1);
			/* \treq TM_12 nm B1B2 s,e Call ActivateTask() from non-preemptive
			 * task on ready basic task which has not reached max number of
			 * activations
			 *
			 * \result Non preemption of running task. Activation request is
			 * queued in ready list. Service returns E_OK
			 */
			ret = ActivateTask(Task2);
			ASSERT(TM_12, ret != E_OK);

			Sequence(2);
			ret = Schedule();
			ASSERT(OTHER, ret != E_OK);

			Sequence(5);
			/* \treq TM_17 nm B1B2 s,e Call ActivateTask() from non-preemptive
			 * task on running basic task which has not reached max number of
			 * activations
			 *
			 * \result Non preemption of running task. Activation request is
			 * queued in ready list. Service returns E_OK
			 */
			ret = ActivateTask(Task1);
			ASSERT(TM_17, ret != E_OK);

			Sequence(6);
			ret = ActivateTask(Task3);
			ASSERT(OTHER, ret != E_OK);

			Sequence(7);
			/* \treq TM_32 nm B1B2 s,e Call ChainTask() from non-preemptive
			 * task on ready basic task which has not reached max number of
			 * activations
			 *
			 * \result Running task is terminated. Activation request is
			 * queued in ready list and ready task with highst priority is
			 * executed
			 */
			ASSERT(TM_32, 0);
			ret = ChainTask(Task3);
			ASSERT(TM_32, 1);
			break;
		case 1:
			/* increment task call counter */
			count++;
			Sequence(10);
			ret = ActivateTask(Task1);
			ASSERT(OTHER, ret != E_OK);

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

TASK(Task2)
{
	static uint32 seq = 2;

	seq++;
	Sequence(seq);
	TerminateTask();
}

TASK(Task3)
{
	static uint32 seq = 7;

	seq++;
	Sequence(seq);
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


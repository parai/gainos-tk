/** \brief Free OSEK Conformance Test for the Resource Managment, Test Sequence 5
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_rm_05.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_RM Resource Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_RM_05 Test Sequence 5
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090414 v0.1.0 MaCe initial version based on old moduletest
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
	/* enable interrupts ISR2 and ISR3 */
	/* nothing to do */

	Sequence(1);
	/* \treq RM_02 nmf B1B2E1E2 e Call GetResource() from a task with invalid
	 * resource ID
	 *
	 * \result Service returns E_OS_ID
	 */
	ret = GetResource(INVALID_RESOURCE);
	ASSERT(RM_02, ret != E_OS_ID);

	Sequence(2);
	/*  trigger ISR 2 */
	TriggerISR2();

#if ( ISR_CATEGORY_3 == ENABLE )
	/* trigger ISR 3 */
	TriggerISR3();
#endif /* #if ( ISR_CATEGORY_3 == ENABLE ) */

	Sequence(5);
	/* \treq RM_12 nmf B1B2E1E2 e Call ReleaseResource() from a task with a resource
	 * which is not occupied
	 *
	 * \result Service returns E_OS_NOFUNC
	 */
	ret = ReleaseResource(Resource1);
	ASSERT(RM_12, ret != E_OS_NOFUNC);
	
	Sequence(6);
	/* \treq RM_09 nmf B1B2E1E2 e Call ReleaseResource() from a task with an
	 * invalid resource ID
	 *
	 * \result Service returns E_OS_ID
	 */
	ret = ReleaseResource(INVALID_RESOURCE);
	ASSERT(RM_09, ret != E_OS_ID);

	ASSERT(OTHER, 0);

	Sequence(7);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

/* This task is not used, only to change the scheduling police */
TASK(Task2)
{
	while(1);
	TerminateTask();
}

ISR(ISR2)
{
	StatusType ret;

	Sequence(3);
	/* \treq RM_03 nmf B1B2E1E2 e Call GetResource() from ISR category 2
	 *
	 * \result Service returns E_OS_CALLEVEL
	 */
	ret = GetResource(Resource1);
	ASSERT(RM_03, ret != E_OS_CALLEVEL);

	Sequence(4);
	/* \treq RM_10 nmf B1B2E1E2 e Call ReleaseResource() from ISR category 2
	 *
	 * \result Service returns E_OS_CALLEVEL
	 */
	ret = ReleaseResource(Resource1);
	ASSERT(RM_10, ret != E_OS_CALLEVEL);
}

#if ( ISR_CATEGORY_3 == ENABLE )
ISR(ISR3)
{
	StatusType ret;

	EnterISR();

	/* ISR3 are not supported by FreeOSEK OS*/

	LeaveISR();
}
#endif /* #if ( ISR_CATEGORY_3 == ENABLE ) */

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


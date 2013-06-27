/** \brief Free OSEK Conformance Test for the Resource Managment, Test Sequence 1
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_rm_01.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_RM Resource Management
 ** @{ */
/** \addtogroup FreeOSEK_CT_RM_01 Test Sequence 1
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
//for this test,the oil_adapter.py is really not that smart,
//so you should modify the config file by hand
//---parai
TASK(Task1)
{
	StatusType ret;

	Sequence(0);
	/* enable interrupts ISR2 and ISR3 */
	/* nothing to do */

	Sequence(1);
	/* \treq RM_01 nmf B1B2E1E2 e Call GetResource() from a task which has no
	 * access to this resource
	 *
	 * \result Service returns E_OS_ACCESS
	 */
	 //for gainos-tk,this was not supported.
	//ret = GetResource(ResourceA);
	//ASSERT(RM_01, ret != E_OS_ACCESS);

	Sequence(2);
	/* \treq RM_02 nmf B1B2E1E2 e Call GetResource() from a task with invalid
	 * resource ID
	 *
	 * \result Service returns E_OS_ID
	 */
	ret = GetResource(INVALID_RESOURCE);
	ASSERT(RM_02, ret != E_OS_ID);

	Sequence(3);
	ret = GetResource(Resource1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(4);
	ret = GetResource(Resource2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(5);
	ret = GetResource(Resource3);
	ASSERT(OTHER, ret != E_OK);

	Sequence(6);
	ret = GetResource(Resource4);
	ASSERT(OTHER, ret != E_OK);

	Sequence(7);
	ret = GetResource(Resource5);
	ASSERT(OTHER, ret != E_OK);

	Sequence(8);
	/* \treq RM_05 nmf B1B2E1E2 e Call GetResource() from a task with too many
	 * resources occupied in parallel. This req do not affect FreeOSEK whera upto 32
	 * resources can be occupied by a task
	 *
	 * \result Service returns E_OK
	 */
	ret = GetResource(Resource6);
	ASSERT(RM_05, ret != E_OK);

	Sequence(9);
	ret = ReleaseResource(Resource6);
	ASSERT(OTHER, ret != E_OK);

	Sequence(10);
	ret = ReleaseResource(Resource5);
	ASSERT(OTHER, ret != E_OK);

	Sequence(11);
	ret = ReleaseResource(Resource4);
	ASSERT(OTHER, ret != E_OK);

	Sequence(12);
	ret = ReleaseResource(Resource3);
	ASSERT(OTHER, ret != E_OK);

	Sequence(13);
	ret = ReleaseResource(Resource2);
	ASSERT(OTHER, ret != E_OK);

	Sequence(14);
	ret = ReleaseResource(Resource1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(15);
	/*  trigger ISR 2 */
	TriggerISR2();

#if ( ISR_CATEGORY_3 == ENABLE )
	/* trigger ISR 3 */
	TriggerISR3();
#endif /* #if ( ISR_CATEGORY_3 == ENABLE ) */

	Sequence(18);
	/* \treq RM_12 nmf B1B2E1E2 e Call ReleaseResource() from a task with a resource
	 * which is not occupied
	 *
	 * \result Service returns E_OS_NOFUNC
	 */
	ret = ReleaseResource(Resource1);
	ASSERT(RM_12, ret != E_OS_NOFUNC);
	
	Sequence(19);
	/* \treq RM_09 nmf B1B2E1E2 e Call ReleaseResource() from a task with an
	 * invalid resource ID
	 *
	 * \result Service returns E_OS_ID
	 */
	ret = ReleaseResource(INVALID_RESOURCE);
	ASSERT(RM_09, ret != E_OS_ID);

	Sequence(20);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

TASK(Task2)
{
	while(1);
	TerminateTask();
}

ISR(ISR2)
{
	StatusType ret;
	EnterISR();
	Sequence(16);
	/* \treq RM_03 nmf B1B2E1E2 e Call GetResource() from ISR category 2
	 *
	 * \result Service returns E_OS_CALLEVEL
	 */
	ret = GetResource(Resource1);
	ASSERT(RM_03, ret != E_OS_CALLEVEL);

	Sequence(17);
	/* \treq RM_10 nmf B1B2E1E2 e Call ReleaseResource() from ISR category 2
	 *
	 * \result Service returns E_OS_CALLEVEL
	 */
	ret = ReleaseResource(Resource1);
	ASSERT(RM_10, ret != E_OS_CALLEVEL);
	LeaveISR();
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


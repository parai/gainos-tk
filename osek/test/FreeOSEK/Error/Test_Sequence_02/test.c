
/** \brief Free OSEK Conformance Test for the Error Handling, Test Sequence 2
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_eh_02.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_EH Error Handling
 ** @{ */
/** \addtogroup FreeOSEK_CT_EH_02 Test Sequence 2
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090418 v0.1.0 MaCe initial version based on old moduletest
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

void ShutdownHook(void)
{
	Sequence(2);
	/* \treq EH_07 nmf B1B2E1E2 se CheckShutdownHook: ShutdownOS
	 *
	 * \result ShutdowHook is called after os shutdown
	 * 
	 */
	ASSERT(EH_07,0);

	Sequence(3);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

TASK(Task1)
{
	AppModeType Mode;

	ASSERT(OTHER, 0);

	Sequence(0);
	/* \treq EH_01 nmf B1B2E1E2 se Call GetActiveApplicationMode()
	 *
	 * \result Return current application mode
	 */
	(void)GetActiveApplicationMode(&Mode);
	ASSERT(EH_01, Mode != OSDEFAULTAPPMODE);

	Sequence(1);
	/* \treq EH_03 nmf B1B2E1E2 se Call ShutdownOS()
	 * Force error
	 *
	 * \result Shutdown operating system
	 */
	ASSERT(EH_03, 0);
	ShutdownOS(E_OK);
	ASSERT(EH_03, 1);
}

/* This task is not used, only to change the scheduling police */
TASK(Task2)
{
	TerminateTask();
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


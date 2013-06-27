
/** \brief Free OSEK Conformance Test for the Error Handling, Test Sequence 1
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_eh_01.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_EH Error Handling
 ** @{ */
/** \addtogroup FreeOSEK_CT_EH_01 Test Sequence 1
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090417 v0.1.0 MaCe initial version based on old moduletest
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

void StartupHook(void)
{
	StatusType ret;

	Sequence(0);
	/* \treq EH_06 nmf B1B2E1E2 se Check StartupHook: Start OS
	 *
	 * \result StartupHook is called after initialisation of OS
	 */
	ret = ActivateTask(Task1);
	ASSERT(EH_06, ret != E_OK);
}

void PreTaskHook(void)
{
	static uint8 count = 0;
	StatusType ret;
	TaskType TaskID;
	TaskStateType TaskState;

	switch (count)
	{
		case 0:
			/* increment pre task hook call count */
			count++;

			Sequence(1);
			/* \treq EH_04 nmf B1B2E1E2 se Check PreTaskHook/PostTaskHook:
			 * Force rescheduling
			 *
			 * \result PreTaskHook is called before executing the new task,
			 * but after the transition to running state. PostTaskHook is called
			 * after existing the current task but before leaving the task's
			 * running state.
			 */
			ret = GetTaskID(&TaskID);
			ASSERT(EH_04, ret != E_OK);
			ASSERT(EH_04, TaskID != Task1);

			Sequence(2);
			ret = GetTaskState(Task1, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != RUNNING);

			Sequence(3);
			ret = GetTaskState(Task2, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != SUSPENDED);
			break;
		case 1:
			/* increment pre task hook call count */
			count++;

			Sequence(8);
			/* \treq EH_04 nmf B1B2E1E2 se Check PreTaskHook/PostTaskHook:
			 * Force rescheduling
			 *
			 * \result PreTaskHook is called before executing the new task,
			 * but after the transition to running state. PostTaskHook is called
			 * after existing the current task but before leaving the task's
			 * running state.
			 */
			ret = GetTaskID(&TaskID);
			ASSERT(EH_04, ret != E_OK);
			ASSERT(EH_04, TaskID != Task2);

			Sequence(9);
			ret = GetTaskState(Task1, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != READY);

			Sequence(10);
			ret = GetTaskState(Task2, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != RUNNING);
			break;
		case 2:
			/* increment pre task hook call count */
			count++;

			Sequence(17);
			/* \treq EH_04 nmf B1B2E1E2 se Check PreTaskHook/PostTaskHook:
			 * Force rescheduling
			 *
			 * \result PreTaskHook is called before executing the new task,
			 * but after the transition to running state. PostTaskHook is called
			 * after existing the current task but before leaving the task's
			 * running state.
			 */
			ret = GetTaskID(&TaskID);
			ASSERT(EH_04, ret != E_OK);
			ASSERT(EH_04, TaskID != Task1);

			Sequence(18);
			ret = GetTaskState(Task1, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != RUNNING);

			Sequence(19);
			ret = GetTaskState(Task2, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != SUSPENDED);
			break;
		default:
			while(1);
			break;
	}
}

void PostTaskHook(void)
{
	static uint8 count = 0;
	StatusType ret;
	TaskType TaskID;
	TaskStateType TaskState;

	switch (count)
	{
		case 0:
			/* increment post task hook call count */
			count++;

			Sequence(5);
			/* \treq EH_04 nmf B1B2E1E2 se Check PreTaskHook/PostTaskHook:
			 * Force rescheduling
			 *
			 * \result PreTaskHook is called before executing the new task,
			 * but after the transition to running state. PostTaskHook is called
			 * after existing the current task but before leaving the task's
			 * running state.
			 */
			ret = GetTaskID(&TaskID);
			ASSERT(EH_04, ret != E_OK);
			ASSERT(EH_04, TaskID != Task1);

			Sequence(6);
			ret = GetTaskState(Task1, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != RUNNING);

			Sequence(7);
			ret = GetTaskState(Task2, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != READY);
			break;
		case 1:
			/* increment post task hook call count */
			count++;

			Sequence(14);
			/* \treq EH_04 nmf B1B2E1E2 se Check PreTaskHook/PostTaskHook:
			 * Force rescheduling
			 *
			 * \result PreTaskHook is called before executing the new task,
			 * but after the transition to running state. PostTaskHook is called
			 * after existing the current task but before leaving the task's
			 * running state.
			 */
			ret = GetTaskID(&TaskID);
			ASSERT(EH_04, ret != E_OK);
			ASSERT(EH_04, TaskID != Task2);

			Sequence(15);
			ret = GetTaskState(Task1, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != READY);

			Sequence(16);
			ret = GetTaskState(Task2, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != RUNNING);
			break;
		case 2:
			/* increment post task hook call count */
			count++;

			Sequence(21);
			/* \treq EH_04 nmf B1B2E1E2 se Check PreTaskHook/PostTaskHook:
			 * Force rescheduling
			 *
			 * \result PreTaskHook is called before executing the new task,
			 * but after the transition to running state. PostTaskHook is called
			 * after existing the current task but before leaving the task's
			 * running state.
			 */
			ret = GetTaskID(&TaskID);
			ASSERT(EH_04, ret != E_OK);
			ASSERT(EH_04, TaskID != Task1);

			Sequence(22);
			ret = GetTaskState(Task1, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != RUNNING);

			Sequence(23);
			ret = GetTaskState(Task2, &TaskState);
			ASSERT(OTHER, ret != E_OK);
			ASSERT(OTHER, TaskState != SUSPENDED);

			Sequence(24);

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

void ErrorHook(void)
{
	Sequence(12);
	/* \treq EH_05 nmf B1B2E1E2 se Check ErrorHook:
	 * Force error
	 *
	 * \result Errorhook is called at the end of a system service which has a
	 * return value not equal to E_OK
	 * 
	 */
	ASSERT(EH_05,0);
}

TASK(Task1)
{
	StatusType ret;

	Sequence(4);
	ret = ActivateTask(Task2);
	ASSERT(OTHER, ret != E_OK);

#if (CT_SCHEDULING_Task1 == CT_NON_PREEMPTIVE)
	/* force scheduling */
	Schedule();
#endif /* #if (CT_SCHEDULING_TASK1 == CT_NON_PREEMPTIVE) */

	Sequence(20);
	TerminateTask();
}

TASK(Task2)
{
	StatusType ret;
	TickType Tick;

	Sequence(11);
	ret = GetAlarm(Alarm1, &Tick);
	ASSERT(OTHER, ret != E_OS_NOFUNC);

	Sequence(13);
	TerminateTask();
}

ALARM(Alarm1)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(Task2);
}
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/


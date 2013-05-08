  
/** 
 * FILE: Exceptions.c
 *
 *  DESCRIPTION: Setup of IVPR to point to the EXCEPTION_HANDLERS memory area 
 *               defined in the linker command file.
 *               Default setup of the IVORxx registers. 
*/


/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/

#include "Exceptions.h" /* Implement functions from this file */

/*----------------------------------------------------------------------------*/
/* Function Implementations                                                   */
/*----------------------------------------------------------------------------*/

#pragma push /* Save the current state */
/* Symbol EXCEPTION_HANDLERS is defined in the application linker command file (.lcf) 
   It is defined to the start of the code memory area used for the .__exception_handlers section. 
*/
/*lint -esym(752, EXCEPTION_HANDLERS) */
__declspec (section ".__exception_handlers") extern long EXCEPTION_HANDLERS;  
#pragma force_active on
#pragma function_align 16 /* We use 16 bytes alignment for Exception handlers */
__declspec(interrupt)
__declspec (section ".__exception_handlers")
void EXCEP_CriticalInputHandler(void)
{
	for(;;);
}
void EXCEP_MachineCheckHandler(void)
{
	for(;;);
}
void EXCEP_DataStorageHandler(void)
{
	for(;;);
}
void EXCEP_InstructionStorageHandler(void)
{
	for(;;);
}
void EXCEP_ExternalInputHandler(void)
{
	for(;;);
}
void EXCEP_AlignmentHandler(void)
{
	for(;;);
}
void EXCEP_ProgramHandler(void)
{
	for(;;);
}
void EXCEP_FloatingPointUnavailableHandler(void)
{
	for(;;);
}
void EXCEP_AuxiliaryProcessorHandler(void)
{
	for(;;);
}
void EXCEP_FixedIntervalTimerHandler(void)
{
	for(;;);
}
void EXCEP_WatchDogTimerHandler(void)
{
	for(;;);
}
void EXCEP_DataTlbErrorHandler(void)
{
	for(;;);
}
void EXCEP_InstructionTlbErrorHandler(void)
{
	for(;;);
}
void EXCEP_DebugHandler(void)
{
	for(;;);
}
void EXCEP_SPE_APU_UnavailableHandler(void)
{
	for(;;);
}
void EXCEP_SPEFloatingPointDataHandler(void)
{
	for(;;);
}
void EXCEP_SPEFloatingPointRoundHandler(void)
{
	for(;;);
}
void EXCEP_SystemCallHandler(void)
{
	for(;;);
}
void EXCEP_DecrementerHandler(void)
{
	for(;;);
}
#pragma force_active off
#pragma pop

__asm void EXCEP_InitExceptionHandlers(void)
{
nofralloc
 /* Set the IVPR to the Exception Handlers memory area defined in the lcf file */ 
    lis     r0, EXCEPTION_HANDLERS@h
    ori     r0, r0, EXCEPTION_HANDLERS@l
    mtivpr  r0
    
#if !defined(Z0H_CORE)
    /* IVORx registers are "hard-wired" in the e200z0 and z0h cores */

    /* IVOR0 Critical input (SPR 400) */
	lis     r0, EXCEP_CriticalInputHandler@h
	ori     r0, r0, EXCEP_CriticalInputHandler@l
    mtivor0 r0
    /* IVOR1 Machine check interrupt (SPR 401) */
    lis     r0, EXCEP_MachineCheckHandler@h
	ori     r0, r0, EXCEP_MachineCheckHandler@l
    mtivor1 r0
    /* IVOR2 Data storage interrupt (SPR 402) */
    lis     r0, EXCEP_DataStorageHandler@h
	ori     r0, r0, EXCEP_DataStorageHandler@l
    mtivor2 r0
    /* IVOr0 Instruction storage interrupt (SPR 403) */
    lis     r0, EXCEP_InstructionStorageHandler@h
	ori     r0, r0, EXCEP_InstructionStorageHandler@l
    mtivor0 r0
    /* IVOR4 External input interrupt (SPR 404) */
    lis     r0, EXCEP_ExternalInputHandler@h
	ori     r0, r0, EXCEP_ExternalInputHandler@l
    mtivor4 r0
    /* IVOR5 Alignment interrupt (SPR 405) */
    lis     r0, EXCEP_AlignmentHandler@h
	ori     r0, r0, EXCEP_AlignmentHandler@l
    mtivor5 r0
    /* IVOR6 Program interrupt (SPR 406) */
    lis     r0, EXCEP_ProgramHandler@h
	ori     r0, r0, EXCEP_ProgramHandler@l
    mtivor6 r0
    /* IVOR7 Floating-point unavailable interrupt (SPR 407) */
    lis     r0, EXCEP_FloatingPointUnavailableHandler@h
	ori     r0, r0, EXCEP_FloatingPointUnavailableHandler@l
    mtivor7 r0
    /* IVOR8 System call interrupt (SPR 408) */
    lis     r0, EXCEP_SystemCallHandler@h
    ori     r0, r0, EXCEP_SystemCallHandler@l
    mtivor8 r0
    /* IVOR9 Auxiliary processor (SPR 409) */
    lis     r0, EXCEP_AuxiliaryProcessorHandler@h
    ori     r0, r0, EXCEP_AuxiliaryProcessorHandler@l
    mtivor9 r0
    /* IVOR10 Decrementer interrupt (SPR 410) */
    lis     r0, EXCEP_DecrementerHandler@h
    ori     r0, r0, EXCEP_DecrementerHandler@l
    mtivor10 r0    
    /* IVOR11 Fixed-interval timer interrupt (SPR 411) */
    lis     r0, EXCEP_FixedIntervalTimerHandler@h
    ori     r0, r0, EXCEP_FixedIntervalTimerHandler@l
    mtivor11 r0
    /* IVOR12 Watchdog timer interrupt (SPR 412) */
    lis     r0, EXCEP_WatchDogTimerHandler@h
    ori     r0, r0, EXCEP_WatchDogTimerHandler@l
    mtivor12 r0
    /* IVOR13 Data TLB error interrupt (SPR 413) */
    lis     r0, EXCEP_DataTlbErrorHandler@h
    ori     r0, r0, EXCEP_DataTlbErrorHandler@l
    mtivor13 r0        
    /* IVOR14 Instruction TLB error interrupt (SPR 414) */
    lis     r0, EXCEP_InstructionTlbErrorHandler@h
    ori     r0, r0, EXCEP_InstructionTlbErrorHandler@l
    mtivor14 r0   
    /* IVOR15 Debug interrupt (SPR 415) */
    lis     r0, EXCEP_DebugHandler@h
    ori     r0, r0, EXCEP_DebugHandler@l
    mtivor15 r0  
    /* IVOR32 SPE APU unavailable interrupt (SPR 528) */
    lis     r0, EXCEP_SPE_APU_UnavailableHandler@h
    ori     r0, r0, EXCEP_SPE_APU_UnavailableHandler@l
    mtivor32 r0  
    /* IVOR33 SPE floating-point data exception interrupt (SPR 529) */
    lis     r0, EXCEP_SPEFloatingPointDataHandler@h
    ori     r0, r0, EXCEP_SPEFloatingPointDataHandler@l
    mtivor33 r0 
    /* IVOR34 SPE floating-point round exception interrupt (SPR 530) */
    lis     r0, EXCEP_SPEFloatingPointRoundHandler@h
    ori     r0, r0, EXCEP_SPEFloatingPointRoundHandler@l
    mtivor34 r0 

#endif

    blr
}

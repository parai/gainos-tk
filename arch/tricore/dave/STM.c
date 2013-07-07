//****************************************************************************
// @Module        System Timer (STM)
// @Filename      STM.c
// @Project       DAvE_Bsp.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1797
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the STM module.
//
//----------------------------------------------------------------------------
// @Date          2013/5/22 23:25:46
//
//****************************************************************************

// USER CODE BEGIN (STM_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "main.h"

// USER CODE BEGIN (STM_General,2)
#include "Os.h"
// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (STM_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (STM_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (STM_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************


// USER CODE BEGIN (STM_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (STM_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (STM_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (STM_General,9)

// USER CODE END


//****************************************************************************
// @Function      void STM_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the STM function 
//                library. It is assumed that the SFRs used by this library 
//                are in their reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2013/5/22
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void STM_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the Module Clock:
  ///  -----------------------------------------------------------------------
  ///  - enable the STM module
  ///  - Application Reset resets the STM module
  ///  - STM clock is System clock / 2 (= 45.00 MHz; 22.22 ns )

  MAIN_vResetENDINIT();
  STM_CLC.U      = 0x00000200;   // load clock control register
  MAIN_vSetENDINIT();


  ///  -----------------------------------------------------------------------
  ///  STM Resolution And Range:
  ///  -----------------------------------------------------------------------
  ///  STM_TIMER_0     bits 0 ... 31 :
  ///  - resolution = 0.02 us
  ///  - range = 1.59 min

  ///  STM_TIMER_1     bits 4 ... 35 :
  ///  - resolution = 0.36 us
  ///  - range = 25.45 min

  ///  STM_TIMER_2     bits 8 ... 39 :
  ///  - resolution = 5.69 us
  ///  - range = 6.79 h

  ///  STM_TIMER_3     bits 12 ... 43 :
  ///  - resolution = 91.02 us
  ///  - range = 4.52 days

  ///  STM_TIMER_4     bits 16 ... 47 :
  ///  - resolution = 1.46 ms
  ///  - range = 72.40 days

  ///  STM_TIMER_5     bits 20 ... 51 :
  ///  - resolution = 23.30 ms
  ///  - range = 3.17 years

  ///  STM_TIMER_6     bits 32 ... 55 :
  ///  - resolution = 1.59 min
  ///  - range = 50.78 years

  ///  STM_TIMER_7     bits 32 ... 55 :
  ///  - resolution = 1.59 min
  ///  - range = 50.78 years

  ///  -----------------------------------------------------------------------
  ///  STM Compare 0 configuration:
  ///  -----------------------------------------------------------------------
  ///  - lowest bit number of STM which is compared with CMP0 is 7
  ///  - 4 bit(s) in register CMP0 are used for the compare operation with STM
  ///  - required compare value of CMP0 is 0x0000000A
  ///  - real compare value of CMP0 is 0x0000000A
  ///  - request on compare match with CMP0 is enabled and located to STMIR0

  STM_CMP0.U     = 0x0000000A;   // load compare register 0

  ///  -----------------------------------------------------------------------
  ///  STM Compare 1 configuration:
  ///  -----------------------------------------------------------------------
  ///  - lowest bit number of STM which is compared with CMP1 is 7
  ///  - 4 bit(s) in register CMP1 are used for the compare operation with STM
  ///  - required compare value of CMP1 is 0x0000000A
  ///  - real compare value of CMP1 is 0x0000000A
  ///  - request on compare match with CMP1 is enabled and located to STMIR1

  STM_CMP1.U     = 0x0000000A;   // load compare register 1

  STM_CMCON.U    = 0x07030703;   // load compare match control register
  STM_ICR.U      = 0x00000051;   // load interrupt control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used STM Interrupts:
  ///  -----------------------------------------------------------------------
  ///  - SRN0 service request node configuration:
  ///  - SRN0 interrupt priority level (SRPN) = 253
  ///  - SRN0 CPU interrupt is selected

  STM_SRC0.U     = 0x000010FD;   // set service request control register

  ///  - SRN1 service request node configuration:
  ///  - SRN1 interrupt priority level (SRPN) = 252
  ///  - SRN1 CPU interrupt is selected

  STM_SRC1.U     = 0x000010FC;   // set service request control register


  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function STM_vInit


//****************************************************************************
// @Function      void STM_viSRN0(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine 0 of STM. It is 
//                called if the selected compare match is pending.
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2013/5/22
//
//****************************************************************************

// USER CODE BEGIN (SRN0,1)

// USER CODE END

void INTERRUPT (STM_INT0) STM_viSRN0(void)
{
  // USER CODE BEGIN (SRN0,2)
	EnterISR();
  // USER CODE END

  if(STM_ICR.B.CMP0IR == 1)   // if compare match of CMP0 is pending
  {
    // USER CODE BEGIN (SRN0,3)
	  (void)IncrementCounter(0);
    // USER CODE END

    STM_ISRR.B.CMP0IRR = 1;  // clear request bit of CMP0
  }

  // USER CODE BEGIN (SRN0,5)
	ExitISR();
  // USER CODE END

} //  End of function STM_viSRN0


//****************************************************************************
// @Function      void STM_viSRN1(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine 1 of STM. It is 
//                called if the selected compare match is pending.
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2013/5/22
//
//****************************************************************************

// USER CODE BEGIN (SRN1,1)
IMPORT void knl_timer_handler( void );
// USER CODE END

void INTERRUPT (STM_INT1) STM_viSRN1(void)
{
  // USER CODE BEGIN (SRN1,2)
	EnterISR();
  // USER CODE END

  if(STM_ICR.B.CMP1IR == 1)   // if compare match of CMP1 is pending
  {
    // USER CODE BEGIN (SRN1,4)
#if(cfgOS_TK_EXTEND == STD_ON)
	  knl_timer_handler();
#endif
    // USER CODE END

    STM_ISRR.B.CMP1IRR = 1;  // clear request bit of CMP1
  }

  // USER CODE BEGIN (SRN1,5)
  ExitISR();
  // USER CODE END

} //  End of function STM_viSRN1



// USER CODE BEGIN (STM_General,10)

// USER CODE END


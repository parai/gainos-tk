//****************************************************************************
// @Module        Interrupt System (INT)
// @Filename      INT.c
// @Project       DAvE_Bsp.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1797
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the INT module.
//
//----------------------------------------------------------------------------
// @Date          2013/5/16 21:37:27
//
//****************************************************************************

// USER CODE BEGIN (INT_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "main.h"

// USER CODE BEGIN (INT_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (INT_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (INT_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (INT_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (INT_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (INT_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (INT_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (INT_General,9)

// USER CODE END


//****************************************************************************
// @Function      void INT_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the INT function 
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
// @Date          2013/5/16
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void INT_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CPU Interrupts:
  ///  -----------------------------------------------------------------------
  ///  - CPU0 service request node configuration:
  ///  - CPU0 interrupt priority level (SRPN) = 254
  ///  - CPU0 CPU interrupt is selected

  CPU_SRC0.U     = 0x000010FE;   // set service request control register



  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function INT_vInit


//****************************************************************************
// @Function      void INT_viCPU0(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the software 
//                interrupt 0. 
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
// @Date          2013/5/16
//
//****************************************************************************

// USER CODE BEGIN (CPU0,1)

// USER CODE END

void INTERRUPT (CPU0INT) INT_viCPU0(void)
{

  // USER CODE BEGIN (CPU0,2)

  // USER CODE END

} //  End of function INT_viCPU0



// USER CODE BEGIN (INT_General,10)

// USER CODE END


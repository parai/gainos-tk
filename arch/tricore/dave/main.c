//****************************************************************************
// @Module        Project Settings
// @Filename      main.c
// @Project       DAvE_Bsp.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1797
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          2013/5/16 21:37:27
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "main.h"

// USER CODE BEGIN (MAIN_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

#define RESET_INDICATOR     ((SCU_RSTSTAT.U & ((uword)(0x0001001B))))
#define WATCHDOG_RESET      ((uword)0x00000008)
#define SOFTWARE_RESET      ((uword)0x00000010)
#define ESR0_RESET          ((uword)0x00000001)
#define ESR1_RESET          ((uword)0x00000002)
#define POWERON_RESET       ((uword)0x00010000)

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************
volatile unsigned int DummyToForceRead; 

// USER CODE BEGIN (MAIN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
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

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //// -----------------------------------------------------------------------
  //// Begin of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------
  ///  All following settings must be set in the start-up file. You can use 
  ///  DAvE's project file (*.dpt) to include this register values into your 
  ///  compiler EDE.

    ///  ---------------------------------------------------------------------
    ///  System Peripheral Bus Control Unit (SBCU):
    ///  ---------------------------------------------------------------------
    ///  SBCU starvation protection is enabled
    ///  the debug trace is enabled. Error information is captured in 
    ///  register SBCU_EADD, SBCU_EDAT and SBCU_ECON
    ///  sample period of request for starvation protection: 64
    ///  SBCU bus time-out value: 65536 cycles

    //// this register must be set in the start-up file
    //// SBCU_CON.U  = 0x4009FFFF;

    ///  ---------------------------------------------------------------------
    ///  LMB External Bus Unit (EBU):
    ///  ---------------------------------------------------------------------
    ///  - enable the EBU module clock
    ///  - disable EndInit Protection of the CLC Register
    ///  - request EBU to run off input clock divided by 1

    //// this register must be set in the start-up file
    //// EBU_CLC.U  = 0x00010000;

    ///  External Arbitration:
    ///  - EBU is disabled

    //// this register must be set in the start-up file
    //// EBU_MODCON.U  = 0x00000000;

    ///  ---------------------------------------------------------------------
    ///  Data Memory Interface (DMI):
    ///  ---------------------------------------------------------------------
    ///  - No Data Cache
    ///  - 128 Kbyte Data Memory

    //// this register must be set in the start-up file
    //// DMI_CON.U  = 0x08000802;

    ///  ---------------------------------------------------------------------
    ///  Program Memory Interface (PMI):
    ///  ---------------------------------------------------------------------
    ///  - No Instruction Cache
    ///  - 40 Kbyte Program Memory

    //// this register must be set in the start-up file
    //// PMI_CON2.U  = 0x02800284;

  //// -----------------------------------------------------------------------
  //// End of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------

  ///  -----------------------------------------------------------------------
  ///  Clock System:
  ///  -----------------------------------------------------------------------
  ///  - external clock frequency: 20.00 MHz
  ///  - input divider (PDIV): 2
  ///  - PLL operation (VCOBYP = 0)
  ///  - VCO range: 700 MHz - 800 MHz
  ///  - feedback divider (NDIV): 72
  ///  - the VCO output frequency is: 720.00 MHz
  ///  - output divider (KDIV): 4
  ///  - CPU clock: 180.00 MHz
  ///  - the ratio fcpu /ffpi is  2 / 1
  ///  - the ratio fcpu /flmb is  1 / 1
  ///  - the ratio fcpu /fpcp is  1 / 1
  ///  - system clock: 90.00 MHz


    if (!SCU_PLLSTAT.B.PWDSTAT)
    {
      MAIN_vResetENDINIT();
      SCU_CCUCON0.U  = 0x00000001; // set FPI,LMB and PCP dividers
      SCU_PLLCON0.B.VCOBYP  = 1; // set VCO bypass (goto Prescaler Mode)
      //while (!SCU_P/LLSTAT.B.VCOBYST);// wait for prescaler mode
      SCU_PLLCON0.U  = 0x01058E21; // set P,N divider, connect OSC
      SCU_PLLCON1.U  = 0x00020003; // set K1,K2 divider
      MAIN_vSetENDINIT();
      //while (SCU_PLLSTAT.B.VCOLOCK == 0);// wait for LOCK
      MAIN_vResetENDINIT();
      SCU_PLLCON0.B.VCOBYP  = 0; // Reset VCO bypass (Leave Prescaler Mode)
      MAIN_vSetENDINIT();
    }

  ///  -----------------------------------------------------------------------
  ///  Interrupt System:
  ///  -----------------------------------------------------------------------
  ///  - four arbitration cycles (max. 255 interrupt sources)
  ///  - two clocks per arbitration cycle

  MTCR(0xFE2C, 0x00000000);      // load CPU interrupt control register
  ISYNC();

  ///  -----------------------------------------------------------------------
  ///  Peripheral Control Processor (PCP):
  ///  -----------------------------------------------------------------------
  ///  - stop the PCP internal clock when PCP is idle

  ///  - use Full Context save area (R[0] - R[7])
  ///  - start progam counter as left by last invocation
  ///  - channel watchdog is disabled
  ///  - maximum channel number checking is disabled

  MAIN_vResetENDINIT();
  PCP_CLC.U      = 0x00000000;   // load PCP clock control register
  PCP_CS.U       = 0x00000200;   // load PCP control and status register
  MAIN_vSetENDINIT();

  ///  - four arbitration cycles (max. 255 PCP channels)
  ///  - two clocks per arbitration cycle
  PCP_ICR.U      = 0x00000000;   // load PCP interrupt control register

  ///  - the PCP warning mechanism is disabled
  PCP_ITR.U      = 0x00000000;   // load PCP interrupt threshold register

  ///  - type of service of PCP node 4 is CPU interrupt
  PCP_SRC4.U     = 0x00001000;   // load service request control register 4

  ///  - type of service of PCP node 5 is CPU interrupt
  PCP_SRC5.U     = 0x00001000;   // load service request control register 5

  ///  - type of service of PCP node 6 is CPU interrupt
  PCP_SRC6.U     = 0x00001000;   // load service request control register 6

  ///  - type of service of PCP node 7 is CPU interrupt
  PCP_SRC7.U     = 0x00001000;   // load service request control register 7

  ///  - type of service of PCP node 8 is CPU interrupt
  PCP_SRC8.U     = 0x00001000;   // load service request control register 8

  ///  -----------------------------------------------------------------------
  ///  Configuration of the DMA Module Clock:
  ///  -----------------------------------------------------------------------
  ///  - enable the DMA module

  MAIN_vResetENDINIT();
  DMA_CLC.U      = 0x00000008;   // DMA clock control register
  DummyToForceRead  = DMA_CLC.U; // read it back to ensure it is read
  MAIN_vSetENDINIT();

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------
  //   initializes the Interrupt System (INT)
  INT_vInit();

  //   initializes the System Timer (STM)
  STM_vInit();


  // USER CODE BEGIN (Init,3)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  System Start Conditions:
  ///  -----------------------------------------------------------------------

  //// - the CPU interrupt system is globally disabled
  DISABLE();

  //// - the PCP interrupt system is globally disabled


  // USER CODE BEGIN (Init,4)

  // USER CODE END

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vWriteWDTCON0(uword uwValue) 
//
//----------------------------------------------------------------------------
// @Description   This function writes the parameter uwValue to the WDT_CON0 
//                register which is password protected. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    uwValue: 
//                Value for the WDTCON0 register
//
//----------------------------------------------------------------------------
// @Date          2013/5/16
//
//****************************************************************************

// USER CODE BEGIN (WriteWDTCON0,1)

// USER CODE END

void MAIN_vWriteWDTCON0(uword uwValue)
{
  uword uwDummy;

  uwDummy        = WDT_CON0.U;  
  uwDummy |=  0x000000F0;       //  set HWPW1 = 1111b

  if(WDT_CON1.B.DR)
  {
    uwDummy |=  0x00000008;     //  set HWPW0 = WDTDR
  }
  else
  {
    uwDummy &= ~0x00000008;     //  set HWPW0 = WDTDR
  }
  if(WDT_CON1.B.IR)
  {
    uwDummy |=  0x00000004;     //  set HWPW0 = WDTIR
  }
  else
  {
    uwDummy &= ~0x00000004;     //  set HWPW0 = WDTIR
  }

  uwDummy &= ~0x00000002;       //  set WDTLCK = 0
  WDT_CON0.U =  uwDummy;          //  unlock access

  uwValue  |=  0x000000F2;      //  set HWPW1 = 1111b and WDTLCK = 1
  uwValue  &= ~0x0000000C;      //  set HWPW0 = 00b
  WDT_CON0.U  =  uwValue;         //  write access and lock

} //  End of function MAIN_vWriteWDTCON0


//****************************************************************************
// @Function      sword main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns an sword value
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2013/5/16
//
//****************************************************************************

// USER CODE BEGIN (Main,1)
#include "Os.h"
// USER CODE END

sword main(void)
{
  sword swReturn;

  // USER CODE BEGIN (Main,2)

  // USER CODE END

  swReturn = 0;

  switch(RESET_INDICATOR)
  {
    case WATCHDOG_RESET:         //  the last reset was a watchdog triggered
                                 //  (hardware) reset

         // USER CODE BEGIN (Main,3)

         // USER CODE END

    case SOFTWARE_RESET:         //  the last reset was an internally 
                                 //  triggered software reset

         // USER CODE BEGIN (Main,4)

         // USER CODE END

    case ESR0_RESET:             //  the last reset was an externally 
                                 //  triggered hardware reset (#ESR0 pin)

         // USER CODE BEGIN (Main,4.1)

         // USER CODE END

    case ESR1_RESET:             //  the last reset was an externally 
                                 //  triggered hardware reset (#ESR1 pin)

         // USER CODE BEGIN (Main,4.2)

         // USER CODE END

    case POWERON_RESET:          //  the last reset was an externally
                                 //  triggered power on reset (#POR pin)

         // USER CODE BEGIN (Main,5)

         // USER CODE END

    default:

         // USER CODE BEGIN (Main,6)

         // USER CODE END

         MAIN_vInit();
  }


         // USER CODE BEGIN (Main,7)
	StartOS(OSDEFAULTAPPMODE);
         // USER CODE END

  return(swReturn);

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END


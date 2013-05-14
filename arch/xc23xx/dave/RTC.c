//****************************************************************************
// @Module        Real Time Clock (RTC)
// @Filename      RTC.c
// @Project       xc2365b.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      TASKING VX-toolset
//
// @Codegenerator 2.0
//
// @Description   This file contains functions that use the RTC module.
//
//----------------------------------------------------------------------------
// @Date          2013/5/14 22:07:01
//
//****************************************************************************

// USER CODE BEGIN (RTC_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "main.h"

// USER CODE BEGIN (RTC_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (RTC_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (RTC_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (RTC_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (RTC_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (RTC_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (RTC_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (RTC_General,9)

// USER CODE END


//****************************************************************************
// @Function      void RTC_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the RTC function 
//                library. It is assumed that the SFRs used by this library 
//                are in reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2013/5/14
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void RTC_vInit(void)
{

  volatile unsigned int uwTemp;

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the RTC Kernal 
  ///  -----------------------------------------------------------------------

  RTC_KSCCFG     =  0x0003;      // Module Enable

  uwTemp         =  RTC_KSCCFG;  // dummy read to avoid pipeline effects

  SCU_RTCCLKCON  =  0x0005;      // RTC working in synchronous mode with osc. 
                                 // freq. as a input freq.

  ///  -----------------------------------------------------------------------
  ///  Configuration of the RTC Counter:
  ///  -----------------------------------------------------------------------
  ///  - RTC input frequency is 8000.000 kHz
  ///  - the input clock is divided by factor 32
  ///  - the input clock is divided by factor 8
  ///  - counter is started after initialization
  ///  - RTC count clock frequency is 31.250 kHz

  while(!(RTC_CON & 0x8000));       // wait until access is possible
  RTC_CON        =  0x0002;      // load RTC control register

  ///  - overflow period on T14:  5.0240 [ms]
  ///  - overflow period on CNT0: 1.0550 [s]
  ///  - overflow period on CNT1: 1.1254 [min]
  ///  - overflow period on CNT2: 1.2004 [h]
  ///  - overflow period on CNT3: 1.7072 [months]

  RTC_T14REL     =  0xFF63;      // load T14 count/reload register
  RTC_RTCL       =  0x032E;      // load RTC low register
  RTC_RELL       =  0x032E;      // load RTC reload low register
  RTC_RTCH       =  0x0000;      // load RTC high register
  RTC_RELH       =  0x0000;      // load RTC reload high register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used RTC Interrupts:
  ///  -----------------------------------------------------------------------
  ///  RTC service request node configuration:
  ///  - RTC interrupt priority level (ILVL) = 15
  ///  - RTC interrupt group level (GLVL) = 0
  ///  - RTC group priority extension (GPX) = 0

  RTC_IC         =  0x007C;     

  ///  Use PEC channel 4 for RTC INT:
  ///  - normal interrupt
  ///  - pointers are not modified
  ///  - transfer a word
  ///  - service End of PEC interrrupt by a EOP interrupt node is disabled
  ///  - channel link mode is disabled

  PECC4          =  0x0000;      // load PECC4 control register


  RTC_ISNC       =  0x0001;      // load RTC interrupt sub node register

  RTC_CON_RUN    =  1;           // starts the counter


  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function RTC_vInit


//****************************************************************************
// @Function      void RTC_viRTC(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the RTC interrupt service routine. It is called up 
//                when:
//                 - counter T14 overflows and is reloaded
//                 - counter CNT0 overflows and is reloaded
//                 - counter CNT1 overflows and is reloaded
//                 - counter CNT2 overflows and is reloaded
//                 - counter CNT3 overflows and is reloaded
//                This interrupt request may eg. be used to provide a system 
//                time tick independent of the CPU frequency, or to wake up 
//                regularly from idle mode.
//                
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
// @Date          2013/5/14
//
//****************************************************************************

// USER CODE BEGIN (RTC,1)

// USER CODE END

_interrupt(RTCINT)  void RTC_viRTC(void)
{

  // USER CODE BEGIN (RTC,2)

  // USER CODE END

  if(RTC_ISNC_T14IR)             // if counter T14 overflow
  {

    // USER CODE BEGIN (RTC,3)

    // USER CODE END

    RTC_ISNC_T14IR = 0;

  }


  // USER CODE BEGIN (RTC,8)

  // USER CODE END

} //  End of function RTC_viRTC




// USER CODE BEGIN (RTC_General,10)

// USER CODE END


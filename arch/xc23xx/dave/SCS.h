//****************************************************************************
// @Module        Project Settings
// @Filename      SCS.h
// @Project       xc2365b.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      TASKING VX-toolset
//
// @Codegenerator 2.0
//
// @Description   This file is the header for the SCS driver
//             
//                Note:
//                This file should not be changed by 
//                the user
//
//----------------------------------------------------------------------------
// @Date          2013/5/14 22:06:58
//
//****************************************************************************

// USER CODE BEGIN (SCS_Header,1)

// USER CODE END



#ifndef _SCS_H_
#define _SCS_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (SCS_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (SCS_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// Notes: All frequencies are specified in [Hz].


// Restoring of driver timer SFRs used
// Range: 1 = Driver timer SFRs can be restored
//        0 = Driver timer SFRs cannot be restored
// Notes: Restoring needs additional code and RAM.
#define SCS_RESTORE_TIMER_USED 1

// Reference frequency of clock source fR
// - fR = fXTAL for crystal or external clock at crystal input
// Range: 4000000...25000000
#define SCS_F_R 8000000

// Target PLL frequency fPLL (<= 80000000)
// (Actual frequency: SCS_F_PLL, can be used e.g. for baud rate calculations)
#define SCS_F_PLL_TARGET 80000000


// Compiler related values *****************************************************
#define DISWDT __diswdt
#define FAR __far
#define INLINE inline
#define MKSP __mksp
#define NOP __nop
#define SHUGE __shuge
#ifndef SCU_PSCSTAT /* workaround for V2.3r2: */
#  define SCU_PSCSTAT (*(volatile __near unsigned int *)0xFFE8)
#  define SCU_PSCSTAT_LSTSEQ (SCU_PSCSTAT & (1U << 12U))
#endif


// Values for calculation ******************************************************

// If not user defined:
// Target VCO frequency fVCO for normal operation mode
#ifndef SCS_F_VCO_TARGET
#define SCS_F_VCO_TARGET 160000000
#endif

// If not user defined:
// Target frequency after P divider fP for normal operation mode
#ifndef SCS_F_P_TARGET
#define SCS_F_P_TARGET 16000000
#endif

// If not user defined:
// Calculate P divider for normal operation, round up
#ifndef SCS_P
#define SCS_P ((SCS_F_R + SCS_F_P_TARGET - 1)/SCS_F_P_TARGET)
#endif

// Calculate frequency after P divider fP for normal operation mode
#define SCS_F_P (SCS_F_R/SCS_P)

// If not user defined:
// Calculate final K2 divider for normal operation mode, round to avoid SCS_F_VCO > SCS_F_VCO_TARGET
#ifndef SCS_K2
#define SCS_K2 (SCS_F_VCO_TARGET/SCS_F_PLL_TARGET)
#endif

// If not user defined:
// Calculate N divider for normal operation mode, round to nearest; avoid SCS_F_VCO > SCS_F_VCO_TARGET
#ifndef SCS_N
#define SCS_N_TEMP ((SCS_F_PLL_TARGET * SCS_K2 + SCS_F_P/2)/SCS_F_P)
#  if SCS_F_P * SCS_N_TEMP > SCS_F_VCO_TARGET
#     define SCS_N (SCS_N_TEMP - 1)
#  else
#     define SCS_N SCS_N_TEMP
#  endif
#endif

// Calculate actual VCO frequency fVCO for normal operation mode
#define SCS_F_VCO (SCS_F_P * SCS_N)

// Calculate K2 for 5 MHz, round to nearest
#define SCS_K2_5MHZ ((SCS_F_VCO + 2500000)/5000000)

// Calculate K2 for 10 MHz, round to nearest
#define SCS_K2_10MHZ ((SCS_F_VCO + 5000000)/10000000)

// Calculate actual 5 MHz frequency
#define SCS_F_5MHZ (SCS_F_VCO/SCS_K2_5MHZ)

// Calculate actual PLL frequency fPLL for normal operation mode
#define SCS_F_PLL (SCS_F_VCO/SCS_K2)

// If not user defined and if necessary:
// Calculate additional K2 step and max. frequency for transition from 10 MHz up to normal mode
#ifndef SCS_K2_UP_1
#  if(SCS_K2 >= 16) || (SCS_K2_10MHZ <= 16)
#    define SCS_K2_UP_1 0
#  else
#    define SCS_K2_UP_1 16
#  endif
#endif
#if SCS_K2_UP_1 == 0
#  define SCS_F_K2_UP_1_MAX 0
#else
#  define SCS_F_K2_UP_1_MAX (SCS_F_VCO/SCS_K2_UP_1)
#endif

// If not user defined and if necessary:
// Calculate additional K2 step and max. frequency for transition from 10 MHz up to normal mode
#ifndef SCS_K2_UP_2
#  if(SCS_K2 >= 5) || (SCS_K2_10MHZ <= 5)
#    define SCS_K2_UP_2 0
#  else
#    define SCS_K2_UP_2 5
#  endif
#endif
#if SCS_K2_UP_2 == 0
#  define SCS_F_K2_UP_2_MAX 0
#else
#  define SCS_F_K2_UP_2_MAX (SCS_F_VCO/SCS_K2_UP_2)
#endif

// If not user defined and if necessary:
// Calculate additional K2 step and max. frequency for transition from 10 MHz up to normal mode
#ifndef SCS_K2_UP_3
#  if(SCS_K2 >= 3) || (SCS_K2_10MHZ <= 3)
#    define SCS_K2_UP_3 0
#  else
#    define SCS_K2_UP_3 3
#  endif
#endif
#if SCS_K2_UP_3 == 0
#  define SCS_F_K2_UP_3_MAX 0
#else
#  define SCS_F_K2_UP_3_MAX (SCS_F_VCO/SCS_K2_UP_3)
#endif

// If not user defined and if necessary:
// Calculate additional K2 step and max. frequency for transition from normal mode down to 5 MHz
#ifndef SCS_K2_DOWN_1
#  if(SCS_K2_5MHZ <= 3) || (SCS_K2 >= 3)
#    define SCS_K2_DOWN_1 0
#  else
#    define SCS_K2_DOWN_1 3
#  endif
#endif
#if SCS_K2_DOWN_1 == 0
#  define SCS_F_K2_DOWN_1_MAX (SCS_F_VCO/SCS_K2)
#else
#  define SCS_F_K2_DOWN_1_MAX (SCS_F_VCO/SCS_K2_DOWN_1)
#endif

// If not user defined and if necessary:
// Calculate additional K2 step and max. frequency for transition from normal mode down to 5 MHz
#ifndef SCS_K2_DOWN_2
#  if(SCS_K2_5MHZ <= 5) || (SCS_K2 >= 5)
#    define SCS_K2_DOWN_2 0
#  else
#    define SCS_K2_DOWN_2 5
#  endif
#endif
#if SCS_K2_DOWN_2 == 0
#  define SCS_F_K2_DOWN_2_MAX SCS_F_K2_DOWN_1_MAX
#else
#  define SCS_F_K2_DOWN_2_MAX (SCS_F_VCO/SCS_K2_DOWN_2)
#endif

// If not user defined and if necessary:
// Calculate additional K2 step and max. frequency for transition from normal mode down to 5 MHz
#ifndef SCS_K2_DOWN_3
#  if(SCS_K2_5MHZ <= 16) || (SCS_K2 >= 16)
#    define SCS_K2_DOWN_3 0
#  else
#    define SCS_K2_DOWN_3 16
#  endif
#endif
#if SCS_K2_DOWN_3 == 0
#  define SCS_F_K2_DOWN_3_MAX SCS_F_K2_DOWN_2_MAX
#else
#  define SCS_F_K2_DOWN_3_MAX (SCS_F_VCO/SCS_K2_DOWN_3)
#endif


// Constants for SCU registers*************************************************

// Constants for EXTCON register
#define SCS_MASK_EXTCON_EN (1U << 0U)   // EN External Clock Enable
#define SCS_POS_EXTCON_SEL (1U)

// Constants for HPOSCCON register
#define SCS_MASK_HPOSCCON_MODE \
(3U   <<2U)   // MODE Oscillator Mode, 0: external crystal/clock,
              // 1,2: reserved, 3: disabled, power-saving mode
#define SCS_MASK_HPOSCCON_SHBY \
(1U   <<8U)   // SHBY Shaper Bypass, 0: not bypassed, 1: bypassed

// Constants for interrupt/trap related registers DMPMIT, DMPMITCLR, INTCLR,
// INTDIS, INTSTAT
#define SCS_POS_INT_WUI (7U)
#define SCS_POS_INT_STM1 (10U)
#define SCS_POS_INT_ESR0T (11U)

// Constants for RSTSTAT1 register
#define SCS_MASK_RSTSTAT1_STM \
(3U   <<12U)  // STM Power-on for DMPM Reset Status
              // 0,1,2: no DMPM power-on, 3: DMPM power-on 

#define SCS_MASK_RSTSTAT1_ST1 \
(3U   <<14U)  // ST1 Power-on for DMP1 Reset Status
              // 0,1,2: no DMP1 power-on, 3: DMP1 power-on

// Constants for SYSCON0 register
#define SCS_MASK_SYSCON0_CLKSEL \
(3U   <<0U)   // CLKSEL Clock Select, 0: fWU, 1: fOSC, 2: fPLL, 3: fCLKIN1


// Other constants*************************************************************

// Power-saving modes
#define SCS_POWER_SAVING_STOPOVER_NORMAL     0U
#define SCS_POWER_SAVING_STOPOVER_CLOCK_ON   1U
#define SCS_POWER_SAVING_STANDBY_NORMAL      2U
#define SCS_POWER_SAVING_STANDBY_FSM         3U

// Wake-up sources, do not change!
#define SCS_WAKEUP_WUT       (1U  <<0U) // wake-up timer
#define SCS_WAKEUP_ESR0      (1U  <<1U) // ESR0
#define SCS_WAKEUP_ESR1      (1U  <<2U) // ESR1
#define SCS_WAKEUP_ESR2      (1U  <<3U) // ESR2
#define SCS_WAKEUP_ESR       (SCS_WAKEUP_ESR0|SCS_WAKEUP_ESR1|SCS_WAKEUP_ESR2)
#define SCS_WAKEUP_STM       (1U  <<4U) // system timer

#ifndef NULL_PTR
# define NULL_PTR (0)
#endif

//****************************************************************************
// @Typedefs
//****************************************************************************

// Type for SCS error
typedef enum
{
  SCS_ERROR_NO_ERROR = 0,        // no error
  SCS_ERROR_TO_OSC_HP_PLLV,      // timeout for high precision oscillator PLLV
  SCS_ERROR_OFW_ATTEMPTS_OSC_HP, // overflow of attempts for high precision oscillator
  SCS_ERROR_TO_OSCSELST,         // timeout for PLLSTAT_OSCSELST
  SCS_ERROR_TO_K1DIV,            // timeout for K1 divider setting
  SCS_ERROR_TO_K2DIV,            // timeout for K2 divider setting
  SCS_ERROR_TO_PDIV,             // timeout for P divider setting
  SCS_ERROR_TO_NDIV,             // timeout for N divider setting
  SCS_ERROR_TO_VCOBYST,          // timeout for VCO bypass switching
  SCS_ERROR_TO_VCO_LOCK,         // timeout for VCO lock
  SCS_ERROR_VCO_UNLOCKED,        // VCO is unlocked
  SCS_ERROR_TO_FSR_BUSY,         // timeout for FSR busy
  SCS_ERROR_TO_GSCSTAT,          // timeout for GSCSTAT
  SCS_ERROR_TO_SEQAEN,           // timeout for SEQAEN
  SCS_ERROR_TO_SEQBEN,           // timeout for SEQBEN
  SCS_ERROR_TO_PSMSTAT,          // timeout for PSMSTAT
  SCS_ERROR_PVC,                 // error PVC
  SCS_ERROR_TO_LSTSEQ,           // timeout for LSTSEQ
  SCS_ERROR_NO_STANDBY           // standby mode not entered
} Scs_ErrorType;

// Type for EXTCLK multiplexer source setting
typedef enum
{
  SCS_EXTCLK_F_SYS    = 0, // system frequency fSYS
  SCS_EXTCLK_F_OUT    = 1, // programmable output frequency fOUT
  SCS_EXTCLK_F_PLL    = 2, // PLL output frequency fPLL
  SCS_EXTCLK_F_OSC    = 3, // high precision oscillator frequency fOSC
  SCS_EXTCLK_F_WU     = 4, // wakeup oscillator frequency fWU
  SCS_EXTCLK_F_CLKIN1 = 5, // direct input frequency fCLKIN1
  SCS_EXTCLK_F_RTC    = 8  // real-time frequency fRTC
} Scs_ExtclkType;

//****************************************************************************
// @Imported Global Variables
//****************************************************************************


//****************************************************************************
// @Global Variables
//****************************************************************************


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

// INLINE functions
INLINE void Scs_EnableHighPrecOsc(unsigned int Enable);


// Functions with standard location
Scs_ErrorType Scs_ApplyNewK2Div(unsigned int K2Div);
Scs_ErrorType Scs_GoFromBaseModeToNormalMode(void);
void Scs_InitTimer(void);

#if(SCS_RESTORE_TIMER_USED)
  void Scs_RestoreTimer(void);
#endif


//****************************************************************************
// @Local Functions
//****************************************************************************

//*****************************************************************************
// @Function      INLINE void Scs_EnableHighPrecOsc(unsigned int Enable)
//
//-----------------------------------------------------------------------------
// @Description   This use case function enables or disables the high precision
//                oscillator for external crystal / clock at crystal input; may
//                be called by the user to reduce waiting time.
//
//-----------------------------------------------------------------------------
// @Returnvalue   None
//
//-----------------------------------------------------------------------------
// @Parameters    Enable: 0 = Disable, 1 = Enable
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_EnableHighPrecOsc,1)

// USER CODE END

INLINE void Scs_EnableHighPrecOsc(unsigned int Enable)
{
  if(Enable)
  {
    // Clear MODE bits to enable external crystal/clock, clear SHBY to disable
    // shaper bypass, leave other bits unchanged
    SCU_HPOSCCON &= (~(SCS_MASK_HPOSCCON_MODE | SCS_MASK_HPOSCCON_SHBY));
  }
  else
  {
    // Set MODE bits to disable external crystal/clock, set SHBY to enable
    // shaper bypass, leave other bits unchanged */
    SCU_HPOSCCON |= (SCS_MASK_HPOSCCON_MODE | SCS_MASK_HPOSCCON_SHBY);
  }
} // end of function Scs_EnableHighPrecOsc

//*****************************************************************************
// @Function      INLINE void Scs_CopyWords(unsigned int SHUGE *DestPtr,
//                const unsigned int SHUGE *SrcPtr, unsigned int Words)
//
//-----------------------------------------------------------------------------
// @Description   This global function copies words from source to destination.
//
//-----------------------------------------------------------------------------
// @Returnvalue   None
//
//-----------------------------------------------------------------------------
// @Parameters    DestPtr: Destination pointer; SrcPtr: Source pointer;
//                Words: Number of words to be copied (> 0)
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_CopyWords,1)

// USER CODE END

INLINE void Scs_CopyWords(unsigned int SHUGE *DestPtr,
const unsigned int SHUGE *SrcPtr, unsigned int Words)
{
  do
  {
    // Copy word and increment pointers
    *DestPtr = *SrcPtr++;
    DestPtr++;

    // Decrement Words
    Words--;
  }
  // until Words = 0
  while (Words != 0U);

} // End of function SCS_CopyWords



#endif  // ifndef _SCS_H_

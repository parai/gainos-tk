//****************************************************************************
// @Module        Project Settings
// @Filename      SCS.c
// @Project       xc2365b.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC2365B-40F80
//
// @Compiler      TASKING VX-toolset
//
// @Codegenerator 2.0
//
// @Description   This file contains the SCS driver.
//                      
//                Note:
//                This file should not be changed by 
//                the user.
//
//----------------------------------------------------------------------------
// @Date          2013/5/14 22:06:58
//
//****************************************************************************

// USER CODE BEGIN (SCS_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "main.h"

// USER CODE BEGIN (SCS_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (SCS_General,3)

// USER CODE END


// Function-like macros********************************************************

// SFR_COND_3: For polling an SFR condition up to 3 times; an "if" construct for
// a not bit-addressable bit needs >= 12 system clock cycles before 3rd check.
// Depending on the compiler (optimization) and the program location, the
// effective number of instruction cycles may be higher.
#define SFR_COND_3(Condition) (((Condition) && (Condition)) && (Condition))
#define SFR_COND_4(Condition) (((Condition) && (Condition)) && ((Condition) && \
                                (Condition)))

// WAIT_COND_RETURN: Waits with T13 until condition is no more met or time is
// over. If the condition is met, the function will be left with the
// specified return value.
#define WAIT_COND_RETURN(Condition, ReturnValue) \
do{} while((Condition) && SCS_T13_RUN); \
if(Condition) {return (ReturnValue);}

// GET_CYCLES: Converts Time[us] and MaxSysFreq[Hz] into cycles for driver timer,
// rounding up; for compile-time use only.
#define GET_CYCLES(Time, MaxSysFreq) \
((unsigned int)(((((long)(Time))*((MaxSysFreq)/1000))+7999)/8000))


// Constants that may be overwritten*******************************************

// If not user defined:
// Number of attempts for high precision oscillator start
#ifndef SCS_ATTEMPTS_OSC_HP
#  define SCS_ATTEMPTS_OSC_HP 10
#endif

// If not user defined:
// Timeout in [us] for PLLV after high precision oscillator start
#ifndef SCS_TIME_OSC_HP_PLLV
#  define SCS_TIME_OSC_HP_PLLV 5000
#endif

// If not user defined:
// Delay time/timeout in [us] for 1024 cycles after high precision oscillator
// start
#ifndef SCS_TIME_OSC_HP_1024
#  define SCS_TIME_OSC_HP_1024 1000
#endif


// Constants that may not be overwritten***************************************

// Maximum system frequency values in [Hz] for timeout calculations
#define SCS_F_INT_5MHZ_MAX                       5200000
#define SCS_F_INT_10MHZ_MAX                      10400000

// Times in [us]
#define SCS_TIME_VCO_BAND_SWITCH                 150
#define SCS_TIME_VCO_FINDIS_TO_BASE              50
#define SCS_TIME_FREQ_CHANGE                     5
#define SCS_TIME_VCO_LOCK                        200
#define SCS_TIME_FLASH_RAMP_DOWN                 500
#define SCS_TIME_FLASH_RAMP_UP                   500
#define SCS_TIME_PSMSTAT                         40
#define SCS_TIME_PLL_POWER_UP                    50

// Driver timer cycles derived from system clock cycles, round up
#define SCS_TIMER_CYCLES_GSC                     ((50000U + 7U)/8U)
#define SCS_TIMER_CYCLES_PSMSTAT                 ((77U + 7U)/8U)


// Constants for SCU registers*************************************************

// Constants for EVRMCON0 register
#define SCS_MASK_EVRMCON0_CCLEV \
(3U   <<10U)  // CCLEV Current Control Level, 0(minimum)...3(maximum)

// Constants for EVRMCON1 register
#define SCS_MASK_EVRMCON1_HPEN \
(1U   <<8U)   // HPEN High Precision Band-gap Enable

// Constants for EVRMSET registers
#define SCS_MASK_EVRMSET_CCDIS \
(1U   <<12U)  // CCDIS Current Control Disable

// Constants for GSCEN register
#define SCS_MASK_GSCEN_PSCBEXEN \
(1U   <<0U)   // PSCBEXEN Sequence B Exit Request Trigger Enable
#define SCS_MASK_GSCEN_SW1EN \
(1U   <<11U)  // SW1EN Software 1 Request Trigger Enable

// Constants for GSCSTAT register
#define SCS_MASK_GSCSTAT_CURRENT \
(3U    <<0U)  // CURRENT currently used system mode
#define SCS_MASK_GSCSTAT_CURRENT_NORMAL \
(0U    <<0U)  // currently used system mode = normal
#define SCS_MASK_GSCSTAT_CURRENT_CLOCK_OFF \
(2U    <<0U)  // currently used system mode = clock off

// Constants for GSCSWREQ register
#define SCS_MASK_GSCSWREQ_SWTRG1 \
(1U    <<0U)  // SWTRG1 Software Trigger 1

// Constants for interrupt/trap related registers DMPMIT, DMPMITCLR, INTCLR,
// INTDIS, INTSTAT
#define SCS_MASK_INT_PVCMI1 \
(1U   <<2U)   // PVCMI1 PVCM Interrupt Request Flag 1 (w for clear)
#define SCS_MASK_INT_PVCMI2 \
(1U   <<3U)   // PVCMI2 PVCM Interrupt Request Flag 2 (w for clear)
#define SCS_MASK_INT_PVC1I1 \
(1U   <<4U)   // PVC1I1 PVC1 Interrupt Request Flag 1 (w for clear)
#define SCS_MASK_INT_PVC1I2 \
(1U   <<5U)   // PVC1I2 PVC1 Interrupt Request Flag 2 (w for clear)
#define SCS_MASK_INT_WUI \
(1U   <<7U)   // WUI Wake-up Timer Interrupt Request Flag (w for clear)
#define SCS_MASK_INT_PVC (SCS_MASK_INT_PVCMI1 | SCS_MASK_INT_PVCMI2 | \
SCS_MASK_INT_PVC1I1 | SCS_MASK_INT_PVC1I2)

// Constants for KSCCFG/KSCFG registers
#define SCS_MASK_KSCCFG_MODEN \
(1U   <<0U)   // MODEN Module Enable
#define SCS_MASK_KSCCFG_BPMODEN \
(1U   <<1U)   // BPMODEN Bit Protection for MODEN, set to 1 for change (w)
#define SCS_MASK_KSCCFG_BPNOM \
(1U   <<7U)   // BPNOM Bit Protection for NOMCFG, set to 1 for change (w)
#define SCS_MASK_KSCCFG_BPSUM \
(1U   <<11U)  // BPSUM Bit Protection for SUMCFG, set to 1 for change (w)
#define SCS_MASK_KSCCFG_COMCFG \
(2U   <<12U)  // COMCFG Clock Off Mode Configuration
              // 0: power-down request not activated, 2: activated
#define SCS_MASK_KSCCFG_BPCOM \
(1U   <<15U)  // BPCOM Bit Protection for COMCFG, set to 1 for change (w)

// Constants for PLLCON0 register
#define SCS_MASK_PLLCON0_NDIV \
(0x3FU<<8U)   // NDIV N-Divider Value 16...40 for VCOSEL = 1
#define SCS_MASK_PLLCON0_NACK \
(1U  <<15U)   // N-Divider Ready Acknowledge
#define SCS_POS_PLLCON0_NDIV 8U

// Constants for PLLCON1 register
#define SCS_MASK_PLLCON1_OSCSEL \
(1U   <<1U)   // OSCSEL Oscillator Input Selection
              // 0: external clock, 1: PLL internal clock
#define SCS_MASK_PLLCON1_AOSCSEL \
(1U   <<3U)   // AOSCSEL Asynchronous Oscillator Input Selection
              // 0: Configuration is controlled via bit OSCSEL
              // 1: PLL internal clock is selected asynchronously
#define SCS_MASK_PLLCON1_PDIV \
(0x0FU<<8U)   // PDIV P-Divider Value 0...15
#define SCS_MASK_PLLCON1_PACK \
(1U   <<15U)  // P-Divider Ready Acknowledge
#define SCS_POS_PLLCON1_PDIV 8U

// Constants for PLLCON2 register
#define SCS_POS_PLLCON2_K1DIV 0U

// Constants for PLLCON3 register
#define SCS_POS_PLLCON3_K2DIV 0U

// Constants for PLLSTAT register
#define SCS_MASK_PLLSTAT_VCOBYST \
(1U   <<0U)   // VCOBYST PLL clock derived from divider K2 (rh)
#define SCS_MASK_PLLSTAT_OSCSELST \
(1U   <<2U)   // OSCSELST Internal clock for PLL (rh)
#define SCS_MASK_PLLSTAT_VCOLOCK \
(1U   <<3U)   // VCOLOCK PLL VCO Lock Status (rh)
#define SCS_MASK_PLLSTAT_PRDY \
(1U   <<5U)   // PRDY P-Divider Ready Status (rh)
#define SCS_MASK_PLLSTAT_NRDY \
(1U   <<6U)   // PRDY N-Divider Ready Status (rh)
#define SCS_MASK_PLLSTAT_K1RDY \
(1U   <<7U)   // K1RDY K1-Divider Ready Status (rh)
#define SCS_MASK_PLLSTAT_K2RDY \
(1U   <<8U)   // K2RDY K2-Divider Ready Status (rh)
#define SCS_MASK_PLLSTAT_VCOL0 \
(1U   <<10U)  // VCOL0 VCO Lock Detection Lost Status (rh)
#define SCS_MASK_PLLSTAT_VCOL1 \
(1U   <<11U)  // VCOL1 VCO Lock Detection Reached Status (rh)
#define SCS_MASK_PLLSTAT_OSCLOCK \
(1U   <<15U)  // OSCLOCK 2^11 OSC_HP cycles counted (rh)

// Constants for PSCSTAT register
#define SCS_MASK_PSCSTAT_PSMSTAT \
(7U   <<2U)   // PSMSTAT (rh)

// Constants for PVCMCON0/PVC1CON0 registers
#define SCS_MASK_PVCCON_L1INTEN \
(1U   <<5U)   // L1INTEN Level 1 Interrupt Request Enable
#define SCS_MASK_PVCCON_L1RSTEN \
(1U   <<6U)   // L1RSTEN Level 1 Reset Request Enable
#define SCS_MASK_PVCCON_L1ASEN \
(1U   <<7U)   // L1ASEN Level 1 Asynchronous Action Enable
#define SCS_MASK_PVCCON_L2INTEN \
(1U   <<13U)  // L2INTEN Level 2 Interrupt Request Enable
#define SCS_MASK_PVCCON_L2RSTEN \
(1U   <<14U)  // L2RSTEN Level 2 Reset Request Enable
#define SCS_MASK_PVCCON_L2ASEN \
(1U   <<15U)  // L2ASEN Level 2 Asynchronous Action Enable
#define SCS_MASK_PVCCON_ACTIONS \
(SCS_MASK_PVCCON_L1INTEN | SCS_MASK_PVCCON_L1RSTEN | SCS_MASK_PVCCON_L1ASEN | \
SCS_MASK_PVCCON_L2INTEN | SCS_MASK_PVCCON_L2RSTEN | SCS_MASK_PVCCON_L2ASEN)

// Constants for SEQCON register
#define SCS_MASK_SEQCON_SEQATRG \
(1U   <<0U)   // SEQATRG Sequence A Trigger (w)
              // (A only started if B is not currently active)
#define SCS_MASK_SEQCON_SEQBTRG \
(1U   <<1U)   // SEQBTRG Sequence B Trigger (w)
              // (B only started if A is not currently active)
#define SCS_MASK_SEQCON_SEQAEN \
(1U   <<2U)   // SEQAEN Sequence A Enable (rwh)
              // 0: never started, 1: started if requested, cleared after A
#define SCS_MASK_SEQCON_SEQBEN \
(1U   <<3U)   // SEQBEN Sequence B Enable (rwh)
              // 0: never started, 1: started if requested, cleared after B
#define SCS_MASK_SEQCON_WUTEN \
(1U   <<8U)   // WUTEN Sequence B is triggered by a WUT event
#define SCS_MASK_SEQCON_ESR0EN \
(1U   <<9U)   // ESR0EN Sequence B is triggered by an ESR0 event
#define SCS_MASK_SEQCON_ESR1EN \
(1U   <<10U)  // ESR1EN Sequence B is triggered by an ESR1 event
#define SCS_MASK_SEQCON_ESR2EN \
(1U   <<11U)  // ESR2EN Sequence B is triggered by an ESR2 event
#define SCS_MASK_SEQCON_STM1EN \
(1U   <<12U)  // STM1EN Sequence B is triggered by an STM1 event
#define SCS_MASK_SEQCON_GSCBY \
(1U   <<15U)  // GSCBY GSC Bypass
#define SCS_POS_SEQCON_WUTEN 8U

// Constants for STATCLR0 register
#define SCS_MASK_STATCLR0_EMCVCO \
(1U   <<13U)  // EMCVCO Clear SYSCON0.EMSVCO (w)

// Constants for STATCLR1 register
#define SCS_MASK_STATCLR1_VCOL0CLR \
(1U   <<0U)   // VCOL0CLR Clear PLLSTAT.VCOL0 (w)
#define SCS_MASK_STATCLR1_VCOL1CLR \
(1U   <<1U)   // VCOL1CLR Clear PLLSTAT.VCOL1 (w)
#define SCS_MASK_STATCLR1_OSC2L1CLR \
(1U   <<2U)   // OSC2L1CLR Clear HPOSCCON.OSC2L1 (w)

// Constants for STATCLR1 register
#define SCS_MASK_STATCLR1_SETFINDIS \
(1U   <<4U)   // SETFINDIS Set PLLSTAT.FINDIS(disconnect VCO input clock) (w)
#define SCS_MASK_STATCLR1_CLRFINDIS \
(1U   <<5U)   // CLRFINDIS Clear PLLSTAT.FINDIS(connect VCO input clock) (w)

// Constants for STMEM0 register
#define SCS_MASK_STMEM0_SSFMOD \
(0xFU <<7U)   // SSFMOD Flash modules activation
              // 0: Startup with flash, F: Startup without flash

// Constants for SWDCON0 register
#define SCS_MASK_SWDCON0_L1INTEN \
(1U   <<5U)   // L1INTEN Level 1 Interrupt Request Enable
#define SCS_MASK_SWDCON0_L1RSTEN \
(1U   <<6U)   // L1RSTEN Level 1 Reset Request Enable
#define SCS_MASK_SWDCON0_L2INTEN \
(1U   <<13U)  // L2INTEN Level 2 Interrupt Request Enable
#define SCS_MASK_SWDCON0_L2RSTEN \
(1U   <<14U)  // L2RSTEN Level 2 Reset Request Enable
#define SCS_MASK_SWDCON0_ACTIONS \
(SCS_MASK_SWDCON0_L1INTEN | SCS_MASK_SWDCON0_L1RSTEN | \
SCS_MASK_SWDCON0_L2INTEN | SCS_MASK_SWDCON0_L2RSTEN)

// Constants for SWDCON1 register
#define SCS_MASK_SWDCON1_POWENSET \
(1U   <<1U)   // POWENSET SWD Power Saving Mode Enable Set (w)

// Constants for trap related registers TRAPCLR, TRAPDIS, TRAPSTAT, TRAPSET
#define SCS_MASK_TRAP_FAT \
(1U   <<0U)   // FAT Flash Access Trap Request
#define SCS_MASK_TRAP_VCOLCKT \
(1U   <<7U)   // VCOLCKT VCOLCK Trap Request

// Constants for WUCR register
#define SCS_MASK_WUCR_RUNCON_START \
(1U    <<0U)  // RUNCON Field for timer start (w)
#define SCS_MASK_WUCR_RUNCON_STOP \
(2U    <<0U)  // RUNCON Field for timer stop (w)
#define SCS_MASK_WUCR_AONCON_OFF \
(2U    <<2U)  // AONCON Field for no auto-start via PSC (w)
#define SCS_MASK_WUCR_ASPCON_ON \
(1U    <<4U)  // ASPCON Field for auto-stop after trigger (w)
#define SCS_MASK_WUCR_ASPCON_OFF \
(2U    <<4U)  // ASPCON Field for no auto-stop after trigger (w)
#define SCS_MASK_WUCR_CLRTRG \
(1U    <<7U)  // CLRTRG Clear Trigger Bit (w)

#define SCS_POS_WUCR_CLKDIV 11U

// Constants for non-SCU registers *********************************************

// Constants for CPUCON1 register
#define SCS_POS_CPUCON1_VECSC     5U

// Constants for CCU60_TCTR0 register
#define SCS_MASK_TCTR0_T13CLK \
(7U    <<8U)  // T13CLK Timer T13 Input Clock Select, f = fCC6 / 2^value)
#define SCS_MASK_TCTR0_T13CLK_8 \
(3U    <<8U)  // T13CLK Timer T13 Input Clock Select, f = fCC6 / 2^3
#define SCS_MASK_TCTR0_T13PRE \
(1U    <<11U) // T13PRE Timer T13 additional prescaler enabled
#define SCS_MASK_TCTR0_T13R \
(1U    <<12U)  // T13R Timer T13 Run Bit (rh)
#define SCS_T13_RUN (CCU60_TCTR0 & SCS_MASK_TCTR0_T13R)

// Constants for CCU60_TCTR2 register
#define SCS_MASK_TCTR2_T13SSC \
(1U    <<1U)  // T13SSC T13 Single Shot Control
#define SCS_MASK_TCTR2_T13TEC \
(7U    <<2U)  // T13TEC T13 Trigger Event Control
#define SCS_MASK_TCTR2_T13RSEL \
(3U    <<10U) // T13RSEL T13 External Run Selection

// Constants for CCU60_TCTR4 register
#define SCS_MASK_TCTR4_T13RR \
(1U    <<8U)  // T13RR Timer 13 Run Reset (w)
#define SCS_MASK_TCTR4_T13RS \
(1U    <<9U)  // T13RS Timer 13 Run Set (w)
#define SCS_MASK_TCTR4_T13RES \
(1U    <<10U) // T13RES Timer 13 Reset (w)
#define SCS_MASK_TCTR4_T13STR \
(1U    <<14U) // T13STR Timer 13 Shadow Transfer Request (w)

// Constants for CCU60_PISELH register
#define SCS_MASK_PISELH_ISCNT13 \
(3U    <<4U)  // ISCNT13 T13 Input Select for Counting Input


// Other constants*************************************************************

// Right-aligned masks
#define SCS_MASK_4LSB  0x000FU
#define SCS_MASK_6LSB  0x003FU
#define SCS_MASK_10LSB 0x03FFU

// Number of K2 ramp steps
#define SCS_K2_RAMP_STEPS (4U)


// Check of parameters*********************************************************

// Check fR
#if (SCS_F_R < 4000000) || (SCS_F_R > 25000000)
#  error "SCS_F_R out of range"
#endif

/* check fPLL target frequency */
#if (SCS_F_PLL_TARGET < 1000000) || (SCS_F_PLL_TARGET > 80000000)
#  error "SCS_F_PLL_TARGET out of range"
#endif

// Check fP
#if (SCS_F_P < 4000000) || (SCS_F_P > 16000000)
#  error"SCS_F_P out of range"
#endif

// Check fVCO
#if (SCS_F_VCO < 10000000) || (SCS_F_VCO > 160000000)
#  error"SCS_F_VCO out of range"
#  endif

// Check P divider
#if (SCS_P < 1) || (SCS_P > 16)
#  error"SCS_P out of range"
#endif

// Check N divider
#if (SCS_N < 16) || (SCS_N > 40)
#  error  "SCS_N out of range, different SCS_P required?"
#  endif

// Check K2 dividers
#if (SCS_K2 < 1) || (SCS_K2 > 512)
#  error "SCS_K2 out of range"
#endif
#if SCS_K2_UP_1 > 512
#  error "SCS_K2_UP_1 out of range"
#endif
#if SCS_K2_UP_2 > 512
#  error "SCS_K2_UP_2 out of range"
#endif
#if SCS_K2_UP_3 > 512
#  error "SCS_K2_UP_3 out of range"
#endif
#if SCS_K2_DOWN_1 > 512
#  error "SCS_K2_DOWN_1 out of range"
#endif
#if SCS_K2_DOWN_2 > 512
#  error "SCS_K2_DOWN_2 out of range"
#endif
#if SCS_K2_DOWN_3 > 512
#  error "SCS_K2_DOWN_3 out of range"
#endif
#if (SCS_K2_5MHZ < 1) || (SCS_K2_5MHZ > 512)
#  error "SCS_K2_5MHZ out of range"
#endif
#if (SCS_K2_10MHZ < 1) || (SCS_K2_10MHZ > 512)
#  error "SCS_K2_10MHZ out of range"
#endif


//****************************************************************************
// @Typedefs
//****************************************************************************

// Type for K2 ramp
typedef struct
{
  unsigned int K2;      // K2 step value
  unsigned int Delay;   // delay in timer cycles after applying K2 step
} Scs_K2RampType;



//****************************************************************************
// @Imported Global Variables
//****************************************************************************


//****************************************************************************
// @Global Variables
//****************************************************************************

static const Scs_K2RampType Scs_K2RampNormalUp[SCS_K2_RAMP_STEPS] =
{
  {SCS_K2_UP_1, GET_CYCLES(SCS_TIME_FREQ_CHANGE, SCS_F_K2_UP_1_MAX)},
  {SCS_K2_UP_2, GET_CYCLES(SCS_TIME_FREQ_CHANGE, SCS_F_K2_UP_2_MAX)},
  {SCS_K2_UP_3, GET_CYCLES(SCS_TIME_FREQ_CHANGE, SCS_F_K2_UP_3_MAX)},
  {SCS_K2,      GET_CYCLES(SCS_TIME_FREQ_CHANGE, SCS_F_VCO/SCS_K2)}
};



#if(SCS_RESTORE_TIMER_USED)
  // Saved CCU60 SFRs
  static unsigned int Ccu60KscfgSave;
  static unsigned int Ccu60Tctr0Save;
  static unsigned int Ccu60Tctr2Save;
  static unsigned int Ccu60PiselhSave;
  static unsigned int Ccu60T13prSave;
#endif // (SCS_RESTORE_TIMER_USED)


//****************************************************************************
// @External Prototypes
//****************************************************************************


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// Basic functions *************************************************************

// INLINE functions
INLINE Scs_ErrorType Scs_lEnableVcoBypass(unsigned int Enable);
INLINE Scs_ErrorType Scs_lSelectExternalPllClock(void);
INLINE void Scs_lStartTimer(unsigned int Cycles);
INLINE Scs_ErrorType Scs_lWaitForVcoLock(unsigned int Timeout);

// Functions with standard location
static Scs_ErrorType Scs_lApplyNewK1Div(unsigned int K1Div);
static Scs_ErrorType Scs_lApplyNewNDiv(unsigned int NDiv);
static Scs_ErrorType Scs_lApplyNewPDiv(unsigned int PDiv);
static Scs_ErrorType Scs_lApplyNewVcoDivs(unsigned int PDiv, unsigned int NDiv,
unsigned int K2Div);
static Scs_ErrorType Scs_lCheckFreqHighPrecOsc(void);
static Scs_ErrorType Scs_lEnableVcoLockEmerg(void);
static Scs_ErrorType Scs_lRampPll(const Scs_K2RampType *K2RampPtr);


//****************************************************************************
// @Local Functions
//****************************************************************************

//*****************************************************************************
// @Function      Scs_ErrorType Scs_lWaitForVcoLock(unsigned int Timeout) 
//
//-----------------------------------------------------------------------------
// @Description   This private function waits for VCO lock.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lWaitForVcoLock,1)

// USER CODE END

INLINE Scs_ErrorType Scs_lWaitForVcoLock(unsigned int Timeout)
{
  // Restart VCO lock detection
  SCU_PLLCON1_RESLD = 1U;

  // Start driver timer for VCO lock timeout
  Scs_lStartTimer(Timeout);

  // Wait till VCO lock occurs or timeout is over
  WAIT_COND_RETURN(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_VCOLOCK),
  SCS_ERROR_TO_VCO_LOCK);

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_lWaitForVcoLock


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lEnableVcoBypass(unsigned int Enable) 
//
//-----------------------------------------------------------------------------
// @Description   This private function enables or disables VCO bypass. 
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    Enable: 0 = Disable, 1 = Enable
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lEnableVcoBypass,1)

// USER CODE END

INLINE Scs_ErrorType Scs_lEnableVcoBypass(unsigned int Enable)
{
  // Enable or disable VCO bypass
  SCU_PLLCON0_VCOBY = Enable;

  if(Enable)
  {
    // Wait for VCO bypass active with short timeout
    if(SFR_COND_3(SCU_PLLSTAT & SCS_MASK_PLLSTAT_VCOBYST))
    {
      // error: timeout VCOBYST
      return SCS_ERROR_TO_VCOBYST;
    }
  }
  else
  {
    // Wait for VCO bypass inactive with short timeout
    if(SFR_COND_3(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_VCOBYST)))
    {
      // error: timeout VCOBYST
      return SCS_ERROR_TO_VCOBYST;
    }
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function SCS_lEnableVcoBypass


//*****************************************************************************
// @Function      INLINE Scs_ErrorType Scs_lSelectExternalPllClock(void)
//
//-----------------------------------------------------------------------------
// @Description   This private function selects the external clock source for
//                the PLL.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lSelectExternalPllClock,1)

// USER CODE END

INLINE Scs_ErrorType Scs_lSelectExternalPllClock(void)
{
  // Select external clock, disable asynchronous clock selection;
  // keep other PLLCON1 bits
  SCU_PLLCON1 &= (~(SCS_MASK_PLLCON1_OSCSEL | SCS_MASK_PLLCON1_AOSCSEL));

  // Wait until external clock is selected (OSCSELST = 0), with short timeout
  if(SFR_COND_3(SCU_PLLSTAT & SCS_MASK_PLLSTAT_OSCSELST))
  {
    // error: timeout
    return SCS_ERROR_TO_OSCSELST;
  }

  // no error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_lSelectExternalPllClock


//*****************************************************************************
// @Function      INLINE void Scs_lStartTimer(unsigned int Cycles)
//
//-----------------------------------------------------------------------------
// @Description   This private function starts timer T13 and waits until the
//                specified number of clocks is counted.
//
//-----------------------------------------------------------------------------
// @Returnvalue   None
//
//-----------------------------------------------------------------------------
// @Parameters    Cycles: Number of T13 clocks to count, 0...65535
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lStartTimer,1)

// USER CODE END

INLINE void Scs_lStartTimer(unsigned int Cycles)
{
  // Stop T13
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13RR;

  // Limit period (see following correction)
  if(Cycles < 3U)
  {
    Cycles = 3U;
  }

  // Correct period according to minimum delay
  Cycles = Cycles - 3U;

  // Set T13 for period register = 0xFFFF
  CCU60_T13 = ~Cycles;

  // Start T13
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13RS;

} // End of function Scs_lStartTimer


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lApplyNewK1Div(unsigned int K1Div)
//
//-----------------------------------------------------------------------------
// @Description   This private function applies a new K1 divider value to the 
//                PLL.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    K1Div: K1 divider value
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lApplyNewK1Div,1)

// USER CODE END

static Scs_ErrorType Scs_lApplyNewK1Div(unsigned int K1Div)
{

  if(K1Div == ((SCU_PLLCON2 >> SCS_POS_PLLCON2_K1DIV) & SCS_MASK_10LSB))
  {
    // New value = old value: do nothing, return without error
    return SCS_ERROR_NO_ERROR;
  }

  // Set K1DIV (K1 divider value), clear K1ACK (K1 acknowledge)
  SCU_PLLCON2 = K1Div << SCS_POS_PLLCON2_K1DIV;

  // wait until K1 ready = 0 with short timeout
  if(SFR_COND_4(SCU_PLLSTAT & SCS_MASK_PLLSTAT_K1RDY))
  {
    // error: timeout K1DIV
    return SCS_ERROR_TO_K1DIV;
  }

  // Set K1 acknowledge
  SCU_PLLCON2_K1ACK = 1U;
    
  // Wait until K1 ready = 1 with short timeout
  if(SFR_COND_4(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_K1RDY)))
  {
    // error: timeout K1DIV
    return SCS_ERROR_TO_K1DIV;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_lApplyNewK1Div


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lApplyNewNDiv(unsigned int NDiv) 
//
//-----------------------------------------------------------------------------
// @Description   This private function applies a new N divider value 
//                to the PLL.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    NDiv: N divider value
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lApplyNewNDiv,1)

// USER CODE END

static Scs_ErrorType Scs_lApplyNewNDiv(unsigned int NDiv)
{
  if(NDiv == ((SCU_PLLCON0 >> SCS_POS_PLLCON0_NDIV) & SCS_MASK_6LSB))
  {
    // New value = old value: do nothing, return without error
    return SCS_ERROR_NO_ERROR;
  }
    
  // Change N divider value, clear N acknowledge; leave other bits unchanged
  SCU_PLLCON0 = (SCU_PLLCON0 & (~(SCS_MASK_PLLCON0_NDIV |
  SCS_MASK_PLLCON0_NACK))) | (NDiv << SCS_POS_PLLCON0_NDIV);
    
  // Wait until N ready = 0 with short timeout
  if(SFR_COND_3(SCU_PLLSTAT & SCS_MASK_PLLSTAT_NRDY))
  {
    // error: timeout NDIV
    return SCS_ERROR_TO_NDIV;
  }

  // Set N acknowledge
  SCU_PLLCON0_NACK = 1U;

  // Wait until N ready = 1 with short timeout
  if(SFR_COND_3(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_NRDY)))
  {
    // error: timeout NDIV
    return SCS_ERROR_TO_NDIV;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // end of function Scs_lApplyNewNDiv 


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lApplyNewPDiv(unsigned int PDiv) 
//
//-----------------------------------------------------------------------------
// @Description   This private function applies a new P divider value 
//                to the PLL.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    PDiv: P divider value
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lApplyNewPDiv,1)

// USER CODE END

static Scs_ErrorType Scs_lApplyNewPDiv(unsigned int PDiv)
{
  if(PDiv == ((SCU_PLLCON1 >> SCS_POS_PLLCON1_PDIV) & SCS_MASK_4LSB))
  {
    // New value = old value: do nothing, return without error
    return SCS_ERROR_NO_ERROR;
  }

  // Nhange P divider value, clear P acknowledge; leave other bits unchanged
  SCU_PLLCON1 = (SCU_PLLCON1 & (~(SCS_MASK_PLLCON1_PDIV |
  SCS_MASK_PLLCON1_PACK))) | (PDiv << SCS_POS_PLLCON1_PDIV);
    
  // Wait until P ready = 0 with short timeout
  if(SFR_COND_3(SCU_PLLSTAT & SCS_MASK_PLLSTAT_PRDY))
  {
    // error: timeout PDIV
    return SCS_ERROR_TO_PDIV;
  }

  // Set P acknowledge
  SCU_PLLCON1_PACK = 1U;

  // Wait until P ready = 1 with short timeout
  if(SFR_COND_3(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_PRDY)))
  {
    // error: timeout PDIV
    return SCS_ERROR_TO_PDIV;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_lApplyNewPDiv


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lApplyNewVcoDivs(unsigned int PDiv, 
//                unsigned int NDiv, unsigned int K2Div)
//
//-----------------------------------------------------------------------------
// @Description   This private function applies new P, N and K2 dividers 
//                to the VCO.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    PDiv: P divider value
//                NDiv: N divider value
//                K2Div: K2 divider value
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lApplyNewVcoDivs,1)

// USER CODE END

static Scs_ErrorType Scs_lApplyNewVcoDivs(unsigned int PDiv, unsigned int NDiv,
unsigned int K2Div)
{
  Scs_ErrorType Error;

  // Set P divider, check for error
  Error = Scs_lApplyNewPDiv(PDiv);
  if(Error)
  {
    return Error;
  }

  // Set N divider, check for error
  Error = Scs_lApplyNewNDiv(NDiv);
  if(Error)
  {
    return Error;
  }

  // Set K2 divider, check for error
  Error = Scs_ApplyNewK2Div(K2Div);
  if(Error)
  {
    return Error;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_lApplyNewVcoDivs


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lCheckFreqHighPrecOsc(void) 
//
//-----------------------------------------------------------------------------
// @Description   This private function checks the high precision oscillator 
//                for a valid output clock.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lCheckFreqHighPrecOsc,1)

// USER CODE END

static Scs_ErrorType Scs_lCheckFreqHighPrecOsc(void)
{
  unsigned int Attempts;

  // Initialize attempts
  Attempts = (unsigned int)SCS_ATTEMPTS_OSC_HP;

  do
  {
    // Start timeout for usable oscillator at fSYS = internal 5 MHz
    Scs_lStartTimer(GET_CYCLES(SCS_TIME_OSC_HP_PLLV, SCS_F_INT_5MHZ_MAX));

    // Wait until oscillator is usable or time is over
    WAIT_COND_RETURN(!SCU_HPOSCCON_PLLV, SCS_ERROR_TO_OSC_HP_PLLV);

    // Clear sticky bit for high precision oscillator frequency error
    SCU_STATCLR1 = SCS_MASK_STATCLR1_OSC2L1CLR;

    // Start driver timer for 1024 cycles delay/timeout at
    // fSYS = internal 5 MHz
    Scs_lStartTimer(GET_CYCLES(SCS_TIME_OSC_HP_1024, SCS_F_INT_5MHZ_MAX));

    // wait till frequency error occurs, oscillator is stable or time is over
    do{}
    while(((!SCU_HPOSCCON_OSC2L1) &&
    (!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_OSCLOCK))) && SCS_T13_RUN);
    if((!SCU_HPOSCCON_OSC2L1) && (SCU_PLLSTAT & SCS_MASK_PLLSTAT_OSCLOCK))
    {
    // no frequency error, oscillator is stable
    return SCS_ERROR_NO_ERROR;
    }
    
    // Decrement attempts
    Attempts--;
  }
  while(Attempts != 0U);

  // error: too many attempts
  return SCS_ERROR_OFW_ATTEMPTS_OSC_HP;

} // End of function Scs_lCheckFreqHighPrecOsc


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lEnableVcoLockEmerg(void) 
//
//-----------------------------------------------------------------------------
// @Description   This private function enables the VCO loss-of-lock
//                emergency handling.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lEnableVcoLockEmerg,1)

// USER CODE END

static Scs_ErrorType Scs_lEnableVcoLockEmerg(void)
{
  volatile unsigned int Work;

  // Check if VCO is unlocked
  if(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_VCOLOCK))
  {
    // error: VCO unlocked
    return SCS_ERROR_VCO_UNLOCKED;
  }

  // Clear sticky bits for VCO lock detection
  SCU_STATCLR1 = SCS_MASK_STATCLR1_VCOL0CLR | SCS_MASK_STATCLR1_VCOL1CLR;

  // Disable emergency clock selection
  SCU_PLLCON1_EMCLKEN = 0U;
  SCU_SYSCON0_EMCLKSELEN = 0U;

  // Clear loss-of-lock emergency status
  SCU_STATCLR0 = SCS_MASK_STATCLR0_EMCVCO;

  // Enable emergency input clock disconnection
  SCU_PLLCON1_EMFINDISEN = 1U;

  // Clear VCOLCK trap request flag
  SCU_TRAPCLR = SCS_MASK_TRAP_VCOLCKT;

  // Enable VCOLCK trap request
  SCU_TRAPDIS &= (~SCS_MASK_TRAP_VCOLCKT);

  // Read PLLSTAT
  Work = SCU_PLLSTAT;

  // Check if sticky bit for VCO lock detection is set or VCO is unlocked
  if((Work & (SCS_MASK_PLLSTAT_VCOL0 | SCS_MASK_PLLSTAT_VCOL1)) ||
  (!(Work & SCS_MASK_PLLSTAT_VCOLOCK)))
  {
    // error: VCO unlocked
    return SCS_ERROR_VCO_UNLOCKED;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_lEnableVcoLockEmerg


//*****************************************************************************
// @Function      Scs_ErrorType Scs_lRampPll(Scs_K2RampType *K2RampPtr) 
//
//-----------------------------------------------------------------------------
// @Description   This private function applies a stepwise ramp-up or ramp-down
//                 of the PLL output frequency using a set of K2 dividers 
//                 and delay values.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lRampPll,1)

// USER CODE END

static Scs_ErrorType Scs_lRampPll(const Scs_K2RampType *K2RampPtr)
{
  Scs_ErrorType Error;
  unsigned int Counter;

  /* initialize counter */
  Counter = SCS_K2_RAMP_STEPS;
    
  /* stop T13 */
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13RR;

  do
  {
    if(K2RampPtr->K2 != 0U)
    {
      /* wait until previous delay time in this function is over */
      do { }
      while(SCS_T13_RUN);

      /* apply new K2 divider */
      Error = Scs_ApplyNewK2Div(K2RampPtr->K2 - 1U);

      /* start delay time from table for frequency change */
      Scs_lStartTimer(K2RampPtr->Delay);

      /* check for error */
      if(Error)
      {
        return Error;
      }
    }
    /* select next K2 data */
    K2RampPtr++;

    /* decrement counter */
    Counter--;

  /* repeat until counter = 0 */
  }while(Counter != 0U);

  /* wait until last delay time in this function is over */
  do { }
  while(SCS_T13_RUN);

  /* no error */
  return SCS_ERROR_NO_ERROR;

} /* end of function Scs_lRampPll */


//*****************************************************************************
// @Function      Scs_ErrorType Scs_ApplyNewK2Div(unsigned int K2Div)
//
//-----------------------------------------------------------------------------
// @Description   This global function applies a new K2 divider value 
//                to the PLL.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    K2Div: K2 divider value
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_lApplyNewK2Div,1)

// USER CODE END

Scs_ErrorType Scs_ApplyNewK2Div(unsigned int K2Div)
{
  if(K2Div == ((SCU_PLLCON3 >> SCS_POS_PLLCON3_K2DIV) & SCS_MASK_10LSB))
  {
    // New value = old value: do nothing, return without error
    return SCS_ERROR_NO_ERROR;
  }

  // set K2DIV (K2 divider value), clear K2ACK (K2 acknowledge)
  SCU_PLLCON3 = K2Div << SCS_POS_PLLCON3_K2DIV;
    
  // Wait until K2 ready = 0 with short timeout
  if(SFR_COND_3(SCU_PLLSTAT & SCS_MASK_PLLSTAT_K2RDY))
  {
    // error: timeout K2DIV
    return SCS_ERROR_TO_K2DIV;
  }

  // Set K2 acknowledge
  SCU_PLLCON3_K2ACK = 1U;
    
  // Wait until K2 ready = 1 with short timeout
  if(SFR_COND_3(!(SCU_PLLSTAT & SCS_MASK_PLLSTAT_K2RDY)))
  {
   // error: timeout K2DIV
    return SCS_ERROR_TO_K2DIV;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_ApplyNewK2Div


//*****************************************************************************
// @Function      Scs_ErrorType Scs_GoFromBaseModeToNormalMode(void)
//
//-----------------------------------------------------------------------------
// @Description   This global function performs a transition from base mode
//                 to normal mode.
//
//-----------------------------------------------------------------------------
// @Returnvalue   Error code, 0 = no error
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_GoFromBaseModeToNormalMode,1)

// USER CODE END

Scs_ErrorType Scs_GoFromBaseModeToNormalMode(void)
{
  Scs_ErrorType Error;

  // Enable high precision oscillator (may already be enabled)
  Scs_EnableHighPrecOsc(1U);

  // Set K1 divider = 1 for VCO bypass frequency of 5 MHz, check for error
  Error = Scs_lApplyNewK1Div(1U - 1U);
  if(Error)
  {
    return Error;
  }

  // Enable VCO bypass, check for error; new fSYS = internal 5 MHz
  Error = Scs_lEnableVcoBypass(1U);
  if(Error)
  {
    return Error;
  }

  // Select VCO band 1; VCOSEL = 1
  SCU_PLLCON0 |= 4U;

  // Wait band switch delay time at fSYS = internal 5 MHz
  // Start timer T13
  Scs_lStartTimer(GET_CYCLES(SCS_TIME_VCO_BAND_SWITCH, SCS_F_INT_5MHZ_MAX));

  // Wait until delay time clocks are counted
  do { }
  while(SCS_T13_RUN);

  // Set final P/N dividers and K2 divider for 10 MHz, check for error
  Error = Scs_lApplyNewVcoDivs((((unsigned int)SCS_P)) - 1U,
  (((unsigned int)SCS_N)) - 1U,(((unsigned int)SCS_K2_10MHZ)) - 1U);
  if(Error)
  {
    return Error;
  }

  // Disconnect VCO from clock input (enable free-running oscillator)
  SCU_STATCLR1 = SCS_MASK_STATCLR1_SETFINDIS;

  // Wait until base frequency is reached at fSYS = internal 5 MHz
  // Start timer T13
  Scs_lStartTimer(GET_CYCLES(SCS_TIME_VCO_FINDIS_TO_BASE, SCS_F_INT_5MHZ_MAX));

  // Wait until delay time clocks are counted
  do { }
  while(SCS_T13_RUN);

  // Wait for high precision oscillator, check for error
  Error = Scs_lCheckFreqHighPrecOsc();
  if(Error)
  {
    return Error;
  }

  // Disable VCO bypass, check for error; new fSYS ~ (50 MHz/SCS_K2_10MHZ)
  // for fVCO = 160 MHz: SCS_K2_10MHZ = 16, new fSYS ~ 3.2 MHz
  Error = Scs_lEnableVcoBypass(0U);
  if(Error)
  {
    return Error;
  }

  // Select external clock as PLL source, check for error
  Error = Scs_lSelectExternalPllClock();
  if(Error)
  {
    return Error;
  }

  // Connect VCO to clock input, new fSYS goes to 10 MHz
  SCU_STATCLR1 = SCS_MASK_STATCLR1_CLRFINDIS;

  // Wait for VCO lock at fSYS ~ 10 MHz, check for error
  Error = Scs_lWaitForVcoLock(GET_CYCLES(SCS_TIME_VCO_LOCK,
  SCS_F_INT_10MHZ_MAX));
  if(Error)
  {
    return Error;
  }

  // Enable VCOLCK emergency, check for error
  Error = Scs_lEnableVcoLockEmerg();
  if(Error)
  {
    return Error;
  }

  // Ramp up PLL from 10 MHz to fSYS = final value in normal mode,
  // check for error */
  Error = Scs_lRampPll(Scs_K2RampNormalUp);
  if(Error)
  {
    return Error;
  }

  // No error
  return SCS_ERROR_NO_ERROR;

} // End of function Scs_GoFromBaseModeToNormalMode


//*****************************************************************************
// @Function      void Scs_InitTimer(void)
//
//-----------------------------------------------------------------------------
// @Description   This global function CCU6 timer T13 as driver timer;
//                previous CCU6 register contents may be saved.
//
//-----------------------------------------------------------------------------
// @Returnvalue   None
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_InitTimer,1)

// USER CODE END

void Scs_InitTimer(void)
{
  volatile unsigned int Work;

  #if(SCS_RESTORE_TIMER_USED)
    // Save CCU60 SFRs (CCU60_TCTR4 needs not be saved)
    Ccu60KscfgSave = CCU60_KSCFG;
    Ccu60Tctr0Save = CCU60_TCTR0;
    Ccu60Tctr2Save = CCU60_TCTR2;
    Ccu60PiselhSave = CCU60_PISELH;
    Ccu60T13prSave = CCU60_T13PR;
  #endif // (SCS_RESTORE_TIMER_USED)

  // Enable CCU60 module
  CCU60_KSCFG = SCS_MASK_KSCCFG_MODEN | SCS_MASK_KSCCFG_BPMODEN;

  // Read CCU60_KSCFG back to avoid pipeline effects
  Work = CCU60_KSCFG;

  // Stop T13, clear T13
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13RR | SCS_MASK_TCTR4_T13RES;

  // Change T13 clock to fCC6/8, clear T13 additional prescaler;
  // leave other bits unchanged
  CCU60_TCTR0 = (CCU60_TCTR0 & (~(SCS_MASK_TCTR0_T13CLK |
  SCS_MASK_TCTR0_T13PRE))) | SCS_MASK_TCTR0_T13CLK_8;

  // Enable T13 single-shot, disable T13 trigger events and T13 external start;
  // leave other bits unchanged
  CCU60_TCTR2 = (CCU60_TCTR2 & (~(SCS_MASK_TCTR2_T13TEC |
  SCS_MASK_TCTR2_T13RSEL))) | SCS_MASK_TCTR2_T13SSC;

  // Enable T13 prescaler as T13 input, leave other bits unchanged
  CCU60_PISELH = CCU60_PISELH & (~SCS_MASK_PISELH_ISCNT13);

  // set T13 period to maximum
  CCU60_T13PR = 0xFFFF;

  // Enable T13 shadow transfer for period setting
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13STR;

} // End of function SCS_InitTimer


#if(SCS_RESTORE_TIMER_USED)
//*****************************************************************************
// @Function      void Scs_RestoreTimer(void)
//
//-----------------------------------------------------------------------------
// @Description   This global function restores CCU6 register contents
//                saved during the previous execution of Scs_InitTimer.
//
//-----------------------------------------------------------------------------
// @Returnvalue   None
//
//-----------------------------------------------------------------------------
// @Parameters    None
//
//-----------------------------------------------------------------------------
// @Date          2013/5/14
//
//-----------------------------------------------------------------------------

// USER CODE BEGIN (Scs_RestoreTimer,1)

// USER CODE END

void Scs_RestoreTimer(void)
{
  volatile unsigned int Work;

  // Stop T13, clear T13
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13RR | SCS_MASK_TCTR4_T13RES;

  // Restore CCU60_TCTR0
  CCU60_TCTR0 = Ccu60Tctr0Save;

  // Restore CCU60_TCTR2
  CCU60_TCTR2 = Ccu60Tctr2Save;

  // Restore CCU60_PISELH
  CCU60_PISELH = Ccu60PiselhSave;

  // Restore T13 period
  CCU60_T13PR = Ccu60T13prSave;

  // Enable T13 shadow transfer for period setting
  CCU60_TCTR4 = SCS_MASK_TCTR4_T13STR;

  // Restore CCU60_KSCFG, enable change
  CCU60_KSCFG = Ccu60KscfgSave | SCS_MASK_KSCCFG_BPMODEN |
  SCS_MASK_KSCCFG_BPNOM | SCS_MASK_KSCCFG_BPSUM | SCS_MASK_KSCCFG_BPCOM;

  // Read CCU60_KSCFG back to avoid pipeline effects
  Work = CCU60_KSCFG;

} // End of function SCS_RestoreTimer
#endif // (SCS_RESTORE_TIMER_USED)





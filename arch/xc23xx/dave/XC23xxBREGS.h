//****************************************************************************
// Description
//       Register Definition File.
// ---------------------------------------------------------------------------
// History:
//
//       Rev.     Date          Description
//       ---------------------------------------------------------------------
//
//       1.0      2013/5/14     Initial version
//
//
//****************************************************************************



#ifndef _XC23xxBREGS_H_
#define _XC23xxBREGS_H_


//****************************************************************************
// @Typedefs
//****************************************************************************

typedef unsigned char  ubyte;    // 1 byte unsigned; prefix: ub 
typedef signed char    sbyte;    // 1 byte signed;   prefix: sb 
typedef unsigned int   uword;    // 2 byte unsigned; prefix: uw 
typedef signed int     sword;    // 2 byte signed;   prefix: sw 
typedef unsigned long  ulong;    // 4 byte unsigned; prefix: ul 
typedef signed long    slong;    // 4 byte signed;   prefix: sl 
typedef unsigned short ushort;   // 2 byte unsigned; prefix: us 
typedef signed short   sshort;   // 2 byte signed;   prefix: ss 

typedef volatile struct
{
  unsigned int    bit0      : 1;
  unsigned int    bit1      : 1;
  unsigned int    bit2      : 1;
  unsigned int    bit3      : 1;
  unsigned int    bit4      : 1;
  unsigned int    bit5      : 1;
  unsigned int    bit6      : 1;
  unsigned int    bit7      : 1;
  unsigned int    bit8      : 1;
  unsigned int    bit9      : 1;
  unsigned int    bit10     : 1;
  unsigned int    bit11     : 1;
  unsigned int    bit12     : 1;
  unsigned int    bit13     : 1;
  unsigned int    bit14     : 1;
  unsigned int    bit15     : 1;
}  T_Reg16;

//****************************************************************************
// @Declaration of SFRs
//****************************************************************************



// Alias Register 0
#define ADC0_ALR0              (*((uword volatile *) 0xE01C))

// Arbitration Slot Enable Register
#define ADC0_ASENR             (*((uword volatile *) 0xE018))

// Broken Wire Detection Configuration Register
#define ADC0_BWDCFGR           (*((uword volatile *) 0xE0CA))

// Broken Wire Detection Enable Register
#define ADC0_BWDENR            (*((uword volatile *) 0xE0C8))

// Channel 0 Control Register
#define ADC0_CHCTR0            (*((uword volatile *) 0xE020))

// Channel 1 Control Register
#define ADC0_CHCTR1            (*((uword volatile *) 0xE022))

// Channel 10 Control Register
#define ADC0_CHCTR10           (*((uword volatile *) 0xE034))

// Channel 11 Control Register
#define ADC0_CHCTR11           (*((uword volatile *) 0xE036))

// Channel 12 Control Register
#define ADC0_CHCTR12           (*((uword volatile *) 0xE038))

// Channel 13 Control Register
#define ADC0_CHCTR13           (*((uword volatile *) 0xE03A))

// Channel 14 Control Register
#define ADC0_CHCTR14           (*((uword volatile *) 0xE03C))

// Channel 15 Control Register
#define ADC0_CHCTR15           (*((uword volatile *) 0xE03E))

// Channel 2 Control Register
#define ADC0_CHCTR2            (*((uword volatile *) 0xE024))

// Channel 3 Control Register
#define ADC0_CHCTR3            (*((uword volatile *) 0xE026))

// Channel 4 Control Register
#define ADC0_CHCTR4            (*((uword volatile *) 0xE028))

// Channel 5 Control Register
#define ADC0_CHCTR5            (*((uword volatile *) 0xE02A))

// Channel 6 Control Register
#define ADC0_CHCTR6            (*((uword volatile *) 0xE02C))

// Channel 7 Control Register
#define ADC0_CHCTR7            (*((uword volatile *) 0xE02E))

// Channel 8 Control Register
#define ADC0_CHCTR8            (*((uword volatile *) 0xE030))

// Channel 9 Control Register
#define ADC0_CHCTR9            (*((uword volatile *) 0xE032))

// Channel Event Indication Clear Register
#define ADC0_CHINCR            (*((uword volatile *) 0xE092))

// Channel Event Indication Flag Register
#define ADC0_CHINFR            (*((uword volatile *) 0xE090))

// Channel Interrupt Node Pointer Register 0
#define ADC0_CHINPR0           (*((uword volatile *) 0xE098))

// Channel Interrupt Node Pointer Register 12
#define ADC0_CHINPR12          (*((uword volatile *) 0xE09E))

// Channel Interrupt Node Pointer Register 4
#define ADC0_CHINPR4           (*((uword volatile *) 0xE09A))

// Channel Interrupt Node Pointer Register 8
#define ADC0_CHINPR8           (*((uword volatile *) 0xE09C))

// Conversion Request Control Register 1
#define ADC0_CRCR1             (*((uword volatile *) 0xE0E8))

// Conversion Request Mode Register 1
#define ADC0_CRMR1             (*((uword volatile *) 0xE0EC))

// Conversion Request Pending Register 1
#define ADC0_CRPR1             (*((uword volatile *) 0xE0EA))

// External Multiplexer Control Register
#define ADC0_EMCTR             (*((uword volatile *) 0xE0D0))

// External Multiplexer Enable Register
#define ADC0_EMENR             (*((uword volatile *) 0xE0D6))

// Event Indication Clear Register
#define ADC0_EVINCR            (*((uword volatile *) 0xE0A2))

// Event Indication Flag Register
#define ADC0_EVINFR            (*((uword volatile *) 0xE0A0))

// Event Interrupt Node Pointer Register 0
#define ADC0_EVINPR0           (*((uword volatile *) 0xE0A8))

// Event Interrupt Node Pointer Register 12
#define ADC0_EVINPR12          (*((uword volatile *) 0xE0AE))

// Event Interrupt Node Pointer Register 8
#define ADC0_EVINPR8           (*((uword volatile *) 0xE0AC))

// Global Control Register
#define ADC0_GLOBCTR           (*((uword volatile *) 0xE010))

// Global Status Register
#define ADC0_GLOBSTR           (*((uword volatile *) 0xE012))

// Module Identification Register
#define ADC0_ID                (*((uword volatile *) 0xE008))

// Input Class Register 0
#define ADC0_INPCR0            (*((uword volatile *) 0xE0C0))

// Input Class Register 1
#define ADC0_INPCR1            (*((uword volatile *) 0xE0C2))

// Kernel State Configuration Register
#define ADC0_KSCFG             (*((uword volatile *) 0xE00C))

// Limit Check Boundary Register 0
#define ADC0_LCBR0             (*((uword volatile *) 0xE084))

// Limit Check Boundary Register 1
#define ADC0_LCBR1             (*((uword volatile *) 0xE086))

// Limit Check Boundary Register 2
#define ADC0_LCBR2             (*((uword volatile *) 0xE088))

// Limit Check Boundary Register 3
#define ADC0_LCBR3             (*((uword volatile *) 0xE08A))

// Queue 0 Register 0
#define ADC0_Q0R0              (*((uword volatile *) 0xE0E4))

// Queue 2 Register 0
#define ADC0_Q0R2              (*((uword volatile *) 0xE0F4))

// Queue 0 Backup Register
#define ADC0_QBUR0             (*((uword volatile *) 0xE0E6))

// Queue 2 Backup Register
#define ADC0_QBUR2             (*((uword volatile *) 0xE0F6))

// Queue 0 Input Register
#define ADC0_QINR0             (*((uword volatile *) 0xE0E6))

// Queue 2 Input Register
#define ADC0_QINR2             (*((uword volatile *) 0xE0F6))

// Queue 0 Mode Register
#define ADC0_QMR0              (*((uword volatile *) 0xE0E0))

// Queue 2 Mode Register
#define ADC0_QMR2              (*((uword volatile *) 0xE0F0))

// Queue 0 Status Register
#define ADC0_QSR0              (*((uword volatile *) 0xE0E2))

// Queue 2 Status Register
#define ADC0_QSR2              (*((uword volatile *) 0xE0F2))

// Result Control Register 0
#define ADC0_RCR0              (*((uword volatile *) 0xE0B0))

// Result Control Register 1
#define ADC0_RCR1              (*((uword volatile *) 0xE0B2))

// Result Control Register 2
#define ADC0_RCR2              (*((uword volatile *) 0xE0B4))

// Result Control Register 3
#define ADC0_RCR3              (*((uword volatile *) 0xE0B6))

// Result Control Register 4
#define ADC0_RCR4              (*((uword volatile *) 0xE0B8))

// Result Control Register 5
#define ADC0_RCR5              (*((uword volatile *) 0xE0BA))

// Result Control Register 6
#define ADC0_RCR6              (*((uword volatile *) 0xE0BC))

// Result Control Register 7
#define ADC0_RCR7              (*((uword volatile *) 0xE0BE))

// Result Register 0
#define ADC0_RESR0             (*((uword volatile *) 0xE040))

// Result Register 1
#define ADC0_RESR1             (*((uword volatile *) 0xE042))

// Result Register 2
#define ADC0_RESR2             (*((uword volatile *) 0xE044))

// Result Register 3
#define ADC0_RESR3             (*((uword volatile *) 0xE046))

// Result Register 4
#define ADC0_RESR4             (*((uword volatile *) 0xE048))

// Result Register 5
#define ADC0_RESR5             (*((uword volatile *) 0xE04A))

// Result Register 6
#define ADC0_RESR6             (*((uword volatile *) 0xE04C))

// Result Register 7
#define ADC0_RESR7             (*((uword volatile *) 0xE04E))

// Result Register 0, View A
#define ADC0_RESRA0            (*((uword volatile *) 0xE050))

// Result Register 1, View A
#define ADC0_RESRA1            (*((uword volatile *) 0xE052))

// Result Register 2, View A
#define ADC0_RESRA2            (*((uword volatile *) 0xE054))

// Result Register 3, View A
#define ADC0_RESRA3            (*((uword volatile *) 0xE056))

// Result Register 4, View A
#define ADC0_RESRA4            (*((uword volatile *) 0xE058))

// Result Register 5, View A
#define ADC0_RESRA5            (*((uword volatile *) 0xE05A))

// Result Register 6, View A
#define ADC0_RESRA6            (*((uword volatile *) 0xE05C))

// Result Register 7, View A
#define ADC0_RESRA7            (*((uword volatile *) 0xE05E))

// Result Register 0, View AV
#define ADC0_RESRAV0           (*((uword volatile *) 0xE070))

// Result Register 1, View AV
#define ADC0_RESRAV1           (*((uword volatile *) 0xE072))

// Result Register 2, View AV
#define ADC0_RESRAV2           (*((uword volatile *) 0xE074))

// Result Register 3, View AV
#define ADC0_RESRAV3           (*((uword volatile *) 0xE076))

// Result Register 4, View AV
#define ADC0_RESRAV4           (*((uword volatile *) 0xE078))

// Result Register 5, View AV
#define ADC0_RESRAV5           (*((uword volatile *) 0xE07A))

// Result Register 6, View AV
#define ADC0_RESRAV6           (*((uword volatile *) 0xE07C))

// Result Register 7, View AV
#define ADC0_RESRAV7           (*((uword volatile *) 0xE07E))

// Result Register 0, View V
#define ADC0_RESRV0            (*((uword volatile *) 0xE060))

// Result Register 1, View V
#define ADC0_RESRV1            (*((uword volatile *) 0xE062))

// Result Register 2, View V
#define ADC0_RESRV2            (*((uword volatile *) 0xE064))

// Result Register 3, View V
#define ADC0_RESRV3            (*((uword volatile *) 0xE066))

// Result Register 4, View V
#define ADC0_RESRV4            (*((uword volatile *) 0xE068))

// Result Register 5, View V
#define ADC0_RESRV5            (*((uword volatile *) 0xE06A))

// Result Register 6, View V
#define ADC0_RESRV6            (*((uword volatile *) 0xE06C))

// Result Register 7, View V
#define ADC0_RESRV7            (*((uword volatile *) 0xE06E))

// Request Source 0 Input Register
#define ADC0_RSIR0             (*((uword volatile *) 0xE000))

// Request Source 1 Input Register
#define ADC0_RSIR1             (*((uword volatile *) 0xE002))

// Request Source 2 Input Register
#define ADC0_RSIR2             (*((uword volatile *) 0xE004))

// Request Source Priority Register 0
#define ADC0_RSPR0             (*((uword volatile *) 0xE014))

// Result Status Shadow Register
#define ADC0_RSSR              (*((uword volatile *) 0xE082))

// Synchronization Control Register
#define ADC0_SYNCTR            (*((uword volatile *) 0xE01A))

// Valid Flag Register
#define ADC0_VFR               (*((uword volatile *) 0xE080))

// Alias Register 0
#define ADC1_ALR0              (*((uword volatile *) 0xE11C))

// Arbitration Slot Enable Register
#define ADC1_ASENR             (*((uword volatile *) 0xE118))

// Broken Wire Detection Configuration Register
#define ADC1_BWDCFGR           (*((uword volatile *) 0xE1CA))

// Broken Wire Detection Enable Register
#define ADC1_BWDENR            (*((uword volatile *) 0xE1C8))

// Channel 0 Control Register
#define ADC1_CHCTR0            (*((uword volatile *) 0xE120))

// Channel 1 Control Register
#define ADC1_CHCTR1            (*((uword volatile *) 0xE122))

// Channel 10 Control Register
#define ADC1_CHCTR10           (*((uword volatile *) 0xE134))

// Channel 11 Control Register
#define ADC1_CHCTR11           (*((uword volatile *) 0xE136))

// Channel 12 Control Register
#define ADC1_CHCTR12           (*((uword volatile *) 0xE138))

// Channel 13 Control Register
#define ADC1_CHCTR13           (*((uword volatile *) 0xE13A))

// Channel 14 Control Register
#define ADC1_CHCTR14           (*((uword volatile *) 0xE13C))

// Channel 15 Control Register
#define ADC1_CHCTR15           (*((uword volatile *) 0xE13E))

// Channel 2 Control Register
#define ADC1_CHCTR2            (*((uword volatile *) 0xE124))

// Channel 3 Control Register
#define ADC1_CHCTR3            (*((uword volatile *) 0xE126))

// Channel 4 Control Register
#define ADC1_CHCTR4            (*((uword volatile *) 0xE128))

// Channel 5 Control Register
#define ADC1_CHCTR5            (*((uword volatile *) 0xE12A))

// Channel 6 Control Register
#define ADC1_CHCTR6            (*((uword volatile *) 0xE12C))

// Channel 7 Control Register
#define ADC1_CHCTR7            (*((uword volatile *) 0xE12E))

// Channel 8 Control Register
#define ADC1_CHCTR8            (*((uword volatile *) 0xE130))

// Channel 9 Control Register
#define ADC1_CHCTR9            (*((uword volatile *) 0xE132))

// Channel Event Indication Clear Register
#define ADC1_CHINCR            (*((uword volatile *) 0xE192))

// Channel Event Indication Flag Register
#define ADC1_CHINFR            (*((uword volatile *) 0xE190))

// Channel Interrupt Node Pointer Register 0
#define ADC1_CHINPR0           (*((uword volatile *) 0xE198))

// Channel Interrupt Node Pointer Register 12
#define ADC1_CHINPR12          (*((uword volatile *) 0xE19E))

// Channel Interrupt Node Pointer Register 4
#define ADC1_CHINPR4           (*((uword volatile *) 0xE19A))

// Channel Interrupt Node Pointer Register 8
#define ADC1_CHINPR8           (*((uword volatile *) 0xE19C))

// Conversion Request Control Register 1
#define ADC1_CRCR1             (*((uword volatile *) 0xE1E8))

// Conversion Request Mode Register 1
#define ADC1_CRMR1             (*((uword volatile *) 0xE1EC))

// Conversion Request Pending Register 1
#define ADC1_CRPR1             (*((uword volatile *) 0xE1EA))

// External Multiplexer Control Register
#define ADC1_EMCTR             (*((uword volatile *) 0xE1D0))

// External Multiplexer Enable Register
#define ADC1_EMENR             (*((uword volatile *) 0xE1D6))

// Event Indication Clear Register
#define ADC1_EVINCR            (*((uword volatile *) 0xE1A2))

// Event Indication Flag Register
#define ADC1_EVINFR            (*((uword volatile *) 0xE1A0))

// Event Interrupt Node Pointer Register 0
#define ADC1_EVINPR0           (*((uword volatile *) 0xE1A8))

// Event Interrupt Node Pointer Register 12
#define ADC1_EVINPR12          (*((uword volatile *) 0xE1AE))

// Event Interrupt Node Pointer Register 8
#define ADC1_EVINPR8           (*((uword volatile *) 0xE1AC))

// Global Control Register
#define ADC1_GLOBCTR           (*((uword volatile *) 0xE110))

// Global Status Register
#define ADC1_GLOBSTR           (*((uword volatile *) 0xE112))

// Module Identification Register
#define ADC1_ID                (*((uword volatile *) 0xE108))

// Input Class Register 0
#define ADC1_INPCR0            (*((uword volatile *) 0xE1C0))

// Input Class Register 1
#define ADC1_INPCR1            (*((uword volatile *) 0xE1C2))

// Limit Check Boundary Register 0
#define ADC1_LCBR0             (*((uword volatile *) 0xE184))

// Limit Check Boundary Register 1
#define ADC1_LCBR1             (*((uword volatile *) 0xE186))

// Limit Check Boundary Register 2
#define ADC1_LCBR2             (*((uword volatile *) 0xE188))

// Limit Check Boundary Register 3
#define ADC1_LCBR3             (*((uword volatile *) 0xE18A))

// Queue 0 Register 0
#define ADC1_Q0R0              (*((uword volatile *) 0xE1E4))

// Queue 2 Register 0
#define ADC1_Q0R2              (*((uword volatile *) 0xE1F4))

// Queue 0 Backup Register
#define ADC1_QBUR0             (*((uword volatile *) 0xE1E6))

// Queue 2 Backup Register
#define ADC1_QBUR2             (*((uword volatile *) 0xE1F6))

// Queue 0 Input Register
#define ADC1_QINR0             (*((uword volatile *) 0xE1E6))

// Queue 2 Input Register
#define ADC1_QINR2             (*((uword volatile *) 0xE1F6))

// Queue 0 Mode Register
#define ADC1_QMR0              (*((uword volatile *) 0xE1E0))

// Queue 2 Mode Register
#define ADC1_QMR2              (*((uword volatile *) 0xE1F0))

// Queue 0 Status Register
#define ADC1_QSR0              (*((uword volatile *) 0xE1E2))

// Queue 2 Status Register
#define ADC1_QSR2              (*((uword volatile *) 0xE1F2))

// Result Control Register 0
#define ADC1_RCR0              (*((uword volatile *) 0xE1B0))

// Result Control Register 1
#define ADC1_RCR1              (*((uword volatile *) 0xE1B2))

// Result Control Register 2
#define ADC1_RCR2              (*((uword volatile *) 0xE1B4))

// Result Control Register 3
#define ADC1_RCR3              (*((uword volatile *) 0xE1B6))

// Result Control Register 4
#define ADC1_RCR4              (*((uword volatile *) 0xE1B8))

// Result Control Register 5
#define ADC1_RCR5              (*((uword volatile *) 0xE1BA))

// Result Control Register 6
#define ADC1_RCR6              (*((uword volatile *) 0xE1BC))

// Result Control Register 7
#define ADC1_RCR7              (*((uword volatile *) 0xE1BE))

// Result Register 0
#define ADC1_RESR0             (*((uword volatile *) 0xE140))

// Result Register 1
#define ADC1_RESR1             (*((uword volatile *) 0xE142))

// Result Register 2
#define ADC1_RESR2             (*((uword volatile *) 0xE144))

// Result Register 3
#define ADC1_RESR3             (*((uword volatile *) 0xE146))

// Result Register 4
#define ADC1_RESR4             (*((uword volatile *) 0xE148))

// Result Register 5
#define ADC1_RESR5             (*((uword volatile *) 0xE14A))

// Result Register 6
#define ADC1_RESR6             (*((uword volatile *) 0xE14C))

// Result Register 7
#define ADC1_RESR7             (*((uword volatile *) 0xE14E))

// Result Register 0, View A
#define ADC1_RESRA0            (*((uword volatile *) 0xE150))

// Result Register 1, View A
#define ADC1_RESRA1            (*((uword volatile *) 0xE152))

// Result Register 2, View A
#define ADC1_RESRA2            (*((uword volatile *) 0xE154))

// Result Register 3, View A
#define ADC1_RESRA3            (*((uword volatile *) 0xE156))

// Result Register 4, View A
#define ADC1_RESRA4            (*((uword volatile *) 0xE158))

// Result Register 5, View A
#define ADC1_RESRA5            (*((uword volatile *) 0xE15A))

// Result Register 6, View A
#define ADC1_RESRA6            (*((uword volatile *) 0xE15C))

// Result Register 7, View A
#define ADC1_RESRA7            (*((uword volatile *) 0xE15E))

// Result Register 0, View AV
#define ADC1_RESRAV0           (*((uword volatile *) 0xE170))

// Result Register 1, View AV
#define ADC1_RESRAV1           (*((uword volatile *) 0xE172))

// Result Register 2, View AV
#define ADC1_RESRAV2           (*((uword volatile *) 0xE174))

// Result Register 3, View AV
#define ADC1_RESRAV3           (*((uword volatile *) 0xE176))

// Result Register 4, View AV
#define ADC1_RESRAV4           (*((uword volatile *) 0xE178))

// Result Register 5, View AV
#define ADC1_RESRAV5           (*((uword volatile *) 0xE17A))

// Result Register 6, View AV
#define ADC1_RESRAV6           (*((uword volatile *) 0xE17C))

// Result Register 7, View AV
#define ADC1_RESRAV7           (*((uword volatile *) 0xE17E))

// Result Register 0, View V
#define ADC1_RESRV0            (*((uword volatile *) 0xE160))

// Result Register 1, View V
#define ADC1_RESRV1            (*((uword volatile *) 0xE162))

// Result Register 2, View V
#define ADC1_RESRV2            (*((uword volatile *) 0xE164))

// Result Register 3, View V
#define ADC1_RESRV3            (*((uword volatile *) 0xE166))

// Result Register 4, View V
#define ADC1_RESRV4            (*((uword volatile *) 0xE168))

// Result Register 5, View V
#define ADC1_RESRV5            (*((uword volatile *) 0xE16A))

// Result Register 6, View V
#define ADC1_RESRV6            (*((uword volatile *) 0xE16C))

// Result Register 7, View V
#define ADC1_RESRV7            (*((uword volatile *) 0xE16E))

// Request Source 0 Input Register
#define ADC1_RSIR0             (*((uword volatile *) 0xE100))

// Request Source 1 Input Register
#define ADC1_RSIR1             (*((uword volatile *) 0xE102))

// Request Source 2 Input Register
#define ADC1_RSIR2             (*((uword volatile *) 0xE104))

// Request Source Priority Register 0
#define ADC1_RSPR0             (*((uword volatile *) 0xE114))

// Result Status Shadow Register
#define ADC1_RSSR              (*((uword volatile *) 0xE182))

// Synchronization Control Register
#define ADC1_SYNCTR            (*((uword volatile *) 0xE11A))

// Valid Flag Register
#define ADC1_VFR               (*((uword volatile *) 0xE180))

// ADC Interrupt Control Reg. 0
#define ADC_0IC                (*((uword volatile *) 0xFF70))
#define ADC_0IC_GPX                      ((T_Reg16 *) 0xFF70)->bit8
#define ADC_0IC_IE                       ((T_Reg16 *) 0xFF70)->bit6
#define ADC_0IC_IR                       ((T_Reg16 *) 0xFF70)->bit7

// ADC Interrupt Control Reg. 1
#define ADC_1IC                (*((uword volatile *) 0xFF72))
#define ADC_1IC_GPX                      ((T_Reg16 *) 0xFF72)->bit8
#define ADC_1IC_IE                       ((T_Reg16 *) 0xFF72)->bit6
#define ADC_1IC_IR                       ((T_Reg16 *) 0xFF72)->bit7

// ADC Interrupt Control Reg. 2
#define ADC_2IC                (*((uword volatile *) 0xFF74))
#define ADC_2IC_GPX                      ((T_Reg16 *) 0xFF74)->bit8
#define ADC_2IC_IE                       ((T_Reg16 *) 0xFF74)->bit6
#define ADC_2IC_IR                       ((T_Reg16 *) 0xFF74)->bit7

// ADC Interrupt Control Reg. 3
#define ADC_3IC                (*((uword volatile *) 0xFF76))
#define ADC_3IC_GPX                      ((T_Reg16 *) 0xFF76)->bit8
#define ADC_3IC_IE                       ((T_Reg16 *) 0xFF76)->bit6
#define ADC_3IC_IR                       ((T_Reg16 *) 0xFF76)->bit7

// ADC Interrupt Control Reg. 4
#define ADC_4IC                (*((uword volatile *) 0xFF78))
#define ADC_4IC_GPX                      ((T_Reg16 *) 0xFF78)->bit8
#define ADC_4IC_IE                       ((T_Reg16 *) 0xFF78)->bit6
#define ADC_4IC_IR                       ((T_Reg16 *) 0xFF78)->bit7

// ADC Interrupt Control Reg. 5
#define ADC_5IC                (*((uword volatile *) 0xFF7A))
#define ADC_5IC_GPX                      ((T_Reg16 *) 0xFF7A)->bit8
#define ADC_5IC_IE                       ((T_Reg16 *) 0xFF7A)->bit6
#define ADC_5IC_IR                       ((T_Reg16 *) 0xFF7A)->bit7

// ADC Interrupt Control Reg. 6
#define ADC_6IC                (*((uword volatile *) 0xFF7C))
#define ADC_6IC_GPX                      ((T_Reg16 *) 0xFF7C)->bit8
#define ADC_6IC_IE                       ((T_Reg16 *) 0xFF7C)->bit6
#define ADC_6IC_IR                       ((T_Reg16 *) 0xFF7C)->bit7

// ADC Interrupt Control Reg. 7
#define ADC_7IC                (*((uword volatile *) 0xFF7E))
#define ADC_7IC_GPX                      ((T_Reg16 *) 0xFF7E)->bit8
#define ADC_7IC_IE                       ((T_Reg16 *) 0xFF7E)->bit6
#define ADC_7IC_IR                       ((T_Reg16 *) 0xFF7E)->bit7

// Address Range/Size for CS1
#define ADDRSEL1               (*((uword volatile *) 0xEE1E))

// Address Range/Size for CS2
#define ADDRSEL2               (*((uword volatile *) 0xEE26))

// Address Range/Size for CS3
#define ADDRSEL3               (*((uword volatile *) 0xEE2E))

// Address Range/Size for CS4
#define ADDRSEL4               (*((uword volatile *) 0xEE36))

// Register Bank Selection Reg. 0
#define BNKSEL0                (*((uword volatile *) 0xEC20))

// Register Bank Selection Reg. 1
#define BNKSEL1                (*((uword volatile *) 0xEC22))

// Register Bank Selection Reg. 2
#define BNKSEL2                (*((uword volatile *) 0xEC24))

// Register Bank Selection Reg. 3
#define BNKSEL3                (*((uword volatile *) 0xEC26))

// CAN Interrupt Control Reg. 0
#define CAN_0IC                (*((uword volatile *) 0xF140))
#define CAN_0IC_GPX                      ((T_Reg16 *) 0xF140)->bit8
#define CAN_0IC_IE                       ((T_Reg16 *) 0xF140)->bit6
#define CAN_0IC_IR                       ((T_Reg16 *) 0xF140)->bit7

// CAN Interrupt Control Reg. 10
#define CAN_10IC               (*((uword volatile *) 0xF154))
#define CAN_10IC_GPX                      ((T_Reg16 *) 0xF154)->bit8
#define CAN_10IC_IE                       ((T_Reg16 *) 0xF154)->bit6
#define CAN_10IC_IR                       ((T_Reg16 *) 0xF154)->bit7

// CAN Interrupt Control Reg. 11
#define CAN_11IC               (*((uword volatile *) 0xF156))
#define CAN_11IC_GPX                      ((T_Reg16 *) 0xF156)->bit8
#define CAN_11IC_IE                       ((T_Reg16 *) 0xF156)->bit6
#define CAN_11IC_IR                       ((T_Reg16 *) 0xF156)->bit7

// CAN Interrupt Control Reg. 12
#define CAN_12IC               (*((uword volatile *) 0xF158))
#define CAN_12IC_GPX                      ((T_Reg16 *) 0xF158)->bit8
#define CAN_12IC_IE                       ((T_Reg16 *) 0xF158)->bit6
#define CAN_12IC_IR                       ((T_Reg16 *) 0xF158)->bit7

// CAN Interrupt Control Reg. 13
#define CAN_13IC               (*((uword volatile *) 0xF15A))
#define CAN_13IC_GPX                      ((T_Reg16 *) 0xF15A)->bit8
#define CAN_13IC_IE                       ((T_Reg16 *) 0xF15A)->bit6
#define CAN_13IC_IR                       ((T_Reg16 *) 0xF15A)->bit7

// CAN Interrupt Control Reg. 14
#define CAN_14IC               (*((uword volatile *) 0xF15C))
#define CAN_14IC_GPX                      ((T_Reg16 *) 0xF15C)->bit8
#define CAN_14IC_IE                       ((T_Reg16 *) 0xF15C)->bit6
#define CAN_14IC_IR                       ((T_Reg16 *) 0xF15C)->bit7

// CAN Interrupt Control Reg. 15
#define CAN_15IC               (*((uword volatile *) 0xF15E))
#define CAN_15IC_GPX                      ((T_Reg16 *) 0xF15E)->bit8
#define CAN_15IC_IE                       ((T_Reg16 *) 0xF15E)->bit6
#define CAN_15IC_IR                       ((T_Reg16 *) 0xF15E)->bit7

// CAN Interrupt Control Reg. 1
#define CAN_1IC                (*((uword volatile *) 0xF142))
#define CAN_1IC_GPX                      ((T_Reg16 *) 0xF142)->bit8
#define CAN_1IC_IE                       ((T_Reg16 *) 0xF142)->bit6
#define CAN_1IC_IR                       ((T_Reg16 *) 0xF142)->bit7

// CAN Interrupt Control Reg. 2
#define CAN_2IC                (*((uword volatile *) 0xF144))
#define CAN_2IC_GPX                      ((T_Reg16 *) 0xF144)->bit8
#define CAN_2IC_IE                       ((T_Reg16 *) 0xF144)->bit6
#define CAN_2IC_IR                       ((T_Reg16 *) 0xF144)->bit7

// CAN Interrupt Control Reg. 3
#define CAN_3IC                (*((uword volatile *) 0xF146))
#define CAN_3IC_GPX                      ((T_Reg16 *) 0xF146)->bit8
#define CAN_3IC_IE                       ((T_Reg16 *) 0xF146)->bit6
#define CAN_3IC_IR                       ((T_Reg16 *) 0xF146)->bit7

// CAN Interrupt Control Reg. 4
#define CAN_4IC                (*((uword volatile *) 0xF148))
#define CAN_4IC_GPX                      ((T_Reg16 *) 0xF148)->bit8
#define CAN_4IC_IE                       ((T_Reg16 *) 0xF148)->bit6
#define CAN_4IC_IR                       ((T_Reg16 *) 0xF148)->bit7

// CAN Interrupt Control Reg. 5
#define CAN_5IC                (*((uword volatile *) 0xF14A))
#define CAN_5IC_GPX                      ((T_Reg16 *) 0xF14A)->bit8
#define CAN_5IC_IE                       ((T_Reg16 *) 0xF14A)->bit6
#define CAN_5IC_IR                       ((T_Reg16 *) 0xF14A)->bit7

// CAN Interrupt Control Reg. 6
#define CAN_6IC                (*((uword volatile *) 0xF14C))
#define CAN_6IC_GPX                      ((T_Reg16 *) 0xF14C)->bit8
#define CAN_6IC_IE                       ((T_Reg16 *) 0xF14C)->bit6
#define CAN_6IC_IR                       ((T_Reg16 *) 0xF14C)->bit7

// CAN Interrupt Control Reg. 7
#define CAN_7IC                (*((uword volatile *) 0xF14E))
#define CAN_7IC_GPX                      ((T_Reg16 *) 0xF14E)->bit8
#define CAN_7IC_IE                       ((T_Reg16 *) 0xF14E)->bit6
#define CAN_7IC_IR                       ((T_Reg16 *) 0xF14E)->bit7

// CAN Interrupt Control Reg. 8
#define CAN_8IC                (*((uword volatile *) 0xF150))
#define CAN_8IC_GPX                      ((T_Reg16 *) 0xF150)->bit8
#define CAN_8IC_IE                       ((T_Reg16 *) 0xF150)->bit6
#define CAN_8IC_IR                       ((T_Reg16 *) 0xF150)->bit7

// CAN Interrupt Control Reg. 9
#define CAN_9IC                (*((uword volatile *) 0xF152))
#define CAN_9IC_GPX                      ((T_Reg16 *) 0xF152)->bit8
#define CAN_9IC_IE                       ((T_Reg16 *) 0xF152)->bit6
#define CAN_9IC_IR                       ((T_Reg16 *) 0xF152)->bit7

// Error Detection and Correction Register High
#define CAN_EDCRH              (*((uword volatile far *) 0x200082))

// Error Detection and Correction Register Low
#define CAN_EDCRL              (*((uword volatile far *) 0x200080))

// Fractional Divider Register H
#define CAN_FDRH               (*((uword volatile far *) 0x20000E))

// Fractional Divider Register L
#define CAN_FDRL               (*((uword volatile far *) 0x20000C))

// Module Identification Register
#define CAN_ID                 (*((uword volatile far *) 0x200008))

// List Register 0 High
#define CAN_LIST0H             (*((uword volatile far *) 0x200102))

// List Register 0 Low
#define CAN_LIST0L             (*((uword volatile far *) 0x200100))

// List Register 1 High
#define CAN_LIST1H             (*((uword volatile far *) 0x200106))

// List Register 1 Low
#define CAN_LIST1L             (*((uword volatile far *) 0x200104))

// List Register 2 High
#define CAN_LIST2H             (*((uword volatile far *) 0x20010A))

// List Register 2 Low
#define CAN_LIST2L             (*((uword volatile far *) 0x200108))

// List Register 3 High
#define CAN_LIST3H             (*((uword volatile far *) 0x20010E))

// List Register 3 Low
#define CAN_LIST3L             (*((uword volatile far *) 0x20010C))

// List Register 4 High
#define CAN_LIST4H             (*((uword volatile far *) 0x200112))

// List Register 4 Low
#define CAN_LIST4L             (*((uword volatile far *) 0x200110))

// List Register 5 High
#define CAN_LIST5H             (*((uword volatile far *) 0x200116))

// List Register 5 Low
#define CAN_LIST5L             (*((uword volatile far *) 0x200114))

// List Register 6 High
#define CAN_LIST6H             (*((uword volatile far *) 0x20011A))

// List Register 6 Low
#define CAN_LIST6L             (*((uword volatile far *) 0x200118))

// List Register 7 High
#define CAN_LIST7H             (*((uword volatile far *) 0x20011E))

// List Register 7 Low
#define CAN_LIST7L             (*((uword volatile far *) 0x20011C))

// Module Control Register
#define CAN_MCR                (*((uword volatile far *) 0x2001C8))

// Module Interrupt Trigger Register
#define CAN_MITR               (*((uword volatile far *) 0x2001CC))

// Message Object 0 Acceptance Mask Register High
#define CAN_MOAMR0H            (*((uword volatile far *) 0x20100E))

// Message Object 0 Acceptance Mask Register Low
#define CAN_MOAMR0L            (*((uword volatile far *) 0x20100C))

// Message Object 100 Acceptance Mask Register High
#define CAN_MOAMR100H          (*((uword volatile far *) 0x201C8E))

// Message Object 100 Acceptance Mask Register Low
#define CAN_MOAMR100L          (*((uword volatile far *) 0x201C8C))

// Message Object 101 Acceptance Mask Register High
#define CAN_MOAMR101H          (*((uword volatile far *) 0x201CAE))

// Message Object 101 Acceptance Mask Register Low
#define CAN_MOAMR101L          (*((uword volatile far *) 0x201CAC))

// Message Object 102 Acceptance Mask Register High
#define CAN_MOAMR102H          (*((uword volatile far *) 0x201CCE))

// Message Object 102 Acceptance Mask Register Low
#define CAN_MOAMR102L          (*((uword volatile far *) 0x201CCC))

// Message Object 103 Acceptance Mask Register High
#define CAN_MOAMR103H          (*((uword volatile far *) 0x201CEE))

// Message Object 103 Acceptance Mask Register Low
#define CAN_MOAMR103L          (*((uword volatile far *) 0x201CEC))

// Message Object 104 Acceptance Mask Register High
#define CAN_MOAMR104H          (*((uword volatile far *) 0x201D0E))

// Message Object 104 Acceptance Mask Register Low
#define CAN_MOAMR104L          (*((uword volatile far *) 0x201D0C))

// Message Object 105 Acceptance Mask Register High
#define CAN_MOAMR105H          (*((uword volatile far *) 0x201D2E))

// Message Object 105 Acceptance Mask Register Low
#define CAN_MOAMR105L          (*((uword volatile far *) 0x201D2C))

// Message Object 106 Acceptance Mask Register High
#define CAN_MOAMR106H          (*((uword volatile far *) 0x201D4E))

// Message Object 106 Acceptance Mask Register Low
#define CAN_MOAMR106L          (*((uword volatile far *) 0x201D4C))

// Message Object 107 Acceptance Mask Register High
#define CAN_MOAMR107H          (*((uword volatile far *) 0x201D6E))

// Message Object 107 Acceptance Mask Register Low
#define CAN_MOAMR107L          (*((uword volatile far *) 0x201D6C))

// Message Object 108 Acceptance Mask Register High
#define CAN_MOAMR108H          (*((uword volatile far *) 0x201D8E))

// Message Object 108 Acceptance Mask Register Low
#define CAN_MOAMR108L          (*((uword volatile far *) 0x201D8C))

// Message Object 109 Acceptance Mask Register High
#define CAN_MOAMR109H          (*((uword volatile far *) 0x201DAE))

// Message Object 109 Acceptance Mask Register Low
#define CAN_MOAMR109L          (*((uword volatile far *) 0x201DAC))

// Message Object 10 Acceptance Mask Register High
#define CAN_MOAMR10H           (*((uword volatile far *) 0x20114E))

// Message Object 10 Acceptance Mask Register Low
#define CAN_MOAMR10L           (*((uword volatile far *) 0x20114C))

// Message Object 110 Acceptance Mask Register High
#define CAN_MOAMR110H          (*((uword volatile far *) 0x201DCE))

// Message Object 110 Acceptance Mask Register Low
#define CAN_MOAMR110L          (*((uword volatile far *) 0x201DCC))

// Message Object 111 Acceptance Mask Register High
#define CAN_MOAMR111H          (*((uword volatile far *) 0x201DEE))

// Message Object 111 Acceptance Mask Register Low
#define CAN_MOAMR111L          (*((uword volatile far *) 0x201DEC))

// Message Object 112 Acceptance Mask Register High
#define CAN_MOAMR112H          (*((uword volatile far *) 0x201E0E))

// Message Object 112 Acceptance Mask Register Low
#define CAN_MOAMR112L          (*((uword volatile far *) 0x201E0C))

// Message Object 113 Acceptance Mask Register High
#define CAN_MOAMR113H          (*((uword volatile far *) 0x201E2E))

// Message Object 113 Acceptance Mask Register Low
#define CAN_MOAMR113L          (*((uword volatile far *) 0x201E2C))

// Message Object 114 Acceptance Mask Register High
#define CAN_MOAMR114H          (*((uword volatile far *) 0x201E4E))

// Message Object 114 Acceptance Mask Register Low
#define CAN_MOAMR114L          (*((uword volatile far *) 0x201E4C))

// Message Object 115 Acceptance Mask Register High
#define CAN_MOAMR115H          (*((uword volatile far *) 0x201E6E))

// Message Object 115 Acceptance Mask Register Low
#define CAN_MOAMR115L          (*((uword volatile far *) 0x201E6C))

// Message Object 116 Acceptance Mask Register High
#define CAN_MOAMR116H          (*((uword volatile far *) 0x201E8E))

// Message Object 116 Acceptance Mask Register Low
#define CAN_MOAMR116L          (*((uword volatile far *) 0x201E8C))

// Message Object 117 Acceptance Mask Register High
#define CAN_MOAMR117H          (*((uword volatile far *) 0x201EAE))

// Message Object 117 Acceptance Mask Register Low
#define CAN_MOAMR117L          (*((uword volatile far *) 0x201EAC))

// Message Object 118 Acceptance Mask Register High
#define CAN_MOAMR118H          (*((uword volatile far *) 0x201ECE))

// Message Object 118 Acceptance Mask Register Low
#define CAN_MOAMR118L          (*((uword volatile far *) 0x201ECC))

// Message Object 119 Acceptance Mask Register High
#define CAN_MOAMR119H          (*((uword volatile far *) 0x201EEE))

// Message Object 119 Acceptance Mask Register Low
#define CAN_MOAMR119L          (*((uword volatile far *) 0x201EEC))

// Message Object 11 Acceptance Mask Register High
#define CAN_MOAMR11H           (*((uword volatile far *) 0x20116E))

// Message Object 11 Acceptance Mask Register Low
#define CAN_MOAMR11L           (*((uword volatile far *) 0x20116C))

// Message Object 120 Acceptance Mask Register High
#define CAN_MOAMR120H          (*((uword volatile far *) 0x201F0E))

// Message Object 120 Acceptance Mask Register Low
#define CAN_MOAMR120L          (*((uword volatile far *) 0x201F0C))

// Message Object 121 Acceptance Mask Register High
#define CAN_MOAMR121H          (*((uword volatile far *) 0x201F2E))

// Message Object 121 Acceptance Mask Register Low
#define CAN_MOAMR121L          (*((uword volatile far *) 0x201F2C))

// Message Object 122 Acceptance Mask Register High
#define CAN_MOAMR122H          (*((uword volatile far *) 0x201F4E))

// Message Object 122 Acceptance Mask Register Low
#define CAN_MOAMR122L          (*((uword volatile far *) 0x201F4C))

// Message Object 123 Acceptance Mask Register High
#define CAN_MOAMR123H          (*((uword volatile far *) 0x201F6E))

// Message Object 123 Acceptance Mask Register Low
#define CAN_MOAMR123L          (*((uword volatile far *) 0x201F6C))

// Message Object 124 Acceptance Mask Register High
#define CAN_MOAMR124H          (*((uword volatile far *) 0x201F8E))

// Message Object 124 Acceptance Mask Register Low
#define CAN_MOAMR124L          (*((uword volatile far *) 0x201F8C))

// Message Object 125 Acceptance Mask Register High
#define CAN_MOAMR125H          (*((uword volatile far *) 0x201FAE))

// Message Object 125 Acceptance Mask Register Low
#define CAN_MOAMR125L          (*((uword volatile far *) 0x201FAC))

// Message Object 126 Acceptance Mask Register High
#define CAN_MOAMR126H          (*((uword volatile far *) 0x201FCE))

// Message Object 126 Acceptance Mask Register Low
#define CAN_MOAMR126L          (*((uword volatile far *) 0x201FCC))

// Message Object 127 Acceptance Mask Register High
#define CAN_MOAMR127H          (*((uword volatile far *) 0x201FEE))

// Message Object 127 Acceptance Mask Register Low
#define CAN_MOAMR127L          (*((uword volatile far *) 0x201FEC))

// Message Object 128 Acceptance Mask Register High
#define CAN_MOAMR128H          (*((uword volatile far *) 0x20200E))

// Message Object 128 Acceptance Mask Register Low
#define CAN_MOAMR128L          (*((uword volatile far *) 0x20200C))

// Message Object 129 Acceptance Mask Register High
#define CAN_MOAMR129H          (*((uword volatile far *) 0x20202E))

// Message Object 129 Acceptance Mask Register Low
#define CAN_MOAMR129L          (*((uword volatile far *) 0x20202C))

// Message Object 12 Acceptance Mask Register High
#define CAN_MOAMR12H           (*((uword volatile far *) 0x20118E))

// Message Object 12 Acceptance Mask Register Low
#define CAN_MOAMR12L           (*((uword volatile far *) 0x20118C))

// Message Object 130 Acceptance Mask Register High
#define CAN_MOAMR130H          (*((uword volatile far *) 0x20204E))

// Message Object 130 Acceptance Mask Register Low
#define CAN_MOAMR130L          (*((uword volatile far *) 0x20204C))

// Message Object 131 Acceptance Mask Register High
#define CAN_MOAMR131H          (*((uword volatile far *) 0x20206E))

// Message Object 131 Acceptance Mask Register Low
#define CAN_MOAMR131L          (*((uword volatile far *) 0x20206C))

// Message Object 132 Acceptance Mask Register High
#define CAN_MOAMR132H          (*((uword volatile far *) 0x20208E))

// Message Object 132 Acceptance Mask Register Low
#define CAN_MOAMR132L          (*((uword volatile far *) 0x20208C))

// Message Object 133 Acceptance Mask Register High
#define CAN_MOAMR133H          (*((uword volatile far *) 0x2020AE))

// Message Object 133 Acceptance Mask Register Low
#define CAN_MOAMR133L          (*((uword volatile far *) 0x2020AC))

// Message Object 134 Acceptance Mask Register High
#define CAN_MOAMR134H          (*((uword volatile far *) 0x2020CE))

// Message Object 134 Acceptance Mask Register Low
#define CAN_MOAMR134L          (*((uword volatile far *) 0x2020CC))

// Message Object 135 Acceptance Mask Register High
#define CAN_MOAMR135H          (*((uword volatile far *) 0x2020EE))

// Message Object 135 Acceptance Mask Register Low
#define CAN_MOAMR135L          (*((uword volatile far *) 0x2020EC))

// Message Object 136 Acceptance Mask Register High
#define CAN_MOAMR136H          (*((uword volatile far *) 0x20210E))

// Message Object 136 Acceptance Mask Register Low
#define CAN_MOAMR136L          (*((uword volatile far *) 0x20210C))

// Message Object 137 Acceptance Mask Register High
#define CAN_MOAMR137H          (*((uword volatile far *) 0x20212E))

// Message Object 137 Acceptance Mask Register Low
#define CAN_MOAMR137L          (*((uword volatile far *) 0x20212C))

// Message Object 138 Acceptance Mask Register High
#define CAN_MOAMR138H          (*((uword volatile far *) 0x20214E))

// Message Object 138 Acceptance Mask Register Low
#define CAN_MOAMR138L          (*((uword volatile far *) 0x20214C))

// Message Object 139 Acceptance Mask Register High
#define CAN_MOAMR139H          (*((uword volatile far *) 0x20216E))

// Message Object 139 Acceptance Mask Register Low
#define CAN_MOAMR139L          (*((uword volatile far *) 0x20216C))

// Message Object 13 Acceptance Mask Register High
#define CAN_MOAMR13H           (*((uword volatile far *) 0x2011AE))

// Message Object 13 Acceptance Mask Register Low
#define CAN_MOAMR13L           (*((uword volatile far *) 0x2011AC))

// Message Object 140 Acceptance Mask Register High
#define CAN_MOAMR140H          (*((uword volatile far *) 0x20218E))

// Message Object 140 Acceptance Mask Register Low
#define CAN_MOAMR140L          (*((uword volatile far *) 0x20218C))

// Message Object 141 Acceptance Mask Register High
#define CAN_MOAMR141H          (*((uword volatile far *) 0x2021AE))

// Message Object 141 Acceptance Mask Register Low
#define CAN_MOAMR141L          (*((uword volatile far *) 0x2021AC))

// Message Object 142 Acceptance Mask Register High
#define CAN_MOAMR142H          (*((uword volatile far *) 0x2021CE))

// Message Object 142 Acceptance Mask Register Low
#define CAN_MOAMR142L          (*((uword volatile far *) 0x2021CC))

// Message Object 143 Acceptance Mask Register High
#define CAN_MOAMR143H          (*((uword volatile far *) 0x2021EE))

// Message Object 143 Acceptance Mask Register Low
#define CAN_MOAMR143L          (*((uword volatile far *) 0x2021EC))

// Message Object 144 Acceptance Mask Register High
#define CAN_MOAMR144H          (*((uword volatile far *) 0x20220E))

// Message Object 144 Acceptance Mask Register Low
#define CAN_MOAMR144L          (*((uword volatile far *) 0x20220C))

// Message Object 145 Acceptance Mask Register High
#define CAN_MOAMR145H          (*((uword volatile far *) 0x20222E))

// Message Object 145 Acceptance Mask Register Low
#define CAN_MOAMR145L          (*((uword volatile far *) 0x20222C))

// Message Object 146 Acceptance Mask Register High
#define CAN_MOAMR146H          (*((uword volatile far *) 0x20224E))

// Message Object 146 Acceptance Mask Register Low
#define CAN_MOAMR146L          (*((uword volatile far *) 0x20224C))

// Message Object 147 Acceptance Mask Register High
#define CAN_MOAMR147H          (*((uword volatile far *) 0x20226E))

// Message Object 147 Acceptance Mask Register Low
#define CAN_MOAMR147L          (*((uword volatile far *) 0x20226C))

// Message Object 148 Acceptance Mask Register High
#define CAN_MOAMR148H          (*((uword volatile far *) 0x20228E))

// Message Object 148 Acceptance Mask Register Low
#define CAN_MOAMR148L          (*((uword volatile far *) 0x20228C))

// Message Object 149 Acceptance Mask Register High
#define CAN_MOAMR149H          (*((uword volatile far *) 0x2022AE))

// Message Object 149 Acceptance Mask Register Low
#define CAN_MOAMR149L          (*((uword volatile far *) 0x2022AC))

// Message Object 14 Acceptance Mask Register High
#define CAN_MOAMR14H           (*((uword volatile far *) 0x2011CE))

// Message Object 14 Acceptance Mask Register Low
#define CAN_MOAMR14L           (*((uword volatile far *) 0x2011CC))

// Message Object 150 Acceptance Mask Register High
#define CAN_MOAMR150H          (*((uword volatile far *) 0x2022CE))

// Message Object 150 Acceptance Mask Register Low
#define CAN_MOAMR150L          (*((uword volatile far *) 0x2022CC))

// Message Object 151 Acceptance Mask Register High
#define CAN_MOAMR151H          (*((uword volatile far *) 0x2022EE))

// Message Object 151 Acceptance Mask Register Low
#define CAN_MOAMR151L          (*((uword volatile far *) 0x2022EC))

// Message Object 152 Acceptance Mask Register High
#define CAN_MOAMR152H          (*((uword volatile far *) 0x20230E))

// Message Object 152 Acceptance Mask Register Low
#define CAN_MOAMR152L          (*((uword volatile far *) 0x20230C))

// Message Object 153 Acceptance Mask Register High
#define CAN_MOAMR153H          (*((uword volatile far *) 0x20232E))

// Message Object 153 Acceptance Mask Register Low
#define CAN_MOAMR153L          (*((uword volatile far *) 0x20232C))

// Message Object 154 Acceptance Mask Register High
#define CAN_MOAMR154H          (*((uword volatile far *) 0x20234E))

// Message Object 154 Acceptance Mask Register Low
#define CAN_MOAMR154L          (*((uword volatile far *) 0x20234C))

// Message Object 155 Acceptance Mask Register High
#define CAN_MOAMR155H          (*((uword volatile far *) 0x20236E))

// Message Object 155 Acceptance Mask Register Low
#define CAN_MOAMR155L          (*((uword volatile far *) 0x20236C))

// Message Object 156 Acceptance Mask Register High
#define CAN_MOAMR156H          (*((uword volatile far *) 0x20238E))

// Message Object 156 Acceptance Mask Register Low
#define CAN_MOAMR156L          (*((uword volatile far *) 0x20238C))

// Message Object 157 Acceptance Mask Register High
#define CAN_MOAMR157H          (*((uword volatile far *) 0x2023AE))

// Message Object 157 Acceptance Mask Register Low
#define CAN_MOAMR157L          (*((uword volatile far *) 0x2023AC))

// Message Object 158 Acceptance Mask Register High
#define CAN_MOAMR158H          (*((uword volatile far *) 0x2023CE))

// Message Object 158 Acceptance Mask Register Low
#define CAN_MOAMR158L          (*((uword volatile far *) 0x2023CC))

// Message Object 159 Acceptance Mask Register High
#define CAN_MOAMR159H          (*((uword volatile far *) 0x2023EE))

// Message Object 159 Acceptance Mask Register Low
#define CAN_MOAMR159L          (*((uword volatile far *) 0x2023EC))

// Message Object 15 Acceptance Mask Register High
#define CAN_MOAMR15H           (*((uword volatile far *) 0x2011EE))

// Message Object 15 Acceptance Mask Register Low
#define CAN_MOAMR15L           (*((uword volatile far *) 0x2011EC))

// Message Object 160 Acceptance Mask Register High
#define CAN_MOAMR160H          (*((uword volatile far *) 0x20240E))

// Message Object 160 Acceptance Mask Register Low
#define CAN_MOAMR160L          (*((uword volatile far *) 0x20240C))

// Message Object 161 Acceptance Mask Register High
#define CAN_MOAMR161H          (*((uword volatile far *) 0x20242E))

// Message Object 161 Acceptance Mask Register Low
#define CAN_MOAMR161L          (*((uword volatile far *) 0x20242C))

// Message Object 162 Acceptance Mask Register High
#define CAN_MOAMR162H          (*((uword volatile far *) 0x20244E))

// Message Object 162 Acceptance Mask Register Low
#define CAN_MOAMR162L          (*((uword volatile far *) 0x20244C))

// Message Object 163 Acceptance Mask Register High
#define CAN_MOAMR163H          (*((uword volatile far *) 0x20246E))

// Message Object 163 Acceptance Mask Register Low
#define CAN_MOAMR163L          (*((uword volatile far *) 0x20246C))

// Message Object 164 Acceptance Mask Register High
#define CAN_MOAMR164H          (*((uword volatile far *) 0x20248E))

// Message Object 164 Acceptance Mask Register Low
#define CAN_MOAMR164L          (*((uword volatile far *) 0x20248C))

// Message Object 165 Acceptance Mask Register High
#define CAN_MOAMR165H          (*((uword volatile far *) 0x2024AE))

// Message Object 165 Acceptance Mask Register Low
#define CAN_MOAMR165L          (*((uword volatile far *) 0x2024AC))

// Message Object 166 Acceptance Mask Register High
#define CAN_MOAMR166H          (*((uword volatile far *) 0x2024CE))

// Message Object 166 Acceptance Mask Register Low
#define CAN_MOAMR166L          (*((uword volatile far *) 0x2024CC))

// Message Object 167 Acceptance Mask Register High
#define CAN_MOAMR167H          (*((uword volatile far *) 0x2024EE))

// Message Object 167 Acceptance Mask Register Low
#define CAN_MOAMR167L          (*((uword volatile far *) 0x2024EC))

// Message Object 168 Acceptance Mask Register High
#define CAN_MOAMR168H          (*((uword volatile far *) 0x20250E))

// Message Object 168 Acceptance Mask Register Low
#define CAN_MOAMR168L          (*((uword volatile far *) 0x20250C))

// Message Object 169 Acceptance Mask Register High
#define CAN_MOAMR169H          (*((uword volatile far *) 0x20252E))

// Message Object 169 Acceptance Mask Register Low
#define CAN_MOAMR169L          (*((uword volatile far *) 0x20252C))

// Message Object 16 Acceptance Mask Register High
#define CAN_MOAMR16H           (*((uword volatile far *) 0x20120E))

// Message Object 16 Acceptance Mask Register Low
#define CAN_MOAMR16L           (*((uword volatile far *) 0x20120C))

// Message Object 170 Acceptance Mask Register High
#define CAN_MOAMR170H          (*((uword volatile far *) 0x20254E))

// Message Object 170 Acceptance Mask Register Low
#define CAN_MOAMR170L          (*((uword volatile far *) 0x20254C))

// Message Object 171 Acceptance Mask Register High
#define CAN_MOAMR171H          (*((uword volatile far *) 0x20256E))

// Message Object 171 Acceptance Mask Register Low
#define CAN_MOAMR171L          (*((uword volatile far *) 0x20256C))

// Message Object 172 Acceptance Mask Register High
#define CAN_MOAMR172H          (*((uword volatile far *) 0x20258E))

// Message Object 172 Acceptance Mask Register Low
#define CAN_MOAMR172L          (*((uword volatile far *) 0x20258C))

// Message Object 173 Acceptance Mask Register High
#define CAN_MOAMR173H          (*((uword volatile far *) 0x2025AE))

// Message Object 173 Acceptance Mask Register Low
#define CAN_MOAMR173L          (*((uword volatile far *) 0x2025AC))

// Message Object 174 Acceptance Mask Register High
#define CAN_MOAMR174H          (*((uword volatile far *) 0x2025CE))

// Message Object 174 Acceptance Mask Register Low
#define CAN_MOAMR174L          (*((uword volatile far *) 0x2025CC))

// Message Object 175 Acceptance Mask Register High
#define CAN_MOAMR175H          (*((uword volatile far *) 0x2025EE))

// Message Object 175 Acceptance Mask Register Low
#define CAN_MOAMR175L          (*((uword volatile far *) 0x2025EC))

// Message Object 176 Acceptance Mask Register High
#define CAN_MOAMR176H          (*((uword volatile far *) 0x20260E))

// Message Object 176 Acceptance Mask Register Low
#define CAN_MOAMR176L          (*((uword volatile far *) 0x20260C))

// Message Object 177 Acceptance Mask Register High
#define CAN_MOAMR177H          (*((uword volatile far *) 0x20262E))

// Message Object 177 Acceptance Mask Register Low
#define CAN_MOAMR177L          (*((uword volatile far *) 0x20262C))

// Message Object 178 Acceptance Mask Register High
#define CAN_MOAMR178H          (*((uword volatile far *) 0x20264E))

// Message Object 178 Acceptance Mask Register Low
#define CAN_MOAMR178L          (*((uword volatile far *) 0x20264C))

// Message Object 179 Acceptance Mask Register High
#define CAN_MOAMR179H          (*((uword volatile far *) 0x20266E))

// Message Object 179 Acceptance Mask Register Low
#define CAN_MOAMR179L          (*((uword volatile far *) 0x20266C))

// Message Object 17 Acceptance Mask Register High
#define CAN_MOAMR17H           (*((uword volatile far *) 0x20122E))

// Message Object 17 Acceptance Mask Register Low
#define CAN_MOAMR17L           (*((uword volatile far *) 0x20122C))

// Message Object 180 Acceptance Mask Register High
#define CAN_MOAMR180H          (*((uword volatile far *) 0x20268E))

// Message Object 180 Acceptance Mask Register Low
#define CAN_MOAMR180L          (*((uword volatile far *) 0x20268C))

// Message Object 181 Acceptance Mask Register High
#define CAN_MOAMR181H          (*((uword volatile far *) 0x2026AE))

// Message Object 181 Acceptance Mask Register Low
#define CAN_MOAMR181L          (*((uword volatile far *) 0x2026AC))

// Message Object 182 Acceptance Mask Register High
#define CAN_MOAMR182H          (*((uword volatile far *) 0x2026CE))

// Message Object 182 Acceptance Mask Register Low
#define CAN_MOAMR182L          (*((uword volatile far *) 0x2026CC))

// Message Object 183 Acceptance Mask Register High
#define CAN_MOAMR183H          (*((uword volatile far *) 0x2026EE))

// Message Object 183 Acceptance Mask Register Low
#define CAN_MOAMR183L          (*((uword volatile far *) 0x2026EC))

// Message Object 184 Acceptance Mask Register High
#define CAN_MOAMR184H          (*((uword volatile far *) 0x20270E))

// Message Object 184 Acceptance Mask Register Low
#define CAN_MOAMR184L          (*((uword volatile far *) 0x20270C))

// Message Object 185 Acceptance Mask Register High
#define CAN_MOAMR185H          (*((uword volatile far *) 0x20272E))

// Message Object 185 Acceptance Mask Register Low
#define CAN_MOAMR185L          (*((uword volatile far *) 0x20272C))

// Message Object 186 Acceptance Mask Register High
#define CAN_MOAMR186H          (*((uword volatile far *) 0x20274E))

// Message Object 186 Acceptance Mask Register Low
#define CAN_MOAMR186L          (*((uword volatile far *) 0x20274C))

// Message Object 187 Acceptance Mask Register High
#define CAN_MOAMR187H          (*((uword volatile far *) 0x20276E))

// Message Object 187 Acceptance Mask Register Low
#define CAN_MOAMR187L          (*((uword volatile far *) 0x20276C))

// Message Object 188 Acceptance Mask Register High
#define CAN_MOAMR188H          (*((uword volatile far *) 0x20278E))

// Message Object 188 Acceptance Mask Register Low
#define CAN_MOAMR188L          (*((uword volatile far *) 0x20278C))

// Message Object 189 Acceptance Mask Register High
#define CAN_MOAMR189H          (*((uword volatile far *) 0x2027AE))

// Message Object 189 Acceptance Mask Register Low
#define CAN_MOAMR189L          (*((uword volatile far *) 0x2027AC))

// Message Object 18 Acceptance Mask Register High
#define CAN_MOAMR18H           (*((uword volatile far *) 0x20124E))

// Message Object 18 Acceptance Mask Register Low
#define CAN_MOAMR18L           (*((uword volatile far *) 0x20124C))

// Message Object 190 Acceptance Mask Register High
#define CAN_MOAMR190H          (*((uword volatile far *) 0x2027CE))

// Message Object 190 Acceptance Mask Register Low
#define CAN_MOAMR190L          (*((uword volatile far *) 0x2027CC))

// Message Object 191 Acceptance Mask Register High
#define CAN_MOAMR191H          (*((uword volatile far *) 0x2027EE))

// Message Object 191 Acceptance Mask Register Low
#define CAN_MOAMR191L          (*((uword volatile far *) 0x2027EC))

// Message Object 192 Acceptance Mask Register High
#define CAN_MOAMR192H          (*((uword volatile far *) 0x20280E))

// Message Object 192 Acceptance Mask Register Low
#define CAN_MOAMR192L          (*((uword volatile far *) 0x20280C))

// Message Object 193 Acceptance Mask Register High
#define CAN_MOAMR193H          (*((uword volatile far *) 0x20282E))

// Message Object 193 Acceptance Mask Register Low
#define CAN_MOAMR193L          (*((uword volatile far *) 0x20282C))

// Message Object 194 Acceptance Mask Register High
#define CAN_MOAMR194H          (*((uword volatile far *) 0x20284E))

// Message Object 194 Acceptance Mask Register Low
#define CAN_MOAMR194L          (*((uword volatile far *) 0x20284C))

// Message Object 195 Acceptance Mask Register High
#define CAN_MOAMR195H          (*((uword volatile far *) 0x20286E))

// Message Object 195 Acceptance Mask Register Low
#define CAN_MOAMR195L          (*((uword volatile far *) 0x20286C))

// Message Object 196 Acceptance Mask Register High
#define CAN_MOAMR196H          (*((uword volatile far *) 0x20288E))

// Message Object 196 Acceptance Mask Register Low
#define CAN_MOAMR196L          (*((uword volatile far *) 0x20288C))

// Message Object 197 Acceptance Mask Register High
#define CAN_MOAMR197H          (*((uword volatile far *) 0x2028AE))

// Message Object 197 Acceptance Mask Register Low
#define CAN_MOAMR197L          (*((uword volatile far *) 0x2028AC))

// Message Object 198 Acceptance Mask Register High
#define CAN_MOAMR198H          (*((uword volatile far *) 0x2028CE))

// Message Object 198 Acceptance Mask Register Low
#define CAN_MOAMR198L          (*((uword volatile far *) 0x2028CC))

// Message Object 199 Acceptance Mask Register High
#define CAN_MOAMR199H          (*((uword volatile far *) 0x2028EE))

// Message Object 199 Acceptance Mask Register Low
#define CAN_MOAMR199L          (*((uword volatile far *) 0x2028EC))

// Message Object 19 Acceptance Mask Register High
#define CAN_MOAMR19H           (*((uword volatile far *) 0x20126E))

// Message Object 19 Acceptance Mask Register Low
#define CAN_MOAMR19L           (*((uword volatile far *) 0x20126C))

// Message Object 1 Acceptance Mask Register High
#define CAN_MOAMR1H            (*((uword volatile far *) 0x20102E))

// Message Object 1 Acceptance Mask Register Low
#define CAN_MOAMR1L            (*((uword volatile far *) 0x20102C))

// Message Object 200 Acceptance Mask Register High
#define CAN_MOAMR200H          (*((uword volatile far *) 0x20290E))

// Message Object 200 Acceptance Mask Register Low
#define CAN_MOAMR200L          (*((uword volatile far *) 0x20290C))

// Message Object 201 Acceptance Mask Register High
#define CAN_MOAMR201H          (*((uword volatile far *) 0x20292E))

// Message Object 201 Acceptance Mask Register Low
#define CAN_MOAMR201L          (*((uword volatile far *) 0x20292C))

// Message Object 202 Acceptance Mask Register High
#define CAN_MOAMR202H          (*((uword volatile far *) 0x20294E))

// Message Object 202 Acceptance Mask Register Low
#define CAN_MOAMR202L          (*((uword volatile far *) 0x20294C))

// Message Object 203 Acceptance Mask Register High
#define CAN_MOAMR203H          (*((uword volatile far *) 0x20296E))

// Message Object 203 Acceptance Mask Register Low
#define CAN_MOAMR203L          (*((uword volatile far *) 0x20296C))

// Message Object 204 Acceptance Mask Register High
#define CAN_MOAMR204H          (*((uword volatile far *) 0x20298E))

// Message Object 204 Acceptance Mask Register Low
#define CAN_MOAMR204L          (*((uword volatile far *) 0x20298C))

// Message Object 205 Acceptance Mask Register High
#define CAN_MOAMR205H          (*((uword volatile far *) 0x2029AE))

// Message Object 205 Acceptance Mask Register Low
#define CAN_MOAMR205L          (*((uword volatile far *) 0x2029AC))

// Message Object 206 Acceptance Mask Register High
#define CAN_MOAMR206H          (*((uword volatile far *) 0x2029CE))

// Message Object 206 Acceptance Mask Register Low
#define CAN_MOAMR206L          (*((uword volatile far *) 0x2029CC))

// Message Object 207 Acceptance Mask Register High
#define CAN_MOAMR207H          (*((uword volatile far *) 0x2029EE))

// Message Object 207 Acceptance Mask Register Low
#define CAN_MOAMR207L          (*((uword volatile far *) 0x2029EC))

// Message Object 208 Acceptance Mask Register High
#define CAN_MOAMR208H          (*((uword volatile far *) 0x202A0E))

// Message Object 208 Acceptance Mask Register Low
#define CAN_MOAMR208L          (*((uword volatile far *) 0x202A0C))

// Message Object 209 Acceptance Mask Register High
#define CAN_MOAMR209H          (*((uword volatile far *) 0x202A2E))

// Message Object 209 Acceptance Mask Register Low
#define CAN_MOAMR209L          (*((uword volatile far *) 0x202A2C))

// Message Object 20 Acceptance Mask Register High
#define CAN_MOAMR20H           (*((uword volatile far *) 0x20128E))

// Message Object 20 Acceptance Mask Register Low
#define CAN_MOAMR20L           (*((uword volatile far *) 0x20128C))

// Message Object 210 Acceptance Mask Register High
#define CAN_MOAMR210H          (*((uword volatile far *) 0x202A4E))

// Message Object 210 Acceptance Mask Register Low
#define CAN_MOAMR210L          (*((uword volatile far *) 0x202A4C))

// Message Object 211 Acceptance Mask Register High
#define CAN_MOAMR211H          (*((uword volatile far *) 0x202A6E))

// Message Object 211 Acceptance Mask Register Low
#define CAN_MOAMR211L          (*((uword volatile far *) 0x202A6C))

// Message Object 212 Acceptance Mask Register High
#define CAN_MOAMR212H          (*((uword volatile far *) 0x202A8E))

// Message Object 212 Acceptance Mask Register Low
#define CAN_MOAMR212L          (*((uword volatile far *) 0x202A8C))

// Message Object 213 Acceptance Mask Register High
#define CAN_MOAMR213H          (*((uword volatile far *) 0x202AAE))

// Message Object 213 Acceptance Mask Register Low
#define CAN_MOAMR213L          (*((uword volatile far *) 0x202AAC))

// Message Object 214 Acceptance Mask Register High
#define CAN_MOAMR214H          (*((uword volatile far *) 0x202ACE))

// Message Object 214 Acceptance Mask Register Low
#define CAN_MOAMR214L          (*((uword volatile far *) 0x202ACC))

// Message Object 215 Acceptance Mask Register High
#define CAN_MOAMR215H          (*((uword volatile far *) 0x202AEE))

// Message Object 215 Acceptance Mask Register Low
#define CAN_MOAMR215L          (*((uword volatile far *) 0x202AEC))

// Message Object 216 Acceptance Mask Register High
#define CAN_MOAMR216H          (*((uword volatile far *) 0x202B0E))

// Message Object 216 Acceptance Mask Register Low
#define CAN_MOAMR216L          (*((uword volatile far *) 0x202B0C))

// Message Object 217 Acceptance Mask Register High
#define CAN_MOAMR217H          (*((uword volatile far *) 0x202B2E))

// Message Object 217 Acceptance Mask Register Low
#define CAN_MOAMR217L          (*((uword volatile far *) 0x202B2C))

// Message Object 218 Acceptance Mask Register High
#define CAN_MOAMR218H          (*((uword volatile far *) 0x202B4E))

// Message Object 218 Acceptance Mask Register Low
#define CAN_MOAMR218L          (*((uword volatile far *) 0x202B4C))

// Message Object 219 Acceptance Mask Register High
#define CAN_MOAMR219H          (*((uword volatile far *) 0x202B6E))

// Message Object 219 Acceptance Mask Register Low
#define CAN_MOAMR219L          (*((uword volatile far *) 0x202B6C))

// Message Object 21 Acceptance Mask Register High
#define CAN_MOAMR21H           (*((uword volatile far *) 0x2012AE))

// Message Object 21 Acceptance Mask Register Low
#define CAN_MOAMR21L           (*((uword volatile far *) 0x2012AC))

// Message Object 220 Acceptance Mask Register High
#define CAN_MOAMR220H          (*((uword volatile far *) 0x202B8E))

// Message Object 220 Acceptance Mask Register Low
#define CAN_MOAMR220L          (*((uword volatile far *) 0x202B8C))

// Message Object 221 Acceptance Mask Register High
#define CAN_MOAMR221H          (*((uword volatile far *) 0x202BAE))

// Message Object 221 Acceptance Mask Register Low
#define CAN_MOAMR221L          (*((uword volatile far *) 0x202BAC))

// Message Object 222 Acceptance Mask Register High
#define CAN_MOAMR222H          (*((uword volatile far *) 0x202BCE))

// Message Object 222 Acceptance Mask Register Low
#define CAN_MOAMR222L          (*((uword volatile far *) 0x202BCC))

// Message Object 223 Acceptance Mask Register High
#define CAN_MOAMR223H          (*((uword volatile far *) 0x202BEE))

// Message Object 223 Acceptance Mask Register Low
#define CAN_MOAMR223L          (*((uword volatile far *) 0x202BEC))

// Message Object 224 Acceptance Mask Register High
#define CAN_MOAMR224H          (*((uword volatile far *) 0x202C0E))

// Message Object 224 Acceptance Mask Register Low
#define CAN_MOAMR224L          (*((uword volatile far *) 0x202C0C))

// Message Object 225 Acceptance Mask Register High
#define CAN_MOAMR225H          (*((uword volatile far *) 0x202C2E))

// Message Object 225 Acceptance Mask Register Low
#define CAN_MOAMR225L          (*((uword volatile far *) 0x202C2C))

// Message Object 226 Acceptance Mask Register High
#define CAN_MOAMR226H          (*((uword volatile far *) 0x202C4E))

// Message Object 226 Acceptance Mask Register Low
#define CAN_MOAMR226L          (*((uword volatile far *) 0x202C4C))

// Message Object 227 Acceptance Mask Register High
#define CAN_MOAMR227H          (*((uword volatile far *) 0x202C6E))

// Message Object 227 Acceptance Mask Register Low
#define CAN_MOAMR227L          (*((uword volatile far *) 0x202C6C))

// Message Object 228 Acceptance Mask Register High
#define CAN_MOAMR228H          (*((uword volatile far *) 0x202C8E))

// Message Object 228 Acceptance Mask Register Low
#define CAN_MOAMR228L          (*((uword volatile far *) 0x202C8C))

// Message Object 229 Acceptance Mask Register High
#define CAN_MOAMR229H          (*((uword volatile far *) 0x202CAE))

// Message Object 229 Acceptance Mask Register Low
#define CAN_MOAMR229L          (*((uword volatile far *) 0x202CAC))

// Message Object 22 Acceptance Mask Register High
#define CAN_MOAMR22H           (*((uword volatile far *) 0x2012CE))

// Message Object 22 Acceptance Mask Register Low
#define CAN_MOAMR22L           (*((uword volatile far *) 0x2012CC))

// Message Object 230 Acceptance Mask Register High
#define CAN_MOAMR230H          (*((uword volatile far *) 0x202CCE))

// Message Object 230 Acceptance Mask Register Low
#define CAN_MOAMR230L          (*((uword volatile far *) 0x202CCC))

// Message Object 231 Acceptance Mask Register High
#define CAN_MOAMR231H          (*((uword volatile far *) 0x202CEE))

// Message Object 231 Acceptance Mask Register Low
#define CAN_MOAMR231L          (*((uword volatile far *) 0x202CEC))

// Message Object 232 Acceptance Mask Register High
#define CAN_MOAMR232H          (*((uword volatile far *) 0x202D0E))

// Message Object 232 Acceptance Mask Register Low
#define CAN_MOAMR232L          (*((uword volatile far *) 0x202D0C))

// Message Object 233 Acceptance Mask Register High
#define CAN_MOAMR233H          (*((uword volatile far *) 0x202D2E))

// Message Object 233 Acceptance Mask Register Low
#define CAN_MOAMR233L          (*((uword volatile far *) 0x202D2C))

// Message Object 234 Acceptance Mask Register High
#define CAN_MOAMR234H          (*((uword volatile far *) 0x202D4E))

// Message Object 234 Acceptance Mask Register Low
#define CAN_MOAMR234L          (*((uword volatile far *) 0x202D4C))

// Message Object 235 Acceptance Mask Register High
#define CAN_MOAMR235H          (*((uword volatile far *) 0x202D6E))

// Message Object 235 Acceptance Mask Register Low
#define CAN_MOAMR235L          (*((uword volatile far *) 0x202D6C))

// Message Object 236 Acceptance Mask Register High
#define CAN_MOAMR236H          (*((uword volatile far *) 0x202D8E))

// Message Object 236 Acceptance Mask Register Low
#define CAN_MOAMR236L          (*((uword volatile far *) 0x202D8C))

// Message Object 237 Acceptance Mask Register High
#define CAN_MOAMR237H          (*((uword volatile far *) 0x202DAE))

// Message Object 237 Acceptance Mask Register Low
#define CAN_MOAMR237L          (*((uword volatile far *) 0x202DAC))

// Message Object 238 Acceptance Mask Register High
#define CAN_MOAMR238H          (*((uword volatile far *) 0x202DCE))

// Message Object 238 Acceptance Mask Register Low
#define CAN_MOAMR238L          (*((uword volatile far *) 0x202DCC))

// Message Object 239 Acceptance Mask Register High
#define CAN_MOAMR239H          (*((uword volatile far *) 0x202DEE))

// Message Object 239 Acceptance Mask Register Low
#define CAN_MOAMR239L          (*((uword volatile far *) 0x202DEC))

// Message Object 23 Acceptance Mask Register High
#define CAN_MOAMR23H           (*((uword volatile far *) 0x2012EE))

// Message Object 23 Acceptance Mask Register Low
#define CAN_MOAMR23L           (*((uword volatile far *) 0x2012EC))

// Message Object 240 Acceptance Mask Register High
#define CAN_MOAMR240H          (*((uword volatile far *) 0x202E0E))

// Message Object 240 Acceptance Mask Register Low
#define CAN_MOAMR240L          (*((uword volatile far *) 0x202E0C))

// Message Object 241 Acceptance Mask Register High
#define CAN_MOAMR241H          (*((uword volatile far *) 0x202E2E))

// Message Object 241 Acceptance Mask Register Low
#define CAN_MOAMR241L          (*((uword volatile far *) 0x202E2C))

// Message Object 242 Acceptance Mask Register High
#define CAN_MOAMR242H          (*((uword volatile far *) 0x202E4E))

// Message Object 242 Acceptance Mask Register Low
#define CAN_MOAMR242L          (*((uword volatile far *) 0x202E4C))

// Message Object 243 Acceptance Mask Register High
#define CAN_MOAMR243H          (*((uword volatile far *) 0x202E6E))

// Message Object 243 Acceptance Mask Register Low
#define CAN_MOAMR243L          (*((uword volatile far *) 0x202E6C))

// Message Object 244 Acceptance Mask Register High
#define CAN_MOAMR244H          (*((uword volatile far *) 0x202E8E))

// Message Object 244 Acceptance Mask Register Low
#define CAN_MOAMR244L          (*((uword volatile far *) 0x202E8C))

// Message Object 245 Acceptance Mask Register High
#define CAN_MOAMR245H          (*((uword volatile far *) 0x202EAE))

// Message Object 245 Acceptance Mask Register Low
#define CAN_MOAMR245L          (*((uword volatile far *) 0x202EAC))

// Message Object 246 Acceptance Mask Register High
#define CAN_MOAMR246H          (*((uword volatile far *) 0x202ECE))

// Message Object 246 Acceptance Mask Register Low
#define CAN_MOAMR246L          (*((uword volatile far *) 0x202ECC))

// Message Object 247 Acceptance Mask Register High
#define CAN_MOAMR247H          (*((uword volatile far *) 0x202EEE))

// Message Object 247 Acceptance Mask Register Low
#define CAN_MOAMR247L          (*((uword volatile far *) 0x202EEC))

// Message Object 248 Acceptance Mask Register High
#define CAN_MOAMR248H          (*((uword volatile far *) 0x202F0E))

// Message Object 248 Acceptance Mask Register Low
#define CAN_MOAMR248L          (*((uword volatile far *) 0x202F0C))

// Message Object 249 Acceptance Mask Register High
#define CAN_MOAMR249H          (*((uword volatile far *) 0x202F2E))

// Message Object 249 Acceptance Mask Register Low
#define CAN_MOAMR249L          (*((uword volatile far *) 0x202F2C))

// Message Object 24 Acceptance Mask Register High
#define CAN_MOAMR24H           (*((uword volatile far *) 0x20130E))

// Message Object 24 Acceptance Mask Register Low
#define CAN_MOAMR24L           (*((uword volatile far *) 0x20130C))

// Message Object 250 Acceptance Mask Register High
#define CAN_MOAMR250H          (*((uword volatile far *) 0x202F4E))

// Message Object 250 Acceptance Mask Register Low
#define CAN_MOAMR250L          (*((uword volatile far *) 0x202F4C))

// Message Object 251 Acceptance Mask Register High
#define CAN_MOAMR251H          (*((uword volatile far *) 0x202F6E))

// Message Object 251 Acceptance Mask Register Low
#define CAN_MOAMR251L          (*((uword volatile far *) 0x202F6C))

// Message Object 252 Acceptance Mask Register High
#define CAN_MOAMR252H          (*((uword volatile far *) 0x202F8E))

// Message Object 252 Acceptance Mask Register Low
#define CAN_MOAMR252L          (*((uword volatile far *) 0x202F8C))

// Message Object 253 Acceptance Mask Register High
#define CAN_MOAMR253H          (*((uword volatile far *) 0x202FAE))

// Message Object 253 Acceptance Mask Register Low
#define CAN_MOAMR253L          (*((uword volatile far *) 0x202FAC))

// Message Object 254 Acceptance Mask Register High
#define CAN_MOAMR254H          (*((uword volatile far *) 0x202FCE))

// Message Object 254 Acceptance Mask Register Low
#define CAN_MOAMR254L          (*((uword volatile far *) 0x202FCC))

// Message Object 255 Acceptance Mask Register High
#define CAN_MOAMR255H          (*((uword volatile far *) 0x202FEE))

// Message Object 255 Acceptance Mask Register Low
#define CAN_MOAMR255L          (*((uword volatile far *) 0x202FEC))

// Message Object 25 Acceptance Mask Register High
#define CAN_MOAMR25H           (*((uword volatile far *) 0x20132E))

// Message Object 25 Acceptance Mask Register Low
#define CAN_MOAMR25L           (*((uword volatile far *) 0x20132C))

// Message Object 26 Acceptance Mask Register High
#define CAN_MOAMR26H           (*((uword volatile far *) 0x20134E))

// Message Object 26 Acceptance Mask Register Low
#define CAN_MOAMR26L           (*((uword volatile far *) 0x20134C))

// Message Object 27 Acceptance Mask Register High
#define CAN_MOAMR27H           (*((uword volatile far *) 0x20136E))

// Message Object 27 Acceptance Mask Register Low
#define CAN_MOAMR27L           (*((uword volatile far *) 0x20136C))

// Message Object 28 Acceptance Mask Register High
#define CAN_MOAMR28H           (*((uword volatile far *) 0x20138E))

// Message Object 28 Acceptance Mask Register Low
#define CAN_MOAMR28L           (*((uword volatile far *) 0x20138C))

// Message Object 29 Acceptance Mask Register High
#define CAN_MOAMR29H           (*((uword volatile far *) 0x2013AE))

// Message Object 29 Acceptance Mask Register Low
#define CAN_MOAMR29L           (*((uword volatile far *) 0x2013AC))

// Message Object 2 Acceptance Mask Register High
#define CAN_MOAMR2H            (*((uword volatile far *) 0x20104E))

// Message Object 2 Acceptance Mask Register Low
#define CAN_MOAMR2L            (*((uword volatile far *) 0x20104C))

// Message Object 30 Acceptance Mask Register High
#define CAN_MOAMR30H           (*((uword volatile far *) 0x2013CE))

// Message Object 30 Acceptance Mask Register Low
#define CAN_MOAMR30L           (*((uword volatile far *) 0x2013CC))

// Message Object 31 Acceptance Mask Register High
#define CAN_MOAMR31H           (*((uword volatile far *) 0x2013EE))

// Message Object 31 Acceptance Mask Register Low
#define CAN_MOAMR31L           (*((uword volatile far *) 0x2013EC))

// Message Object 32 Acceptance Mask Register High
#define CAN_MOAMR32H           (*((uword volatile far *) 0x20140E))

// Message Object 32 Acceptance Mask Register Low
#define CAN_MOAMR32L           (*((uword volatile far *) 0x20140C))

// Message Object 33 Acceptance Mask Register High
#define CAN_MOAMR33H           (*((uword volatile far *) 0x20142E))

// Message Object 33 Acceptance Mask Register Low
#define CAN_MOAMR33L           (*((uword volatile far *) 0x20142C))

// Message Object 34 Acceptance Mask Register High
#define CAN_MOAMR34H           (*((uword volatile far *) 0x20144E))

// Message Object 34 Acceptance Mask Register Low
#define CAN_MOAMR34L           (*((uword volatile far *) 0x20144C))

// Message Object 35 Acceptance Mask Register High
#define CAN_MOAMR35H           (*((uword volatile far *) 0x20146E))

// Message Object 35 Acceptance Mask Register Low
#define CAN_MOAMR35L           (*((uword volatile far *) 0x20146C))

// Message Object 36 Acceptance Mask Register High
#define CAN_MOAMR36H           (*((uword volatile far *) 0x20148E))

// Message Object 36 Acceptance Mask Register Low
#define CAN_MOAMR36L           (*((uword volatile far *) 0x20148C))

// Message Object 37 Acceptance Mask Register High
#define CAN_MOAMR37H           (*((uword volatile far *) 0x2014AE))

// Message Object 37 Acceptance Mask Register Low
#define CAN_MOAMR37L           (*((uword volatile far *) 0x2014AC))

// Message Object 38 Acceptance Mask Register High
#define CAN_MOAMR38H           (*((uword volatile far *) 0x2014CE))

// Message Object 38 Acceptance Mask Register Low
#define CAN_MOAMR38L           (*((uword volatile far *) 0x2014CC))

// Message Object 39 Acceptance Mask Register High
#define CAN_MOAMR39H           (*((uword volatile far *) 0x2014EE))

// Message Object 39 Acceptance Mask Register Low
#define CAN_MOAMR39L           (*((uword volatile far *) 0x2014EC))

// Message Object 3 Acceptance Mask Register High
#define CAN_MOAMR3H            (*((uword volatile far *) 0x20106E))

// Message Object 3 Acceptance Mask Register Low
#define CAN_MOAMR3L            (*((uword volatile far *) 0x20106C))

// Message Object 40 Acceptance Mask Register High
#define CAN_MOAMR40H           (*((uword volatile far *) 0x20150E))

// Message Object 40 Acceptance Mask Register Low
#define CAN_MOAMR40L           (*((uword volatile far *) 0x20150C))

// Message Object 41 Acceptance Mask Register High
#define CAN_MOAMR41H           (*((uword volatile far *) 0x20152E))

// Message Object 41 Acceptance Mask Register Low
#define CAN_MOAMR41L           (*((uword volatile far *) 0x20152C))

// Message Object 42 Acceptance Mask Register High
#define CAN_MOAMR42H           (*((uword volatile far *) 0x20154E))

// Message Object 42 Acceptance Mask Register Low
#define CAN_MOAMR42L           (*((uword volatile far *) 0x20154C))

// Message Object 43 Acceptance Mask Register High
#define CAN_MOAMR43H           (*((uword volatile far *) 0x20156E))

// Message Object 43 Acceptance Mask Register Low
#define CAN_MOAMR43L           (*((uword volatile far *) 0x20156C))

// Message Object 44 Acceptance Mask Register High
#define CAN_MOAMR44H           (*((uword volatile far *) 0x20158E))

// Message Object 44 Acceptance Mask Register Low
#define CAN_MOAMR44L           (*((uword volatile far *) 0x20158C))

// Message Object 45 Acceptance Mask Register High
#define CAN_MOAMR45H           (*((uword volatile far *) 0x2015AE))

// Message Object 45 Acceptance Mask Register Low
#define CAN_MOAMR45L           (*((uword volatile far *) 0x2015AC))

// Message Object 46 Acceptance Mask Register High
#define CAN_MOAMR46H           (*((uword volatile far *) 0x2015CE))

// Message Object 46 Acceptance Mask Register Low
#define CAN_MOAMR46L           (*((uword volatile far *) 0x2015CC))

// Message Object 47 Acceptance Mask Register High
#define CAN_MOAMR47H           (*((uword volatile far *) 0x2015EE))

// Message Object 47 Acceptance Mask Register Low
#define CAN_MOAMR47L           (*((uword volatile far *) 0x2015EC))

// Message Object 48 Acceptance Mask Register High
#define CAN_MOAMR48H           (*((uword volatile far *) 0x20160E))

// Message Object 48 Acceptance Mask Register Low
#define CAN_MOAMR48L           (*((uword volatile far *) 0x20160C))

// Message Object 49 Acceptance Mask Register High
#define CAN_MOAMR49H           (*((uword volatile far *) 0x20162E))

// Message Object 49 Acceptance Mask Register Low
#define CAN_MOAMR49L           (*((uword volatile far *) 0x20162C))

// Message Object 4 Acceptance Mask Register High
#define CAN_MOAMR4H            (*((uword volatile far *) 0x20108E))

// Message Object 4 Acceptance Mask Register Low
#define CAN_MOAMR4L            (*((uword volatile far *) 0x20108C))

// Message Object 50 Acceptance Mask Register High
#define CAN_MOAMR50H           (*((uword volatile far *) 0x20164E))

// Message Object 50 Acceptance Mask Register Low
#define CAN_MOAMR50L           (*((uword volatile far *) 0x20164C))

// Message Object 51 Acceptance Mask Register High
#define CAN_MOAMR51H           (*((uword volatile far *) 0x20166E))

// Message Object 51 Acceptance Mask Register Low
#define CAN_MOAMR51L           (*((uword volatile far *) 0x20166C))

// Message Object 52 Acceptance Mask Register High
#define CAN_MOAMR52H           (*((uword volatile far *) 0x20168E))

// Message Object 52 Acceptance Mask Register Low
#define CAN_MOAMR52L           (*((uword volatile far *) 0x20168C))

// Message Object 53 Acceptance Mask Register High
#define CAN_MOAMR53H           (*((uword volatile far *) 0x2016AE))

// Message Object 53 Acceptance Mask Register Low
#define CAN_MOAMR53L           (*((uword volatile far *) 0x2016AC))

// Message Object 54 Acceptance Mask Register High
#define CAN_MOAMR54H           (*((uword volatile far *) 0x2016CE))

// Message Object 54 Acceptance Mask Register Low
#define CAN_MOAMR54L           (*((uword volatile far *) 0x2016CC))

// Message Object 55 Acceptance Mask Register High
#define CAN_MOAMR55H           (*((uword volatile far *) 0x2016EE))

// Message Object 55 Acceptance Mask Register Low
#define CAN_MOAMR55L           (*((uword volatile far *) 0x2016EC))

// Message Object 56 Acceptance Mask Register High
#define CAN_MOAMR56H           (*((uword volatile far *) 0x20170E))

// Message Object 56 Acceptance Mask Register Low
#define CAN_MOAMR56L           (*((uword volatile far *) 0x20170C))

// Message Object 57 Acceptance Mask Register High
#define CAN_MOAMR57H           (*((uword volatile far *) 0x20172E))

// Message Object 57 Acceptance Mask Register Low
#define CAN_MOAMR57L           (*((uword volatile far *) 0x20172C))

// Message Object 58 Acceptance Mask Register High
#define CAN_MOAMR58H           (*((uword volatile far *) 0x20174E))

// Message Object 58 Acceptance Mask Register Low
#define CAN_MOAMR58L           (*((uword volatile far *) 0x20174C))

// Message Object 59 Acceptance Mask Register High
#define CAN_MOAMR59H           (*((uword volatile far *) 0x20176E))

// Message Object 59 Acceptance Mask Register Low
#define CAN_MOAMR59L           (*((uword volatile far *) 0x20176C))

// Message Object 5 Acceptance Mask Register High
#define CAN_MOAMR5H            (*((uword volatile far *) 0x2010AE))

// Message Object 5 Acceptance Mask Register Low
#define CAN_MOAMR5L            (*((uword volatile far *) 0x2010AC))

// Message Object 60 Acceptance Mask Register High
#define CAN_MOAMR60H           (*((uword volatile far *) 0x20178E))

// Message Object 60 Acceptance Mask Register Low
#define CAN_MOAMR60L           (*((uword volatile far *) 0x20178C))

// Message Object 61 Acceptance Mask Register High
#define CAN_MOAMR61H           (*((uword volatile far *) 0x2017AE))

// Message Object 61 Acceptance Mask Register Low
#define CAN_MOAMR61L           (*((uword volatile far *) 0x2017AC))

// Message Object 62 Acceptance Mask Register High
#define CAN_MOAMR62H           (*((uword volatile far *) 0x2017CE))

// Message Object 62 Acceptance Mask Register Low
#define CAN_MOAMR62L           (*((uword volatile far *) 0x2017CC))

// Message Object 63 Acceptance Mask Register High
#define CAN_MOAMR63H           (*((uword volatile far *) 0x2017EE))

// Message Object 63 Acceptance Mask Register Low
#define CAN_MOAMR63L           (*((uword volatile far *) 0x2017EC))

// Message Object 64 Acceptance Mask Register High
#define CAN_MOAMR64H           (*((uword volatile far *) 0x20180E))

// Message Object 64 Acceptance Mask Register Low
#define CAN_MOAMR64L           (*((uword volatile far *) 0x20180C))

// Message Object 65 Acceptance Mask Register High
#define CAN_MOAMR65H           (*((uword volatile far *) 0x20182E))

// Message Object 65 Acceptance Mask Register Low
#define CAN_MOAMR65L           (*((uword volatile far *) 0x20182C))

// Message Object 66 Acceptance Mask Register High
#define CAN_MOAMR66H           (*((uword volatile far *) 0x20184E))

// Message Object 66 Acceptance Mask Register Low
#define CAN_MOAMR66L           (*((uword volatile far *) 0x20184C))

// Message Object 67 Acceptance Mask Register High
#define CAN_MOAMR67H           (*((uword volatile far *) 0x20186E))

// Message Object 67 Acceptance Mask Register Low
#define CAN_MOAMR67L           (*((uword volatile far *) 0x20186C))

// Message Object 68 Acceptance Mask Register High
#define CAN_MOAMR68H           (*((uword volatile far *) 0x20188E))

// Message Object 68 Acceptance Mask Register Low
#define CAN_MOAMR68L           (*((uword volatile far *) 0x20188C))

// Message Object 69 Acceptance Mask Register High
#define CAN_MOAMR69H           (*((uword volatile far *) 0x2018AE))

// Message Object 69 Acceptance Mask Register Low
#define CAN_MOAMR69L           (*((uword volatile far *) 0x2018AC))

// Message Object 6 Acceptance Mask Register High
#define CAN_MOAMR6H            (*((uword volatile far *) 0x2010CE))

// Message Object 6 Acceptance Mask Register Low
#define CAN_MOAMR6L            (*((uword volatile far *) 0x2010CC))

// Message Object 70 Acceptance Mask Register High
#define CAN_MOAMR70H           (*((uword volatile far *) 0x2018CE))

// Message Object 70 Acceptance Mask Register Low
#define CAN_MOAMR70L           (*((uword volatile far *) 0x2018CC))

// Message Object 71 Acceptance Mask Register High
#define CAN_MOAMR71H           (*((uword volatile far *) 0x2018EE))

// Message Object 71 Acceptance Mask Register Low
#define CAN_MOAMR71L           (*((uword volatile far *) 0x2018EC))

// Message Object 72 Acceptance Mask Register High
#define CAN_MOAMR72H           (*((uword volatile far *) 0x20190E))

// Message Object 72 Acceptance Mask Register Low
#define CAN_MOAMR72L           (*((uword volatile far *) 0x20190C))

// Message Object 73 Acceptance Mask Register High
#define CAN_MOAMR73H           (*((uword volatile far *) 0x20192E))

// Message Object 73 Acceptance Mask Register Low
#define CAN_MOAMR73L           (*((uword volatile far *) 0x20192C))

// Message Object 74 Acceptance Mask Register High
#define CAN_MOAMR74H           (*((uword volatile far *) 0x20194E))

// Message Object 74 Acceptance Mask Register Low
#define CAN_MOAMR74L           (*((uword volatile far *) 0x20194C))

// Message Object 75 Acceptance Mask Register High
#define CAN_MOAMR75H           (*((uword volatile far *) 0x20196E))

// Message Object 75 Acceptance Mask Register Low
#define CAN_MOAMR75L           (*((uword volatile far *) 0x20196C))

// Message Object 76 Acceptance Mask Register High
#define CAN_MOAMR76H           (*((uword volatile far *) 0x20198E))

// Message Object 76 Acceptance Mask Register Low
#define CAN_MOAMR76L           (*((uword volatile far *) 0x20198C))

// Message Object 77 Acceptance Mask Register High
#define CAN_MOAMR77H           (*((uword volatile far *) 0x2019AE))

// Message Object 77 Acceptance Mask Register Low
#define CAN_MOAMR77L           (*((uword volatile far *) 0x2019AC))

// Message Object 78 Acceptance Mask Register High
#define CAN_MOAMR78H           (*((uword volatile far *) 0x2019CE))

// Message Object 78 Acceptance Mask Register Low
#define CAN_MOAMR78L           (*((uword volatile far *) 0x2019CC))

// Message Object 79 Acceptance Mask Register High
#define CAN_MOAMR79H           (*((uword volatile far *) 0x2019EE))

// Message Object 79 Acceptance Mask Register Low
#define CAN_MOAMR79L           (*((uword volatile far *) 0x2019EC))

// Message Object 7 Acceptance Mask Register High
#define CAN_MOAMR7H            (*((uword volatile far *) 0x2010EE))

// Message Object 7 Acceptance Mask Register Low
#define CAN_MOAMR7L            (*((uword volatile far *) 0x2010EC))

// Message Object 80 Acceptance Mask Register High
#define CAN_MOAMR80H           (*((uword volatile far *) 0x201A0E))

// Message Object 80 Acceptance Mask Register Low
#define CAN_MOAMR80L           (*((uword volatile far *) 0x201A0C))

// Message Object 81 Acceptance Mask Register High
#define CAN_MOAMR81H           (*((uword volatile far *) 0x201A2E))

// Message Object 81 Acceptance Mask Register Low
#define CAN_MOAMR81L           (*((uword volatile far *) 0x201A2C))

// Message Object 82 Acceptance Mask Register High
#define CAN_MOAMR82H           (*((uword volatile far *) 0x201A4E))

// Message Object 82 Acceptance Mask Register Low
#define CAN_MOAMR82L           (*((uword volatile far *) 0x201A4C))

// Message Object 83 Acceptance Mask Register High
#define CAN_MOAMR83H           (*((uword volatile far *) 0x201A6E))

// Message Object 83 Acceptance Mask Register Low
#define CAN_MOAMR83L           (*((uword volatile far *) 0x201A6C))

// Message Object 84 Acceptance Mask Register High
#define CAN_MOAMR84H           (*((uword volatile far *) 0x201A8E))

// Message Object 84 Acceptance Mask Register Low
#define CAN_MOAMR84L           (*((uword volatile far *) 0x201A8C))

// Message Object 85 Acceptance Mask Register High
#define CAN_MOAMR85H           (*((uword volatile far *) 0x201AAE))

// Message Object 85 Acceptance Mask Register Low
#define CAN_MOAMR85L           (*((uword volatile far *) 0x201AAC))

// Message Object 86 Acceptance Mask Register High
#define CAN_MOAMR86H           (*((uword volatile far *) 0x201ACE))

// Message Object 86 Acceptance Mask Register Low
#define CAN_MOAMR86L           (*((uword volatile far *) 0x201ACC))

// Message Object 87 Acceptance Mask Register High
#define CAN_MOAMR87H           (*((uword volatile far *) 0x201AEE))

// Message Object 87 Acceptance Mask Register Low
#define CAN_MOAMR87L           (*((uword volatile far *) 0x201AEC))

// Message Object 88 Acceptance Mask Register High
#define CAN_MOAMR88H           (*((uword volatile far *) 0x201B0E))

// Message Object 88 Acceptance Mask Register Low
#define CAN_MOAMR88L           (*((uword volatile far *) 0x201B0C))

// Message Object 89 Acceptance Mask Register High
#define CAN_MOAMR89H           (*((uword volatile far *) 0x201B2E))

// Message Object 89 Acceptance Mask Register Low
#define CAN_MOAMR89L           (*((uword volatile far *) 0x201B2C))

// Message Object 8 Acceptance Mask Register High
#define CAN_MOAMR8H            (*((uword volatile far *) 0x20110E))

// Message Object 8 Acceptance Mask Register Low
#define CAN_MOAMR8L            (*((uword volatile far *) 0x20110C))

// Message Object 90 Acceptance Mask Register High
#define CAN_MOAMR90H           (*((uword volatile far *) 0x201B4E))

// Message Object 90 Acceptance Mask Register Low
#define CAN_MOAMR90L           (*((uword volatile far *) 0x201B4C))

// Message Object 91 Acceptance Mask Register High
#define CAN_MOAMR91H           (*((uword volatile far *) 0x201B6E))

// Message Object 91 Acceptance Mask Register Low
#define CAN_MOAMR91L           (*((uword volatile far *) 0x201B6C))

// Message Object 92 Acceptance Mask Register High
#define CAN_MOAMR92H           (*((uword volatile far *) 0x201B8E))

// Message Object 92 Acceptance Mask Register Low
#define CAN_MOAMR92L           (*((uword volatile far *) 0x201B8C))

// Message Object 93 Acceptance Mask Register High
#define CAN_MOAMR93H           (*((uword volatile far *) 0x201BAE))

// Message Object 93 Acceptance Mask Register Low
#define CAN_MOAMR93L           (*((uword volatile far *) 0x201BAC))

// Message Object 94 Acceptance Mask Register High
#define CAN_MOAMR94H           (*((uword volatile far *) 0x201BCE))

// Message Object 94 Acceptance Mask Register Low
#define CAN_MOAMR94L           (*((uword volatile far *) 0x201BCC))

// Message Object 95 Acceptance Mask Register High
#define CAN_MOAMR95H           (*((uword volatile far *) 0x201BEE))

// Message Object 95 Acceptance Mask Register Low
#define CAN_MOAMR95L           (*((uword volatile far *) 0x201BEC))

// Message Object 96 Acceptance Mask Register High
#define CAN_MOAMR96H           (*((uword volatile far *) 0x201C0E))

// Message Object 96 Acceptance Mask Register Low
#define CAN_MOAMR96L           (*((uword volatile far *) 0x201C0C))

// Message Object 97 Acceptance Mask Register High
#define CAN_MOAMR97H           (*((uword volatile far *) 0x201C2E))

// Message Object 97 Acceptance Mask Register Low
#define CAN_MOAMR97L           (*((uword volatile far *) 0x201C2C))

// Message Object 98 Acceptance Mask Register High
#define CAN_MOAMR98H           (*((uword volatile far *) 0x201C4E))

// Message Object 98 Acceptance Mask Register Low
#define CAN_MOAMR98L           (*((uword volatile far *) 0x201C4C))

// Message Object 99 Acceptance Mask Register High
#define CAN_MOAMR99H           (*((uword volatile far *) 0x201C6E))

// Message Object 99 Acceptance Mask Register Low
#define CAN_MOAMR99L           (*((uword volatile far *) 0x201C6C))

// Message Object 9 Acceptance Mask Register High
#define CAN_MOAMR9H            (*((uword volatile far *) 0x20112E))

// Message Object 9 Acceptance Mask Register Low
#define CAN_MOAMR9L            (*((uword volatile far *) 0x20112C))

// Message Object 0 Arbitration Register High
#define CAN_MOAR0H             (*((uword volatile far *) 0x20101A))

// Message Object 0 Arbitration Register Low
#define CAN_MOAR0L             (*((uword volatile far *) 0x201018))

// Message Object 100 Arbitration Register High
#define CAN_MOAR100H           (*((uword volatile far *) 0x201C9A))

// Message Object 100 Arbitration Register Low
#define CAN_MOAR100L           (*((uword volatile far *) 0x201C98))

// Message Object 101 Arbitration Register High
#define CAN_MOAR101H           (*((uword volatile far *) 0x201CBA))

// Message Object 101 Arbitration Register Low
#define CAN_MOAR101L           (*((uword volatile far *) 0x201CB8))

// Message Object 102 Arbitration Register High
#define CAN_MOAR102H           (*((uword volatile far *) 0x201CDA))

// Message Object 102 Arbitration Register Low
#define CAN_MOAR102L           (*((uword volatile far *) 0x201CD8))

// Message Object 103 Arbitration Register High
#define CAN_MOAR103H           (*((uword volatile far *) 0x201CFA))

// Message Object 103 Arbitration Register Low
#define CAN_MOAR103L           (*((uword volatile far *) 0x201CF8))

// Message Object 104 Arbitration Register High
#define CAN_MOAR104H           (*((uword volatile far *) 0x201D1A))

// Message Object 104 Arbitration Register Low
#define CAN_MOAR104L           (*((uword volatile far *) 0x201D18))

// Message Object 105 Arbitration Register High
#define CAN_MOAR105H           (*((uword volatile far *) 0x201D3A))

// Message Object 105 Arbitration Register Low
#define CAN_MOAR105L           (*((uword volatile far *) 0x201D38))

// Message Object 106 Arbitration Register High
#define CAN_MOAR106H           (*((uword volatile far *) 0x201D5A))

// Message Object 106 Arbitration Register Low
#define CAN_MOAR106L           (*((uword volatile far *) 0x201D58))

// Message Object 107 Arbitration Register High
#define CAN_MOAR107H           (*((uword volatile far *) 0x201D7A))

// Message Object 107 Arbitration Register Low
#define CAN_MOAR107L           (*((uword volatile far *) 0x201D78))

// Message Object 108 Arbitration Register High
#define CAN_MOAR108H           (*((uword volatile far *) 0x201D9A))

// Message Object 108 Arbitration Register Low
#define CAN_MOAR108L           (*((uword volatile far *) 0x201D98))

// Message Object 109 Arbitration Register High
#define CAN_MOAR109H           (*((uword volatile far *) 0x201DBA))

// Message Object 109 Arbitration Register Low
#define CAN_MOAR109L           (*((uword volatile far *) 0x201DB8))

// Message Object 10 Arbitration Register High
#define CAN_MOAR10H            (*((uword volatile far *) 0x20115A))

// Message Object 10 Arbitration Register Low
#define CAN_MOAR10L            (*((uword volatile far *) 0x201158))

// Message Object 110 Arbitration Register High
#define CAN_MOAR110H           (*((uword volatile far *) 0x201DDA))

// Message Object 110 Arbitration Register Low
#define CAN_MOAR110L           (*((uword volatile far *) 0x201DD8))

// Message Object 111 Arbitration Register High
#define CAN_MOAR111H           (*((uword volatile far *) 0x201DFA))

// Message Object 111 Arbitration Register Low
#define CAN_MOAR111L           (*((uword volatile far *) 0x201DF8))

// Message Object 112 Arbitration Register High
#define CAN_MOAR112H           (*((uword volatile far *) 0x201E1A))

// Message Object 112 Arbitration Register Low
#define CAN_MOAR112L           (*((uword volatile far *) 0x201E18))

// Message Object 113 Arbitration Register High
#define CAN_MOAR113H           (*((uword volatile far *) 0x201E3A))

// Message Object 113 Arbitration Register Low
#define CAN_MOAR113L           (*((uword volatile far *) 0x201E38))

// Message Object 114 Arbitration Register High
#define CAN_MOAR114H           (*((uword volatile far *) 0x201E5A))

// Message Object 114 Arbitration Register Low
#define CAN_MOAR114L           (*((uword volatile far *) 0x201E58))

// Message Object 115 Arbitration Register High
#define CAN_MOAR115H           (*((uword volatile far *) 0x201E7A))

// Message Object 115 Arbitration Register Low
#define CAN_MOAR115L           (*((uword volatile far *) 0x201E78))

// Message Object 116 Arbitration Register High
#define CAN_MOAR116H           (*((uword volatile far *) 0x201E9A))

// Message Object 116 Arbitration Register Low
#define CAN_MOAR116L           (*((uword volatile far *) 0x201E98))

// Message Object 117 Arbitration Register High
#define CAN_MOAR117H           (*((uword volatile far *) 0x201EBA))

// Message Object 117 Arbitration Register Low
#define CAN_MOAR117L           (*((uword volatile far *) 0x201EB8))

// Message Object 118 Arbitration Register High
#define CAN_MOAR118H           (*((uword volatile far *) 0x201EDA))

// Message Object 118 Arbitration Register Low
#define CAN_MOAR118L           (*((uword volatile far *) 0x201ED8))

// Message Object 119 Arbitration Register High
#define CAN_MOAR119H           (*((uword volatile far *) 0x201EFA))

// Message Object 119 Arbitration Register Low
#define CAN_MOAR119L           (*((uword volatile far *) 0x201EF8))

// Message Object 11 Arbitration Register High
#define CAN_MOAR11H            (*((uword volatile far *) 0x20117A))

// Message Object 11 Arbitration Register Low
#define CAN_MOAR11L            (*((uword volatile far *) 0x201178))

// Message Object 120 Arbitration Register High
#define CAN_MOAR120H           (*((uword volatile far *) 0x201F1A))

// Message Object 120 Arbitration Register Low
#define CAN_MOAR120L           (*((uword volatile far *) 0x201F18))

// Message Object 121 Arbitration Register High
#define CAN_MOAR121H           (*((uword volatile far *) 0x201F3A))

// Message Object 121 Arbitration Register Low
#define CAN_MOAR121L           (*((uword volatile far *) 0x201F38))

// Message Object 122 Arbitration Register High
#define CAN_MOAR122H           (*((uword volatile far *) 0x201F5A))

// Message Object 122 Arbitration Register Low
#define CAN_MOAR122L           (*((uword volatile far *) 0x201F58))

// Message Object 123 Arbitration Register High
#define CAN_MOAR123H           (*((uword volatile far *) 0x201F7A))

// Message Object 123 Arbitration Register Low
#define CAN_MOAR123L           (*((uword volatile far *) 0x201F78))

// Message Object 124 Arbitration Register High
#define CAN_MOAR124H           (*((uword volatile far *) 0x201F9A))

// Message Object 124 Arbitration Register Low
#define CAN_MOAR124L           (*((uword volatile far *) 0x201F98))

// Message Object 125 Arbitration Register High
#define CAN_MOAR125H           (*((uword volatile far *) 0x201FBA))

// Message Object 125 Arbitration Register Low
#define CAN_MOAR125L           (*((uword volatile far *) 0x201FB8))

// Message Object 126 Arbitration Register High
#define CAN_MOAR126H           (*((uword volatile far *) 0x201FDA))

// Message Object 126 Arbitration Register Low
#define CAN_MOAR126L           (*((uword volatile far *) 0x201FD8))

// Message Object 127 Arbitration Register High
#define CAN_MOAR127H           (*((uword volatile far *) 0x201FFA))

// Message Object 127 Arbitration Register Low
#define CAN_MOAR127L           (*((uword volatile far *) 0x201FF8))

// Message Object 128 Arbitration Register High
#define CAN_MOAR128H           (*((uword volatile far *) 0x20201A))

// Message Object 128 Arbitration Register Low
#define CAN_MOAR128L           (*((uword volatile far *) 0x202018))

// Message Object 129 Arbitration Register High
#define CAN_MOAR129H           (*((uword volatile far *) 0x20203A))

// Message Object 129 Arbitration Register Low
#define CAN_MOAR129L           (*((uword volatile far *) 0x202038))

// Message Object 12 Arbitration Register High
#define CAN_MOAR12H            (*((uword volatile far *) 0x20119A))

// Message Object 12 Arbitration Register Low
#define CAN_MOAR12L            (*((uword volatile far *) 0x201198))

// Message Object 130 Arbitration Register High
#define CAN_MOAR130H           (*((uword volatile far *) 0x20205A))

// Message Object 130 Arbitration Register Low
#define CAN_MOAR130L           (*((uword volatile far *) 0x202058))

// Message Object 131 Arbitration Register High
#define CAN_MOAR131H           (*((uword volatile far *) 0x20207A))

// Message Object 131 Arbitration Register Low
#define CAN_MOAR131L           (*((uword volatile far *) 0x202078))

// Message Object 132 Arbitration Register High
#define CAN_MOAR132H           (*((uword volatile far *) 0x20209A))

// Message Object 132 Arbitration Register Low
#define CAN_MOAR132L           (*((uword volatile far *) 0x202098))

// Message Object 133 Arbitration Register High
#define CAN_MOAR133H           (*((uword volatile far *) 0x2020BA))

// Message Object 133 Arbitration Register Low
#define CAN_MOAR133L           (*((uword volatile far *) 0x2020B8))

// Message Object 134 Arbitration Register High
#define CAN_MOAR134H           (*((uword volatile far *) 0x2020DA))

// Message Object 134 Arbitration Register Low
#define CAN_MOAR134L           (*((uword volatile far *) 0x2020D8))

// Message Object 135 Arbitration Register High
#define CAN_MOAR135H           (*((uword volatile far *) 0x2020FA))

// Message Object 135 Arbitration Register Low
#define CAN_MOAR135L           (*((uword volatile far *) 0x2020F8))

// Message Object 136 Arbitration Register High
#define CAN_MOAR136H           (*((uword volatile far *) 0x20211A))

// Message Object 136 Arbitration Register Low
#define CAN_MOAR136L           (*((uword volatile far *) 0x202118))

// Message Object 137 Arbitration Register High
#define CAN_MOAR137H           (*((uword volatile far *) 0x20213A))

// Message Object 137 Arbitration Register Low
#define CAN_MOAR137L           (*((uword volatile far *) 0x202138))

// Message Object 138 Arbitration Register High
#define CAN_MOAR138H           (*((uword volatile far *) 0x20215A))

// Message Object 138 Arbitration Register Low
#define CAN_MOAR138L           (*((uword volatile far *) 0x202158))

// Message Object 139 Arbitration Register High
#define CAN_MOAR139H           (*((uword volatile far *) 0x20217A))

// Message Object 139 Arbitration Register Low
#define CAN_MOAR139L           (*((uword volatile far *) 0x202178))

// Message Object 13 Arbitration Register High
#define CAN_MOAR13H            (*((uword volatile far *) 0x2011BA))

// Message Object 13 Arbitration Register Low
#define CAN_MOAR13L            (*((uword volatile far *) 0x2011B8))

// Message Object 140 Arbitration Register High
#define CAN_MOAR140H           (*((uword volatile far *) 0x20219A))

// Message Object 140 Arbitration Register Low
#define CAN_MOAR140L           (*((uword volatile far *) 0x202198))

// Message Object 141 Arbitration Register High
#define CAN_MOAR141H           (*((uword volatile far *) 0x2021BA))

// Message Object 141 Arbitration Register Low
#define CAN_MOAR141L           (*((uword volatile far *) 0x2021B8))

// Message Object 142 Arbitration Register High
#define CAN_MOAR142H           (*((uword volatile far *) 0x2021DA))

// Message Object 142 Arbitration Register Low
#define CAN_MOAR142L           (*((uword volatile far *) 0x2021D8))

// Message Object 143 Arbitration Register High
#define CAN_MOAR143H           (*((uword volatile far *) 0x2021FA))

// Message Object 143 Arbitration Register Low
#define CAN_MOAR143L           (*((uword volatile far *) 0x2021F8))

// Message Object 144 Arbitration Register High
#define CAN_MOAR144H           (*((uword volatile far *) 0x20221A))

// Message Object 144 Arbitration Register Low
#define CAN_MOAR144L           (*((uword volatile far *) 0x202218))

// Message Object 145 Arbitration Register High
#define CAN_MOAR145H           (*((uword volatile far *) 0x20223A))

// Message Object 145 Arbitration Register Low
#define CAN_MOAR145L           (*((uword volatile far *) 0x202238))

// Message Object 146 Arbitration Register High
#define CAN_MOAR146H           (*((uword volatile far *) 0x20225A))

// Message Object 146 Arbitration Register Low
#define CAN_MOAR146L           (*((uword volatile far *) 0x202258))

// Message Object 147 Arbitration Register High
#define CAN_MOAR147H           (*((uword volatile far *) 0x20227A))

// Message Object 147 Arbitration Register Low
#define CAN_MOAR147L           (*((uword volatile far *) 0x202278))

// Message Object 148 Arbitration Register High
#define CAN_MOAR148H           (*((uword volatile far *) 0x20229A))

// Message Object 148 Arbitration Register Low
#define CAN_MOAR148L           (*((uword volatile far *) 0x202298))

// Message Object 149 Arbitration Register High
#define CAN_MOAR149H           (*((uword volatile far *) 0x2022BA))

// Message Object 149 Arbitration Register Low
#define CAN_MOAR149L           (*((uword volatile far *) 0x2022B8))

// Message Object 14 Arbitration Register High
#define CAN_MOAR14H            (*((uword volatile far *) 0x2011DA))

// Message Object 14 Arbitration Register Low
#define CAN_MOAR14L            (*((uword volatile far *) 0x2011D8))

// Message Object 150 Arbitration Register High
#define CAN_MOAR150H           (*((uword volatile far *) 0x2022DA))

// Message Object 150 Arbitration Register Low
#define CAN_MOAR150L           (*((uword volatile far *) 0x2022D8))

// Message Object 151 Arbitration Register High
#define CAN_MOAR151H           (*((uword volatile far *) 0x2022FA))

// Message Object 151 Arbitration Register Low
#define CAN_MOAR151L           (*((uword volatile far *) 0x2022F8))

// Message Object 152 Arbitration Register High
#define CAN_MOAR152H           (*((uword volatile far *) 0x20231A))

// Message Object 152 Arbitration Register Low
#define CAN_MOAR152L           (*((uword volatile far *) 0x202318))

// Message Object 153 Arbitration Register High
#define CAN_MOAR153H           (*((uword volatile far *) 0x20233A))

// Message Object 153 Arbitration Register Low
#define CAN_MOAR153L           (*((uword volatile far *) 0x202338))

// Message Object 154 Arbitration Register High
#define CAN_MOAR154H           (*((uword volatile far *) 0x20235A))

// Message Object 154 Arbitration Register Low
#define CAN_MOAR154L           (*((uword volatile far *) 0x202358))

// Message Object 155 Arbitration Register High
#define CAN_MOAR155H           (*((uword volatile far *) 0x20237A))

// Message Object 155 Arbitration Register Low
#define CAN_MOAR155L           (*((uword volatile far *) 0x202378))

// Message Object 156 Arbitration Register High
#define CAN_MOAR156H           (*((uword volatile far *) 0x20239A))

// Message Object 156 Arbitration Register Low
#define CAN_MOAR156L           (*((uword volatile far *) 0x202398))

// Message Object 157 Arbitration Register High
#define CAN_MOAR157H           (*((uword volatile far *) 0x2023BA))

// Message Object 157 Arbitration Register Low
#define CAN_MOAR157L           (*((uword volatile far *) 0x2023B8))

// Message Object 158 Arbitration Register High
#define CAN_MOAR158H           (*((uword volatile far *) 0x2023DA))

// Message Object 158 Arbitration Register Low
#define CAN_MOAR158L           (*((uword volatile far *) 0x2023D8))

// Message Object 159 Arbitration Register High
#define CAN_MOAR159H           (*((uword volatile far *) 0x2023FA))

// Message Object 159 Arbitration Register Low
#define CAN_MOAR159L           (*((uword volatile far *) 0x2023F8))

// Message Object 15 Arbitration Register High
#define CAN_MOAR15H            (*((uword volatile far *) 0x2011FA))

// Message Object 15 Arbitration Register Low
#define CAN_MOAR15L            (*((uword volatile far *) 0x2011F8))

// Message Object 160 Arbitration Register High
#define CAN_MOAR160H           (*((uword volatile far *) 0x20241A))

// Message Object 160 Arbitration Register Low
#define CAN_MOAR160L           (*((uword volatile far *) 0x202418))

// Message Object 161 Arbitration Register High
#define CAN_MOAR161H           (*((uword volatile far *) 0x20243A))

// Message Object 161 Arbitration Register Low
#define CAN_MOAR161L           (*((uword volatile far *) 0x202438))

// Message Object 162 Arbitration Register High
#define CAN_MOAR162H           (*((uword volatile far *) 0x20245A))

// Message Object 162 Arbitration Register Low
#define CAN_MOAR162L           (*((uword volatile far *) 0x202458))

// Message Object 163 Arbitration Register High
#define CAN_MOAR163H           (*((uword volatile far *) 0x20247A))

// Message Object 163 Arbitration Register Low
#define CAN_MOAR163L           (*((uword volatile far *) 0x202478))

// Message Object 164 Arbitration Register High
#define CAN_MOAR164H           (*((uword volatile far *) 0x20249A))

// Message Object 164 Arbitration Register Low
#define CAN_MOAR164L           (*((uword volatile far *) 0x202498))

// Message Object 165 Arbitration Register High
#define CAN_MOAR165H           (*((uword volatile far *) 0x2024BA))

// Message Object 165 Arbitration Register Low
#define CAN_MOAR165L           (*((uword volatile far *) 0x2024B8))

// Message Object 166 Arbitration Register High
#define CAN_MOAR166H           (*((uword volatile far *) 0x2024DA))

// Message Object 166 Arbitration Register Low
#define CAN_MOAR166L           (*((uword volatile far *) 0x2024D8))

// Message Object 167 Arbitration Register High
#define CAN_MOAR167H           (*((uword volatile far *) 0x2024FA))

// Message Object 167 Arbitration Register Low
#define CAN_MOAR167L           (*((uword volatile far *) 0x2024F8))

// Message Object 168 Arbitration Register High
#define CAN_MOAR168H           (*((uword volatile far *) 0x20251A))

// Message Object 168 Arbitration Register Low
#define CAN_MOAR168L           (*((uword volatile far *) 0x202518))

// Message Object 169 Arbitration Register High
#define CAN_MOAR169H           (*((uword volatile far *) 0x20253A))

// Message Object 169 Arbitration Register Low
#define CAN_MOAR169L           (*((uword volatile far *) 0x202538))

// Message Object 16 Arbitration Register High
#define CAN_MOAR16H            (*((uword volatile far *) 0x20121A))

// Message Object 16 Arbitration Register Low
#define CAN_MOAR16L            (*((uword volatile far *) 0x201218))

// Message Object 170 Arbitration Register High
#define CAN_MOAR170H           (*((uword volatile far *) 0x20255A))

// Message Object 170 Arbitration Register Low
#define CAN_MOAR170L           (*((uword volatile far *) 0x202558))

// Message Object 171 Arbitration Register High
#define CAN_MOAR171H           (*((uword volatile far *) 0x20257A))

// Message Object 171 Arbitration Register Low
#define CAN_MOAR171L           (*((uword volatile far *) 0x202578))

// Message Object 172 Arbitration Register High
#define CAN_MOAR172H           (*((uword volatile far *) 0x20259A))

// Message Object 172 Arbitration Register Low
#define CAN_MOAR172L           (*((uword volatile far *) 0x202598))

// Message Object 173 Arbitration Register High
#define CAN_MOAR173H           (*((uword volatile far *) 0x2025BA))

// Message Object 173 Arbitration Register Low
#define CAN_MOAR173L           (*((uword volatile far *) 0x2025B8))

// Message Object 174 Arbitration Register High
#define CAN_MOAR174H           (*((uword volatile far *) 0x2025DA))

// Message Object 174 Arbitration Register Low
#define CAN_MOAR174L           (*((uword volatile far *) 0x2025D8))

// Message Object 175 Arbitration Register High
#define CAN_MOAR175H           (*((uword volatile far *) 0x2025FA))

// Message Object 175 Arbitration Register Low
#define CAN_MOAR175L           (*((uword volatile far *) 0x2025F8))

// Message Object 176 Arbitration Register High
#define CAN_MOAR176H           (*((uword volatile far *) 0x20261A))

// Message Object 176 Arbitration Register Low
#define CAN_MOAR176L           (*((uword volatile far *) 0x202618))

// Message Object 177 Arbitration Register High
#define CAN_MOAR177H           (*((uword volatile far *) 0x20263A))

// Message Object 177 Arbitration Register Low
#define CAN_MOAR177L           (*((uword volatile far *) 0x202638))

// Message Object 178 Arbitration Register High
#define CAN_MOAR178H           (*((uword volatile far *) 0x20265A))

// Message Object 178 Arbitration Register Low
#define CAN_MOAR178L           (*((uword volatile far *) 0x202658))

// Message Object 179 Arbitration Register High
#define CAN_MOAR179H           (*((uword volatile far *) 0x20267A))

// Message Object 179 Arbitration Register Low
#define CAN_MOAR179L           (*((uword volatile far *) 0x202678))

// Message Object 17 Arbitration Register High
#define CAN_MOAR17H            (*((uword volatile far *) 0x20123A))

// Message Object 17 Arbitration Register Low
#define CAN_MOAR17L            (*((uword volatile far *) 0x201238))

// Message Object 180 Arbitration Register High
#define CAN_MOAR180H           (*((uword volatile far *) 0x20269A))

// Message Object 180 Arbitration Register Low
#define CAN_MOAR180L           (*((uword volatile far *) 0x202698))

// Message Object 181 Arbitration Register High
#define CAN_MOAR181H           (*((uword volatile far *) 0x2026BA))

// Message Object 181 Arbitration Register Low
#define CAN_MOAR181L           (*((uword volatile far *) 0x2026B8))

// Message Object 182 Arbitration Register High
#define CAN_MOAR182H           (*((uword volatile far *) 0x2026DA))

// Message Object 182 Arbitration Register Low
#define CAN_MOAR182L           (*((uword volatile far *) 0x2026D8))

// Message Object 183 Arbitration Register High
#define CAN_MOAR183H           (*((uword volatile far *) 0x2026FA))

// Message Object 183 Arbitration Register Low
#define CAN_MOAR183L           (*((uword volatile far *) 0x2026F8))

// Message Object 184 Arbitration Register High
#define CAN_MOAR184H           (*((uword volatile far *) 0x20271A))

// Message Object 184 Arbitration Register Low
#define CAN_MOAR184L           (*((uword volatile far *) 0x202718))

// Message Object 185 Arbitration Register High
#define CAN_MOAR185H           (*((uword volatile far *) 0x20273A))

// Message Object 185 Arbitration Register Low
#define CAN_MOAR185L           (*((uword volatile far *) 0x202738))

// Message Object 186 Arbitration Register High
#define CAN_MOAR186H           (*((uword volatile far *) 0x20275A))

// Message Object 186 Arbitration Register Low
#define CAN_MOAR186L           (*((uword volatile far *) 0x202758))

// Message Object 187 Arbitration Register High
#define CAN_MOAR187H           (*((uword volatile far *) 0x20277A))

// Message Object 187 Arbitration Register Low
#define CAN_MOAR187L           (*((uword volatile far *) 0x202778))

// Message Object 188 Arbitration Register High
#define CAN_MOAR188H           (*((uword volatile far *) 0x20279A))

// Message Object 188 Arbitration Register Low
#define CAN_MOAR188L           (*((uword volatile far *) 0x202798))

// Message Object 189 Arbitration Register High
#define CAN_MOAR189H           (*((uword volatile far *) 0x2027BA))

// Message Object 189 Arbitration Register Low
#define CAN_MOAR189L           (*((uword volatile far *) 0x2027B8))

// Message Object 18 Arbitration Register High
#define CAN_MOAR18H            (*((uword volatile far *) 0x20125A))

// Message Object 18 Arbitration Register Low
#define CAN_MOAR18L            (*((uword volatile far *) 0x201258))

// Message Object 190 Arbitration Register High
#define CAN_MOAR190H           (*((uword volatile far *) 0x2027DA))

// Message Object 190 Arbitration Register Low
#define CAN_MOAR190L           (*((uword volatile far *) 0x2027D8))

// Message Object 191 Arbitration Register High
#define CAN_MOAR191H           (*((uword volatile far *) 0x2027FA))

// Message Object 191 Arbitration Register Low
#define CAN_MOAR191L           (*((uword volatile far *) 0x2027F8))

// Message Object 192 Arbitration Register High
#define CAN_MOAR192H           (*((uword volatile far *) 0x20281A))

// Message Object 192 Arbitration Register Low
#define CAN_MOAR192L           (*((uword volatile far *) 0x202818))

// Message Object 193 Arbitration Register High
#define CAN_MOAR193H           (*((uword volatile far *) 0x20283A))

// Message Object 193 Arbitration Register Low
#define CAN_MOAR193L           (*((uword volatile far *) 0x202838))

// Message Object 194 Arbitration Register High
#define CAN_MOAR194H           (*((uword volatile far *) 0x20285A))

// Message Object 194 Arbitration Register Low
#define CAN_MOAR194L           (*((uword volatile far *) 0x202858))

// Message Object 195 Arbitration Register High
#define CAN_MOAR195H           (*((uword volatile far *) 0x20287A))

// Message Object 195 Arbitration Register Low
#define CAN_MOAR195L           (*((uword volatile far *) 0x202878))

// Message Object 196 Arbitration Register High
#define CAN_MOAR196H           (*((uword volatile far *) 0x20289A))

// Message Object 196 Arbitration Register Low
#define CAN_MOAR196L           (*((uword volatile far *) 0x202898))

// Message Object 197 Arbitration Register High
#define CAN_MOAR197H           (*((uword volatile far *) 0x2028BA))

// Message Object 197 Arbitration Register Low
#define CAN_MOAR197L           (*((uword volatile far *) 0x2028B8))

// Message Object 198 Arbitration Register High
#define CAN_MOAR198H           (*((uword volatile far *) 0x2028DA))

// Message Object 198 Arbitration Register Low
#define CAN_MOAR198L           (*((uword volatile far *) 0x2028D8))

// Message Object 199 Arbitration Register High
#define CAN_MOAR199H           (*((uword volatile far *) 0x2028FA))

// Message Object 199 Arbitration Register Low
#define CAN_MOAR199L           (*((uword volatile far *) 0x2028F8))

// Message Object 19 Arbitration Register High
#define CAN_MOAR19H            (*((uword volatile far *) 0x20127A))

// Message Object 19 Arbitration Register Low
#define CAN_MOAR19L            (*((uword volatile far *) 0x201278))

// Message Object 1 Arbitration Register High
#define CAN_MOAR1H             (*((uword volatile far *) 0x20103A))

// Message Object 1 Arbitration Register Low
#define CAN_MOAR1L             (*((uword volatile far *) 0x201038))

// Message Object 200 Arbitration Register High
#define CAN_MOAR200H           (*((uword volatile far *) 0x20291A))

// Message Object 200 Arbitration Register Low
#define CAN_MOAR200L           (*((uword volatile far *) 0x202918))

// Message Object 201 Arbitration Register High
#define CAN_MOAR201H           (*((uword volatile far *) 0x20293A))

// Message Object 201 Arbitration Register Low
#define CAN_MOAR201L           (*((uword volatile far *) 0x202938))

// Message Object 202 Arbitration Register High
#define CAN_MOAR202H           (*((uword volatile far *) 0x20295A))

// Message Object 202 Arbitration Register Low
#define CAN_MOAR202L           (*((uword volatile far *) 0x202958))

// Message Object 203 Arbitration Register High
#define CAN_MOAR203H           (*((uword volatile far *) 0x20297A))

// Message Object 203 Arbitration Register Low
#define CAN_MOAR203L           (*((uword volatile far *) 0x202978))

// Message Object 204 Arbitration Register High
#define CAN_MOAR204H           (*((uword volatile far *) 0x20299A))

// Message Object 204 Arbitration Register Low
#define CAN_MOAR204L           (*((uword volatile far *) 0x202998))

// Message Object 205 Arbitration Register High
#define CAN_MOAR205H           (*((uword volatile far *) 0x2029BA))

// Message Object 205 Arbitration Register Low
#define CAN_MOAR205L           (*((uword volatile far *) 0x2029B8))

// Message Object 206 Arbitration Register High
#define CAN_MOAR206H           (*((uword volatile far *) 0x2029DA))

// Message Object 206 Arbitration Register Low
#define CAN_MOAR206L           (*((uword volatile far *) 0x2029D8))

// Message Object 207 Arbitration Register High
#define CAN_MOAR207H           (*((uword volatile far *) 0x2029FA))

// Message Object 207 Arbitration Register Low
#define CAN_MOAR207L           (*((uword volatile far *) 0x2029F8))

// Message Object 208 Arbitration Register High
#define CAN_MOAR208H           (*((uword volatile far *) 0x202A1A))

// Message Object 208 Arbitration Register Low
#define CAN_MOAR208L           (*((uword volatile far *) 0x202A18))

// Message Object 209 Arbitration Register High
#define CAN_MOAR209H           (*((uword volatile far *) 0x202A3A))

// Message Object 209 Arbitration Register Low
#define CAN_MOAR209L           (*((uword volatile far *) 0x202A38))

// Message Object 20 Arbitration Register High
#define CAN_MOAR20H            (*((uword volatile far *) 0x20129A))

// Message Object 20 Arbitration Register Low
#define CAN_MOAR20L            (*((uword volatile far *) 0x201298))

// Message Object 210 Arbitration Register High
#define CAN_MOAR210H           (*((uword volatile far *) 0x202A5A))

// Message Object 210 Arbitration Register Low
#define CAN_MOAR210L           (*((uword volatile far *) 0x202A58))

// Message Object 211 Arbitration Register High
#define CAN_MOAR211H           (*((uword volatile far *) 0x202A7A))

// Message Object 211 Arbitration Register Low
#define CAN_MOAR211L           (*((uword volatile far *) 0x202A78))

// Message Object 212 Arbitration Register High
#define CAN_MOAR212H           (*((uword volatile far *) 0x202A9A))

// Message Object 212 Arbitration Register Low
#define CAN_MOAR212L           (*((uword volatile far *) 0x202A98))

// Message Object 213 Arbitration Register High
#define CAN_MOAR213H           (*((uword volatile far *) 0x202ABA))

// Message Object 213 Arbitration Register Low
#define CAN_MOAR213L           (*((uword volatile far *) 0x202AB8))

// Message Object 214 Arbitration Register High
#define CAN_MOAR214H           (*((uword volatile far *) 0x202ADA))

// Message Object 214 Arbitration Register Low
#define CAN_MOAR214L           (*((uword volatile far *) 0x202AD8))

// Message Object 215 Arbitration Register High
#define CAN_MOAR215H           (*((uword volatile far *) 0x202AFA))

// Message Object 215 Arbitration Register Low
#define CAN_MOAR215L           (*((uword volatile far *) 0x202AF8))

// Message Object 216 Arbitration Register High
#define CAN_MOAR216H           (*((uword volatile far *) 0x202B1A))

// Message Object 216 Arbitration Register Low
#define CAN_MOAR216L           (*((uword volatile far *) 0x202B18))

// Message Object 217 Arbitration Register High
#define CAN_MOAR217H           (*((uword volatile far *) 0x202B3A))

// Message Object 217 Arbitration Register Low
#define CAN_MOAR217L           (*((uword volatile far *) 0x202B38))

// Message Object 218 Arbitration Register High
#define CAN_MOAR218H           (*((uword volatile far *) 0x202B5A))

// Message Object 218 Arbitration Register Low
#define CAN_MOAR218L           (*((uword volatile far *) 0x202B58))

// Message Object 219 Arbitration Register High
#define CAN_MOAR219H           (*((uword volatile far *) 0x202B7A))

// Message Object 219 Arbitration Register Low
#define CAN_MOAR219L           (*((uword volatile far *) 0x202B78))

// Message Object 21 Arbitration Register High
#define CAN_MOAR21H            (*((uword volatile far *) 0x2012BA))

// Message Object 21 Arbitration Register Low
#define CAN_MOAR21L            (*((uword volatile far *) 0x2012B8))

// Message Object 220 Arbitration Register High
#define CAN_MOAR220H           (*((uword volatile far *) 0x202B9A))

// Message Object 220 Arbitration Register Low
#define CAN_MOAR220L           (*((uword volatile far *) 0x202B98))

// Message Object 221 Arbitration Register High
#define CAN_MOAR221H           (*((uword volatile far *) 0x202BBA))

// Message Object 221 Arbitration Register Low
#define CAN_MOAR221L           (*((uword volatile far *) 0x202BB8))

// Message Object 222 Arbitration Register High
#define CAN_MOAR222H           (*((uword volatile far *) 0x202BDA))

// Message Object 222 Arbitration Register Low
#define CAN_MOAR222L           (*((uword volatile far *) 0x202BD8))

// Message Object 223 Arbitration Register High
#define CAN_MOAR223H           (*((uword volatile far *) 0x202BFA))

// Message Object 223 Arbitration Register Low
#define CAN_MOAR223L           (*((uword volatile far *) 0x202BF8))

// Message Object 224 Arbitration Register High
#define CAN_MOAR224H           (*((uword volatile far *) 0x202C1A))

// Message Object 224 Arbitration Register Low
#define CAN_MOAR224L           (*((uword volatile far *) 0x202C18))

// Message Object 225 Arbitration Register High
#define CAN_MOAR225H           (*((uword volatile far *) 0x202C3A))

// Message Object 225 Arbitration Register Low
#define CAN_MOAR225L           (*((uword volatile far *) 0x202C38))

// Message Object 226 Arbitration Register High
#define CAN_MOAR226H           (*((uword volatile far *) 0x202C5A))

// Message Object 226 Arbitration Register Low
#define CAN_MOAR226L           (*((uword volatile far *) 0x202C58))

// Message Object 227 Arbitration Register High
#define CAN_MOAR227H           (*((uword volatile far *) 0x202C7A))

// Message Object 227 Arbitration Register Low
#define CAN_MOAR227L           (*((uword volatile far *) 0x202C78))

// Message Object 228 Arbitration Register High
#define CAN_MOAR228H           (*((uword volatile far *) 0x202C9A))

// Message Object 228 Arbitration Register Low
#define CAN_MOAR228L           (*((uword volatile far *) 0x202C98))

// Message Object 229 Arbitration Register High
#define CAN_MOAR229H           (*((uword volatile far *) 0x202CBA))

// Message Object 229 Arbitration Register Low
#define CAN_MOAR229L           (*((uword volatile far *) 0x202CB8))

// Message Object 22 Arbitration Register High
#define CAN_MOAR22H            (*((uword volatile far *) 0x2012DA))

// Message Object 22 Arbitration Register Low
#define CAN_MOAR22L            (*((uword volatile far *) 0x2012D8))

// Message Object 230 Arbitration Register High
#define CAN_MOAR230H           (*((uword volatile far *) 0x202CDA))

// Message Object 230 Arbitration Register Low
#define CAN_MOAR230L           (*((uword volatile far *) 0x202CD8))

// Message Object 231 Arbitration Register High
#define CAN_MOAR231H           (*((uword volatile far *) 0x202CFA))

// Message Object 231 Arbitration Register Low
#define CAN_MOAR231L           (*((uword volatile far *) 0x202CF8))

// Message Object 232 Arbitration Register High
#define CAN_MOAR232H           (*((uword volatile far *) 0x202D1A))

// Message Object 232 Arbitration Register Low
#define CAN_MOAR232L           (*((uword volatile far *) 0x202D18))

// Message Object 233 Arbitration Register High
#define CAN_MOAR233H           (*((uword volatile far *) 0x202D3A))

// Message Object 233 Arbitration Register Low
#define CAN_MOAR233L           (*((uword volatile far *) 0x202D38))

// Message Object 234 Arbitration Register High
#define CAN_MOAR234H           (*((uword volatile far *) 0x202D5A))

// Message Object 234 Arbitration Register Low
#define CAN_MOAR234L           (*((uword volatile far *) 0x202D58))

// Message Object 235 Arbitration Register High
#define CAN_MOAR235H           (*((uword volatile far *) 0x202D7A))

// Message Object 235 Arbitration Register Low
#define CAN_MOAR235L           (*((uword volatile far *) 0x202D78))

// Message Object 236 Arbitration Register High
#define CAN_MOAR236H           (*((uword volatile far *) 0x202D9A))

// Message Object 236 Arbitration Register Low
#define CAN_MOAR236L           (*((uword volatile far *) 0x202D98))

// Message Object 237 Arbitration Register High
#define CAN_MOAR237H           (*((uword volatile far *) 0x202DBA))

// Message Object 237 Arbitration Register Low
#define CAN_MOAR237L           (*((uword volatile far *) 0x202DB8))

// Message Object 238 Arbitration Register High
#define CAN_MOAR238H           (*((uword volatile far *) 0x202DDA))

// Message Object 238 Arbitration Register Low
#define CAN_MOAR238L           (*((uword volatile far *) 0x202DD8))

// Message Object 239 Arbitration Register High
#define CAN_MOAR239H           (*((uword volatile far *) 0x202DFA))

// Message Object 239 Arbitration Register Low
#define CAN_MOAR239L           (*((uword volatile far *) 0x202DF8))

// Message Object 23 Arbitration Register High
#define CAN_MOAR23H            (*((uword volatile far *) 0x2012FA))

// Message Object 23 Arbitration Register Low
#define CAN_MOAR23L            (*((uword volatile far *) 0x2012F8))

// Message Object 240 Arbitration Register High
#define CAN_MOAR240H           (*((uword volatile far *) 0x202E1A))

// Message Object 240 Arbitration Register Low
#define CAN_MOAR240L           (*((uword volatile far *) 0x202E18))

// Message Object 241 Arbitration Register High
#define CAN_MOAR241H           (*((uword volatile far *) 0x202E3A))

// Message Object 241 Arbitration Register Low
#define CAN_MOAR241L           (*((uword volatile far *) 0x202E38))

// Message Object 242 Arbitration Register High
#define CAN_MOAR242H           (*((uword volatile far *) 0x202E5A))

// Message Object 242 Arbitration Register Low
#define CAN_MOAR242L           (*((uword volatile far *) 0x202E58))

// Message Object 243 Arbitration Register High
#define CAN_MOAR243H           (*((uword volatile far *) 0x202E7A))

// Message Object 243 Arbitration Register Low
#define CAN_MOAR243L           (*((uword volatile far *) 0x202E78))

// Message Object 244 Arbitration Register High
#define CAN_MOAR244H           (*((uword volatile far *) 0x202E9A))

// Message Object 244 Arbitration Register Low
#define CAN_MOAR244L           (*((uword volatile far *) 0x202E98))

// Message Object 245 Arbitration Register High
#define CAN_MOAR245H           (*((uword volatile far *) 0x202EBA))

// Message Object 245 Arbitration Register Low
#define CAN_MOAR245L           (*((uword volatile far *) 0x202EB8))

// Message Object 246 Arbitration Register High
#define CAN_MOAR246H           (*((uword volatile far *) 0x202EDA))

// Message Object 246 Arbitration Register Low
#define CAN_MOAR246L           (*((uword volatile far *) 0x202ED8))

// Message Object 247 Arbitration Register High
#define CAN_MOAR247H           (*((uword volatile far *) 0x202EFA))

// Message Object 247 Arbitration Register Low
#define CAN_MOAR247L           (*((uword volatile far *) 0x202EF8))

// Message Object 248 Arbitration Register High
#define CAN_MOAR248H           (*((uword volatile far *) 0x202F1A))

// Message Object 248 Arbitration Register Low
#define CAN_MOAR248L           (*((uword volatile far *) 0x202F18))

// Message Object 249 Arbitration Register High
#define CAN_MOAR249H           (*((uword volatile far *) 0x202F3A))

// Message Object 249 Arbitration Register Low
#define CAN_MOAR249L           (*((uword volatile far *) 0x202F38))

// Message Object 24 Arbitration Register High
#define CAN_MOAR24H            (*((uword volatile far *) 0x20131A))

// Message Object 24 Arbitration Register Low
#define CAN_MOAR24L            (*((uword volatile far *) 0x201318))

// Message Object 250 Arbitration Register High
#define CAN_MOAR250H           (*((uword volatile far *) 0x202F5A))

// Message Object 250 Arbitration Register Low
#define CAN_MOAR250L           (*((uword volatile far *) 0x202F58))

// Message Object 251 Arbitration Register High
#define CAN_MOAR251H           (*((uword volatile far *) 0x202F7A))

// Message Object 251 Arbitration Register Low
#define CAN_MOAR251L           (*((uword volatile far *) 0x202F78))

// Message Object 252 Arbitration Register High
#define CAN_MOAR252H           (*((uword volatile far *) 0x202F9A))

// Message Object 252 Arbitration Register Low
#define CAN_MOAR252L           (*((uword volatile far *) 0x202F98))

// Message Object 253 Arbitration Register High
#define CAN_MOAR253H           (*((uword volatile far *) 0x202FBA))

// Message Object 253 Arbitration Register Low
#define CAN_MOAR253L           (*((uword volatile far *) 0x202FB8))

// Message Object 254 Arbitration Register High
#define CAN_MOAR254H           (*((uword volatile far *) 0x202FDA))

// Message Object 254 Arbitration Register Low
#define CAN_MOAR254L           (*((uword volatile far *) 0x202FD8))

// Message Object 255 Arbitration Register High
#define CAN_MOAR255H           (*((uword volatile far *) 0x202FFA))

// Message Object 255 Arbitration Register Low
#define CAN_MOAR255L           (*((uword volatile far *) 0x202FF8))

// Message Object 25 Arbitration Register High
#define CAN_MOAR25H            (*((uword volatile far *) 0x20133A))

// Message Object 25 Arbitration Register Low
#define CAN_MOAR25L            (*((uword volatile far *) 0x201338))

// Message Object 26 Arbitration Register High
#define CAN_MOAR26H            (*((uword volatile far *) 0x20135A))

// Message Object 26 Arbitration Register Low
#define CAN_MOAR26L            (*((uword volatile far *) 0x201358))

// Message Object 27 Arbitration Register High
#define CAN_MOAR27H            (*((uword volatile far *) 0x20137A))

// Message Object 27 Arbitration Register Low
#define CAN_MOAR27L            (*((uword volatile far *) 0x201378))

// Message Object 28 Arbitration Register High
#define CAN_MOAR28H            (*((uword volatile far *) 0x20139A))

// Message Object 28 Arbitration Register Low
#define CAN_MOAR28L            (*((uword volatile far *) 0x201398))

// Message Object 29 Arbitration Register High
#define CAN_MOAR29H            (*((uword volatile far *) 0x2013BA))

// Message Object 29 Arbitration Register Low
#define CAN_MOAR29L            (*((uword volatile far *) 0x2013B8))

// Message Object 2 Arbitration Register High
#define CAN_MOAR2H             (*((uword volatile far *) 0x20105A))

// Message Object 2 Arbitration Register Low
#define CAN_MOAR2L             (*((uword volatile far *) 0x201058))

// Message Object 30 Arbitration Register High
#define CAN_MOAR30H            (*((uword volatile far *) 0x2013DA))

// Message Object 30 Arbitration Register Low
#define CAN_MOAR30L            (*((uword volatile far *) 0x2013D8))

// Message Object 31 Arbitration Register High
#define CAN_MOAR31H            (*((uword volatile far *) 0x2013FA))

// Message Object 31 Arbitration Register Low
#define CAN_MOAR31L            (*((uword volatile far *) 0x2013F8))

// Message Object 32 Arbitration Register High
#define CAN_MOAR32H            (*((uword volatile far *) 0x20141A))

// Message Object 32 Arbitration Register Low
#define CAN_MOAR32L            (*((uword volatile far *) 0x201418))

// Message Object 33 Arbitration Register High
#define CAN_MOAR33H            (*((uword volatile far *) 0x20143A))

// Message Object 33 Arbitration Register Low
#define CAN_MOAR33L            (*((uword volatile far *) 0x201438))

// Message Object 34 Arbitration Register High
#define CAN_MOAR34H            (*((uword volatile far *) 0x20145A))

// Message Object 34 Arbitration Register Low
#define CAN_MOAR34L            (*((uword volatile far *) 0x201458))

// Message Object 35 Arbitration Register High
#define CAN_MOAR35H            (*((uword volatile far *) 0x20147A))

// Message Object 35 Arbitration Register Low
#define CAN_MOAR35L            (*((uword volatile far *) 0x201478))

// Message Object 36 Arbitration Register High
#define CAN_MOAR36H            (*((uword volatile far *) 0x20149A))

// Message Object 36 Arbitration Register Low
#define CAN_MOAR36L            (*((uword volatile far *) 0x201498))

// Message Object 37 Arbitration Register High
#define CAN_MOAR37H            (*((uword volatile far *) 0x2014BA))

// Message Object 37 Arbitration Register Low
#define CAN_MOAR37L            (*((uword volatile far *) 0x2014B8))

// Message Object 38 Arbitration Register High
#define CAN_MOAR38H            (*((uword volatile far *) 0x2014DA))

// Message Object 38 Arbitration Register Low
#define CAN_MOAR38L            (*((uword volatile far *) 0x2014D8))

// Message Object 39 Arbitration Register High
#define CAN_MOAR39H            (*((uword volatile far *) 0x2014FA))

// Message Object 39 Arbitration Register Low
#define CAN_MOAR39L            (*((uword volatile far *) 0x2014F8))

// Message Object 3 Arbitration Register High
#define CAN_MOAR3H             (*((uword volatile far *) 0x20107A))

// Message Object 3 Arbitration Register Low
#define CAN_MOAR3L             (*((uword volatile far *) 0x201078))

// Message Object 40 Arbitration Register High
#define CAN_MOAR40H            (*((uword volatile far *) 0x20151A))

// Message Object 40 Arbitration Register Low
#define CAN_MOAR40L            (*((uword volatile far *) 0x201518))

// Message Object 41 Arbitration Register High
#define CAN_MOAR41H            (*((uword volatile far *) 0x20153A))

// Message Object 41 Arbitration Register Low
#define CAN_MOAR41L            (*((uword volatile far *) 0x201538))

// Message Object 42 Arbitration Register High
#define CAN_MOAR42H            (*((uword volatile far *) 0x20155A))

// Message Object 42 Arbitration Register Low
#define CAN_MOAR42L            (*((uword volatile far *) 0x201558))

// Message Object 43 Arbitration Register High
#define CAN_MOAR43H            (*((uword volatile far *) 0x20157A))

// Message Object 43 Arbitration Register Low
#define CAN_MOAR43L            (*((uword volatile far *) 0x201578))

// Message Object 44 Arbitration Register High
#define CAN_MOAR44H            (*((uword volatile far *) 0x20159A))

// Message Object 44 Arbitration Register Low
#define CAN_MOAR44L            (*((uword volatile far *) 0x201598))

// Message Object 45 Arbitration Register High
#define CAN_MOAR45H            (*((uword volatile far *) 0x2015BA))

// Message Object 45 Arbitration Register Low
#define CAN_MOAR45L            (*((uword volatile far *) 0x2015B8))

// Message Object 46 Arbitration Register High
#define CAN_MOAR46H            (*((uword volatile far *) 0x2015DA))

// Message Object 46 Arbitration Register Low
#define CAN_MOAR46L            (*((uword volatile far *) 0x2015D8))

// Message Object 47 Arbitration Register High
#define CAN_MOAR47H            (*((uword volatile far *) 0x2015FA))

// Message Object 47 Arbitration Register Low
#define CAN_MOAR47L            (*((uword volatile far *) 0x2015F8))

// Message Object 48 Arbitration Register High
#define CAN_MOAR48H            (*((uword volatile far *) 0x20161A))

// Message Object 48 Arbitration Register Low
#define CAN_MOAR48L            (*((uword volatile far *) 0x201618))

// Message Object 49 Arbitration Register High
#define CAN_MOAR49H            (*((uword volatile far *) 0x20163A))

// Message Object 49 Arbitration Register Low
#define CAN_MOAR49L            (*((uword volatile far *) 0x201638))

// Message Object 4 Arbitration Register High
#define CAN_MOAR4H             (*((uword volatile far *) 0x20109A))

// Message Object 4 Arbitration Register Low
#define CAN_MOAR4L             (*((uword volatile far *) 0x201098))

// Message Object 50 Arbitration Register High
#define CAN_MOAR50H            (*((uword volatile far *) 0x20165A))

// Message Object 50 Arbitration Register Low
#define CAN_MOAR50L            (*((uword volatile far *) 0x201658))

// Message Object 51 Arbitration Register High
#define CAN_MOAR51H            (*((uword volatile far *) 0x20167A))

// Message Object 51 Arbitration Register Low
#define CAN_MOAR51L            (*((uword volatile far *) 0x201678))

// Message Object 52 Arbitration Register High
#define CAN_MOAR52H            (*((uword volatile far *) 0x20169A))

// Message Object 52 Arbitration Register Low
#define CAN_MOAR52L            (*((uword volatile far *) 0x201698))

// Message Object 53 Arbitration Register High
#define CAN_MOAR53H            (*((uword volatile far *) 0x2016BA))

// Message Object 53 Arbitration Register Low
#define CAN_MOAR53L            (*((uword volatile far *) 0x2016B8))

// Message Object 54 Arbitration Register High
#define CAN_MOAR54H            (*((uword volatile far *) 0x2016DA))

// Message Object 54 Arbitration Register Low
#define CAN_MOAR54L            (*((uword volatile far *) 0x2016D8))

// Message Object 55 Arbitration Register High
#define CAN_MOAR55H            (*((uword volatile far *) 0x2016FA))

// Message Object 55 Arbitration Register Low
#define CAN_MOAR55L            (*((uword volatile far *) 0x2016F8))

// Message Object 56 Arbitration Register High
#define CAN_MOAR56H            (*((uword volatile far *) 0x20171A))

// Message Object 56 Arbitration Register Low
#define CAN_MOAR56L            (*((uword volatile far *) 0x201718))

// Message Object 57 Arbitration Register High
#define CAN_MOAR57H            (*((uword volatile far *) 0x20173A))

// Message Object 57 Arbitration Register Low
#define CAN_MOAR57L            (*((uword volatile far *) 0x201738))

// Message Object 58 Arbitration Register High
#define CAN_MOAR58H            (*((uword volatile far *) 0x20175A))

// Message Object 58 Arbitration Register Low
#define CAN_MOAR58L            (*((uword volatile far *) 0x201758))

// Message Object 59 Arbitration Register High
#define CAN_MOAR59H            (*((uword volatile far *) 0x20177A))

// Message Object 59 Arbitration Register Low
#define CAN_MOAR59L            (*((uword volatile far *) 0x201778))

// Message Object 5 Arbitration Register High
#define CAN_MOAR5H             (*((uword volatile far *) 0x2010BA))

// Message Object 5 Arbitration Register Low
#define CAN_MOAR5L             (*((uword volatile far *) 0x2010B8))

// Message Object 60 Arbitration Register High
#define CAN_MOAR60H            (*((uword volatile far *) 0x20179A))

// Message Object 60 Arbitration Register Low
#define CAN_MOAR60L            (*((uword volatile far *) 0x201798))

// Message Object 61 Arbitration Register High
#define CAN_MOAR61H            (*((uword volatile far *) 0x2017BA))

// Message Object 61 Arbitration Register Low
#define CAN_MOAR61L            (*((uword volatile far *) 0x2017B8))

// Message Object 62 Arbitration Register High
#define CAN_MOAR62H            (*((uword volatile far *) 0x2017DA))

// Message Object 62 Arbitration Register Low
#define CAN_MOAR62L            (*((uword volatile far *) 0x2017D8))

// Message Object 63 Arbitration Register High
#define CAN_MOAR63H            (*((uword volatile far *) 0x2017FA))

// Message Object 63 Arbitration Register Low
#define CAN_MOAR63L            (*((uword volatile far *) 0x2017F8))

// Message Object 64 Arbitration Register High
#define CAN_MOAR64H            (*((uword volatile far *) 0x20181A))

// Message Object 64 Arbitration Register Low
#define CAN_MOAR64L            (*((uword volatile far *) 0x201818))

// Message Object 65 Arbitration Register High
#define CAN_MOAR65H            (*((uword volatile far *) 0x20183A))

// Message Object 65 Arbitration Register Low
#define CAN_MOAR65L            (*((uword volatile far *) 0x201838))

// Message Object 66 Arbitration Register High
#define CAN_MOAR66H            (*((uword volatile far *) 0x20185A))

// Message Object 66 Arbitration Register Low
#define CAN_MOAR66L            (*((uword volatile far *) 0x201858))

// Message Object 67 Arbitration Register High
#define CAN_MOAR67H            (*((uword volatile far *) 0x20187A))

// Message Object 67 Arbitration Register Low
#define CAN_MOAR67L            (*((uword volatile far *) 0x201878))

// Message Object 68 Arbitration Register High
#define CAN_MOAR68H            (*((uword volatile far *) 0x20189A))

// Message Object 68 Arbitration Register Low
#define CAN_MOAR68L            (*((uword volatile far *) 0x201898))

// Message Object 69 Arbitration Register High
#define CAN_MOAR69H            (*((uword volatile far *) 0x2018BA))

// Message Object 69 Arbitration Register Low
#define CAN_MOAR69L            (*((uword volatile far *) 0x2018B8))

// Message Object 6 Arbitration Register High
#define CAN_MOAR6H             (*((uword volatile far *) 0x2010DA))

// Message Object 6 Arbitration Register Low
#define CAN_MOAR6L             (*((uword volatile far *) 0x2010D8))

// Message Object 70 Arbitration Register High
#define CAN_MOAR70H            (*((uword volatile far *) 0x2018DA))

// Message Object 70 Arbitration Register Low
#define CAN_MOAR70L            (*((uword volatile far *) 0x2018D8))

// Message Object 71 Arbitration Register High
#define CAN_MOAR71H            (*((uword volatile far *) 0x2018FA))

// Message Object 71 Arbitration Register Low
#define CAN_MOAR71L            (*((uword volatile far *) 0x2018F8))

// Message Object 72 Arbitration Register High
#define CAN_MOAR72H            (*((uword volatile far *) 0x20191A))

// Message Object 72 Arbitration Register Low
#define CAN_MOAR72L            (*((uword volatile far *) 0x201918))

// Message Object 73 Arbitration Register High
#define CAN_MOAR73H            (*((uword volatile far *) 0x20193A))

// Message Object 73 Arbitration Register Low
#define CAN_MOAR73L            (*((uword volatile far *) 0x201938))

// Message Object 74 Arbitration Register High
#define CAN_MOAR74H            (*((uword volatile far *) 0x20195A))

// Message Object 74 Arbitration Register Low
#define CAN_MOAR74L            (*((uword volatile far *) 0x201958))

// Message Object 75 Arbitration Register High
#define CAN_MOAR75H            (*((uword volatile far *) 0x20197A))

// Message Object 75 Arbitration Register Low
#define CAN_MOAR75L            (*((uword volatile far *) 0x201978))

// Message Object 76 Arbitration Register High
#define CAN_MOAR76H            (*((uword volatile far *) 0x20199A))

// Message Object 76 Arbitration Register Low
#define CAN_MOAR76L            (*((uword volatile far *) 0x201998))

// Message Object 77 Arbitration Register High
#define CAN_MOAR77H            (*((uword volatile far *) 0x2019BA))

// Message Object 77 Arbitration Register Low
#define CAN_MOAR77L            (*((uword volatile far *) 0x2019B8))

// Message Object 78 Arbitration Register High
#define CAN_MOAR78H            (*((uword volatile far *) 0x2019DA))

// Message Object 78 Arbitration Register Low
#define CAN_MOAR78L            (*((uword volatile far *) 0x2019D8))

// Message Object 79 Arbitration Register High
#define CAN_MOAR79H            (*((uword volatile far *) 0x2019FA))

// Message Object 79 Arbitration Register Low
#define CAN_MOAR79L            (*((uword volatile far *) 0x2019F8))

// Message Object 7 Arbitration Register High
#define CAN_MOAR7H             (*((uword volatile far *) 0x2010FA))

// Message Object 7 Arbitration Register Low
#define CAN_MOAR7L             (*((uword volatile far *) 0x2010F8))

// Message Object 80 Arbitration Register High
#define CAN_MOAR80H            (*((uword volatile far *) 0x201A1A))

// Message Object 80 Arbitration Register Low
#define CAN_MOAR80L            (*((uword volatile far *) 0x201A18))

// Message Object 81 Arbitration Register High
#define CAN_MOAR81H            (*((uword volatile far *) 0x201A3A))

// Message Object 81 Arbitration Register Low
#define CAN_MOAR81L            (*((uword volatile far *) 0x201A38))

// Message Object 82 Arbitration Register High
#define CAN_MOAR82H            (*((uword volatile far *) 0x201A5A))

// Message Object 82 Arbitration Register Low
#define CAN_MOAR82L            (*((uword volatile far *) 0x201A58))

// Message Object 83 Arbitration Register High
#define CAN_MOAR83H            (*((uword volatile far *) 0x201A7A))

// Message Object 83 Arbitration Register Low
#define CAN_MOAR83L            (*((uword volatile far *) 0x201A78))

// Message Object 84 Arbitration Register High
#define CAN_MOAR84H            (*((uword volatile far *) 0x201A9A))

// Message Object 84 Arbitration Register Low
#define CAN_MOAR84L            (*((uword volatile far *) 0x201A98))

// Message Object 85 Arbitration Register High
#define CAN_MOAR85H            (*((uword volatile far *) 0x201ABA))

// Message Object 85 Arbitration Register Low
#define CAN_MOAR85L            (*((uword volatile far *) 0x201AB8))

// Message Object 86 Arbitration Register High
#define CAN_MOAR86H            (*((uword volatile far *) 0x201ADA))

// Message Object 86 Arbitration Register Low
#define CAN_MOAR86L            (*((uword volatile far *) 0x201AD8))

// Message Object 87 Arbitration Register High
#define CAN_MOAR87H            (*((uword volatile far *) 0x201AFA))

// Message Object 87 Arbitration Register Low
#define CAN_MOAR87L            (*((uword volatile far *) 0x201AF8))

// Message Object 88 Arbitration Register High
#define CAN_MOAR88H            (*((uword volatile far *) 0x201B1A))

// Message Object 88 Arbitration Register Low
#define CAN_MOAR88L            (*((uword volatile far *) 0x201B18))

// Message Object 89 Arbitration Register High
#define CAN_MOAR89H            (*((uword volatile far *) 0x201B3A))

// Message Object 89 Arbitration Register Low
#define CAN_MOAR89L            (*((uword volatile far *) 0x201B38))

// Message Object 8 Arbitration Register High
#define CAN_MOAR8H             (*((uword volatile far *) 0x20111A))

// Message Object 8 Arbitration Register Low
#define CAN_MOAR8L             (*((uword volatile far *) 0x201118))

// Message Object 90 Arbitration Register High
#define CAN_MOAR90H            (*((uword volatile far *) 0x201B5A))

// Message Object 90 Arbitration Register Low
#define CAN_MOAR90L            (*((uword volatile far *) 0x201B58))

// Message Object 91 Arbitration Register High
#define CAN_MOAR91H            (*((uword volatile far *) 0x201B7A))

// Message Object 91 Arbitration Register Low
#define CAN_MOAR91L            (*((uword volatile far *) 0x201B78))

// Message Object 92 Arbitration Register High
#define CAN_MOAR92H            (*((uword volatile far *) 0x201B9A))

// Message Object 92 Arbitration Register Low
#define CAN_MOAR92L            (*((uword volatile far *) 0x201B98))

// Message Object 93 Arbitration Register High
#define CAN_MOAR93H            (*((uword volatile far *) 0x201BBA))

// Message Object 93 Arbitration Register Low
#define CAN_MOAR93L            (*((uword volatile far *) 0x201BB8))

// Message Object 94 Arbitration Register High
#define CAN_MOAR94H            (*((uword volatile far *) 0x201BDA))

// Message Object 94 Arbitration Register Low
#define CAN_MOAR94L            (*((uword volatile far *) 0x201BD8))

// Message Object 95 Arbitration Register High
#define CAN_MOAR95H            (*((uword volatile far *) 0x201BFA))

// Message Object 95 Arbitration Register Low
#define CAN_MOAR95L            (*((uword volatile far *) 0x201BF8))

// Message Object 96 Arbitration Register High
#define CAN_MOAR96H            (*((uword volatile far *) 0x201C1A))

// Message Object 96 Arbitration Register Low
#define CAN_MOAR96L            (*((uword volatile far *) 0x201C18))

// Message Object 97 Arbitration Register High
#define CAN_MOAR97H            (*((uword volatile far *) 0x201C3A))

// Message Object 97 Arbitration Register Low
#define CAN_MOAR97L            (*((uword volatile far *) 0x201C38))

// Message Object 98 Arbitration Register High
#define CAN_MOAR98H            (*((uword volatile far *) 0x201C5A))

// Message Object 98 Arbitration Register Low
#define CAN_MOAR98L            (*((uword volatile far *) 0x201C58))

// Message Object 99 Arbitration Register High
#define CAN_MOAR99H            (*((uword volatile far *) 0x201C7A))

// Message Object 99 Arbitration Register Low
#define CAN_MOAR99L            (*((uword volatile far *) 0x201C78))

// Message Object 9 Arbitration Register High
#define CAN_MOAR9H             (*((uword volatile far *) 0x20113A))

// Message Object 9 Arbitration Register Low
#define CAN_MOAR9L             (*((uword volatile far *) 0x201138))

// Message Object 0 Control Register High
#define CAN_MOCTR0H            (*((uword volatile far *) 0x20101E))

// Message Object 0 Control Register Low
#define CAN_MOCTR0L            (*((uword volatile far *) 0x20101C))

// Message Object 100 Control Register High
#define CAN_MOCTR100H          (*((uword volatile far *) 0x201C9E))

// Message Object 100 Control Register Low
#define CAN_MOCTR100L          (*((uword volatile far *) 0x201C9C))

// Message Object 101 Control Register High
#define CAN_MOCTR101H          (*((uword volatile far *) 0x201CBE))

// Message Object 101 Control Register Low
#define CAN_MOCTR101L          (*((uword volatile far *) 0x201CBC))

// Message Object 102 Control Register High
#define CAN_MOCTR102H          (*((uword volatile far *) 0x201CDE))

// Message Object 102 Control Register Low
#define CAN_MOCTR102L          (*((uword volatile far *) 0x201CDC))

// Message Object 103 Control Register High
#define CAN_MOCTR103H          (*((uword volatile far *) 0x201CFE))

// Message Object 103 Control Register Low
#define CAN_MOCTR103L          (*((uword volatile far *) 0x201CFC))

// Message Object 104 Control Register High
#define CAN_MOCTR104H          (*((uword volatile far *) 0x201D1E))

// Message Object 104 Control Register Low
#define CAN_MOCTR104L          (*((uword volatile far *) 0x201D1C))

// Message Object 105 Control Register High
#define CAN_MOCTR105H          (*((uword volatile far *) 0x201D3E))

// Message Object 105 Control Register Low
#define CAN_MOCTR105L          (*((uword volatile far *) 0x201D3C))

// Message Object 106 Control Register High
#define CAN_MOCTR106H          (*((uword volatile far *) 0x201D5E))

// Message Object 106 Control Register Low
#define CAN_MOCTR106L          (*((uword volatile far *) 0x201D5C))

// Message Object 107 Control Register High
#define CAN_MOCTR107H          (*((uword volatile far *) 0x201D7E))

// Message Object 107 Control Register Low
#define CAN_MOCTR107L          (*((uword volatile far *) 0x201D7C))

// Message Object 108 Control Register High
#define CAN_MOCTR108H          (*((uword volatile far *) 0x201D9E))

// Message Object 108 Control Register Low
#define CAN_MOCTR108L          (*((uword volatile far *) 0x201D9C))

// Message Object 109 Control Register High
#define CAN_MOCTR109H          (*((uword volatile far *) 0x201DBE))

// Message Object 109 Control Register Low
#define CAN_MOCTR109L          (*((uword volatile far *) 0x201DBC))

// Message Object 10 Control Register High
#define CAN_MOCTR10H           (*((uword volatile far *) 0x20115E))

// Message Object 10 Control Register Low
#define CAN_MOCTR10L           (*((uword volatile far *) 0x20115C))

// Message Object 110 Control Register High
#define CAN_MOCTR110H          (*((uword volatile far *) 0x201DDE))

// Message Object 110 Control Register Low
#define CAN_MOCTR110L          (*((uword volatile far *) 0x201DDC))

// Message Object 111 Control Register High
#define CAN_MOCTR111H          (*((uword volatile far *) 0x201DFE))

// Message Object 111 Control Register Low
#define CAN_MOCTR111L          (*((uword volatile far *) 0x201DFC))

// Message Object 112 Control Register High
#define CAN_MOCTR112H          (*((uword volatile far *) 0x201E1E))

// Message Object 112 Control Register Low
#define CAN_MOCTR112L          (*((uword volatile far *) 0x201E1C))

// Message Object 113 Control Register High
#define CAN_MOCTR113H          (*((uword volatile far *) 0x201E3E))

// Message Object 113 Control Register Low
#define CAN_MOCTR113L          (*((uword volatile far *) 0x201E3C))

// Message Object 114 Control Register High
#define CAN_MOCTR114H          (*((uword volatile far *) 0x201E5E))

// Message Object 114 Control Register Low
#define CAN_MOCTR114L          (*((uword volatile far *) 0x201E5C))

// Message Object 115 Control Register High
#define CAN_MOCTR115H          (*((uword volatile far *) 0x201E7E))

// Message Object 115 Control Register Low
#define CAN_MOCTR115L          (*((uword volatile far *) 0x201E7C))

// Message Object 116 Control Register High
#define CAN_MOCTR116H          (*((uword volatile far *) 0x201E9E))

// Message Object 116 Control Register Low
#define CAN_MOCTR116L          (*((uword volatile far *) 0x201E9C))

// Message Object 117 Control Register High
#define CAN_MOCTR117H          (*((uword volatile far *) 0x201EBE))

// Message Object 117 Control Register Low
#define CAN_MOCTR117L          (*((uword volatile far *) 0x201EBC))

// Message Object 118 Control Register High
#define CAN_MOCTR118H          (*((uword volatile far *) 0x201EDE))

// Message Object 118 Control Register Low
#define CAN_MOCTR118L          (*((uword volatile far *) 0x201EDC))

// Message Object 119 Control Register High
#define CAN_MOCTR119H          (*((uword volatile far *) 0x201EFE))

// Message Object 119 Control Register Low
#define CAN_MOCTR119L          (*((uword volatile far *) 0x201EFC))

// Message Object 11 Control Register High
#define CAN_MOCTR11H           (*((uword volatile far *) 0x20117E))

// Message Object 11 Control Register Low
#define CAN_MOCTR11L           (*((uword volatile far *) 0x20117C))

// Message Object 120 Control Register High
#define CAN_MOCTR120H          (*((uword volatile far *) 0x201F1E))

// Message Object 120 Control Register Low
#define CAN_MOCTR120L          (*((uword volatile far *) 0x201F1C))

// Message Object 121 Control Register High
#define CAN_MOCTR121H          (*((uword volatile far *) 0x201F3E))

// Message Object 121 Control Register Low
#define CAN_MOCTR121L          (*((uword volatile far *) 0x201F3C))

// Message Object 122 Control Register High
#define CAN_MOCTR122H          (*((uword volatile far *) 0x201F5E))

// Message Object 122 Control Register Low
#define CAN_MOCTR122L          (*((uword volatile far *) 0x201F5C))

// Message Object 123 Control Register High
#define CAN_MOCTR123H          (*((uword volatile far *) 0x201F7E))

// Message Object 123 Control Register Low
#define CAN_MOCTR123L          (*((uword volatile far *) 0x201F7C))

// Message Object 124 Control Register High
#define CAN_MOCTR124H          (*((uword volatile far *) 0x201F9E))

// Message Object 124 Control Register Low
#define CAN_MOCTR124L          (*((uword volatile far *) 0x201F9C))

// Message Object 125 Control Register High
#define CAN_MOCTR125H          (*((uword volatile far *) 0x201FBE))

// Message Object 125 Control Register Low
#define CAN_MOCTR125L          (*((uword volatile far *) 0x201FBC))

// Message Object 126 Control Register High
#define CAN_MOCTR126H          (*((uword volatile far *) 0x201FDE))

// Message Object 126 Control Register Low
#define CAN_MOCTR126L          (*((uword volatile far *) 0x201FDC))

// Message Object 127 Control Register High
#define CAN_MOCTR127H          (*((uword volatile far *) 0x201FFE))

// Message Object 127 Control Register Low
#define CAN_MOCTR127L          (*((uword volatile far *) 0x201FFC))

// Message Object 128 Control Register High
#define CAN_MOCTR128H          (*((uword volatile far *) 0x20201E))

// Message Object 128 Control Register Low
#define CAN_MOCTR128L          (*((uword volatile far *) 0x20201C))

// Message Object 129 Control Register High
#define CAN_MOCTR129H          (*((uword volatile far *) 0x20203E))

// Message Object 129 Control Register Low
#define CAN_MOCTR129L          (*((uword volatile far *) 0x20203C))

// Message Object 12 Control Register High
#define CAN_MOCTR12H           (*((uword volatile far *) 0x20119E))

// Message Object 12 Control Register Low
#define CAN_MOCTR12L           (*((uword volatile far *) 0x20119C))

// Message Object 130 Control Register High
#define CAN_MOCTR130H          (*((uword volatile far *) 0x20205E))

// Message Object 130 Control Register Low
#define CAN_MOCTR130L          (*((uword volatile far *) 0x20205C))

// Message Object 131 Control Register High
#define CAN_MOCTR131H          (*((uword volatile far *) 0x20207E))

// Message Object 131 Control Register Low
#define CAN_MOCTR131L          (*((uword volatile far *) 0x20207C))

// Message Object 132 Control Register High
#define CAN_MOCTR132H          (*((uword volatile far *) 0x20209E))

// Message Object 132 Control Register Low
#define CAN_MOCTR132L          (*((uword volatile far *) 0x20209C))

// Message Object 133 Control Register High
#define CAN_MOCTR133H          (*((uword volatile far *) 0x2020BE))

// Message Object 133 Control Register Low
#define CAN_MOCTR133L          (*((uword volatile far *) 0x2020BC))

// Message Object 134 Control Register High
#define CAN_MOCTR134H          (*((uword volatile far *) 0x2020DE))

// Message Object 134 Control Register Low
#define CAN_MOCTR134L          (*((uword volatile far *) 0x2020DC))

// Message Object 135 Control Register High
#define CAN_MOCTR135H          (*((uword volatile far *) 0x2020FE))

// Message Object 135 Control Register Low
#define CAN_MOCTR135L          (*((uword volatile far *) 0x2020FC))

// Message Object 136 Control Register High
#define CAN_MOCTR136H          (*((uword volatile far *) 0x20211E))

// Message Object 136 Control Register Low
#define CAN_MOCTR136L          (*((uword volatile far *) 0x20211C))

// Message Object 137 Control Register High
#define CAN_MOCTR137H          (*((uword volatile far *) 0x20213E))

// Message Object 137 Control Register Low
#define CAN_MOCTR137L          (*((uword volatile far *) 0x20213C))

// Message Object 138 Control Register High
#define CAN_MOCTR138H          (*((uword volatile far *) 0x20215E))

// Message Object 138 Control Register Low
#define CAN_MOCTR138L          (*((uword volatile far *) 0x20215C))

// Message Object 139 Control Register High
#define CAN_MOCTR139H          (*((uword volatile far *) 0x20217E))

// Message Object 139 Control Register Low
#define CAN_MOCTR139L          (*((uword volatile far *) 0x20217C))

// Message Object 13 Control Register High
#define CAN_MOCTR13H           (*((uword volatile far *) 0x2011BE))

// Message Object 13 Control Register Low
#define CAN_MOCTR13L           (*((uword volatile far *) 0x2011BC))

// Message Object 140 Control Register High
#define CAN_MOCTR140H          (*((uword volatile far *) 0x20219E))

// Message Object 140 Control Register Low
#define CAN_MOCTR140L          (*((uword volatile far *) 0x20219C))

// Message Object 141 Control Register High
#define CAN_MOCTR141H          (*((uword volatile far *) 0x2021BE))

// Message Object 141 Control Register Low
#define CAN_MOCTR141L          (*((uword volatile far *) 0x2021BC))

// Message Object 142 Control Register High
#define CAN_MOCTR142H          (*((uword volatile far *) 0x2021DE))

// Message Object 142 Control Register Low
#define CAN_MOCTR142L          (*((uword volatile far *) 0x2021DC))

// Message Object 143 Control Register High
#define CAN_MOCTR143H          (*((uword volatile far *) 0x2021FE))

// Message Object 143 Control Register Low
#define CAN_MOCTR143L          (*((uword volatile far *) 0x2021FC))

// Message Object 144 Control Register High
#define CAN_MOCTR144H          (*((uword volatile far *) 0x20221E))

// Message Object 144 Control Register Low
#define CAN_MOCTR144L          (*((uword volatile far *) 0x20221C))

// Message Object 145 Control Register High
#define CAN_MOCTR145H          (*((uword volatile far *) 0x20223E))

// Message Object 145 Control Register Low
#define CAN_MOCTR145L          (*((uword volatile far *) 0x20223C))

// Message Object 146 Control Register High
#define CAN_MOCTR146H          (*((uword volatile far *) 0x20225E))

// Message Object 146 Control Register Low
#define CAN_MOCTR146L          (*((uword volatile far *) 0x20225C))

// Message Object 147 Control Register High
#define CAN_MOCTR147H          (*((uword volatile far *) 0x20227E))

// Message Object 147 Control Register Low
#define CAN_MOCTR147L          (*((uword volatile far *) 0x20227C))

// Message Object 148 Control Register High
#define CAN_MOCTR148H          (*((uword volatile far *) 0x20229E))

// Message Object 148 Control Register Low
#define CAN_MOCTR148L          (*((uword volatile far *) 0x20229C))

// Message Object 149 Control Register High
#define CAN_MOCTR149H          (*((uword volatile far *) 0x2022BE))

// Message Object 149 Control Register Low
#define CAN_MOCTR149L          (*((uword volatile far *) 0x2022BC))

// Message Object 14 Control Register High
#define CAN_MOCTR14H           (*((uword volatile far *) 0x2011DE))

// Message Object 14 Control Register Low
#define CAN_MOCTR14L           (*((uword volatile far *) 0x2011DC))

// Message Object 150 Control Register High
#define CAN_MOCTR150H          (*((uword volatile far *) 0x2022DE))

// Message Object 150 Control Register Low
#define CAN_MOCTR150L          (*((uword volatile far *) 0x2022DC))

// Message Object 151 Control Register High
#define CAN_MOCTR151H          (*((uword volatile far *) 0x2022FE))

// Message Object 151 Control Register Low
#define CAN_MOCTR151L          (*((uword volatile far *) 0x2022FC))

// Message Object 152 Control Register High
#define CAN_MOCTR152H          (*((uword volatile far *) 0x20231E))

// Message Object 152 Control Register Low
#define CAN_MOCTR152L          (*((uword volatile far *) 0x20231C))

// Message Object 153 Control Register High
#define CAN_MOCTR153H          (*((uword volatile far *) 0x20233E))

// Message Object 153 Control Register Low
#define CAN_MOCTR153L          (*((uword volatile far *) 0x20233C))

// Message Object 154 Control Register High
#define CAN_MOCTR154H          (*((uword volatile far *) 0x20235E))

// Message Object 154 Control Register Low
#define CAN_MOCTR154L          (*((uword volatile far *) 0x20235C))

// Message Object 155 Control Register High
#define CAN_MOCTR155H          (*((uword volatile far *) 0x20237E))

// Message Object 155 Control Register Low
#define CAN_MOCTR155L          (*((uword volatile far *) 0x20237C))

// Message Object 156 Control Register High
#define CAN_MOCTR156H          (*((uword volatile far *) 0x20239E))

// Message Object 156 Control Register Low
#define CAN_MOCTR156L          (*((uword volatile far *) 0x20239C))

// Message Object 157 Control Register High
#define CAN_MOCTR157H          (*((uword volatile far *) 0x2023BE))

// Message Object 157 Control Register Low
#define CAN_MOCTR157L          (*((uword volatile far *) 0x2023BC))

// Message Object 158 Control Register High
#define CAN_MOCTR158H          (*((uword volatile far *) 0x2023DE))

// Message Object 158 Control Register Low
#define CAN_MOCTR158L          (*((uword volatile far *) 0x2023DC))

// Message Object 159 Control Register High
#define CAN_MOCTR159H          (*((uword volatile far *) 0x2023FE))

// Message Object 159 Control Register Low
#define CAN_MOCTR159L          (*((uword volatile far *) 0x2023FC))

// Message Object 15 Control Register High
#define CAN_MOCTR15H           (*((uword volatile far *) 0x2011FE))

// Message Object 15 Control Register Low
#define CAN_MOCTR15L           (*((uword volatile far *) 0x2011FC))

// Message Object 160 Control Register High
#define CAN_MOCTR160H          (*((uword volatile far *) 0x20241E))

// Message Object 160 Control Register Low
#define CAN_MOCTR160L          (*((uword volatile far *) 0x20241C))

// Message Object 161 Control Register High
#define CAN_MOCTR161H          (*((uword volatile far *) 0x20243E))

// Message Object 161 Control Register Low
#define CAN_MOCTR161L          (*((uword volatile far *) 0x20243C))

// Message Object 162 Control Register High
#define CAN_MOCTR162H          (*((uword volatile far *) 0x20245E))

// Message Object 162 Control Register Low
#define CAN_MOCTR162L          (*((uword volatile far *) 0x20245C))

// Message Object 163 Control Register High
#define CAN_MOCTR163H          (*((uword volatile far *) 0x20247E))

// Message Object 163 Control Register Low
#define CAN_MOCTR163L          (*((uword volatile far *) 0x20247C))

// Message Object 164 Control Register High
#define CAN_MOCTR164H          (*((uword volatile far *) 0x20249E))

// Message Object 164 Control Register Low
#define CAN_MOCTR164L          (*((uword volatile far *) 0x20249C))

// Message Object 165 Control Register High
#define CAN_MOCTR165H          (*((uword volatile far *) 0x2024BE))

// Message Object 165 Control Register Low
#define CAN_MOCTR165L          (*((uword volatile far *) 0x2024BC))

// Message Object 166 Control Register High
#define CAN_MOCTR166H          (*((uword volatile far *) 0x2024DE))

// Message Object 166 Control Register Low
#define CAN_MOCTR166L          (*((uword volatile far *) 0x2024DC))

// Message Object 167 Control Register High
#define CAN_MOCTR167H          (*((uword volatile far *) 0x2024FE))

// Message Object 167 Control Register Low
#define CAN_MOCTR167L          (*((uword volatile far *) 0x2024FC))

// Message Object 168 Control Register High
#define CAN_MOCTR168H          (*((uword volatile far *) 0x20251E))

// Message Object 168 Control Register Low
#define CAN_MOCTR168L          (*((uword volatile far *) 0x20251C))

// Message Object 169 Control Register High
#define CAN_MOCTR169H          (*((uword volatile far *) 0x20253E))

// Message Object 169 Control Register Low
#define CAN_MOCTR169L          (*((uword volatile far *) 0x20253C))

// Message Object 16 Control Register High
#define CAN_MOCTR16H           (*((uword volatile far *) 0x20121E))

// Message Object 16 Control Register Low
#define CAN_MOCTR16L           (*((uword volatile far *) 0x20121C))

// Message Object 170 Control Register High
#define CAN_MOCTR170H          (*((uword volatile far *) 0x20255E))

// Message Object 170 Control Register Low
#define CAN_MOCTR170L          (*((uword volatile far *) 0x20255C))

// Message Object 171 Control Register High
#define CAN_MOCTR171H          (*((uword volatile far *) 0x20257E))

// Message Object 171 Control Register Low
#define CAN_MOCTR171L          (*((uword volatile far *) 0x20257C))

// Message Object 172 Control Register High
#define CAN_MOCTR172H          (*((uword volatile far *) 0x20259E))

// Message Object 172 Control Register Low
#define CAN_MOCTR172L          (*((uword volatile far *) 0x20259C))

// Message Object 173 Control Register High
#define CAN_MOCTR173H          (*((uword volatile far *) 0x2025BE))

// Message Object 173 Control Register Low
#define CAN_MOCTR173L          (*((uword volatile far *) 0x2025BC))

// Message Object 174 Control Register High
#define CAN_MOCTR174H          (*((uword volatile far *) 0x2025DE))

// Message Object 174 Control Register Low
#define CAN_MOCTR174L          (*((uword volatile far *) 0x2025DC))

// Message Object 175 Control Register High
#define CAN_MOCTR175H          (*((uword volatile far *) 0x2025FE))

// Message Object 175 Control Register Low
#define CAN_MOCTR175L          (*((uword volatile far *) 0x2025FC))

// Message Object 176 Control Register High
#define CAN_MOCTR176H          (*((uword volatile far *) 0x20261E))

// Message Object 176 Control Register Low
#define CAN_MOCTR176L          (*((uword volatile far *) 0x20261C))

// Message Object 177 Control Register High
#define CAN_MOCTR177H          (*((uword volatile far *) 0x20263E))

// Message Object 177 Control Register Low
#define CAN_MOCTR177L          (*((uword volatile far *) 0x20263C))

// Message Object 178 Control Register High
#define CAN_MOCTR178H          (*((uword volatile far *) 0x20265E))

// Message Object 178 Control Register Low
#define CAN_MOCTR178L          (*((uword volatile far *) 0x20265C))

// Message Object 179 Control Register High
#define CAN_MOCTR179H          (*((uword volatile far *) 0x20267E))

// Message Object 179 Control Register Low
#define CAN_MOCTR179L          (*((uword volatile far *) 0x20267C))

// Message Object 17 Control Register High
#define CAN_MOCTR17H           (*((uword volatile far *) 0x20123E))

// Message Object 17 Control Register Low
#define CAN_MOCTR17L           (*((uword volatile far *) 0x20123C))

// Message Object 180 Control Register High
#define CAN_MOCTR180H          (*((uword volatile far *) 0x20269E))

// Message Object 180 Control Register Low
#define CAN_MOCTR180L          (*((uword volatile far *) 0x20269C))

// Message Object 181 Control Register High
#define CAN_MOCTR181H          (*((uword volatile far *) 0x2026BE))

// Message Object 181 Control Register Low
#define CAN_MOCTR181L          (*((uword volatile far *) 0x2026BC))

// Message Object 182 Control Register High
#define CAN_MOCTR182H          (*((uword volatile far *) 0x2026DE))

// Message Object 182 Control Register Low
#define CAN_MOCTR182L          (*((uword volatile far *) 0x2026DC))

// Message Object 183 Control Register High
#define CAN_MOCTR183H          (*((uword volatile far *) 0x2026FE))

// Message Object 183 Control Register Low
#define CAN_MOCTR183L          (*((uword volatile far *) 0x2026FC))

// Message Object 184 Control Register High
#define CAN_MOCTR184H          (*((uword volatile far *) 0x20271E))

// Message Object 184 Control Register Low
#define CAN_MOCTR184L          (*((uword volatile far *) 0x20271C))

// Message Object 185 Control Register High
#define CAN_MOCTR185H          (*((uword volatile far *) 0x20273E))

// Message Object 185 Control Register Low
#define CAN_MOCTR185L          (*((uword volatile far *) 0x20273C))

// Message Object 186 Control Register High
#define CAN_MOCTR186H          (*((uword volatile far *) 0x20275E))

// Message Object 186 Control Register Low
#define CAN_MOCTR186L          (*((uword volatile far *) 0x20275C))

// Message Object 187 Control Register High
#define CAN_MOCTR187H          (*((uword volatile far *) 0x20277E))

// Message Object 187 Control Register Low
#define CAN_MOCTR187L          (*((uword volatile far *) 0x20277C))

// Message Object 188 Control Register High
#define CAN_MOCTR188H          (*((uword volatile far *) 0x20279E))

// Message Object 188 Control Register Low
#define CAN_MOCTR188L          (*((uword volatile far *) 0x20279C))

// Message Object 189 Control Register High
#define CAN_MOCTR189H          (*((uword volatile far *) 0x2027BE))

// Message Object 189 Control Register Low
#define CAN_MOCTR189L          (*((uword volatile far *) 0x2027BC))

// Message Object 18 Control Register High
#define CAN_MOCTR18H           (*((uword volatile far *) 0x20125E))

// Message Object 18 Control Register Low
#define CAN_MOCTR18L           (*((uword volatile far *) 0x20125C))

// Message Object 190 Control Register High
#define CAN_MOCTR190H          (*((uword volatile far *) 0x2027DE))

// Message Object 190 Control Register Low
#define CAN_MOCTR190L          (*((uword volatile far *) 0x2027DC))

// Message Object 191 Control Register High
#define CAN_MOCTR191H          (*((uword volatile far *) 0x2027FE))

// Message Object 191 Control Register Low
#define CAN_MOCTR191L          (*((uword volatile far *) 0x2027FC))

// Message Object 192 Control Register High
#define CAN_MOCTR192H          (*((uword volatile far *) 0x20281E))

// Message Object 192 Control Register Low
#define CAN_MOCTR192L          (*((uword volatile far *) 0x20281C))

// Message Object 193 Control Register High
#define CAN_MOCTR193H          (*((uword volatile far *) 0x20283E))

// Message Object 193 Control Register Low
#define CAN_MOCTR193L          (*((uword volatile far *) 0x20283C))

// Message Object 194 Control Register High
#define CAN_MOCTR194H          (*((uword volatile far *) 0x20285E))

// Message Object 194 Control Register Low
#define CAN_MOCTR194L          (*((uword volatile far *) 0x20285C))

// Message Object 195 Control Register High
#define CAN_MOCTR195H          (*((uword volatile far *) 0x20287E))

// Message Object 195 Control Register Low
#define CAN_MOCTR195L          (*((uword volatile far *) 0x20287C))

// Message Object 196 Control Register High
#define CAN_MOCTR196H          (*((uword volatile far *) 0x20289E))

// Message Object 196 Control Register Low
#define CAN_MOCTR196L          (*((uword volatile far *) 0x20289C))

// Message Object 197 Control Register High
#define CAN_MOCTR197H          (*((uword volatile far *) 0x2028BE))

// Message Object 197 Control Register Low
#define CAN_MOCTR197L          (*((uword volatile far *) 0x2028BC))

// Message Object 198 Control Register High
#define CAN_MOCTR198H          (*((uword volatile far *) 0x2028DE))

// Message Object 198 Control Register Low
#define CAN_MOCTR198L          (*((uword volatile far *) 0x2028DC))

// Message Object 199 Control Register High
#define CAN_MOCTR199H          (*((uword volatile far *) 0x2028FE))

// Message Object 199 Control Register Low
#define CAN_MOCTR199L          (*((uword volatile far *) 0x2028FC))

// Message Object 19 Control Register High
#define CAN_MOCTR19H           (*((uword volatile far *) 0x20127E))

// Message Object 19 Control Register Low
#define CAN_MOCTR19L           (*((uword volatile far *) 0x20127C))

// Message Object 1 Control Register High
#define CAN_MOCTR1H            (*((uword volatile far *) 0x20103E))

// Message Object 1 Control Register Low
#define CAN_MOCTR1L            (*((uword volatile far *) 0x20103C))

// Message Object 200 Control Register High
#define CAN_MOCTR200H          (*((uword volatile far *) 0x20291E))

// Message Object 200 Control Register Low
#define CAN_MOCTR200L          (*((uword volatile far *) 0x20291C))

// Message Object 201 Control Register High
#define CAN_MOCTR201H          (*((uword volatile far *) 0x20293E))

// Message Object 201 Control Register Low
#define CAN_MOCTR201L          (*((uword volatile far *) 0x20293C))

// Message Object 202 Control Register High
#define CAN_MOCTR202H          (*((uword volatile far *) 0x20295E))

// Message Object 202 Control Register Low
#define CAN_MOCTR202L          (*((uword volatile far *) 0x20295C))

// Message Object 203 Control Register High
#define CAN_MOCTR203H          (*((uword volatile far *) 0x20297E))

// Message Object 203 Control Register Low
#define CAN_MOCTR203L          (*((uword volatile far *) 0x20297C))

// Message Object 204 Control Register High
#define CAN_MOCTR204H          (*((uword volatile far *) 0x20299E))

// Message Object 204 Control Register Low
#define CAN_MOCTR204L          (*((uword volatile far *) 0x20299C))

// Message Object 205 Control Register High
#define CAN_MOCTR205H          (*((uword volatile far *) 0x2029BE))

// Message Object 205 Control Register Low
#define CAN_MOCTR205L          (*((uword volatile far *) 0x2029BC))

// Message Object 206 Control Register High
#define CAN_MOCTR206H          (*((uword volatile far *) 0x2029DE))

// Message Object 206 Control Register Low
#define CAN_MOCTR206L          (*((uword volatile far *) 0x2029DC))

// Message Object 207 Control Register High
#define CAN_MOCTR207H          (*((uword volatile far *) 0x2029FE))

// Message Object 207 Control Register Low
#define CAN_MOCTR207L          (*((uword volatile far *) 0x2029FC))

// Message Object 208 Control Register High
#define CAN_MOCTR208H          (*((uword volatile far *) 0x202A1E))

// Message Object 208 Control Register Low
#define CAN_MOCTR208L          (*((uword volatile far *) 0x202A1C))

// Message Object 209 Control Register High
#define CAN_MOCTR209H          (*((uword volatile far *) 0x202A3E))

// Message Object 209 Control Register Low
#define CAN_MOCTR209L          (*((uword volatile far *) 0x202A3C))

// Message Object 20 Control Register High
#define CAN_MOCTR20H           (*((uword volatile far *) 0x20129E))

// Message Object 20 Control Register Low
#define CAN_MOCTR20L           (*((uword volatile far *) 0x20129C))

// Message Object 210 Control Register High
#define CAN_MOCTR210H          (*((uword volatile far *) 0x202A5E))

// Message Object 210 Control Register Low
#define CAN_MOCTR210L          (*((uword volatile far *) 0x202A5C))

// Message Object 211 Control Register High
#define CAN_MOCTR211H          (*((uword volatile far *) 0x202A7E))

// Message Object 211 Control Register Low
#define CAN_MOCTR211L          (*((uword volatile far *) 0x202A7C))

// Message Object 212 Control Register High
#define CAN_MOCTR212H          (*((uword volatile far *) 0x202A9E))

// Message Object 212 Control Register Low
#define CAN_MOCTR212L          (*((uword volatile far *) 0x202A9C))

// Message Object 213 Control Register High
#define CAN_MOCTR213H          (*((uword volatile far *) 0x202ABE))

// Message Object 213 Control Register Low
#define CAN_MOCTR213L          (*((uword volatile far *) 0x202ABC))

// Message Object 214 Control Register High
#define CAN_MOCTR214H          (*((uword volatile far *) 0x202ADE))

// Message Object 214 Control Register Low
#define CAN_MOCTR214L          (*((uword volatile far *) 0x202ADC))

// Message Object 215 Control Register High
#define CAN_MOCTR215H          (*((uword volatile far *) 0x202AFE))

// Message Object 215 Control Register Low
#define CAN_MOCTR215L          (*((uword volatile far *) 0x202AFC))

// Message Object 216 Control Register High
#define CAN_MOCTR216H          (*((uword volatile far *) 0x202B1E))

// Message Object 216 Control Register Low
#define CAN_MOCTR216L          (*((uword volatile far *) 0x202B1C))

// Message Object 217 Control Register High
#define CAN_MOCTR217H          (*((uword volatile far *) 0x202B3E))

// Message Object 217 Control Register Low
#define CAN_MOCTR217L          (*((uword volatile far *) 0x202B3C))

// Message Object 218 Control Register High
#define CAN_MOCTR218H          (*((uword volatile far *) 0x202B5E))

// Message Object 218 Control Register Low
#define CAN_MOCTR218L          (*((uword volatile far *) 0x202B5C))

// Message Object 219 Control Register High
#define CAN_MOCTR219H          (*((uword volatile far *) 0x202B7E))

// Message Object 219 Control Register Low
#define CAN_MOCTR219L          (*((uword volatile far *) 0x202B7C))

// Message Object 21 Control Register High
#define CAN_MOCTR21H           (*((uword volatile far *) 0x2012BE))

// Message Object 21 Control Register Low
#define CAN_MOCTR21L           (*((uword volatile far *) 0x2012BC))

// Message Object 220 Control Register High
#define CAN_MOCTR220H          (*((uword volatile far *) 0x202B9E))

// Message Object 220 Control Register Low
#define CAN_MOCTR220L          (*((uword volatile far *) 0x202B9C))

// Message Object 221 Control Register High
#define CAN_MOCTR221H          (*((uword volatile far *) 0x202BBE))

// Message Object 221 Control Register Low
#define CAN_MOCTR221L          (*((uword volatile far *) 0x202BBC))

// Message Object 222 Control Register High
#define CAN_MOCTR222H          (*((uword volatile far *) 0x202BDE))

// Message Object 222 Control Register Low
#define CAN_MOCTR222L          (*((uword volatile far *) 0x202BDC))

// Message Object 223 Control Register High
#define CAN_MOCTR223H          (*((uword volatile far *) 0x202BFE))

// Message Object 223 Control Register Low
#define CAN_MOCTR223L          (*((uword volatile far *) 0x202BFC))

// Message Object 224 Control Register High
#define CAN_MOCTR224H          (*((uword volatile far *) 0x202C1E))

// Message Object 224 Control Register Low
#define CAN_MOCTR224L          (*((uword volatile far *) 0x202C1C))

// Message Object 225 Control Register High
#define CAN_MOCTR225H          (*((uword volatile far *) 0x202C3E))

// Message Object 225 Control Register Low
#define CAN_MOCTR225L          (*((uword volatile far *) 0x202C3C))

// Message Object 226 Control Register High
#define CAN_MOCTR226H          (*((uword volatile far *) 0x202C5E))

// Message Object 226 Control Register Low
#define CAN_MOCTR226L          (*((uword volatile far *) 0x202C5C))

// Message Object 227 Control Register High
#define CAN_MOCTR227H          (*((uword volatile far *) 0x202C7E))

// Message Object 227 Control Register Low
#define CAN_MOCTR227L          (*((uword volatile far *) 0x202C7C))

// Message Object 228 Control Register High
#define CAN_MOCTR228H          (*((uword volatile far *) 0x202C9E))

// Message Object 228 Control Register Low
#define CAN_MOCTR228L          (*((uword volatile far *) 0x202C9C))

// Message Object 229 Control Register High
#define CAN_MOCTR229H          (*((uword volatile far *) 0x202CBE))

// Message Object 229 Control Register Low
#define CAN_MOCTR229L          (*((uword volatile far *) 0x202CBC))

// Message Object 22 Control Register High
#define CAN_MOCTR22H           (*((uword volatile far *) 0x2012DE))

// Message Object 22 Control Register Low
#define CAN_MOCTR22L           (*((uword volatile far *) 0x2012DC))

// Message Object 230 Control Register High
#define CAN_MOCTR230H          (*((uword volatile far *) 0x202CDE))

// Message Object 230 Control Register Low
#define CAN_MOCTR230L          (*((uword volatile far *) 0x202CDC))

// Message Object 231 Control Register High
#define CAN_MOCTR231H          (*((uword volatile far *) 0x202CFE))

// Message Object 231 Control Register Low
#define CAN_MOCTR231L          (*((uword volatile far *) 0x202CFC))

// Message Object 232 Control Register High
#define CAN_MOCTR232H          (*((uword volatile far *) 0x202D1E))

// Message Object 232 Control Register Low
#define CAN_MOCTR232L          (*((uword volatile far *) 0x202D1C))

// Message Object 233 Control Register High
#define CAN_MOCTR233H          (*((uword volatile far *) 0x202D3E))

// Message Object 233 Control Register Low
#define CAN_MOCTR233L          (*((uword volatile far *) 0x202D3C))

// Message Object 234 Control Register High
#define CAN_MOCTR234H          (*((uword volatile far *) 0x202D5E))

// Message Object 234 Control Register Low
#define CAN_MOCTR234L          (*((uword volatile far *) 0x202D5C))

// Message Object 235 Control Register High
#define CAN_MOCTR235H          (*((uword volatile far *) 0x202D7E))

// Message Object 235 Control Register Low
#define CAN_MOCTR235L          (*((uword volatile far *) 0x202D7C))

// Message Object 236 Control Register High
#define CAN_MOCTR236H          (*((uword volatile far *) 0x202D9E))

// Message Object 236 Control Register Low
#define CAN_MOCTR236L          (*((uword volatile far *) 0x202D9C))

// Message Object 237 Control Register High
#define CAN_MOCTR237H          (*((uword volatile far *) 0x202DBE))

// Message Object 237 Control Register Low
#define CAN_MOCTR237L          (*((uword volatile far *) 0x202DBC))

// Message Object 238 Control Register High
#define CAN_MOCTR238H          (*((uword volatile far *) 0x202DDE))

// Message Object 238 Control Register Low
#define CAN_MOCTR238L          (*((uword volatile far *) 0x202DDC))

// Message Object 239 Control Register High
#define CAN_MOCTR239H          (*((uword volatile far *) 0x202DFE))

// Message Object 239 Control Register Low
#define CAN_MOCTR239L          (*((uword volatile far *) 0x202DFC))

// Message Object 23 Control Register High
#define CAN_MOCTR23H           (*((uword volatile far *) 0x2012FE))

// Message Object 23 Control Register Low
#define CAN_MOCTR23L           (*((uword volatile far *) 0x2012FC))

// Message Object 240 Control Register High
#define CAN_MOCTR240H          (*((uword volatile far *) 0x202E1E))

// Message Object 240 Control Register Low
#define CAN_MOCTR240L          (*((uword volatile far *) 0x202E1C))

// Message Object 241 Control Register High
#define CAN_MOCTR241H          (*((uword volatile far *) 0x202E3E))

// Message Object 241 Control Register Low
#define CAN_MOCTR241L          (*((uword volatile far *) 0x202E3C))

// Message Object 242 Control Register High
#define CAN_MOCTR242H          (*((uword volatile far *) 0x202E5E))

// Message Object 242 Control Register Low
#define CAN_MOCTR242L          (*((uword volatile far *) 0x202E5C))

// Message Object 243 Control Register High
#define CAN_MOCTR243H          (*((uword volatile far *) 0x202E7E))

// Message Object 243 Control Register Low
#define CAN_MOCTR243L          (*((uword volatile far *) 0x202E7C))

// Message Object 244 Control Register High
#define CAN_MOCTR244H          (*((uword volatile far *) 0x202E9E))

// Message Object 244 Control Register Low
#define CAN_MOCTR244L          (*((uword volatile far *) 0x202E9C))

// Message Object 245 Control Register High
#define CAN_MOCTR245H          (*((uword volatile far *) 0x202EBE))

// Message Object 245 Control Register Low
#define CAN_MOCTR245L          (*((uword volatile far *) 0x202EBC))

// Message Object 246 Control Register High
#define CAN_MOCTR246H          (*((uword volatile far *) 0x202EDE))

// Message Object 246 Control Register Low
#define CAN_MOCTR246L          (*((uword volatile far *) 0x202EDC))

// Message Object 247 Control Register High
#define CAN_MOCTR247H          (*((uword volatile far *) 0x202EFE))

// Message Object 247 Control Register Low
#define CAN_MOCTR247L          (*((uword volatile far *) 0x202EFC))

// Message Object 248 Control Register High
#define CAN_MOCTR248H          (*((uword volatile far *) 0x202F1E))

// Message Object 248 Control Register Low
#define CAN_MOCTR248L          (*((uword volatile far *) 0x202F1C))

// Message Object 249 Control Register High
#define CAN_MOCTR249H          (*((uword volatile far *) 0x202F3E))

// Message Object 249 Control Register Low
#define CAN_MOCTR249L          (*((uword volatile far *) 0x202F3C))

// Message Object 24 Control Register High
#define CAN_MOCTR24H           (*((uword volatile far *) 0x20131E))

// Message Object 24 Control Register Low
#define CAN_MOCTR24L           (*((uword volatile far *) 0x20131C))

// Message Object 250 Control Register High
#define CAN_MOCTR250H          (*((uword volatile far *) 0x202F5E))

// Message Object 250 Control Register Low
#define CAN_MOCTR250L          (*((uword volatile far *) 0x202F5C))

// Message Object 251 Control Register High
#define CAN_MOCTR251H          (*((uword volatile far *) 0x202F7E))

// Message Object 251 Control Register Low
#define CAN_MOCTR251L          (*((uword volatile far *) 0x202F7C))

// Message Object 252 Control Register High
#define CAN_MOCTR252H          (*((uword volatile far *) 0x202F9E))

// Message Object 252 Control Register Low
#define CAN_MOCTR252L          (*((uword volatile far *) 0x202F9C))

// Message Object 253 Control Register High
#define CAN_MOCTR253H          (*((uword volatile far *) 0x202FBE))

// Message Object 253 Control Register Low
#define CAN_MOCTR253L          (*((uword volatile far *) 0x202FBC))

// Message Object 254 Control Register High
#define CAN_MOCTR254H          (*((uword volatile far *) 0x202FDE))

// Message Object 254 Control Register Low
#define CAN_MOCTR254L          (*((uword volatile far *) 0x202FDC))

// Message Object 255 Control Register High
#define CAN_MOCTR255H          (*((uword volatile far *) 0x202FFE))

// Message Object 255 Control Register High
#define CAN_MOCTR255H          (*((uword volatile far *) 0x202FFE))

// Message Object 255 Control Register Low
#define CAN_MOCTR255L          (*((uword volatile far *) 0x202FFC))

// Message Object 25 Control Register High
#define CAN_MOCTR25H           (*((uword volatile far *) 0x20133E))

// Message Object 25 Control Register Low
#define CAN_MOCTR25L           (*((uword volatile far *) 0x20133C))

// Message Object 26 Control Register High
#define CAN_MOCTR26H           (*((uword volatile far *) 0x20135E))

// Message Object 26 Control Register Low
#define CAN_MOCTR26L           (*((uword volatile far *) 0x20135C))

// Message Object 27 Control Register High
#define CAN_MOCTR27H           (*((uword volatile far *) 0x20137E))

// Message Object 27 Control Register Low
#define CAN_MOCTR27L           (*((uword volatile far *) 0x20137C))

// Message Object 28 Control Register High
#define CAN_MOCTR28H           (*((uword volatile far *) 0x20139E))

// Message Object 28 Control Register Low
#define CAN_MOCTR28L           (*((uword volatile far *) 0x20139C))

// Message Object 29 Control Register High
#define CAN_MOCTR29H           (*((uword volatile far *) 0x2013BE))

// Message Object 29 Control Register Low
#define CAN_MOCTR29L           (*((uword volatile far *) 0x2013BC))

// Message Object 2 Control Register High
#define CAN_MOCTR2H            (*((uword volatile far *) 0x20105E))

// Message Object 2 Control Register Low
#define CAN_MOCTR2L            (*((uword volatile far *) 0x20105C))

// Message Object 30 Control Register High
#define CAN_MOCTR30H           (*((uword volatile far *) 0x2013DE))

// Message Object 30 Control Register Low
#define CAN_MOCTR30L           (*((uword volatile far *) 0x2013DC))

// Message Object 31 Control Register High
#define CAN_MOCTR31H           (*((uword volatile far *) 0x2013FE))

// Message Object 31 Control Register Low
#define CAN_MOCTR31L           (*((uword volatile far *) 0x2013FC))

// Message Object 32 Control Register High
#define CAN_MOCTR32H           (*((uword volatile far *) 0x20141E))

// Message Object 32 Control Register Low
#define CAN_MOCTR32L           (*((uword volatile far *) 0x20141C))

// Message Object 33 Control Register High
#define CAN_MOCTR33H           (*((uword volatile far *) 0x20143E))

// Message Object 33 Control Register Low
#define CAN_MOCTR33L           (*((uword volatile far *) 0x20143C))

// Message Object 34 Control Register High
#define CAN_MOCTR34H           (*((uword volatile far *) 0x20145E))

// Message Object 34 Control Register Low
#define CAN_MOCTR34L           (*((uword volatile far *) 0x20145C))

// Message Object 35 Control Register High
#define CAN_MOCTR35H           (*((uword volatile far *) 0x20147E))

// Message Object 35 Control Register Low
#define CAN_MOCTR35L           (*((uword volatile far *) 0x20147C))

// Message Object 36 Control Register High
#define CAN_MOCTR36H           (*((uword volatile far *) 0x20149E))

// Message Object 36 Control Register Low
#define CAN_MOCTR36L           (*((uword volatile far *) 0x20149C))

// Message Object 37 Control Register High
#define CAN_MOCTR37H           (*((uword volatile far *) 0x2014BE))

// Message Object 37 Control Register Low
#define CAN_MOCTR37L           (*((uword volatile far *) 0x2014BC))

// Message Object 38 Control Register High
#define CAN_MOCTR38H           (*((uword volatile far *) 0x2014DE))

// Message Object 38 Control Register Low
#define CAN_MOCTR38L           (*((uword volatile far *) 0x2014DC))

// Message Object 39 Control Register High
#define CAN_MOCTR39H           (*((uword volatile far *) 0x2014FE))

// Message Object 39 Control Register Low
#define CAN_MOCTR39L           (*((uword volatile far *) 0x2014FC))

// Message Object 3 Control Register High
#define CAN_MOCTR3H            (*((uword volatile far *) 0x20107E))

// Message Object 3 Control Register Low
#define CAN_MOCTR3L            (*((uword volatile far *) 0x20107C))

// Message Object 40 Control Register High
#define CAN_MOCTR40H           (*((uword volatile far *) 0x20151E))

// Message Object 40 Control Register Low
#define CAN_MOCTR40L           (*((uword volatile far *) 0x20151C))

// Message Object 41 Control Register High
#define CAN_MOCTR41H           (*((uword volatile far *) 0x20153E))

// Message Object 41 Control Register Low
#define CAN_MOCTR41L           (*((uword volatile far *) 0x20153C))

// Message Object 42 Control Register High
#define CAN_MOCTR42H           (*((uword volatile far *) 0x20155E))

// Message Object 42 Control Register Low
#define CAN_MOCTR42L           (*((uword volatile far *) 0x20155C))

// Message Object 43 Control Register High
#define CAN_MOCTR43H           (*((uword volatile far *) 0x20157E))

// Message Object 43 Control Register Low
#define CAN_MOCTR43L           (*((uword volatile far *) 0x20157C))

// Message Object 44 Control Register High
#define CAN_MOCTR44H           (*((uword volatile far *) 0x20159E))

// Message Object 44 Control Register Low
#define CAN_MOCTR44L           (*((uword volatile far *) 0x20159C))

// Message Object 45 Control Register High
#define CAN_MOCTR45H           (*((uword volatile far *) 0x2015BE))

// Message Object 45 Control Register Low
#define CAN_MOCTR45L           (*((uword volatile far *) 0x2015BC))

// Message Object 46 Control Register High
#define CAN_MOCTR46H           (*((uword volatile far *) 0x2015DE))

// Message Object 46 Control Register Low
#define CAN_MOCTR46L           (*((uword volatile far *) 0x2015DC))

// Message Object 47 Control Register High
#define CAN_MOCTR47H           (*((uword volatile far *) 0x2015FE))

// Message Object 47 Control Register Low
#define CAN_MOCTR47L           (*((uword volatile far *) 0x2015FC))

// Message Object 48 Control Register High
#define CAN_MOCTR48H           (*((uword volatile far *) 0x20161E))

// Message Object 48 Control Register Low
#define CAN_MOCTR48L           (*((uword volatile far *) 0x20161C))

// Message Object 49 Control Register High
#define CAN_MOCTR49H           (*((uword volatile far *) 0x20163E))

// Message Object 49 Control Register Low
#define CAN_MOCTR49L           (*((uword volatile far *) 0x20163C))

// Message Object 4 Control Register High
#define CAN_MOCTR4H            (*((uword volatile far *) 0x20109E))

// Message Object 4 Control Register Low
#define CAN_MOCTR4L            (*((uword volatile far *) 0x20109C))

// Message Object 50 Control Register High
#define CAN_MOCTR50H           (*((uword volatile far *) 0x20165E))

// Message Object 50 Control Register Low
#define CAN_MOCTR50L           (*((uword volatile far *) 0x20165C))

// Message Object 51 Control Register High
#define CAN_MOCTR51H           (*((uword volatile far *) 0x20167E))

// Message Object 51 Control Register Low
#define CAN_MOCTR51L           (*((uword volatile far *) 0x20167C))

// Message Object 52 Control Register High
#define CAN_MOCTR52H           (*((uword volatile far *) 0x20169E))

// Message Object 52 Control Register Low
#define CAN_MOCTR52L           (*((uword volatile far *) 0x20169C))

// Message Object 53 Control Register High
#define CAN_MOCTR53H           (*((uword volatile far *) 0x2016BE))

// Message Object 53 Control Register Low
#define CAN_MOCTR53L           (*((uword volatile far *) 0x2016BC))

// Message Object 54 Control Register High
#define CAN_MOCTR54H           (*((uword volatile far *) 0x2016DE))

// Message Object 54 Control Register Low
#define CAN_MOCTR54L           (*((uword volatile far *) 0x2016DC))

// Message Object 55 Control Register High
#define CAN_MOCTR55H           (*((uword volatile far *) 0x2016FE))

// Message Object 55 Control Register Low
#define CAN_MOCTR55L           (*((uword volatile far *) 0x2016FC))

// Message Object 56 Control Register High
#define CAN_MOCTR56H           (*((uword volatile far *) 0x20171E))

// Message Object 56 Control Register Low
#define CAN_MOCTR56L           (*((uword volatile far *) 0x20171C))

// Message Object 57 Control Register High
#define CAN_MOCTR57H           (*((uword volatile far *) 0x20173E))

// Message Object 57 Control Register Low
#define CAN_MOCTR57L           (*((uword volatile far *) 0x20173C))

// Message Object 58 Control Register High
#define CAN_MOCTR58H           (*((uword volatile far *) 0x20175E))

// Message Object 58 Control Register Low
#define CAN_MOCTR58L           (*((uword volatile far *) 0x20175C))

// Message Object 59 Control Register High
#define CAN_MOCTR59H           (*((uword volatile far *) 0x20177E))

// Message Object 59 Control Register Low
#define CAN_MOCTR59L           (*((uword volatile far *) 0x20177C))

// Message Object 5 Control Register High
#define CAN_MOCTR5H            (*((uword volatile far *) 0x2010BE))

// Message Object 5 Control Register Low
#define CAN_MOCTR5L            (*((uword volatile far *) 0x2010BC))

// Message Object 60 Control Register High
#define CAN_MOCTR60H           (*((uword volatile far *) 0x20179E))

// Message Object 60 Control Register Low
#define CAN_MOCTR60L           (*((uword volatile far *) 0x20179C))

// Message Object 61 Control Register High
#define CAN_MOCTR61H           (*((uword volatile far *) 0x2017BE))

// Message Object 61 Control Register Low
#define CAN_MOCTR61L           (*((uword volatile far *) 0x2017BC))

// Message Object 62 Control Register High
#define CAN_MOCTR62H           (*((uword volatile far *) 0x2017DE))

// Message Object 62 Control Register Low
#define CAN_MOCTR62L           (*((uword volatile far *) 0x2017DC))

// Message Object 63 Control Register High
#define CAN_MOCTR63H           (*((uword volatile far *) 0x2017FE))

// Message Object 63 Control Register Low
#define CAN_MOCTR63L           (*((uword volatile far *) 0x2017FC))

// Message Object 64 Control Register High
#define CAN_MOCTR64H           (*((uword volatile far *) 0x20181E))

// Message Object 64 Control Register Low
#define CAN_MOCTR64L           (*((uword volatile far *) 0x20181C))

// Message Object 65 Control Register High
#define CAN_MOCTR65H           (*((uword volatile far *) 0x20183E))

// Message Object 65 Control Register Low
#define CAN_MOCTR65L           (*((uword volatile far *) 0x20183C))

// Message Object 66 Control Register High
#define CAN_MOCTR66H           (*((uword volatile far *) 0x20185E))

// Message Object 66 Control Register Low
#define CAN_MOCTR66L           (*((uword volatile far *) 0x20185C))

// Message Object 67 Control Register High
#define CAN_MOCTR67H           (*((uword volatile far *) 0x20187E))

// Message Object 67 Control Register Low
#define CAN_MOCTR67L           (*((uword volatile far *) 0x20187C))

// Message Object 68 Control Register High
#define CAN_MOCTR68H           (*((uword volatile far *) 0x20189E))

// Message Object 68 Control Register Low
#define CAN_MOCTR68L           (*((uword volatile far *) 0x20189C))

// Message Object 69 Control Register High
#define CAN_MOCTR69H           (*((uword volatile far *) 0x2018BE))

// Message Object 69 Control Register Low
#define CAN_MOCTR69L           (*((uword volatile far *) 0x2018BC))

// Message Object 6 Control Register High
#define CAN_MOCTR6H            (*((uword volatile far *) 0x2010DE))

// Message Object 6 Control Register Low
#define CAN_MOCTR6L            (*((uword volatile far *) 0x2010DC))

// Message Object 70 Control Register High
#define CAN_MOCTR70H           (*((uword volatile far *) 0x2018DE))

// Message Object 70 Control Register Low
#define CAN_MOCTR70L           (*((uword volatile far *) 0x2018DC))

// Message Object 71 Control Register High
#define CAN_MOCTR71H           (*((uword volatile far *) 0x2018FE))

// Message Object 71 Control Register Low
#define CAN_MOCTR71L           (*((uword volatile far *) 0x2018FC))

// Message Object 72 Control Register High
#define CAN_MOCTR72H           (*((uword volatile far *) 0x20191E))

// Message Object 72 Control Register Low
#define CAN_MOCTR72L           (*((uword volatile far *) 0x20191C))

// Message Object 73 Control Register High
#define CAN_MOCTR73H           (*((uword volatile far *) 0x20193E))

// Message Object 73 Control Register Low
#define CAN_MOCTR73L           (*((uword volatile far *) 0x20193C))

// Message Object 74 Control Register High
#define CAN_MOCTR74H           (*((uword volatile far *) 0x20195E))

// Message Object 74 Control Register Low
#define CAN_MOCTR74L           (*((uword volatile far *) 0x20195C))

// Message Object 75 Control Register High
#define CAN_MOCTR75H           (*((uword volatile far *) 0x20197E))

// Message Object 75 Control Register Low
#define CAN_MOCTR75L           (*((uword volatile far *) 0x20197C))

// Message Object 76 Control Register High
#define CAN_MOCTR76H           (*((uword volatile far *) 0x20199E))

// Message Object 76 Control Register Low
#define CAN_MOCTR76L           (*((uword volatile far *) 0x20199C))

// Message Object 77 Control Register High
#define CAN_MOCTR77H           (*((uword volatile far *) 0x2019BE))

// Message Object 77 Control Register Low
#define CAN_MOCTR77L           (*((uword volatile far *) 0x2019BC))

// Message Object 78 Control Register High
#define CAN_MOCTR78H           (*((uword volatile far *) 0x2019DE))

// Message Object 78 Control Register Low
#define CAN_MOCTR78L           (*((uword volatile far *) 0x2019DC))

// Message Object 79 Control Register High
#define CAN_MOCTR79H           (*((uword volatile far *) 0x2019FE))

// Message Object 79 Control Register Low
#define CAN_MOCTR79L           (*((uword volatile far *) 0x2019FC))

// Message Object 7 Control Register High
#define CAN_MOCTR7H            (*((uword volatile far *) 0x2010FE))

// Message Object 7 Control Register Low
#define CAN_MOCTR7L            (*((uword volatile far *) 0x2010FC))

// Message Object 80 Control Register High
#define CAN_MOCTR80H           (*((uword volatile far *) 0x201A1E))

// Message Object 80 Control Register Low
#define CAN_MOCTR80L           (*((uword volatile far *) 0x201A1C))

// Message Object 81 Control Register High
#define CAN_MOCTR81H           (*((uword volatile far *) 0x201A3E))

// Message Object 81 Control Register Low
#define CAN_MOCTR81L           (*((uword volatile far *) 0x201A3C))

// Message Object 82 Control Register High
#define CAN_MOCTR82H           (*((uword volatile far *) 0x201A5E))

// Message Object 82 Control Register Low
#define CAN_MOCTR82L           (*((uword volatile far *) 0x201A5C))

// Message Object 83 Control Register High
#define CAN_MOCTR83H           (*((uword volatile far *) 0x201A7E))

// Message Object 83 Control Register Low
#define CAN_MOCTR83L           (*((uword volatile far *) 0x201A7C))

// Message Object 84 Control Register High
#define CAN_MOCTR84H           (*((uword volatile far *) 0x201A9E))

// Message Object 84 Control Register Low
#define CAN_MOCTR84L           (*((uword volatile far *) 0x201A9C))

// Message Object 85 Control Register High
#define CAN_MOCTR85H           (*((uword volatile far *) 0x201ABE))

// Message Object 85 Control Register Low
#define CAN_MOCTR85L           (*((uword volatile far *) 0x201ABC))

// Message Object 86 Control Register High
#define CAN_MOCTR86H           (*((uword volatile far *) 0x201ADE))

// Message Object 86 Control Register Low
#define CAN_MOCTR86L           (*((uword volatile far *) 0x201ADC))

// Message Object 87 Control Register High
#define CAN_MOCTR87H           (*((uword volatile far *) 0x201AFE))

// Message Object 87 Control Register Low
#define CAN_MOCTR87L           (*((uword volatile far *) 0x201AFC))

// Message Object 88 Control Register High
#define CAN_MOCTR88H           (*((uword volatile far *) 0x201B1E))

// Message Object 88 Control Register Low
#define CAN_MOCTR88L           (*((uword volatile far *) 0x201B1C))

// Message Object 89 Control Register High
#define CAN_MOCTR89H           (*((uword volatile far *) 0x201B3E))

// Message Object 89 Control Register Low
#define CAN_MOCTR89L           (*((uword volatile far *) 0x201B3C))

// Message Object 8 Control Register High
#define CAN_MOCTR8H            (*((uword volatile far *) 0x20111E))

// Message Object 8 Control Register Low
#define CAN_MOCTR8L            (*((uword volatile far *) 0x20111C))

// Message Object 90 Control Register High
#define CAN_MOCTR90H           (*((uword volatile far *) 0x201B5E))

// Message Object 90 Control Register Low
#define CAN_MOCTR90L           (*((uword volatile far *) 0x201B5C))

// Message Object 91 Control Register High
#define CAN_MOCTR91H           (*((uword volatile far *) 0x201B7E))

// Message Object 91 Control Register Low
#define CAN_MOCTR91L           (*((uword volatile far *) 0x201B7C))

// Message Object 92 Control Register High
#define CAN_MOCTR92H           (*((uword volatile far *) 0x201B9E))

// Message Object 92 Control Register Low
#define CAN_MOCTR92L           (*((uword volatile far *) 0x201B9C))

// Message Object 93 Control Register High
#define CAN_MOCTR93H           (*((uword volatile far *) 0x201BBE))

// Message Object 93 Control Register Low
#define CAN_MOCTR93L           (*((uword volatile far *) 0x201BBC))

// Message Object 94 Control Register High
#define CAN_MOCTR94H           (*((uword volatile far *) 0x201BDE))

// Message Object 94 Control Register Low
#define CAN_MOCTR94L           (*((uword volatile far *) 0x201BDC))

// Message Object 95 Control Register High
#define CAN_MOCTR95H           (*((uword volatile far *) 0x201BFE))

// Message Object 95 Control Register Low
#define CAN_MOCTR95L           (*((uword volatile far *) 0x201BFC))

// Message Object 96 Control Register High
#define CAN_MOCTR96H           (*((uword volatile far *) 0x201C1E))

// Message Object 96 Control Register Low
#define CAN_MOCTR96L           (*((uword volatile far *) 0x201C1C))

// Message Object 97 Control Register High
#define CAN_MOCTR97H           (*((uword volatile far *) 0x201C3E))

// Message Object 97 Control Register Low
#define CAN_MOCTR97L           (*((uword volatile far *) 0x201C3C))

// Message Object 98 Control Register High
#define CAN_MOCTR98H           (*((uword volatile far *) 0x201C5E))

// Message Object 98 Control Register Low
#define CAN_MOCTR98L           (*((uword volatile far *) 0x201C5C))

// Message Object 99 Control Register High
#define CAN_MOCTR99H           (*((uword volatile far *) 0x201C7E))

// Message Object 99 Control Register Low
#define CAN_MOCTR99L           (*((uword volatile far *) 0x201C7C))

// Message Object 9 Control Register High
#define CAN_MOCTR9H            (*((uword volatile far *) 0x20113E))

// Message Object 9 Control Register Low
#define CAN_MOCTR9L            (*((uword volatile far *) 0x20113C))

// Message Object 0 Data Register High High
#define CAN_MODATA0HH          (*((uword volatile far *) 0x201016))

// Message Object 0 Data Register High Low
#define CAN_MODATA0HL          (*((uword volatile far *) 0x201014))

// Message Object 0 Data Register Low High
#define CAN_MODATA0LH          (*((uword volatile far *) 0x201012))

// Message Object 0 Data Register Low Low
#define CAN_MODATA0LL          (*((uword volatile far *) 0x201010))

// Message Object 100 Data Register High High
#define CAN_MODATA100HH        (*((uword volatile far *) 0x201C96))

// Message Object 100 Data Register High Low
#define CAN_MODATA100HL        (*((uword volatile far *) 0x201C94))

// Message Object 100 Data Register Low High
#define CAN_MODATA100LH        (*((uword volatile far *) 0x201C92))

// Message Object 100 Data Register Low Low
#define CAN_MODATA100LL        (*((uword volatile far *) 0x201C90))

// Message Object 101 Data Register High High
#define CAN_MODATA101HH        (*((uword volatile far *) 0x201CB6))

// Message Object 101 Data Register High Low
#define CAN_MODATA101HL        (*((uword volatile far *) 0x201CB4))

// Message Object 101 Data Register Low High
#define CAN_MODATA101LH        (*((uword volatile far *) 0x201CB2))

// Message Object 101 Data Register Low Low
#define CAN_MODATA101LL        (*((uword volatile far *) 0x201CB0))

// Message Object 102 Data Register High High
#define CAN_MODATA102HH        (*((uword volatile far *) 0x201CD6))

// Message Object 102 Data Register High Low
#define CAN_MODATA102HL        (*((uword volatile far *) 0x201CD4))

// Message Object 102 Data Register Low High
#define CAN_MODATA102LH        (*((uword volatile far *) 0x201CD2))

// Message Object 102 Data Register Low Low
#define CAN_MODATA102LL        (*((uword volatile far *) 0x201CD0))

// Message Object 103 Data Register High High
#define CAN_MODATA103HH        (*((uword volatile far *) 0x201CF6))

// Message Object 103 Data Register High Low
#define CAN_MODATA103HL        (*((uword volatile far *) 0x201CF4))

// Message Object 103 Data Register Low High
#define CAN_MODATA103LH        (*((uword volatile far *) 0x201CF2))

// Message Object 103 Data Register Low Low
#define CAN_MODATA103LL        (*((uword volatile far *) 0x201CF0))

// Message Object 104 Data Register High High
#define CAN_MODATA104HH        (*((uword volatile far *) 0x201D16))

// Message Object 104 Data Register High Low
#define CAN_MODATA104HL        (*((uword volatile far *) 0x201D14))

// Message Object 104 Data Register Low High
#define CAN_MODATA104LH        (*((uword volatile far *) 0x201D12))

// Message Object 104 Data Register Low Low
#define CAN_MODATA104LL        (*((uword volatile far *) 0x201D10))

// Message Object 105 Data Register High High
#define CAN_MODATA105HH        (*((uword volatile far *) 0x201D36))

// Message Object 105 Data Register High Low
#define CAN_MODATA105HL        (*((uword volatile far *) 0x201D34))

// Message Object 105 Data Register Low High
#define CAN_MODATA105LH        (*((uword volatile far *) 0x201D32))

// Message Object 105 Data Register Low Low
#define CAN_MODATA105LL        (*((uword volatile far *) 0x201D30))

// Message Object 106 Data Register High High
#define CAN_MODATA106HH        (*((uword volatile far *) 0x201D56))

// Message Object 106 Data Register High Low
#define CAN_MODATA106HL        (*((uword volatile far *) 0x201D54))

// Message Object 106 Data Register Low High
#define CAN_MODATA106LH        (*((uword volatile far *) 0x201D52))

// Message Object 106 Data Register Low Low
#define CAN_MODATA106LL        (*((uword volatile far *) 0x201D50))

// Message Object 107 Data Register High High
#define CAN_MODATA107HH        (*((uword volatile far *) 0x201D76))

// Message Object 107 Data Register High Low
#define CAN_MODATA107HL        (*((uword volatile far *) 0x201D74))

// Message Object 107 Data Register Low High
#define CAN_MODATA107LH        (*((uword volatile far *) 0x201D72))

// Message Object 107 Data Register Low Low
#define CAN_MODATA107LL        (*((uword volatile far *) 0x201D70))

// Message Object 108 Data Register High High
#define CAN_MODATA108HH        (*((uword volatile far *) 0x201D96))

// Message Object 108 Data Register High Low
#define CAN_MODATA108HL        (*((uword volatile far *) 0x201D94))

// Message Object 108 Data Register Low High
#define CAN_MODATA108LH        (*((uword volatile far *) 0x201D92))

// Message Object 108 Data Register Low Low
#define CAN_MODATA108LL        (*((uword volatile far *) 0x201D90))

// Message Object 109 Data Register High High
#define CAN_MODATA109HH        (*((uword volatile far *) 0x201DB6))

// Message Object 109 Data Register High Low
#define CAN_MODATA109HL        (*((uword volatile far *) 0x201DB4))

// Message Object 109 Data Register Low High
#define CAN_MODATA109LH        (*((uword volatile far *) 0x201DB2))

// Message Object 109 Data Register Low Low
#define CAN_MODATA109LL        (*((uword volatile far *) 0x201DB0))

// Message Object 10 Data Register High High
#define CAN_MODATA10HH         (*((uword volatile far *) 0x201156))

// Message Object 10 Data Register High Low
#define CAN_MODATA10HL         (*((uword volatile far *) 0x201154))

// Message Object 10 Data Register Low High
#define CAN_MODATA10LH         (*((uword volatile far *) 0x201152))

// Message Object 10 Data Register Low Low
#define CAN_MODATA10LL         (*((uword volatile far *) 0x201150))

// Message Object 110 Data Register High High
#define CAN_MODATA110HH        (*((uword volatile far *) 0x201DD6))

// Message Object 110 Data Register High Low
#define CAN_MODATA110HL        (*((uword volatile far *) 0x201DD4))

// Message Object 110 Data Register Low High
#define CAN_MODATA110LH        (*((uword volatile far *) 0x201DD2))

// Message Object 110 Data Register Low Low
#define CAN_MODATA110LL        (*((uword volatile far *) 0x201DD0))

// Message Object 111 Data Register High High
#define CAN_MODATA111HH        (*((uword volatile far *) 0x201DF6))

// Message Object 111 Data Register High Low
#define CAN_MODATA111HL        (*((uword volatile far *) 0x201DF4))

// Message Object 111 Data Register Low High
#define CAN_MODATA111LH        (*((uword volatile far *) 0x201DF2))

// Message Object 111 Data Register Low Low
#define CAN_MODATA111LL        (*((uword volatile far *) 0x201DF0))

// Message Object 112 Data Register High High
#define CAN_MODATA112HH        (*((uword volatile far *) 0x201E16))

// Message Object 112 Data Register High Low
#define CAN_MODATA112HL        (*((uword volatile far *) 0x201E14))

// Message Object 112 Data Register Low High
#define CAN_MODATA112LH        (*((uword volatile far *) 0x201E12))

// Message Object 112 Data Register Low Low
#define CAN_MODATA112LL        (*((uword volatile far *) 0x201E10))

// Message Object 113 Data Register High High
#define CAN_MODATA113HH        (*((uword volatile far *) 0x201E36))

// Message Object 113 Data Register High Low
#define CAN_MODATA113HL        (*((uword volatile far *) 0x201E34))

// Message Object 113 Data Register Low High
#define CAN_MODATA113LH        (*((uword volatile far *) 0x201E32))

// Message Object 113 Data Register Low Low
#define CAN_MODATA113LL        (*((uword volatile far *) 0x201E30))

// Message Object 114 Data Register High High
#define CAN_MODATA114HH        (*((uword volatile far *) 0x201E56))

// Message Object 114 Data Register High Low
#define CAN_MODATA114HL        (*((uword volatile far *) 0x201E54))

// Message Object 114 Data Register Low High
#define CAN_MODATA114LH        (*((uword volatile far *) 0x201E52))

// Message Object 114 Data Register Low Low
#define CAN_MODATA114LL        (*((uword volatile far *) 0x201E50))

// Message Object 115 Data Register High High
#define CAN_MODATA115HH        (*((uword volatile far *) 0x201E76))

// Message Object 115 Data Register High Low
#define CAN_MODATA115HL        (*((uword volatile far *) 0x201E74))

// Message Object 115 Data Register Low High
#define CAN_MODATA115LH        (*((uword volatile far *) 0x201E72))

// Message Object 115 Data Register Low Low
#define CAN_MODATA115LL        (*((uword volatile far *) 0x201E70))

// Message Object 116 Data Register High High
#define CAN_MODATA116HH        (*((uword volatile far *) 0x201E96))

// Message Object 116 Data Register High Low
#define CAN_MODATA116HL        (*((uword volatile far *) 0x201E94))

// Message Object 116 Data Register Low High
#define CAN_MODATA116LH        (*((uword volatile far *) 0x201E92))

// Message Object 116 Data Register Low Low
#define CAN_MODATA116LL        (*((uword volatile far *) 0x201E90))

// Message Object 117 Data Register High High
#define CAN_MODATA117HH        (*((uword volatile far *) 0x201EB6))

// Message Object 117 Data Register High Low
#define CAN_MODATA117HL        (*((uword volatile far *) 0x201EB4))

// Message Object 117 Data Register Low High
#define CAN_MODATA117LH        (*((uword volatile far *) 0x201EB2))

// Message Object 117 Data Register Low Low
#define CAN_MODATA117LL        (*((uword volatile far *) 0x201EB0))

// Message Object 118 Data Register High High
#define CAN_MODATA118HH        (*((uword volatile far *) 0x201ED6))

// Message Object 118 Data Register High Low
#define CAN_MODATA118HL        (*((uword volatile far *) 0x201ED4))

// Message Object 118 Data Register Low High
#define CAN_MODATA118LH        (*((uword volatile far *) 0x201ED2))

// Message Object 118 Data Register Low Low
#define CAN_MODATA118LL        (*((uword volatile far *) 0x201ED0))

// Message Object 119 Data Register High High
#define CAN_MODATA119HH        (*((uword volatile far *) 0x201EF6))

// Message Object 119 Data Register High Low
#define CAN_MODATA119HL        (*((uword volatile far *) 0x201EF4))

// Message Object 119 Data Register Low High
#define CAN_MODATA119LH        (*((uword volatile far *) 0x201EF2))

// Message Object 119 Data Register Low Low
#define CAN_MODATA119LL        (*((uword volatile far *) 0x201EF0))

// Message Object 11 Data Register High High
#define CAN_MODATA11HH         (*((uword volatile far *) 0x201176))

// Message Object 11 Data Register High Low
#define CAN_MODATA11HL         (*((uword volatile far *) 0x201174))

// Message Object 11 Data Register Low High
#define CAN_MODATA11LH         (*((uword volatile far *) 0x201172))

// Message Object 11 Data Register Low Low
#define CAN_MODATA11LL         (*((uword volatile far *) 0x201170))

// Message Object 120 Data Register High High
#define CAN_MODATA120HH        (*((uword volatile far *) 0x201F16))

// Message Object 120 Data Register High Low
#define CAN_MODATA120HL        (*((uword volatile far *) 0x201F14))

// Message Object 120 Data Register Low High
#define CAN_MODATA120LH        (*((uword volatile far *) 0x201F12))

// Message Object 120 Data Register Low Low
#define CAN_MODATA120LL        (*((uword volatile far *) 0x201F10))

// Message Object 121 Data Register High High
#define CAN_MODATA121HH        (*((uword volatile far *) 0x201F36))

// Message Object 121 Data Register High Low
#define CAN_MODATA121HL        (*((uword volatile far *) 0x201F34))

// Message Object 121 Data Register Low High
#define CAN_MODATA121LH        (*((uword volatile far *) 0x201F32))

// Message Object 121 Data Register Low Low
#define CAN_MODATA121LL        (*((uword volatile far *) 0x201F30))

// Message Object 122 Data Register High High
#define CAN_MODATA122HH        (*((uword volatile far *) 0x201F56))

// Message Object 122 Data Register High Low
#define CAN_MODATA122HL        (*((uword volatile far *) 0x201F54))

// Message Object 122 Data Register Low High
#define CAN_MODATA122LH        (*((uword volatile far *) 0x201F52))

// Message Object 122 Data Register Low Low
#define CAN_MODATA122LL        (*((uword volatile far *) 0x201F50))

// Message Object 123 Data Register High High
#define CAN_MODATA123HH        (*((uword volatile far *) 0x201F76))

// Message Object 123 Data Register High Low
#define CAN_MODATA123HL        (*((uword volatile far *) 0x201F74))

// Message Object 123 Data Register Low High
#define CAN_MODATA123LH        (*((uword volatile far *) 0x201F72))

// Message Object 123 Data Register Low Low
#define CAN_MODATA123LL        (*((uword volatile far *) 0x201F70))

// Message Object 124 Data Register High High
#define CAN_MODATA124HH        (*((uword volatile far *) 0x201F96))

// Message Object 124 Data Register High Low
#define CAN_MODATA124HL        (*((uword volatile far *) 0x201F94))

// Message Object 124 Data Register Low High
#define CAN_MODATA124LH        (*((uword volatile far *) 0x201F92))

// Message Object 124 Data Register Low Low
#define CAN_MODATA124LL        (*((uword volatile far *) 0x201F90))

// Message Object 125 Data Register High High
#define CAN_MODATA125HH        (*((uword volatile far *) 0x201FB6))

// Message Object 125 Data Register High Low
#define CAN_MODATA125HL        (*((uword volatile far *) 0x201FB4))

// Message Object 125 Data Register Low High
#define CAN_MODATA125LH        (*((uword volatile far *) 0x201FB2))

// Message Object 125 Data Register Low Low
#define CAN_MODATA125LL        (*((uword volatile far *) 0x201FB0))

// Message Object 126 Data Register High High
#define CAN_MODATA126HH        (*((uword volatile far *) 0x201FD6))

// Message Object 126 Data Register High Low
#define CAN_MODATA126HL        (*((uword volatile far *) 0x201FD4))

// Message Object 126 Data Register Low High
#define CAN_MODATA126LH        (*((uword volatile far *) 0x201FD2))

// Message Object 126 Data Register Low Low
#define CAN_MODATA126LL        (*((uword volatile far *) 0x201FD0))

// Message Object 127 Data Register High High
#define CAN_MODATA127HH        (*((uword volatile far *) 0x201FF6))

// Message Object 127 Data Register High Low
#define CAN_MODATA127HL        (*((uword volatile far *) 0x201FF4))

// Message Object 127 Data Register Low High
#define CAN_MODATA127LH        (*((uword volatile far *) 0x201FF2))

// Message Object 127 Data Register Low Low
#define CAN_MODATA127LL        (*((uword volatile far *) 0x201FF0))

// Message Object 128 Data Register High High
#define CAN_MODATA128HH        (*((uword volatile far *) 0x202016))

// Message Object 128 Data Register High Low
#define CAN_MODATA128HL        (*((uword volatile far *) 0x202014))

// Message Object 128 Data Register Low High
#define CAN_MODATA128LH        (*((uword volatile far *) 0x202012))

// Message Object 128 Data Register Low Low
#define CAN_MODATA128LL        (*((uword volatile far *) 0x202010))

// Message Object 129 Data Register High High
#define CAN_MODATA129HH        (*((uword volatile far *) 0x202036))

// Message Object 129 Data Register High Low
#define CAN_MODATA129HL        (*((uword volatile far *) 0x202034))

// Message Object 129 Data Register Low High
#define CAN_MODATA129LH        (*((uword volatile far *) 0x202032))

// Message Object 129 Data Register Low Low
#define CAN_MODATA129LL        (*((uword volatile far *) 0x202030))

// Message Object 12 Data Register High High
#define CAN_MODATA12HH         (*((uword volatile far *) 0x201196))

// Message Object 12 Data Register High Low
#define CAN_MODATA12HL         (*((uword volatile far *) 0x201194))

// Message Object 12 Data Register Low High
#define CAN_MODATA12LH         (*((uword volatile far *) 0x201192))

// Message Object 12 Data Register Low Low
#define CAN_MODATA12LL         (*((uword volatile far *) 0x201190))

// Message Object 130 Data Register High High
#define CAN_MODATA130HH        (*((uword volatile far *) 0x202056))

// Message Object 130 Data Register High Low
#define CAN_MODATA130HL        (*((uword volatile far *) 0x202054))

// Message Object 130 Data Register Low High
#define CAN_MODATA130LH        (*((uword volatile far *) 0x202052))

// Message Object 130 Data Register Low Low
#define CAN_MODATA130LL        (*((uword volatile far *) 0x202050))

// Message Object 131 Data Register High High
#define CAN_MODATA131HH        (*((uword volatile far *) 0x202076))

// Message Object 131 Data Register High Low
#define CAN_MODATA131HL        (*((uword volatile far *) 0x202074))

// Message Object 131 Data Register Low High
#define CAN_MODATA131LH        (*((uword volatile far *) 0x202072))

// Message Object 131 Data Register Low Low
#define CAN_MODATA131LL        (*((uword volatile far *) 0x202070))

// Message Object 132 Data Register High High
#define CAN_MODATA132HH        (*((uword volatile far *) 0x202096))

// Message Object 132 Data Register High Low
#define CAN_MODATA132HL        (*((uword volatile far *) 0x202094))

// Message Object 132 Data Register Low High
#define CAN_MODATA132LH        (*((uword volatile far *) 0x202092))

// Message Object 132 Data Register Low Low
#define CAN_MODATA132LL        (*((uword volatile far *) 0x202090))

// Message Object 133 Data Register High High
#define CAN_MODATA133HH        (*((uword volatile far *) 0x2020B6))

// Message Object 133 Data Register High Low
#define CAN_MODATA133HL        (*((uword volatile far *) 0x2020B4))

// Message Object 133 Data Register Low High
#define CAN_MODATA133LH        (*((uword volatile far *) 0x2020B2))

// Message Object 133 Data Register Low Low
#define CAN_MODATA133LL        (*((uword volatile far *) 0x2020B0))

// Message Object 134 Data Register High High
#define CAN_MODATA134HH        (*((uword volatile far *) 0x2020D6))

// Message Object 134 Data Register High Low
#define CAN_MODATA134HL        (*((uword volatile far *) 0x2020D4))

// Message Object 134 Data Register Low High
#define CAN_MODATA134LH        (*((uword volatile far *) 0x2020D2))

// Message Object 134 Data Register Low Low
#define CAN_MODATA134LL        (*((uword volatile far *) 0x2020D0))

// Message Object 135 Data Register High High
#define CAN_MODATA135HH        (*((uword volatile far *) 0x2020F6))

// Message Object 135 Data Register High Low
#define CAN_MODATA135HL        (*((uword volatile far *) 0x2020F4))

// Message Object 135 Data Register Low High
#define CAN_MODATA135LH        (*((uword volatile far *) 0x2020F2))

// Message Object 135 Data Register Low Low
#define CAN_MODATA135LL        (*((uword volatile far *) 0x2020F0))

// Message Object 136 Data Register High High
#define CAN_MODATA136HH        (*((uword volatile far *) 0x202116))

// Message Object 136 Data Register High Low
#define CAN_MODATA136HL        (*((uword volatile far *) 0x202114))

// Message Object 136 Data Register Low High
#define CAN_MODATA136LH        (*((uword volatile far *) 0x202112))

// Message Object 136 Data Register Low Low
#define CAN_MODATA136LL        (*((uword volatile far *) 0x202110))

// Message Object 137 Data Register High High
#define CAN_MODATA137HH        (*((uword volatile far *) 0x202136))

// Message Object 137 Data Register High Low
#define CAN_MODATA137HL        (*((uword volatile far *) 0x202134))

// Message Object 137 Data Register Low High
#define CAN_MODATA137LH        (*((uword volatile far *) 0x202132))

// Message Object 137 Data Register Low Low
#define CAN_MODATA137LL        (*((uword volatile far *) 0x202130))

// Message Object 138 Data Register High High
#define CAN_MODATA138HH        (*((uword volatile far *) 0x202156))

// Message Object 138 Data Register High Low
#define CAN_MODATA138HL        (*((uword volatile far *) 0x202154))

// Message Object 138 Data Register Low High
#define CAN_MODATA138LH        (*((uword volatile far *) 0x202152))

// Message Object 138 Data Register Low Low
#define CAN_MODATA138LL        (*((uword volatile far *) 0x202150))

// Message Object 139 Data Register High High
#define CAN_MODATA139HH        (*((uword volatile far *) 0x202176))

// Message Object 139 Data Register High Low
#define CAN_MODATA139HL        (*((uword volatile far *) 0x202174))

// Message Object 139 Data Register Low High
#define CAN_MODATA139LH        (*((uword volatile far *) 0x202172))

// Message Object 139 Data Register Low Low
#define CAN_MODATA139LL        (*((uword volatile far *) 0x202170))

// Message Object 13 Data Register High High
#define CAN_MODATA13HH         (*((uword volatile far *) 0x2011B6))

// Message Object 13 Data Register High Low
#define CAN_MODATA13HL         (*((uword volatile far *) 0x2011B4))

// Message Object 13 Data Register Low High
#define CAN_MODATA13LH         (*((uword volatile far *) 0x2011B2))

// Message Object 13 Data Register Low Low
#define CAN_MODATA13LL         (*((uword volatile far *) 0x2011B0))

// Message Object 140 Data Register High High
#define CAN_MODATA140HH        (*((uword volatile far *) 0x202196))

// Message Object 140 Data Register High Low
#define CAN_MODATA140HL        (*((uword volatile far *) 0x202194))

// Message Object 140 Data Register Low High
#define CAN_MODATA140LH        (*((uword volatile far *) 0x202192))

// Message Object 140 Data Register Low Low
#define CAN_MODATA140LL        (*((uword volatile far *) 0x202190))

// Message Object 141 Data Register High High
#define CAN_MODATA141HH        (*((uword volatile far *) 0x2021B6))

// Message Object 141 Data Register High Low
#define CAN_MODATA141HL        (*((uword volatile far *) 0x2021B4))

// Message Object 141 Data Register Low High
#define CAN_MODATA141LH        (*((uword volatile far *) 0x2021B2))

// Message Object 141 Data Register Low Low
#define CAN_MODATA141LL        (*((uword volatile far *) 0x2021B0))

// Message Object 142 Data Register High High
#define CAN_MODATA142HH        (*((uword volatile far *) 0x2021D6))

// Message Object 142 Data Register High Low
#define CAN_MODATA142HL        (*((uword volatile far *) 0x2021D4))

// Message Object 142 Data Register Low High
#define CAN_MODATA142LH        (*((uword volatile far *) 0x2021D2))

// Message Object 142 Data Register Low Low
#define CAN_MODATA142LL        (*((uword volatile far *) 0x2021D0))

// Message Object 143 Data Register High High
#define CAN_MODATA143HH        (*((uword volatile far *) 0x2021F6))

// Message Object 143 Data Register High Low
#define CAN_MODATA143HL        (*((uword volatile far *) 0x2021F4))

// Message Object 143 Data Register Low High
#define CAN_MODATA143LH        (*((uword volatile far *) 0x2021F2))

// Message Object 143 Data Register Low Low
#define CAN_MODATA143LL        (*((uword volatile far *) 0x2021F0))

// Message Object 144 Data Register High High
#define CAN_MODATA144HH        (*((uword volatile far *) 0x202216))

// Message Object 144 Data Register High Low
#define CAN_MODATA144HL        (*((uword volatile far *) 0x202214))

// Message Object 144 Data Register Low High
#define CAN_MODATA144LH        (*((uword volatile far *) 0x202212))

// Message Object 144 Data Register Low Low
#define CAN_MODATA144LL        (*((uword volatile far *) 0x202210))

// Message Object 145 Data Register High High
#define CAN_MODATA145HH        (*((uword volatile far *) 0x202236))

// Message Object 145 Data Register High Low
#define CAN_MODATA145HL        (*((uword volatile far *) 0x202234))

// Message Object 145 Data Register Low High
#define CAN_MODATA145LH        (*((uword volatile far *) 0x202232))

// Message Object 145 Data Register Low Low
#define CAN_MODATA145LL        (*((uword volatile far *) 0x202230))

// Message Object 146 Data Register High High
#define CAN_MODATA146HH        (*((uword volatile far *) 0x202256))

// Message Object 146 Data Register High Low
#define CAN_MODATA146HL        (*((uword volatile far *) 0x202254))

// Message Object 146 Data Register Low High
#define CAN_MODATA146LH        (*((uword volatile far *) 0x202252))

// Message Object 146 Data Register Low Low
#define CAN_MODATA146LL        (*((uword volatile far *) 0x202250))

// Message Object 147 Data Register High High
#define CAN_MODATA147HH        (*((uword volatile far *) 0x202276))

// Message Object 147 Data Register High Low
#define CAN_MODATA147HL        (*((uword volatile far *) 0x202274))

// Message Object 147 Data Register Low High
#define CAN_MODATA147LH        (*((uword volatile far *) 0x202272))

// Message Object 147 Data Register Low Low
#define CAN_MODATA147LL        (*((uword volatile far *) 0x202270))

// Message Object 148 Data Register High High
#define CAN_MODATA148HH        (*((uword volatile far *) 0x202296))

// Message Object 148 Data Register High Low
#define CAN_MODATA148HL        (*((uword volatile far *) 0x202294))

// Message Object 148 Data Register Low High
#define CAN_MODATA148LH        (*((uword volatile far *) 0x202292))

// Message Object 148 Data Register Low Low
#define CAN_MODATA148LL        (*((uword volatile far *) 0x202290))

// Message Object 149 Data Register High High
#define CAN_MODATA149HH        (*((uword volatile far *) 0x2022B6))

// Message Object 149 Data Register High Low
#define CAN_MODATA149HL        (*((uword volatile far *) 0x2022B4))

// Message Object 149 Data Register Low High
#define CAN_MODATA149LH        (*((uword volatile far *) 0x2022B2))

// Message Object 149 Data Register Low Low
#define CAN_MODATA149LL        (*((uword volatile far *) 0x2022B0))

// Message Object 14 Data Register High High
#define CAN_MODATA14HH         (*((uword volatile far *) 0x2011D6))

// Message Object 14 Data Register High Low
#define CAN_MODATA14HL         (*((uword volatile far *) 0x2011D4))

// Message Object 14 Data Register Low High
#define CAN_MODATA14LH         (*((uword volatile far *) 0x2011D2))

// Message Object 14 Data Register Low Low
#define CAN_MODATA14LL         (*((uword volatile far *) 0x2011D0))

// Message Object 150 Data Register High High
#define CAN_MODATA150HH        (*((uword volatile far *) 0x2022D6))

// Message Object 150 Data Register High Low
#define CAN_MODATA150HL        (*((uword volatile far *) 0x2022D4))

// Message Object 150 Data Register Low High
#define CAN_MODATA150LH        (*((uword volatile far *) 0x2022D2))

// Message Object 150 Data Register Low Low
#define CAN_MODATA150LL        (*((uword volatile far *) 0x2022D0))

// Message Object 151 Data Register High High
#define CAN_MODATA151HH        (*((uword volatile far *) 0x2022F6))

// Message Object 151 Data Register High Low
#define CAN_MODATA151HL        (*((uword volatile far *) 0x2022F4))

// Message Object 151 Data Register Low High
#define CAN_MODATA151LH        (*((uword volatile far *) 0x2022F2))

// Message Object 151 Data Register Low Low
#define CAN_MODATA151LL        (*((uword volatile far *) 0x2022F0))

// Message Object 152 Data Register High High
#define CAN_MODATA152HH        (*((uword volatile far *) 0x202316))

// Message Object 152 Data Register High Low
#define CAN_MODATA152HL        (*((uword volatile far *) 0x202314))

// Message Object 152 Data Register Low High
#define CAN_MODATA152LH        (*((uword volatile far *) 0x202312))

// Message Object 152 Data Register Low Low
#define CAN_MODATA152LL        (*((uword volatile far *) 0x202310))

// Message Object 153 Data Register High High
#define CAN_MODATA153HH        (*((uword volatile far *) 0x202336))

// Message Object 153 Data Register High Low
#define CAN_MODATA153HL        (*((uword volatile far *) 0x202334))

// Message Object 153 Data Register Low High
#define CAN_MODATA153LH        (*((uword volatile far *) 0x202332))

// Message Object 153 Data Register Low Low
#define CAN_MODATA153LL        (*((uword volatile far *) 0x202330))

// Message Object 154 Data Register High High
#define CAN_MODATA154HH        (*((uword volatile far *) 0x202356))

// Message Object 154 Data Register High Low
#define CAN_MODATA154HL        (*((uword volatile far *) 0x202354))

// Message Object 154 Data Register Low High
#define CAN_MODATA154LH        (*((uword volatile far *) 0x202352))

// Message Object 154 Data Register Low Low
#define CAN_MODATA154LL        (*((uword volatile far *) 0x202350))

// Message Object 155 Data Register High High
#define CAN_MODATA155HH        (*((uword volatile far *) 0x202376))

// Message Object 155 Data Register High Low
#define CAN_MODATA155HL        (*((uword volatile far *) 0x202374))

// Message Object 155 Data Register Low High
#define CAN_MODATA155LH        (*((uword volatile far *) 0x202372))

// Message Object 155 Data Register Low Low
#define CAN_MODATA155LL        (*((uword volatile far *) 0x202370))

// Message Object 156 Data Register High High
#define CAN_MODATA156HH        (*((uword volatile far *) 0x202396))

// Message Object 156 Data Register High Low
#define CAN_MODATA156HL        (*((uword volatile far *) 0x202394))

// Message Object 156 Data Register Low High
#define CAN_MODATA156LH        (*((uword volatile far *) 0x202392))

// Message Object 156 Data Register Low Low
#define CAN_MODATA156LL        (*((uword volatile far *) 0x202390))

// Message Object 157 Data Register High High
#define CAN_MODATA157HH        (*((uword volatile far *) 0x2023B6))

// Message Object 157 Data Register High Low
#define CAN_MODATA157HL        (*((uword volatile far *) 0x2023B4))

// Message Object 157 Data Register Low High
#define CAN_MODATA157LH        (*((uword volatile far *) 0x2023B2))

// Message Object 157 Data Register Low Low
#define CAN_MODATA157LL        (*((uword volatile far *) 0x2023B0))

// Message Object 158 Data Register High High
#define CAN_MODATA158HH        (*((uword volatile far *) 0x2023D6))

// Message Object 158 Data Register High Low
#define CAN_MODATA158HL        (*((uword volatile far *) 0x2023D4))

// Message Object 158 Data Register Low High
#define CAN_MODATA158LH        (*((uword volatile far *) 0x2023D2))

// Message Object 158 Data Register Low Low
#define CAN_MODATA158LL        (*((uword volatile far *) 0x2023D0))

// Message Object 159 Data Register High High
#define CAN_MODATA159HH        (*((uword volatile far *) 0x2023F6))

// Message Object 159 Data Register High Low
#define CAN_MODATA159HL        (*((uword volatile far *) 0x2023F4))

// Message Object 159 Data Register Low High
#define CAN_MODATA159LH        (*((uword volatile far *) 0x2023F2))

// Message Object 159 Data Register Low Low
#define CAN_MODATA159LL        (*((uword volatile far *) 0x2023F0))

// Message Object 15 Data Register High High
#define CAN_MODATA15HH         (*((uword volatile far *) 0x2011F6))

// Message Object 15 Data Register High Low
#define CAN_MODATA15HL         (*((uword volatile far *) 0x2011F4))

// Message Object 15 Data Register Low High
#define CAN_MODATA15LH         (*((uword volatile far *) 0x2011F2))

// Message Object 15 Data Register Low Low
#define CAN_MODATA15LL         (*((uword volatile far *) 0x2011F0))

// Message Object 160 Data Register High High
#define CAN_MODATA160HH        (*((uword volatile far *) 0x202416))

// Message Object 160 Data Register High Low
#define CAN_MODATA160HL        (*((uword volatile far *) 0x202414))

// Message Object 160 Data Register Low High
#define CAN_MODATA160LH        (*((uword volatile far *) 0x202412))

// Message Object 160 Data Register Low Low
#define CAN_MODATA160LL        (*((uword volatile far *) 0x202410))

// Message Object 161 Data Register High High
#define CAN_MODATA161HH        (*((uword volatile far *) 0x202436))

// Message Object 161 Data Register High Low
#define CAN_MODATA161HL        (*((uword volatile far *) 0x202434))

// Message Object 161 Data Register Low High
#define CAN_MODATA161LH        (*((uword volatile far *) 0x202432))

// Message Object 161 Data Register Low Low
#define CAN_MODATA161LL        (*((uword volatile far *) 0x202430))

// Message Object 162 Data Register High High
#define CAN_MODATA162HH        (*((uword volatile far *) 0x202456))

// Message Object 162 Data Register High Low
#define CAN_MODATA162HL        (*((uword volatile far *) 0x202454))

// Message Object 162 Data Register Low High
#define CAN_MODATA162LH        (*((uword volatile far *) 0x202452))

// Message Object 162 Data Register Low Low
#define CAN_MODATA162LL        (*((uword volatile far *) 0x202450))

// Message Object 163 Data Register High High
#define CAN_MODATA163HH        (*((uword volatile far *) 0x202476))

// Message Object 163 Data Register High Low
#define CAN_MODATA163HL        (*((uword volatile far *) 0x202474))

// Message Object 163 Data Register Low High
#define CAN_MODATA163LH        (*((uword volatile far *) 0x202472))

// Message Object 163 Data Register Low Low
#define CAN_MODATA163LL        (*((uword volatile far *) 0x202470))

// Message Object 164 Data Register High High
#define CAN_MODATA164HH        (*((uword volatile far *) 0x202496))

// Message Object 164 Data Register High Low
#define CAN_MODATA164HL        (*((uword volatile far *) 0x202494))

// Message Object 164 Data Register Low High
#define CAN_MODATA164LH        (*((uword volatile far *) 0x202492))

// Message Object 164 Data Register Low Low
#define CAN_MODATA164LL        (*((uword volatile far *) 0x202490))

// Message Object 165 Data Register High High
#define CAN_MODATA165HH        (*((uword volatile far *) 0x2024B6))

// Message Object 165 Data Register High Low
#define CAN_MODATA165HL        (*((uword volatile far *) 0x2024B4))

// Message Object 165 Data Register Low High
#define CAN_MODATA165LH        (*((uword volatile far *) 0x2024B2))

// Message Object 165 Data Register Low Low
#define CAN_MODATA165LL        (*((uword volatile far *) 0x2024B0))

// Message Object 166 Data Register High High
#define CAN_MODATA166HH        (*((uword volatile far *) 0x2024D6))

// Message Object 166 Data Register High Low
#define CAN_MODATA166HL        (*((uword volatile far *) 0x2024D4))

// Message Object 166 Data Register Low High
#define CAN_MODATA166LH        (*((uword volatile far *) 0x2024D2))

// Message Object 166 Data Register Low Low
#define CAN_MODATA166LL        (*((uword volatile far *) 0x2024D0))

// Message Object 167 Data Register High High
#define CAN_MODATA167HH        (*((uword volatile far *) 0x2024F6))

// Message Object 167 Data Register High Low
#define CAN_MODATA167HL        (*((uword volatile far *) 0x2024F4))

// Message Object 167 Data Register Low High
#define CAN_MODATA167LH        (*((uword volatile far *) 0x2024F2))

// Message Object 167 Data Register Low Low
#define CAN_MODATA167LL        (*((uword volatile far *) 0x2024F0))

// Message Object 168 Data Register High High
#define CAN_MODATA168HH        (*((uword volatile far *) 0x202516))

// Message Object 168 Data Register High Low
#define CAN_MODATA168HL        (*((uword volatile far *) 0x202514))

// Message Object 168 Data Register Low High
#define CAN_MODATA168LH        (*((uword volatile far *) 0x202512))

// Message Object 168 Data Register Low Low
#define CAN_MODATA168LL        (*((uword volatile far *) 0x202510))

// Message Object 169 Data Register High High
#define CAN_MODATA169HH        (*((uword volatile far *) 0x202536))

// Message Object 169 Data Register High Low
#define CAN_MODATA169HL        (*((uword volatile far *) 0x202534))

// Message Object 169 Data Register Low High
#define CAN_MODATA169LH        (*((uword volatile far *) 0x202532))

// Message Object 169 Data Register Low Low
#define CAN_MODATA169LL        (*((uword volatile far *) 0x202530))

// Message Object 16 Data Register High High
#define CAN_MODATA16HH         (*((uword volatile far *) 0x201216))

// Message Object 16 Data Register High Low
#define CAN_MODATA16HL         (*((uword volatile far *) 0x201214))

// Message Object 16 Data Register Low High
#define CAN_MODATA16LH         (*((uword volatile far *) 0x201212))

// Message Object 16 Data Register Low Low
#define CAN_MODATA16LL         (*((uword volatile far *) 0x201210))

// Message Object 170 Data Register High High
#define CAN_MODATA170HH        (*((uword volatile far *) 0x202556))

// Message Object 170 Data Register High Low
#define CAN_MODATA170HL        (*((uword volatile far *) 0x202554))

// Message Object 170 Data Register Low High
#define CAN_MODATA170LH        (*((uword volatile far *) 0x202552))

// Message Object 170 Data Register Low Low
#define CAN_MODATA170LL        (*((uword volatile far *) 0x202550))

// Message Object 171 Data Register High High
#define CAN_MODATA171HH        (*((uword volatile far *) 0x202576))

// Message Object 171 Data Register High Low
#define CAN_MODATA171HL        (*((uword volatile far *) 0x202574))

// Message Object 171 Data Register Low High
#define CAN_MODATA171LH        (*((uword volatile far *) 0x202572))

// Message Object 171 Data Register Low Low
#define CAN_MODATA171LL        (*((uword volatile far *) 0x202570))

// Message Object 172 Data Register High High
#define CAN_MODATA172HH        (*((uword volatile far *) 0x202596))

// Message Object 172 Data Register High Low
#define CAN_MODATA172HL        (*((uword volatile far *) 0x202594))

// Message Object 172 Data Register Low High
#define CAN_MODATA172LH        (*((uword volatile far *) 0x202592))

// Message Object 172 Data Register Low Low
#define CAN_MODATA172LL        (*((uword volatile far *) 0x202590))

// Message Object 173 Data Register High High
#define CAN_MODATA173HH        (*((uword volatile far *) 0x2025B6))

// Message Object 173 Data Register High Low
#define CAN_MODATA173HL        (*((uword volatile far *) 0x2025B4))

// Message Object 173 Data Register Low High
#define CAN_MODATA173LH        (*((uword volatile far *) 0x2025B2))

// Message Object 173 Data Register Low Low
#define CAN_MODATA173LL        (*((uword volatile far *) 0x2025B0))

// Message Object 174 Data Register High High
#define CAN_MODATA174HH        (*((uword volatile far *) 0x2025D6))

// Message Object 174 Data Register High Low
#define CAN_MODATA174HL        (*((uword volatile far *) 0x2025D4))

// Message Object 174 Data Register Low High
#define CAN_MODATA174LH        (*((uword volatile far *) 0x2025D2))

// Message Object 174 Data Register Low Low
#define CAN_MODATA174LL        (*((uword volatile far *) 0x2025D0))

// Message Object 175 Data Register High High
#define CAN_MODATA175HH        (*((uword volatile far *) 0x2025F6))

// Message Object 175 Data Register High Low
#define CAN_MODATA175HL        (*((uword volatile far *) 0x2025F4))

// Message Object 175 Data Register Low High
#define CAN_MODATA175LH        (*((uword volatile far *) 0x2025F2))

// Message Object 175 Data Register Low Low
#define CAN_MODATA175LL        (*((uword volatile far *) 0x2025F0))

// Message Object 176 Data Register High High
#define CAN_MODATA176HH        (*((uword volatile far *) 0x202616))

// Message Object 176 Data Register High Low
#define CAN_MODATA176HL        (*((uword volatile far *) 0x202614))

// Message Object 176 Data Register Low High
#define CAN_MODATA176LH        (*((uword volatile far *) 0x202612))

// Message Object 176 Data Register Low Low
#define CAN_MODATA176LL        (*((uword volatile far *) 0x202610))

// Message Object 177 Data Register High High
#define CAN_MODATA177HH        (*((uword volatile far *) 0x202636))

// Message Object 177 Data Register High Low
#define CAN_MODATA177HL        (*((uword volatile far *) 0x202634))

// Message Object 177 Data Register Low High
#define CAN_MODATA177LH        (*((uword volatile far *) 0x202632))

// Message Object 177 Data Register Low Low
#define CAN_MODATA177LL        (*((uword volatile far *) 0x202630))

// Message Object 178 Data Register High High
#define CAN_MODATA178HH        (*((uword volatile far *) 0x202656))

// Message Object 178 Data Register High Low
#define CAN_MODATA178HL        (*((uword volatile far *) 0x202654))

// Message Object 178 Data Register Low High
#define CAN_MODATA178LH        (*((uword volatile far *) 0x202652))

// Message Object 178 Data Register Low Low
#define CAN_MODATA178LL        (*((uword volatile far *) 0x202650))

// Message Object 179 Data Register High High
#define CAN_MODATA179HH        (*((uword volatile far *) 0x202676))

// Message Object 179 Data Register High Low
#define CAN_MODATA179HL        (*((uword volatile far *) 0x202674))

// Message Object 179 Data Register Low High
#define CAN_MODATA179LH        (*((uword volatile far *) 0x202672))

// Message Object 179 Data Register Low Low
#define CAN_MODATA179LL        (*((uword volatile far *) 0x202670))

// Message Object 17 Data Register High High
#define CAN_MODATA17HH         (*((uword volatile far *) 0x201236))

// Message Object 17 Data Register High Low
#define CAN_MODATA17HL         (*((uword volatile far *) 0x201234))

// Message Object 17 Data Register Low High
#define CAN_MODATA17LH         (*((uword volatile far *) 0x201232))

// Message Object 17 Data Register Low Low
#define CAN_MODATA17LL         (*((uword volatile far *) 0x201230))

// Message Object 180 Data Register High High
#define CAN_MODATA180HH        (*((uword volatile far *) 0x202696))

// Message Object 180 Data Register High Low
#define CAN_MODATA180HL        (*((uword volatile far *) 0x202694))

// Message Object 180 Data Register Low High
#define CAN_MODATA180LH        (*((uword volatile far *) 0x202692))

// Message Object 180 Data Register Low Low
#define CAN_MODATA180LL        (*((uword volatile far *) 0x202690))

// Message Object 181 Data Register High High
#define CAN_MODATA181HH        (*((uword volatile far *) 0x2026B6))

// Message Object 181 Data Register High Low
#define CAN_MODATA181HL        (*((uword volatile far *) 0x2026B4))

// Message Object 181 Data Register Low High
#define CAN_MODATA181LH        (*((uword volatile far *) 0x2026B2))

// Message Object 181 Data Register Low Low
#define CAN_MODATA181LL        (*((uword volatile far *) 0x2026B0))

// Message Object 182 Data Register High High
#define CAN_MODATA182HH        (*((uword volatile far *) 0x2026D6))

// Message Object 182 Data Register High Low
#define CAN_MODATA182HL        (*((uword volatile far *) 0x2026D4))

// Message Object 182 Data Register Low High
#define CAN_MODATA182LH        (*((uword volatile far *) 0x2026D2))

// Message Object 182 Data Register Low Low
#define CAN_MODATA182LL        (*((uword volatile far *) 0x2026D0))

// Message Object 183 Data Register High High
#define CAN_MODATA183HH        (*((uword volatile far *) 0x2026F6))

// Message Object 183 Data Register High Low
#define CAN_MODATA183HL        (*((uword volatile far *) 0x2026F4))

// Message Object 183 Data Register Low High
#define CAN_MODATA183LH        (*((uword volatile far *) 0x2026F2))

// Message Object 183 Data Register Low Low
#define CAN_MODATA183LL        (*((uword volatile far *) 0x2026F0))

// Message Object 184 Data Register High High
#define CAN_MODATA184HH        (*((uword volatile far *) 0x202716))

// Message Object 184 Data Register High Low
#define CAN_MODATA184HL        (*((uword volatile far *) 0x202714))

// Message Object 184 Data Register Low High
#define CAN_MODATA184LH        (*((uword volatile far *) 0x202712))

// Message Object 184 Data Register Low Low
#define CAN_MODATA184LL        (*((uword volatile far *) 0x202710))

// Message Object 185 Data Register High High
#define CAN_MODATA185HH        (*((uword volatile far *) 0x202736))

// Message Object 185 Data Register High Low
#define CAN_MODATA185HL        (*((uword volatile far *) 0x202734))

// Message Object 185 Data Register Low High
#define CAN_MODATA185LH        (*((uword volatile far *) 0x202732))

// Message Object 185 Data Register Low Low
#define CAN_MODATA185LL        (*((uword volatile far *) 0x202730))

// Message Object 186 Data Register High High
#define CAN_MODATA186HH        (*((uword volatile far *) 0x202756))

// Message Object 186 Data Register High Low
#define CAN_MODATA186HL        (*((uword volatile far *) 0x202754))

// Message Object 186 Data Register Low High
#define CAN_MODATA186LH        (*((uword volatile far *) 0x202752))

// Message Object 186 Data Register Low Low
#define CAN_MODATA186LL        (*((uword volatile far *) 0x202750))

// Message Object 187 Data Register High High
#define CAN_MODATA187HH        (*((uword volatile far *) 0x202776))

// Message Object 187 Data Register High Low
#define CAN_MODATA187HL        (*((uword volatile far *) 0x202774))

// Message Object 187 Data Register Low High
#define CAN_MODATA187LH        (*((uword volatile far *) 0x202772))

// Message Object 187 Data Register Low Low
#define CAN_MODATA187LL        (*((uword volatile far *) 0x202770))

// Message Object 188 Data Register High High
#define CAN_MODATA188HH        (*((uword volatile far *) 0x202796))

// Message Object 188 Data Register High Low
#define CAN_MODATA188HL        (*((uword volatile far *) 0x202794))

// Message Object 188 Data Register Low High
#define CAN_MODATA188LH        (*((uword volatile far *) 0x202792))

// Message Object 188 Data Register Low Low
#define CAN_MODATA188LL        (*((uword volatile far *) 0x202790))

// Message Object 189 Data Register High High
#define CAN_MODATA189HH        (*((uword volatile far *) 0x2027B6))

// Message Object 189 Data Register High Low
#define CAN_MODATA189HL        (*((uword volatile far *) 0x2027B4))

// Message Object 189 Data Register Low High
#define CAN_MODATA189LH        (*((uword volatile far *) 0x2027B2))

// Message Object 189 Data Register Low Low
#define CAN_MODATA189LL        (*((uword volatile far *) 0x2027B0))

// Message Object 18 Data Register High High
#define CAN_MODATA18HH         (*((uword volatile far *) 0x201256))

// Message Object 18 Data Register High Low
#define CAN_MODATA18HL         (*((uword volatile far *) 0x201254))

// Message Object 18 Data Register Low High
#define CAN_MODATA18LH         (*((uword volatile far *) 0x201252))

// Message Object 18 Data Register Low Low
#define CAN_MODATA18LL         (*((uword volatile far *) 0x201250))

// Message Object 190 Data Register High High
#define CAN_MODATA190HH        (*((uword volatile far *) 0x2027D6))

// Message Object 190 Data Register High Low
#define CAN_MODATA190HL        (*((uword volatile far *) 0x2027D4))

// Message Object 190 Data Register Low High
#define CAN_MODATA190LH        (*((uword volatile far *) 0x2027D2))

// Message Object 190 Data Register Low Low
#define CAN_MODATA190LL        (*((uword volatile far *) 0x2027D0))

// Message Object 191 Data Register High High
#define CAN_MODATA191HH        (*((uword volatile far *) 0x2027F6))

// Message Object 191 Data Register High Low
#define CAN_MODATA191HL        (*((uword volatile far *) 0x2027F4))

// Message Object 191 Data Register Low High
#define CAN_MODATA191LH        (*((uword volatile far *) 0x2027F2))

// Message Object 191 Data Register Low Low
#define CAN_MODATA191LL        (*((uword volatile far *) 0x2027F0))

// Message Object 192 Data Register High High
#define CAN_MODATA192HH        (*((uword volatile far *) 0x202816))

// Message Object 192 Data Register High Low
#define CAN_MODATA192HL        (*((uword volatile far *) 0x202814))

// Message Object 192 Data Register Low High
#define CAN_MODATA192LH        (*((uword volatile far *) 0x202812))

// Message Object 192 Data Register Low Low
#define CAN_MODATA192LL        (*((uword volatile far *) 0x202810))

// Message Object 193 Data Register High High
#define CAN_MODATA193HH        (*((uword volatile far *) 0x202836))

// Message Object 193 Data Register High Low
#define CAN_MODATA193HL        (*((uword volatile far *) 0x202834))

// Message Object 193 Data Register Low High
#define CAN_MODATA193LH        (*((uword volatile far *) 0x202832))

// Message Object 193 Data Register Low Low
#define CAN_MODATA193LL        (*((uword volatile far *) 0x202830))

// Message Object 194 Data Register High High
#define CAN_MODATA194HH        (*((uword volatile far *) 0x202856))

// Message Object 194 Data Register High Low
#define CAN_MODATA194HL        (*((uword volatile far *) 0x202854))

// Message Object 194 Data Register Low High
#define CAN_MODATA194LH        (*((uword volatile far *) 0x202852))

// Message Object 194 Data Register Low Low
#define CAN_MODATA194LL        (*((uword volatile far *) 0x202850))

// Message Object 195 Data Register High High
#define CAN_MODATA195HH        (*((uword volatile far *) 0x202876))

// Message Object 195 Data Register High Low
#define CAN_MODATA195HL        (*((uword volatile far *) 0x202874))

// Message Object 195 Data Register Low High
#define CAN_MODATA195LH        (*((uword volatile far *) 0x202872))

// Message Object 195 Data Register Low Low
#define CAN_MODATA195LL        (*((uword volatile far *) 0x202870))

// Message Object 196 Data Register High High
#define CAN_MODATA196HH        (*((uword volatile far *) 0x202896))

// Message Object 196 Data Register High Low
#define CAN_MODATA196HL        (*((uword volatile far *) 0x202894))

// Message Object 196 Data Register Low High
#define CAN_MODATA196LH        (*((uword volatile far *) 0x202892))

// Message Object 196 Data Register Low Low
#define CAN_MODATA196LL        (*((uword volatile far *) 0x202890))

// Message Object 197 Data Register High High
#define CAN_MODATA197HH        (*((uword volatile far *) 0x2028B6))

// Message Object 197 Data Register High Low
#define CAN_MODATA197HL        (*((uword volatile far *) 0x2028B4))

// Message Object 197 Data Register Low High
#define CAN_MODATA197LH        (*((uword volatile far *) 0x2028B2))

// Message Object 197 Data Register Low Low
#define CAN_MODATA197LL        (*((uword volatile far *) 0x2028B0))

// Message Object 198 Data Register High High
#define CAN_MODATA198HH        (*((uword volatile far *) 0x2028D6))

// Message Object 198 Data Register High Low
#define CAN_MODATA198HL        (*((uword volatile far *) 0x2028D4))

// Message Object 198 Data Register Low High
#define CAN_MODATA198LH        (*((uword volatile far *) 0x2028D2))

// Message Object 198 Data Register Low Low
#define CAN_MODATA198LL        (*((uword volatile far *) 0x2028D0))

// Message Object 199 Data Register High High
#define CAN_MODATA199HH        (*((uword volatile far *) 0x2028F6))

// Message Object 199 Data Register High Low
#define CAN_MODATA199HL        (*((uword volatile far *) 0x2028F4))

// Message Object 199 Data Register Low High
#define CAN_MODATA199LH        (*((uword volatile far *) 0x2028F2))

// Message Object 199 Data Register Low Low
#define CAN_MODATA199LL        (*((uword volatile far *) 0x2028F0))

// Message Object 19 Data Register High High
#define CAN_MODATA19HH         (*((uword volatile far *) 0x201276))

// Message Object 19 Data Register High Low
#define CAN_MODATA19HL         (*((uword volatile far *) 0x201274))

// Message Object 19 Data Register Low High
#define CAN_MODATA19LH         (*((uword volatile far *) 0x201272))

// Message Object 19 Data Register Low Low
#define CAN_MODATA19LL         (*((uword volatile far *) 0x201270))

// Message Object 1 Data Register High High
#define CAN_MODATA1HH          (*((uword volatile far *) 0x201036))

// Message Object 1 Data Register High Low
#define CAN_MODATA1HL          (*((uword volatile far *) 0x201034))

// Message Object 1 Data Register Low High
#define CAN_MODATA1LH          (*((uword volatile far *) 0x201032))

// Message Object 1 Data Register Low Low
#define CAN_MODATA1LL          (*((uword volatile far *) 0x201030))

// Message Object 200 Data Register High High
#define CAN_MODATA200HH        (*((uword volatile far *) 0x202916))

// Message Object 200 Data Register High Low
#define CAN_MODATA200HL        (*((uword volatile far *) 0x202914))

// Message Object 200 Data Register Low High
#define CAN_MODATA200LH        (*((uword volatile far *) 0x202912))

// Message Object 200 Data Register Low Low
#define CAN_MODATA200LL        (*((uword volatile far *) 0x202910))

// Message Object 201 Data Register High High
#define CAN_MODATA201HH        (*((uword volatile far *) 0x202936))

// Message Object 201 Data Register High Low
#define CAN_MODATA201HL        (*((uword volatile far *) 0x202934))

// Message Object 201 Data Register Low High
#define CAN_MODATA201LH        (*((uword volatile far *) 0x202932))

// Message Object 201 Data Register Low Low
#define CAN_MODATA201LL        (*((uword volatile far *) 0x202930))

// Message Object 202 Data Register High High
#define CAN_MODATA202HH        (*((uword volatile far *) 0x202956))

// Message Object 202 Data Register High Low
#define CAN_MODATA202HL        (*((uword volatile far *) 0x202954))

// Message Object 202 Data Register Low High
#define CAN_MODATA202LH        (*((uword volatile far *) 0x202952))

// Message Object 202 Data Register Low Low
#define CAN_MODATA202LL        (*((uword volatile far *) 0x202950))

// Message Object 203 Data Register High High
#define CAN_MODATA203HH        (*((uword volatile far *) 0x202976))

// Message Object 203 Data Register High Low
#define CAN_MODATA203HL        (*((uword volatile far *) 0x202974))

// Message Object 203 Data Register Low High
#define CAN_MODATA203LH        (*((uword volatile far *) 0x202972))

// Message Object 203 Data Register Low Low
#define CAN_MODATA203LL        (*((uword volatile far *) 0x202970))

// Message Object 204 Data Register High High
#define CAN_MODATA204HH        (*((uword volatile far *) 0x202996))

// Message Object 204 Data Register High Low
#define CAN_MODATA204HL        (*((uword volatile far *) 0x202994))

// Message Object 204 Data Register Low High
#define CAN_MODATA204LH        (*((uword volatile far *) 0x202992))

// Message Object 204 Data Register Low Low
#define CAN_MODATA204LL        (*((uword volatile far *) 0x202990))

// Message Object 205 Data Register High High
#define CAN_MODATA205HH        (*((uword volatile far *) 0x2029B6))

// Message Object 205 Data Register High Low
#define CAN_MODATA205HL        (*((uword volatile far *) 0x2029B4))

// Message Object 205 Data Register Low High
#define CAN_MODATA205LH        (*((uword volatile far *) 0x2029B2))

// Message Object 205 Data Register Low Low
#define CAN_MODATA205LL        (*((uword volatile far *) 0x2029B0))

// Message Object 206 Data Register High High
#define CAN_MODATA206HH        (*((uword volatile far *) 0x2029D6))

// Message Object 206 Data Register High Low
#define CAN_MODATA206HL        (*((uword volatile far *) 0x2029D4))

// Message Object 206 Data Register Low High
#define CAN_MODATA206LH        (*((uword volatile far *) 0x2029D2))

// Message Object 206 Data Register Low Low
#define CAN_MODATA206LL        (*((uword volatile far *) 0x2029D0))

// Message Object 207 Data Register High High
#define CAN_MODATA207HH        (*((uword volatile far *) 0x2029F6))

// Message Object 207 Data Register High Low
#define CAN_MODATA207HL        (*((uword volatile far *) 0x2029F4))

// Message Object 207 Data Register Low High
#define CAN_MODATA207LH        (*((uword volatile far *) 0x2029F2))

// Message Object 207 Data Register Low Low
#define CAN_MODATA207LL        (*((uword volatile far *) 0x2029F0))

// Message Object 208 Data Register High High
#define CAN_MODATA208HH        (*((uword volatile far *) 0x202A16))

// Message Object 208 Data Register High Low
#define CAN_MODATA208HL        (*((uword volatile far *) 0x202A14))

// Message Object 208 Data Register Low High
#define CAN_MODATA208LH        (*((uword volatile far *) 0x202A12))

// Message Object 208 Data Register Low Low
#define CAN_MODATA208LL        (*((uword volatile far *) 0x202A10))

// Message Object 209 Data Register High High
#define CAN_MODATA209HH        (*((uword volatile far *) 0x202A36))

// Message Object 209 Data Register High Low
#define CAN_MODATA209HL        (*((uword volatile far *) 0x202A34))

// Message Object 209 Data Register Low High
#define CAN_MODATA209LH        (*((uword volatile far *) 0x202A32))

// Message Object 209 Data Register Low Low
#define CAN_MODATA209LL        (*((uword volatile far *) 0x202A30))

// Message Object 20 Data Register High High
#define CAN_MODATA20HH         (*((uword volatile far *) 0x201296))

// Message Object 20 Data Register High Low
#define CAN_MODATA20HL         (*((uword volatile far *) 0x201294))

// Message Object 20 Data Register Low High
#define CAN_MODATA20LH         (*((uword volatile far *) 0x201292))

// Message Object 20 Data Register Low Low
#define CAN_MODATA20LL         (*((uword volatile far *) 0x201290))

// Message Object 210 Data Register High High
#define CAN_MODATA210HH        (*((uword volatile far *) 0x202A56))

// Message Object 210 Data Register High Low
#define CAN_MODATA210HL        (*((uword volatile far *) 0x202A54))

// Message Object 210 Data Register Low High
#define CAN_MODATA210LH        (*((uword volatile far *) 0x202A52))

// Message Object 210 Data Register Low Low
#define CAN_MODATA210LL        (*((uword volatile far *) 0x202A50))

// Message Object 211 Data Register High High
#define CAN_MODATA211HH        (*((uword volatile far *) 0x202A76))

// Message Object 211 Data Register High Low
#define CAN_MODATA211HL        (*((uword volatile far *) 0x202A74))

// Message Object 211 Data Register Low High
#define CAN_MODATA211LH        (*((uword volatile far *) 0x202A72))

// Message Object 211 Data Register Low Low
#define CAN_MODATA211LL        (*((uword volatile far *) 0x202A70))

// Message Object 212 Data Register High High
#define CAN_MODATA212HH        (*((uword volatile far *) 0x202A96))

// Message Object 212 Data Register High Low
#define CAN_MODATA212HL        (*((uword volatile far *) 0x202A94))

// Message Object 212 Data Register Low High
#define CAN_MODATA212LH        (*((uword volatile far *) 0x202A92))

// Message Object 212 Data Register Low Low
#define CAN_MODATA212LL        (*((uword volatile far *) 0x202A90))

// Message Object 213 Data Register High High
#define CAN_MODATA213HH        (*((uword volatile far *) 0x202AB6))

// Message Object 213 Data Register High Low
#define CAN_MODATA213HL        (*((uword volatile far *) 0x202AB4))

// Message Object 213 Data Register Low High
#define CAN_MODATA213LH        (*((uword volatile far *) 0x202AB2))

// Message Object 213 Data Register Low Low
#define CAN_MODATA213LL        (*((uword volatile far *) 0x202AB0))

// Message Object 214 Data Register High High
#define CAN_MODATA214HH        (*((uword volatile far *) 0x202AD6))

// Message Object 214 Data Register High Low
#define CAN_MODATA214HL        (*((uword volatile far *) 0x202AD4))

// Message Object 214 Data Register Low High
#define CAN_MODATA214LH        (*((uword volatile far *) 0x202AD2))

// Message Object 214 Data Register Low Low
#define CAN_MODATA214LL        (*((uword volatile far *) 0x202AD0))

// Message Object 215 Data Register High High
#define CAN_MODATA215HH        (*((uword volatile far *) 0x202AF6))

// Message Object 215 Data Register High Low
#define CAN_MODATA215HL        (*((uword volatile far *) 0x202AF4))

// Message Object 215 Data Register Low High
#define CAN_MODATA215LH        (*((uword volatile far *) 0x202AF2))

// Message Object 215 Data Register Low Low
#define CAN_MODATA215LL        (*((uword volatile far *) 0x202AF0))

// Message Object 216 Data Register High High
#define CAN_MODATA216HH        (*((uword volatile far *) 0x202B16))

// Message Object 216 Data Register High Low
#define CAN_MODATA216HL        (*((uword volatile far *) 0x202B14))

// Message Object 216 Data Register Low High
#define CAN_MODATA216LH        (*((uword volatile far *) 0x202B12))

// Message Object 216 Data Register Low Low
#define CAN_MODATA216LL        (*((uword volatile far *) 0x202B10))

// Message Object 217 Data Register High High
#define CAN_MODATA217HH        (*((uword volatile far *) 0x202B36))

// Message Object 217 Data Register High Low
#define CAN_MODATA217HL        (*((uword volatile far *) 0x202B34))

// Message Object 217 Data Register Low High
#define CAN_MODATA217LH        (*((uword volatile far *) 0x202B32))

// Message Object 217 Data Register Low Low
#define CAN_MODATA217LL        (*((uword volatile far *) 0x202B30))

// Message Object 218 Data Register High High
#define CAN_MODATA218HH        (*((uword volatile far *) 0x202B56))

// Message Object 218 Data Register High Low
#define CAN_MODATA218HL        (*((uword volatile far *) 0x202B54))

// Message Object 218 Data Register Low High
#define CAN_MODATA218LH        (*((uword volatile far *) 0x202B52))

// Message Object 218 Data Register Low Low
#define CAN_MODATA218LL        (*((uword volatile far *) 0x202B50))

// Message Object 219 Data Register High High
#define CAN_MODATA219HH        (*((uword volatile far *) 0x202B76))

// Message Object 219 Data Register High Low
#define CAN_MODATA219HL        (*((uword volatile far *) 0x202B74))

// Message Object 219 Data Register Low High
#define CAN_MODATA219LH        (*((uword volatile far *) 0x202B72))

// Message Object 219 Data Register Low Low
#define CAN_MODATA219LL        (*((uword volatile far *) 0x202B70))

// Message Object 21 Data Register High High
#define CAN_MODATA21HH         (*((uword volatile far *) 0x2012B6))

// Message Object 21 Data Register High Low
#define CAN_MODATA21HL         (*((uword volatile far *) 0x2012B4))

// Message Object 21 Data Register Low High
#define CAN_MODATA21LH         (*((uword volatile far *) 0x2012B2))

// Message Object 21 Data Register Low Low
#define CAN_MODATA21LL         (*((uword volatile far *) 0x2012B0))

// Message Object 220 Data Register High High
#define CAN_MODATA220HH        (*((uword volatile far *) 0x202B96))

// Message Object 220 Data Register High Low
#define CAN_MODATA220HL        (*((uword volatile far *) 0x202B94))

// Message Object 220 Data Register Low High
#define CAN_MODATA220LH        (*((uword volatile far *) 0x202B92))

// Message Object 220 Data Register Low Low
#define CAN_MODATA220LL        (*((uword volatile far *) 0x202B90))

// Message Object 221 Data Register High High
#define CAN_MODATA221HH        (*((uword volatile far *) 0x202BB6))

// Message Object 221 Data Register High Low
#define CAN_MODATA221HL        (*((uword volatile far *) 0x202BB4))

// Message Object 221 Data Register Low High
#define CAN_MODATA221LH        (*((uword volatile far *) 0x202BB2))

// Message Object 221 Data Register Low Low
#define CAN_MODATA221LL        (*((uword volatile far *) 0x202BB0))

// Message Object 222 Data Register High High
#define CAN_MODATA222HH        (*((uword volatile far *) 0x202BD6))

// Message Object 222 Data Register High Low
#define CAN_MODATA222HL        (*((uword volatile far *) 0x202BD4))

// Message Object 222 Data Register Low High
#define CAN_MODATA222LH        (*((uword volatile far *) 0x202BD2))

// Message Object 222 Data Register Low Low
#define CAN_MODATA222LL        (*((uword volatile far *) 0x202BD0))

// Message Object 223 Data Register High High
#define CAN_MODATA223HH        (*((uword volatile far *) 0x202BF6))

// Message Object 223 Data Register High Low
#define CAN_MODATA223HL        (*((uword volatile far *) 0x202BF4))

// Message Object 223 Data Register Low High
#define CAN_MODATA223LH        (*((uword volatile far *) 0x202BF2))

// Message Object 223 Data Register Low Low
#define CAN_MODATA223LL        (*((uword volatile far *) 0x202BF0))

// Message Object 224 Data Register High High
#define CAN_MODATA224HH        (*((uword volatile far *) 0x202C16))

// Message Object 224 Data Register High Low
#define CAN_MODATA224HL        (*((uword volatile far *) 0x202C14))

// Message Object 224 Data Register Low High
#define CAN_MODATA224LH        (*((uword volatile far *) 0x202C12))

// Message Object 224 Data Register Low Low
#define CAN_MODATA224LL        (*((uword volatile far *) 0x202C10))

// Message Object 225 Data Register High High
#define CAN_MODATA225HH        (*((uword volatile far *) 0x202C36))

// Message Object 225 Data Register High Low
#define CAN_MODATA225HL        (*((uword volatile far *) 0x202C34))

// Message Object 225 Data Register Low High
#define CAN_MODATA225LH        (*((uword volatile far *) 0x202C32))

// Message Object 225 Data Register Low Low
#define CAN_MODATA225LL        (*((uword volatile far *) 0x202C30))

// Message Object 226 Data Register High High
#define CAN_MODATA226HH        (*((uword volatile far *) 0x202C56))

// Message Object 226 Data Register High Low
#define CAN_MODATA226HL        (*((uword volatile far *) 0x202C54))

// Message Object 226 Data Register Low High
#define CAN_MODATA226LH        (*((uword volatile far *) 0x202C52))

// Message Object 226 Data Register Low Low
#define CAN_MODATA226LL        (*((uword volatile far *) 0x202C50))

// Message Object 227 Data Register High High
#define CAN_MODATA227HH        (*((uword volatile far *) 0x202C76))

// Message Object 227 Data Register High Low
#define CAN_MODATA227HL        (*((uword volatile far *) 0x202C74))

// Message Object 227 Data Register Low High
#define CAN_MODATA227LH        (*((uword volatile far *) 0x202C72))

// Message Object 227 Data Register Low Low
#define CAN_MODATA227LL        (*((uword volatile far *) 0x202C70))

// Message Object 228 Data Register High High
#define CAN_MODATA228HH        (*((uword volatile far *) 0x202C96))

// Message Object 228 Data Register High Low
#define CAN_MODATA228HL        (*((uword volatile far *) 0x202C94))

// Message Object 228 Data Register Low High
#define CAN_MODATA228LH        (*((uword volatile far *) 0x202C92))

// Message Object 228 Data Register Low Low
#define CAN_MODATA228LL        (*((uword volatile far *) 0x202C90))

// Message Object 229 Data Register High High
#define CAN_MODATA229HH        (*((uword volatile far *) 0x202CB6))

// Message Object 229 Data Register High Low
#define CAN_MODATA229HL        (*((uword volatile far *) 0x202CB4))

// Message Object 229 Data Register Low High
#define CAN_MODATA229LH        (*((uword volatile far *) 0x202CB2))

// Message Object 229 Data Register Low Low
#define CAN_MODATA229LL        (*((uword volatile far *) 0x202CB0))

// Message Object 22 Data Register High High
#define CAN_MODATA22HH         (*((uword volatile far *) 0x2012D6))

// Message Object 22 Data Register High Low
#define CAN_MODATA22HL         (*((uword volatile far *) 0x2012D4))

// Message Object 22 Data Register Low High
#define CAN_MODATA22LH         (*((uword volatile far *) 0x2012D2))

// Message Object 22 Data Register Low Low
#define CAN_MODATA22LL         (*((uword volatile far *) 0x2012D0))

// Message Object 230 Data Register High High
#define CAN_MODATA230HH        (*((uword volatile far *) 0x202CD6))

// Message Object 230 Data Register High Low
#define CAN_MODATA230HL        (*((uword volatile far *) 0x202CD4))

// Message Object 230 Data Register Low High
#define CAN_MODATA230LH        (*((uword volatile far *) 0x202CD2))

// Message Object 230 Data Register Low Low
#define CAN_MODATA230LL        (*((uword volatile far *) 0x202CD0))

// Message Object 231 Data Register High High
#define CAN_MODATA231HH        (*((uword volatile far *) 0x202CF6))

// Message Object 231 Data Register High Low
#define CAN_MODATA231HL        (*((uword volatile far *) 0x202CF4))

// Message Object 231 Data Register Low High
#define CAN_MODATA231LH        (*((uword volatile far *) 0x202CF2))

// Message Object 231 Data Register Low Low
#define CAN_MODATA231LL        (*((uword volatile far *) 0x202CF0))

// Message Object 232 Data Register High High
#define CAN_MODATA232HH        (*((uword volatile far *) 0x202D16))

// Message Object 232 Data Register High Low
#define CAN_MODATA232HL        (*((uword volatile far *) 0x202D14))

// Message Object 232 Data Register Low High
#define CAN_MODATA232LH        (*((uword volatile far *) 0x202D12))

// Message Object 232 Data Register Low Low
#define CAN_MODATA232LL        (*((uword volatile far *) 0x202D10))

// Message Object 233 Data Register High High
#define CAN_MODATA233HH        (*((uword volatile far *) 0x202D36))

// Message Object 233 Data Register High Low
#define CAN_MODATA233HL        (*((uword volatile far *) 0x202D34))

// Message Object 233 Data Register Low High
#define CAN_MODATA233LH        (*((uword volatile far *) 0x202D32))

// Message Object 233 Data Register Low Low
#define CAN_MODATA233LL        (*((uword volatile far *) 0x202D30))

// Message Object 234 Data Register High High
#define CAN_MODATA234HH        (*((uword volatile far *) 0x202D56))

// Message Object 234 Data Register High Low
#define CAN_MODATA234HL        (*((uword volatile far *) 0x202D54))

// Message Object 234 Data Register Low High
#define CAN_MODATA234LH        (*((uword volatile far *) 0x202D52))

// Message Object 234 Data Register Low Low
#define CAN_MODATA234LL        (*((uword volatile far *) 0x202D50))

// Message Object 235 Data Register High High
#define CAN_MODATA235HH        (*((uword volatile far *) 0x202D76))

// Message Object 235 Data Register High Low
#define CAN_MODATA235HL        (*((uword volatile far *) 0x202D74))

// Message Object 235 Data Register Low High
#define CAN_MODATA235LH        (*((uword volatile far *) 0x202D72))

// Message Object 235 Data Register Low Low
#define CAN_MODATA235LL        (*((uword volatile far *) 0x202D70))

// Message Object 236 Data Register High High
#define CAN_MODATA236HH        (*((uword volatile far *) 0x202D96))

// Message Object 236 Data Register High Low
#define CAN_MODATA236HL        (*((uword volatile far *) 0x202D94))

// Message Object 236 Data Register Low High
#define CAN_MODATA236LH        (*((uword volatile far *) 0x202D92))

// Message Object 236 Data Register Low Low
#define CAN_MODATA236LL        (*((uword volatile far *) 0x202D90))

// Message Object 237 Data Register High High
#define CAN_MODATA237HH        (*((uword volatile far *) 0x202DB6))

// Message Object 237 Data Register High Low
#define CAN_MODATA237HL        (*((uword volatile far *) 0x202DB4))

// Message Object 237 Data Register Low High
#define CAN_MODATA237LH        (*((uword volatile far *) 0x202DB2))

// Message Object 237 Data Register Low Low
#define CAN_MODATA237LL        (*((uword volatile far *) 0x202DB0))

// Message Object 238 Data Register High High
#define CAN_MODATA238HH        (*((uword volatile far *) 0x202DD6))

// Message Object 238 Data Register High Low
#define CAN_MODATA238HL        (*((uword volatile far *) 0x202DD4))

// Message Object 238 Data Register Low High
#define CAN_MODATA238LH        (*((uword volatile far *) 0x202DD2))

// Message Object 238 Data Register Low Low
#define CAN_MODATA238LL        (*((uword volatile far *) 0x202DD0))

// Message Object 239 Data Register High High
#define CAN_MODATA239HH        (*((uword volatile far *) 0x202DF6))

// Message Object 239 Data Register High Low
#define CAN_MODATA239HL        (*((uword volatile far *) 0x202DF4))

// Message Object 239 Data Register Low High
#define CAN_MODATA239LH        (*((uword volatile far *) 0x202DF2))

// Message Object 239 Data Register Low Low
#define CAN_MODATA239LL        (*((uword volatile far *) 0x202DF0))

// Message Object 23 Data Register High High
#define CAN_MODATA23HH         (*((uword volatile far *) 0x2012F6))

// Message Object 23 Data Register High Low
#define CAN_MODATA23HL         (*((uword volatile far *) 0x2012F4))

// Message Object 23 Data Register Low High
#define CAN_MODATA23LH         (*((uword volatile far *) 0x2012F2))

// Message Object 23 Data Register Low Low
#define CAN_MODATA23LL         (*((uword volatile far *) 0x2012F0))

// Message Object 240 Data Register High High
#define CAN_MODATA240HH        (*((uword volatile far *) 0x202E16))

// Message Object 240 Data Register High Low
#define CAN_MODATA240HL        (*((uword volatile far *) 0x202E14))

// Message Object 240 Data Register Low High
#define CAN_MODATA240LH        (*((uword volatile far *) 0x202E12))

// Message Object 240 Data Register Low Low
#define CAN_MODATA240LL        (*((uword volatile far *) 0x202E10))

// Message Object 241 Data Register High High
#define CAN_MODATA241HH        (*((uword volatile far *) 0x202E36))

// Message Object 241 Data Register High Low
#define CAN_MODATA241HL        (*((uword volatile far *) 0x202E34))

// Message Object 241 Data Register Low High
#define CAN_MODATA241LH        (*((uword volatile far *) 0x202E32))

// Message Object 241 Data Register Low Low
#define CAN_MODATA241LL        (*((uword volatile far *) 0x202E30))

// Message Object 242 Data Register High High
#define CAN_MODATA242HH        (*((uword volatile far *) 0x202E56))

// Message Object 242 Data Register High Low
#define CAN_MODATA242HL        (*((uword volatile far *) 0x202E54))

// Message Object 242 Data Register Low High
#define CAN_MODATA242LH        (*((uword volatile far *) 0x202E52))

// Message Object 242 Data Register Low Low
#define CAN_MODATA242LL        (*((uword volatile far *) 0x202E50))

// Message Object 243 Data Register High High
#define CAN_MODATA243HH        (*((uword volatile far *) 0x202E76))

// Message Object 243 Data Register High Low
#define CAN_MODATA243HL        (*((uword volatile far *) 0x202E74))

// Message Object 243 Data Register Low High
#define CAN_MODATA243LH        (*((uword volatile far *) 0x202E72))

// Message Object 243 Data Register Low Low
#define CAN_MODATA243LL        (*((uword volatile far *) 0x202E70))

// Message Object 244 Data Register High High
#define CAN_MODATA244HH        (*((uword volatile far *) 0x202E96))

// Message Object 244 Data Register High Low
#define CAN_MODATA244HL        (*((uword volatile far *) 0x202E94))

// Message Object 244 Data Register Low High
#define CAN_MODATA244LH        (*((uword volatile far *) 0x202E92))

// Message Object 244 Data Register Low Low
#define CAN_MODATA244LL        (*((uword volatile far *) 0x202E90))

// Message Object 245 Data Register High High
#define CAN_MODATA245HH        (*((uword volatile far *) 0x202EB6))

// Message Object 245 Data Register High Low
#define CAN_MODATA245HL        (*((uword volatile far *) 0x202EB4))

// Message Object 245 Data Register Low High
#define CAN_MODATA245LH        (*((uword volatile far *) 0x202EB2))

// Message Object 245 Data Register Low Low
#define CAN_MODATA245LL        (*((uword volatile far *) 0x202EB0))

// Message Object 246 Data Register High High
#define CAN_MODATA246HH        (*((uword volatile far *) 0x202ED6))

// Message Object 246 Data Register High Low
#define CAN_MODATA246HL        (*((uword volatile far *) 0x202ED4))

// Message Object 246 Data Register Low High
#define CAN_MODATA246LH        (*((uword volatile far *) 0x202ED2))

// Message Object 246 Data Register Low Low
#define CAN_MODATA246LL        (*((uword volatile far *) 0x202ED0))

// Message Object 247 Data Register High High
#define CAN_MODATA247HH        (*((uword volatile far *) 0x202EF6))

// Message Object 247 Data Register High Low
#define CAN_MODATA247HL        (*((uword volatile far *) 0x202EF4))

// Message Object 247 Data Register Low High
#define CAN_MODATA247LH        (*((uword volatile far *) 0x202EF2))

// Message Object 247 Data Register Low Low
#define CAN_MODATA247LL        (*((uword volatile far *) 0x202EF0))

// Message Object 248 Data Register High High
#define CAN_MODATA248HH        (*((uword volatile far *) 0x202F16))

// Message Object 248 Data Register High Low
#define CAN_MODATA248HL        (*((uword volatile far *) 0x202F14))

// Message Object 248 Data Register Low High
#define CAN_MODATA248LH        (*((uword volatile far *) 0x202F12))

// Message Object 248 Data Register Low Low
#define CAN_MODATA248LL        (*((uword volatile far *) 0x202F10))

// Message Object 249 Data Register High High
#define CAN_MODATA249HH        (*((uword volatile far *) 0x202F36))

// Message Object 249 Data Register High Low
#define CAN_MODATA249HL        (*((uword volatile far *) 0x202F34))

// Message Object 249 Data Register Low High
#define CAN_MODATA249LH        (*((uword volatile far *) 0x202F32))

// Message Object 249 Data Register Low Low
#define CAN_MODATA249LL        (*((uword volatile far *) 0x202F30))

// Message Object 24 Data Register High High
#define CAN_MODATA24HH         (*((uword volatile far *) 0x201316))

// Message Object 24 Data Register High Low
#define CAN_MODATA24HL         (*((uword volatile far *) 0x201314))

// Message Object 24 Data Register Low High
#define CAN_MODATA24LH         (*((uword volatile far *) 0x201312))

// Message Object 24 Data Register Low Low
#define CAN_MODATA24LL         (*((uword volatile far *) 0x201310))

// Message Object 250 Data Register High High
#define CAN_MODATA250HH        (*((uword volatile far *) 0x202F56))

// Message Object 250 Data Register High Low
#define CAN_MODATA250HL        (*((uword volatile far *) 0x202F54))

// Message Object 250 Data Register Low High
#define CAN_MODATA250LH        (*((uword volatile far *) 0x202F52))

// Message Object 250 Data Register Low Low
#define CAN_MODATA250LL        (*((uword volatile far *) 0x202F50))

// Message Object 251 Data Register High High
#define CAN_MODATA251HH        (*((uword volatile far *) 0x202F76))

// Message Object 251 Data Register High Low
#define CAN_MODATA251HL        (*((uword volatile far *) 0x202F74))

// Message Object 251 Data Register Low High
#define CAN_MODATA251LH        (*((uword volatile far *) 0x202F72))

// Message Object 251 Data Register Low Low
#define CAN_MODATA251LL        (*((uword volatile far *) 0x202F70))

// Message Object 252 Data Register High High
#define CAN_MODATA252HH        (*((uword volatile far *) 0x202F96))

// Message Object 252 Data Register High Low
#define CAN_MODATA252HL        (*((uword volatile far *) 0x202F94))

// Message Object 252 Data Register Low High
#define CAN_MODATA252LH        (*((uword volatile far *) 0x202F92))

// Message Object 252 Data Register Low Low
#define CAN_MODATA252LL        (*((uword volatile far *) 0x202F90))

// Message Object 253 Data Register High High
#define CAN_MODATA253HH        (*((uword volatile far *) 0x202FB6))

// Message Object 253 Data Register High Low
#define CAN_MODATA253HL        (*((uword volatile far *) 0x202FB4))

// Message Object 253 Data Register Low High
#define CAN_MODATA253LH        (*((uword volatile far *) 0x202FB2))

// Message Object 253 Data Register Low Low
#define CAN_MODATA253LL        (*((uword volatile far *) 0x202FB0))

// Message Object 254 Data Register High High
#define CAN_MODATA254HH        (*((uword volatile far *) 0x202FD6))

// Message Object 254 Data Register High Low
#define CAN_MODATA254HL        (*((uword volatile far *) 0x202FD4))

// Message Object 254 Data Register Low High
#define CAN_MODATA254LH        (*((uword volatile far *) 0x202FD2))

// Message Object 254 Data Register Low Low
#define CAN_MODATA254LL        (*((uword volatile far *) 0x202FD0))

// Message Object 255 Data Register High High
#define CAN_MODATA255HH        (*((uword volatile far *) 0x202FF6))

// Message Object 255 Data Register High Low
#define CAN_MODATA255HL        (*((uword volatile far *) 0x202FF4))

// Message Object 255 Data Register Low High
#define CAN_MODATA255LH        (*((uword volatile far *) 0x202FF2))

// Message Object 255 Data Register Low Low
#define CAN_MODATA255LL        (*((uword volatile far *) 0x202FF0))

// Message Object 25 Data Register High High
#define CAN_MODATA25HH         (*((uword volatile far *) 0x201336))

// Message Object 25 Data Register High Low
#define CAN_MODATA25HL         (*((uword volatile far *) 0x201334))

// Message Object 25 Data Register Low High
#define CAN_MODATA25LH         (*((uword volatile far *) 0x201332))

// Message Object 25 Data Register Low Low
#define CAN_MODATA25LL         (*((uword volatile far *) 0x201330))

// Message Object 26 Data Register High High
#define CAN_MODATA26HH         (*((uword volatile far *) 0x201356))

// Message Object 26 Data Register High Low
#define CAN_MODATA26HL         (*((uword volatile far *) 0x201354))

// Message Object 26 Data Register Low High
#define CAN_MODATA26LH         (*((uword volatile far *) 0x201352))

// Message Object 26 Data Register Low Low
#define CAN_MODATA26LL         (*((uword volatile far *) 0x201350))

// Message Object 27 Data Register High High
#define CAN_MODATA27HH         (*((uword volatile far *) 0x201376))

// Message Object 27 Data Register High Low
#define CAN_MODATA27HL         (*((uword volatile far *) 0x201374))

// Message Object 27 Data Register Low High
#define CAN_MODATA27LH         (*((uword volatile far *) 0x201372))

// Message Object 27 Data Register Low Low
#define CAN_MODATA27LL         (*((uword volatile far *) 0x201370))

// Message Object 28 Data Register High High
#define CAN_MODATA28HH         (*((uword volatile far *) 0x201396))

// Message Object 28 Data Register High Low
#define CAN_MODATA28HL         (*((uword volatile far *) 0x201394))

// Message Object 28 Data Register Low High
#define CAN_MODATA28LH         (*((uword volatile far *) 0x201392))

// Message Object 28 Data Register Low Low
#define CAN_MODATA28LL         (*((uword volatile far *) 0x201390))

// Message Object 29 Data Register High High
#define CAN_MODATA29HH         (*((uword volatile far *) 0x2013B6))

// Message Object 29 Data Register High Low
#define CAN_MODATA29HL         (*((uword volatile far *) 0x2013B4))

// Message Object 29 Data Register Low High
#define CAN_MODATA29LH         (*((uword volatile far *) 0x2013B2))

// Message Object 29 Data Register Low Low
#define CAN_MODATA29LL         (*((uword volatile far *) 0x2013B0))

// Message Object 2 Data Register High High
#define CAN_MODATA2HH          (*((uword volatile far *) 0x201056))

// Message Object 2 Data Register High Low
#define CAN_MODATA2HL          (*((uword volatile far *) 0x201054))

// Message Object 2 Data Register Low High
#define CAN_MODATA2LH          (*((uword volatile far *) 0x201052))

// Message Object 2 Data Register Low Low
#define CAN_MODATA2LL          (*((uword volatile far *) 0x201050))

// Message Object 30 Data Register High High
#define CAN_MODATA30HH         (*((uword volatile far *) 0x2013D6))

// Message Object 30 Data Register High Low
#define CAN_MODATA30HL         (*((uword volatile far *) 0x2013D4))

// Message Object 30 Data Register Low High
#define CAN_MODATA30LH         (*((uword volatile far *) 0x2013D2))

// Message Object 30 Data Register Low Low
#define CAN_MODATA30LL         (*((uword volatile far *) 0x2013D0))

// Message Object 31 Data Register High High
#define CAN_MODATA31HH         (*((uword volatile far *) 0x2013F6))

// Message Object 31 Data Register High Low
#define CAN_MODATA31HL         (*((uword volatile far *) 0x2013F4))

// Message Object 31 Data Register Low High
#define CAN_MODATA31LH         (*((uword volatile far *) 0x2013F2))

// Message Object 31 Data Register Low Low
#define CAN_MODATA31LL         (*((uword volatile far *) 0x2013F0))

// Message Object 32 Data Register High High
#define CAN_MODATA32HH         (*((uword volatile far *) 0x201416))

// Message Object 32 Data Register High Low
#define CAN_MODATA32HL         (*((uword volatile far *) 0x201414))

// Message Object 32 Data Register Low High
#define CAN_MODATA32LH         (*((uword volatile far *) 0x201412))

// Message Object 32 Data Register Low Low
#define CAN_MODATA32LL         (*((uword volatile far *) 0x201410))

// Message Object 33 Data Register High High
#define CAN_MODATA33HH         (*((uword volatile far *) 0x201436))

// Message Object 33 Data Register High Low
#define CAN_MODATA33HL         (*((uword volatile far *) 0x201434))

// Message Object 33 Data Register Low High
#define CAN_MODATA33LH         (*((uword volatile far *) 0x201432))

// Message Object 33 Data Register Low Low
#define CAN_MODATA33LL         (*((uword volatile far *) 0x201430))

// Message Object 34 Data Register High High
#define CAN_MODATA34HH         (*((uword volatile far *) 0x201456))

// Message Object 34 Data Register High Low
#define CAN_MODATA34HL         (*((uword volatile far *) 0x201454))

// Message Object 34 Data Register Low High
#define CAN_MODATA34LH         (*((uword volatile far *) 0x201452))

// Message Object 34 Data Register Low Low
#define CAN_MODATA34LL         (*((uword volatile far *) 0x201450))

// Message Object 35 Data Register High High
#define CAN_MODATA35HH         (*((uword volatile far *) 0x201476))

// Message Object 35 Data Register High Low
#define CAN_MODATA35HL         (*((uword volatile far *) 0x201474))

// Message Object 35 Data Register Low High
#define CAN_MODATA35LH         (*((uword volatile far *) 0x201472))

// Message Object 35 Data Register Low Low
#define CAN_MODATA35LL         (*((uword volatile far *) 0x201470))

// Message Object 36 Data Register High High
#define CAN_MODATA36HH         (*((uword volatile far *) 0x201496))

// Message Object 36 Data Register High Low
#define CAN_MODATA36HL         (*((uword volatile far *) 0x201494))

// Message Object 36 Data Register Low High
#define CAN_MODATA36LH         (*((uword volatile far *) 0x201492))

// Message Object 36 Data Register Low Low
#define CAN_MODATA36LL         (*((uword volatile far *) 0x201490))

// Message Object 37 Data Register High High
#define CAN_MODATA37HH         (*((uword volatile far *) 0x2014B6))

// Message Object 37 Data Register High Low
#define CAN_MODATA37HL         (*((uword volatile far *) 0x2014B4))

// Message Object 37 Data Register Low High
#define CAN_MODATA37LH         (*((uword volatile far *) 0x2014B2))

// Message Object 37 Data Register Low Low
#define CAN_MODATA37LL         (*((uword volatile far *) 0x2014B0))

// Message Object 38 Data Register High High
#define CAN_MODATA38HH         (*((uword volatile far *) 0x2014D6))

// Message Object 38 Data Register High Low
#define CAN_MODATA38HL         (*((uword volatile far *) 0x2014D4))

// Message Object 38 Data Register Low High
#define CAN_MODATA38LH         (*((uword volatile far *) 0x2014D2))

// Message Object 38 Data Register Low Low
#define CAN_MODATA38LL         (*((uword volatile far *) 0x2014D0))

// Message Object 39 Data Register High High
#define CAN_MODATA39HH         (*((uword volatile far *) 0x2014F6))

// Message Object 39 Data Register High Low
#define CAN_MODATA39HL         (*((uword volatile far *) 0x2014F4))

// Message Object 39 Data Register Low High
#define CAN_MODATA39LH         (*((uword volatile far *) 0x2014F2))

// Message Object 39 Data Register Low Low
#define CAN_MODATA39LL         (*((uword volatile far *) 0x2014F0))

// Message Object 3 Data Register High High
#define CAN_MODATA3HH          (*((uword volatile far *) 0x201076))

// Message Object 3 Data Register High Low
#define CAN_MODATA3HL          (*((uword volatile far *) 0x201074))

// Message Object 3 Data Register Low High
#define CAN_MODATA3LH          (*((uword volatile far *) 0x201072))

// Message Object 3 Data Register Low Low
#define CAN_MODATA3LL          (*((uword volatile far *) 0x201070))

// Message Object 40 Data Register High High
#define CAN_MODATA40HH         (*((uword volatile far *) 0x201516))

// Message Object 40 Data Register High Low
#define CAN_MODATA40HL         (*((uword volatile far *) 0x201514))

// Message Object 40 Data Register Low High
#define CAN_MODATA40LH         (*((uword volatile far *) 0x201512))

// Message Object 40 Data Register Low Low
#define CAN_MODATA40LL         (*((uword volatile far *) 0x201510))

// Message Object 41 Data Register High High
#define CAN_MODATA41HH         (*((uword volatile far *) 0x201536))

// Message Object 41 Data Register High Low
#define CAN_MODATA41HL         (*((uword volatile far *) 0x201534))

// Message Object 41 Data Register Low High
#define CAN_MODATA41LH         (*((uword volatile far *) 0x201532))

// Message Object 41 Data Register Low Low
#define CAN_MODATA41LL         (*((uword volatile far *) 0x201530))

// Message Object 42 Data Register High High
#define CAN_MODATA42HH         (*((uword volatile far *) 0x201556))

// Message Object 42 Data Register High Low
#define CAN_MODATA42HL         (*((uword volatile far *) 0x201554))

// Message Object 42 Data Register Low High
#define CAN_MODATA42LH         (*((uword volatile far *) 0x201552))

// Message Object 42 Data Register Low Low
#define CAN_MODATA42LL         (*((uword volatile far *) 0x201550))

// Message Object 43 Data Register High High
#define CAN_MODATA43HH         (*((uword volatile far *) 0x201576))

// Message Object 43 Data Register High Low
#define CAN_MODATA43HL         (*((uword volatile far *) 0x201574))

// Message Object 43 Data Register Low High
#define CAN_MODATA43LH         (*((uword volatile far *) 0x201572))

// Message Object 43 Data Register Low Low
#define CAN_MODATA43LL         (*((uword volatile far *) 0x201570))

// Message Object 44 Data Register High High
#define CAN_MODATA44HH         (*((uword volatile far *) 0x201596))

// Message Object 44 Data Register High Low
#define CAN_MODATA44HL         (*((uword volatile far *) 0x201594))

// Message Object 44 Data Register Low High
#define CAN_MODATA44LH         (*((uword volatile far *) 0x201592))

// Message Object 44 Data Register Low Low
#define CAN_MODATA44LL         (*((uword volatile far *) 0x201590))

// Message Object 45 Data Register High High
#define CAN_MODATA45HH         (*((uword volatile far *) 0x2015B6))

// Message Object 45 Data Register High Low
#define CAN_MODATA45HL         (*((uword volatile far *) 0x2015B4))

// Message Object 45 Data Register Low High
#define CAN_MODATA45LH         (*((uword volatile far *) 0x2015B2))

// Message Object 45 Data Register Low Low
#define CAN_MODATA45LL         (*((uword volatile far *) 0x2015B0))

// Message Object 46 Data Register High High
#define CAN_MODATA46HH         (*((uword volatile far *) 0x2015D6))

// Message Object 46 Data Register High Low
#define CAN_MODATA46HL         (*((uword volatile far *) 0x2015D4))

// Message Object 46 Data Register Low High
#define CAN_MODATA46LH         (*((uword volatile far *) 0x2015D2))

// Message Object 46 Data Register Low Low
#define CAN_MODATA46LL         (*((uword volatile far *) 0x2015D0))

// Message Object 47 Data Register High High
#define CAN_MODATA47HH         (*((uword volatile far *) 0x2015F6))

// Message Object 47 Data Register High Low
#define CAN_MODATA47HL         (*((uword volatile far *) 0x2015F4))

// Message Object 47 Data Register Low High
#define CAN_MODATA47LH         (*((uword volatile far *) 0x2015F2))

// Message Object 47 Data Register Low Low
#define CAN_MODATA47LL         (*((uword volatile far *) 0x2015F0))

// Message Object 48 Data Register High High
#define CAN_MODATA48HH         (*((uword volatile far *) 0x201616))

// Message Object 48 Data Register High Low
#define CAN_MODATA48HL         (*((uword volatile far *) 0x201614))

// Message Object 48 Data Register Low High
#define CAN_MODATA48LH         (*((uword volatile far *) 0x201612))

// Message Object 48 Data Register Low Low
#define CAN_MODATA48LL         (*((uword volatile far *) 0x201610))

// Message Object 49 Data Register High High
#define CAN_MODATA49HH         (*((uword volatile far *) 0x201636))

// Message Object 49 Data Register High Low
#define CAN_MODATA49HL         (*((uword volatile far *) 0x201634))

// Message Object 49 Data Register Low High
#define CAN_MODATA49LH         (*((uword volatile far *) 0x201632))

// Message Object 49 Data Register Low Low
#define CAN_MODATA49LL         (*((uword volatile far *) 0x201630))

// Message Object 4 Data Register High High
#define CAN_MODATA4HH          (*((uword volatile far *) 0x201096))

// Message Object 4 Data Register High Low
#define CAN_MODATA4HL          (*((uword volatile far *) 0x201094))

// Message Object 4 Data Register Low High
#define CAN_MODATA4LH          (*((uword volatile far *) 0x201092))

// Message Object 4 Data Register Low Low
#define CAN_MODATA4LL          (*((uword volatile far *) 0x201090))

// Message Object 50 Data Register High High
#define CAN_MODATA50HH         (*((uword volatile far *) 0x201656))

// Message Object 50 Data Register High Low
#define CAN_MODATA50HL         (*((uword volatile far *) 0x201654))

// Message Object 50 Data Register Low High
#define CAN_MODATA50LH         (*((uword volatile far *) 0x201652))

// Message Object 50 Data Register Low Low
#define CAN_MODATA50LL         (*((uword volatile far *) 0x201650))

// Message Object 51 Data Register High High
#define CAN_MODATA51HH         (*((uword volatile far *) 0x201676))

// Message Object 51 Data Register High Low
#define CAN_MODATA51HL         (*((uword volatile far *) 0x201674))

// Message Object 51 Data Register Low High
#define CAN_MODATA51LH         (*((uword volatile far *) 0x201672))

// Message Object 51 Data Register Low Low
#define CAN_MODATA51LL         (*((uword volatile far *) 0x201670))

// Message Object 52 Data Register High High
#define CAN_MODATA52HH         (*((uword volatile far *) 0x201696))

// Message Object 52 Data Register High Low
#define CAN_MODATA52HL         (*((uword volatile far *) 0x201694))

// Message Object 52 Data Register Low High
#define CAN_MODATA52LH         (*((uword volatile far *) 0x201692))

// Message Object 52 Data Register Low Low
#define CAN_MODATA52LL         (*((uword volatile far *) 0x201690))

// Message Object 53 Data Register High High
#define CAN_MODATA53HH         (*((uword volatile far *) 0x2016B6))

// Message Object 53 Data Register High Low
#define CAN_MODATA53HL         (*((uword volatile far *) 0x2016B4))

// Message Object 53 Data Register Low High
#define CAN_MODATA53LH         (*((uword volatile far *) 0x2016B2))

// Message Object 53 Data Register Low Low
#define CAN_MODATA53LL         (*((uword volatile far *) 0x2016B0))

// Message Object 54 Data Register High High
#define CAN_MODATA54HH         (*((uword volatile far *) 0x2016D6))

// Message Object 54 Data Register High Low
#define CAN_MODATA54HL         (*((uword volatile far *) 0x2016D4))

// Message Object 54 Data Register Low High
#define CAN_MODATA54LH         (*((uword volatile far *) 0x2016D2))

// Message Object 54 Data Register Low Low
#define CAN_MODATA54LL         (*((uword volatile far *) 0x2016D0))

// Message Object 55 Data Register High High
#define CAN_MODATA55HH         (*((uword volatile far *) 0x2016F6))

// Message Object 55 Data Register High Low
#define CAN_MODATA55HL         (*((uword volatile far *) 0x2016F4))

// Message Object 55 Data Register Low High
#define CAN_MODATA55LH         (*((uword volatile far *) 0x2016F2))

// Message Object 55 Data Register Low Low
#define CAN_MODATA55LL         (*((uword volatile far *) 0x2016F0))

// Message Object 56 Data Register High High
#define CAN_MODATA56HH         (*((uword volatile far *) 0x201716))

// Message Object 56 Data Register High Low
#define CAN_MODATA56HL         (*((uword volatile far *) 0x201714))

// Message Object 56 Data Register Low High
#define CAN_MODATA56LH         (*((uword volatile far *) 0x201712))

// Message Object 56 Data Register Low Low
#define CAN_MODATA56LL         (*((uword volatile far *) 0x201710))

// Message Object 57 Data Register High High
#define CAN_MODATA57HH         (*((uword volatile far *) 0x201736))

// Message Object 57 Data Register High Low
#define CAN_MODATA57HL         (*((uword volatile far *) 0x201734))

// Message Object 57 Data Register Low High
#define CAN_MODATA57LH         (*((uword volatile far *) 0x201732))

// Message Object 57 Data Register Low Low
#define CAN_MODATA57LL         (*((uword volatile far *) 0x201730))

// Message Object 58 Data Register High High
#define CAN_MODATA58HH         (*((uword volatile far *) 0x201756))

// Message Object 58 Data Register High Low
#define CAN_MODATA58HL         (*((uword volatile far *) 0x201754))

// Message Object 58 Data Register Low High
#define CAN_MODATA58LH         (*((uword volatile far *) 0x201752))

// Message Object 58 Data Register Low Low
#define CAN_MODATA58LL         (*((uword volatile far *) 0x201750))

// Message Object 59 Data Register High High
#define CAN_MODATA59HH         (*((uword volatile far *) 0x201776))

// Message Object 59 Data Register High Low
#define CAN_MODATA59HL         (*((uword volatile far *) 0x201774))

// Message Object 59 Data Register Low High
#define CAN_MODATA59LH         (*((uword volatile far *) 0x201772))

// Message Object 59 Data Register Low Low
#define CAN_MODATA59LL         (*((uword volatile far *) 0x201770))

// Message Object 5 Data Register High High
#define CAN_MODATA5HH          (*((uword volatile far *) 0x2010B6))

// Message Object 5 Data Register High Low
#define CAN_MODATA5HL          (*((uword volatile far *) 0x2010B4))

// Message Object 5 Data Register Low High
#define CAN_MODATA5LH          (*((uword volatile far *) 0x2010B2))

// Message Object 5 Data Register Low Low
#define CAN_MODATA5LL          (*((uword volatile far *) 0x2010B0))

// Message Object 60 Data Register High High
#define CAN_MODATA60HH         (*((uword volatile far *) 0x201796))

// Message Object 60 Data Register High Low
#define CAN_MODATA60HL         (*((uword volatile far *) 0x201794))

// Message Object 60 Data Register Low High
#define CAN_MODATA60LH         (*((uword volatile far *) 0x201792))

// Message Object 60 Data Register Low Low
#define CAN_MODATA60LL         (*((uword volatile far *) 0x201790))

// Message Object 61 Data Register High High
#define CAN_MODATA61HH         (*((uword volatile far *) 0x2017B6))

// Message Object 61 Data Register High Low
#define CAN_MODATA61HL         (*((uword volatile far *) 0x2017B4))

// Message Object 61 Data Register Low High
#define CAN_MODATA61LH         (*((uword volatile far *) 0x2017B2))

// Message Object 61 Data Register Low Low
#define CAN_MODATA61LL         (*((uword volatile far *) 0x2017B0))

// Message Object 62 Data Register High High
#define CAN_MODATA62HH         (*((uword volatile far *) 0x2017D6))

// Message Object 62 Data Register High Low
#define CAN_MODATA62HL         (*((uword volatile far *) 0x2017D4))

// Message Object 62 Data Register Low High
#define CAN_MODATA62LH         (*((uword volatile far *) 0x2017D2))

// Message Object 62 Data Register Low Low
#define CAN_MODATA62LL         (*((uword volatile far *) 0x2017D0))

// Message Object 63 Data Register High High
#define CAN_MODATA63HH         (*((uword volatile far *) 0x2017F6))

// Message Object 63 Data Register High Low
#define CAN_MODATA63HL         (*((uword volatile far *) 0x2017F4))

// Message Object 63 Data Register Low High
#define CAN_MODATA63LH         (*((uword volatile far *) 0x2017F2))

// Message Object 63 Data Register Low Low
#define CAN_MODATA63LL         (*((uword volatile far *) 0x2017F0))

// Message Object 64 Data Register High High
#define CAN_MODATA64HH         (*((uword volatile far *) 0x201816))

// Message Object 64 Data Register High Low
#define CAN_MODATA64HL         (*((uword volatile far *) 0x201814))

// Message Object 64 Data Register Low High
#define CAN_MODATA64LH         (*((uword volatile far *) 0x201812))

// Message Object 64 Data Register Low Low
#define CAN_MODATA64LL         (*((uword volatile far *) 0x201810))

// Message Object 65 Data Register High High
#define CAN_MODATA65HH         (*((uword volatile far *) 0x201836))

// Message Object 65 Data Register High Low
#define CAN_MODATA65HL         (*((uword volatile far *) 0x201834))

// Message Object 65 Data Register Low High
#define CAN_MODATA65LH         (*((uword volatile far *) 0x201832))

// Message Object 65 Data Register Low Low
#define CAN_MODATA65LL         (*((uword volatile far *) 0x201830))

// Message Object 66 Data Register High High
#define CAN_MODATA66HH         (*((uword volatile far *) 0x201856))

// Message Object 66 Data Register High Low
#define CAN_MODATA66HL         (*((uword volatile far *) 0x201854))

// Message Object 66 Data Register Low High
#define CAN_MODATA66LH         (*((uword volatile far *) 0x201852))

// Message Object 66 Data Register Low Low
#define CAN_MODATA66LL         (*((uword volatile far *) 0x201850))

// Message Object 67 Data Register High High
#define CAN_MODATA67HH         (*((uword volatile far *) 0x201876))

// Message Object 67 Data Register High Low
#define CAN_MODATA67HL         (*((uword volatile far *) 0x201874))

// Message Object 67 Data Register Low High
#define CAN_MODATA67LH         (*((uword volatile far *) 0x201872))

// Message Object 67 Data Register Low Low
#define CAN_MODATA67LL         (*((uword volatile far *) 0x201870))

// Message Object 68 Data Register High High
#define CAN_MODATA68HH         (*((uword volatile far *) 0x201896))

// Message Object 68 Data Register High Low
#define CAN_MODATA68HL         (*((uword volatile far *) 0x201894))

// Message Object 68 Data Register Low High
#define CAN_MODATA68LH         (*((uword volatile far *) 0x201892))

// Message Object 68 Data Register Low Low
#define CAN_MODATA68LL         (*((uword volatile far *) 0x201890))

// Message Object 69 Data Register High High
#define CAN_MODATA69HH         (*((uword volatile far *) 0x2018B6))

// Message Object 69 Data Register High Low
#define CAN_MODATA69HL         (*((uword volatile far *) 0x2018B4))

// Message Object 69 Data Register Low High
#define CAN_MODATA69LH         (*((uword volatile far *) 0x2018B2))

// Message Object 69 Data Register Low Low
#define CAN_MODATA69LL         (*((uword volatile far *) 0x2018B0))

// Message Object 6 Data Register High High
#define CAN_MODATA6HH          (*((uword volatile far *) 0x2010D6))

// Message Object 6 Data Register High Low
#define CAN_MODATA6HL          (*((uword volatile far *) 0x2010D4))

// Message Object 6 Data Register Low High
#define CAN_MODATA6LH          (*((uword volatile far *) 0x2010D2))

// Message Object 6 Data Register Low Low
#define CAN_MODATA6LL          (*((uword volatile far *) 0x2010D0))

// Message Object 70 Data Register High High
#define CAN_MODATA70HH         (*((uword volatile far *) 0x2018D6))

// Message Object 70 Data Register High Low
#define CAN_MODATA70HL         (*((uword volatile far *) 0x2018D4))

// Message Object 70 Data Register Low High
#define CAN_MODATA70LH         (*((uword volatile far *) 0x2018D2))

// Message Object 70 Data Register Low Low
#define CAN_MODATA70LL         (*((uword volatile far *) 0x2018D0))

// Message Object 71 Data Register High High
#define CAN_MODATA71HH         (*((uword volatile far *) 0x2018F6))

// Message Object 71 Data Register High Low
#define CAN_MODATA71HL         (*((uword volatile far *) 0x2018F4))

// Message Object 71 Data Register Low High
#define CAN_MODATA71LH         (*((uword volatile far *) 0x2018F2))

// Message Object 71 Data Register Low Low
#define CAN_MODATA71LL         (*((uword volatile far *) 0x2018F0))

// Message Object 72 Data Register High High
#define CAN_MODATA72HH         (*((uword volatile far *) 0x201916))

// Message Object 72 Data Register High Low
#define CAN_MODATA72HL         (*((uword volatile far *) 0x201914))

// Message Object 72 Data Register Low High
#define CAN_MODATA72LH         (*((uword volatile far *) 0x201912))

// Message Object 72 Data Register Low Low
#define CAN_MODATA72LL         (*((uword volatile far *) 0x201910))

// Message Object 73 Data Register High High
#define CAN_MODATA73HH         (*((uword volatile far *) 0x201936))

// Message Object 73 Data Register High Low
#define CAN_MODATA73HL         (*((uword volatile far *) 0x201934))

// Message Object 73 Data Register Low High
#define CAN_MODATA73LH         (*((uword volatile far *) 0x201932))

// Message Object 73 Data Register Low Low
#define CAN_MODATA73LL         (*((uword volatile far *) 0x201930))

// Message Object 74 Data Register High High
#define CAN_MODATA74HH         (*((uword volatile far *) 0x201956))

// Message Object 74 Data Register High Low
#define CAN_MODATA74HL         (*((uword volatile far *) 0x201954))

// Message Object 74 Data Register Low High
#define CAN_MODATA74LH         (*((uword volatile far *) 0x201952))

// Message Object 74 Data Register Low Low
#define CAN_MODATA74LL         (*((uword volatile far *) 0x201950))

// Message Object 75 Data Register High High
#define CAN_MODATA75HH         (*((uword volatile far *) 0x201976))

// Message Object 75 Data Register High Low
#define CAN_MODATA75HL         (*((uword volatile far *) 0x201974))

// Message Object 75 Data Register Low High
#define CAN_MODATA75LH         (*((uword volatile far *) 0x201972))

// Message Object 75 Data Register Low Low
#define CAN_MODATA75LL         (*((uword volatile far *) 0x201970))

// Message Object 76 Data Register High High
#define CAN_MODATA76HH         (*((uword volatile far *) 0x201996))

// Message Object 76 Data Register High Low
#define CAN_MODATA76HL         (*((uword volatile far *) 0x201994))

// Message Object 76 Data Register Low High
#define CAN_MODATA76LH         (*((uword volatile far *) 0x201992))

// Message Object 76 Data Register Low Low
#define CAN_MODATA76LL         (*((uword volatile far *) 0x201990))

// Message Object 77 Data Register High High
#define CAN_MODATA77HH         (*((uword volatile far *) 0x2019B6))

// Message Object 77 Data Register High Low
#define CAN_MODATA77HL         (*((uword volatile far *) 0x2019B4))

// Message Object 77 Data Register Low High
#define CAN_MODATA77LH         (*((uword volatile far *) 0x2019B2))

// Message Object 77 Data Register Low Low
#define CAN_MODATA77LL         (*((uword volatile far *) 0x2019B0))

// Message Object 78 Data Register High High
#define CAN_MODATA78HH         (*((uword volatile far *) 0x2019D6))

// Message Object 78 Data Register High Low
#define CAN_MODATA78HL         (*((uword volatile far *) 0x2019D4))

// Message Object 78 Data Register Low High
#define CAN_MODATA78LH         (*((uword volatile far *) 0x2019D2))

// Message Object 78 Data Register Low Low
#define CAN_MODATA78LL         (*((uword volatile far *) 0x2019D0))

// Message Object 79 Data Register High High
#define CAN_MODATA79HH         (*((uword volatile far *) 0x2019F6))

// Message Object 79 Data Register High Low
#define CAN_MODATA79HL         (*((uword volatile far *) 0x2019F4))

// Message Object 79 Data Register Low High
#define CAN_MODATA79LH         (*((uword volatile far *) 0x2019F2))

// Message Object 79 Data Register Low Low
#define CAN_MODATA79LL         (*((uword volatile far *) 0x2019F0))

// Message Object 7 Data Register High High
#define CAN_MODATA7HH          (*((uword volatile far *) 0x2010F6))

// Message Object 7 Data Register High Low
#define CAN_MODATA7HL          (*((uword volatile far *) 0x2010F4))

// Message Object 7 Data Register Low High
#define CAN_MODATA7LH          (*((uword volatile far *) 0x2010F2))

// Message Object 7 Data Register Low Low
#define CAN_MODATA7LL          (*((uword volatile far *) 0x2010F0))

// Message Object 80 Data Register High High
#define CAN_MODATA80HH         (*((uword volatile far *) 0x201A16))

// Message Object 80 Data Register High Low
#define CAN_MODATA80HL         (*((uword volatile far *) 0x201A14))

// Message Object 80 Data Register Low High
#define CAN_MODATA80LH         (*((uword volatile far *) 0x201A12))

// Message Object 80 Data Register Low Low
#define CAN_MODATA80LL         (*((uword volatile far *) 0x201A10))

// Message Object 81 Data Register High High
#define CAN_MODATA81HH         (*((uword volatile far *) 0x201A36))

// Message Object 81 Data Register High Low
#define CAN_MODATA81HL         (*((uword volatile far *) 0x201A34))

// Message Object 81 Data Register Low High
#define CAN_MODATA81LH         (*((uword volatile far *) 0x201A32))

// Message Object 81 Data Register Low Low
#define CAN_MODATA81LL         (*((uword volatile far *) 0x201A30))

// Message Object 82 Data Register High High
#define CAN_MODATA82HH         (*((uword volatile far *) 0x201A56))

// Message Object 82 Data Register High Low
#define CAN_MODATA82HL         (*((uword volatile far *) 0x201A54))

// Message Object 82 Data Register Low High
#define CAN_MODATA82LH         (*((uword volatile far *) 0x201A52))

// Message Object 82 Data Register Low Low
#define CAN_MODATA82LL         (*((uword volatile far *) 0x201A50))

// Message Object 83 Data Register High High
#define CAN_MODATA83HH         (*((uword volatile far *) 0x201A76))

// Message Object 83 Data Register High Low
#define CAN_MODATA83HL         (*((uword volatile far *) 0x201A74))

// Message Object 83 Data Register Low High
#define CAN_MODATA83LH         (*((uword volatile far *) 0x201A72))

// Message Object 83 Data Register Low Low
#define CAN_MODATA83LL         (*((uword volatile far *) 0x201A70))

// Message Object 84 Data Register High High
#define CAN_MODATA84HH         (*((uword volatile far *) 0x201A96))

// Message Object 84 Data Register High Low
#define CAN_MODATA84HL         (*((uword volatile far *) 0x201A94))

// Message Object 84 Data Register Low High
#define CAN_MODATA84LH         (*((uword volatile far *) 0x201A92))

// Message Object 84 Data Register Low Low
#define CAN_MODATA84LL         (*((uword volatile far *) 0x201A90))

// Message Object 85 Data Register High High
#define CAN_MODATA85HH         (*((uword volatile far *) 0x201AB6))

// Message Object 85 Data Register High Low
#define CAN_MODATA85HL         (*((uword volatile far *) 0x201AB4))

// Message Object 85 Data Register Low High
#define CAN_MODATA85LH         (*((uword volatile far *) 0x201AB2))

// Message Object 85 Data Register Low Low
#define CAN_MODATA85LL         (*((uword volatile far *) 0x201AB0))

// Message Object 86 Data Register High High
#define CAN_MODATA86HH         (*((uword volatile far *) 0x201AD6))

// Message Object 86 Data Register High Low
#define CAN_MODATA86HL         (*((uword volatile far *) 0x201AD4))

// Message Object 86 Data Register Low High
#define CAN_MODATA86LH         (*((uword volatile far *) 0x201AD2))

// Message Object 86 Data Register Low Low
#define CAN_MODATA86LL         (*((uword volatile far *) 0x201AD0))

// Message Object 87 Data Register High High
#define CAN_MODATA87HH         (*((uword volatile far *) 0x201AF6))

// Message Object 87 Data Register High Low
#define CAN_MODATA87HL         (*((uword volatile far *) 0x201AF4))

// Message Object 87 Data Register Low High
#define CAN_MODATA87LH         (*((uword volatile far *) 0x201AF2))

// Message Object 87 Data Register Low Low
#define CAN_MODATA87LL         (*((uword volatile far *) 0x201AF0))

// Message Object 88 Data Register High High
#define CAN_MODATA88HH         (*((uword volatile far *) 0x201B16))

// Message Object 88 Data Register High Low
#define CAN_MODATA88HL         (*((uword volatile far *) 0x201B14))

// Message Object 88 Data Register Low High
#define CAN_MODATA88LH         (*((uword volatile far *) 0x201B12))

// Message Object 88 Data Register Low Low
#define CAN_MODATA88LL         (*((uword volatile far *) 0x201B10))

// Message Object 89 Data Register High High
#define CAN_MODATA89HH         (*((uword volatile far *) 0x201B36))

// Message Object 89 Data Register High Low
#define CAN_MODATA89HL         (*((uword volatile far *) 0x201B34))

// Message Object 89 Data Register Low High
#define CAN_MODATA89LH         (*((uword volatile far *) 0x201B32))

// Message Object 89 Data Register Low Low
#define CAN_MODATA89LL         (*((uword volatile far *) 0x201B30))

// Message Object 8 Data Register High High
#define CAN_MODATA8HH          (*((uword volatile far *) 0x201116))

// Message Object 8 Data Register High Low
#define CAN_MODATA8HL          (*((uword volatile far *) 0x201114))

// Message Object 8 Data Register Low High
#define CAN_MODATA8LH          (*((uword volatile far *) 0x201112))

// Message Object 8 Data Register Low Low
#define CAN_MODATA8LL          (*((uword volatile far *) 0x201110))

// Message Object 90 Data Register High High
#define CAN_MODATA90HH         (*((uword volatile far *) 0x201B56))

// Message Object 90 Data Register High Low
#define CAN_MODATA90HL         (*((uword volatile far *) 0x201B54))

// Message Object 90 Data Register Low High
#define CAN_MODATA90LH         (*((uword volatile far *) 0x201B52))

// Message Object 90 Data Register Low Low
#define CAN_MODATA90LL         (*((uword volatile far *) 0x201B50))

// Message Object 91 Data Register High High
#define CAN_MODATA91HH         (*((uword volatile far *) 0x201B76))

// Message Object 91 Data Register High Low
#define CAN_MODATA91HL         (*((uword volatile far *) 0x201B74))

// Message Object 91 Data Register Low High
#define CAN_MODATA91LH         (*((uword volatile far *) 0x201B72))

// Message Object 91 Data Register Low Low
#define CAN_MODATA91LL         (*((uword volatile far *) 0x201B70))

// Message Object 92 Data Register High High
#define CAN_MODATA92HH         (*((uword volatile far *) 0x201B96))

// Message Object 92 Data Register High Low
#define CAN_MODATA92HL         (*((uword volatile far *) 0x201B94))

// Message Object 92 Data Register Low High
#define CAN_MODATA92LH         (*((uword volatile far *) 0x201B92))

// Message Object 92 Data Register Low Low
#define CAN_MODATA92LL         (*((uword volatile far *) 0x201B90))

// Message Object 93 Data Register High High
#define CAN_MODATA93HH         (*((uword volatile far *) 0x201BB6))

// Message Object 93 Data Register High Low
#define CAN_MODATA93HL         (*((uword volatile far *) 0x201BB4))

// Message Object 93 Data Register Low High
#define CAN_MODATA93LH         (*((uword volatile far *) 0x201BB2))

// Message Object 93 Data Register Low Low
#define CAN_MODATA93LL         (*((uword volatile far *) 0x201BB0))

// Message Object 94 Data Register High High
#define CAN_MODATA94HH         (*((uword volatile far *) 0x201BD6))

// Message Object 94 Data Register High Low
#define CAN_MODATA94HL         (*((uword volatile far *) 0x201BD4))

// Message Object 94 Data Register Low High
#define CAN_MODATA94LH         (*((uword volatile far *) 0x201BD2))

// Message Object 94 Data Register Low Low
#define CAN_MODATA94LL         (*((uword volatile far *) 0x201BD0))

// Message Object 95 Data Register High High
#define CAN_MODATA95HH         (*((uword volatile far *) 0x201BF6))

// Message Object 95 Data Register High Low
#define CAN_MODATA95HL         (*((uword volatile far *) 0x201BF4))

// Message Object 95 Data Register Low High
#define CAN_MODATA95LH         (*((uword volatile far *) 0x201BF2))

// Message Object 95 Data Register Low Low
#define CAN_MODATA95LL         (*((uword volatile far *) 0x201BF0))

// Message Object 96 Data Register High High
#define CAN_MODATA96HH         (*((uword volatile far *) 0x201C16))

// Message Object 96 Data Register High Low
#define CAN_MODATA96HL         (*((uword volatile far *) 0x201C14))

// Message Object 96 Data Register Low High
#define CAN_MODATA96LH         (*((uword volatile far *) 0x201C12))

// Message Object 96 Data Register Low Low
#define CAN_MODATA96LL         (*((uword volatile far *) 0x201C10))

// Message Object 97 Data Register High High
#define CAN_MODATA97HH         (*((uword volatile far *) 0x201C36))

// Message Object 97 Data Register High Low
#define CAN_MODATA97HL         (*((uword volatile far *) 0x201C34))

// Message Object 97 Data Register Low High
#define CAN_MODATA97LH         (*((uword volatile far *) 0x201C32))

// Message Object 97 Data Register Low Low
#define CAN_MODATA97LL         (*((uword volatile far *) 0x201C30))

// Message Object 98 Data Register High High
#define CAN_MODATA98HH         (*((uword volatile far *) 0x201C56))

// Message Object 98 Data Register High Low
#define CAN_MODATA98HL         (*((uword volatile far *) 0x201C54))

// Message Object 98 Data Register Low High
#define CAN_MODATA98LH         (*((uword volatile far *) 0x201C52))

// Message Object 98 Data Register Low Low
#define CAN_MODATA98LL         (*((uword volatile far *) 0x201C50))

// Message Object 99 Data Register High High
#define CAN_MODATA99HH         (*((uword volatile far *) 0x201C76))

// Message Object 99 Data Register High Low
#define CAN_MODATA99HL         (*((uword volatile far *) 0x201C74))

// Message Object 99 Data Register Low High
#define CAN_MODATA99LH         (*((uword volatile far *) 0x201C72))

// Message Object 99 Data Register Low Low
#define CAN_MODATA99LL         (*((uword volatile far *) 0x201C70))

// Message Object 9 Data Register High High
#define CAN_MODATA9HH          (*((uword volatile far *) 0x201136))

// Message Object 9 Data Register High Low
#define CAN_MODATA9HL          (*((uword volatile far *) 0x201134))

// Message Object 9 Data Register Low High
#define CAN_MODATA9LH          (*((uword volatile far *) 0x201132))

// Message Object 9 Data Register Low Low
#define CAN_MODATA9LL          (*((uword volatile far *) 0x201130))

// Message Object 0 Function Control Register High
#define CAN_MOFCR0H            (*((uword volatile far *) 0x201002))

// Message Object 0 Function Control Register Low
#define CAN_MOFCR0L            (*((uword volatile far *) 0x201000))

// Message Object 100 Function Control Register High
#define CAN_MOFCR100H          (*((uword volatile far *) 0x201C82))

// Message Object 100 Function Control Register Low
#define CAN_MOFCR100L          (*((uword volatile far *) 0x201C80))

// Message Object 101 Function Control Register High
#define CAN_MOFCR101H          (*((uword volatile far *) 0x201CA2))

// Message Object 101 Function Control Register Low
#define CAN_MOFCR101L          (*((uword volatile far *) 0x201CA0))

// Message Object 102 Function Control Register High
#define CAN_MOFCR102H          (*((uword volatile far *) 0x201CC2))

// Message Object 102 Function Control Register Low
#define CAN_MOFCR102L          (*((uword volatile far *) 0x201CC0))

// Message Object 103 Function Control Register High
#define CAN_MOFCR103H          (*((uword volatile far *) 0x201CE2))

// Message Object 103 Function Control Register Low
#define CAN_MOFCR103L          (*((uword volatile far *) 0x201CE0))

// Message Object 104 Function Control Register High
#define CAN_MOFCR104H          (*((uword volatile far *) 0x201D02))

// Message Object 104 Function Control Register Low
#define CAN_MOFCR104L          (*((uword volatile far *) 0x201D00))

// Message Object 105 Function Control Register High
#define CAN_MOFCR105H          (*((uword volatile far *) 0x201D22))

// Message Object 105 Function Control Register Low
#define CAN_MOFCR105L          (*((uword volatile far *) 0x201D20))

// Message Object 106 Function Control Register High
#define CAN_MOFCR106H          (*((uword volatile far *) 0x201D42))

// Message Object 106 Function Control Register Low
#define CAN_MOFCR106L          (*((uword volatile far *) 0x201D40))

// Message Object 107 Function Control Register High
#define CAN_MOFCR107H          (*((uword volatile far *) 0x201D62))

// Message Object 107 Function Control Register Low
#define CAN_MOFCR107L          (*((uword volatile far *) 0x201D60))

// Message Object 108 Function Control Register High
#define CAN_MOFCR108H          (*((uword volatile far *) 0x201D82))

// Message Object 108 Function Control Register Low
#define CAN_MOFCR108L          (*((uword volatile far *) 0x201D80))

// Message Object 109 Function Control Register High
#define CAN_MOFCR109H          (*((uword volatile far *) 0x201DA2))

// Message Object 109 Function Control Register Low
#define CAN_MOFCR109L          (*((uword volatile far *) 0x201DA0))

// Message Object 10 Function Control Register High
#define CAN_MOFCR10H           (*((uword volatile far *) 0x201142))

// Message Object 10 Function Control Register Low
#define CAN_MOFCR10L           (*((uword volatile far *) 0x201140))

// Message Object 110 Function Control Register High
#define CAN_MOFCR110H          (*((uword volatile far *) 0x201DC2))

// Message Object 110 Function Control Register Low
#define CAN_MOFCR110L          (*((uword volatile far *) 0x201DC0))

// Message Object 111 Function Control Register High
#define CAN_MOFCR111H          (*((uword volatile far *) 0x201DE2))

// Message Object 111 Function Control Register Low
#define CAN_MOFCR111L          (*((uword volatile far *) 0x201DE0))

// Message Object 112 Function Control Register High
#define CAN_MOFCR112H          (*((uword volatile far *) 0x201E02))

// Message Object 112 Function Control Register Low
#define CAN_MOFCR112L          (*((uword volatile far *) 0x201E00))

// Message Object 113 Function Control Register High
#define CAN_MOFCR113H          (*((uword volatile far *) 0x201E22))

// Message Object 113 Function Control Register Low
#define CAN_MOFCR113L          (*((uword volatile far *) 0x201E20))

// Message Object 114 Function Control Register High
#define CAN_MOFCR114H          (*((uword volatile far *) 0x201E42))

// Message Object 114 Function Control Register Low
#define CAN_MOFCR114L          (*((uword volatile far *) 0x201E40))

// Message Object 115 Function Control Register High
#define CAN_MOFCR115H          (*((uword volatile far *) 0x201E62))

// Message Object 115 Function Control Register Low
#define CAN_MOFCR115L          (*((uword volatile far *) 0x201E60))

// Message Object 116 Function Control Register High
#define CAN_MOFCR116H          (*((uword volatile far *) 0x201E82))

// Message Object 116 Function Control Register Low
#define CAN_MOFCR116L          (*((uword volatile far *) 0x201E80))

// Message Object 117 Function Control Register High
#define CAN_MOFCR117H          (*((uword volatile far *) 0x201EA2))

// Message Object 117 Function Control Register Low
#define CAN_MOFCR117L          (*((uword volatile far *) 0x201EA0))

// Message Object 118 Function Control Register High
#define CAN_MOFCR118H          (*((uword volatile far *) 0x201EC2))

// Message Object 118 Function Control Register Low
#define CAN_MOFCR118L          (*((uword volatile far *) 0x201EC0))

// Message Object 119 Function Control Register High
#define CAN_MOFCR119H          (*((uword volatile far *) 0x201EE2))

// Message Object 119 Function Control Register Low
#define CAN_MOFCR119L          (*((uword volatile far *) 0x201EE0))

// Message Object 11 Function Control Register High
#define CAN_MOFCR11H           (*((uword volatile far *) 0x201162))

// Message Object 11 Function Control Register Low
#define CAN_MOFCR11L           (*((uword volatile far *) 0x201160))

// Message Object 120 Function Control Register High
#define CAN_MOFCR120H          (*((uword volatile far *) 0x201F02))

// Message Object 120 Function Control Register Low
#define CAN_MOFCR120L          (*((uword volatile far *) 0x201F00))

// Message Object 121 Function Control Register High
#define CAN_MOFCR121H          (*((uword volatile far *) 0x201F22))

// Message Object 121 Function Control Register Low
#define CAN_MOFCR121L          (*((uword volatile far *) 0x201F20))

// Message Object 122 Function Control Register High
#define CAN_MOFCR122H          (*((uword volatile far *) 0x201F42))

// Message Object 122 Function Control Register Low
#define CAN_MOFCR122L          (*((uword volatile far *) 0x201F40))

// Message Object 123 Function Control Register High
#define CAN_MOFCR123H          (*((uword volatile far *) 0x201F62))

// Message Object 123 Function Control Register Low
#define CAN_MOFCR123L          (*((uword volatile far *) 0x201F60))

// Message Object 124 Function Control Register High
#define CAN_MOFCR124H          (*((uword volatile far *) 0x201F82))

// Message Object 124 Function Control Register Low
#define CAN_MOFCR124L          (*((uword volatile far *) 0x201F80))

// Message Object 125 Function Control Register High
#define CAN_MOFCR125H          (*((uword volatile far *) 0x201FA2))

// Message Object 125 Function Control Register Low
#define CAN_MOFCR125L          (*((uword volatile far *) 0x201FA0))

// Message Object 126 Function Control Register High
#define CAN_MOFCR126H          (*((uword volatile far *) 0x201FC2))

// Message Object 126 Function Control Register Low
#define CAN_MOFCR126L          (*((uword volatile far *) 0x201FC0))

// Message Object 127 Function Control Register High
#define CAN_MOFCR127H          (*((uword volatile far *) 0x201FE2))

// Message Object 127 Function Control Register Low
#define CAN_MOFCR127L          (*((uword volatile far *) 0x201FE0))

// Message Object 128 Function Control Register High
#define CAN_MOFCR128H          (*((uword volatile far *) 0x202002))

// Message Object 128 Function Control Register Low
#define CAN_MOFCR128L          (*((uword volatile far *) 0x202000))

// Message Object 129 Function Control Register High
#define CAN_MOFCR129H          (*((uword volatile far *) 0x202022))

// Message Object 129 Function Control Register Low
#define CAN_MOFCR129L          (*((uword volatile far *) 0x202020))

// Message Object 12 Function Control Register High
#define CAN_MOFCR12H           (*((uword volatile far *) 0x201182))

// Message Object 12 Function Control Register Low
#define CAN_MOFCR12L           (*((uword volatile far *) 0x201180))

// Message Object 130 Function Control Register High
#define CAN_MOFCR130H          (*((uword volatile far *) 0x202042))

// Message Object 130 Function Control Register Low
#define CAN_MOFCR130L          (*((uword volatile far *) 0x202040))

// Message Object 131 Function Control Register High
#define CAN_MOFCR131H          (*((uword volatile far *) 0x202062))

// Message Object 131 Function Control Register Low
#define CAN_MOFCR131L          (*((uword volatile far *) 0x202060))

// Message Object 132 Function Control Register High
#define CAN_MOFCR132H          (*((uword volatile far *) 0x202082))

// Message Object 132 Function Control Register Low
#define CAN_MOFCR132L          (*((uword volatile far *) 0x202080))

// Message Object 133 Function Control Register High
#define CAN_MOFCR133H          (*((uword volatile far *) 0x2020A2))

// Message Object 133 Function Control Register Low
#define CAN_MOFCR133L          (*((uword volatile far *) 0x2020A0))

// Message Object 134 Function Control Register High
#define CAN_MOFCR134H          (*((uword volatile far *) 0x2020C2))

// Message Object 134 Function Control Register Low
#define CAN_MOFCR134L          (*((uword volatile far *) 0x2020C0))

// Message Object 135 Function Control Register High
#define CAN_MOFCR135H          (*((uword volatile far *) 0x2020E2))

// Message Object 135 Function Control Register Low
#define CAN_MOFCR135L          (*((uword volatile far *) 0x2020E0))

// Message Object 136 Function Control Register High
#define CAN_MOFCR136H          (*((uword volatile far *) 0x202102))

// Message Object 136 Function Control Register Low
#define CAN_MOFCR136L          (*((uword volatile far *) 0x202100))

// Message Object 137 Function Control Register High
#define CAN_MOFCR137H          (*((uword volatile far *) 0x202122))

// Message Object 137 Function Control Register Low
#define CAN_MOFCR137L          (*((uword volatile far *) 0x202120))

// Message Object 138 Function Control Register High
#define CAN_MOFCR138H          (*((uword volatile far *) 0x202142))

// Message Object 138 Function Control Register Low
#define CAN_MOFCR138L          (*((uword volatile far *) 0x202140))

// Message Object 139 Function Control Register High
#define CAN_MOFCR139H          (*((uword volatile far *) 0x202162))

// Message Object 139 Function Control Register Low
#define CAN_MOFCR139L          (*((uword volatile far *) 0x202160))

// Message Object 13 Function Control Register High
#define CAN_MOFCR13H           (*((uword volatile far *) 0x2011A2))

// Message Object 13 Function Control Register Low
#define CAN_MOFCR13L           (*((uword volatile far *) 0x2011A0))

// Message Object 140 Function Control Register High
#define CAN_MOFCR140H          (*((uword volatile far *) 0x202182))

// Message Object 140 Function Control Register Low
#define CAN_MOFCR140L          (*((uword volatile far *) 0x202180))

// Message Object 141 Function Control Register High
#define CAN_MOFCR141H          (*((uword volatile far *) 0x2021A2))

// Message Object 141 Function Control Register Low
#define CAN_MOFCR141L          (*((uword volatile far *) 0x2021A0))

// Message Object 142 Function Control Register High
#define CAN_MOFCR142H          (*((uword volatile far *) 0x2021C2))

// Message Object 142 Function Control Register Low
#define CAN_MOFCR142L          (*((uword volatile far *) 0x2021C0))

// Message Object 143 Function Control Register High
#define CAN_MOFCR143H          (*((uword volatile far *) 0x2021E2))

// Message Object 143 Function Control Register Low
#define CAN_MOFCR143L          (*((uword volatile far *) 0x2021E0))

// Message Object 144 Function Control Register High
#define CAN_MOFCR144H          (*((uword volatile far *) 0x202202))

// Message Object 144 Function Control Register Low
#define CAN_MOFCR144L          (*((uword volatile far *) 0x202200))

// Message Object 145 Function Control Register High
#define CAN_MOFCR145H          (*((uword volatile far *) 0x202222))

// Message Object 145 Function Control Register Low
#define CAN_MOFCR145L          (*((uword volatile far *) 0x202220))

// Message Object 146 Function Control Register High
#define CAN_MOFCR146H          (*((uword volatile far *) 0x202242))

// Message Object 146 Function Control Register Low
#define CAN_MOFCR146L          (*((uword volatile far *) 0x202240))

// Message Object 147 Function Control Register High
#define CAN_MOFCR147H          (*((uword volatile far *) 0x202262))

// Message Object 147 Function Control Register Low
#define CAN_MOFCR147L          (*((uword volatile far *) 0x202260))

// Message Object 148 Function Control Register High
#define CAN_MOFCR148H          (*((uword volatile far *) 0x202282))

// Message Object 148 Function Control Register Low
#define CAN_MOFCR148L          (*((uword volatile far *) 0x202280))

// Message Object 149 Function Control Register High
#define CAN_MOFCR149H          (*((uword volatile far *) 0x2022A2))

// Message Object 149 Function Control Register Low
#define CAN_MOFCR149L          (*((uword volatile far *) 0x2022A0))

// Message Object 14 Function Control Register High
#define CAN_MOFCR14H           (*((uword volatile far *) 0x2011C2))

// Message Object 14 Function Control Register Low
#define CAN_MOFCR14L           (*((uword volatile far *) 0x2011C0))

// Message Object 150 Function Control Register High
#define CAN_MOFCR150H          (*((uword volatile far *) 0x2022C2))

// Message Object 150 Function Control Register Low
#define CAN_MOFCR150L          (*((uword volatile far *) 0x2022C0))

// Message Object 151 Function Control Register High
#define CAN_MOFCR151H          (*((uword volatile far *) 0x2022E2))

// Message Object 151 Function Control Register Low
#define CAN_MOFCR151L          (*((uword volatile far *) 0x2022E0))

// Message Object 152 Function Control Register High
#define CAN_MOFCR152H          (*((uword volatile far *) 0x202302))

// Message Object 152 Function Control Register Low
#define CAN_MOFCR152L          (*((uword volatile far *) 0x202300))

// Message Object 153 Function Control Register High
#define CAN_MOFCR153H          (*((uword volatile far *) 0x202322))

// Message Object 153 Function Control Register Low
#define CAN_MOFCR153L          (*((uword volatile far *) 0x202320))

// Message Object 154 Function Control Register High
#define CAN_MOFCR154H          (*((uword volatile far *) 0x202342))

// Message Object 154 Function Control Register Low
#define CAN_MOFCR154L          (*((uword volatile far *) 0x202340))

// Message Object 155 Function Control Register High
#define CAN_MOFCR155H          (*((uword volatile far *) 0x202362))

// Message Object 155 Function Control Register Low
#define CAN_MOFCR155L          (*((uword volatile far *) 0x202360))

// Message Object 156 Function Control Register High
#define CAN_MOFCR156H          (*((uword volatile far *) 0x202382))

// Message Object 156 Function Control Register Low
#define CAN_MOFCR156L          (*((uword volatile far *) 0x202380))

// Message Object 157 Function Control Register High
#define CAN_MOFCR157H          (*((uword volatile far *) 0x2023A2))

// Message Object 157 Function Control Register Low
#define CAN_MOFCR157L          (*((uword volatile far *) 0x2023A0))

// Message Object 158 Function Control Register High
#define CAN_MOFCR158H          (*((uword volatile far *) 0x2023C2))

// Message Object 158 Function Control Register Low
#define CAN_MOFCR158L          (*((uword volatile far *) 0x2023C0))

// Message Object 159 Function Control Register High
#define CAN_MOFCR159H          (*((uword volatile far *) 0x2023E2))

// Message Object 159 Function Control Register Low
#define CAN_MOFCR159L          (*((uword volatile far *) 0x2023E0))

// Message Object 15 Function Control Register High
#define CAN_MOFCR15H           (*((uword volatile far *) 0x2011E2))

// Message Object 15 Function Control Register Low
#define CAN_MOFCR15L           (*((uword volatile far *) 0x2011E0))

// Message Object 160 Function Control Register High
#define CAN_MOFCR160H          (*((uword volatile far *) 0x202402))

// Message Object 160 Function Control Register Low
#define CAN_MOFCR160L          (*((uword volatile far *) 0x202400))

// Message Object 161 Function Control Register High
#define CAN_MOFCR161H          (*((uword volatile far *) 0x202422))

// Message Object 161 Function Control Register Low
#define CAN_MOFCR161L          (*((uword volatile far *) 0x202420))

// Message Object 162 Function Control Register High
#define CAN_MOFCR162H          (*((uword volatile far *) 0x202442))

// Message Object 162 Function Control Register Low
#define CAN_MOFCR162L          (*((uword volatile far *) 0x202440))

// Message Object 163 Function Control Register High
#define CAN_MOFCR163H          (*((uword volatile far *) 0x202462))

// Message Object 163 Function Control Register Low
#define CAN_MOFCR163L          (*((uword volatile far *) 0x202460))

// Message Object 164 Function Control Register High
#define CAN_MOFCR164H          (*((uword volatile far *) 0x202482))

// Message Object 164 Function Control Register Low
#define CAN_MOFCR164L          (*((uword volatile far *) 0x202480))

// Message Object 165 Function Control Register High
#define CAN_MOFCR165H          (*((uword volatile far *) 0x2024A2))

// Message Object 165 Function Control Register Low
#define CAN_MOFCR165L          (*((uword volatile far *) 0x2024A0))

// Message Object 166 Function Control Register High
#define CAN_MOFCR166H          (*((uword volatile far *) 0x2024C2))

// Message Object 166 Function Control Register Low
#define CAN_MOFCR166L          (*((uword volatile far *) 0x2024C0))

// Message Object 167 Function Control Register High
#define CAN_MOFCR167H          (*((uword volatile far *) 0x2024E2))

// Message Object 167 Function Control Register Low
#define CAN_MOFCR167L          (*((uword volatile far *) 0x2024E0))

// Message Object 168 Function Control Register High
#define CAN_MOFCR168H          (*((uword volatile far *) 0x202502))

// Message Object 168 Function Control Register Low
#define CAN_MOFCR168L          (*((uword volatile far *) 0x202500))

// Message Object 169 Function Control Register High
#define CAN_MOFCR169H          (*((uword volatile far *) 0x202522))

// Message Object 169 Function Control Register Low
#define CAN_MOFCR169L          (*((uword volatile far *) 0x202520))

// Message Object 16 Function Control Register High
#define CAN_MOFCR16H           (*((uword volatile far *) 0x201202))

// Message Object 16 Function Control Register Low
#define CAN_MOFCR16L           (*((uword volatile far *) 0x201200))

// Message Object 170 Function Control Register High
#define CAN_MOFCR170H          (*((uword volatile far *) 0x202542))

// Message Object 170 Function Control Register Low
#define CAN_MOFCR170L          (*((uword volatile far *) 0x202540))

// Message Object 171 Function Control Register High
#define CAN_MOFCR171H          (*((uword volatile far *) 0x202562))

// Message Object 171 Function Control Register Low
#define CAN_MOFCR171L          (*((uword volatile far *) 0x202560))

// Message Object 172 Function Control Register High
#define CAN_MOFCR172H          (*((uword volatile far *) 0x202582))

// Message Object 172 Function Control Register Low
#define CAN_MOFCR172L          (*((uword volatile far *) 0x202580))

// Message Object 173 Function Control Register High
#define CAN_MOFCR173H          (*((uword volatile far *) 0x2025A2))

// Message Object 173 Function Control Register Low
#define CAN_MOFCR173L          (*((uword volatile far *) 0x2025A0))

// Message Object 174 Function Control Register High
#define CAN_MOFCR174H          (*((uword volatile far *) 0x2025C2))

// Message Object 174 Function Control Register Low
#define CAN_MOFCR174L          (*((uword volatile far *) 0x2025C0))

// Message Object 175 Function Control Register High
#define CAN_MOFCR175H          (*((uword volatile far *) 0x2025E2))

// Message Object 175 Function Control Register Low
#define CAN_MOFCR175L          (*((uword volatile far *) 0x2025E0))

// Message Object 176 Function Control Register High
#define CAN_MOFCR176H          (*((uword volatile far *) 0x202602))

// Message Object 176 Function Control Register Low
#define CAN_MOFCR176L          (*((uword volatile far *) 0x202600))

// Message Object 177 Function Control Register High
#define CAN_MOFCR177H          (*((uword volatile far *) 0x202622))

// Message Object 177 Function Control Register Low
#define CAN_MOFCR177L          (*((uword volatile far *) 0x202620))

// Message Object 178 Function Control Register High
#define CAN_MOFCR178H          (*((uword volatile far *) 0x202642))

// Message Object 178 Function Control Register Low
#define CAN_MOFCR178L          (*((uword volatile far *) 0x202640))

// Message Object 179 Function Control Register High
#define CAN_MOFCR179H          (*((uword volatile far *) 0x202662))

// Message Object 179 Function Control Register Low
#define CAN_MOFCR179L          (*((uword volatile far *) 0x202660))

// Message Object 17 Function Control Register High
#define CAN_MOFCR17H           (*((uword volatile far *) 0x201222))

// Message Object 17 Function Control Register Low
#define CAN_MOFCR17L           (*((uword volatile far *) 0x201220))

// Message Object 180 Function Control Register High
#define CAN_MOFCR180H          (*((uword volatile far *) 0x202682))

// Message Object 180 Function Control Register Low
#define CAN_MOFCR180L          (*((uword volatile far *) 0x202680))

// Message Object 181 Function Control Register High
#define CAN_MOFCR181H          (*((uword volatile far *) 0x2026A2))

// Message Object 181 Function Control Register Low
#define CAN_MOFCR181L          (*((uword volatile far *) 0x2026A0))

// Message Object 182 Function Control Register High
#define CAN_MOFCR182H          (*((uword volatile far *) 0x2026C2))

// Message Object 182 Function Control Register Low
#define CAN_MOFCR182L          (*((uword volatile far *) 0x2026C0))

// Message Object 183 Function Control Register High
#define CAN_MOFCR183H          (*((uword volatile far *) 0x2026E2))

// Message Object 183 Function Control Register Low
#define CAN_MOFCR183L          (*((uword volatile far *) 0x2026E0))

// Message Object 184 Function Control Register High
#define CAN_MOFCR184H          (*((uword volatile far *) 0x202702))

// Message Object 184 Function Control Register Low
#define CAN_MOFCR184L          (*((uword volatile far *) 0x202700))

// Message Object 185 Function Control Register High
#define CAN_MOFCR185H          (*((uword volatile far *) 0x202722))

// Message Object 185 Function Control Register Low
#define CAN_MOFCR185L          (*((uword volatile far *) 0x202720))

// Message Object 186 Function Control Register High
#define CAN_MOFCR186H          (*((uword volatile far *) 0x202742))

// Message Object 186 Function Control Register Low
#define CAN_MOFCR186L          (*((uword volatile far *) 0x202740))

// Message Object 187 Function Control Register High
#define CAN_MOFCR187H          (*((uword volatile far *) 0x202762))

// Message Object 187 Function Control Register Low
#define CAN_MOFCR187L          (*((uword volatile far *) 0x202760))

// Message Object 188 Function Control Register High
#define CAN_MOFCR188H          (*((uword volatile far *) 0x202782))

// Message Object 188 Function Control Register Low
#define CAN_MOFCR188L          (*((uword volatile far *) 0x202780))

// Message Object 189 Function Control Register High
#define CAN_MOFCR189H          (*((uword volatile far *) 0x2027A2))

// Message Object 189 Function Control Register Low
#define CAN_MOFCR189L          (*((uword volatile far *) 0x2027A0))

// Message Object 18 Function Control Register High
#define CAN_MOFCR18H           (*((uword volatile far *) 0x201242))

// Message Object 18 Function Control Register Low
#define CAN_MOFCR18L           (*((uword volatile far *) 0x201240))

// Message Object 190 Function Control Register High
#define CAN_MOFCR190H          (*((uword volatile far *) 0x2027C2))

// Message Object 190 Function Control Register Low
#define CAN_MOFCR190L          (*((uword volatile far *) 0x2027C0))

// Message Object 191 Function Control Register High
#define CAN_MOFCR191H          (*((uword volatile far *) 0x2027E2))

// Message Object 191 Function Control Register Low
#define CAN_MOFCR191L          (*((uword volatile far *) 0x2027E0))

// Message Object 192 Function Control Register High
#define CAN_MOFCR192H          (*((uword volatile far *) 0x202802))

// Message Object 192 Function Control Register Low
#define CAN_MOFCR192L          (*((uword volatile far *) 0x202800))

// Message Object 193 Function Control Register High
#define CAN_MOFCR193H          (*((uword volatile far *) 0x202822))

// Message Object 193 Function Control Register Low
#define CAN_MOFCR193L          (*((uword volatile far *) 0x202820))

// Message Object 194 Function Control Register High
#define CAN_MOFCR194H          (*((uword volatile far *) 0x202842))

// Message Object 194 Function Control Register Low
#define CAN_MOFCR194L          (*((uword volatile far *) 0x202840))

// Message Object 195 Function Control Register High
#define CAN_MOFCR195H          (*((uword volatile far *) 0x202862))

// Message Object 195 Function Control Register Low
#define CAN_MOFCR195L          (*((uword volatile far *) 0x202860))

// Message Object 196 Function Control Register High
#define CAN_MOFCR196H          (*((uword volatile far *) 0x202882))

// Message Object 196 Function Control Register Low
#define CAN_MOFCR196L          (*((uword volatile far *) 0x202880))

// Message Object 197 Function Control Register High
#define CAN_MOFCR197H          (*((uword volatile far *) 0x2028A2))

// Message Object 197 Function Control Register Low
#define CAN_MOFCR197L          (*((uword volatile far *) 0x2028A0))

// Message Object 198 Function Control Register High
#define CAN_MOFCR198H          (*((uword volatile far *) 0x2028C2))

// Message Object 198 Function Control Register Low
#define CAN_MOFCR198L          (*((uword volatile far *) 0x2028C0))

// Message Object 199 Function Control Register High
#define CAN_MOFCR199H          (*((uword volatile far *) 0x2028E2))

// Message Object 199 Function Control Register Low
#define CAN_MOFCR199L          (*((uword volatile far *) 0x2028E0))

// Message Object 19 Function Control Register High
#define CAN_MOFCR19H           (*((uword volatile far *) 0x201262))

// Message Object 19 Function Control Register Low
#define CAN_MOFCR19L           (*((uword volatile far *) 0x201260))

// Message Object 1 Function Control Register High
#define CAN_MOFCR1H            (*((uword volatile far *) 0x201022))

// Message Object 1 Function Control Register Low
#define CAN_MOFCR1L            (*((uword volatile far *) 0x201020))

// Message Object 200 Function Control Register High
#define CAN_MOFCR200H          (*((uword volatile far *) 0x202902))

// Message Object 200 Function Control Register Low
#define CAN_MOFCR200L          (*((uword volatile far *) 0x202900))

// Message Object 201 Function Control Register High
#define CAN_MOFCR201H          (*((uword volatile far *) 0x202922))

// Message Object 201 Function Control Register Low
#define CAN_MOFCR201L          (*((uword volatile far *) 0x202920))

// Message Object 202 Function Control Register High
#define CAN_MOFCR202H          (*((uword volatile far *) 0x202942))

// Message Object 202 Function Control Register Low
#define CAN_MOFCR202L          (*((uword volatile far *) 0x202940))

// Message Object 203 Function Control Register High
#define CAN_MOFCR203H          (*((uword volatile far *) 0x202962))

// Message Object 203 Function Control Register Low
#define CAN_MOFCR203L          (*((uword volatile far *) 0x202960))

// Message Object 204 Function Control Register High
#define CAN_MOFCR204H          (*((uword volatile far *) 0x202982))

// Message Object 204 Function Control Register Low
#define CAN_MOFCR204L          (*((uword volatile far *) 0x202980))

// Message Object 205 Function Control Register High
#define CAN_MOFCR205H          (*((uword volatile far *) 0x2029A2))

// Message Object 205 Function Control Register Low
#define CAN_MOFCR205L          (*((uword volatile far *) 0x2029A0))

// Message Object 206 Function Control Register High
#define CAN_MOFCR206H          (*((uword volatile far *) 0x2029C2))

// Message Object 206 Function Control Register Low
#define CAN_MOFCR206L          (*((uword volatile far *) 0x2029C0))

// Message Object 207 Function Control Register High
#define CAN_MOFCR207H          (*((uword volatile far *) 0x2029E2))

// Message Object 207 Function Control Register Low
#define CAN_MOFCR207L          (*((uword volatile far *) 0x2029E0))

// Message Object 208 Function Control Register High
#define CAN_MOFCR208H          (*((uword volatile far *) 0x202A02))

// Message Object 208 Function Control Register Low
#define CAN_MOFCR208L          (*((uword volatile far *) 0x202A00))

// Message Object 209 Function Control Register High
#define CAN_MOFCR209H          (*((uword volatile far *) 0x202A22))

// Message Object 209 Function Control Register Low
#define CAN_MOFCR209L          (*((uword volatile far *) 0x202A20))

// Message Object 20 Function Control Register High
#define CAN_MOFCR20H           (*((uword volatile far *) 0x201282))

// Message Object 20 Function Control Register Low
#define CAN_MOFCR20L           (*((uword volatile far *) 0x201280))

// Message Object 210 Function Control Register High
#define CAN_MOFCR210H          (*((uword volatile far *) 0x202A42))

// Message Object 210 Function Control Register Low
#define CAN_MOFCR210L          (*((uword volatile far *) 0x202A40))

// Message Object 211 Function Control Register High
#define CAN_MOFCR211H          (*((uword volatile far *) 0x202A62))

// Message Object 211 Function Control Register Low
#define CAN_MOFCR211L          (*((uword volatile far *) 0x202A60))

// Message Object 212 Function Control Register High
#define CAN_MOFCR212H          (*((uword volatile far *) 0x202A82))

// Message Object 212 Function Control Register Low
#define CAN_MOFCR212L          (*((uword volatile far *) 0x202A80))

// Message Object 213 Function Control Register High
#define CAN_MOFCR213H          (*((uword volatile far *) 0x202AA2))

// Message Object 213 Function Control Register Low
#define CAN_MOFCR213L          (*((uword volatile far *) 0x202AA0))

// Message Object 214 Function Control Register High
#define CAN_MOFCR214H          (*((uword volatile far *) 0x202AC2))

// Message Object 214 Function Control Register Low
#define CAN_MOFCR214L          (*((uword volatile far *) 0x202AC0))

// Message Object 215 Function Control Register High
#define CAN_MOFCR215H          (*((uword volatile far *) 0x202AE2))

// Message Object 215 Function Control Register Low
#define CAN_MOFCR215L          (*((uword volatile far *) 0x202AE0))

// Message Object 216 Function Control Register High
#define CAN_MOFCR216H          (*((uword volatile far *) 0x202B02))

// Message Object 216 Function Control Register Low
#define CAN_MOFCR216L          (*((uword volatile far *) 0x202B00))

// Message Object 217 Function Control Register High
#define CAN_MOFCR217H          (*((uword volatile far *) 0x202B22))

// Message Object 217 Function Control Register Low
#define CAN_MOFCR217L          (*((uword volatile far *) 0x202B20))

// Message Object 218 Function Control Register High
#define CAN_MOFCR218H          (*((uword volatile far *) 0x202B42))

// Message Object 218 Function Control Register Low
#define CAN_MOFCR218L          (*((uword volatile far *) 0x202B40))

// Message Object 219 Function Control Register High
#define CAN_MOFCR219H          (*((uword volatile far *) 0x202B62))

// Message Object 219 Function Control Register Low
#define CAN_MOFCR219L          (*((uword volatile far *) 0x202B60))

// Message Object 21 Function Control Register High
#define CAN_MOFCR21H           (*((uword volatile far *) 0x2012A2))

// Message Object 21 Function Control Register Low
#define CAN_MOFCR21L           (*((uword volatile far *) 0x2012A0))

// Message Object 220 Function Control Register High
#define CAN_MOFCR220H          (*((uword volatile far *) 0x202B82))

// Message Object 220 Function Control Register Low
#define CAN_MOFCR220L          (*((uword volatile far *) 0x202B80))

// Message Object 221 Function Control Register High
#define CAN_MOFCR221H          (*((uword volatile far *) 0x202BA2))

// Message Object 221 Function Control Register Low
#define CAN_MOFCR221L          (*((uword volatile far *) 0x202BA0))

// Message Object 222 Function Control Register High
#define CAN_MOFCR222H          (*((uword volatile far *) 0x202BC2))

// Message Object 222 Function Control Register Low
#define CAN_MOFCR222L          (*((uword volatile far *) 0x202BC0))

// Message Object 223 Function Control Register High
#define CAN_MOFCR223H          (*((uword volatile far *) 0x202BE2))

// Message Object 223 Function Control Register Low
#define CAN_MOFCR223L          (*((uword volatile far *) 0x202BE0))

// Message Object 224 Function Control Register High
#define CAN_MOFCR224H          (*((uword volatile far *) 0x202C02))

// Message Object 224 Function Control Register Low
#define CAN_MOFCR224L          (*((uword volatile far *) 0x202C00))

// Message Object 225 Function Control Register High
#define CAN_MOFCR225H          (*((uword volatile far *) 0x202C22))

// Message Object 225 Function Control Register Low
#define CAN_MOFCR225L          (*((uword volatile far *) 0x202C20))

// Message Object 226 Function Control Register High
#define CAN_MOFCR226H          (*((uword volatile far *) 0x202C42))

// Message Object 226 Function Control Register Low
#define CAN_MOFCR226L          (*((uword volatile far *) 0x202C40))

// Message Object 227 Function Control Register High
#define CAN_MOFCR227H          (*((uword volatile far *) 0x202C62))

// Message Object 227 Function Control Register Low
#define CAN_MOFCR227L          (*((uword volatile far *) 0x202C60))

// Message Object 228 Function Control Register High
#define CAN_MOFCR228H          (*((uword volatile far *) 0x202C82))

// Message Object 228 Function Control Register Low
#define CAN_MOFCR228L          (*((uword volatile far *) 0x202C80))

// Message Object 229 Function Control Register High
#define CAN_MOFCR229H          (*((uword volatile far *) 0x202CA2))

// Message Object 229 Function Control Register Low
#define CAN_MOFCR229L          (*((uword volatile far *) 0x202CA0))

// Message Object 22 Function Control Register High
#define CAN_MOFCR22H           (*((uword volatile far *) 0x2012C2))

// Message Object 22 Function Control Register Low
#define CAN_MOFCR22L           (*((uword volatile far *) 0x2012C0))

// Message Object 230 Function Control Register High
#define CAN_MOFCR230H          (*((uword volatile far *) 0x202CC2))

// Message Object 230 Function Control Register Low
#define CAN_MOFCR230L          (*((uword volatile far *) 0x202CC0))

// Message Object 231 Function Control Register High
#define CAN_MOFCR231H          (*((uword volatile far *) 0x202CE2))

// Message Object 231 Function Control Register Low
#define CAN_MOFCR231L          (*((uword volatile far *) 0x202CE0))

// Message Object 232 Function Control Register High
#define CAN_MOFCR232H          (*((uword volatile far *) 0x202D02))

// Message Object 232 Function Control Register Low
#define CAN_MOFCR232L          (*((uword volatile far *) 0x202D00))

// Message Object 233 Function Control Register High
#define CAN_MOFCR233H          (*((uword volatile far *) 0x202D22))

// Message Object 233 Function Control Register Low
#define CAN_MOFCR233L          (*((uword volatile far *) 0x202D20))

// Message Object 234 Function Control Register High
#define CAN_MOFCR234H          (*((uword volatile far *) 0x202D42))

// Message Object 234 Function Control Register Low
#define CAN_MOFCR234L          (*((uword volatile far *) 0x202D40))

// Message Object 235 Function Control Register High
#define CAN_MOFCR235H          (*((uword volatile far *) 0x202D62))

// Message Object 235 Function Control Register Low
#define CAN_MOFCR235L          (*((uword volatile far *) 0x202D60))

// Message Object 236 Function Control Register High
#define CAN_MOFCR236H          (*((uword volatile far *) 0x202D82))

// Message Object 236 Function Control Register Low
#define CAN_MOFCR236L          (*((uword volatile far *) 0x202D80))

// Message Object 237 Function Control Register High
#define CAN_MOFCR237H          (*((uword volatile far *) 0x202DA2))

// Message Object 237 Function Control Register Low
#define CAN_MOFCR237L          (*((uword volatile far *) 0x202DA0))

// Message Object 238 Function Control Register High
#define CAN_MOFCR238H          (*((uword volatile far *) 0x202DC2))

// Message Object 238 Function Control Register Low
#define CAN_MOFCR238L          (*((uword volatile far *) 0x202DC0))

// Message Object 239 Function Control Register High
#define CAN_MOFCR239H          (*((uword volatile far *) 0x202DE2))

// Message Object 239 Function Control Register Low
#define CAN_MOFCR239L          (*((uword volatile far *) 0x202DE0))

// Message Object 23 Function Control Register High
#define CAN_MOFCR23H           (*((uword volatile far *) 0x2012E2))

// Message Object 23 Function Control Register Low
#define CAN_MOFCR23L           (*((uword volatile far *) 0x2012E0))

// Message Object 240 Function Control Register High
#define CAN_MOFCR240H          (*((uword volatile far *) 0x202E02))

// Message Object 240 Function Control Register Low
#define CAN_MOFCR240L          (*((uword volatile far *) 0x202E00))

// Message Object 241 Function Control Register High
#define CAN_MOFCR241H          (*((uword volatile far *) 0x202E22))

// Message Object 241 Function Control Register Low
#define CAN_MOFCR241L          (*((uword volatile far *) 0x202E20))

// Message Object 242 Function Control Register High
#define CAN_MOFCR242H          (*((uword volatile far *) 0x202E42))

// Message Object 242 Function Control Register Low
#define CAN_MOFCR242L          (*((uword volatile far *) 0x202E40))

// Message Object 243 Function Control Register High
#define CAN_MOFCR243H          (*((uword volatile far *) 0x202E62))

// Message Object 243 Function Control Register Low
#define CAN_MOFCR243L          (*((uword volatile far *) 0x202E60))

// Message Object 244 Function Control Register High
#define CAN_MOFCR244H          (*((uword volatile far *) 0x202E82))

// Message Object 244 Function Control Register Low
#define CAN_MOFCR244L          (*((uword volatile far *) 0x202E80))

// Message Object 245 Function Control Register High
#define CAN_MOFCR245H          (*((uword volatile far *) 0x202EA2))

// Message Object 245 Function Control Register Low
#define CAN_MOFCR245L          (*((uword volatile far *) 0x202EA0))

// Message Object 246 Function Control Register High
#define CAN_MOFCR246H          (*((uword volatile far *) 0x202EC2))

// Message Object 246 Function Control Register Low
#define CAN_MOFCR246L          (*((uword volatile far *) 0x202EC0))

// Message Object 247 Function Control Register High
#define CAN_MOFCR247H          (*((uword volatile far *) 0x202EE2))

// Message Object 247 Function Control Register Low
#define CAN_MOFCR247L          (*((uword volatile far *) 0x202EE0))

// Message Object 248 Function Control Register High
#define CAN_MOFCR248H          (*((uword volatile far *) 0x202F02))

// Message Object 248 Function Control Register Low
#define CAN_MOFCR248L          (*((uword volatile far *) 0x202F00))

// Message Object 249 Function Control Register High
#define CAN_MOFCR249H          (*((uword volatile far *) 0x202F22))

// Message Object 249 Function Control Register Low
#define CAN_MOFCR249L          (*((uword volatile far *) 0x202F20))

// Message Object 24 Function Control Register High
#define CAN_MOFCR24H           (*((uword volatile far *) 0x201302))

// Message Object 24 Function Control Register Low
#define CAN_MOFCR24L           (*((uword volatile far *) 0x201300))

// Message Object 250 Function Control Register High
#define CAN_MOFCR250H          (*((uword volatile far *) 0x202F42))

// Message Object 250 Function Control Register Low
#define CAN_MOFCR250L          (*((uword volatile far *) 0x202F40))

// Message Object 251 Function Control Register High
#define CAN_MOFCR251H          (*((uword volatile far *) 0x202F62))

// Message Object 251 Function Control Register Low
#define CAN_MOFCR251L          (*((uword volatile far *) 0x202F60))

// Message Object 252 Function Control Register High
#define CAN_MOFCR252H          (*((uword volatile far *) 0x202F82))

// Message Object 252 Function Control Register Low
#define CAN_MOFCR252L          (*((uword volatile far *) 0x202F80))

// Message Object 253 Function Control Register High
#define CAN_MOFCR253H          (*((uword volatile far *) 0x202FA2))

// Message Object 253 Function Control Register Low
#define CAN_MOFCR253L          (*((uword volatile far *) 0x202FA0))

// Message Object 254 Function Control Register High
#define CAN_MOFCR254H          (*((uword volatile far *) 0x202FC2))

// Message Object 254 Function Control Register Low
#define CAN_MOFCR254L          (*((uword volatile far *) 0x202FC0))

// Message Object 255 Function Control Register High
#define CAN_MOFCR255H          (*((uword volatile far *) 0x202FE2))

// Message Object 255 Function Control Register Low
#define CAN_MOFCR255L          (*((uword volatile far *) 0x202FE0))

// Message Object 25 Function Control Register High
#define CAN_MOFCR25H           (*((uword volatile far *) 0x201322))

// Message Object 25 Function Control Register Low
#define CAN_MOFCR25L           (*((uword volatile far *) 0x201320))

// Message Object 26 Function Control Register High
#define CAN_MOFCR26H           (*((uword volatile far *) 0x201342))

// Message Object 26 Function Control Register Low
#define CAN_MOFCR26L           (*((uword volatile far *) 0x201340))

// Message Object 27 Function Control Register High
#define CAN_MOFCR27H           (*((uword volatile far *) 0x201362))

// Message Object 27 Function Control Register Low
#define CAN_MOFCR27L           (*((uword volatile far *) 0x201360))

// Message Object 28 Function Control Register High
#define CAN_MOFCR28H           (*((uword volatile far *) 0x201382))

// Message Object 28 Function Control Register Low
#define CAN_MOFCR28L           (*((uword volatile far *) 0x201380))

// Message Object 29 Function Control Register High
#define CAN_MOFCR29H           (*((uword volatile far *) 0x2013A2))

// Message Object 29 Function Control Register Low
#define CAN_MOFCR29L           (*((uword volatile far *) 0x2013A0))

// Message Object 2 Function Control Register High
#define CAN_MOFCR2H            (*((uword volatile far *) 0x201042))

// Message Object 2 Function Control Register Low
#define CAN_MOFCR2L            (*((uword volatile far *) 0x201040))

// Message Object 30 Function Control Register High
#define CAN_MOFCR30H           (*((uword volatile far *) 0x2013C2))

// Message Object 30 Function Control Register Low
#define CAN_MOFCR30L           (*((uword volatile far *) 0x2013C0))

// Message Object 31 Function Control Register High
#define CAN_MOFCR31H           (*((uword volatile far *) 0x2013E2))

// Message Object 31 Function Control Register Low
#define CAN_MOFCR31L           (*((uword volatile far *) 0x2013E0))

// Message Object 32 Function Control Register High
#define CAN_MOFCR32H           (*((uword volatile far *) 0x201402))

// Message Object 32 Function Control Register Low
#define CAN_MOFCR32L           (*((uword volatile far *) 0x201400))

// Message Object 33 Function Control Register High
#define CAN_MOFCR33H           (*((uword volatile far *) 0x201422))

// Message Object 33 Function Control Register Low
#define CAN_MOFCR33L           (*((uword volatile far *) 0x201420))

// Message Object 34 Function Control Register High
#define CAN_MOFCR34H           (*((uword volatile far *) 0x201442))

// Message Object 34 Function Control Register Low
#define CAN_MOFCR34L           (*((uword volatile far *) 0x201440))

// Message Object 35 Function Control Register High
#define CAN_MOFCR35H           (*((uword volatile far *) 0x201462))

// Message Object 35 Function Control Register Low
#define CAN_MOFCR35L           (*((uword volatile far *) 0x201460))

// Message Object 36 Function Control Register High
#define CAN_MOFCR36H           (*((uword volatile far *) 0x201482))

// Message Object 36 Function Control Register Low
#define CAN_MOFCR36L           (*((uword volatile far *) 0x201480))

// Message Object 37 Function Control Register High
#define CAN_MOFCR37H           (*((uword volatile far *) 0x2014A2))

// Message Object 37 Function Control Register Low
#define CAN_MOFCR37L           (*((uword volatile far *) 0x2014A0))

// Message Object 38 Function Control Register High
#define CAN_MOFCR38H           (*((uword volatile far *) 0x2014C2))

// Message Object 38 Function Control Register Low
#define CAN_MOFCR38L           (*((uword volatile far *) 0x2014C0))

// Message Object 39 Function Control Register High
#define CAN_MOFCR39H           (*((uword volatile far *) 0x2014E2))

// Message Object 39 Function Control Register Low
#define CAN_MOFCR39L           (*((uword volatile far *) 0x2014E0))

// Message Object 3 Function Control Register High
#define CAN_MOFCR3H            (*((uword volatile far *) 0x201062))

// Message Object 3 Function Control Register Low
#define CAN_MOFCR3L            (*((uword volatile far *) 0x201060))

// Message Object 40 Function Control Register High
#define CAN_MOFCR40H           (*((uword volatile far *) 0x201502))

// Message Object 40 Function Control Register Low
#define CAN_MOFCR40L           (*((uword volatile far *) 0x201500))

// Message Object 41 Function Control Register High
#define CAN_MOFCR41H           (*((uword volatile far *) 0x201522))

// Message Object 41 Function Control Register Low
#define CAN_MOFCR41L           (*((uword volatile far *) 0x201520))

// Message Object 42 Function Control Register High
#define CAN_MOFCR42H           (*((uword volatile far *) 0x201542))

// Message Object 42 Function Control Register Low
#define CAN_MOFCR42L           (*((uword volatile far *) 0x201540))

// Message Object 43 Function Control Register High
#define CAN_MOFCR43H           (*((uword volatile far *) 0x201562))

// Message Object 43 Function Control Register Low
#define CAN_MOFCR43L           (*((uword volatile far *) 0x201560))

// Message Object 44 Function Control Register High
#define CAN_MOFCR44H           (*((uword volatile far *) 0x201582))

// Message Object 44 Function Control Register Low
#define CAN_MOFCR44L           (*((uword volatile far *) 0x201580))

// Message Object 45 Function Control Register High
#define CAN_MOFCR45H           (*((uword volatile far *) 0x2015A2))

// Message Object 45 Function Control Register Low
#define CAN_MOFCR45L           (*((uword volatile far *) 0x2015A0))

// Message Object 46 Function Control Register High
#define CAN_MOFCR46H           (*((uword volatile far *) 0x2015C2))

// Message Object 46 Function Control Register Low
#define CAN_MOFCR46L           (*((uword volatile far *) 0x2015C0))

// Message Object 47 Function Control Register High
#define CAN_MOFCR47H           (*((uword volatile far *) 0x2015E2))

// Message Object 47 Function Control Register Low
#define CAN_MOFCR47L           (*((uword volatile far *) 0x2015E0))

// Message Object 48 Function Control Register High
#define CAN_MOFCR48H           (*((uword volatile far *) 0x201602))

// Message Object 48 Function Control Register Low
#define CAN_MOFCR48L           (*((uword volatile far *) 0x201600))

// Message Object 49 Function Control Register High
#define CAN_MOFCR49H           (*((uword volatile far *) 0x201622))

// Message Object 49 Function Control Register Low
#define CAN_MOFCR49L           (*((uword volatile far *) 0x201620))

// Message Object 4 Function Control Register High
#define CAN_MOFCR4H            (*((uword volatile far *) 0x201082))

// Message Object 4 Function Control Register Low
#define CAN_MOFCR4L            (*((uword volatile far *) 0x201080))

// Message Object 50 Function Control Register High
#define CAN_MOFCR50H           (*((uword volatile far *) 0x201642))

// Message Object 50 Function Control Register Low
#define CAN_MOFCR50L           (*((uword volatile far *) 0x201640))

// Message Object 51 Function Control Register High
#define CAN_MOFCR51H           (*((uword volatile far *) 0x201662))

// Message Object 51 Function Control Register Low
#define CAN_MOFCR51L           (*((uword volatile far *) 0x201660))

// Message Object 52 Function Control Register High
#define CAN_MOFCR52H           (*((uword volatile far *) 0x201682))

// Message Object 52 Function Control Register Low
#define CAN_MOFCR52L           (*((uword volatile far *) 0x201680))

// Message Object 53 Function Control Register High
#define CAN_MOFCR53H           (*((uword volatile far *) 0x2016A2))

// Message Object 53 Function Control Register Low
#define CAN_MOFCR53L           (*((uword volatile far *) 0x2016A0))

// Message Object 54 Function Control Register High
#define CAN_MOFCR54H           (*((uword volatile far *) 0x2016C2))

// Message Object 54 Function Control Register Low
#define CAN_MOFCR54L           (*((uword volatile far *) 0x2016C0))

// Message Object 55 Function Control Register High
#define CAN_MOFCR55H           (*((uword volatile far *) 0x2016E2))

// Message Object 55 Function Control Register Low
#define CAN_MOFCR55L           (*((uword volatile far *) 0x2016E0))

// Message Object 56 Function Control Register High
#define CAN_MOFCR56H           (*((uword volatile far *) 0x201702))

// Message Object 56 Function Control Register Low
#define CAN_MOFCR56L           (*((uword volatile far *) 0x201700))

// Message Object 57 Function Control Register High
#define CAN_MOFCR57H           (*((uword volatile far *) 0x201722))

// Message Object 57 Function Control Register Low
#define CAN_MOFCR57L           (*((uword volatile far *) 0x201720))

// Message Object 58 Function Control Register High
#define CAN_MOFCR58H           (*((uword volatile far *) 0x201742))

// Message Object 58 Function Control Register Low
#define CAN_MOFCR58L           (*((uword volatile far *) 0x201740))

// Message Object 59 Function Control Register High
#define CAN_MOFCR59H           (*((uword volatile far *) 0x201762))

// Message Object 59 Function Control Register Low
#define CAN_MOFCR59L           (*((uword volatile far *) 0x201760))

// Message Object 5 Function Control Register High
#define CAN_MOFCR5H            (*((uword volatile far *) 0x2010A2))

// Message Object 5 Function Control Register Low
#define CAN_MOFCR5L            (*((uword volatile far *) 0x2010A0))

// Message Object 60 Function Control Register High
#define CAN_MOFCR60H           (*((uword volatile far *) 0x201782))

// Message Object 60 Function Control Register Low
#define CAN_MOFCR60L           (*((uword volatile far *) 0x201780))

// Message Object 61 Function Control Register High
#define CAN_MOFCR61H           (*((uword volatile far *) 0x2017A2))

// Message Object 61 Function Control Register Low
#define CAN_MOFCR61L           (*((uword volatile far *) 0x2017A0))

// Message Object 62 Function Control Register High
#define CAN_MOFCR62H           (*((uword volatile far *) 0x2017C2))

// Message Object 62 Function Control Register Low
#define CAN_MOFCR62L           (*((uword volatile far *) 0x2017C0))

// Message Object 63 Function Control Register High
#define CAN_MOFCR63H           (*((uword volatile far *) 0x2017E2))

// Message Object 63 Function Control Register Low
#define CAN_MOFCR63L           (*((uword volatile far *) 0x2017E0))

// Message Object 64 Function Control Register High
#define CAN_MOFCR64H           (*((uword volatile far *) 0x201802))

// Message Object 64 Function Control Register Low
#define CAN_MOFCR64L           (*((uword volatile far *) 0x201800))

// Message Object 65 Function Control Register High
#define CAN_MOFCR65H           (*((uword volatile far *) 0x201822))

// Message Object 65 Function Control Register Low
#define CAN_MOFCR65L           (*((uword volatile far *) 0x201820))

// Message Object 66 Function Control Register High
#define CAN_MOFCR66H           (*((uword volatile far *) 0x201842))

// Message Object 66 Function Control Register Low
#define CAN_MOFCR66L           (*((uword volatile far *) 0x201840))

// Message Object 67 Function Control Register High
#define CAN_MOFCR67H           (*((uword volatile far *) 0x201862))

// Message Object 67 Function Control Register Low
#define CAN_MOFCR67L           (*((uword volatile far *) 0x201860))

// Message Object 68 Function Control Register High
#define CAN_MOFCR68H           (*((uword volatile far *) 0x201882))

// Message Object 68 Function Control Register Low
#define CAN_MOFCR68L           (*((uword volatile far *) 0x201880))

// Message Object 69 Function Control Register High
#define CAN_MOFCR69H           (*((uword volatile far *) 0x2018A2))

// Message Object 69 Function Control Register Low
#define CAN_MOFCR69L           (*((uword volatile far *) 0x2018A0))

// Message Object 6 Function Control Register High
#define CAN_MOFCR6H            (*((uword volatile far *) 0x2010C2))

// Message Object 6 Function Control Register Low
#define CAN_MOFCR6L            (*((uword volatile far *) 0x2010C0))

// Message Object 70 Function Control Register High
#define CAN_MOFCR70H           (*((uword volatile far *) 0x2018C2))

// Message Object 70 Function Control Register Low
#define CAN_MOFCR70L           (*((uword volatile far *) 0x2018C0))

// Message Object 71 Function Control Register High
#define CAN_MOFCR71H           (*((uword volatile far *) 0x2018E2))

// Message Object 71 Function Control Register Low
#define CAN_MOFCR71L           (*((uword volatile far *) 0x2018E0))

// Message Object 72 Function Control Register High
#define CAN_MOFCR72H           (*((uword volatile far *) 0x201902))

// Message Object 72 Function Control Register Low
#define CAN_MOFCR72L           (*((uword volatile far *) 0x201900))

// Message Object 73 Function Control Register High
#define CAN_MOFCR73H           (*((uword volatile far *) 0x201922))

// Message Object 73 Function Control Register Low
#define CAN_MOFCR73L           (*((uword volatile far *) 0x201920))

// Message Object 74 Function Control Register High
#define CAN_MOFCR74H           (*((uword volatile far *) 0x201942))

// Message Object 74 Function Control Register Low
#define CAN_MOFCR74L           (*((uword volatile far *) 0x201940))

// Message Object 75 Function Control Register High
#define CAN_MOFCR75H           (*((uword volatile far *) 0x201962))

// Message Object 75 Function Control Register Low
#define CAN_MOFCR75L           (*((uword volatile far *) 0x201960))

// Message Object 76 Function Control Register High
#define CAN_MOFCR76H           (*((uword volatile far *) 0x201982))

// Message Object 76 Function Control Register Low
#define CAN_MOFCR76L           (*((uword volatile far *) 0x201980))

// Message Object 77 Function Control Register High
#define CAN_MOFCR77H           (*((uword volatile far *) 0x2019A2))

// Message Object 77 Function Control Register Low
#define CAN_MOFCR77L           (*((uword volatile far *) 0x2019A0))

// Message Object 78 Function Control Register High
#define CAN_MOFCR78H           (*((uword volatile far *) 0x2019C2))

// Message Object 78 Function Control Register Low
#define CAN_MOFCR78L           (*((uword volatile far *) 0x2019C0))

// Message Object 79 Function Control Register High
#define CAN_MOFCR79H           (*((uword volatile far *) 0x2019E2))

// Message Object 79 Function Control Register Low
#define CAN_MOFCR79L           (*((uword volatile far *) 0x2019E0))

// Message Object 7 Function Control Register High
#define CAN_MOFCR7H            (*((uword volatile far *) 0x2010E2))

// Message Object 7 Function Control Register Low
#define CAN_MOFCR7L            (*((uword volatile far *) 0x2010E0))

// Message Object 80 Function Control Register High
#define CAN_MOFCR80H           (*((uword volatile far *) 0x201A02))

// Message Object 80 Function Control Register Low
#define CAN_MOFCR80L           (*((uword volatile far *) 0x201A00))

// Message Object 81 Function Control Register High
#define CAN_MOFCR81H           (*((uword volatile far *) 0x201A22))

// Message Object 81 Function Control Register Low
#define CAN_MOFCR81L           (*((uword volatile far *) 0x201A20))

// Message Object 82 Function Control Register High
#define CAN_MOFCR82H           (*((uword volatile far *) 0x201A42))

// Message Object 82 Function Control Register Low
#define CAN_MOFCR82L           (*((uword volatile far *) 0x201A40))

// Message Object 83 Function Control Register High
#define CAN_MOFCR83H           (*((uword volatile far *) 0x201A62))

// Message Object 83 Function Control Register Low
#define CAN_MOFCR83L           (*((uword volatile far *) 0x201A60))

// Message Object 84 Function Control Register High
#define CAN_MOFCR84H           (*((uword volatile far *) 0x201A82))

// Message Object 84 Function Control Register Low
#define CAN_MOFCR84L           (*((uword volatile far *) 0x201A80))

// Message Object 85 Function Control Register High
#define CAN_MOFCR85H           (*((uword volatile far *) 0x201AA2))

// Message Object 85 Function Control Register Low
#define CAN_MOFCR85L           (*((uword volatile far *) 0x201AA0))

// Message Object 86 Function Control Register High
#define CAN_MOFCR86H           (*((uword volatile far *) 0x201AC2))

// Message Object 86 Function Control Register Low
#define CAN_MOFCR86L           (*((uword volatile far *) 0x201AC0))

// Message Object 87 Function Control Register High
#define CAN_MOFCR87H           (*((uword volatile far *) 0x201AE2))

// Message Object 87 Function Control Register Low
#define CAN_MOFCR87L           (*((uword volatile far *) 0x201AE0))

// Message Object 88 Function Control Register High
#define CAN_MOFCR88H           (*((uword volatile far *) 0x201B02))

// Message Object 88 Function Control Register Low
#define CAN_MOFCR88L           (*((uword volatile far *) 0x201B00))

// Message Object 89 Function Control Register High
#define CAN_MOFCR89H           (*((uword volatile far *) 0x201B22))

// Message Object 89 Function Control Register Low
#define CAN_MOFCR89L           (*((uword volatile far *) 0x201B20))

// Message Object 8 Function Control Register High
#define CAN_MOFCR8H            (*((uword volatile far *) 0x201102))

// Message Object 8 Function Control Register Low
#define CAN_MOFCR8L            (*((uword volatile far *) 0x201100))

// Message Object 90 Function Control Register High
#define CAN_MOFCR90H           (*((uword volatile far *) 0x201B42))

// Message Object 90 Function Control Register Low
#define CAN_MOFCR90L           (*((uword volatile far *) 0x201B40))

// Message Object 91 Function Control Register High
#define CAN_MOFCR91H           (*((uword volatile far *) 0x201B62))

// Message Object 91 Function Control Register Low
#define CAN_MOFCR91L           (*((uword volatile far *) 0x201B60))

// Message Object 92 Function Control Register High
#define CAN_MOFCR92H           (*((uword volatile far *) 0x201B82))

// Message Object 92 Function Control Register Low
#define CAN_MOFCR92L           (*((uword volatile far *) 0x201B80))

// Message Object 93 Function Control Register High
#define CAN_MOFCR93H           (*((uword volatile far *) 0x201BA2))

// Message Object 93 Function Control Register Low
#define CAN_MOFCR93L           (*((uword volatile far *) 0x201BA0))

// Message Object 94 Function Control Register High
#define CAN_MOFCR94H           (*((uword volatile far *) 0x201BC2))

// Message Object 94 Function Control Register Low
#define CAN_MOFCR94L           (*((uword volatile far *) 0x201BC0))

// Message Object 95 Function Control Register High
#define CAN_MOFCR95H           (*((uword volatile far *) 0x201BE2))

// Message Object 95 Function Control Register Low
#define CAN_MOFCR95L           (*((uword volatile far *) 0x201BE0))

// Message Object 96 Function Control Register High
#define CAN_MOFCR96H           (*((uword volatile far *) 0x201C02))

// Message Object 96 Function Control Register Low
#define CAN_MOFCR96L           (*((uword volatile far *) 0x201C00))

// Message Object 97 Function Control Register High
#define CAN_MOFCR97H           (*((uword volatile far *) 0x201C22))

// Message Object 97 Function Control Register Low
#define CAN_MOFCR97L           (*((uword volatile far *) 0x201C20))

// Message Object 98 Function Control Register High
#define CAN_MOFCR98H           (*((uword volatile far *) 0x201C42))

// Message Object 98 Function Control Register Low
#define CAN_MOFCR98L           (*((uword volatile far *) 0x201C40))

// Message Object 99 Function Control Register High
#define CAN_MOFCR99H           (*((uword volatile far *) 0x201C62))

// Message Object 99 Function Control Register Low
#define CAN_MOFCR99L           (*((uword volatile far *) 0x201C60))

// Message Object 9 Function Control Register High
#define CAN_MOFCR9H            (*((uword volatile far *) 0x201122))

// Message Object 9 Function Control Register Low
#define CAN_MOFCR9L            (*((uword volatile far *) 0x201120))

// Message Object 0 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR0H           (*((uword volatile far *) 0x201006))

// Message Object 0 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR0L           (*((uword volatile far *) 0x201004))

// Message Object 100 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR100H         (*((uword volatile far *) 0x201C86))

// Message Object 100 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR100L         (*((uword volatile far *) 0x201C84))

// Message Object 101 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR101H         (*((uword volatile far *) 0x201CA6))

// Message Object 101 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR101L         (*((uword volatile far *) 0x201CA4))

// Message Object 102 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR102H         (*((uword volatile far *) 0x201CC6))

// Message Object 102 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR102L         (*((uword volatile far *) 0x201CC4))

// Message Object 103 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR103H         (*((uword volatile far *) 0x201CE6))

// Message Object 103 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR103L         (*((uword volatile far *) 0x201CE4))

// Message Object 104 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR104H         (*((uword volatile far *) 0x201D06))

// Message Object 104 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR104L         (*((uword volatile far *) 0x201D04))

// Message Object 105 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR105H         (*((uword volatile far *) 0x201D26))

// Message Object 105 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR105L         (*((uword volatile far *) 0x201D24))

// Message Object 106 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR106H         (*((uword volatile far *) 0x201D46))

// Message Object 106 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR106L         (*((uword volatile far *) 0x201D44))

// Message Object 107 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR107H         (*((uword volatile far *) 0x201D66))

// Message Object 107 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR107L         (*((uword volatile far *) 0x201D64))

// Message Object 108 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR108H         (*((uword volatile far *) 0x201D86))

// Message Object 108 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR108L         (*((uword volatile far *) 0x201D84))

// Message Object 109 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR109H         (*((uword volatile far *) 0x201DA6))

// Message Object 109 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR109L         (*((uword volatile far *) 0x201DA4))

// Message Object 10 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR10H          (*((uword volatile far *) 0x201146))

// Message Object 10 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR10L          (*((uword volatile far *) 0x201144))

// Message Object 110 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR110H         (*((uword volatile far *) 0x201DC6))

// Message Object 110 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR110L         (*((uword volatile far *) 0x201DC4))

// Message Object 111 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR111H         (*((uword volatile far *) 0x201DE6))

// Message Object 111 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR111L         (*((uword volatile far *) 0x201DE4))

// Message Object 112 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR112H         (*((uword volatile far *) 0x201E06))

// Message Object 112 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR112L         (*((uword volatile far *) 0x201E04))

// Message Object 113 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR113H         (*((uword volatile far *) 0x201E26))

// Message Object 113 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR113L         (*((uword volatile far *) 0x201E24))

// Message Object 114 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR114H         (*((uword volatile far *) 0x201E46))

// Message Object 114 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR114L         (*((uword volatile far *) 0x201E44))

// Message Object 115 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR115H         (*((uword volatile far *) 0x201E66))

// Message Object 115 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR115L         (*((uword volatile far *) 0x201E64))

// Message Object 116 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR116H         (*((uword volatile far *) 0x201E86))

// Message Object 116 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR116L         (*((uword volatile far *) 0x201E84))

// Message Object 117 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR117H         (*((uword volatile far *) 0x201EA6))

// Message Object 117 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR117L         (*((uword volatile far *) 0x201EA4))

// Message Object 118 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR118H         (*((uword volatile far *) 0x201EC6))

// Message Object 118 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR118L         (*((uword volatile far *) 0x201EC4))

// Message Object 119 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR119H         (*((uword volatile far *) 0x201EE6))

// Message Object 119 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR119L         (*((uword volatile far *) 0x201EE4))

// Message Object 11 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR11H          (*((uword volatile far *) 0x201166))

// Message Object 11 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR11L          (*((uword volatile far *) 0x201164))

// Message Object 120 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR120H         (*((uword volatile far *) 0x201F06))

// Message Object 120 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR120L         (*((uword volatile far *) 0x201F04))

// Message Object 121 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR121H         (*((uword volatile far *) 0x201F26))

// Message Object 121 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR121L         (*((uword volatile far *) 0x201F24))

// Message Object 122 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR122H         (*((uword volatile far *) 0x201F46))

// Message Object 122 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR122L         (*((uword volatile far *) 0x201F44))

// Message Object 123 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR123H         (*((uword volatile far *) 0x201F66))

// Message Object 123 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR123L         (*((uword volatile far *) 0x201F64))

// Message Object 124 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR124H         (*((uword volatile far *) 0x201F86))

// Message Object 124 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR124L         (*((uword volatile far *) 0x201F84))

// Message Object 125 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR125H         (*((uword volatile far *) 0x201FA6))

// Message Object 125 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR125L         (*((uword volatile far *) 0x201FA4))

// Message Object 126 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR126H         (*((uword volatile far *) 0x201FC6))

// Message Object 126 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR126L         (*((uword volatile far *) 0x201FC4))

// Message Object 127 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR127H         (*((uword volatile far *) 0x201FE6))

// Message Object 127 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR127L         (*((uword volatile far *) 0x201FE4))

// Message Object 128 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR128H         (*((uword volatile far *) 0x202006))

// Message Object 128 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR128L         (*((uword volatile far *) 0x202004))

// Message Object 129 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR129H         (*((uword volatile far *) 0x202026))

// Message Object 129 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR129L         (*((uword volatile far *) 0x202024))

// Message Object 12 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR12H          (*((uword volatile far *) 0x201186))

// Message Object 12 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR12L          (*((uword volatile far *) 0x201184))

// Message Object 130 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR130H         (*((uword volatile far *) 0x202046))

// Message Object 130 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR130L         (*((uword volatile far *) 0x202044))

// Message Object 131 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR131H         (*((uword volatile far *) 0x202066))

// Message Object 131 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR131L         (*((uword volatile far *) 0x202064))

// Message Object 132 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR132H         (*((uword volatile far *) 0x202086))

// Message Object 132 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR132L         (*((uword volatile far *) 0x202084))

// Message Object 133 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR133H         (*((uword volatile far *) 0x2020A6))

// Message Object 133 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR133L         (*((uword volatile far *) 0x2020A4))

// Message Object 134 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR134H         (*((uword volatile far *) 0x2020C6))

// Message Object 134 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR134L         (*((uword volatile far *) 0x2020C4))

// Message Object 135 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR135H         (*((uword volatile far *) 0x2020E6))

// Message Object 135 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR135L         (*((uword volatile far *) 0x2020E4))

// Message Object 136 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR136H         (*((uword volatile far *) 0x202106))

// Message Object 136 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR136L         (*((uword volatile far *) 0x202104))

// Message Object 137 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR137H         (*((uword volatile far *) 0x202126))

// Message Object 137 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR137L         (*((uword volatile far *) 0x202124))

// Message Object 138 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR138H         (*((uword volatile far *) 0x202146))

// Message Object 138 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR138L         (*((uword volatile far *) 0x202144))

// Message Object 139 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR139H         (*((uword volatile far *) 0x202166))

// Message Object 139 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR139L         (*((uword volatile far *) 0x202164))

// Message Object 13 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR13H          (*((uword volatile far *) 0x2011A6))

// Message Object 13 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR13L          (*((uword volatile far *) 0x2011A4))

// Message Object 140 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR140H         (*((uword volatile far *) 0x202186))

// Message Object 140 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR140L         (*((uword volatile far *) 0x202184))

// Message Object 141 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR141H         (*((uword volatile far *) 0x2021A6))

// Message Object 141 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR141L         (*((uword volatile far *) 0x2021A4))

// Message Object 142 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR142H         (*((uword volatile far *) 0x2021C6))

// Message Object 142 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR142L         (*((uword volatile far *) 0x2021C4))

// Message Object 143 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR143H         (*((uword volatile far *) 0x2021E6))

// Message Object 143 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR143L         (*((uword volatile far *) 0x2021E4))

// Message Object 144 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR144H         (*((uword volatile far *) 0x202206))

// Message Object 144 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR144L         (*((uword volatile far *) 0x202204))

// Message Object 145 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR145H         (*((uword volatile far *) 0x202226))

// Message Object 145 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR145L         (*((uword volatile far *) 0x202224))

// Message Object 146 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR146H         (*((uword volatile far *) 0x202246))

// Message Object 146 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR146L         (*((uword volatile far *) 0x202244))

// Message Object 147 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR147H         (*((uword volatile far *) 0x202266))

// Message Object 147 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR147L         (*((uword volatile far *) 0x202264))

// Message Object 148 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR148H         (*((uword volatile far *) 0x202286))

// Message Object 148 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR148L         (*((uword volatile far *) 0x202284))

// Message Object 149 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR149H         (*((uword volatile far *) 0x2022A6))

// Message Object 149 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR149L         (*((uword volatile far *) 0x2022A4))

// Message Object 14 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR14H          (*((uword volatile far *) 0x2011C6))

// Message Object 14 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR14L          (*((uword volatile far *) 0x2011C4))

// Message Object 150 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR150H         (*((uword volatile far *) 0x2022C6))

// Message Object 150 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR150L         (*((uword volatile far *) 0x2022C4))

// Message Object 151 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR151H         (*((uword volatile far *) 0x2022E6))

// Message Object 151 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR151L         (*((uword volatile far *) 0x2022E4))

// Message Object 152 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR152H         (*((uword volatile far *) 0x202306))

// Message Object 152 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR152L         (*((uword volatile far *) 0x202304))

// Message Object 153 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR153H         (*((uword volatile far *) 0x202326))

// Message Object 153 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR153L         (*((uword volatile far *) 0x202324))

// Message Object 154 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR154H         (*((uword volatile far *) 0x202346))

// Message Object 154 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR154L         (*((uword volatile far *) 0x202344))

// Message Object 155 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR155H         (*((uword volatile far *) 0x202366))

// Message Object 155 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR155L         (*((uword volatile far *) 0x202364))

// Message Object 156 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR156H         (*((uword volatile far *) 0x202386))

// Message Object 156 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR156L         (*((uword volatile far *) 0x202384))

// Message Object 157 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR157H         (*((uword volatile far *) 0x2023A6))

// Message Object 157 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR157L         (*((uword volatile far *) 0x2023A4))

// Message Object 158 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR158H         (*((uword volatile far *) 0x2023C6))

// Message Object 158 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR158L         (*((uword volatile far *) 0x2023C4))

// Message Object 159 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR159H         (*((uword volatile far *) 0x2023E6))

// Message Object 159 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR159L         (*((uword volatile far *) 0x2023E4))

// Message Object 15 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR15H          (*((uword volatile far *) 0x2011E6))

// Message Object 15 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR15L          (*((uword volatile far *) 0x2011E4))

// Message Object 160 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR160H         (*((uword volatile far *) 0x202406))

// Message Object 160 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR160L         (*((uword volatile far *) 0x202404))

// Message Object 161 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR161H         (*((uword volatile far *) 0x202426))

// Message Object 161 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR161L         (*((uword volatile far *) 0x202424))

// Message Object 162 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR162H         (*((uword volatile far *) 0x202446))

// Message Object 162 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR162L         (*((uword volatile far *) 0x202444))

// Message Object 163 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR163H         (*((uword volatile far *) 0x202466))

// Message Object 163 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR163L         (*((uword volatile far *) 0x202464))

// Message Object 164 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR164H         (*((uword volatile far *) 0x202486))

// Message Object 164 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR164L         (*((uword volatile far *) 0x202484))

// Message Object 165 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR165H         (*((uword volatile far *) 0x2024A6))

// Message Object 165 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR165L         (*((uword volatile far *) 0x2024A4))

// Message Object 166 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR166H         (*((uword volatile far *) 0x2024C6))

// Message Object 166 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR166L         (*((uword volatile far *) 0x2024C4))

// Message Object 167 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR167H         (*((uword volatile far *) 0x2024E6))

// Message Object 167 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR167L         (*((uword volatile far *) 0x2024E4))

// Message Object 168 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR168H         (*((uword volatile far *) 0x202506))

// Message Object 168 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR168L         (*((uword volatile far *) 0x202504))

// Message Object 169 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR169H         (*((uword volatile far *) 0x202526))

// Message Object 169 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR169L         (*((uword volatile far *) 0x202524))

// Message Object 16 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR16H          (*((uword volatile far *) 0x201206))

// Message Object 16 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR16L          (*((uword volatile far *) 0x201204))

// Message Object 170 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR170H         (*((uword volatile far *) 0x202546))

// Message Object 170 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR170L         (*((uword volatile far *) 0x202544))

// Message Object 171 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR171H         (*((uword volatile far *) 0x202566))

// Message Object 171 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR171L         (*((uword volatile far *) 0x202564))

// Message Object 172 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR172H         (*((uword volatile far *) 0x202586))

// Message Object 172 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR172L         (*((uword volatile far *) 0x202584))

// Message Object 173 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR173H         (*((uword volatile far *) 0x2025A6))

// Message Object 173 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR173L         (*((uword volatile far *) 0x2025A4))

// Message Object 174 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR174H         (*((uword volatile far *) 0x2025C6))

// Message Object 174 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR174L         (*((uword volatile far *) 0x2025C4))

// Message Object 175 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR175H         (*((uword volatile far *) 0x2025E6))

// Message Object 175 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR175L         (*((uword volatile far *) 0x2025E4))

// Message Object 176 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR176H         (*((uword volatile far *) 0x202606))

// Message Object 176 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR176L         (*((uword volatile far *) 0x202604))

// Message Object 177 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR177H         (*((uword volatile far *) 0x202626))

// Message Object 177 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR177L         (*((uword volatile far *) 0x202624))

// Message Object 178 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR178H         (*((uword volatile far *) 0x202646))

// Message Object 178 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR178L         (*((uword volatile far *) 0x202644))

// Message Object 179 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR179H         (*((uword volatile far *) 0x202666))

// Message Object 179 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR179L         (*((uword volatile far *) 0x202664))

// Message Object 17 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR17H          (*((uword volatile far *) 0x201226))

// Message Object 17 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR17L          (*((uword volatile far *) 0x201224))

// Message Object 180 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR180H         (*((uword volatile far *) 0x202686))

// Message Object 180 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR180L         (*((uword volatile far *) 0x202684))

// Message Object 181 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR181H         (*((uword volatile far *) 0x2026A6))

// Message Object 181 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR181L         (*((uword volatile far *) 0x2026A4))

// Message Object 182 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR182H         (*((uword volatile far *) 0x2026C6))

// Message Object 182 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR182L         (*((uword volatile far *) 0x2026C4))

// Message Object 183 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR183H         (*((uword volatile far *) 0x2026E6))

// Message Object 183 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR183L         (*((uword volatile far *) 0x2026E4))

// Message Object 184 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR184H         (*((uword volatile far *) 0x202706))

// Message Object 184 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR184L         (*((uword volatile far *) 0x202704))

// Message Object 185 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR185H         (*((uword volatile far *) 0x202726))

// Message Object 185 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR185L         (*((uword volatile far *) 0x202724))

// Message Object 186 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR186H         (*((uword volatile far *) 0x202746))

// Message Object 186 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR186L         (*((uword volatile far *) 0x202744))

// Message Object 187 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR187H         (*((uword volatile far *) 0x202766))

// Message Object 187 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR187L         (*((uword volatile far *) 0x202764))

// Message Object 188 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR188H         (*((uword volatile far *) 0x202786))

// Message Object 188 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR188L         (*((uword volatile far *) 0x202784))

// Message Object 189 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR189H         (*((uword volatile far *) 0x2027A6))

// Message Object 189 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR189L         (*((uword volatile far *) 0x2027A4))

// Message Object 18 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR18H          (*((uword volatile far *) 0x201246))

// Message Object 18 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR18L          (*((uword volatile far *) 0x201244))

// Message Object 190 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR190H         (*((uword volatile far *) 0x2027C6))

// Message Object 190 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR190L         (*((uword volatile far *) 0x2027C4))

// Message Object 191 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR191H         (*((uword volatile far *) 0x2027E6))

// Message Object 191 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR191L         (*((uword volatile far *) 0x2027E4))

// Message Object 192 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR192H         (*((uword volatile far *) 0x202806))

// Message Object 192 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR192L         (*((uword volatile far *) 0x202804))

// Message Object 193 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR193H         (*((uword volatile far *) 0x202826))

// Message Object 193 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR193L         (*((uword volatile far *) 0x202824))

// Message Object 194 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR194H         (*((uword volatile far *) 0x202846))

// Message Object 194 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR194L         (*((uword volatile far *) 0x202844))

// Message Object 195 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR195H         (*((uword volatile far *) 0x202866))

// Message Object 195 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR195L         (*((uword volatile far *) 0x202864))

// Message Object 196 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR196H         (*((uword volatile far *) 0x202886))

// Message Object 196 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR196L         (*((uword volatile far *) 0x202884))

// Message Object 197 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR197H         (*((uword volatile far *) 0x2028A6))

// Message Object 197 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR197L         (*((uword volatile far *) 0x2028A4))

// Message Object 198 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR198H         (*((uword volatile far *) 0x2028C6))

// Message Object 198 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR198L         (*((uword volatile far *) 0x2028C4))

// Message Object 199 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR199H         (*((uword volatile far *) 0x2028E6))

// Message Object 199 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR199L         (*((uword volatile far *) 0x2028E4))

// Message Object 19 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR19H          (*((uword volatile far *) 0x201266))

// Message Object 19 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR19L          (*((uword volatile far *) 0x201264))

// Message Object 1 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR1H           (*((uword volatile far *) 0x201026))

// Message Object 1 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR1L           (*((uword volatile far *) 0x201024))

// Message Object 200 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR200H         (*((uword volatile far *) 0x202906))

// Message Object 200 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR200L         (*((uword volatile far *) 0x202904))

// Message Object 201 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR201H         (*((uword volatile far *) 0x202926))

// Message Object 201 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR201L         (*((uword volatile far *) 0x202924))

// Message Object 202 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR202H         (*((uword volatile far *) 0x202946))

// Message Object 202 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR202L         (*((uword volatile far *) 0x202944))

// Message Object 203 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR203H         (*((uword volatile far *) 0x202966))

// Message Object 203 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR203L         (*((uword volatile far *) 0x202964))

// Message Object 204 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR204H         (*((uword volatile far *) 0x202986))

// Message Object 204 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR204L         (*((uword volatile far *) 0x202984))

// Message Object 205 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR205H         (*((uword volatile far *) 0x2029A6))

// Message Object 205 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR205L         (*((uword volatile far *) 0x2029A4))

// Message Object 206 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR206H         (*((uword volatile far *) 0x2029C6))

// Message Object 206 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR206L         (*((uword volatile far *) 0x2029C4))

// Message Object 207 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR207H         (*((uword volatile far *) 0x2029E6))

// Message Object 207 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR207L         (*((uword volatile far *) 0x2029E4))

// Message Object 208 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR208H         (*((uword volatile far *) 0x202A06))

// Message Object 208 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR208L         (*((uword volatile far *) 0x202A04))

// Message Object 209 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR209H         (*((uword volatile far *) 0x202A26))

// Message Object 209 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR209L         (*((uword volatile far *) 0x202A24))

// Message Object 20 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR20H          (*((uword volatile far *) 0x201286))

// Message Object 20 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR20L          (*((uword volatile far *) 0x201284))

// Message Object 210 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR210H         (*((uword volatile far *) 0x202A46))

// Message Object 210 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR210L         (*((uword volatile far *) 0x202A44))

// Message Object 211 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR211H         (*((uword volatile far *) 0x202A66))

// Message Object 211 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR211L         (*((uword volatile far *) 0x202A64))

// Message Object 212 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR212H         (*((uword volatile far *) 0x202A86))

// Message Object 212 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR212L         (*((uword volatile far *) 0x202A84))

// Message Object 213 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR213H         (*((uword volatile far *) 0x202AA6))

// Message Object 213 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR213L         (*((uword volatile far *) 0x202AA4))

// Message Object 214 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR214H         (*((uword volatile far *) 0x202AC6))

// Message Object 214 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR214L         (*((uword volatile far *) 0x202AC4))

// Message Object 215 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR215H         (*((uword volatile far *) 0x202AE6))

// Message Object 215 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR215L         (*((uword volatile far *) 0x202AE4))

// Message Object 216 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR216H         (*((uword volatile far *) 0x202B06))

// Message Object 216 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR216L         (*((uword volatile far *) 0x202B04))

// Message Object 217 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR217H         (*((uword volatile far *) 0x202B26))

// Message Object 217 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR217L         (*((uword volatile far *) 0x202B24))

// Message Object 218 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR218H         (*((uword volatile far *) 0x202B46))

// Message Object 218 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR218L         (*((uword volatile far *) 0x202B44))

// Message Object 219 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR219H         (*((uword volatile far *) 0x202B66))

// Message Object 219 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR219L         (*((uword volatile far *) 0x202B64))

// Message Object 21 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR21H          (*((uword volatile far *) 0x2012A6))

// Message Object 21 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR21L          (*((uword volatile far *) 0x2012A4))

// Message Object 220 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR220H         (*((uword volatile far *) 0x202B86))

// Message Object 220 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR220L         (*((uword volatile far *) 0x202B84))

// Message Object 221 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR221H         (*((uword volatile far *) 0x202BA6))

// Message Object 221 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR221L         (*((uword volatile far *) 0x202BA4))

// Message Object 222 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR222H         (*((uword volatile far *) 0x202BC6))

// Message Object 222 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR222L         (*((uword volatile far *) 0x202BC4))

// Message Object 223 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR223H         (*((uword volatile far *) 0x202BE6))

// Message Object 223 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR223L         (*((uword volatile far *) 0x202BE4))

// Message Object 224 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR224H         (*((uword volatile far *) 0x202C06))

// Message Object 224 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR224L         (*((uword volatile far *) 0x202C04))

// Message Object 225 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR225H         (*((uword volatile far *) 0x202C26))

// Message Object 225 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR225L         (*((uword volatile far *) 0x202C24))

// Message Object 226 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR226H         (*((uword volatile far *) 0x202C46))

// Message Object 226 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR226L         (*((uword volatile far *) 0x202C44))

// Message Object 227 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR227H         (*((uword volatile far *) 0x202C66))

// Message Object 227 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR227L         (*((uword volatile far *) 0x202C64))

// Message Object 228 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR228H         (*((uword volatile far *) 0x202C86))

// Message Object 228 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR228L         (*((uword volatile far *) 0x202C84))

// Message Object 229 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR229H         (*((uword volatile far *) 0x202CA6))

// Message Object 229 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR229L         (*((uword volatile far *) 0x202CA4))

// Message Object 22 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR22H          (*((uword volatile far *) 0x2012C6))

// Message Object 22 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR22L          (*((uword volatile far *) 0x2012C4))

// Message Object 230 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR230H         (*((uword volatile far *) 0x202CC6))

// Message Object 230 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR230L         (*((uword volatile far *) 0x202CC4))

// Message Object 231 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR231H         (*((uword volatile far *) 0x202CE6))

// Message Object 231 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR231L         (*((uword volatile far *) 0x202CE4))

// Message Object 232 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR232H         (*((uword volatile far *) 0x202D06))

// Message Object 232 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR232L         (*((uword volatile far *) 0x202D04))

// Message Object 233 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR233H         (*((uword volatile far *) 0x202D26))

// Message Object 233 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR233L         (*((uword volatile far *) 0x202D24))

// Message Object 234 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR234H         (*((uword volatile far *) 0x202D46))

// Message Object 234 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR234L         (*((uword volatile far *) 0x202D44))

// Message Object 235 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR235H         (*((uword volatile far *) 0x202D66))

// Message Object 235 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR235L         (*((uword volatile far *) 0x202D64))

// Message Object 236 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR236H         (*((uword volatile far *) 0x202D86))

// Message Object 236 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR236L         (*((uword volatile far *) 0x202D84))

// Message Object 237 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR237H         (*((uword volatile far *) 0x202DA6))

// Message Object 237 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR237L         (*((uword volatile far *) 0x202DA4))

// Message Object 238 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR238H         (*((uword volatile far *) 0x202DC6))

// Message Object 238 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR238L         (*((uword volatile far *) 0x202DC4))

// Message Object 239 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR239H         (*((uword volatile far *) 0x202DE6))

// Message Object 239 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR239L         (*((uword volatile far *) 0x202DE4))

// Message Object 23 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR23H          (*((uword volatile far *) 0x2012E6))

// Message Object 23 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR23L          (*((uword volatile far *) 0x2012E4))

// Message Object 240 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR240H         (*((uword volatile far *) 0x202E06))

// Message Object 240 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR240L         (*((uword volatile far *) 0x202E04))

// Message Object 241 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR241H         (*((uword volatile far *) 0x202E26))

// Message Object 241 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR241L         (*((uword volatile far *) 0x202E24))

// Message Object 242 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR242H         (*((uword volatile far *) 0x202E46))

// Message Object 242 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR242L         (*((uword volatile far *) 0x202E44))

// Message Object 243 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR243H         (*((uword volatile far *) 0x202E66))

// Message Object 243 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR243L         (*((uword volatile far *) 0x202E64))

// Message Object 244 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR244H         (*((uword volatile far *) 0x202E86))

// Message Object 244 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR244L         (*((uword volatile far *) 0x202E84))

// Message Object 245 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR245H         (*((uword volatile far *) 0x202EA6))

// Message Object 245 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR245L         (*((uword volatile far *) 0x202EA4))

// Message Object 246 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR246H         (*((uword volatile far *) 0x202EC6))

// Message Object 246 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR246L         (*((uword volatile far *) 0x202EC4))

// Message Object 247 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR247H         (*((uword volatile far *) 0x202EE6))

// Message Object 247 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR247L         (*((uword volatile far *) 0x202EE4))

// Message Object 248 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR248H         (*((uword volatile far *) 0x202F06))

// Message Object 248 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR248L         (*((uword volatile far *) 0x202F04))

// Message Object 249 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR249H         (*((uword volatile far *) 0x202F26))

// Message Object 249 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR249L         (*((uword volatile far *) 0x202F24))

// Message Object 24 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR24H          (*((uword volatile far *) 0x201306))

// Message Object 24 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR24L          (*((uword volatile far *) 0x201304))

// Message Object 250 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR250H         (*((uword volatile far *) 0x202F46))

// Message Object 250 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR250L         (*((uword volatile far *) 0x202F44))

// Message Object 251 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR251H         (*((uword volatile far *) 0x202F66))

// Message Object 251 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR251L         (*((uword volatile far *) 0x202F64))

// Message Object 252 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR252H         (*((uword volatile far *) 0x202F86))

// Message Object 252 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR252L         (*((uword volatile far *) 0x202F84))

// Message Object 253 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR253H         (*((uword volatile far *) 0x202FA6))

// Message Object 253 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR253L         (*((uword volatile far *) 0x202FA4))

// Message Object 254 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR254H         (*((uword volatile far *) 0x202FC6))

// Message Object 254 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR254L         (*((uword volatile far *) 0x202FC4))

// Message Object 255 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR255H         (*((uword volatile far *) 0x202FE6))

// Message Object 255 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR255L         (*((uword volatile far *) 0x202FE4))

// Message Object 25 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR25H          (*((uword volatile far *) 0x201326))

// Message Object 25 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR25L          (*((uword volatile far *) 0x201324))

// Message Object 26 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR26H          (*((uword volatile far *) 0x201346))

// Message Object 26 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR26L          (*((uword volatile far *) 0x201344))

// Message Object 27 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR27H          (*((uword volatile far *) 0x201366))

// Message Object 27 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR27L          (*((uword volatile far *) 0x201364))

// Message Object 28 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR28H          (*((uword volatile far *) 0x201386))

// Message Object 28 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR28L          (*((uword volatile far *) 0x201384))

// Message Object 29 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR29H          (*((uword volatile far *) 0x2013A6))

// Message Object 29 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR29L          (*((uword volatile far *) 0x2013A4))

// Message Object 2 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR2H           (*((uword volatile far *) 0x201046))

// Message Object 2 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR2L           (*((uword volatile far *) 0x201044))

// Message Object 30 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR30H          (*((uword volatile far *) 0x2013C6))

// Message Object 30 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR30L          (*((uword volatile far *) 0x2013C4))

// Message Object 31 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR31H          (*((uword volatile far *) 0x2013E6))

// Message Object 31 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR31L          (*((uword volatile far *) 0x2013E4))

// Message Object 32 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR32H          (*((uword volatile far *) 0x201406))

// Message Object 32 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR32L          (*((uword volatile far *) 0x201404))

// Message Object 33 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR33H          (*((uword volatile far *) 0x201426))

// Message Object 33 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR33L          (*((uword volatile far *) 0x201424))

// Message Object 34 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR34H          (*((uword volatile far *) 0x201446))

// Message Object 34 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR34L          (*((uword volatile far *) 0x201444))

// Message Object 35 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR35H          (*((uword volatile far *) 0x201466))

// Message Object 35 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR35L          (*((uword volatile far *) 0x201464))

// Message Object 36 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR36H          (*((uword volatile far *) 0x201486))

// Message Object 36 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR36L          (*((uword volatile far *) 0x201484))

// Message Object 37 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR37H          (*((uword volatile far *) 0x2014A6))

// Message Object 37 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR37L          (*((uword volatile far *) 0x2014A4))

// Message Object 38 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR38H          (*((uword volatile far *) 0x2014C6))

// Message Object 38 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR38L          (*((uword volatile far *) 0x2014C4))

// Message Object 39 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR39H          (*((uword volatile far *) 0x2014E6))

// Message Object 39 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR39L          (*((uword volatile far *) 0x2014E4))

// Message Object 3 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR3H           (*((uword volatile far *) 0x201066))

// Message Object 3 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR3L           (*((uword volatile far *) 0x201064))

// Message Object 40 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR40H          (*((uword volatile far *) 0x201506))

// Message Object 40 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR40L          (*((uword volatile far *) 0x201504))

// Message Object 41 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR41H          (*((uword volatile far *) 0x201526))

// Message Object 41 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR41L          (*((uword volatile far *) 0x201524))

// Message Object 42 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR42H          (*((uword volatile far *) 0x201546))

// Message Object 42 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR42L          (*((uword volatile far *) 0x201544))

// Message Object 43 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR43H          (*((uword volatile far *) 0x201566))

// Message Object 43 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR43L          (*((uword volatile far *) 0x201564))

// Message Object 44 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR44H          (*((uword volatile far *) 0x201586))

// Message Object 44 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR44L          (*((uword volatile far *) 0x201584))

// Message Object 45 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR45H          (*((uword volatile far *) 0x2015A6))

// Message Object 45 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR45L          (*((uword volatile far *) 0x2015A4))

// Message Object 46 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR46H          (*((uword volatile far *) 0x2015C6))

// Message Object 46 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR46L          (*((uword volatile far *) 0x2015C4))

// Message Object 47 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR47H          (*((uword volatile far *) 0x2015E6))

// Message Object 47 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR47L          (*((uword volatile far *) 0x2015E4))

// Message Object 48 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR48H          (*((uword volatile far *) 0x201606))

// Message Object 48 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR48L          (*((uword volatile far *) 0x201604))

// Message Object 49 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR49H          (*((uword volatile far *) 0x201626))

// Message Object 49 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR49L          (*((uword volatile far *) 0x201624))

// Message Object 4 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR4H           (*((uword volatile far *) 0x201086))

// Message Object 4 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR4L           (*((uword volatile far *) 0x201084))

// Message Object 50 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR50H          (*((uword volatile far *) 0x201646))

// Message Object 50 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR50L          (*((uword volatile far *) 0x201644))

// Message Object 51 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR51H          (*((uword volatile far *) 0x201666))

// Message Object 51 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR51L          (*((uword volatile far *) 0x201664))

// Message Object 52 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR52H          (*((uword volatile far *) 0x201686))

// Message Object 52 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR52L          (*((uword volatile far *) 0x201684))

// Message Object 53 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR53H          (*((uword volatile far *) 0x2016A6))

// Message Object 53 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR53L          (*((uword volatile far *) 0x2016A4))

// Message Object 54 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR54H          (*((uword volatile far *) 0x2016C6))

// Message Object 54 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR54L          (*((uword volatile far *) 0x2016C4))

// Message Object 55 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR55H          (*((uword volatile far *) 0x2016E6))

// Message Object 55 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR55L          (*((uword volatile far *) 0x2016E4))

// Message Object 56 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR56H          (*((uword volatile far *) 0x201706))

// Message Object 56 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR56L          (*((uword volatile far *) 0x201704))

// Message Object 57 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR57H          (*((uword volatile far *) 0x201726))

// Message Object 57 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR57L          (*((uword volatile far *) 0x201724))

// Message Object 58 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR58H          (*((uword volatile far *) 0x201746))

// Message Object 58 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR58L          (*((uword volatile far *) 0x201744))

// Message Object 59 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR59H          (*((uword volatile far *) 0x201766))

// Message Object 59 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR59L          (*((uword volatile far *) 0x201764))

// Message Object 5 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR5H           (*((uword volatile far *) 0x2010A6))

// Message Object 5 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR5L           (*((uword volatile far *) 0x2010A4))

// Message Object 60 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR60H          (*((uword volatile far *) 0x201786))

// Message Object 60 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR60L          (*((uword volatile far *) 0x201784))

// Message Object 61 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR61H          (*((uword volatile far *) 0x2017A6))

// Message Object 61 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR61L          (*((uword volatile far *) 0x2017A4))

// Message Object 62 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR62H          (*((uword volatile far *) 0x2017C6))

// Message Object 62 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR62L          (*((uword volatile far *) 0x2017C4))

// Message Object 63 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR63H          (*((uword volatile far *) 0x2017E6))

// Message Object 63 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR63L          (*((uword volatile far *) 0x2017E4))

// Message Object 64 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR64H          (*((uword volatile far *) 0x201806))

// Message Object 64 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR64L          (*((uword volatile far *) 0x201804))

// Message Object 65 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR65H          (*((uword volatile far *) 0x201826))

// Message Object 65 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR65L          (*((uword volatile far *) 0x201824))

// Message Object 66 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR66H          (*((uword volatile far *) 0x201846))

// Message Object 66 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR66L          (*((uword volatile far *) 0x201844))

// Message Object 67 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR67H          (*((uword volatile far *) 0x201866))

// Message Object 67 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR67L          (*((uword volatile far *) 0x201864))

// Message Object 68 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR68H          (*((uword volatile far *) 0x201886))

// Message Object 68 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR68L          (*((uword volatile far *) 0x201884))

// Message Object 69 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR69H          (*((uword volatile far *) 0x2018A6))

// Message Object 69 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR69L          (*((uword volatile far *) 0x2018A4))

// Message Object 6 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR6H           (*((uword volatile far *) 0x2010C6))

// Message Object 6 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR6L           (*((uword volatile far *) 0x2010C4))

// Message Object 70 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR70H          (*((uword volatile far *) 0x2018C6))

// Message Object 70 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR70L          (*((uword volatile far *) 0x2018C4))

// Message Object 71 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR71H          (*((uword volatile far *) 0x2018E6))

// Message Object 71 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR71L          (*((uword volatile far *) 0x2018E4))

// Message Object 72 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR72H          (*((uword volatile far *) 0x201906))

// Message Object 72 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR72L          (*((uword volatile far *) 0x201904))

// Message Object 73 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR73H          (*((uword volatile far *) 0x201926))

// Message Object 73 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR73L          (*((uword volatile far *) 0x201924))

// Message Object 74 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR74H          (*((uword volatile far *) 0x201946))

// Message Object 74 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR74L          (*((uword volatile far *) 0x201944))

// Message Object 75 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR75H          (*((uword volatile far *) 0x201966))

// Message Object 75 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR75L          (*((uword volatile far *) 0x201964))

// Message Object 76 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR76H          (*((uword volatile far *) 0x201986))

// Message Object 76 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR76L          (*((uword volatile far *) 0x201984))

// Message Object 77 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR77H          (*((uword volatile far *) 0x2019A6))

// Message Object 77 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR77L          (*((uword volatile far *) 0x2019A4))

// Message Object 78 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR78H          (*((uword volatile far *) 0x2019C6))

// Message Object 78 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR78L          (*((uword volatile far *) 0x2019C4))

// Message Object 79 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR79H          (*((uword volatile far *) 0x2019E6))

// Message Object 79 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR79L          (*((uword volatile far *) 0x2019E4))

// Message Object 7 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR7H           (*((uword volatile far *) 0x2010E6))

// Message Object 7 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR7L           (*((uword volatile far *) 0x2010E4))

// Message Object 80 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR80H          (*((uword volatile far *) 0x201A06))

// Message Object 80 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR80L          (*((uword volatile far *) 0x201A04))

// Message Object 81 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR81H          (*((uword volatile far *) 0x201A26))

// Message Object 81 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR81L          (*((uword volatile far *) 0x201A24))

// Message Object 82 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR82H          (*((uword volatile far *) 0x201A46))

// Message Object 82 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR82L          (*((uword volatile far *) 0x201A44))

// Message Object 83 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR83H          (*((uword volatile far *) 0x201A66))

// Message Object 83 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR83L          (*((uword volatile far *) 0x201A64))

// Message Object 84 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR84H          (*((uword volatile far *) 0x201A86))

// Message Object 84 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR84L          (*((uword volatile far *) 0x201A84))

// Message Object 85 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR85H          (*((uword volatile far *) 0x201AA6))

// Message Object 85 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR85L          (*((uword volatile far *) 0x201AA4))

// Message Object 86 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR86H          (*((uword volatile far *) 0x201AC6))

// Message Object 86 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR86L          (*((uword volatile far *) 0x201AC4))

// Message Object 87 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR87H          (*((uword volatile far *) 0x201AE6))

// Message Object 87 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR87L          (*((uword volatile far *) 0x201AE4))

// Message Object 88 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR88H          (*((uword volatile far *) 0x201B06))

// Message Object 88 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR88L          (*((uword volatile far *) 0x201B04))

// Message Object 89 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR89H          (*((uword volatile far *) 0x201B26))

// Message Object 89 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR89L          (*((uword volatile far *) 0x201B24))

// Message Object 8 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR8H           (*((uword volatile far *) 0x201106))

// Message Object 8 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR8L           (*((uword volatile far *) 0x201104))

// Message Object 90 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR90H          (*((uword volatile far *) 0x201B46))

// Message Object 90 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR90L          (*((uword volatile far *) 0x201B44))

// Message Object 91 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR91H          (*((uword volatile far *) 0x201B66))

// Message Object 91 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR91L          (*((uword volatile far *) 0x201B64))

// Message Object 92 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR92H          (*((uword volatile far *) 0x201B86))

// Message Object 92 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR92L          (*((uword volatile far *) 0x201B84))

// Message Object 93 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR93H          (*((uword volatile far *) 0x201BA6))

// Message Object 93 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR93L          (*((uword volatile far *) 0x201BA4))

// Message Object 94 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR94H          (*((uword volatile far *) 0x201BC6))

// Message Object 94 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR94L          (*((uword volatile far *) 0x201BC4))

// Message Object 95 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR95H          (*((uword volatile far *) 0x201BE6))

// Message Object 95 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR95L          (*((uword volatile far *) 0x201BE4))

// Message Object 96 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR96H          (*((uword volatile far *) 0x201C06))

// Message Object 96 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR96L          (*((uword volatile far *) 0x201C04))

// Message Object 97 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR97H          (*((uword volatile far *) 0x201C26))

// Message Object 97 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR97L          (*((uword volatile far *) 0x201C24))

// Message Object 98 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR98H          (*((uword volatile far *) 0x201C46))

// Message Object 98 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR98L          (*((uword volatile far *) 0x201C44))

// Message Object 99 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR99H          (*((uword volatile far *) 0x201C66))

// Message Object 99 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR99L          (*((uword volatile far *) 0x201C64))

// Message Object 9 FIFO/Gateway Pointer Register High
#define CAN_MOFGPR9H           (*((uword volatile far *) 0x201126))

// Message Object 9 FIFO/Gateway Pointer Register Low
#define CAN_MOFGPR9L           (*((uword volatile far *) 0x201124))

// Message Object 0 Interrupt Pointer Register High
#define CAN_MOIPR0H            (*((uword volatile far *) 0x20100A))

// Message Object 0 Interrupt Pointer Register Low
#define CAN_MOIPR0L            (*((uword volatile far *) 0x201008))

// Message Object 100 Interrupt Pointer Register High
#define CAN_MOIPR100H          (*((uword volatile far *) 0x201C8A))

// Message Object 100 Interrupt Pointer Register Low
#define CAN_MOIPR100L          (*((uword volatile far *) 0x201C88))

// Message Object 101 Interrupt Pointer Register High
#define CAN_MOIPR101H          (*((uword volatile far *) 0x201CAA))

// Message Object 101 Interrupt Pointer Register Low
#define CAN_MOIPR101L          (*((uword volatile far *) 0x201CA8))

// Message Object 102 Interrupt Pointer Register High
#define CAN_MOIPR102H          (*((uword volatile far *) 0x201CCA))

// Message Object 102 Interrupt Pointer Register Low
#define CAN_MOIPR102L          (*((uword volatile far *) 0x201CC8))

// Message Object 103 Interrupt Pointer Register High
#define CAN_MOIPR103H          (*((uword volatile far *) 0x201CEA))

// Message Object 103 Interrupt Pointer Register Low
#define CAN_MOIPR103L          (*((uword volatile far *) 0x201CE8))

// Message Object 104 Interrupt Pointer Register High
#define CAN_MOIPR104H          (*((uword volatile far *) 0x201D0A))

// Message Object 104 Interrupt Pointer Register Low
#define CAN_MOIPR104L          (*((uword volatile far *) 0x201D08))

// Message Object 105 Interrupt Pointer Register High
#define CAN_MOIPR105H          (*((uword volatile far *) 0x201D2A))

// Message Object 105 Interrupt Pointer Register Low
#define CAN_MOIPR105L          (*((uword volatile far *) 0x201D28))

// Message Object 106 Interrupt Pointer Register High
#define CAN_MOIPR106H          (*((uword volatile far *) 0x201D4A))

// Message Object 106 Interrupt Pointer Register Low
#define CAN_MOIPR106L          (*((uword volatile far *) 0x201D48))

// Message Object 107 Interrupt Pointer Register High
#define CAN_MOIPR107H          (*((uword volatile far *) 0x201D6A))

// Message Object 107 Interrupt Pointer Register Low
#define CAN_MOIPR107L          (*((uword volatile far *) 0x201D68))

// Message Object 108 Interrupt Pointer Register High
#define CAN_MOIPR108H          (*((uword volatile far *) 0x201D8A))

// Message Object 108 Interrupt Pointer Register Low
#define CAN_MOIPR108L          (*((uword volatile far *) 0x201D88))

// Message Object 109 Interrupt Pointer Register High
#define CAN_MOIPR109H          (*((uword volatile far *) 0x201DAA))

// Message Object 109 Interrupt Pointer Register Low
#define CAN_MOIPR109L          (*((uword volatile far *) 0x201DA8))

// Message Object 10 Interrupt Pointer Register High
#define CAN_MOIPR10H           (*((uword volatile far *) 0x20114A))

// Message Object 10 Interrupt Pointer Register Low
#define CAN_MOIPR10L           (*((uword volatile far *) 0x201148))

// Message Object 110 Interrupt Pointer Register High
#define CAN_MOIPR110H          (*((uword volatile far *) 0x201DCA))

// Message Object 110 Interrupt Pointer Register Low
#define CAN_MOIPR110L          (*((uword volatile far *) 0x201DC8))

// Message Object 111 Interrupt Pointer Register High
#define CAN_MOIPR111H          (*((uword volatile far *) 0x201DEA))

// Message Object 111 Interrupt Pointer Register Low
#define CAN_MOIPR111L          (*((uword volatile far *) 0x201DE8))

// Message Object 112 Interrupt Pointer Register High
#define CAN_MOIPR112H          (*((uword volatile far *) 0x201E0A))

// Message Object 112 Interrupt Pointer Register Low
#define CAN_MOIPR112L          (*((uword volatile far *) 0x201E08))

// Message Object 113 Interrupt Pointer Register High
#define CAN_MOIPR113H          (*((uword volatile far *) 0x201E2A))

// Message Object 113 Interrupt Pointer Register Low
#define CAN_MOIPR113L          (*((uword volatile far *) 0x201E28))

// Message Object 114 Interrupt Pointer Register High
#define CAN_MOIPR114H          (*((uword volatile far *) 0x201E4A))

// Message Object 114 Interrupt Pointer Register Low
#define CAN_MOIPR114L          (*((uword volatile far *) 0x201E48))

// Message Object 115 Interrupt Pointer Register High
#define CAN_MOIPR115H          (*((uword volatile far *) 0x201E6A))

// Message Object 115 Interrupt Pointer Register Low
#define CAN_MOIPR115L          (*((uword volatile far *) 0x201E68))

// Message Object 116 Interrupt Pointer Register High
#define CAN_MOIPR116H          (*((uword volatile far *) 0x201E8A))

// Message Object 116 Interrupt Pointer Register Low
#define CAN_MOIPR116L          (*((uword volatile far *) 0x201E88))

// Message Object 117 Interrupt Pointer Register High
#define CAN_MOIPR117H          (*((uword volatile far *) 0x201EAA))

// Message Object 117 Interrupt Pointer Register Low
#define CAN_MOIPR117L          (*((uword volatile far *) 0x201EA8))

// Message Object 118 Interrupt Pointer Register High
#define CAN_MOIPR118H          (*((uword volatile far *) 0x201ECA))

// Message Object 118 Interrupt Pointer Register Low
#define CAN_MOIPR118L          (*((uword volatile far *) 0x201EC8))

// Message Object 119 Interrupt Pointer Register High
#define CAN_MOIPR119H          (*((uword volatile far *) 0x201EEA))

// Message Object 119 Interrupt Pointer Register Low
#define CAN_MOIPR119L          (*((uword volatile far *) 0x201EE8))

// Message Object 11 Interrupt Pointer Register High
#define CAN_MOIPR11H           (*((uword volatile far *) 0x20116A))

// Message Object 11 Interrupt Pointer Register Low
#define CAN_MOIPR11L           (*((uword volatile far *) 0x201168))

// Message Object 120 Interrupt Pointer Register High
#define CAN_MOIPR120H          (*((uword volatile far *) 0x201F0A))

// Message Object 120 Interrupt Pointer Register Low
#define CAN_MOIPR120L          (*((uword volatile far *) 0x201F08))

// Message Object 121 Interrupt Pointer Register High
#define CAN_MOIPR121H          (*((uword volatile far *) 0x201F2A))

// Message Object 121 Interrupt Pointer Register Low
#define CAN_MOIPR121L          (*((uword volatile far *) 0x201F28))

// Message Object 122 Interrupt Pointer Register High
#define CAN_MOIPR122H          (*((uword volatile far *) 0x201F4A))

// Message Object 122 Interrupt Pointer Register Low
#define CAN_MOIPR122L          (*((uword volatile far *) 0x201F48))

// Message Object 123 Interrupt Pointer Register High
#define CAN_MOIPR123H          (*((uword volatile far *) 0x201F6A))

// Message Object 123 Interrupt Pointer Register Low
#define CAN_MOIPR123L          (*((uword volatile far *) 0x201F68))

// Message Object 124 Interrupt Pointer Register High
#define CAN_MOIPR124H          (*((uword volatile far *) 0x201F8A))

// Message Object 124 Interrupt Pointer Register Low
#define CAN_MOIPR124L          (*((uword volatile far *) 0x201F88))

// Message Object 125 Interrupt Pointer Register High
#define CAN_MOIPR125H          (*((uword volatile far *) 0x201FAA))

// Message Object 125 Interrupt Pointer Register Low
#define CAN_MOIPR125L          (*((uword volatile far *) 0x201FA8))

// Message Object 126 Interrupt Pointer Register High
#define CAN_MOIPR126H          (*((uword volatile far *) 0x201FCA))

// Message Object 126 Interrupt Pointer Register Low
#define CAN_MOIPR126L          (*((uword volatile far *) 0x201FC8))

// Message Object 127 Interrupt Pointer Register High
#define CAN_MOIPR127H          (*((uword volatile far *) 0x201FEA))

// Message Object 127 Interrupt Pointer Register Low
#define CAN_MOIPR127L          (*((uword volatile far *) 0x201FE8))

// Message Object 128 Interrupt Pointer Register High
#define CAN_MOIPR128H          (*((uword volatile far *) 0x20200A))

// Message Object 128 Interrupt Pointer Register Low
#define CAN_MOIPR128L          (*((uword volatile far *) 0x202008))

// Message Object 129 Interrupt Pointer Register High
#define CAN_MOIPR129H          (*((uword volatile far *) 0x20202A))

// Message Object 129 Interrupt Pointer Register Low
#define CAN_MOIPR129L          (*((uword volatile far *) 0x202028))

// Message Object 12 Interrupt Pointer Register High
#define CAN_MOIPR12H           (*((uword volatile far *) 0x20118A))

// Message Object 12 Interrupt Pointer Register Low
#define CAN_MOIPR12L           (*((uword volatile far *) 0x201188))

// Message Object 130 Interrupt Pointer Register High
#define CAN_MOIPR130H          (*((uword volatile far *) 0x20204A))

// Message Object 130 Interrupt Pointer Register Low
#define CAN_MOIPR130L          (*((uword volatile far *) 0x202048))

// Message Object 131 Interrupt Pointer Register High
#define CAN_MOIPR131H          (*((uword volatile far *) 0x20206A))

// Message Object 131 Interrupt Pointer Register Low
#define CAN_MOIPR131L          (*((uword volatile far *) 0x202068))

// Message Object 132 Interrupt Pointer Register High
#define CAN_MOIPR132H          (*((uword volatile far *) 0x20208A))

// Message Object 132 Interrupt Pointer Register Low
#define CAN_MOIPR132L          (*((uword volatile far *) 0x202088))

// Message Object 133 Interrupt Pointer Register High
#define CAN_MOIPR133H          (*((uword volatile far *) 0x2020AA))

// Message Object 133 Interrupt Pointer Register Low
#define CAN_MOIPR133L          (*((uword volatile far *) 0x2020A8))

// Message Object 134 Interrupt Pointer Register High
#define CAN_MOIPR134H          (*((uword volatile far *) 0x2020CA))

// Message Object 134 Interrupt Pointer Register Low
#define CAN_MOIPR134L          (*((uword volatile far *) 0x2020C8))

// Message Object 135 Interrupt Pointer Register High
#define CAN_MOIPR135H          (*((uword volatile far *) 0x2020EA))

// Message Object 135 Interrupt Pointer Register Low
#define CAN_MOIPR135L          (*((uword volatile far *) 0x2020E8))

// Message Object 136 Interrupt Pointer Register High
#define CAN_MOIPR136H          (*((uword volatile far *) 0x20210A))

// Message Object 136 Interrupt Pointer Register Low
#define CAN_MOIPR136L          (*((uword volatile far *) 0x202108))

// Message Object 137 Interrupt Pointer Register High
#define CAN_MOIPR137H          (*((uword volatile far *) 0x20212A))

// Message Object 137 Interrupt Pointer Register Low
#define CAN_MOIPR137L          (*((uword volatile far *) 0x202128))

// Message Object 138 Interrupt Pointer Register High
#define CAN_MOIPR138H          (*((uword volatile far *) 0x20214A))

// Message Object 138 Interrupt Pointer Register Low
#define CAN_MOIPR138L          (*((uword volatile far *) 0x202148))

// Message Object 139 Interrupt Pointer Register High
#define CAN_MOIPR139H          (*((uword volatile far *) 0x20216A))

// Message Object 139 Interrupt Pointer Register Low
#define CAN_MOIPR139L          (*((uword volatile far *) 0x202168))

// Message Object 13 Interrupt Pointer Register High
#define CAN_MOIPR13H           (*((uword volatile far *) 0x2011AA))

// Message Object 13 Interrupt Pointer Register Low
#define CAN_MOIPR13L           (*((uword volatile far *) 0x2011A8))

// Message Object 140 Interrupt Pointer Register High
#define CAN_MOIPR140H          (*((uword volatile far *) 0x20218A))

// Message Object 140 Interrupt Pointer Register Low
#define CAN_MOIPR140L          (*((uword volatile far *) 0x202188))

// Message Object 141 Interrupt Pointer Register High
#define CAN_MOIPR141H          (*((uword volatile far *) 0x2021AA))

// Message Object 141 Interrupt Pointer Register Low
#define CAN_MOIPR141L          (*((uword volatile far *) 0x2021A8))

// Message Object 142 Interrupt Pointer Register High
#define CAN_MOIPR142H          (*((uword volatile far *) 0x2021CA))

// Message Object 142 Interrupt Pointer Register Low
#define CAN_MOIPR142L          (*((uword volatile far *) 0x2021C8))

// Message Object 143 Interrupt Pointer Register High
#define CAN_MOIPR143H          (*((uword volatile far *) 0x2021EA))

// Message Object 143 Interrupt Pointer Register Low
#define CAN_MOIPR143L          (*((uword volatile far *) 0x2021E8))

// Message Object 144 Interrupt Pointer Register High
#define CAN_MOIPR144H          (*((uword volatile far *) 0x20220A))

// Message Object 144 Interrupt Pointer Register Low
#define CAN_MOIPR144L          (*((uword volatile far *) 0x202208))

// Message Object 145 Interrupt Pointer Register High
#define CAN_MOIPR145H          (*((uword volatile far *) 0x20222A))

// Message Object 145 Interrupt Pointer Register Low
#define CAN_MOIPR145L          (*((uword volatile far *) 0x202228))

// Message Object 146 Interrupt Pointer Register High
#define CAN_MOIPR146H          (*((uword volatile far *) 0x20224A))

// Message Object 146 Interrupt Pointer Register Low
#define CAN_MOIPR146L          (*((uword volatile far *) 0x202248))

// Message Object 147 Interrupt Pointer Register High
#define CAN_MOIPR147H          (*((uword volatile far *) 0x20226A))

// Message Object 147 Interrupt Pointer Register Low
#define CAN_MOIPR147L          (*((uword volatile far *) 0x202268))

// Message Object 148 Interrupt Pointer Register High
#define CAN_MOIPR148H          (*((uword volatile far *) 0x20228A))

// Message Object 148 Interrupt Pointer Register Low
#define CAN_MOIPR148L          (*((uword volatile far *) 0x202288))

// Message Object 149 Interrupt Pointer Register High
#define CAN_MOIPR149H          (*((uword volatile far *) 0x2022AA))

// Message Object 149 Interrupt Pointer Register Low
#define CAN_MOIPR149L          (*((uword volatile far *) 0x2022A8))

// Message Object 14 Interrupt Pointer Register High
#define CAN_MOIPR14H           (*((uword volatile far *) 0x2011CA))

// Message Object 14 Interrupt Pointer Register Low
#define CAN_MOIPR14L           (*((uword volatile far *) 0x2011C8))

// Message Object 150 Interrupt Pointer Register High
#define CAN_MOIPR150H          (*((uword volatile far *) 0x2022CA))

// Message Object 150 Interrupt Pointer Register Low
#define CAN_MOIPR150L          (*((uword volatile far *) 0x2022C8))

// Message Object 151 Interrupt Pointer Register High
#define CAN_MOIPR151H          (*((uword volatile far *) 0x2022EA))

// Message Object 151 Interrupt Pointer Register Low
#define CAN_MOIPR151L          (*((uword volatile far *) 0x2022E8))

// Message Object 152 Interrupt Pointer Register High
#define CAN_MOIPR152H          (*((uword volatile far *) 0x20230A))

// Message Object 152 Interrupt Pointer Register Low
#define CAN_MOIPR152L          (*((uword volatile far *) 0x202308))

// Message Object 153 Interrupt Pointer Register High
#define CAN_MOIPR153H          (*((uword volatile far *) 0x20232A))

// Message Object 153 Interrupt Pointer Register Low
#define CAN_MOIPR153L          (*((uword volatile far *) 0x202328))

// Message Object 154 Interrupt Pointer Register High
#define CAN_MOIPR154H          (*((uword volatile far *) 0x20234A))

// Message Object 154 Interrupt Pointer Register Low
#define CAN_MOIPR154L          (*((uword volatile far *) 0x202348))

// Message Object 155 Interrupt Pointer Register High
#define CAN_MOIPR155H          (*((uword volatile far *) 0x20236A))

// Message Object 155 Interrupt Pointer Register Low
#define CAN_MOIPR155L          (*((uword volatile far *) 0x202368))

// Message Object 156 Interrupt Pointer Register High
#define CAN_MOIPR156H          (*((uword volatile far *) 0x20238A))

// Message Object 156 Interrupt Pointer Register Low
#define CAN_MOIPR156L          (*((uword volatile far *) 0x202388))

// Message Object 157 Interrupt Pointer Register High
#define CAN_MOIPR157H          (*((uword volatile far *) 0x2023AA))

// Message Object 157 Interrupt Pointer Register Low
#define CAN_MOIPR157L          (*((uword volatile far *) 0x2023A8))

// Message Object 158 Interrupt Pointer Register High
#define CAN_MOIPR158H          (*((uword volatile far *) 0x2023CA))

// Message Object 158 Interrupt Pointer Register Low
#define CAN_MOIPR158L          (*((uword volatile far *) 0x2023C8))

// Message Object 159 Interrupt Pointer Register High
#define CAN_MOIPR159H          (*((uword volatile far *) 0x2023EA))

// Message Object 159 Interrupt Pointer Register Low
#define CAN_MOIPR159L          (*((uword volatile far *) 0x2023E8))

// Message Object 15 Interrupt Pointer Register High
#define CAN_MOIPR15H           (*((uword volatile far *) 0x2011EA))

// Message Object 15 Interrupt Pointer Register Low
#define CAN_MOIPR15L           (*((uword volatile far *) 0x2011E8))

// Message Object 160 Interrupt Pointer Register High
#define CAN_MOIPR160H          (*((uword volatile far *) 0x20240A))

// Message Object 160 Interrupt Pointer Register Low
#define CAN_MOIPR160L          (*((uword volatile far *) 0x202408))

// Message Object 161 Interrupt Pointer Register High
#define CAN_MOIPR161H          (*((uword volatile far *) 0x20242A))

// Message Object 161 Interrupt Pointer Register Low
#define CAN_MOIPR161L          (*((uword volatile far *) 0x202428))

// Message Object 162 Interrupt Pointer Register High
#define CAN_MOIPR162H          (*((uword volatile far *) 0x20244A))

// Message Object 162 Interrupt Pointer Register Low
#define CAN_MOIPR162L          (*((uword volatile far *) 0x202448))

// Message Object 163 Interrupt Pointer Register High
#define CAN_MOIPR163H          (*((uword volatile far *) 0x20246A))

// Message Object 163 Interrupt Pointer Register Low
#define CAN_MOIPR163L          (*((uword volatile far *) 0x202468))

// Message Object 164 Interrupt Pointer Register High
#define CAN_MOIPR164H          (*((uword volatile far *) 0x20248A))

// Message Object 164 Interrupt Pointer Register Low
#define CAN_MOIPR164L          (*((uword volatile far *) 0x202488))

// Message Object 165 Interrupt Pointer Register High
#define CAN_MOIPR165H          (*((uword volatile far *) 0x2024AA))

// Message Object 165 Interrupt Pointer Register Low
#define CAN_MOIPR165L          (*((uword volatile far *) 0x2024A8))

// Message Object 166 Interrupt Pointer Register High
#define CAN_MOIPR166H          (*((uword volatile far *) 0x2024CA))

// Message Object 166 Interrupt Pointer Register Low
#define CAN_MOIPR166L          (*((uword volatile far *) 0x2024C8))

// Message Object 167 Interrupt Pointer Register High
#define CAN_MOIPR167H          (*((uword volatile far *) 0x2024EA))

// Message Object 167 Interrupt Pointer Register Low
#define CAN_MOIPR167L          (*((uword volatile far *) 0x2024E8))

// Message Object 168 Interrupt Pointer Register High
#define CAN_MOIPR168H          (*((uword volatile far *) 0x20250A))

// Message Object 168 Interrupt Pointer Register Low
#define CAN_MOIPR168L          (*((uword volatile far *) 0x202508))

// Message Object 169 Interrupt Pointer Register High
#define CAN_MOIPR169H          (*((uword volatile far *) 0x20252A))

// Message Object 169 Interrupt Pointer Register Low
#define CAN_MOIPR169L          (*((uword volatile far *) 0x202528))

// Message Object 16 Interrupt Pointer Register High
#define CAN_MOIPR16H           (*((uword volatile far *) 0x20120A))

// Message Object 16 Interrupt Pointer Register Low
#define CAN_MOIPR16L           (*((uword volatile far *) 0x201208))

// Message Object 170 Interrupt Pointer Register High
#define CAN_MOIPR170H          (*((uword volatile far *) 0x20254A))

// Message Object 170 Interrupt Pointer Register Low
#define CAN_MOIPR170L          (*((uword volatile far *) 0x202548))

// Message Object 171 Interrupt Pointer Register High
#define CAN_MOIPR171H          (*((uword volatile far *) 0x20256A))

// Message Object 171 Interrupt Pointer Register Low
#define CAN_MOIPR171L          (*((uword volatile far *) 0x202568))

// Message Object 172 Interrupt Pointer Register High
#define CAN_MOIPR172H          (*((uword volatile far *) 0x20258A))

// Message Object 172 Interrupt Pointer Register Low
#define CAN_MOIPR172L          (*((uword volatile far *) 0x202588))

// Message Object 173 Interrupt Pointer Register High
#define CAN_MOIPR173H          (*((uword volatile far *) 0x2025AA))

// Message Object 173 Interrupt Pointer Register Low
#define CAN_MOIPR173L          (*((uword volatile far *) 0x2025A8))

// Message Object 174 Interrupt Pointer Register High
#define CAN_MOIPR174H          (*((uword volatile far *) 0x2025CA))

// Message Object 174 Interrupt Pointer Register Low
#define CAN_MOIPR174L          (*((uword volatile far *) 0x2025C8))

// Message Object 175 Interrupt Pointer Register High
#define CAN_MOIPR175H          (*((uword volatile far *) 0x2025EA))

// Message Object 175 Interrupt Pointer Register Low
#define CAN_MOIPR175L          (*((uword volatile far *) 0x2025E8))

// Message Object 176 Interrupt Pointer Register High
#define CAN_MOIPR176H          (*((uword volatile far *) 0x20260A))

// Message Object 176 Interrupt Pointer Register Low
#define CAN_MOIPR176L          (*((uword volatile far *) 0x202608))

// Message Object 177 Interrupt Pointer Register High
#define CAN_MOIPR177H          (*((uword volatile far *) 0x20262A))

// Message Object 177 Interrupt Pointer Register Low
#define CAN_MOIPR177L          (*((uword volatile far *) 0x202628))

// Message Object 178 Interrupt Pointer Register High
#define CAN_MOIPR178H          (*((uword volatile far *) 0x20264A))

// Message Object 178 Interrupt Pointer Register Low
#define CAN_MOIPR178L          (*((uword volatile far *) 0x202648))

// Message Object 179 Interrupt Pointer Register High
#define CAN_MOIPR179H          (*((uword volatile far *) 0x20266A))

// Message Object 179 Interrupt Pointer Register Low
#define CAN_MOIPR179L          (*((uword volatile far *) 0x202668))

// Message Object 17 Interrupt Pointer Register High
#define CAN_MOIPR17H           (*((uword volatile far *) 0x20122A))

// Message Object 17 Interrupt Pointer Register Low
#define CAN_MOIPR17L           (*((uword volatile far *) 0x201228))

// Message Object 180 Interrupt Pointer Register High
#define CAN_MOIPR180H          (*((uword volatile far *) 0x20268A))

// Message Object 180 Interrupt Pointer Register Low
#define CAN_MOIPR180L          (*((uword volatile far *) 0x202688))

// Message Object 181 Interrupt Pointer Register High
#define CAN_MOIPR181H          (*((uword volatile far *) 0x2026AA))

// Message Object 181 Interrupt Pointer Register Low
#define CAN_MOIPR181L          (*((uword volatile far *) 0x2026A8))

// Message Object 182 Interrupt Pointer Register High
#define CAN_MOIPR182H          (*((uword volatile far *) 0x2026CA))

// Message Object 182 Interrupt Pointer Register Low
#define CAN_MOIPR182L          (*((uword volatile far *) 0x2026C8))

// Message Object 183 Interrupt Pointer Register High
#define CAN_MOIPR183H          (*((uword volatile far *) 0x2026EA))

// Message Object 183 Interrupt Pointer Register Low
#define CAN_MOIPR183L          (*((uword volatile far *) 0x2026E8))

// Message Object 184 Interrupt Pointer Register High
#define CAN_MOIPR184H          (*((uword volatile far *) 0x20270A))

// Message Object 184 Interrupt Pointer Register Low
#define CAN_MOIPR184L          (*((uword volatile far *) 0x202708))

// Message Object 185 Interrupt Pointer Register High
#define CAN_MOIPR185H          (*((uword volatile far *) 0x20272A))

// Message Object 185 Interrupt Pointer Register Low
#define CAN_MOIPR185L          (*((uword volatile far *) 0x202728))

// Message Object 186 Interrupt Pointer Register High
#define CAN_MOIPR186H          (*((uword volatile far *) 0x20274A))

// Message Object 186 Interrupt Pointer Register Low
#define CAN_MOIPR186L          (*((uword volatile far *) 0x202748))

// Message Object 187 Interrupt Pointer Register High
#define CAN_MOIPR187H          (*((uword volatile far *) 0x20276A))

// Message Object 187 Interrupt Pointer Register Low
#define CAN_MOIPR187L          (*((uword volatile far *) 0x202768))

// Message Object 188 Interrupt Pointer Register High
#define CAN_MOIPR188H          (*((uword volatile far *) 0x20278A))

// Message Object 188 Interrupt Pointer Register Low
#define CAN_MOIPR188L          (*((uword volatile far *) 0x202788))

// Message Object 189 Interrupt Pointer Register High
#define CAN_MOIPR189H          (*((uword volatile far *) 0x2027AA))

// Message Object 189 Interrupt Pointer Register Low
#define CAN_MOIPR189L          (*((uword volatile far *) 0x2027A8))

// Message Object 18 Interrupt Pointer Register High
#define CAN_MOIPR18H           (*((uword volatile far *) 0x20124A))

// Message Object 18 Interrupt Pointer Register Low
#define CAN_MOIPR18L           (*((uword volatile far *) 0x201248))

// Message Object 190 Interrupt Pointer Register High
#define CAN_MOIPR190H          (*((uword volatile far *) 0x2027CA))

// Message Object 190 Interrupt Pointer Register Low
#define CAN_MOIPR190L          (*((uword volatile far *) 0x2027C8))

// Message Object 191 Interrupt Pointer Register High
#define CAN_MOIPR191H          (*((uword volatile far *) 0x2027EA))

// Message Object 191 Interrupt Pointer Register Low
#define CAN_MOIPR191L          (*((uword volatile far *) 0x2027E8))

// Message Object 192 Interrupt Pointer Register High
#define CAN_MOIPR192H          (*((uword volatile far *) 0x20280A))

// Message Object 192 Interrupt Pointer Register Low
#define CAN_MOIPR192L          (*((uword volatile far *) 0x202808))

// Message Object 193 Interrupt Pointer Register High
#define CAN_MOIPR193H          (*((uword volatile far *) 0x20282A))

// Message Object 193 Interrupt Pointer Register Low
#define CAN_MOIPR193L          (*((uword volatile far *) 0x202828))

// Message Object 194 Interrupt Pointer Register High
#define CAN_MOIPR194H          (*((uword volatile far *) 0x20284A))

// Message Object 194 Interrupt Pointer Register Low
#define CAN_MOIPR194L          (*((uword volatile far *) 0x202848))

// Message Object 195 Interrupt Pointer Register High
#define CAN_MOIPR195H          (*((uword volatile far *) 0x20286A))

// Message Object 195 Interrupt Pointer Register Low
#define CAN_MOIPR195L          (*((uword volatile far *) 0x202868))

// Message Object 196 Interrupt Pointer Register High
#define CAN_MOIPR196H          (*((uword volatile far *) 0x20288A))

// Message Object 196 Interrupt Pointer Register Low
#define CAN_MOIPR196L          (*((uword volatile far *) 0x202888))

// Message Object 197 Interrupt Pointer Register High
#define CAN_MOIPR197H          (*((uword volatile far *) 0x2028AA))

// Message Object 197 Interrupt Pointer Register Low
#define CAN_MOIPR197L          (*((uword volatile far *) 0x2028A8))

// Message Object 198 Interrupt Pointer Register High
#define CAN_MOIPR198H          (*((uword volatile far *) 0x2028CA))

// Message Object 198 Interrupt Pointer Register Low
#define CAN_MOIPR198L          (*((uword volatile far *) 0x2028C8))

// Message Object 199 Interrupt Pointer Register High
#define CAN_MOIPR199H          (*((uword volatile far *) 0x2028EA))

// Message Object 199 Interrupt Pointer Register Low
#define CAN_MOIPR199L          (*((uword volatile far *) 0x2028E8))

// Message Object 19 Interrupt Pointer Register High
#define CAN_MOIPR19H           (*((uword volatile far *) 0x20126A))

// Message Object 19 Interrupt Pointer Register Low
#define CAN_MOIPR19L           (*((uword volatile far *) 0x201268))

// Message Object 1 Interrupt Pointer Register High
#define CAN_MOIPR1H            (*((uword volatile far *) 0x20102A))

// Message Object 1 Interrupt Pointer Register Low
#define CAN_MOIPR1L            (*((uword volatile far *) 0x201028))

// Message Object 200 Interrupt Pointer Register High
#define CAN_MOIPR200H          (*((uword volatile far *) 0x20290A))

// Message Object 200 Interrupt Pointer Register Low
#define CAN_MOIPR200L          (*((uword volatile far *) 0x202908))

// Message Object 201 Interrupt Pointer Register High
#define CAN_MOIPR201H          (*((uword volatile far *) 0x20292A))

// Message Object 201 Interrupt Pointer Register Low
#define CAN_MOIPR201L          (*((uword volatile far *) 0x202928))

// Message Object 202 Interrupt Pointer Register High
#define CAN_MOIPR202H          (*((uword volatile far *) 0x20294A))

// Message Object 202 Interrupt Pointer Register Low
#define CAN_MOIPR202L          (*((uword volatile far *) 0x202948))

// Message Object 203 Interrupt Pointer Register High
#define CAN_MOIPR203H          (*((uword volatile far *) 0x20296A))

// Message Object 203 Interrupt Pointer Register Low
#define CAN_MOIPR203L          (*((uword volatile far *) 0x202968))

// Message Object 204 Interrupt Pointer Register High
#define CAN_MOIPR204H          (*((uword volatile far *) 0x20298A))

// Message Object 204 Interrupt Pointer Register Low
#define CAN_MOIPR204L          (*((uword volatile far *) 0x202988))

// Message Object 205 Interrupt Pointer Register High
#define CAN_MOIPR205H          (*((uword volatile far *) 0x2029AA))

// Message Object 205 Interrupt Pointer Register Low
#define CAN_MOIPR205L          (*((uword volatile far *) 0x2029A8))

// Message Object 206 Interrupt Pointer Register High
#define CAN_MOIPR206H          (*((uword volatile far *) 0x2029CA))

// Message Object 206 Interrupt Pointer Register Low
#define CAN_MOIPR206L          (*((uword volatile far *) 0x2029C8))

// Message Object 207 Interrupt Pointer Register High
#define CAN_MOIPR207H          (*((uword volatile far *) 0x2029EA))

// Message Object 207 Interrupt Pointer Register Low
#define CAN_MOIPR207L          (*((uword volatile far *) 0x2029E8))

// Message Object 208 Interrupt Pointer Register High
#define CAN_MOIPR208H          (*((uword volatile far *) 0x202A0A))

// Message Object 208 Interrupt Pointer Register Low
#define CAN_MOIPR208L          (*((uword volatile far *) 0x202A08))

// Message Object 209 Interrupt Pointer Register High
#define CAN_MOIPR209H          (*((uword volatile far *) 0x202A2A))

// Message Object 209 Interrupt Pointer Register Low
#define CAN_MOIPR209L          (*((uword volatile far *) 0x202A28))

// Message Object 20 Interrupt Pointer Register High
#define CAN_MOIPR20H           (*((uword volatile far *) 0x20128A))

// Message Object 20 Interrupt Pointer Register Low
#define CAN_MOIPR20L           (*((uword volatile far *) 0x201288))

// Message Object 210 Interrupt Pointer Register High
#define CAN_MOIPR210H          (*((uword volatile far *) 0x202A4A))

// Message Object 210 Interrupt Pointer Register Low
#define CAN_MOIPR210L          (*((uword volatile far *) 0x202A48))

// Message Object 211 Interrupt Pointer Register High
#define CAN_MOIPR211H          (*((uword volatile far *) 0x202A6A))

// Message Object 211 Interrupt Pointer Register Low
#define CAN_MOIPR211L          (*((uword volatile far *) 0x202A68))

// Message Object 212 Interrupt Pointer Register High
#define CAN_MOIPR212H          (*((uword volatile far *) 0x202A8A))

// Message Object 212 Interrupt Pointer Register Low
#define CAN_MOIPR212L          (*((uword volatile far *) 0x202A88))

// Message Object 213 Interrupt Pointer Register High
#define CAN_MOIPR213H          (*((uword volatile far *) 0x202AAA))

// Message Object 213 Interrupt Pointer Register Low
#define CAN_MOIPR213L          (*((uword volatile far *) 0x202AA8))

// Message Object 214 Interrupt Pointer Register High
#define CAN_MOIPR214H          (*((uword volatile far *) 0x202ACA))

// Message Object 214 Interrupt Pointer Register Low
#define CAN_MOIPR214L          (*((uword volatile far *) 0x202AC8))

// Message Object 215 Interrupt Pointer Register High
#define CAN_MOIPR215H          (*((uword volatile far *) 0x202AEA))

// Message Object 215 Interrupt Pointer Register Low
#define CAN_MOIPR215L          (*((uword volatile far *) 0x202AE8))

// Message Object 216 Interrupt Pointer Register High
#define CAN_MOIPR216H          (*((uword volatile far *) 0x202B0A))

// Message Object 216 Interrupt Pointer Register Low
#define CAN_MOIPR216L          (*((uword volatile far *) 0x202B08))

// Message Object 217 Interrupt Pointer Register High
#define CAN_MOIPR217H          (*((uword volatile far *) 0x202B2A))

// Message Object 217 Interrupt Pointer Register Low
#define CAN_MOIPR217L          (*((uword volatile far *) 0x202B28))

// Message Object 218 Interrupt Pointer Register High
#define CAN_MOIPR218H          (*((uword volatile far *) 0x202B4A))

// Message Object 218 Interrupt Pointer Register Low
#define CAN_MOIPR218L          (*((uword volatile far *) 0x202B48))

// Message Object 219 Interrupt Pointer Register High
#define CAN_MOIPR219H          (*((uword volatile far *) 0x202B6A))

// Message Object 219 Interrupt Pointer Register Low
#define CAN_MOIPR219L          (*((uword volatile far *) 0x202B68))

// Message Object 21 Interrupt Pointer Register High
#define CAN_MOIPR21H           (*((uword volatile far *) 0x2012AA))

// Message Object 21 Interrupt Pointer Register Low
#define CAN_MOIPR21L           (*((uword volatile far *) 0x2012A8))

// Message Object 220 Interrupt Pointer Register High
#define CAN_MOIPR220H          (*((uword volatile far *) 0x202B8A))

// Message Object 220 Interrupt Pointer Register Low
#define CAN_MOIPR220L          (*((uword volatile far *) 0x202B88))

// Message Object 221 Interrupt Pointer Register High
#define CAN_MOIPR221H          (*((uword volatile far *) 0x202BAA))

// Message Object 221 Interrupt Pointer Register Low
#define CAN_MOIPR221L          (*((uword volatile far *) 0x202BA8))

// Message Object 222 Interrupt Pointer Register High
#define CAN_MOIPR222H          (*((uword volatile far *) 0x202BCA))

// Message Object 222 Interrupt Pointer Register Low
#define CAN_MOIPR222L          (*((uword volatile far *) 0x202BC8))

// Message Object 223 Interrupt Pointer Register High
#define CAN_MOIPR223H          (*((uword volatile far *) 0x202BEA))

// Message Object 223 Interrupt Pointer Register Low
#define CAN_MOIPR223L          (*((uword volatile far *) 0x202BE8))

// Message Object 224 Interrupt Pointer Register High
#define CAN_MOIPR224H          (*((uword volatile far *) 0x202C0A))

// Message Object 224 Interrupt Pointer Register Low
#define CAN_MOIPR224L          (*((uword volatile far *) 0x202C08))

// Message Object 225 Interrupt Pointer Register High
#define CAN_MOIPR225H          (*((uword volatile far *) 0x202C2A))

// Message Object 225 Interrupt Pointer Register Low
#define CAN_MOIPR225L          (*((uword volatile far *) 0x202C28))

// Message Object 226 Interrupt Pointer Register High
#define CAN_MOIPR226H          (*((uword volatile far *) 0x202C4A))

// Message Object 226 Interrupt Pointer Register Low
#define CAN_MOIPR226L          (*((uword volatile far *) 0x202C48))

// Message Object 227 Interrupt Pointer Register High
#define CAN_MOIPR227H          (*((uword volatile far *) 0x202C6A))

// Message Object 227 Interrupt Pointer Register Low
#define CAN_MOIPR227L          (*((uword volatile far *) 0x202C68))

// Message Object 228 Interrupt Pointer Register High
#define CAN_MOIPR228H          (*((uword volatile far *) 0x202C8A))

// Message Object 228 Interrupt Pointer Register Low
#define CAN_MOIPR228L          (*((uword volatile far *) 0x202C88))

// Message Object 229 Interrupt Pointer Register High
#define CAN_MOIPR229H          (*((uword volatile far *) 0x202CAA))

// Message Object 229 Interrupt Pointer Register Low
#define CAN_MOIPR229L          (*((uword volatile far *) 0x202CA8))

// Message Object 22 Interrupt Pointer Register High
#define CAN_MOIPR22H           (*((uword volatile far *) 0x2012CA))

// Message Object 22 Interrupt Pointer Register Low
#define CAN_MOIPR22L           (*((uword volatile far *) 0x2012C8))

// Message Object 230 Interrupt Pointer Register High
#define CAN_MOIPR230H          (*((uword volatile far *) 0x202CCA))

// Message Object 230 Interrupt Pointer Register Low
#define CAN_MOIPR230L          (*((uword volatile far *) 0x202CC8))

// Message Object 231 Interrupt Pointer Register High
#define CAN_MOIPR231H          (*((uword volatile far *) 0x202CEA))

// Message Object 231 Interrupt Pointer Register Low
#define CAN_MOIPR231L          (*((uword volatile far *) 0x202CE8))

// Message Object 232 Interrupt Pointer Register High
#define CAN_MOIPR232H          (*((uword volatile far *) 0x202D0A))

// Message Object 232 Interrupt Pointer Register Low
#define CAN_MOIPR232L          (*((uword volatile far *) 0x202D08))

// Message Object 233 Interrupt Pointer Register High
#define CAN_MOIPR233H          (*((uword volatile far *) 0x202D2A))

// Message Object 233 Interrupt Pointer Register Low
#define CAN_MOIPR233L          (*((uword volatile far *) 0x202D28))

// Message Object 234 Interrupt Pointer Register High
#define CAN_MOIPR234H          (*((uword volatile far *) 0x202D4A))

// Message Object 234 Interrupt Pointer Register Low
#define CAN_MOIPR234L          (*((uword volatile far *) 0x202D48))

// Message Object 235 Interrupt Pointer Register High
#define CAN_MOIPR235H          (*((uword volatile far *) 0x202D6A))

// Message Object 235 Interrupt Pointer Register Low
#define CAN_MOIPR235L          (*((uword volatile far *) 0x202D68))

// Message Object 236 Interrupt Pointer Register High
#define CAN_MOIPR236H          (*((uword volatile far *) 0x202D8A))

// Message Object 236 Interrupt Pointer Register Low
#define CAN_MOIPR236L          (*((uword volatile far *) 0x202D88))

// Message Object 237 Interrupt Pointer Register High
#define CAN_MOIPR237H          (*((uword volatile far *) 0x202DAA))

// Message Object 237 Interrupt Pointer Register Low
#define CAN_MOIPR237L          (*((uword volatile far *) 0x202DA8))

// Message Object 238 Interrupt Pointer Register High
#define CAN_MOIPR238H          (*((uword volatile far *) 0x202DCA))

// Message Object 238 Interrupt Pointer Register Low
#define CAN_MOIPR238L          (*((uword volatile far *) 0x202DC8))

// Message Object 239 Interrupt Pointer Register High
#define CAN_MOIPR239H          (*((uword volatile far *) 0x202DEA))

// Message Object 239 Interrupt Pointer Register Low
#define CAN_MOIPR239L          (*((uword volatile far *) 0x202DE8))

// Message Object 23 Interrupt Pointer Register High
#define CAN_MOIPR23H           (*((uword volatile far *) 0x2012EA))

// Message Object 23 Interrupt Pointer Register Low
#define CAN_MOIPR23L           (*((uword volatile far *) 0x2012E8))

// Message Object 240 Interrupt Pointer Register High
#define CAN_MOIPR240H          (*((uword volatile far *) 0x202E0A))

// Message Object 240 Interrupt Pointer Register Low
#define CAN_MOIPR240L          (*((uword volatile far *) 0x202E08))

// Message Object 241 Interrupt Pointer Register High
#define CAN_MOIPR241H          (*((uword volatile far *) 0x202E2A))

// Message Object 241 Interrupt Pointer Register Low
#define CAN_MOIPR241L          (*((uword volatile far *) 0x202E28))

// Message Object 242 Interrupt Pointer Register High
#define CAN_MOIPR242H          (*((uword volatile far *) 0x202E4A))

// Message Object 242 Interrupt Pointer Register Low
#define CAN_MOIPR242L          (*((uword volatile far *) 0x202E48))

// Message Object 243 Interrupt Pointer Register High
#define CAN_MOIPR243H          (*((uword volatile far *) 0x202E6A))

// Message Object 243 Interrupt Pointer Register Low
#define CAN_MOIPR243L          (*((uword volatile far *) 0x202E68))

// Message Object 244 Interrupt Pointer Register High
#define CAN_MOIPR244H          (*((uword volatile far *) 0x202E8A))

// Message Object 244 Interrupt Pointer Register Low
#define CAN_MOIPR244L          (*((uword volatile far *) 0x202E88))

// Message Object 245 Interrupt Pointer Register High
#define CAN_MOIPR245H          (*((uword volatile far *) 0x202EAA))

// Message Object 245 Interrupt Pointer Register Low
#define CAN_MOIPR245L          (*((uword volatile far *) 0x202EA8))

// Message Object 246 Interrupt Pointer Register High
#define CAN_MOIPR246H          (*((uword volatile far *) 0x202ECA))

// Message Object 246 Interrupt Pointer Register Low
#define CAN_MOIPR246L          (*((uword volatile far *) 0x202EC8))

// Message Object 247 Interrupt Pointer Register High
#define CAN_MOIPR247H          (*((uword volatile far *) 0x202EEA))

// Message Object 247 Interrupt Pointer Register Low
#define CAN_MOIPR247L          (*((uword volatile far *) 0x202EE8))

// Message Object 248 Interrupt Pointer Register High
#define CAN_MOIPR248H          (*((uword volatile far *) 0x202F0A))

// Message Object 248 Interrupt Pointer Register Low
#define CAN_MOIPR248L          (*((uword volatile far *) 0x202F08))

// Message Object 249 Interrupt Pointer Register High
#define CAN_MOIPR249H          (*((uword volatile far *) 0x202F2A))

// Message Object 249 Interrupt Pointer Register Low
#define CAN_MOIPR249L          (*((uword volatile far *) 0x202F28))

// Message Object 24 Interrupt Pointer Register High
#define CAN_MOIPR24H           (*((uword volatile far *) 0x20130A))

// Message Object 24 Interrupt Pointer Register Low
#define CAN_MOIPR24L           (*((uword volatile far *) 0x201308))

// Message Object 250 Interrupt Pointer Register High
#define CAN_MOIPR250H          (*((uword volatile far *) 0x202F4A))

// Message Object 250 Interrupt Pointer Register Low
#define CAN_MOIPR250L          (*((uword volatile far *) 0x202F48))

// Message Object 251 Interrupt Pointer Register High
#define CAN_MOIPR251H          (*((uword volatile far *) 0x202F6A))

// Message Object 251 Interrupt Pointer Register Low
#define CAN_MOIPR251L          (*((uword volatile far *) 0x202F68))

// Message Object 252 Interrupt Pointer Register High
#define CAN_MOIPR252H          (*((uword volatile far *) 0x202F8A))

// Message Object 252 Interrupt Pointer Register Low
#define CAN_MOIPR252L          (*((uword volatile far *) 0x202F88))

// Message Object 253 Interrupt Pointer Register High
#define CAN_MOIPR253H          (*((uword volatile far *) 0x202FAA))

// Message Object 253 Interrupt Pointer Register Low
#define CAN_MOIPR253L          (*((uword volatile far *) 0x202FA8))

// Message Object 254 Interrupt Pointer Register High
#define CAN_MOIPR254H          (*((uword volatile far *) 0x202FCA))

// Message Object 254 Interrupt Pointer Register Low
#define CAN_MOIPR254L          (*((uword volatile far *) 0x202FC8))

// Message Object 255 Interrupt Pointer Register High
#define CAN_MOIPR255H          (*((uword volatile far *) 0x202FEA))

// Message Object 255 Interrupt Pointer Register Low
#define CAN_MOIPR255L          (*((uword volatile far *) 0x202FE8))

// Message Object 25 Interrupt Pointer Register High
#define CAN_MOIPR25H           (*((uword volatile far *) 0x20132A))

// Message Object 25 Interrupt Pointer Register Low
#define CAN_MOIPR25L           (*((uword volatile far *) 0x201328))

// Message Object 26 Interrupt Pointer Register High
#define CAN_MOIPR26H           (*((uword volatile far *) 0x20134A))

// Message Object 26 Interrupt Pointer Register Low
#define CAN_MOIPR26L           (*((uword volatile far *) 0x201348))

// Message Object 27 Interrupt Pointer Register High
#define CAN_MOIPR27H           (*((uword volatile far *) 0x20136A))

// Message Object 27 Interrupt Pointer Register Low
#define CAN_MOIPR27L           (*((uword volatile far *) 0x201368))

// Message Object 28 Interrupt Pointer Register High
#define CAN_MOIPR28H           (*((uword volatile far *) 0x20138A))

// Message Object 28 Interrupt Pointer Register Low
#define CAN_MOIPR28L           (*((uword volatile far *) 0x201388))

// Message Object 29 Interrupt Pointer Register High
#define CAN_MOIPR29H           (*((uword volatile far *) 0x2013AA))

// Message Object 29 Interrupt Pointer Register Low
#define CAN_MOIPR29L           (*((uword volatile far *) 0x2013A8))

// Message Object 2 Interrupt Pointer Register High
#define CAN_MOIPR2H            (*((uword volatile far *) 0x20104A))

// Message Object 2 Interrupt Pointer Register Low
#define CAN_MOIPR2L            (*((uword volatile far *) 0x201048))

// Message Object 30 Interrupt Pointer Register High
#define CAN_MOIPR30H           (*((uword volatile far *) 0x2013CA))

// Message Object 30 Interrupt Pointer Register Low
#define CAN_MOIPR30L           (*((uword volatile far *) 0x2013C8))

// Message Object 31 Interrupt Pointer Register High
#define CAN_MOIPR31H           (*((uword volatile far *) 0x2013EA))

// Message Object 31 Interrupt Pointer Register Low
#define CAN_MOIPR31L           (*((uword volatile far *) 0x2013E8))

// Message Object 32 Interrupt Pointer Register High
#define CAN_MOIPR32H           (*((uword volatile far *) 0x20140A))

// Message Object 32 Interrupt Pointer Register Low
#define CAN_MOIPR32L           (*((uword volatile far *) 0x201408))

// Message Object 33 Interrupt Pointer Register High
#define CAN_MOIPR33H           (*((uword volatile far *) 0x20142A))

// Message Object 33 Interrupt Pointer Register Low
#define CAN_MOIPR33L           (*((uword volatile far *) 0x201428))

// Message Object 34 Interrupt Pointer Register High
#define CAN_MOIPR34H           (*((uword volatile far *) 0x20144A))

// Message Object 34 Interrupt Pointer Register Low
#define CAN_MOIPR34L           (*((uword volatile far *) 0x201448))

// Message Object 35 Interrupt Pointer Register High
#define CAN_MOIPR35H           (*((uword volatile far *) 0x20146A))

// Message Object 35 Interrupt Pointer Register Low
#define CAN_MOIPR35L           (*((uword volatile far *) 0x201468))

// Message Object 36 Interrupt Pointer Register High
#define CAN_MOIPR36H           (*((uword volatile far *) 0x20148A))

// Message Object 36 Interrupt Pointer Register Low
#define CAN_MOIPR36L           (*((uword volatile far *) 0x201488))

// Message Object 37 Interrupt Pointer Register High
#define CAN_MOIPR37H           (*((uword volatile far *) 0x2014AA))

// Message Object 37 Interrupt Pointer Register Low
#define CAN_MOIPR37L           (*((uword volatile far *) 0x2014A8))

// Message Object 38 Interrupt Pointer Register High
#define CAN_MOIPR38H           (*((uword volatile far *) 0x2014CA))

// Message Object 38 Interrupt Pointer Register Low
#define CAN_MOIPR38L           (*((uword volatile far *) 0x2014C8))

// Message Object 39 Interrupt Pointer Register High
#define CAN_MOIPR39H           (*((uword volatile far *) 0x2014EA))

// Message Object 39 Interrupt Pointer Register Low
#define CAN_MOIPR39L           (*((uword volatile far *) 0x2014E8))

// Message Object 3 Interrupt Pointer Register High
#define CAN_MOIPR3H            (*((uword volatile far *) 0x20106A))

// Message Object 3 Interrupt Pointer Register Low
#define CAN_MOIPR3L            (*((uword volatile far *) 0x201068))

// Message Object 40 Interrupt Pointer Register High
#define CAN_MOIPR40H           (*((uword volatile far *) 0x20150A))

// Message Object 40 Interrupt Pointer Register Low
#define CAN_MOIPR40L           (*((uword volatile far *) 0x201508))

// Message Object 41 Interrupt Pointer Register High
#define CAN_MOIPR41H           (*((uword volatile far *) 0x20152A))

// Message Object 41 Interrupt Pointer Register Low
#define CAN_MOIPR41L           (*((uword volatile far *) 0x201528))

// Message Object 42 Interrupt Pointer Register High
#define CAN_MOIPR42H           (*((uword volatile far *) 0x20154A))

// Message Object 42 Interrupt Pointer Register Low
#define CAN_MOIPR42L           (*((uword volatile far *) 0x201548))

// Message Object 43 Interrupt Pointer Register High
#define CAN_MOIPR43H           (*((uword volatile far *) 0x20156A))

// Message Object 43 Interrupt Pointer Register Low
#define CAN_MOIPR43L           (*((uword volatile far *) 0x201568))

// Message Object 44 Interrupt Pointer Register High
#define CAN_MOIPR44H           (*((uword volatile far *) 0x20158A))

// Message Object 44 Interrupt Pointer Register Low
#define CAN_MOIPR44L           (*((uword volatile far *) 0x201588))

// Message Object 45 Interrupt Pointer Register High
#define CAN_MOIPR45H           (*((uword volatile far *) 0x2015AA))

// Message Object 45 Interrupt Pointer Register Low
#define CAN_MOIPR45L           (*((uword volatile far *) 0x2015A8))

// Message Object 46 Interrupt Pointer Register High
#define CAN_MOIPR46H           (*((uword volatile far *) 0x2015CA))

// Message Object 46 Interrupt Pointer Register Low
#define CAN_MOIPR46L           (*((uword volatile far *) 0x2015C8))

// Message Object 47 Interrupt Pointer Register High
#define CAN_MOIPR47H           (*((uword volatile far *) 0x2015EA))

// Message Object 47 Interrupt Pointer Register Low
#define CAN_MOIPR47L           (*((uword volatile far *) 0x2015E8))

// Message Object 48 Interrupt Pointer Register High
#define CAN_MOIPR48H           (*((uword volatile far *) 0x20160A))

// Message Object 48 Interrupt Pointer Register Low
#define CAN_MOIPR48L           (*((uword volatile far *) 0x201608))

// Message Object 49 Interrupt Pointer Register High
#define CAN_MOIPR49H           (*((uword volatile far *) 0x20162A))

// Message Object 49 Interrupt Pointer Register Low
#define CAN_MOIPR49L           (*((uword volatile far *) 0x201628))

// Message Object 4 Interrupt Pointer Register High
#define CAN_MOIPR4H            (*((uword volatile far *) 0x20108A))

// Message Object 4 Interrupt Pointer Register Low
#define CAN_MOIPR4L            (*((uword volatile far *) 0x201088))

// Message Object 50 Interrupt Pointer Register High
#define CAN_MOIPR50H           (*((uword volatile far *) 0x20164A))

// Message Object 50 Interrupt Pointer Register Low
#define CAN_MOIPR50L           (*((uword volatile far *) 0x201648))

// Message Object 51 Interrupt Pointer Register High
#define CAN_MOIPR51H           (*((uword volatile far *) 0x20166A))

// Message Object 51 Interrupt Pointer Register Low
#define CAN_MOIPR51L           (*((uword volatile far *) 0x201668))

// Message Object 52 Interrupt Pointer Register High
#define CAN_MOIPR52H           (*((uword volatile far *) 0x20168A))

// Message Object 52 Interrupt Pointer Register Low
#define CAN_MOIPR52L           (*((uword volatile far *) 0x201688))

// Message Object 53 Interrupt Pointer Register High
#define CAN_MOIPR53H           (*((uword volatile far *) 0x2016AA))

// Message Object 53 Interrupt Pointer Register Low
#define CAN_MOIPR53L           (*((uword volatile far *) 0x2016A8))

// Message Object 54 Interrupt Pointer Register High
#define CAN_MOIPR54H           (*((uword volatile far *) 0x2016CA))

// Message Object 54 Interrupt Pointer Register Low
#define CAN_MOIPR54L           (*((uword volatile far *) 0x2016C8))

// Message Object 55 Interrupt Pointer Register High
#define CAN_MOIPR55H           (*((uword volatile far *) 0x2016EA))

// Message Object 55 Interrupt Pointer Register Low
#define CAN_MOIPR55L           (*((uword volatile far *) 0x2016E8))

// Message Object 56 Interrupt Pointer Register High
#define CAN_MOIPR56H           (*((uword volatile far *) 0x20170A))

// Message Object 56 Interrupt Pointer Register Low
#define CAN_MOIPR56L           (*((uword volatile far *) 0x201708))

// Message Object 57 Interrupt Pointer Register High
#define CAN_MOIPR57H           (*((uword volatile far *) 0x20172A))

// Message Object 57 Interrupt Pointer Register Low
#define CAN_MOIPR57L           (*((uword volatile far *) 0x201728))

// Message Object 58 Interrupt Pointer Register High
#define CAN_MOIPR58H           (*((uword volatile far *) 0x20174A))

// Message Object 58 Interrupt Pointer Register Low
#define CAN_MOIPR58L           (*((uword volatile far *) 0x201748))

// Message Object 59 Interrupt Pointer Register High
#define CAN_MOIPR59H           (*((uword volatile far *) 0x20176A))

// Message Object 59 Interrupt Pointer Register Low
#define CAN_MOIPR59L           (*((uword volatile far *) 0x201768))

// Message Object 5 Interrupt Pointer Register High
#define CAN_MOIPR5H            (*((uword volatile far *) 0x2010AA))

// Message Object 5 Interrupt Pointer Register Low
#define CAN_MOIPR5L            (*((uword volatile far *) 0x2010A8))

// Message Object 60 Interrupt Pointer Register High
#define CAN_MOIPR60H           (*((uword volatile far *) 0x20178A))

// Message Object 60 Interrupt Pointer Register Low
#define CAN_MOIPR60L           (*((uword volatile far *) 0x201788))

// Message Object 61 Interrupt Pointer Register High
#define CAN_MOIPR61H           (*((uword volatile far *) 0x2017AA))

// Message Object 61 Interrupt Pointer Register Low
#define CAN_MOIPR61L           (*((uword volatile far *) 0x2017A8))

// Message Object 62 Interrupt Pointer Register High
#define CAN_MOIPR62H           (*((uword volatile far *) 0x2017CA))

// Message Object 62 Interrupt Pointer Register Low
#define CAN_MOIPR62L           (*((uword volatile far *) 0x2017C8))

// Message Object 63 Interrupt Pointer Register High
#define CAN_MOIPR63H           (*((uword volatile far *) 0x2017EA))

// Message Object 63 Interrupt Pointer Register Low
#define CAN_MOIPR63L           (*((uword volatile far *) 0x2017E8))

// Message Object 64 Interrupt Pointer Register High
#define CAN_MOIPR64H           (*((uword volatile far *) 0x20180A))

// Message Object 64 Interrupt Pointer Register Low
#define CAN_MOIPR64L           (*((uword volatile far *) 0x201808))

// Message Object 65 Interrupt Pointer Register High
#define CAN_MOIPR65H           (*((uword volatile far *) 0x20182A))

// Message Object 65 Interrupt Pointer Register Low
#define CAN_MOIPR65L           (*((uword volatile far *) 0x201828))

// Message Object 66 Interrupt Pointer Register High
#define CAN_MOIPR66H           (*((uword volatile far *) 0x20184A))

// Message Object 66 Interrupt Pointer Register Low
#define CAN_MOIPR66L           (*((uword volatile far *) 0x201848))

// Message Object 67 Interrupt Pointer Register High
#define CAN_MOIPR67H           (*((uword volatile far *) 0x20186A))

// Message Object 67 Interrupt Pointer Register Low
#define CAN_MOIPR67L           (*((uword volatile far *) 0x201868))

// Message Object 68 Interrupt Pointer Register High
#define CAN_MOIPR68H           (*((uword volatile far *) 0x20188A))

// Message Object 68 Interrupt Pointer Register Low
#define CAN_MOIPR68L           (*((uword volatile far *) 0x201888))

// Message Object 69 Interrupt Pointer Register High
#define CAN_MOIPR69H           (*((uword volatile far *) 0x2018AA))

// Message Object 69 Interrupt Pointer Register Low
#define CAN_MOIPR69L           (*((uword volatile far *) 0x2018A8))

// Message Object 6 Interrupt Pointer Register High
#define CAN_MOIPR6H            (*((uword volatile far *) 0x2010CA))

// Message Object 6 Interrupt Pointer Register Low
#define CAN_MOIPR6L            (*((uword volatile far *) 0x2010C8))

// Message Object 70 Interrupt Pointer Register High
#define CAN_MOIPR70H           (*((uword volatile far *) 0x2018CA))

// Message Object 70 Interrupt Pointer Register Low
#define CAN_MOIPR70L           (*((uword volatile far *) 0x2018C8))

// Message Object 71 Interrupt Pointer Register High
#define CAN_MOIPR71H           (*((uword volatile far *) 0x2018EA))

// Message Object 71 Interrupt Pointer Register Low
#define CAN_MOIPR71L           (*((uword volatile far *) 0x2018E8))

// Message Object 72 Interrupt Pointer Register High
#define CAN_MOIPR72H           (*((uword volatile far *) 0x20190A))

// Message Object 72 Interrupt Pointer Register Low
#define CAN_MOIPR72L           (*((uword volatile far *) 0x201908))

// Message Object 73 Interrupt Pointer Register High
#define CAN_MOIPR73H           (*((uword volatile far *) 0x20192A))

// Message Object 73 Interrupt Pointer Register Low
#define CAN_MOIPR73L           (*((uword volatile far *) 0x201928))

// Message Object 74 Interrupt Pointer Register High
#define CAN_MOIPR74H           (*((uword volatile far *) 0x20194A))

// Message Object 74 Interrupt Pointer Register Low
#define CAN_MOIPR74L           (*((uword volatile far *) 0x201948))

// Message Object 75 Interrupt Pointer Register High
#define CAN_MOIPR75H           (*((uword volatile far *) 0x20196A))

// Message Object 75 Interrupt Pointer Register Low
#define CAN_MOIPR75L           (*((uword volatile far *) 0x201968))

// Message Object 76 Interrupt Pointer Register High
#define CAN_MOIPR76H           (*((uword volatile far *) 0x20198A))

// Message Object 76 Interrupt Pointer Register Low
#define CAN_MOIPR76L           (*((uword volatile far *) 0x201988))

// Message Object 77 Interrupt Pointer Register High
#define CAN_MOIPR77H           (*((uword volatile far *) 0x2019AA))

// Message Object 77 Interrupt Pointer Register Low
#define CAN_MOIPR77L           (*((uword volatile far *) 0x2019A8))

// Message Object 78 Interrupt Pointer Register High
#define CAN_MOIPR78H           (*((uword volatile far *) 0x2019CA))

// Message Object 78 Interrupt Pointer Register Low
#define CAN_MOIPR78L           (*((uword volatile far *) 0x2019C8))

// Message Object 79 Interrupt Pointer Register High
#define CAN_MOIPR79H           (*((uword volatile far *) 0x2019EA))

// Message Object 79 Interrupt Pointer Register Low
#define CAN_MOIPR79L           (*((uword volatile far *) 0x2019E8))

// Message Object 7 Interrupt Pointer Register High
#define CAN_MOIPR7H            (*((uword volatile far *) 0x2010EA))

// Message Object 7 Interrupt Pointer Register Low
#define CAN_MOIPR7L            (*((uword volatile far *) 0x2010E8))

// Message Object 80 Interrupt Pointer Register High
#define CAN_MOIPR80H           (*((uword volatile far *) 0x201A0A))

// Message Object 80 Interrupt Pointer Register Low
#define CAN_MOIPR80L           (*((uword volatile far *) 0x201A08))

// Message Object 81 Interrupt Pointer Register High
#define CAN_MOIPR81H           (*((uword volatile far *) 0x201A2A))

// Message Object 81 Interrupt Pointer Register Low
#define CAN_MOIPR81L           (*((uword volatile far *) 0x201A28))

// Message Object 82 Interrupt Pointer Register High
#define CAN_MOIPR82H           (*((uword volatile far *) 0x201A4A))

// Message Object 82 Interrupt Pointer Register Low
#define CAN_MOIPR82L           (*((uword volatile far *) 0x201A48))

// Message Object 83 Interrupt Pointer Register High
#define CAN_MOIPR83H           (*((uword volatile far *) 0x201A6A))

// Message Object 83 Interrupt Pointer Register Low
#define CAN_MOIPR83L           (*((uword volatile far *) 0x201A68))

// Message Object 84 Interrupt Pointer Register High
#define CAN_MOIPR84H           (*((uword volatile far *) 0x201A8A))

// Message Object 84 Interrupt Pointer Register Low
#define CAN_MOIPR84L           (*((uword volatile far *) 0x201A88))

// Message Object 85 Interrupt Pointer Register High
#define CAN_MOIPR85H           (*((uword volatile far *) 0x201AAA))

// Message Object 85 Interrupt Pointer Register Low
#define CAN_MOIPR85L           (*((uword volatile far *) 0x201AA8))

// Message Object 86 Interrupt Pointer Register High
#define CAN_MOIPR86H           (*((uword volatile far *) 0x201ACA))

// Message Object 86 Interrupt Pointer Register Low
#define CAN_MOIPR86L           (*((uword volatile far *) 0x201AC8))

// Message Object 87 Interrupt Pointer Register High
#define CAN_MOIPR87H           (*((uword volatile far *) 0x201AEA))

// Message Object 87 Interrupt Pointer Register Low
#define CAN_MOIPR87L           (*((uword volatile far *) 0x201AE8))

// Message Object 88 Interrupt Pointer Register High
#define CAN_MOIPR88H           (*((uword volatile far *) 0x201B0A))

// Message Object 88 Interrupt Pointer Register Low
#define CAN_MOIPR88L           (*((uword volatile far *) 0x201B08))

// Message Object 89 Interrupt Pointer Register High
#define CAN_MOIPR89H           (*((uword volatile far *) 0x201B2A))

// Message Object 89 Interrupt Pointer Register Low
#define CAN_MOIPR89L           (*((uword volatile far *) 0x201B28))

// Message Object 8 Interrupt Pointer Register High
#define CAN_MOIPR8H            (*((uword volatile far *) 0x20110A))

// Message Object 8 Interrupt Pointer Register Low
#define CAN_MOIPR8L            (*((uword volatile far *) 0x201108))

// Message Object 90 Interrupt Pointer Register High
#define CAN_MOIPR90H           (*((uword volatile far *) 0x201B4A))

// Message Object 90 Interrupt Pointer Register Low
#define CAN_MOIPR90L           (*((uword volatile far *) 0x201B48))

// Message Object 91 Interrupt Pointer Register High
#define CAN_MOIPR91H           (*((uword volatile far *) 0x201B6A))

// Message Object 91 Interrupt Pointer Register Low
#define CAN_MOIPR91L           (*((uword volatile far *) 0x201B68))

// Message Object 92 Interrupt Pointer Register High
#define CAN_MOIPR92H           (*((uword volatile far *) 0x201B8A))

// Message Object 92 Interrupt Pointer Register Low
#define CAN_MOIPR92L           (*((uword volatile far *) 0x201B88))

// Message Object 93 Interrupt Pointer Register High
#define CAN_MOIPR93H           (*((uword volatile far *) 0x201BAA))

// Message Object 93 Interrupt Pointer Register Low
#define CAN_MOIPR93L           (*((uword volatile far *) 0x201BA8))

// Message Object 94 Interrupt Pointer Register High
#define CAN_MOIPR94H           (*((uword volatile far *) 0x201BCA))

// Message Object 94 Interrupt Pointer Register Low
#define CAN_MOIPR94L           (*((uword volatile far *) 0x201BC8))

// Message Object 95 Interrupt Pointer Register High
#define CAN_MOIPR95H           (*((uword volatile far *) 0x201BEA))

// Message Object 95 Interrupt Pointer Register Low
#define CAN_MOIPR95L           (*((uword volatile far *) 0x201BE8))

// Message Object 96 Interrupt Pointer Register High
#define CAN_MOIPR96H           (*((uword volatile far *) 0x201C0A))

// Message Object 96 Interrupt Pointer Register Low
#define CAN_MOIPR96L           (*((uword volatile far *) 0x201C08))

// Message Object 97 Interrupt Pointer Register High
#define CAN_MOIPR97H           (*((uword volatile far *) 0x201C2A))

// Message Object 97 Interrupt Pointer Register Low
#define CAN_MOIPR97L           (*((uword volatile far *) 0x201C28))

// Message Object 98 Interrupt Pointer Register High
#define CAN_MOIPR98H           (*((uword volatile far *) 0x201C4A))

// Message Object 98 Interrupt Pointer Register Low
#define CAN_MOIPR98L           (*((uword volatile far *) 0x201C48))

// Message Object 99 Interrupt Pointer Register High
#define CAN_MOIPR99H           (*((uword volatile far *) 0x201C6A))

// Message Object 99 Interrupt Pointer Register Low
#define CAN_MOIPR99L           (*((uword volatile far *) 0x201C68))

// Message Object 9 Interrupt Pointer Register High
#define CAN_MOIPR9H            (*((uword volatile far *) 0x20112A))

// Message Object 9 Interrupt Pointer Register Low
#define CAN_MOIPR9L            (*((uword volatile far *) 0x201128))

// Message Object 0 Status Register High
#define CAN_MOSTAT0H           (*((uword volatile far *) 0x20101E))

// Message Object 0 Control Register Low
#define CAN_MOSTAT0L           (*((uword volatile far *) 0x20101C))

// Message Object 100 Status Register High
#define CAN_MOSTAT100H         (*((uword volatile far *) 0x201C9E))

// Message Object 100 Control Register Low
#define CAN_MOSTAT100L         (*((uword volatile far *) 0x201C9C))

// Message Object 101 Status Register High
#define CAN_MOSTAT101H         (*((uword volatile far *) 0x201CBE))

// Message Object 101 Control Register Low
#define CAN_MOSTAT101L         (*((uword volatile far *) 0x201CBC))

// Message Object 102 Status Register High
#define CAN_MOSTAT102H         (*((uword volatile far *) 0x201CDE))

// Message Object 102 Control Register Low
#define CAN_MOSTAT102L         (*((uword volatile far *) 0x201CDC))

// Message Object 103 Status Register High
#define CAN_MOSTAT103H         (*((uword volatile far *) 0x201CFE))

// Message Object 103 Control Register Low
#define CAN_MOSTAT103L         (*((uword volatile far *) 0x201CFC))

// Message Object 104 Status Register High
#define CAN_MOSTAT104H         (*((uword volatile far *) 0x201D1E))

// Message Object 104 Control Register Low
#define CAN_MOSTAT104L         (*((uword volatile far *) 0x201D1C))

// Message Object 105 Status Register High
#define CAN_MOSTAT105H         (*((uword volatile far *) 0x201D3E))

// Message Object 105 Control Register Low
#define CAN_MOSTAT105L         (*((uword volatile far *) 0x201D3C))

// Message Object 106 Status Register High
#define CAN_MOSTAT106H         (*((uword volatile far *) 0x201D5E))

// Message Object 106 Control Register Low
#define CAN_MOSTAT106L         (*((uword volatile far *) 0x201D5C))

// Message Object 107 Status Register High
#define CAN_MOSTAT107H         (*((uword volatile far *) 0x201D7E))

// Message Object 107 Control Register Low
#define CAN_MOSTAT107L         (*((uword volatile far *) 0x201D7C))

// Message Object 108 Status Register High
#define CAN_MOSTAT108H         (*((uword volatile far *) 0x201D9E))

// Message Object 108 Control Register Low
#define CAN_MOSTAT108L         (*((uword volatile far *) 0x201D9C))

// Message Object 109 Status Register High
#define CAN_MOSTAT109H         (*((uword volatile far *) 0x201DBE))

// Message Object 109 Control Register Low
#define CAN_MOSTAT109L         (*((uword volatile far *) 0x201DBC))

// Message Object 10 Status Register High
#define CAN_MOSTAT10H          (*((uword volatile far *) 0x20115E))

// Message Object 10 Control Register Low
#define CAN_MOSTAT10L          (*((uword volatile far *) 0x20115C))

// Message Object 110 Status Register High
#define CAN_MOSTAT110H         (*((uword volatile far *) 0x201DDE))

// Message Object 110 Control Register Low
#define CAN_MOSTAT110L         (*((uword volatile far *) 0x201DDC))

// Message Object 111 Status Register High
#define CAN_MOSTAT111H         (*((uword volatile far *) 0x201DFE))

// Message Object 111 Control Register Low
#define CAN_MOSTAT111L         (*((uword volatile far *) 0x201DFC))

// Message Object 112 Status Register High
#define CAN_MOSTAT112H         (*((uword volatile far *) 0x201E1E))

// Message Object 112 Control Register Low
#define CAN_MOSTAT112L         (*((uword volatile far *) 0x201E1C))

// Message Object 113 Status Register High
#define CAN_MOSTAT113H         (*((uword volatile far *) 0x201E3E))

// Message Object 113 Control Register Low
#define CAN_MOSTAT113L         (*((uword volatile far *) 0x201E3C))

// Message Object 114 Status Register High
#define CAN_MOSTAT114H         (*((uword volatile far *) 0x201E5E))

// Message Object 114 Control Register Low
#define CAN_MOSTAT114L         (*((uword volatile far *) 0x201E5C))

// Message Object 115 Status Register High
#define CAN_MOSTAT115H         (*((uword volatile far *) 0x201E7E))

// Message Object 115 Control Register Low
#define CAN_MOSTAT115L         (*((uword volatile far *) 0x201E7C))

// Message Object 116 Status Register High
#define CAN_MOSTAT116H         (*((uword volatile far *) 0x201E9E))

// Message Object 116 Control Register Low
#define CAN_MOSTAT116L         (*((uword volatile far *) 0x201E9C))

// Message Object 117 Status Register High
#define CAN_MOSTAT117H         (*((uword volatile far *) 0x201EBE))

// Message Object 117 Control Register Low
#define CAN_MOSTAT117L         (*((uword volatile far *) 0x201EBC))

// Message Object 118 Status Register High
#define CAN_MOSTAT118H         (*((uword volatile far *) 0x201EDE))

// Message Object 118 Control Register Low
#define CAN_MOSTAT118L         (*((uword volatile far *) 0x201EDC))

// Message Object 119 Status Register High
#define CAN_MOSTAT119H         (*((uword volatile far *) 0x201EFE))

// Message Object 119 Control Register Low
#define CAN_MOSTAT119L         (*((uword volatile far *) 0x201EFC))

// Message Object 11 Status Register High
#define CAN_MOSTAT11H          (*((uword volatile far *) 0x20117E))

// Message Object 11 Control Register Low
#define CAN_MOSTAT11L          (*((uword volatile far *) 0x20117C))

// Message Object 120 Status Register High
#define CAN_MOSTAT120H         (*((uword volatile far *) 0x201F1E))

// Message Object 120 Control Register Low
#define CAN_MOSTAT120L         (*((uword volatile far *) 0x201F1C))

// Message Object 121 Status Register High
#define CAN_MOSTAT121H         (*((uword volatile far *) 0x201F3E))

// Message Object 121 Control Register Low
#define CAN_MOSTAT121L         (*((uword volatile far *) 0x201F3C))

// Message Object 122 Status Register High
#define CAN_MOSTAT122H         (*((uword volatile far *) 0x201F5E))

// Message Object 122 Control Register Low
#define CAN_MOSTAT122L         (*((uword volatile far *) 0x201F5C))

// Message Object 123 Status Register High
#define CAN_MOSTAT123H         (*((uword volatile far *) 0x201F7E))

// Message Object 123 Control Register Low
#define CAN_MOSTAT123L         (*((uword volatile far *) 0x201F7C))

// Message Object 124 Status Register High
#define CAN_MOSTAT124H         (*((uword volatile far *) 0x201F9E))

// Message Object 124 Control Register Low
#define CAN_MOSTAT124L         (*((uword volatile far *) 0x201F9C))

// Message Object 125 Status Register High
#define CAN_MOSTAT125H         (*((uword volatile far *) 0x201FBE))

// Message Object 125 Control Register Low
#define CAN_MOSTAT125L         (*((uword volatile far *) 0x201FBC))

// Message Object 126 Status Register High
#define CAN_MOSTAT126H         (*((uword volatile far *) 0x201FDE))

// Message Object 126 Control Register Low
#define CAN_MOSTAT126L         (*((uword volatile far *) 0x201FDC))

// Message Object 127 Status Register High
#define CAN_MOSTAT127H         (*((uword volatile far *) 0x201FFE))

// Message Object 127 Control Register Low
#define CAN_MOSTAT127L         (*((uword volatile far *) 0x201FFC))

// Message Object 128 Status Register High
#define CAN_MOSTAT128H         (*((uword volatile far *) 0x20201E))

// Message Object 128 Control Register Low
#define CAN_MOSTAT128L         (*((uword volatile far *) 0x20201C))

// Message Object 129 Status Register High
#define CAN_MOSTAT129H         (*((uword volatile far *) 0x20203E))

// Message Object 129 Control Register Low
#define CAN_MOSTAT129L         (*((uword volatile far *) 0x20203C))

// Message Object 12 Status Register High
#define CAN_MOSTAT12H          (*((uword volatile far *) 0x20119E))

// Message Object 12 Control Register Low
#define CAN_MOSTAT12L          (*((uword volatile far *) 0x20119C))

// Message Object 130 Status Register High
#define CAN_MOSTAT130H         (*((uword volatile far *) 0x20205E))

// Message Object 130 Control Register Low
#define CAN_MOSTAT130L         (*((uword volatile far *) 0x20205C))

// Message Object 131 Status Register High
#define CAN_MOSTAT131H         (*((uword volatile far *) 0x20207E))

// Message Object 131 Control Register Low
#define CAN_MOSTAT131L         (*((uword volatile far *) 0x20207C))

// Message Object 132 Status Register High
#define CAN_MOSTAT132H         (*((uword volatile far *) 0x20209E))

// Message Object 132 Control Register Low
#define CAN_MOSTAT132L         (*((uword volatile far *) 0x20209C))

// Message Object 133 Status Register High
#define CAN_MOSTAT133H         (*((uword volatile far *) 0x2020BE))

// Message Object 133 Control Register Low
#define CAN_MOSTAT133L         (*((uword volatile far *) 0x2020BC))

// Message Object 134 Status Register High
#define CAN_MOSTAT134H         (*((uword volatile far *) 0x2020DE))

// Message Object 134 Control Register Low
#define CAN_MOSTAT134L         (*((uword volatile far *) 0x2020DC))

// Message Object 135 Status Register High
#define CAN_MOSTAT135H         (*((uword volatile far *) 0x2020FE))

// Message Object 135 Control Register Low
#define CAN_MOSTAT135L         (*((uword volatile far *) 0x2020FC))

// Message Object 136 Status Register High
#define CAN_MOSTAT136H         (*((uword volatile far *) 0x20211E))

// Message Object 136 Control Register Low
#define CAN_MOSTAT136L         (*((uword volatile far *) 0x20211C))

// Message Object 137 Status Register High
#define CAN_MOSTAT137H         (*((uword volatile far *) 0x20213E))

// Message Object 137 Control Register Low
#define CAN_MOSTAT137L         (*((uword volatile far *) 0x20213C))

// Message Object 138 Status Register High
#define CAN_MOSTAT138H         (*((uword volatile far *) 0x20215E))

// Message Object 138 Control Register Low
#define CAN_MOSTAT138L         (*((uword volatile far *) 0x20215C))

// Message Object 139 Status Register High
#define CAN_MOSTAT139H         (*((uword volatile far *) 0x20217E))

// Message Object 139 Control Register Low
#define CAN_MOSTAT139L         (*((uword volatile far *) 0x20217C))

// Message Object 13 Status Register High
#define CAN_MOSTAT13H          (*((uword volatile far *) 0x2011BE))

// Message Object 13 Control Register Low
#define CAN_MOSTAT13L          (*((uword volatile far *) 0x2011BC))

// Message Object 140 Status Register High
#define CAN_MOSTAT140H         (*((uword volatile far *) 0x20219E))

// Message Object 140 Control Register Low
#define CAN_MOSTAT140L         (*((uword volatile far *) 0x20219C))

// Message Object 141 Status Register High
#define CAN_MOSTAT141H         (*((uword volatile far *) 0x2021BE))

// Message Object 141 Control Register Low
#define CAN_MOSTAT141L         (*((uword volatile far *) 0x2021BC))

// Message Object 142 Status Register High
#define CAN_MOSTAT142H         (*((uword volatile far *) 0x2021DE))

// Message Object 142 Control Register Low
#define CAN_MOSTAT142L         (*((uword volatile far *) 0x2021DC))

// Message Object 143 Status Register High
#define CAN_MOSTAT143H         (*((uword volatile far *) 0x2021FE))

// Message Object 143 Control Register Low
#define CAN_MOSTAT143L         (*((uword volatile far *) 0x2021FC))

// Message Object 144 Status Register High
#define CAN_MOSTAT144H         (*((uword volatile far *) 0x20221E))

// Message Object 144 Control Register Low
#define CAN_MOSTAT144L         (*((uword volatile far *) 0x20221C))

// Message Object 145 Status Register High
#define CAN_MOSTAT145H         (*((uword volatile far *) 0x20223E))

// Message Object 145 Control Register Low
#define CAN_MOSTAT145L         (*((uword volatile far *) 0x20223C))

// Message Object 146 Status Register High
#define CAN_MOSTAT146H         (*((uword volatile far *) 0x20225E))

// Message Object 146 Control Register Low
#define CAN_MOSTAT146L         (*((uword volatile far *) 0x20225C))

// Message Object 147 Status Register High
#define CAN_MOSTAT147H         (*((uword volatile far *) 0x20227E))

// Message Object 147 Control Register Low
#define CAN_MOSTAT147L         (*((uword volatile far *) 0x20227C))

// Message Object 148 Status Register High
#define CAN_MOSTAT148H         (*((uword volatile far *) 0x20229E))

// Message Object 148 Control Register Low
#define CAN_MOSTAT148L         (*((uword volatile far *) 0x20229C))

// Message Object 149 Status Register High
#define CAN_MOSTAT149H         (*((uword volatile far *) 0x2022BE))

// Message Object 149 Control Register Low
#define CAN_MOSTAT149L         (*((uword volatile far *) 0x2022BC))

// Message Object 14 Status Register High
#define CAN_MOSTAT14H          (*((uword volatile far *) 0x2011DE))

// Message Object 14 Control Register Low
#define CAN_MOSTAT14L          (*((uword volatile far *) 0x2011DC))

// Message Object 150 Status Register High
#define CAN_MOSTAT150H         (*((uword volatile far *) 0x2022DE))

// Message Object 150 Control Register Low
#define CAN_MOSTAT150L         (*((uword volatile far *) 0x2022DC))

// Message Object 151 Status Register High
#define CAN_MOSTAT151H         (*((uword volatile far *) 0x2022FE))

// Message Object 151 Control Register Low
#define CAN_MOSTAT151L         (*((uword volatile far *) 0x2022FC))

// Message Object 152 Status Register High
#define CAN_MOSTAT152H         (*((uword volatile far *) 0x20231E))

// Message Object 152 Control Register Low
#define CAN_MOSTAT152L         (*((uword volatile far *) 0x20231C))

// Message Object 153 Status Register High
#define CAN_MOSTAT153H         (*((uword volatile far *) 0x20233E))

// Message Object 153 Control Register Low
#define CAN_MOSTAT153L         (*((uword volatile far *) 0x20233C))

// Message Object 154 Status Register High
#define CAN_MOSTAT154H         (*((uword volatile far *) 0x20235E))

// Message Object 154 Control Register Low
#define CAN_MOSTAT154L         (*((uword volatile far *) 0x20235C))

// Message Object 155 Status Register High
#define CAN_MOSTAT155H         (*((uword volatile far *) 0x20237E))

// Message Object 155 Control Register Low
#define CAN_MOSTAT155L         (*((uword volatile far *) 0x20237C))

// Message Object 156 Status Register High
#define CAN_MOSTAT156H         (*((uword volatile far *) 0x20239E))

// Message Object 156 Control Register Low
#define CAN_MOSTAT156L         (*((uword volatile far *) 0x20239C))

// Message Object 157 Status Register High
#define CAN_MOSTAT157H         (*((uword volatile far *) 0x2023BE))

// Message Object 157 Control Register Low
#define CAN_MOSTAT157L         (*((uword volatile far *) 0x2023BC))

// Message Object 158 Status Register High
#define CAN_MOSTAT158H         (*((uword volatile far *) 0x2023DE))

// Message Object 158 Control Register Low
#define CAN_MOSTAT158L         (*((uword volatile far *) 0x2023DC))

// Message Object 159 Status Register High
#define CAN_MOSTAT159H         (*((uword volatile far *) 0x2023FE))

// Message Object 159 Control Register Low
#define CAN_MOSTAT159L         (*((uword volatile far *) 0x2023FC))

// Message Object 15 Status Register High
#define CAN_MOSTAT15H          (*((uword volatile far *) 0x2011FE))

// Message Object 15 Control Register Low
#define CAN_MOSTAT15L          (*((uword volatile far *) 0x2011FC))

// Message Object 160 Status Register High
#define CAN_MOSTAT160H         (*((uword volatile far *) 0x20241E))

// Message Object 160 Control Register Low
#define CAN_MOSTAT160L         (*((uword volatile far *) 0x20241C))

// Message Object 161 Status Register High
#define CAN_MOSTAT161H         (*((uword volatile far *) 0x20243E))

// Message Object 161 Control Register Low
#define CAN_MOSTAT161L         (*((uword volatile far *) 0x20243C))

// Message Object 162 Status Register High
#define CAN_MOSTAT162H         (*((uword volatile far *) 0x20245E))

// Message Object 162 Control Register Low
#define CAN_MOSTAT162L         (*((uword volatile far *) 0x20245C))

// Message Object 163 Status Register High
#define CAN_MOSTAT163H         (*((uword volatile far *) 0x20247E))

// Message Object 163 Control Register Low
#define CAN_MOSTAT163L         (*((uword volatile far *) 0x20247C))

// Message Object 164 Status Register High
#define CAN_MOSTAT164H         (*((uword volatile far *) 0x20249E))

// Message Object 164 Control Register Low
#define CAN_MOSTAT164L         (*((uword volatile far *) 0x20249C))

// Message Object 165 Status Register High
#define CAN_MOSTAT165H         (*((uword volatile far *) 0x2024BE))

// Message Object 165 Control Register Low
#define CAN_MOSTAT165L         (*((uword volatile far *) 0x2024BC))

// Message Object 166 Status Register High
#define CAN_MOSTAT166H         (*((uword volatile far *) 0x2024DE))

// Message Object 166 Control Register Low
#define CAN_MOSTAT166L         (*((uword volatile far *) 0x2024DC))

// Message Object 167 Status Register High
#define CAN_MOSTAT167H         (*((uword volatile far *) 0x2024FE))

// Message Object 167 Control Register Low
#define CAN_MOSTAT167L         (*((uword volatile far *) 0x2024FC))

// Message Object 168 Status Register High
#define CAN_MOSTAT168H         (*((uword volatile far *) 0x20251E))

// Message Object 168 Control Register Low
#define CAN_MOSTAT168L         (*((uword volatile far *) 0x20251C))

// Message Object 169 Status Register High
#define CAN_MOSTAT169H         (*((uword volatile far *) 0x20253E))

// Message Object 169 Control Register Low
#define CAN_MOSTAT169L         (*((uword volatile far *) 0x20253C))

// Message Object 16 Status Register High
#define CAN_MOSTAT16H          (*((uword volatile far *) 0x20121E))

// Message Object 16 Control Register Low
#define CAN_MOSTAT16L          (*((uword volatile far *) 0x20121C))

// Message Object 170 Status Register High
#define CAN_MOSTAT170H         (*((uword volatile far *) 0x20255E))

// Message Object 170 Control Register Low
#define CAN_MOSTAT170L         (*((uword volatile far *) 0x20255C))

// Message Object 171 Status Register High
#define CAN_MOSTAT171H         (*((uword volatile far *) 0x20257E))

// Message Object 171 Control Register Low
#define CAN_MOSTAT171L         (*((uword volatile far *) 0x20257C))

// Message Object 172 Status Register High
#define CAN_MOSTAT172H         (*((uword volatile far *) 0x20259E))

// Message Object 172 Control Register Low
#define CAN_MOSTAT172L         (*((uword volatile far *) 0x20259C))

// Message Object 173 Status Register High
#define CAN_MOSTAT173H         (*((uword volatile far *) 0x2025BE))

// Message Object 173 Control Register Low
#define CAN_MOSTAT173L         (*((uword volatile far *) 0x2025BC))

// Message Object 174 Status Register High
#define CAN_MOSTAT174H         (*((uword volatile far *) 0x2025DE))

// Message Object 174 Control Register Low
#define CAN_MOSTAT174L         (*((uword volatile far *) 0x2025DC))

// Message Object 175 Status Register High
#define CAN_MOSTAT175H         (*((uword volatile far *) 0x2025FE))

// Message Object 175 Control Register Low
#define CAN_MOSTAT175L         (*((uword volatile far *) 0x2025FC))

// Message Object 176 Status Register High
#define CAN_MOSTAT176H         (*((uword volatile far *) 0x20261E))

// Message Object 176 Control Register Low
#define CAN_MOSTAT176L         (*((uword volatile far *) 0x20261C))

// Message Object 177 Status Register High
#define CAN_MOSTAT177H         (*((uword volatile far *) 0x20263E))

// Message Object 177 Control Register Low
#define CAN_MOSTAT177L         (*((uword volatile far *) 0x20263C))

// Message Object 178 Status Register High
#define CAN_MOSTAT178H         (*((uword volatile far *) 0x20265E))

// Message Object 178 Control Register Low
#define CAN_MOSTAT178L         (*((uword volatile far *) 0x20265C))

// Message Object 179 Status Register High
#define CAN_MOSTAT179H         (*((uword volatile far *) 0x20267E))

// Message Object 179 Control Register Low
#define CAN_MOSTAT179L         (*((uword volatile far *) 0x20267C))

// Message Object 17 Status Register High
#define CAN_MOSTAT17H          (*((uword volatile far *) 0x20123E))

// Message Object 17 Control Register Low
#define CAN_MOSTAT17L          (*((uword volatile far *) 0x20123C))

// Message Object 180 Status Register High
#define CAN_MOSTAT180H         (*((uword volatile far *) 0x20269E))

// Message Object 180 Control Register Low
#define CAN_MOSTAT180L         (*((uword volatile far *) 0x20269C))

// Message Object 181 Status Register High
#define CAN_MOSTAT181H         (*((uword volatile far *) 0x2026BE))

// Message Object 181 Control Register Low
#define CAN_MOSTAT181L         (*((uword volatile far *) 0x2026BC))

// Message Object 182 Status Register High
#define CAN_MOSTAT182H         (*((uword volatile far *) 0x2026DE))

// Message Object 182 Control Register Low
#define CAN_MOSTAT182L         (*((uword volatile far *) 0x2026DC))

// Message Object 183 Status Register High
#define CAN_MOSTAT183H         (*((uword volatile far *) 0x2026FE))

// Message Object 183 Control Register Low
#define CAN_MOSTAT183L         (*((uword volatile far *) 0x2026FC))

// Message Object 184 Status Register High
#define CAN_MOSTAT184H         (*((uword volatile far *) 0x20271E))

// Message Object 184 Control Register Low
#define CAN_MOSTAT184L         (*((uword volatile far *) 0x20271C))

// Message Object 185 Status Register High
#define CAN_MOSTAT185H         (*((uword volatile far *) 0x20273E))

// Message Object 185 Control Register Low
#define CAN_MOSTAT185L         (*((uword volatile far *) 0x20273C))

// Message Object 186 Status Register High
#define CAN_MOSTAT186H         (*((uword volatile far *) 0x20275E))

// Message Object 186 Control Register Low
#define CAN_MOSTAT186L         (*((uword volatile far *) 0x20275C))

// Message Object 187 Status Register High
#define CAN_MOSTAT187H         (*((uword volatile far *) 0x20277E))

// Message Object 187 Control Register Low
#define CAN_MOSTAT187L         (*((uword volatile far *) 0x20277C))

// Message Object 188 Status Register High
#define CAN_MOSTAT188H         (*((uword volatile far *) 0x20279E))

// Message Object 188 Control Register Low
#define CAN_MOSTAT188L         (*((uword volatile far *) 0x20279C))

// Message Object 189 Status Register High
#define CAN_MOSTAT189H         (*((uword volatile far *) 0x2027BE))

// Message Object 189 Control Register Low
#define CAN_MOSTAT189L         (*((uword volatile far *) 0x2027BC))

// Message Object 18 Status Register High
#define CAN_MOSTAT18H          (*((uword volatile far *) 0x20125E))

// Message Object 18 Control Register Low
#define CAN_MOSTAT18L          (*((uword volatile far *) 0x20125C))

// Message Object 190 Status Register High
#define CAN_MOSTAT190H         (*((uword volatile far *) 0x2027DE))

// Message Object 190 Control Register Low
#define CAN_MOSTAT190L         (*((uword volatile far *) 0x2027DC))

// Message Object 191 Status Register High
#define CAN_MOSTAT191H         (*((uword volatile far *) 0x2027FE))

// Message Object 191 Control Register Low
#define CAN_MOSTAT191L         (*((uword volatile far *) 0x2027FC))

// Message Object 192 Status Register High
#define CAN_MOSTAT192H         (*((uword volatile far *) 0x20281E))

// Message Object 192 Control Register Low
#define CAN_MOSTAT192L         (*((uword volatile far *) 0x20281C))

// Message Object 193 Status Register High
#define CAN_MOSTAT193H         (*((uword volatile far *) 0x20283E))

// Message Object 193 Control Register Low
#define CAN_MOSTAT193L         (*((uword volatile far *) 0x20283C))

// Message Object 194 Status Register High
#define CAN_MOSTAT194H         (*((uword volatile far *) 0x20285E))

// Message Object 194 Control Register Low
#define CAN_MOSTAT194L         (*((uword volatile far *) 0x20285C))

// Message Object 195 Status Register High
#define CAN_MOSTAT195H         (*((uword volatile far *) 0x20287E))

// Message Object 195 Control Register Low
#define CAN_MOSTAT195L         (*((uword volatile far *) 0x20287C))

// Message Object 196 Status Register High
#define CAN_MOSTAT196H         (*((uword volatile far *) 0x20289E))

// Message Object 196 Control Register Low
#define CAN_MOSTAT196L         (*((uword volatile far *) 0x20289C))

// Message Object 197 Status Register High
#define CAN_MOSTAT197H         (*((uword volatile far *) 0x2028BE))

// Message Object 197 Control Register Low
#define CAN_MOSTAT197L         (*((uword volatile far *) 0x2028BC))

// Message Object 198 Status Register High
#define CAN_MOSTAT198H         (*((uword volatile far *) 0x2028DE))

// Message Object 198 Control Register Low
#define CAN_MOSTAT198L         (*((uword volatile far *) 0x2028DC))

// Message Object 199 Status Register High
#define CAN_MOSTAT199H         (*((uword volatile far *) 0x2028FE))

// Message Object 199 Control Register Low
#define CAN_MOSTAT199L         (*((uword volatile far *) 0x2028FC))

// Message Object 19 Status Register High
#define CAN_MOSTAT19H          (*((uword volatile far *) 0x20127E))

// Message Object 19 Control Register Low
#define CAN_MOSTAT19L          (*((uword volatile far *) 0x20127C))

// Message Object 1 Status Register High
#define CAN_MOSTAT1H           (*((uword volatile far *) 0x20103E))

// Message Object 1 Control Register Low
#define CAN_MOSTAT1L           (*((uword volatile far *) 0x20103C))

// Message Object 200 Status Register High
#define CAN_MOSTAT200H         (*((uword volatile far *) 0x20291E))

// Message Object 200 Control Register Low
#define CAN_MOSTAT200L         (*((uword volatile far *) 0x20291C))

// Message Object 201 Status Register High
#define CAN_MOSTAT201H         (*((uword volatile far *) 0x20293E))

// Message Object 201 Control Register Low
#define CAN_MOSTAT201L         (*((uword volatile far *) 0x20293C))

// Message Object 202 Status Register High
#define CAN_MOSTAT202H         (*((uword volatile far *) 0x20295E))

// Message Object 202 Control Register Low
#define CAN_MOSTAT202L         (*((uword volatile far *) 0x20295C))

// Message Object 203 Status Register High
#define CAN_MOSTAT203H         (*((uword volatile far *) 0x20297E))

// Message Object 203 Control Register Low
#define CAN_MOSTAT203L         (*((uword volatile far *) 0x20297C))

// Message Object 204 Status Register High
#define CAN_MOSTAT204H         (*((uword volatile far *) 0x20299E))

// Message Object 204 Control Register Low
#define CAN_MOSTAT204L         (*((uword volatile far *) 0x20299C))

// Message Object 205 Status Register High
#define CAN_MOSTAT205H         (*((uword volatile far *) 0x2029BE))

// Message Object 205 Control Register Low
#define CAN_MOSTAT205L         (*((uword volatile far *) 0x2029BC))

// Message Object 206 Status Register High
#define CAN_MOSTAT206H         (*((uword volatile far *) 0x2029DE))

// Message Object 206 Control Register Low
#define CAN_MOSTAT206L         (*((uword volatile far *) 0x2029DC))

// Message Object 207 Status Register High
#define CAN_MOSTAT207H         (*((uword volatile far *) 0x2029FE))

// Message Object 207 Control Register Low
#define CAN_MOSTAT207L         (*((uword volatile far *) 0x2029FC))

// Message Object 208 Status Register High
#define CAN_MOSTAT208H         (*((uword volatile far *) 0x202A1E))

// Message Object 208 Control Register Low
#define CAN_MOSTAT208L         (*((uword volatile far *) 0x202A1C))

// Message Object 209 Status Register High
#define CAN_MOSTAT209H         (*((uword volatile far *) 0x202A3E))

// Message Object 209 Control Register Low
#define CAN_MOSTAT209L         (*((uword volatile far *) 0x202A3C))

// Message Object 20 Status Register High
#define CAN_MOSTAT20H          (*((uword volatile far *) 0x20129E))

// Message Object 20 Control Register Low
#define CAN_MOSTAT20L          (*((uword volatile far *) 0x20129C))

// Message Object 210 Status Register High
#define CAN_MOSTAT210H         (*((uword volatile far *) 0x202A5E))

// Message Object 210 Control Register Low
#define CAN_MOSTAT210L         (*((uword volatile far *) 0x202A5C))

// Message Object 211 Status Register High
#define CAN_MOSTAT211H         (*((uword volatile far *) 0x202A7E))

// Message Object 211 Control Register Low
#define CAN_MOSTAT211L         (*((uword volatile far *) 0x202A7C))

// Message Object 212 Status Register High
#define CAN_MOSTAT212H         (*((uword volatile far *) 0x202A9E))

// Message Object 212 Control Register Low
#define CAN_MOSTAT212L         (*((uword volatile far *) 0x202A9C))

// Message Object 213 Status Register High
#define CAN_MOSTAT213H         (*((uword volatile far *) 0x202ABE))

// Message Object 213 Control Register Low
#define CAN_MOSTAT213L         (*((uword volatile far *) 0x202ABC))

// Message Object 214 Status Register High
#define CAN_MOSTAT214H         (*((uword volatile far *) 0x202ADE))

// Message Object 214 Control Register Low
#define CAN_MOSTAT214L         (*((uword volatile far *) 0x202ADC))

// Message Object 215 Status Register High
#define CAN_MOSTAT215H         (*((uword volatile far *) 0x202AFE))

// Message Object 215 Control Register Low
#define CAN_MOSTAT215L         (*((uword volatile far *) 0x202AFC))

// Message Object 216 Status Register High
#define CAN_MOSTAT216H         (*((uword volatile far *) 0x202B1E))

// Message Object 216 Control Register Low
#define CAN_MOSTAT216L         (*((uword volatile far *) 0x202B1C))

// Message Object 217 Status Register High
#define CAN_MOSTAT217H         (*((uword volatile far *) 0x202B3E))

// Message Object 217 Control Register Low
#define CAN_MOSTAT217L         (*((uword volatile far *) 0x202B3C))

// Message Object 218 Status Register High
#define CAN_MOSTAT218H         (*((uword volatile far *) 0x202B5E))

// Message Object 218 Control Register Low
#define CAN_MOSTAT218L         (*((uword volatile far *) 0x202B5C))

// Message Object 219 Status Register High
#define CAN_MOSTAT219H         (*((uword volatile far *) 0x202B7E))

// Message Object 219 Control Register Low
#define CAN_MOSTAT219L         (*((uword volatile far *) 0x202B7C))

// Message Object 21 Status Register High
#define CAN_MOSTAT21H          (*((uword volatile far *) 0x2012BE))

// Message Object 21 Control Register Low
#define CAN_MOSTAT21L          (*((uword volatile far *) 0x2012BC))

// Message Object 220 Status Register High
#define CAN_MOSTAT220H         (*((uword volatile far *) 0x202B9E))

// Message Object 220 Control Register Low
#define CAN_MOSTAT220L         (*((uword volatile far *) 0x202B9C))

// Message Object 221 Status Register High
#define CAN_MOSTAT221H         (*((uword volatile far *) 0x202BBE))

// Message Object 221 Control Register Low
#define CAN_MOSTAT221L         (*((uword volatile far *) 0x202BBC))

// Message Object 222 Status Register High
#define CAN_MOSTAT222H         (*((uword volatile far *) 0x202BDE))

// Message Object 222 Control Register Low
#define CAN_MOSTAT222L         (*((uword volatile far *) 0x202BDC))

// Message Object 223 Status Register High
#define CAN_MOSTAT223H         (*((uword volatile far *) 0x202BFE))

// Message Object 223 Control Register Low
#define CAN_MOSTAT223L         (*((uword volatile far *) 0x202BFC))

// Message Object 224 Status Register High
#define CAN_MOSTAT224H         (*((uword volatile far *) 0x202C1E))

// Message Object 224 Control Register Low
#define CAN_MOSTAT224L         (*((uword volatile far *) 0x202C1C))

// Message Object 225 Status Register High
#define CAN_MOSTAT225H         (*((uword volatile far *) 0x202C3E))

// Message Object 225 Control Register Low
#define CAN_MOSTAT225L         (*((uword volatile far *) 0x202C3C))

// Message Object 226 Status Register High
#define CAN_MOSTAT226H         (*((uword volatile far *) 0x202C5E))

// Message Object 226 Control Register Low
#define CAN_MOSTAT226L         (*((uword volatile far *) 0x202C5C))

// Message Object 227 Status Register High
#define CAN_MOSTAT227H         (*((uword volatile far *) 0x202C7E))

// Message Object 227 Control Register Low
#define CAN_MOSTAT227L         (*((uword volatile far *) 0x202C7C))

// Message Object 228 Status Register High
#define CAN_MOSTAT228H         (*((uword volatile far *) 0x202C9E))

// Message Object 228 Control Register Low
#define CAN_MOSTAT228L         (*((uword volatile far *) 0x202C9C))

// Message Object 229 Status Register High
#define CAN_MOSTAT229H         (*((uword volatile far *) 0x202CBE))

// Message Object 229 Control Register Low
#define CAN_MOSTAT229L         (*((uword volatile far *) 0x202CBC))

// Message Object 22 Status Register High
#define CAN_MOSTAT22H          (*((uword volatile far *) 0x2012DE))

// Message Object 22 Control Register Low
#define CAN_MOSTAT22L          (*((uword volatile far *) 0x2012DC))

// Message Object 230 Status Register High
#define CAN_MOSTAT230H         (*((uword volatile far *) 0x202CDE))

// Message Object 230 Control Register Low
#define CAN_MOSTAT230L         (*((uword volatile far *) 0x202CDC))

// Message Object 231 Status Register High
#define CAN_MOSTAT231H         (*((uword volatile far *) 0x202CFE))

// Message Object 231 Control Register Low
#define CAN_MOSTAT231L         (*((uword volatile far *) 0x202CFC))

// Message Object 232 Status Register High
#define CAN_MOSTAT232H         (*((uword volatile far *) 0x202D1E))

// Message Object 232 Control Register Low
#define CAN_MOSTAT232L         (*((uword volatile far *) 0x202D1C))

// Message Object 233 Status Register High
#define CAN_MOSTAT233H         (*((uword volatile far *) 0x202D3E))

// Message Object 233 Control Register Low
#define CAN_MOSTAT233L         (*((uword volatile far *) 0x202D3C))

// Message Object 234 Status Register High
#define CAN_MOSTAT234H         (*((uword volatile far *) 0x202D5E))

// Message Object 234 Control Register Low
#define CAN_MOSTAT234L         (*((uword volatile far *) 0x202D5C))

// Message Object 235 Status Register High
#define CAN_MOSTAT235H         (*((uword volatile far *) 0x202D7E))

// Message Object 235 Control Register Low
#define CAN_MOSTAT235L         (*((uword volatile far *) 0x202D7C))

// Message Object 236 Status Register High
#define CAN_MOSTAT236H         (*((uword volatile far *) 0x202D9E))

// Message Object 236 Control Register Low
#define CAN_MOSTAT236L         (*((uword volatile far *) 0x202D9C))

// Message Object 237 Status Register High
#define CAN_MOSTAT237H         (*((uword volatile far *) 0x202DBE))

// Message Object 237 Control Register Low
#define CAN_MOSTAT237L         (*((uword volatile far *) 0x202DBC))

// Message Object 238 Status Register High
#define CAN_MOSTAT238H         (*((uword volatile far *) 0x202DDE))

// Message Object 238 Control Register Low
#define CAN_MOSTAT238L         (*((uword volatile far *) 0x202DDC))

// Message Object 239 Status Register High
#define CAN_MOSTAT239H         (*((uword volatile far *) 0x202DFE))

// Message Object 239 Control Register Low
#define CAN_MOSTAT239L         (*((uword volatile far *) 0x202DFC))

// Message Object 23 Status Register High
#define CAN_MOSTAT23H          (*((uword volatile far *) 0x2012FE))

// Message Object 23 Control Register Low
#define CAN_MOSTAT23L          (*((uword volatile far *) 0x2012FC))

// Message Object 240 Status Register High
#define CAN_MOSTAT240H         (*((uword volatile far *) 0x202E1E))

// Message Object 240 Control Register Low
#define CAN_MOSTAT240L         (*((uword volatile far *) 0x202E1C))

// Message Object 241 Status Register High
#define CAN_MOSTAT241H         (*((uword volatile far *) 0x202E3E))

// Message Object 241 Control Register Low
#define CAN_MOSTAT241L         (*((uword volatile far *) 0x202E3C))

// Message Object 242 Status Register High
#define CAN_MOSTAT242H         (*((uword volatile far *) 0x202E5E))

// Message Object 242 Control Register Low
#define CAN_MOSTAT242L         (*((uword volatile far *) 0x202E5C))

// Message Object 243 Status Register High
#define CAN_MOSTAT243H         (*((uword volatile far *) 0x202E7E))

// Message Object 243 Control Register Low
#define CAN_MOSTAT243L         (*((uword volatile far *) 0x202E7C))

// Message Object 244 Status Register High
#define CAN_MOSTAT244H         (*((uword volatile far *) 0x202E9E))

// Message Object 244 Control Register Low
#define CAN_MOSTAT244L         (*((uword volatile far *) 0x202E9C))

// Message Object 245 Status Register High
#define CAN_MOSTAT245H         (*((uword volatile far *) 0x202EBE))

// Message Object 245 Control Register Low
#define CAN_MOSTAT245L         (*((uword volatile far *) 0x202EBC))

// Message Object 246 Status Register High
#define CAN_MOSTAT246H         (*((uword volatile far *) 0x202EDE))

// Message Object 246 Control Register Low
#define CAN_MOSTAT246L         (*((uword volatile far *) 0x202EDC))

// Message Object 247 Status Register High
#define CAN_MOSTAT247H         (*((uword volatile far *) 0x202EFE))

// Message Object 247 Control Register Low
#define CAN_MOSTAT247L         (*((uword volatile far *) 0x202EFC))

// Message Object 248 Status Register High
#define CAN_MOSTAT248H         (*((uword volatile far *) 0x202F1E))

// Message Object 248 Control Register Low
#define CAN_MOSTAT248L         (*((uword volatile far *) 0x202F1C))

// Message Object 249 Status Register High
#define CAN_MOSTAT249H         (*((uword volatile far *) 0x202F3E))

// Message Object 249 Control Register Low
#define CAN_MOSTAT249L         (*((uword volatile far *) 0x202F3C))

// Message Object 24 Status Register High
#define CAN_MOSTAT24H          (*((uword volatile far *) 0x20131E))

// Message Object 24 Control Register Low
#define CAN_MOSTAT24L          (*((uword volatile far *) 0x20131C))

// Message Object 250 Status Register High
#define CAN_MOSTAT250H         (*((uword volatile far *) 0x202F5E))

// Message Object 250 Control Register Low
#define CAN_MOSTAT250L         (*((uword volatile far *) 0x202F5C))

// Message Object 251 Status Register High
#define CAN_MOSTAT251H         (*((uword volatile far *) 0x202F7E))

// Message Object 251 Control Register Low
#define CAN_MOSTAT251L         (*((uword volatile far *) 0x202F7C))

// Message Object 252 Status Register High
#define CAN_MOSTAT252H         (*((uword volatile far *) 0x202F9E))

// Message Object 252 Control Register Low
#define CAN_MOSTAT252L         (*((uword volatile far *) 0x202F9C))

// Message Object 253 Status Register High
#define CAN_MOSTAT253H         (*((uword volatile far *) 0x202FBE))

// Message Object 253 Control Register Low
#define CAN_MOSTAT253L         (*((uword volatile far *) 0x202FBC))

// Message Object 254 Status Register High
#define CAN_MOSTAT254H         (*((uword volatile far *) 0x202FDE))

// Message Object 254 Control Register Low
#define CAN_MOSTAT254L         (*((uword volatile far *) 0x202FDC))

// Message Object 255 Status Register High
#define CAN_MOSTAT255H         (*((uword volatile far *) 0x202FFE))

// Message Object 255 Control Register Low
#define CAN_MOSTAT255L         (*((uword volatile far *) 0x202FFC))

// Message Object 25 Status Register High
#define CAN_MOSTAT25H          (*((uword volatile far *) 0x20133E))

// Message Object 25 Control Register Low
#define CAN_MOSTAT25L          (*((uword volatile far *) 0x20133C))

// Message Object 26 Status Register High
#define CAN_MOSTAT26H          (*((uword volatile far *) 0x20135E))

// Message Object 26 Control Register Low
#define CAN_MOSTAT26L          (*((uword volatile far *) 0x20135C))

// Message Object 27 Status Register High
#define CAN_MOSTAT27H          (*((uword volatile far *) 0x20137E))

// Message Object 27 Control Register Low
#define CAN_MOSTAT27L          (*((uword volatile far *) 0x20137C))

// Message Object 28 Status Register High
#define CAN_MOSTAT28H          (*((uword volatile far *) 0x20139E))

// Message Object 28 Control Register Low
#define CAN_MOSTAT28L          (*((uword volatile far *) 0x20139C))

// Message Object 29 Status Register High
#define CAN_MOSTAT29H          (*((uword volatile far *) 0x2013BE))

// Message Object 29 Control Register Low
#define CAN_MOSTAT29L          (*((uword volatile far *) 0x2013BC))

// Message Object 2 Status Register High
#define CAN_MOSTAT2H           (*((uword volatile far *) 0x20105E))

// Message Object 2 Control Register Low
#define CAN_MOSTAT2L           (*((uword volatile far *) 0x20105C))

// Message Object 30 Status Register High
#define CAN_MOSTAT30H          (*((uword volatile far *) 0x2013DE))

// Message Object 30 Control Register Low
#define CAN_MOSTAT30L          (*((uword volatile far *) 0x2013DC))

// Message Object 31 Status Register High
#define CAN_MOSTAT31H          (*((uword volatile far *) 0x2013FE))

// Message Object 31 Control Register Low
#define CAN_MOSTAT31L          (*((uword volatile far *) 0x2013FC))

// Message Object 32 Status Register High
#define CAN_MOSTAT32H          (*((uword volatile far *) 0x20141E))

// Message Object 32 Control Register Low
#define CAN_MOSTAT32L          (*((uword volatile far *) 0x20141C))

// Message Object 33 Status Register High
#define CAN_MOSTAT33H          (*((uword volatile far *) 0x20143E))

// Message Object 33 Control Register Low
#define CAN_MOSTAT33L          (*((uword volatile far *) 0x20143C))

// Message Object 34 Status Register High
#define CAN_MOSTAT34H          (*((uword volatile far *) 0x20145E))

// Message Object 34 Control Register Low
#define CAN_MOSTAT34L          (*((uword volatile far *) 0x20145C))

// Message Object 35 Status Register High
#define CAN_MOSTAT35H          (*((uword volatile far *) 0x20147E))

// Message Object 35 Control Register Low
#define CAN_MOSTAT35L          (*((uword volatile far *) 0x20147C))

// Message Object 36 Status Register High
#define CAN_MOSTAT36H          (*((uword volatile far *) 0x20149E))

// Message Object 36 Control Register Low
#define CAN_MOSTAT36L          (*((uword volatile far *) 0x20149C))

// Message Object 37 Status Register High
#define CAN_MOSTAT37H          (*((uword volatile far *) 0x2014BE))

// Message Object 37 Control Register Low
#define CAN_MOSTAT37L          (*((uword volatile far *) 0x2014BC))

// Message Object 38 Status Register High
#define CAN_MOSTAT38H          (*((uword volatile far *) 0x2014DE))

// Message Object 38 Control Register Low
#define CAN_MOSTAT38L          (*((uword volatile far *) 0x2014DC))

// Message Object 39 Status Register High
#define CAN_MOSTAT39H          (*((uword volatile far *) 0x2014FE))

// Message Object 39 Control Register Low
#define CAN_MOSTAT39L          (*((uword volatile far *) 0x2014FC))

// Message Object 3 Status Register High
#define CAN_MOSTAT3H           (*((uword volatile far *) 0x20107E))

// Message Object 3 Control Register Low
#define CAN_MOSTAT3L           (*((uword volatile far *) 0x20107C))

// Message Object 40 Status Register High
#define CAN_MOSTAT40H          (*((uword volatile far *) 0x20151E))

// Message Object 40 Control Register Low
#define CAN_MOSTAT40L          (*((uword volatile far *) 0x20151C))

// Message Object 41 Status Register High
#define CAN_MOSTAT41H          (*((uword volatile far *) 0x20153E))

// Message Object 41 Control Register Low
#define CAN_MOSTAT41L          (*((uword volatile far *) 0x20153C))

// Message Object 42 Status Register High
#define CAN_MOSTAT42H          (*((uword volatile far *) 0x20155E))

// Message Object 42 Control Register Low
#define CAN_MOSTAT42L          (*((uword volatile far *) 0x20155C))

// Message Object 43 Status Register High
#define CAN_MOSTAT43H          (*((uword volatile far *) 0x20157E))

// Message Object 43 Control Register Low
#define CAN_MOSTAT43L          (*((uword volatile far *) 0x20157C))

// Message Object 44 Status Register High
#define CAN_MOSTAT44H          (*((uword volatile far *) 0x20159E))

// Message Object 44 Control Register Low
#define CAN_MOSTAT44L          (*((uword volatile far *) 0x20159C))

// Message Object 45 Status Register High
#define CAN_MOSTAT45H          (*((uword volatile far *) 0x2015BE))

// Message Object 45 Control Register Low
#define CAN_MOSTAT45L          (*((uword volatile far *) 0x2015BC))

// Message Object 46 Status Register High
#define CAN_MOSTAT46H          (*((uword volatile far *) 0x2015DE))

// Message Object 46 Control Register Low
#define CAN_MOSTAT46L          (*((uword volatile far *) 0x2015DC))

// Message Object 47 Status Register High
#define CAN_MOSTAT47H          (*((uword volatile far *) 0x2015FE))

// Message Object 47 Control Register Low
#define CAN_MOSTAT47L          (*((uword volatile far *) 0x2015FC))

// Message Object 48 Status Register High
#define CAN_MOSTAT48H          (*((uword volatile far *) 0x20161E))

// Message Object 48 Control Register Low
#define CAN_MOSTAT48L          (*((uword volatile far *) 0x20161C))

// Message Object 49 Status Register High
#define CAN_MOSTAT49H          (*((uword volatile far *) 0x20163E))

// Message Object 49 Control Register Low
#define CAN_MOSTAT49L          (*((uword volatile far *) 0x20163C))

// Message Object 4 Status Register High
#define CAN_MOSTAT4H           (*((uword volatile far *) 0x20109E))

// Message Object 4 Control Register Low
#define CAN_MOSTAT4L           (*((uword volatile far *) 0x20109C))

// Message Object 50 Status Register High
#define CAN_MOSTAT50H          (*((uword volatile far *) 0x20165E))

// Message Object 50 Control Register Low
#define CAN_MOSTAT50L          (*((uword volatile far *) 0x20165C))

// Message Object 51 Status Register High
#define CAN_MOSTAT51H          (*((uword volatile far *) 0x20167E))

// Message Object 51 Control Register Low
#define CAN_MOSTAT51L          (*((uword volatile far *) 0x20167C))

// Message Object 52 Status Register High
#define CAN_MOSTAT52H          (*((uword volatile far *) 0x20169E))

// Message Object 52 Control Register Low
#define CAN_MOSTAT52L          (*((uword volatile far *) 0x20169C))

// Message Object 53 Status Register High
#define CAN_MOSTAT53H          (*((uword volatile far *) 0x2016BE))

// Message Object 53 Control Register Low
#define CAN_MOSTAT53L          (*((uword volatile far *) 0x2016BC))

// Message Object 54 Status Register High
#define CAN_MOSTAT54H          (*((uword volatile far *) 0x2016DE))

// Message Object 54 Control Register Low
#define CAN_MOSTAT54L          (*((uword volatile far *) 0x2016DC))

// Message Object 55 Status Register High
#define CAN_MOSTAT55H          (*((uword volatile far *) 0x2016FE))

// Message Object 55 Control Register Low
#define CAN_MOSTAT55L          (*((uword volatile far *) 0x2016FC))

// Message Object 56 Status Register High
#define CAN_MOSTAT56H          (*((uword volatile far *) 0x20171E))

// Message Object 56 Control Register Low
#define CAN_MOSTAT56L          (*((uword volatile far *) 0x20171C))

// Message Object 57 Status Register High
#define CAN_MOSTAT57H          (*((uword volatile far *) 0x20173E))

// Message Object 57 Control Register Low
#define CAN_MOSTAT57L          (*((uword volatile far *) 0x20173C))

// Message Object 58 Status Register High
#define CAN_MOSTAT58H          (*((uword volatile far *) 0x20175E))

// Message Object 58 Control Register Low
#define CAN_MOSTAT58L          (*((uword volatile far *) 0x20175C))

// Message Object 59 Status Register High
#define CAN_MOSTAT59H          (*((uword volatile far *) 0x20177E))

// Message Object 59 Control Register Low
#define CAN_MOSTAT59L          (*((uword volatile far *) 0x20177C))

// Message Object 5 Status Register High
#define CAN_MOSTAT5H           (*((uword volatile far *) 0x2010BE))

// Message Object 5 Control Register Low
#define CAN_MOSTAT5L           (*((uword volatile far *) 0x2010BC))

// Message Object 60 Status Register High
#define CAN_MOSTAT60H          (*((uword volatile far *) 0x20179E))

// Message Object 60 Control Register Low
#define CAN_MOSTAT60L          (*((uword volatile far *) 0x20179C))

// Message Object 61 Status Register High
#define CAN_MOSTAT61H          (*((uword volatile far *) 0x2017BE))

// Message Object 61 Control Register Low
#define CAN_MOSTAT61L          (*((uword volatile far *) 0x2017BC))

// Message Object 62 Status Register High
#define CAN_MOSTAT62H          (*((uword volatile far *) 0x2017DE))

// Message Object 62 Control Register Low
#define CAN_MOSTAT62L          (*((uword volatile far *) 0x2017DC))

// Message Object 63 Status Register High
#define CAN_MOSTAT63H          (*((uword volatile far *) 0x2017FE))

// Message Object 63 Control Register Low
#define CAN_MOSTAT63L          (*((uword volatile far *) 0x2017FC))

// Message Object 64 Status Register High
#define CAN_MOSTAT64H          (*((uword volatile far *) 0x20181E))

// Message Object 64 Control Register Low
#define CAN_MOSTAT64L          (*((uword volatile far *) 0x20181C))

// Message Object 65 Status Register High
#define CAN_MOSTAT65H          (*((uword volatile far *) 0x20183E))

// Message Object 65 Control Register Low
#define CAN_MOSTAT65L          (*((uword volatile far *) 0x20183C))

// Message Object 66 Status Register High
#define CAN_MOSTAT66H          (*((uword volatile far *) 0x20185E))

// Message Object 66 Control Register Low
#define CAN_MOSTAT66L          (*((uword volatile far *) 0x20185C))

// Message Object 67 Status Register High
#define CAN_MOSTAT67H          (*((uword volatile far *) 0x20187E))

// Message Object 67 Control Register Low
#define CAN_MOSTAT67L          (*((uword volatile far *) 0x20187C))

// Message Object 68 Status Register High
#define CAN_MOSTAT68H          (*((uword volatile far *) 0x20189E))

// Message Object 68 Control Register Low
#define CAN_MOSTAT68L          (*((uword volatile far *) 0x20189C))

// Message Object 69 Status Register High
#define CAN_MOSTAT69H          (*((uword volatile far *) 0x2018BE))

// Message Object 69 Control Register Low
#define CAN_MOSTAT69L          (*((uword volatile far *) 0x2018BC))

// Message Object 6 Status Register High
#define CAN_MOSTAT6H           (*((uword volatile far *) 0x2010DE))

// Message Object 6 Control Register Low
#define CAN_MOSTAT6L           (*((uword volatile far *) 0x2010DC))

// Message Object 70 Status Register High
#define CAN_MOSTAT70H          (*((uword volatile far *) 0x2018DE))

// Message Object 70 Control Register Low
#define CAN_MOSTAT70L          (*((uword volatile far *) 0x2018DC))

// Message Object 71 Status Register High
#define CAN_MOSTAT71H          (*((uword volatile far *) 0x2018FE))

// Message Object 71 Control Register Low
#define CAN_MOSTAT71L          (*((uword volatile far *) 0x2018FC))

// Message Object 72 Status Register High
#define CAN_MOSTAT72H          (*((uword volatile far *) 0x20191E))

// Message Object 72 Control Register Low
#define CAN_MOSTAT72L          (*((uword volatile far *) 0x20191C))

// Message Object 73 Status Register High
#define CAN_MOSTAT73H          (*((uword volatile far *) 0x20193E))

// Message Object 73 Control Register Low
#define CAN_MOSTAT73L          (*((uword volatile far *) 0x20193C))

// Message Object 74 Status Register High
#define CAN_MOSTAT74H          (*((uword volatile far *) 0x20195E))

// Message Object 74 Control Register Low
#define CAN_MOSTAT74L          (*((uword volatile far *) 0x20195C))

// Message Object 75 Status Register High
#define CAN_MOSTAT75H          (*((uword volatile far *) 0x20197E))

// Message Object 75 Control Register Low
#define CAN_MOSTAT75L          (*((uword volatile far *) 0x20197C))

// Message Object 76 Status Register High
#define CAN_MOSTAT76H          (*((uword volatile far *) 0x20199E))

// Message Object 76 Control Register Low
#define CAN_MOSTAT76L          (*((uword volatile far *) 0x20199C))

// Message Object 77 Status Register High
#define CAN_MOSTAT77H          (*((uword volatile far *) 0x2019BE))

// Message Object 77 Control Register Low
#define CAN_MOSTAT77L          (*((uword volatile far *) 0x2019BC))

// Message Object 78 Status Register High
#define CAN_MOSTAT78H          (*((uword volatile far *) 0x2019DE))

// Message Object 78 Control Register Low
#define CAN_MOSTAT78L          (*((uword volatile far *) 0x2019DC))

// Message Object 79 Status Register High
#define CAN_MOSTAT79H          (*((uword volatile far *) 0x2019FE))

// Message Object 79 Control Register Low
#define CAN_MOSTAT79L          (*((uword volatile far *) 0x2019FC))

// Message Object 7 Status Register High
#define CAN_MOSTAT7H           (*((uword volatile far *) 0x2010FE))

// Message Object 7 Control Register Low
#define CAN_MOSTAT7L           (*((uword volatile far *) 0x2010FC))

// Message Object 80 Status Register High
#define CAN_MOSTAT80H          (*((uword volatile far *) 0x201A1E))

// Message Object 80 Control Register Low
#define CAN_MOSTAT80L          (*((uword volatile far *) 0x201A1C))

// Message Object 81 Status Register High
#define CAN_MOSTAT81H          (*((uword volatile far *) 0x201A3E))

// Message Object 81 Control Register Low
#define CAN_MOSTAT81L          (*((uword volatile far *) 0x201A3C))

// Message Object 82 Status Register High
#define CAN_MOSTAT82H          (*((uword volatile far *) 0x201A5E))

// Message Object 82 Control Register Low
#define CAN_MOSTAT82L          (*((uword volatile far *) 0x201A5C))

// Message Object 83 Status Register High
#define CAN_MOSTAT83H          (*((uword volatile far *) 0x201A7E))

// Message Object 83 Control Register Low
#define CAN_MOSTAT83L          (*((uword volatile far *) 0x201A7C))

// Message Object 84 Status Register High
#define CAN_MOSTAT84H          (*((uword volatile far *) 0x201A9E))

// Message Object 84 Control Register Low
#define CAN_MOSTAT84L          (*((uword volatile far *) 0x201A9C))

// Message Object 85 Status Register High
#define CAN_MOSTAT85H          (*((uword volatile far *) 0x201ABE))

// Message Object 85 Control Register Low
#define CAN_MOSTAT85L          (*((uword volatile far *) 0x201ABC))

// Message Object 86 Status Register High
#define CAN_MOSTAT86H          (*((uword volatile far *) 0x201ADE))

// Message Object 86 Control Register Low
#define CAN_MOSTAT86L          (*((uword volatile far *) 0x201ADC))

// Message Object 87 Status Register High
#define CAN_MOSTAT87H          (*((uword volatile far *) 0x201AFE))

// Message Object 87 Control Register Low
#define CAN_MOSTAT87L          (*((uword volatile far *) 0x201AFC))

// Message Object 88 Status Register High
#define CAN_MOSTAT88H          (*((uword volatile far *) 0x201B1E))

// Message Object 88 Control Register Low
#define CAN_MOSTAT88L          (*((uword volatile far *) 0x201B1C))

// Message Object 89 Status Register High
#define CAN_MOSTAT89H          (*((uword volatile far *) 0x201B3E))

// Message Object 89 Control Register Low
#define CAN_MOSTAT89L          (*((uword volatile far *) 0x201B3C))

// Message Object 8 Status Register High
#define CAN_MOSTAT8H           (*((uword volatile far *) 0x20111E))

// Message Object 8 Control Register Low
#define CAN_MOSTAT8L           (*((uword volatile far *) 0x20111C))

// Message Object 90 Status Register High
#define CAN_MOSTAT90H          (*((uword volatile far *) 0x201B5E))

// Message Object 90 Control Register Low
#define CAN_MOSTAT90L          (*((uword volatile far *) 0x201B5C))

// Message Object 91 Status Register High
#define CAN_MOSTAT91H          (*((uword volatile far *) 0x201B7E))

// Message Object 91 Control Register Low
#define CAN_MOSTAT91L          (*((uword volatile far *) 0x201B7C))

// Message Object 92 Status Register High
#define CAN_MOSTAT92H          (*((uword volatile far *) 0x201B9E))

// Message Object 92 Control Register Low
#define CAN_MOSTAT92L          (*((uword volatile far *) 0x201B9C))

// Message Object 93 Status Register High
#define CAN_MOSTAT93H          (*((uword volatile far *) 0x201BBE))

// Message Object 93 Control Register Low
#define CAN_MOSTAT93L          (*((uword volatile far *) 0x201BBC))

// Message Object 94 Status Register High
#define CAN_MOSTAT94H          (*((uword volatile far *) 0x201BDE))

// Message Object 94 Control Register Low
#define CAN_MOSTAT94L          (*((uword volatile far *) 0x201BDC))

// Message Object 95 Status Register High
#define CAN_MOSTAT95H          (*((uword volatile far *) 0x201BFE))

// Message Object 95 Control Register Low
#define CAN_MOSTAT95L          (*((uword volatile far *) 0x201BFC))

// Message Object 96 Status Register High
#define CAN_MOSTAT96H          (*((uword volatile far *) 0x201C1E))

// Message Object 96 Control Register Low
#define CAN_MOSTAT96L          (*((uword volatile far *) 0x201C1C))

// Message Object 97 Status Register High
#define CAN_MOSTAT97H          (*((uword volatile far *) 0x201C3E))

// Message Object 97 Control Register Low
#define CAN_MOSTAT97L          (*((uword volatile far *) 0x201C3C))

// Message Object 98 Status Register High
#define CAN_MOSTAT98H          (*((uword volatile far *) 0x201C5E))

// Message Object 98 Control Register Low
#define CAN_MOSTAT98L          (*((uword volatile far *) 0x201C5C))

// Message Object 99 Status Register High
#define CAN_MOSTAT99H          (*((uword volatile far *) 0x201C7E))

// Message Object 99 Control Register Low
#define CAN_MOSTAT99L          (*((uword volatile far *) 0x201C7C))

// Message Object 9 Status Register High
#define CAN_MOSTAT9H           (*((uword volatile far *) 0x20113E))

// Message Object 9 Control Register Low
#define CAN_MOSTAT9L           (*((uword volatile far *) 0x20113C))

// Message Index Register 0
#define CAN_MSID0              (*((uword volatile far *) 0x200180))

// Message Index Register 1
#define CAN_MSID1              (*((uword volatile far *) 0x200184))

// Message Index Register 2
#define CAN_MSID2              (*((uword volatile far *) 0x200188))

// Message Index Register 3
#define CAN_MSID3              (*((uword volatile far *) 0x20018C))

// Message Index Register 4
#define CAN_MSID4              (*((uword volatile far *) 0x200190))

// Message Index Register 5
#define CAN_MSID5              (*((uword volatile far *) 0x200194))

// Message Index Register 6
#define CAN_MSID6              (*((uword volatile far *) 0x200198))

// Message Index Register 7
#define CAN_MSID7              (*((uword volatile far *) 0x20019C))

// Message Index Mask Register High
#define CAN_MSIMASKH           (*((uword volatile far *) 0x2001C2))

// Message Index Mask Register Low
#define CAN_MSIMASKL           (*((uword volatile far *) 0x2001C0))

// Message Pending Register 0 High
#define CAN_MSPND0H            (*((uword volatile far *) 0x200142))

// Message Pending Register 0 Low
#define CAN_MSPND0L            (*((uword volatile far *) 0x200140))

// Message Pending Register 1 High
#define CAN_MSPND1H            (*((uword volatile far *) 0x200146))

// Message Pending Register 1 Low
#define CAN_MSPND1L            (*((uword volatile far *) 0x200144))

// Message Pending Register 2 High
#define CAN_MSPND2H            (*((uword volatile far *) 0x20014A))

// Message Pending Register 2 Low
#define CAN_MSPND2L            (*((uword volatile far *) 0x200148))

// Message Pending Register 3 High
#define CAN_MSPND3H            (*((uword volatile far *) 0x20014E))

// Message Pending Register 3 Low
#define CAN_MSPND3L            (*((uword volatile far *) 0x20014C))

// Message Pending Register 4 High
#define CAN_MSPND4H            (*((uword volatile far *) 0x200152))

// Message Pending Register 4 Low
#define CAN_MSPND4L            (*((uword volatile far *) 0x200150))

// Message Pending Register 5 High
#define CAN_MSPND5H            (*((uword volatile far *) 0x200156))

// Message Pending Register 5 Low
#define CAN_MSPND5L            (*((uword volatile far *) 0x200154))

// Message Pending Register 6 High
#define CAN_MSPND6H            (*((uword volatile far *) 0x20015A))

// Message Pending Register 6 Low
#define CAN_MSPND6L            (*((uword volatile far *) 0x200158))

// Message Pending Register 7 High
#define CAN_MSPND7H            (*((uword volatile far *) 0x20015E))

// Message Pending Register 7 Low
#define CAN_MSPND7L            (*((uword volatile far *) 0x20015C))

// Node 0 Bit Timing Register High
#define CAN_NBTR0H             (*((uword volatile far *) 0x200212))

// Node 0 Bit Timing Register Low
#define CAN_NBTR0L             (*((uword volatile far *) 0x200210))

// Node 1 Bit Timing Register High
#define CAN_NBTR1H             (*((uword volatile far *) 0x200312))

// Node 1 Bit Timing Register Low
#define CAN_NBTR1L             (*((uword volatile far *) 0x200310))

// Node 2 Bit Timing Register High
#define CAN_NBTR2H             (*((uword volatile far *) 0x200412))

// Node 2 Bit Timing Register Low
#define CAN_NBTR2L             (*((uword volatile far *) 0x200410))

// Node 3 Bit Timing Register High
#define CAN_NBTR3H             (*((uword volatile far *) 0x200512))

// Node 3 Bit Timing Register Low
#define CAN_NBTR3L             (*((uword volatile far *) 0x200510))

// Node 4 Bit Timing Register High
#define CAN_NBTR4H             (*((uword volatile far *) 0x200612))

// Node 4 Bit Timing Register Low
#define CAN_NBTR4L             (*((uword volatile far *) 0x200610))

// Node 5 Bit Timing Register High
#define CAN_NBTR5H             (*((uword volatile far *) 0x200712))

// Node 5 Bit Timing Register Low
#define CAN_NBTR5L             (*((uword volatile far *) 0x200710))

// Node 0 Control Register
#define CAN_NCR0               (*((uword volatile far *) 0x200200))

// Node 1 Control Register
#define CAN_NCR1               (*((uword volatile far *) 0x200300))

// Node 2 Control Register
#define CAN_NCR2               (*((uword volatile far *) 0x200400))

// Node 3 Control Register
#define CAN_NCR3               (*((uword volatile far *) 0x200500))

// Node 4 Control Register
#define CAN_NCR4               (*((uword volatile far *) 0x200600))

// Node 5 Control Register
#define CAN_NCR5               (*((uword volatile far *) 0x200700))

// Node 0 Error Counter Register High
#define CAN_NECNT0H            (*((uword volatile far *) 0x200216))

// Node 0 Error Counter Register Low
#define CAN_NECNT0L            (*((uword volatile far *) 0x200214))

// Node 1 Error Counter Register High
#define CAN_NECNT1H            (*((uword volatile far *) 0x200316))

// Node 1 Error Counter Register Low
#define CAN_NECNT1L            (*((uword volatile far *) 0x200314))

// Node 2 Error Counter Register High
#define CAN_NECNT2H            (*((uword volatile far *) 0x200416))

// Node 2 Error Counter Register Low
#define CAN_NECNT2L            (*((uword volatile far *) 0x200414))

// Node 3 Error Counter Register High
#define CAN_NECNT3H            (*((uword volatile far *) 0x200516))

// Node 3 Error Counter Register Low
#define CAN_NECNT3L            (*((uword volatile far *) 0x200514))

// Node 4 Error Counter Register High
#define CAN_NECNT4H            (*((uword volatile far *) 0x200616))

// Node 4 Error Counter Register Low
#define CAN_NECNT4L            (*((uword volatile far *) 0x200614))

// Node 5 Error Counter Register High
#define CAN_NECNT5H            (*((uword volatile far *) 0x200716))

// Node 5 Error Counter Register Low
#define CAN_NECNT5L            (*((uword volatile far *) 0x200714))

// Node 0 Frame Counter Register High
#define CAN_NFCR0H             (*((uword volatile far *) 0x20021A))

// Node 0 Frame Counter Register Low
#define CAN_NFCR0L             (*((uword volatile far *) 0x200218))

// Node 1 Frame Counter Register High
#define CAN_NFCR1H             (*((uword volatile far *) 0x20031A))

// Node 1 Frame Counter Register Low
#define CAN_NFCR1L             (*((uword volatile far *) 0x200318))

// Node 2 Frame Counter Register High
#define CAN_NFCR2H             (*((uword volatile far *) 0x20041A))

// Node 2 Frame Counter Register Low
#define CAN_NFCR2L             (*((uword volatile far *) 0x200418))

// Node 3 Frame Counter Register High
#define CAN_NFCR3H             (*((uword volatile far *) 0x20051A))

// Node 3 Frame Counter Register Low
#define CAN_NFCR3L             (*((uword volatile far *) 0x200518))

// Node 4 Frame Counter Register High
#define CAN_NFCR4H             (*((uword volatile far *) 0x20061A))

// Node 4 Frame Counter Register Low
#define CAN_NFCR4L             (*((uword volatile far *) 0x200618))

// Node 5 Frame Counter Register High
#define CAN_NFCR5H             (*((uword volatile far *) 0x20071A))

// Node 5 Frame Counter Register Low
#define CAN_NFCR5L             (*((uword volatile far *) 0x200718))

// Node 0 Interrupt Pointer Register
#define CAN_NIPR0              (*((uword volatile far *) 0x200208))

// Node 1 Interrupt Pointer Register
#define CAN_NIPR1              (*((uword volatile far *) 0x200308))

// Node 2 Interrupt Pointer Register
#define CAN_NIPR2              (*((uword volatile far *) 0x200408))

// Node 3 Interrupt Pointer Register
#define CAN_NIPR3              (*((uword volatile far *) 0x200508))

// Node 4 Interrupt Pointer Register
#define CAN_NIPR4              (*((uword volatile far *) 0x200608))

// Node 5 Interrupt Pointer Register
#define CAN_NIPR5              (*((uword volatile far *) 0x200708))

// Node 0 Port Control Register
#define CAN_NPCR0              (*((uword volatile far *) 0x20020C))

// Node 1 Port Control Register
#define CAN_NPCR1              (*((uword volatile far *) 0x20030C))

// Node 2 Port Control Register
#define CAN_NPCR2              (*((uword volatile far *) 0x20040C))

// Node 3 Port Control Register
#define CAN_NPCR3              (*((uword volatile far *) 0x20050C))

// Node 4 Port Control Register
#define CAN_NPCR4              (*((uword volatile far *) 0x20060C))

// Node 5 Port Control Register
#define CAN_NPCR5              (*((uword volatile far *) 0x20070C))

// Node 0 Status Register
#define CAN_NSR0               (*((uword volatile far *) 0x200204))

// Node 1 Status Register
#define CAN_NSR1               (*((uword volatile far *) 0x200304))

// Node 2 Status Register
#define CAN_NSR2               (*((uword volatile far *) 0x200404))

// Node 3 Status Register
#define CAN_NSR3               (*((uword volatile far *) 0x200504))

// Node 4 Status Register
#define CAN_NSR4               (*((uword volatile far *) 0x200604))

// Node 5 Status Register
#define CAN_NSR5               (*((uword volatile far *) 0x200704))

// Panel Control Register
#define CAN_PANCTRH            (*((uword volatile far *) 0x2001C6))

// Panel Control Register
#define CAN_PANCTRL            (*((uword volatile far *) 0x2001C4))

// CAPCOM2 Capture/Compare Register 16
#define CC2_CC16               (*((uword volatile *) 0xFE60))

// CAPCOM Interrupt Control Reg. 16
#define CC2_CC16IC             (*((uword volatile *) 0xF1C0))
#define CC2_CC16IC_GPX                      ((T_Reg16 *) 0xF1C0)->bit8
#define CC2_CC16IC_IE                       ((T_Reg16 *) 0xF1C0)->bit6
#define CC2_CC16IC_IR                       ((T_Reg16 *) 0xF1C0)->bit7

// CAPCOM2 Capture/Compare Register 17
#define CC2_CC17               (*((uword volatile *) 0xFE62))

// CAPCOM Interrupt Control Reg. 17
#define CC2_CC17IC             (*((uword volatile *) 0xF1C2))
#define CC2_CC17IC_GPX                      ((T_Reg16 *) 0xF1C2)->bit8
#define CC2_CC17IC_IE                       ((T_Reg16 *) 0xF1C2)->bit6
#define CC2_CC17IC_IR                       ((T_Reg16 *) 0xF1C2)->bit7

// CAPCOM2 Capture/Compare Register 18
#define CC2_CC18               (*((uword volatile *) 0xFE64))

// CAPCOM Interrupt Control Reg. 18
#define CC2_CC18IC             (*((uword volatile *) 0xF1C4))
#define CC2_CC18IC_GPX                      ((T_Reg16 *) 0xF1C4)->bit8
#define CC2_CC18IC_IE                       ((T_Reg16 *) 0xF1C4)->bit6
#define CC2_CC18IC_IR                       ((T_Reg16 *) 0xF1C4)->bit7

// CAPCOM2 Capture/Compare Register 19
#define CC2_CC19               (*((uword volatile *) 0xFE66))

// CAPCOM Interrupt Control Reg. 19
#define CC2_CC19IC             (*((uword volatile *) 0xF1C6))
#define CC2_CC19IC_GPX                      ((T_Reg16 *) 0xF1C6)->bit8
#define CC2_CC19IC_IE                       ((T_Reg16 *) 0xF1C6)->bit6
#define CC2_CC19IC_IR                       ((T_Reg16 *) 0xF1C6)->bit7

// CAPCOM2 Capture/Compare Register 20
#define CC2_CC20               (*((uword volatile *) 0xFE68))

// CAPCOM Interrupt Control Reg. 20
#define CC2_CC20IC             (*((uword volatile *) 0xF1C8))
#define CC2_CC20IC_GPX                      ((T_Reg16 *) 0xF1C8)->bit8
#define CC2_CC20IC_IE                       ((T_Reg16 *) 0xF1C8)->bit6
#define CC2_CC20IC_IR                       ((T_Reg16 *) 0xF1C8)->bit7

// CAPCOM2 Capture/Compare Register 21
#define CC2_CC21               (*((uword volatile *) 0xFE6A))

// CAPCOM Interrupt Control Reg. 21
#define CC2_CC21IC             (*((uword volatile *) 0xF1CA))
#define CC2_CC21IC_GPX                      ((T_Reg16 *) 0xF1CA)->bit8
#define CC2_CC21IC_IE                       ((T_Reg16 *) 0xF1CA)->bit6
#define CC2_CC21IC_IR                       ((T_Reg16 *) 0xF1CA)->bit7

// CAPCOM2 Capture/Compare Register 22
#define CC2_CC22               (*((uword volatile *) 0xFE6C))

// CAPCOM Interrupt Control Reg. 22
#define CC2_CC22IC             (*((uword volatile *) 0xF1CC))
#define CC2_CC22IC_GPX                      ((T_Reg16 *) 0xF1CC)->bit8
#define CC2_CC22IC_IE                       ((T_Reg16 *) 0xF1CC)->bit6
#define CC2_CC22IC_IR                       ((T_Reg16 *) 0xF1CC)->bit7

// CAPCOM2 Capture/Compare Register 23
#define CC2_CC23               (*((uword volatile *) 0xFE6E))

// CAPCOM Interrupt Control Reg. 23
#define CC2_CC23IC             (*((uword volatile *) 0xF1CE))
#define CC2_CC23IC_GPX                      ((T_Reg16 *) 0xF1CE)->bit8
#define CC2_CC23IC_IE                       ((T_Reg16 *) 0xF1CE)->bit6
#define CC2_CC23IC_IR                       ((T_Reg16 *) 0xF1CE)->bit7

// CAPCOM2 Capture/Compare Register 24
#define CC2_CC24               (*((uword volatile *) 0xFE70))

// CAPCOM Interrupt Control Reg. 24
#define CC2_CC24IC             (*((uword volatile *) 0xF1D0))
#define CC2_CC24IC_GPX                      ((T_Reg16 *) 0xF1D0)->bit8
#define CC2_CC24IC_IE                       ((T_Reg16 *) 0xF1D0)->bit6
#define CC2_CC24IC_IR                       ((T_Reg16 *) 0xF1D0)->bit7

// CAPCOM2 Capture/Compare Register 25
#define CC2_CC25               (*((uword volatile *) 0xFE72))

// CAPCOM Interrupt Control Reg. 25
#define CC2_CC25IC             (*((uword volatile *) 0xF1D2))
#define CC2_CC25IC_GPX                      ((T_Reg16 *) 0xF1D2)->bit8
#define CC2_CC25IC_IE                       ((T_Reg16 *) 0xF1D2)->bit6
#define CC2_CC25IC_IR                       ((T_Reg16 *) 0xF1D2)->bit7

// CAPCOM2 Capture/Compare Register 26
#define CC2_CC26               (*((uword volatile *) 0xFE74))

// CAPCOM Interrupt Control Reg. 26
#define CC2_CC26IC             (*((uword volatile *) 0xF1D4))
#define CC2_CC26IC_GPX                      ((T_Reg16 *) 0xF1D4)->bit8
#define CC2_CC26IC_IE                       ((T_Reg16 *) 0xF1D4)->bit6
#define CC2_CC26IC_IR                       ((T_Reg16 *) 0xF1D4)->bit7

// CAPCOM2 Capture/Compare Register 27
#define CC2_CC27               (*((uword volatile *) 0xFE76))

// CAPCOM Interrupt Control Reg. 27
#define CC2_CC27IC             (*((uword volatile *) 0xF1D6))
#define CC2_CC27IC_GPX                      ((T_Reg16 *) 0xF1D6)->bit8
#define CC2_CC27IC_IE                       ((T_Reg16 *) 0xF1D6)->bit6
#define CC2_CC27IC_IR                       ((T_Reg16 *) 0xF1D6)->bit7

// CAPCOM2 Capture/Compare Register 28
#define CC2_CC28               (*((uword volatile *) 0xFE78))

// CAPCOM Interrupt Control Reg. 28
#define CC2_CC28IC             (*((uword volatile *) 0xF1D8))
#define CC2_CC28IC_GPX                      ((T_Reg16 *) 0xF1D8)->bit8
#define CC2_CC28IC_IE                       ((T_Reg16 *) 0xF1D8)->bit6
#define CC2_CC28IC_IR                       ((T_Reg16 *) 0xF1D8)->bit7

// CAPCOM2 Capture/Compare Register 29
#define CC2_CC29               (*((uword volatile *) 0xFE7A))

// CAPCOM Interrupt Control Reg. 29
#define CC2_CC29IC             (*((uword volatile *) 0xF1DA))
#define CC2_CC29IC_GPX                      ((T_Reg16 *) 0xF1DA)->bit8
#define CC2_CC29IC_IE                       ((T_Reg16 *) 0xF1DA)->bit6
#define CC2_CC29IC_IR                       ((T_Reg16 *) 0xF1DA)->bit7

// CAPCOM2 Capture/Compare Register 30
#define CC2_CC30               (*((uword volatile *) 0xFE7C))

// CAPCOM Interrupt Control Reg. 30
#define CC2_CC30IC             (*((uword volatile *) 0xF1DC))
#define CC2_CC30IC_GPX                      ((T_Reg16 *) 0xF1DC)->bit8
#define CC2_CC30IC_IE                       ((T_Reg16 *) 0xF1DC)->bit6
#define CC2_CC30IC_IR                       ((T_Reg16 *) 0xF1DC)->bit7

// CAPCOM2 Capture/Compare Register 31
#define CC2_CC31               (*((uword volatile *) 0xFE7E))

// CAPCOM Interrupt Control Reg. 31
#define CC2_CC31IC             (*((uword volatile *) 0xF1DE))
#define CC2_CC31IC_GPX                      ((T_Reg16 *) 0xF1DE)->bit8
#define CC2_CC31IC_IE                       ((T_Reg16 *) 0xF1DE)->bit6
#define CC2_CC31IC_IR                       ((T_Reg16 *) 0xF1DE)->bit7

// CAPCOM2 Double-Register Compare Mode Register
#define CC2_DRM                (*((uword volatile *) 0xFF2A))

// CAPCOM2 Identification Register
#define CC2_ID                 (*((uword volatile *) 0xFFEE))

// CAPCOM2 CAPCOM2 I/O Control Register
#define CC2_IOC                (*((uword volatile *) 0xF066))

// CC2 Kernel State Con. Register
#define CC2_KSCCFG             (*((uword volatile *) 0xFE24))

// CAPCOM2 Capture/Compare Mode Registers for the CAPCOM2 Unit [CC16...CC19]
#define CC2_M4                 (*((uword volatile *) 0xFF22))
#define CC2_M4_ACC16                    ((T_Reg16 *) 0xFF22)->bit3
#define CC2_M4_ACC17                    ((T_Reg16 *) 0xFF22)->bit7
#define CC2_M4_ACC18                    ((T_Reg16 *) 0xFF22)->bit11
#define CC2_M4_ACC19                    ((T_Reg16 *) 0xFF22)->bit15

// CAPCOM2 Capture/Compare Mode Registers for the CAPCOM2 Unit [CC20...CC23]
#define CC2_M5                 (*((uword volatile *) 0xFF24))
#define CC2_M5_ACC20                    ((T_Reg16 *) 0xFF24)->bit3
#define CC2_M5_ACC21                    ((T_Reg16 *) 0xFF24)->bit7
#define CC2_M5_ACC22                    ((T_Reg16 *) 0xFF24)->bit11
#define CC2_M5_ACC23                    ((T_Reg16 *) 0xFF24)->bit15

// CAPCOM2 Capture/Compare Mode Registers for the CAPCOM2 Unit [CC24...CC27]
#define CC2_M6                 (*((uword volatile *) 0xFF26))
#define CC2_M6_ACC24                    ((T_Reg16 *) 0xFF26)->bit3
#define CC2_M6_ACC25                    ((T_Reg16 *) 0xFF26)->bit7
#define CC2_M6_ACC26                    ((T_Reg16 *) 0xFF26)->bit11
#define CC2_M6_ACC27                    ((T_Reg16 *) 0xFF26)->bit15

// CAPCOM2 Capture/Compare Mode Registers for the CAPCOM2 Unit [CC28...CC31]
#define CC2_M7                 (*((uword volatile *) 0xFF28))
#define CC2_M7_ACC28                    ((T_Reg16 *) 0xFF28)->bit3
#define CC2_M7_ACC29                    ((T_Reg16 *) 0xFF28)->bit7
#define CC2_M7_ACC30                    ((T_Reg16 *) 0xFF28)->bit11
#define CC2_M7_ACC31                    ((T_Reg16 *) 0xFF28)->bit15

// CAPCOM2 Compare Output Register
#define CC2_OUT                (*((uword volatile *) 0xFF2C))
#define CC2_OUT_CC0IO                    ((T_Reg16 *) 0xFF2C)->bit0
#define CC2_OUT_CC10IO                   ((T_Reg16 *) 0xFF2C)->bit10
#define CC2_OUT_CC11IO                   ((T_Reg16 *) 0xFF2C)->bit11
#define CC2_OUT_CC12IO                   ((T_Reg16 *) 0xFF2C)->bit12
#define CC2_OUT_CC13IO                   ((T_Reg16 *) 0xFF2C)->bit13
#define CC2_OUT_CC14IO                   ((T_Reg16 *) 0xFF2C)->bit14
#define CC2_OUT_CC15IO                   ((T_Reg16 *) 0xFF2C)->bit15
#define CC2_OUT_CC1IO                    ((T_Reg16 *) 0xFF2C)->bit1
#define CC2_OUT_CC2IO                    ((T_Reg16 *) 0xFF2C)->bit2
#define CC2_OUT_CC3IO                    ((T_Reg16 *) 0xFF2C)->bit3
#define CC2_OUT_CC4IO                    ((T_Reg16 *) 0xFF2C)->bit4
#define CC2_OUT_CC5IO                    ((T_Reg16 *) 0xFF2C)->bit5
#define CC2_OUT_CC6IO                    ((T_Reg16 *) 0xFF2C)->bit6
#define CC2_OUT_CC7IO                    ((T_Reg16 *) 0xFF2C)->bit7
#define CC2_OUT_CC8IO                    ((T_Reg16 *) 0xFF2C)->bit8
#define CC2_OUT_CC9IO                    ((T_Reg16 *) 0xFF2C)->bit9

// CAPCOM2 Single Event Enable Register
#define CC2_SEE                (*((uword volatile *) 0xFE2A))

// CAPCOM2 Single Event Mode Register
#define CC2_SEM                (*((uword volatile *) 0xFE28))

// CAPCOM2 Timer 7 Register
#define CC2_T7                 (*((uword volatile *) 0xF050))

// CAPCOM2 Timer 7/8 Control Register
#define CC2_T78CON             (*((uword volatile *) 0xFF20))
#define CC2_T78CON_T7M                      ((T_Reg16 *) 0xFF20)->bit3
#define CC2_T78CON_T7R                      ((T_Reg16 *) 0xFF20)->bit6
#define CC2_T78CON_T8M                      ((T_Reg16 *) 0xFF20)->bit11
#define CC2_T78CON_T8R                      ((T_Reg16 *) 0xFF20)->bit14

// CAPCOM TIMER 7 IC
#define CC2_T7IC               (*((uword volatile *) 0xFF6C))
#define CC2_T7IC_GPX                      ((T_Reg16 *) 0xFF6C)->bit8
#define CC2_T7IC_IE                       ((T_Reg16 *) 0xFF6C)->bit6
#define CC2_T7IC_IR                       ((T_Reg16 *) 0xFF6C)->bit7

// CAPCOM2 Timer 7 Reload Register
#define CC2_T7REL              (*((uword volatile *) 0xF054))

// CAPCOM2 Timer 8 Register
#define CC2_T8                 (*((uword volatile *) 0xF052))

// CAPCOM TIMER 8 IC
#define CC2_T8IC               (*((uword volatile *) 0xFF6E))
#define CC2_T8IC_GPX                      ((T_Reg16 *) 0xFF6E)->bit8
#define CC2_T8IC_IE                       ((T_Reg16 *) 0xFF6E)->bit6
#define CC2_T8IC_IR                       ((T_Reg16 *) 0xFF6E)->bit7

// CAPCOM2 Timer 8 Reload Register
#define CC2_T8REL              (*((uword volatile *) 0xF056))

// CCU60 Interrupt Control Reg. 0
#define CCU60_0IC              (*((uword volatile *) 0xF160))
#define CCU60_0IC_GPX                      ((T_Reg16 *) 0xF160)->bit8
#define CCU60_0IC_IE                       ((T_Reg16 *) 0xF160)->bit6
#define CCU60_0IC_IR                       ((T_Reg16 *) 0xF160)->bit7

// CCU60 Interrupt Control Reg. 1
#define CCU60_1IC              (*((uword volatile *) 0xF162))
#define CCU60_1IC_GPX                      ((T_Reg16 *) 0xF162)->bit8
#define CCU60_1IC_IE                       ((T_Reg16 *) 0xF162)->bit6
#define CCU60_1IC_IR                       ((T_Reg16 *) 0xF162)->bit7

// CCU60 Interrupt Control Reg. 2
#define CCU60_2IC              (*((uword volatile *) 0xF164))
#define CCU60_2IC_GPX                      ((T_Reg16 *) 0xF164)->bit8
#define CCU60_2IC_IE                       ((T_Reg16 *) 0xF164)->bit6
#define CCU60_2IC_IR                       ((T_Reg16 *) 0xF164)->bit7

// CCU60 Interrupt Control Reg. 3
#define CCU60_3IC              (*((uword volatile *) 0xF166))
#define CCU60_3IC_GPX                      ((T_Reg16 *) 0xF166)->bit8
#define CCU60_3IC_IE                       ((T_Reg16 *) 0xF166)->bit6
#define CCU60_3IC_IR                       ((T_Reg16 *) 0xF166)->bit7

// Capture/Compare Register for Channel CC60
#define CCU60_CC60R            (*((uword volatile *) 0xEA18))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU60_CC60SR           (*((uword volatile *) 0xEA20))

// Capture/Compare Register for Channel CC61
#define CCU60_CC61R            (*((uword volatile *) 0xEA1A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU60_CC61SR           (*((uword volatile *) 0xEA22))

// Capture/Compare Register for Channel CC62
#define CCU60_CC62R            (*((uword volatile *) 0xEA1C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU60_CC62SR           (*((uword volatile *) 0xEA24))

// Compare Register for T13
#define CCU60_CC63R            (*((uword volatile *) 0xEA34))

// Compare Shadow Register for T13
#define CCU60_CC63SR           (*((uword volatile *) 0xEA36))

// Compare State Modification Register
#define CCU60_CMPMODIF         (*((uword volatile *) 0xEA2A))

// Compare State Register
#define CCU60_CMPSTAT          (*((uword volatile *) 0xEA28))

// Module Identification Register
#define CCU60_ID               (*((uword volatile *) 0xEA08))

// Interrupt Enable Register
#define CCU60_IEN              (*((uword volatile *) 0xEA58))

// Interrupt Node Pointer Register
#define CCU60_INP              (*((uword volatile *) 0xEA56))

// Interrupt Status Register
#define CCU60_IS               (*((uword volatile *) 0xEA50))

// Interrupt Status Reset Register
#define CCU60_ISR              (*((uword volatile *) 0xEA54))

// Interrupt Status Set Register
#define CCU60_ISS              (*((uword volatile *) 0xEA52))

// Kernel State Configuration Register
#define CCU60_KSCFG            (*((uword volatile *) 0xEA00))

// Kernel State Control Sensitivity Register
#define CCU60_KSCSR            (*((uword volatile *) 0xEA0E))

// Module Configuration Register
#define CCU60_MCFG             (*((uword volatile *) 0xEA0C))

// Multi-Channel Mode Control Register
#define CCU60_MCMCTR           (*((uword volatile *) 0xEA4E))

// Multi-Channel Mode Output Register
#define CCU60_MCMOUT           (*((uword volatile *) 0xEA4C))

// Multi-Channel Mode Output Shadow Register
#define CCU60_MCMOUTS          (*((uword volatile *) 0xEA4A))

// Modulation Control Register
#define CCU60_MODCTR           (*((uword volatile *) 0xEA40))

// Port Input Select Register High
#define CCU60_PISELH           (*((uword volatile *) 0xEA06))

// Port Input Select Register Low
#define CCU60_PISELL           (*((uword volatile *) 0xEA04))

// Passive State Level Register
#define CCU60_PSLR             (*((uword volatile *) 0xEA44))

// Timer T12 Counter Register
#define CCU60_T12              (*((uword volatile *) 0xEA10))

// Dead-Time Control Register for Timer12
#define CCU60_T12DTC           (*((uword volatile *) 0xEA14))

// T12 Mode Select Register
#define CCU60_T12MSEL          (*((uword volatile *) 0xEA46))

// Timer 12 Period Register
#define CCU60_T12PR            (*((uword volatile *) 0xEA12))

// Timer T13 Counter Register
#define CCU60_T13              (*((uword volatile *) 0xEA30))

// Timer 13 Period Register
#define CCU60_T13PR            (*((uword volatile *) 0xEA32))

// Timer Control Register 0
#define CCU60_TCTR0            (*((uword volatile *) 0xEA2C))

// Timer Control Register 2
#define CCU60_TCTR2            (*((uword volatile *) 0xEA2E))

// Timer Control Register 4
#define CCU60_TCTR4            (*((uword volatile *) 0xEA26))

// Trap Control Register
#define CCU60_TRPCTR           (*((uword volatile *) 0xEA42))

// CCU61 Interrupt Control Reg. 0
#define CCU61_0IC              (*((uword volatile *) 0xF168))
#define CCU61_0IC_GPX                      ((T_Reg16 *) 0xF168)->bit8
#define CCU61_0IC_IE                       ((T_Reg16 *) 0xF168)->bit6
#define CCU61_0IC_IR                       ((T_Reg16 *) 0xF168)->bit7

// CCU61 Interrupt Control Reg. 1
#define CCU61_1IC              (*((uword volatile *) 0xF16A))
#define CCU61_1IC_GPX                      ((T_Reg16 *) 0xF16A)->bit8
#define CCU61_1IC_IE                       ((T_Reg16 *) 0xF16A)->bit6
#define CCU61_1IC_IR                       ((T_Reg16 *) 0xF16A)->bit7

// CCU61 Interrupt Control Reg. 2
#define CCU61_2IC              (*((uword volatile *) 0xF16C))
#define CCU61_2IC_GPX                      ((T_Reg16 *) 0xF16C)->bit8
#define CCU61_2IC_IE                       ((T_Reg16 *) 0xF16C)->bit6
#define CCU61_2IC_IR                       ((T_Reg16 *) 0xF16C)->bit7

// CCU61 Interrupt Control Reg. 3
#define CCU61_3IC              (*((uword volatile *) 0xF16E))
#define CCU61_3IC_GPX                      ((T_Reg16 *) 0xF16E)->bit8
#define CCU61_3IC_IE                       ((T_Reg16 *) 0xF16E)->bit6
#define CCU61_3IC_IR                       ((T_Reg16 *) 0xF16E)->bit7

// Capture/Compare Register for Channel CC60
#define CCU61_CC60R            (*((uword volatile *) 0xEA98))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU61_CC60SR           (*((uword volatile *) 0xEAA0))

// Capture/Compare Register for Channel CC61
#define CCU61_CC61R            (*((uword volatile *) 0xEA9A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU61_CC61SR           (*((uword volatile *) 0xEAA2))

// Capture/Compare Register for Channel CC62
#define CCU61_CC62R            (*((uword volatile *) 0xEA9C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU61_CC62SR           (*((uword volatile *) 0xEAA4))

// Compare Register for T13
#define CCU61_CC63R            (*((uword volatile *) 0xEAB4))

// Compare Shadow Register for T13
#define CCU61_CC63SR           (*((uword volatile *) 0xEAB6))

// Compare State Modification Register
#define CCU61_CMPMODIF         (*((uword volatile *) 0xEAAA))

// Compare State Register
#define CCU61_CMPSTAT          (*((uword volatile *) 0xEAA8))

// Module Identification Register
#define CCU61_ID               (*((uword volatile *) 0xEA88))

// Interrupt Enable Register
#define CCU61_IEN              (*((uword volatile *) 0xEAD8))

// Interrupt Node Pointer Register
#define CCU61_INP              (*((uword volatile *) 0xEAD6))

// Interrupt Status Register
#define CCU61_IS               (*((uword volatile *) 0xEAD0))

// Interrupt Status Reset Register
#define CCU61_ISR              (*((uword volatile *) 0xEAD4))

// Interrupt Status Set Register
#define CCU61_ISS              (*((uword volatile *) 0xEAD2))

// Kernel State Configuration Register
#define CCU61_KSCFG            (*((uword volatile *) 0xEA80))

// Kernel State Control Sensitivity Register
#define CCU61_KSCSR            (*((uword volatile *) 0xEA8E))

// Module Configuration Register
#define CCU61_MCFG             (*((uword volatile *) 0xEA8C))

// Multi-Channel Mode Control Register
#define CCU61_MCMCTR           (*((uword volatile *) 0xEACE))

// Multi-Channel Mode Output Register
#define CCU61_MCMOUT           (*((uword volatile *) 0xEACC))

// Multi-Channel Mode Output Shadow Register
#define CCU61_MCMOUTS          (*((uword volatile *) 0xEACA))

// Modulation Control Register
#define CCU61_MODCTR           (*((uword volatile *) 0xEAC0))

// Port Input Select Register High
#define CCU61_PISELH           (*((uword volatile *) 0xEA86))

// Port Input Select Register Low
#define CCU61_PISELL           (*((uword volatile *) 0xEA84))

// Passive State Level Register
#define CCU61_PSLR             (*((uword volatile *) 0xEAC4))

// Timer T12 Counter Register
#define CCU61_T12              (*((uword volatile *) 0xEA90))

// Dead-Time Control Register for Timer12
#define CCU61_T12DTC           (*((uword volatile *) 0xEA94))

// T12 Mode Select Register
#define CCU61_T12MSEL          (*((uword volatile *) 0xEAC6))

// Timer 12 Period Register
#define CCU61_T12PR            (*((uword volatile *) 0xEA92))

// Timer T13 Counter Register
#define CCU61_T13              (*((uword volatile *) 0xEAB0))

// Timer 13 Period Register
#define CCU61_T13PR            (*((uword volatile *) 0xEAB2))

// Timer Control Register 0
#define CCU61_TCTR0            (*((uword volatile *) 0xEAAC))

// Timer Control Register 2
#define CCU61_TCTR2            (*((uword volatile *) 0xEAAE))

// Timer Control Register 4
#define CCU61_TCTR4            (*((uword volatile *) 0xEAA6))

// Trap Control Register
#define CCU61_TRPCTR           (*((uword volatile *) 0xEAC2))

// CCU62 Interrupt Control Reg. 0
#define CCU62_0IC              (*((uword volatile *) 0xF170))
#define CCU62_0IC_GPX                      ((T_Reg16 *) 0xF170)->bit8
#define CCU62_0IC_IE                       ((T_Reg16 *) 0xF170)->bit6
#define CCU62_0IC_IR                       ((T_Reg16 *) 0xF170)->bit7

// CCU62 Interrupt Control Reg. 1
#define CCU62_1IC              (*((uword volatile *) 0xF172))
#define CCU62_1IC_GPX                      ((T_Reg16 *) 0xF172)->bit8
#define CCU62_1IC_IE                       ((T_Reg16 *) 0xF172)->bit6
#define CCU62_1IC_IR                       ((T_Reg16 *) 0xF172)->bit7

// CCU62 Interrupt Control Reg. 2
#define CCU62_2IC              (*((uword volatile *) 0xF174))
#define CCU62_2IC_GPX                      ((T_Reg16 *) 0xF174)->bit8
#define CCU62_2IC_IE                       ((T_Reg16 *) 0xF174)->bit6
#define CCU62_2IC_IR                       ((T_Reg16 *) 0xF174)->bit7

// CCU62 Interrupt Control Reg. 3
#define CCU62_3IC              (*((uword volatile *) 0xF176))
#define CCU62_3IC_GPX                      ((T_Reg16 *) 0xF176)->bit8
#define CCU62_3IC_IE                       ((T_Reg16 *) 0xF176)->bit6
#define CCU62_3IC_IR                       ((T_Reg16 *) 0xF176)->bit7

// Capture/Compare Register for Channel CC60
#define CCU62_CC60R            (*((uword volatile *) 0xEB18))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU62_CC60SR           (*((uword volatile *) 0xEB20))

// Capture/Compare Register for Channel CC61
#define CCU62_CC61R            (*((uword volatile *) 0xEB1A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU62_CC61SR           (*((uword volatile *) 0xEB22))

// Capture/Compare Register for Channel CC62
#define CCU62_CC62R            (*((uword volatile *) 0xEB1C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU62_CC62SR           (*((uword volatile *) 0xEB24))

// Compare Register for T13
#define CCU62_CC63R            (*((uword volatile *) 0xEB34))

// Compare Shadow Register for T13
#define CCU62_CC63SR           (*((uword volatile *) 0xEB36))

// Compare State Modification Register
#define CCU62_CMPMODIF         (*((uword volatile *) 0xEB2A))

// Compare State Register
#define CCU62_CMPSTAT          (*((uword volatile *) 0xEB28))

// Module Identification Register
#define CCU62_ID               (*((uword volatile *) 0xEB08))

// Interrupt Enable Register
#define CCU62_IEN              (*((uword volatile *) 0xEB58))

// Interrupt Node Pointer Register
#define CCU62_INP              (*((uword volatile *) 0xEB56))

// Interrupt Status Register
#define CCU62_IS               (*((uword volatile *) 0xEB50))

// Interrupt Status Reset Register
#define CCU62_ISR              (*((uword volatile *) 0xEB54))

// Interrupt Status Set Register
#define CCU62_ISS              (*((uword volatile *) 0xEB52))

// Kernel State Configuration Register
#define CCU62_KSCFG            (*((uword volatile *) 0xEB00))

// Kernel State Control Sensitivity Register
#define CCU62_KSCSR            (*((uword volatile *) 0xEB0E))

// Module Configuration Register
#define CCU62_MCFG             (*((uword volatile *) 0xEB0C))

// Multi-Channel Mode Control Register
#define CCU62_MCMCTR           (*((uword volatile *) 0xEB4E))

// Multi-Channel Mode Output Register
#define CCU62_MCMOUT           (*((uword volatile *) 0xEB4C))

// Multi-Channel Mode Output Shadow Register
#define CCU62_MCMOUTS          (*((uword volatile *) 0xEB4A))

// Modulation Control Register
#define CCU62_MODCTR           (*((uword volatile *) 0xEB40))

// Port Input Select Register High
#define CCU62_PISELH           (*((uword volatile *) 0xEB06))

// Port Input Select Register Low
#define CCU62_PISELL           (*((uword volatile *) 0xEB04))

// Passive State Level Register
#define CCU62_PSLR             (*((uword volatile *) 0xEB44))

// Timer T12 Counter Register
#define CCU62_T12              (*((uword volatile *) 0xEB10))

// Dead-Time Control Register for Timer12
#define CCU62_T12DTC           (*((uword volatile *) 0xEB14))

// T12 Mode Select Register
#define CCU62_T12MSEL          (*((uword volatile *) 0xEB46))

// Timer 12 Period Register
#define CCU62_T12PR            (*((uword volatile *) 0xEB12))

// Timer T13 Counter Register
#define CCU62_T13              (*((uword volatile *) 0xEB30))

// Timer 13 Period Register
#define CCU62_T13PR            (*((uword volatile *) 0xEB32))

// Timer Control Register 0
#define CCU62_TCTR0            (*((uword volatile *) 0xEB2C))

// Timer Control Register 2
#define CCU62_TCTR2            (*((uword volatile *) 0xEB2E))

// Timer Control Register 4
#define CCU62_TCTR4            (*((uword volatile *) 0xEB26))

// Trap Control Register
#define CCU62_TRPCTR           (*((uword volatile *) 0xEB42))

// CCU63 Interrupt Control Reg. 0
#define CCU63_0IC              (*((uword volatile *) 0xF178))
#define CCU63_0IC_GPX                      ((T_Reg16 *) 0xF178)->bit8
#define CCU63_0IC_IE                       ((T_Reg16 *) 0xF178)->bit6
#define CCU63_0IC_IR                       ((T_Reg16 *) 0xF178)->bit7

// CCU63 Interrupt Control Reg. 1
#define CCU63_1IC              (*((uword volatile *) 0xF17A))
#define CCU63_1IC_GPX                      ((T_Reg16 *) 0xF17A)->bit8
#define CCU63_1IC_IE                       ((T_Reg16 *) 0xF17A)->bit6
#define CCU63_1IC_IR                       ((T_Reg16 *) 0xF17A)->bit7

// CCU63 Interrupt Control Reg. 2
#define CCU63_2IC              (*((uword volatile *) 0xF17C))
#define CCU63_2IC_GPX                      ((T_Reg16 *) 0xF17C)->bit8
#define CCU63_2IC_IE                       ((T_Reg16 *) 0xF17C)->bit6
#define CCU63_2IC_IR                       ((T_Reg16 *) 0xF17C)->bit7

// CCU63 Interrupt Control Reg. 3
#define CCU63_3IC              (*((uword volatile *) 0xF17E))
#define CCU63_3IC_GPX                      ((T_Reg16 *) 0xF17E)->bit8
#define CCU63_3IC_IE                       ((T_Reg16 *) 0xF17E)->bit6
#define CCU63_3IC_IR                       ((T_Reg16 *) 0xF17E)->bit7

// Capture/Compare Register for Channel CC60
#define CCU63_CC60R            (*((uword volatile *) 0xEB98))

// Capture/Compare Shadow Reg. for Channel CC60
#define CCU63_CC60SR           (*((uword volatile *) 0xEBA0))

// Capture/Compare Register for Channel CC61
#define CCU63_CC61R            (*((uword volatile *) 0xEB9A))

// Capture/Compare Shadow Reg. for Channel CC61
#define CCU63_CC61SR           (*((uword volatile *) 0xEBA2))

// Capture/Compare Register for Channel CC62
#define CCU63_CC62R            (*((uword volatile *) 0xEB9C))

// Capture/Compare Shadow Reg. for Channel CC62
#define CCU63_CC62SR           (*((uword volatile *) 0xEBA4))

// Compare Register for T13
#define CCU63_CC63R            (*((uword volatile *) 0xEBB4))

// Compare Shadow Register for T13
#define CCU63_CC63SR           (*((uword volatile *) 0xEBB6))

// Compare State Modification Register
#define CCU63_CMPMODIF         (*((uword volatile *) 0xEBAA))

// Compare State Register
#define CCU63_CMPSTAT          (*((uword volatile *) 0xEBA8))

// Module Identification Register
#define CCU63_ID               (*((uword volatile *) 0xEB88))

// Interrupt Enable Register
#define CCU63_IEN              (*((uword volatile *) 0xEBD8))

// Interrupt Node Pointer Register
#define CCU63_INP              (*((uword volatile *) 0xEBD6))

// Interrupt Status Register
#define CCU63_IS               (*((uword volatile *) 0xEBD0))

// Interrupt Status Reset Register
#define CCU63_ISR              (*((uword volatile *) 0xEBD4))

// Interrupt Status Set Register
#define CCU63_ISS              (*((uword volatile *) 0xEBD2))

// Kernel State Configuration Register
#define CCU63_KSCFG            (*((uword volatile *) 0xEB80))

// Kernel State Control Sensitivity Register
#define CCU63_KSCSR            (*((uword volatile *) 0xEB8E))

// Module Configuration Register
#define CCU63_MCFG             (*((uword volatile *) 0xEB8C))

// Multi-Channel Mode Control Register
#define CCU63_MCMCTR           (*((uword volatile *) 0xEBCE))

// Multi-Channel Mode Output Register
#define CCU63_MCMOUT           (*((uword volatile *) 0xEBCC))

// Multi-Channel Mode Output Shadow Register
#define CCU63_MCMOUTS          (*((uword volatile *) 0xEBCA))

// Modulation Control Register
#define CCU63_MODCTR           (*((uword volatile *) 0xEBC0))

// Port Input Select Register High
#define CCU63_PISELH           (*((uword volatile *) 0xEB86))

// Port Input Select Register Low
#define CCU63_PISELL           (*((uword volatile *) 0xEB84))

// Passive State Level Register
#define CCU63_PSLR             (*((uword volatile *) 0xEBC4))

// Timer T12 Counter Register
#define CCU63_T12              (*((uword volatile *) 0xEB90))

// Dead-Time Control Register for Timer12
#define CCU63_T12DTC           (*((uword volatile *) 0xEB94))

// T12 Mode Select Register
#define CCU63_T12MSEL          (*((uword volatile *) 0xEBC6))

// Timer 12 Period Register
#define CCU63_T12PR            (*((uword volatile *) 0xEB92))

// Timer T13 Counter Register
#define CCU63_T13              (*((uword volatile *) 0xEBB0))

// Timer 13 Period Register
#define CCU63_T13PR            (*((uword volatile *) 0xEBB2))

// Timer Control Register 0
#define CCU63_TCTR0            (*((uword volatile *) 0xEBAC))

// Timer Control Register 2
#define CCU63_TCTR2            (*((uword volatile *) 0xEBAE))

// Timer Control Register 4
#define CCU63_TCTR4            (*((uword volatile *) 0xEBA6))

// Trap Control Register
#define CCU63_TRPCTR           (*((uword volatile *) 0xEBC2))

// Monitor target ADdress register
#define CMADR                  (*((uword volatile *) 0xF0F8))

// Monitor Control and Break Level register
#define CMCTR                  (*((uword volatile *) 0xF0FA))

// Data Register in Communication Mode
#define COMDATA                (*((uword volatile *) 0xF068))

// Context Pointer
#define CP                     (*((uword volatile *) 0xFE10))

// CPU Control Register 1
#define CPUCON1                (*((uword volatile *) 0xFE18))

// CPU Control Register 2
#define CPUCON2                (*((uword volatile *) 0xFE1A))

// CPU Identification Register
#define CPUID                  (*((uword volatile *) 0xF00C))

// Code Segment Pointer
#define CSP                    (*((uword volatile *) 0xFE08))

// Debug Status Register
#define DBGSR                  (*((uword volatile *) 0xF0FC))

// Data Compare Data Programming register
#define DCMPDP                 (*((uword volatile *) 0xF0EE))

// Data Compare Select Programming register
#define DCMPSP                 (*((uword volatile *) 0xF0EC))

// Break Pin Event Control Register
#define DEXEVT                 (*((uword volatile *) 0xF0F2))

// Data Page Pointer 0
#define DPP0                   (*((uword volatile *) 0xFE00))

// Data Page Pointer 1
#define DPP1                   (*((uword volatile *) 0xFE02))

// Data Page Pointer 2
#define DPP2                   (*((uword volatile *) 0xFE04))

// Data Page Pointer 3
#define DPP3                   (*((uword volatile *) 0xFE06))

// PEC Destination Pointer 0
#define DSTP0                  (*((uword volatile *) 0xEC42))

// PEC Destination Pointer 1
#define DSTP1                  (*((uword volatile *) 0xEC46))

// PEC Destination Pointer 2
#define DSTP2                  (*((uword volatile *) 0xEC4A))

// PEC Destination Pointer 3
#define DSTP3                  (*((uword volatile *) 0xEC4E))

// PEC Destination Pointer 4
#define DSTP4                  (*((uword volatile *) 0xEC52))

// PEC Destination Pointer 5
#define DSTP5                  (*((uword volatile *) 0xEC56))

// PEC Destination Pointer 6
#define DSTP6                  (*((uword volatile *) 0xEC5A))

// PEC Destination Pointer 7
#define DSTP7                  (*((uword volatile *) 0xEC5E))

// Software Debug Event Control Register
#define DSWEVT                 (*((uword volatile *) 0xF0F4))

// Task ID Register
#define DTIDR                  (*((uword volatile *) 0xF0D8))

// Hardware Trigger Event Control Register
#define DTREVT                 (*((uword volatile *) 0xF0F0))

// EBC Mode Register 0
#define EBCMOD0                (*((uword volatile *) 0xEE00))

// EBC Mode Register 1
#define EBCMOD1                (*((uword volatile *) 0xEE02))

// EOP Interrupt Control Reg.
#define EOPIC                  (*((uword volatile *) 0xF19E))
#define EOPIC_EOPIE                    ((T_Reg16 *) 0xF19E)->bit6
#define EOPIC_EOPIR                    ((T_Reg16 *) 0xF19E)->bit7
#define EOPIC_GPX                      ((T_Reg16 *) 0xF19E)->bit8

// Function Cfg. Reg. for CS0
#define FCONCS0                (*((uword volatile *) 0xEE12))

// Function Cfg. Reg. for CS1
#define FCONCS1                (*((uword volatile *) 0xEE1A))

// Function Cfg. Reg. for CS2
#define FCONCS2                (*((uword volatile *) 0xEE22))

// Function Cfg. Reg. for CS3
#define FCONCS3                (*((uword volatile *) 0xEE2A))

// Function Cfg. Reg. for CS4
#define FCONCS4                (*((uword volatile *) 0xEE32))

// Fast Interrupt Address Reg. 0
#define FINT0ADDR              (*((uword volatile *) 0xEC02))

// Fast Interrupt Control Reg. 0
#define FINT0CSP               (*((uword volatile *) 0xEC00))

// Fast Interrupt Address Reg. 1
#define FINT1ADDR              (*((uword volatile *) 0xEC06))

// Fast Interrupt Control Reg. 1
#define FINT1CSP               (*((uword volatile *) 0xEC04))

// Flash Kernel State Con. Register
#define FL_KSCCFG              (*((uword volatile *) 0xFE22))

// Capture/Reload Register
#define GPT12E_CAPREL          (*((uword volatile *) 0xFE4A))

// GPT12 CAPREL IC
#define GPT12E_CRIC            (*((uword volatile *) 0xFF6A))
#define GPT12E_CRIC_GPX                      ((T_Reg16 *) 0xFF6A)->bit8
#define GPT12E_CRIC_IE                       ((T_Reg16 *) 0xFF6A)->bit6
#define GPT12E_CRIC_IR                       ((T_Reg16 *) 0xFF6A)->bit7

// GPT12E Module Identification Register
#define GPT12E_ID              (*((uword volatile *) 0xFFE6))

// GPT12E Kernel State Con. Register
#define GPT12E_KSCCFG          (*((uword volatile *) 0xFE1C))

// Port Input Select Register
#define GPT12E_PISEL           (*((uword volatile *) 0xFE4C))

// Timer 2
#define GPT12E_T2              (*((uword volatile *) 0xFE40))

// Timer 2 Control Register
#define GPT12E_T2CON           (*((uword volatile *) 0xFF40))
#define GPT12E_T2CON_T2CHDIR                  ((T_Reg16 *) 0xFF40)->bit14
#define GPT12E_T2CON_T2EDGE                   ((T_Reg16 *) 0xFF40)->bit13
#define GPT12E_T2CON_T2IRDIS                  ((T_Reg16 *) 0xFF40)->bit12
#define GPT12E_T2CON_T2R                      ((T_Reg16 *) 0xFF40)->bit6
#define GPT12E_T2CON_T2RC                     ((T_Reg16 *) 0xFF40)->bit9
#define GPT12E_T2CON_T2RDIR                   ((T_Reg16 *) 0xFF40)->bit15
#define GPT12E_T2CON_T2UD                     ((T_Reg16 *) 0xFF40)->bit7
#define GPT12E_T2CON_T2UDE                    ((T_Reg16 *) 0xFF40)->bit8

// GPT12 TIMER 2 IC
#define GPT12E_T2IC            (*((uword volatile *) 0xFF60))
#define GPT12E_T2IC_GPX                      ((T_Reg16 *) 0xFF60)->bit8
#define GPT12E_T2IC_IE                       ((T_Reg16 *) 0xFF60)->bit6
#define GPT12E_T2IC_IR                       ((T_Reg16 *) 0xFF60)->bit7

// Timer 3
#define GPT12E_T3              (*((uword volatile *) 0xFE42))

// Timer 3 Control Register
#define GPT12E_T3CON           (*((uword volatile *) 0xFF42))
#define GPT12E_T3CON_T3CHDIR                  ((T_Reg16 *) 0xFF42)->bit14
#define GPT12E_T3CON_T3EDGE                   ((T_Reg16 *) 0xFF42)->bit13
#define GPT12E_T3CON_T3OE                     ((T_Reg16 *) 0xFF42)->bit9
#define GPT12E_T3CON_T3OTL                    ((T_Reg16 *) 0xFF42)->bit10
#define GPT12E_T3CON_T3R                      ((T_Reg16 *) 0xFF42)->bit6
#define GPT12E_T3CON_T3RDIR                   ((T_Reg16 *) 0xFF42)->bit15
#define GPT12E_T3CON_T3UD                     ((T_Reg16 *) 0xFF42)->bit7
#define GPT12E_T3CON_T3UDE                    ((T_Reg16 *) 0xFF42)->bit8

// GPT12 TIMER 3 IC
#define GPT12E_T3IC            (*((uword volatile *) 0xFF62))
#define GPT12E_T3IC_GPX                      ((T_Reg16 *) 0xFF62)->bit8
#define GPT12E_T3IC_IE                       ((T_Reg16 *) 0xFF62)->bit6
#define GPT12E_T3IC_IR                       ((T_Reg16 *) 0xFF62)->bit7

// Timer 4
#define GPT12E_T4              (*((uword volatile *) 0xFE44))

// Timer 4 Control Register
#define GPT12E_T4CON           (*((uword volatile *) 0xFF44))
#define GPT12E_T4CON_CLRT2EN                  ((T_Reg16 *) 0xFF44)->bit10
#define GPT12E_T4CON_CLRT3EN                  ((T_Reg16 *) 0xFF44)->bit11
#define GPT12E_T4CON_T4CHDIR                  ((T_Reg16 *) 0xFF44)->bit14
#define GPT12E_T4CON_T4EDGE                   ((T_Reg16 *) 0xFF44)->bit13
#define GPT12E_T4CON_T4IRDIS                  ((T_Reg16 *) 0xFF44)->bit12
#define GPT12E_T4CON_T4R                      ((T_Reg16 *) 0xFF44)->bit6
#define GPT12E_T4CON_T4RC                     ((T_Reg16 *) 0xFF44)->bit9
#define GPT12E_T4CON_T4RDIR                   ((T_Reg16 *) 0xFF44)->bit15
#define GPT12E_T4CON_T4UD                     ((T_Reg16 *) 0xFF44)->bit7
#define GPT12E_T4CON_T4UDE                    ((T_Reg16 *) 0xFF44)->bit8

// GPT12 TIMER 4 IC
#define GPT12E_T4IC            (*((uword volatile *) 0xFF64))
#define GPT12E_T4IC_GPX                      ((T_Reg16 *) 0xFF64)->bit8
#define GPT12E_T4IC_IE                       ((T_Reg16 *) 0xFF64)->bit6
#define GPT12E_T4IC_IR                       ((T_Reg16 *) 0xFF64)->bit7

// Timer 5
#define GPT12E_T5              (*((uword volatile *) 0xFE46))

// Timer 5 Control Register
#define GPT12E_T5CON           (*((uword volatile *) 0xFF46))
#define GPT12E_T5CON_CT3                      ((T_Reg16 *) 0xFF46)->bit10
#define GPT12E_T5CON_T5CLR                    ((T_Reg16 *) 0xFF46)->bit14
#define GPT12E_T5CON_T5R                      ((T_Reg16 *) 0xFF46)->bit6
#define GPT12E_T5CON_T5RC                     ((T_Reg16 *) 0xFF46)->bit9
#define GPT12E_T5CON_T5SC                     ((T_Reg16 *) 0xFF46)->bit15
#define GPT12E_T5CON_T5UD                     ((T_Reg16 *) 0xFF46)->bit7
#define GPT12E_T5CON_T5UDE                    ((T_Reg16 *) 0xFF46)->bit8

// GPT12 TIMER 5 IC
#define GPT12E_T5IC            (*((uword volatile *) 0xFF66))
#define GPT12E_T5IC_GPX                      ((T_Reg16 *) 0xFF66)->bit8
#define GPT12E_T5IC_IE                       ((T_Reg16 *) 0xFF66)->bit6
#define GPT12E_T5IC_IR                       ((T_Reg16 *) 0xFF66)->bit7

// Timer 6
#define GPT12E_T6              (*((uword volatile *) 0xFE48))

// Timer 6 Control Register
#define GPT12E_T6CON           (*((uword volatile *) 0xFF48))
#define GPT12E_T6CON_T6CLR                    ((T_Reg16 *) 0xFF48)->bit14
#define GPT12E_T6CON_T6OE                     ((T_Reg16 *) 0xFF48)->bit9
#define GPT12E_T6CON_T6OTL                    ((T_Reg16 *) 0xFF48)->bit10
#define GPT12E_T6CON_T6R                      ((T_Reg16 *) 0xFF48)->bit6
#define GPT12E_T6CON_T6SR                     ((T_Reg16 *) 0xFF48)->bit15
#define GPT12E_T6CON_T6UD                     ((T_Reg16 *) 0xFF48)->bit7
#define GPT12E_T6CON_T6UDE                    ((T_Reg16 *) 0xFF48)->bit8

// GPT12 TIMER 6 IC
#define GPT12E_T6IC            (*((uword volatile *) 0xFF68))
#define GPT12E_T6IC_GPX                      ((T_Reg16 *) 0xFF68)->bit8
#define GPT12E_T6IC_IE                       ((T_Reg16 *) 0xFF68)->bit6
#define GPT12E_T6IC_IR                       ((T_Reg16 *) 0xFF68)->bit7

// Address Pointer
#define IDX0                   (*((uword volatile *) 0xFF08))

// Address Pointer
#define IDX1                   (*((uword volatile *) 0xFF0A))

// ECC Status
#define IMB_ECC_STAT           (*((uword volatile far *) 0xFFFF22))

// ECC Trap Control
#define IMB_ECC_TRAP           (*((uword volatile far *) 0xFFFF20))

// Flash State Busy
#define IMB_FSR_BUSY           (*((uword volatile far *) 0xFFFF06))

// Flash State Operations
#define IMB_FSR_OP             (*((uword volatile far *) 0xFFFF08))

// Flash State Protection
#define IMB_FSR_PROT           (*((uword volatile far *) 0xFFFF0A))

// IMB Control High
#define IMB_IMBCTRH            (*((uword volatile far *) 0xFFFF02))

// IMB Control Low
#define IMB_IMBCTRL            (*((uword volatile far *) 0xFFFF00))

// Interrupt Control
#define IMB_INTCTR             (*((uword volatile far *) 0xFFFF04))

// Margin Control 0
#define IMB_MAR0               (*((uword volatile far *) 0xFFFF0C))

// Protection Configuration 0.
#define IMB_PROCON0            (*((uword volatile far *) 0xFFFF10))

// Protection Configuration 1.
#define IMB_PROCON1            (*((uword volatile far *) 0xFFFF12))

// Protection Configuration 2.
#define IMB_PROCON2            (*((uword volatile far *) 0xFFFF14))

// Protection Configuration 3.
#define IMB_PROCON3            (*((uword volatile far *) 0xFFFF16))

// Status and Control Register
#define IOSR                   (*((uword volatile *) 0xF06C))

// Accumulator High Word
#define MAH                    (*((uword volatile *) 0xFE5E))

// Accumulator Low Word
#define MAL                    (*((uword volatile *) 0xFE5C))

// MultiCAN Kernel State Con. Register
#define MCAN_KSCCFG            (*((uword volatile *) 0xFE1E))

// Count Register
#define MCHK_COUNT             (*((uword volatile *) 0xFE5A))

// Module Identification Register MEM
#define MCHK_ID                (*((uword volatile *) 0xFFE0))

// Input Register
#define MCHK_IR                (*((uword volatile *) 0xFE58))

// Result Register High
#define MCHK_RRH               (*((uword volatile *) 0xF05A))

// Result Register Low
#define MCHK_RRL               (*((uword volatile *) 0xF058))

// Tap Polynomial Register High
#define MCHK_TPRH              (*((uword volatile *) 0xF05E))

// Tap Polynomial Register Low
#define MCHK_TPRL              (*((uword volatile *) 0xF05C))

// MAC Control Word
#define MCW                    (*((uword volatile *) 0xFFDC))
#define MCW_MP                       ((T_Reg16 *) 0xFFDC)->bit10
#define MCW_MS                       ((T_Reg16 *) 0xFFDC)->bit9

// Multiply Divide Control
#define MDC                    (*((uword volatile *) 0xFF0E))
#define MDC_MDRIU                    ((T_Reg16 *) 0xFF0E)->bit4

// Multiply Divide High Word
#define MDH                    (*((uword volatile *) 0xFE0C))

// Multiply Divide Low Word
#define MDL                    (*((uword volatile *) 0xFE0E))

// London Subsystem Kernel State Con. Register
#define MEM_KSCCFG             (*((uword volatile *) 0xF012))

// Protection Mode Register 0
#define MPU_PM0                (*((uword volatile *) 0xFFC8))
#define MPU_PM0_L0EA                     ((T_Reg16 *) 0xFFC8)->bit4
#define MPU_PM0_L0EB                     ((T_Reg16 *) 0xFFC8)->bit12
#define MPU_PM0_L1EA                     ((T_Reg16 *) 0xFFC8)->bit5
#define MPU_PM0_L1EB                     ((T_Reg16 *) 0xFFC8)->bit13
#define MPU_PM0_L2EA                     ((T_Reg16 *) 0xFFC8)->bit6
#define MPU_PM0_L2EB                     ((T_Reg16 *) 0xFFC8)->bit14
#define MPU_PM0_L3EA                     ((T_Reg16 *) 0xFFC8)->bit7
#define MPU_PM0_L3EB                     ((T_Reg16 *) 0xFFC8)->bit15
#define MPU_PM0_PROTEN                   ((T_Reg16 *) 0xFFC8)->bit0
#define MPU_PM0_REA                      ((T_Reg16 *) 0xFFC8)->bit2
#define MPU_PM0_REB                      ((T_Reg16 *) 0xFFC8)->bit10
#define MPU_PM0_WEA                      ((T_Reg16 *) 0xFFC8)->bit3
#define MPU_PM0_WEB                      ((T_Reg16 *) 0xFFC8)->bit11
#define MPU_PM0_XEA                      ((T_Reg16 *) 0xFFC8)->bit1
#define MPU_PM0_XEB                      ((T_Reg16 *) 0xFFC8)->bit9

// Protection Mode Register 1
#define MPU_PM1                (*((uword volatile *) 0xFFCA))
#define MPU_PM1_L0EA                     ((T_Reg16 *) 0xFFCA)->bit4
#define MPU_PM1_L0EB                     ((T_Reg16 *) 0xFFCA)->bit12
#define MPU_PM1_L1EA                     ((T_Reg16 *) 0xFFCA)->bit5
#define MPU_PM1_L1EB                     ((T_Reg16 *) 0xFFCA)->bit13
#define MPU_PM1_L2EA                     ((T_Reg16 *) 0xFFCA)->bit6
#define MPU_PM1_L2EB                     ((T_Reg16 *) 0xFFCA)->bit14
#define MPU_PM1_L3EA                     ((T_Reg16 *) 0xFFCA)->bit7
#define MPU_PM1_L3EB                     ((T_Reg16 *) 0xFFCA)->bit15
#define MPU_PM1_REA                      ((T_Reg16 *) 0xFFCA)->bit2
#define MPU_PM1_REB                      ((T_Reg16 *) 0xFFCA)->bit10
#define MPU_PM1_WEA                      ((T_Reg16 *) 0xFFCA)->bit3
#define MPU_PM1_WEB                      ((T_Reg16 *) 0xFFCA)->bit11
#define MPU_PM1_XEA                      ((T_Reg16 *) 0xFFCA)->bit1
#define MPU_PM1_XEB                      ((T_Reg16 *) 0xFFCA)->bit9

// Protection Mode Register 2
#define MPU_PM2                (*((uword volatile *) 0xFFCC))
#define MPU_PM2_L0EA                     ((T_Reg16 *) 0xFFCC)->bit4
#define MPU_PM2_L0EB                     ((T_Reg16 *) 0xFFCC)->bit12
#define MPU_PM2_L1EA                     ((T_Reg16 *) 0xFFCC)->bit5
#define MPU_PM2_L1EB                     ((T_Reg16 *) 0xFFCC)->bit13
#define MPU_PM2_L2EA                     ((T_Reg16 *) 0xFFCC)->bit6
#define MPU_PM2_L2EB                     ((T_Reg16 *) 0xFFCC)->bit14
#define MPU_PM2_L3EA                     ((T_Reg16 *) 0xFFCC)->bit7
#define MPU_PM2_L3EB                     ((T_Reg16 *) 0xFFCC)->bit15
#define MPU_PM2_REA                      ((T_Reg16 *) 0xFFCC)->bit2
#define MPU_PM2_REB                      ((T_Reg16 *) 0xFFCC)->bit10
#define MPU_PM2_WEA                      ((T_Reg16 *) 0xFFCC)->bit3
#define MPU_PM2_WEB                      ((T_Reg16 *) 0xFFCC)->bit11
#define MPU_PM2_XEA                      ((T_Reg16 *) 0xFFCC)->bit1
#define MPU_PM2_XEB                      ((T_Reg16 *) 0xFFCC)->bit9

// Protection Mode Register 3
#define MPU_PM3                (*((uword volatile *) 0xFFCE))
#define MPU_PM3_L0EA                     ((T_Reg16 *) 0xFFCE)->bit4
#define MPU_PM3_L0EB                     ((T_Reg16 *) 0xFFCE)->bit12
#define MPU_PM3_L1EA                     ((T_Reg16 *) 0xFFCE)->bit5
#define MPU_PM3_L1EB                     ((T_Reg16 *) 0xFFCE)->bit13
#define MPU_PM3_L2EA                     ((T_Reg16 *) 0xFFCE)->bit6
#define MPU_PM3_L2EB                     ((T_Reg16 *) 0xFFCE)->bit14
#define MPU_PM3_L3EA                     ((T_Reg16 *) 0xFFCE)->bit7
#define MPU_PM3_L3EB                     ((T_Reg16 *) 0xFFCE)->bit15
#define MPU_PM3_REA                      ((T_Reg16 *) 0xFFCE)->bit2
#define MPU_PM3_REB                      ((T_Reg16 *) 0xFFCE)->bit10
#define MPU_PM3_WEA                      ((T_Reg16 *) 0xFFCE)->bit3
#define MPU_PM3_WEB                      ((T_Reg16 *) 0xFFCE)->bit11
#define MPU_PM3_XEA                      ((T_Reg16 *) 0xFFCE)->bit1
#define MPU_PM3_XEB                      ((T_Reg16 *) 0xFFCE)->bit9

// Protection Mode Register 4
#define MPU_PM4                (*((uword volatile *) 0xFFD0))
#define MPU_PM4_L0EA                     ((T_Reg16 *) 0xFFD0)->bit4
#define MPU_PM4_L0EB                     ((T_Reg16 *) 0xFFD0)->bit12
#define MPU_PM4_L1EA                     ((T_Reg16 *) 0xFFD0)->bit5
#define MPU_PM4_L1EB                     ((T_Reg16 *) 0xFFD0)->bit13
#define MPU_PM4_L2EA                     ((T_Reg16 *) 0xFFD0)->bit6
#define MPU_PM4_L2EB                     ((T_Reg16 *) 0xFFD0)->bit14
#define MPU_PM4_L3EA                     ((T_Reg16 *) 0xFFD0)->bit7
#define MPU_PM4_L3EB                     ((T_Reg16 *) 0xFFD0)->bit15
#define MPU_PM4_REA                      ((T_Reg16 *) 0xFFD0)->bit2
#define MPU_PM4_REB                      ((T_Reg16 *) 0xFFD0)->bit10
#define MPU_PM4_WEA                      ((T_Reg16 *) 0xFFD0)->bit3
#define MPU_PM4_WEB                      ((T_Reg16 *) 0xFFD0)->bit11
#define MPU_PM4_XEA                      ((T_Reg16 *) 0xFFD0)->bit1
#define MPU_PM4_XEB                      ((T_Reg16 *) 0xFFD0)->bit9

// Protection Mode Register 5
#define MPU_PM5                (*((uword volatile *) 0xFFD2))
#define MPU_PM5_L0EA                     ((T_Reg16 *) 0xFFD2)->bit4
#define MPU_PM5_L0EB                     ((T_Reg16 *) 0xFFD2)->bit12
#define MPU_PM5_L1EA                     ((T_Reg16 *) 0xFFD2)->bit5
#define MPU_PM5_L1EB                     ((T_Reg16 *) 0xFFD2)->bit13
#define MPU_PM5_L2EA                     ((T_Reg16 *) 0xFFD2)->bit6
#define MPU_PM5_L2EB                     ((T_Reg16 *) 0xFFD2)->bit14
#define MPU_PM5_L3EA                     ((T_Reg16 *) 0xFFD2)->bit7
#define MPU_PM5_L3EB                     ((T_Reg16 *) 0xFFD2)->bit15
#define MPU_PM5_REA                      ((T_Reg16 *) 0xFFD2)->bit2
#define MPU_PM5_REB                      ((T_Reg16 *) 0xFFD2)->bit10
#define MPU_PM5_WEA                      ((T_Reg16 *) 0xFFD2)->bit3
#define MPU_PM5_WEB                      ((T_Reg16 *) 0xFFD2)->bit11
#define MPU_PM5_XEA                      ((T_Reg16 *) 0xFFD2)->bit1
#define MPU_PM5_XEB                      ((T_Reg16 *) 0xFFD2)->bit9

// Protection Range Address
#define MPU_PRA                (*((uword volatile *) 0xFFC4))
#define MPU_PRA_RMOD                     ((T_Reg16 *) 0xFFC4)->bit15
#define MPU_PRA_RWA                      ((T_Reg16 *) 0xFFC4)->bit14
#define MPU_PRA_WMOD                     ((T_Reg16 *) 0xFFC4)->bit7
#define MPU_PRA_WWA                      ((T_Reg16 *) 0xFFC4)->bit6

// Protection Range Data
#define MPU_PRD                (*((uword volatile *) 0xFFC6))

// MAC Repeat Word
#define MRW                    (*((uword volatile *) 0xFFDA))

// MAC Status Word
#define MSW                    (*((uword volatile *) 0xFFDE))
#define MSW_MC                       ((T_Reg16 *) 0xFFDE)->bit10
#define MSW_ME                       ((T_Reg16 *) 0xFFDE)->bit12
#define MSW_MN                       ((T_Reg16 *) 0xFFDE)->bit8
#define MSW_MSL                      ((T_Reg16 *) 0xFFDE)->bit13
#define MSW_MSV                      ((T_Reg16 *) 0xFFDE)->bit11
#define MSW_MV                       ((T_Reg16 *) 0xFFDE)->bit14
#define MSW_MZ                       ((T_Reg16 *) 0xFFDE)->bit9

// Constant Ones Register
#define ONES                   (*((uword volatile *) 0xFF1E))

// Port 0 Input Register
#define P0_IN                  (*((uword volatile *) 0xFF80))
#define P0_IN_P0                       ((T_Reg16 *) 0xFF80)->bit0
#define P0_IN_P1                       ((T_Reg16 *) 0xFF80)->bit1
#define P0_IN_P10                      ((T_Reg16 *) 0xFF80)->bit10
#define P0_IN_P11                      ((T_Reg16 *) 0xFF80)->bit11
#define P0_IN_P12                      ((T_Reg16 *) 0xFF80)->bit12
#define P0_IN_P13                      ((T_Reg16 *) 0xFF80)->bit13
#define P0_IN_P14                      ((T_Reg16 *) 0xFF80)->bit14
#define P0_IN_P15                      ((T_Reg16 *) 0xFF80)->bit15
#define P0_IN_P2                       ((T_Reg16 *) 0xFF80)->bit2
#define P0_IN_P3                       ((T_Reg16 *) 0xFF80)->bit3
#define P0_IN_P4                       ((T_Reg16 *) 0xFF80)->bit4
#define P0_IN_P5                       ((T_Reg16 *) 0xFF80)->bit5
#define P0_IN_P6                       ((T_Reg16 *) 0xFF80)->bit6
#define P0_IN_P7                       ((T_Reg16 *) 0xFF80)->bit7
#define P0_IN_P8                       ((T_Reg16 *) 0xFF80)->bit8
#define P0_IN_P9                       ((T_Reg16 *) 0xFF80)->bit9

// Port 0 Input/Output Control Register 00
#define P0_IOCR00              (*((uword volatile *) 0xE800))

// Port 0 Input/Output Control Register 01
#define P0_IOCR01              (*((uword volatile *) 0xE802))

// Port 0 Input/Output Control Register 02
#define P0_IOCR02              (*((uword volatile *) 0xE804))

// Port 0 Input/Output Control Register 03
#define P0_IOCR03              (*((uword volatile *) 0xE806))

// Port 0 Input/Output Control Register 04
#define P0_IOCR04              (*((uword volatile *) 0xE808))

// Port 0 Input/Output Control Register 05
#define P0_IOCR05              (*((uword volatile *) 0xE80A))

// Port 0 Input/Output Control Register 06
#define P0_IOCR06              (*((uword volatile *) 0xE80C))

// Port 0 Input/Output Control Register 07
#define P0_IOCR07              (*((uword volatile *) 0xE80E))

// Port 0 Output Modification Register Low
#define P0_OMRL                (*((uword volatile *) 0xE9C0))

// Port 0 Output Register
#define P0_OUT                 (*((uword volatile *) 0xFFA2))
#define P0_OUT_P0                       ((T_Reg16 *) 0xFFA2)->bit0
#define P0_OUT_P1                       ((T_Reg16 *) 0xFFA2)->bit1
#define P0_OUT_P10                      ((T_Reg16 *) 0xFFA2)->bit10
#define P0_OUT_P11                      ((T_Reg16 *) 0xFFA2)->bit11
#define P0_OUT_P12                      ((T_Reg16 *) 0xFFA2)->bit12
#define P0_OUT_P13                      ((T_Reg16 *) 0xFFA2)->bit13
#define P0_OUT_P14                      ((T_Reg16 *) 0xFFA2)->bit14
#define P0_OUT_P15                      ((T_Reg16 *) 0xFFA2)->bit15
#define P0_OUT_P2                       ((T_Reg16 *) 0xFFA2)->bit2
#define P0_OUT_P3                       ((T_Reg16 *) 0xFFA2)->bit3
#define P0_OUT_P4                       ((T_Reg16 *) 0xFFA2)->bit4
#define P0_OUT_P5                       ((T_Reg16 *) 0xFFA2)->bit5
#define P0_OUT_P6                       ((T_Reg16 *) 0xFFA2)->bit6
#define P0_OUT_P7                       ((T_Reg16 *) 0xFFA2)->bit7
#define P0_OUT_P8                       ((T_Reg16 *) 0xFFA2)->bit8
#define P0_OUT_P9                       ((T_Reg16 *) 0xFFA2)->bit9

// Port 0 Output Control Register
#define P0_POCON               (*((uword volatile *) 0xE8A0))

// Port 10 Input Register
#define P10_IN                 (*((uword volatile *) 0xFF94))
#define P10_IN_P0                       ((T_Reg16 *) 0xFF94)->bit0
#define P10_IN_P1                       ((T_Reg16 *) 0xFF94)->bit1
#define P10_IN_P10                      ((T_Reg16 *) 0xFF94)->bit10
#define P10_IN_P11                      ((T_Reg16 *) 0xFF94)->bit11
#define P10_IN_P12                      ((T_Reg16 *) 0xFF94)->bit12
#define P10_IN_P13                      ((T_Reg16 *) 0xFF94)->bit13
#define P10_IN_P14                      ((T_Reg16 *) 0xFF94)->bit14
#define P10_IN_P15                      ((T_Reg16 *) 0xFF94)->bit15
#define P10_IN_P2                       ((T_Reg16 *) 0xFF94)->bit2
#define P10_IN_P3                       ((T_Reg16 *) 0xFF94)->bit3
#define P10_IN_P4                       ((T_Reg16 *) 0xFF94)->bit4
#define P10_IN_P5                       ((T_Reg16 *) 0xFF94)->bit5
#define P10_IN_P6                       ((T_Reg16 *) 0xFF94)->bit6
#define P10_IN_P7                       ((T_Reg16 *) 0xFF94)->bit7
#define P10_IN_P8                       ((T_Reg16 *) 0xFF94)->bit8
#define P10_IN_P9                       ((T_Reg16 *) 0xFF94)->bit9

// Port 10 Input/Output Control Register 00
#define P10_IOCR00             (*((uword volatile *) 0xE940))

// Port 10 Input/Output Control Register 01
#define P10_IOCR01             (*((uword volatile *) 0xE942))

// Port 10 Input/Output Control Register 02
#define P10_IOCR02             (*((uword volatile *) 0xE944))

// Port 10 Input/Output Control Register 03
#define P10_IOCR03             (*((uword volatile *) 0xE946))

// Port 10 Input/Output Control Register 04
#define P10_IOCR04             (*((uword volatile *) 0xE948))

// Port 10 Input/Output Control Register 05
#define P10_IOCR05             (*((uword volatile *) 0xE94A))

// Port 10 Input/Output Control Register 06
#define P10_IOCR06             (*((uword volatile *) 0xE94C))

// Port 10 Input/Output Control Register 07
#define P10_IOCR07             (*((uword volatile *) 0xE94E))

// Port 10 Input/Output Control Register 08
#define P10_IOCR08             (*((uword volatile *) 0xE950))

// Port 10 Input/Output Control Register 09
#define P10_IOCR09             (*((uword volatile *) 0xE952))

// Port 10 Input/Output Control Register 10
#define P10_IOCR10             (*((uword volatile *) 0xE954))

// Port 10 Input/Output Control Register 11
#define P10_IOCR11             (*((uword volatile *) 0xE956))

// Port 10 Input/Output Control Register 12
#define P10_IOCR12             (*((uword volatile *) 0xE958))

// Port 10 Input/Output Control Register 13
#define P10_IOCR13             (*((uword volatile *) 0xE95A))

// Port 10 Input/Output Control Register 14
#define P10_IOCR14             (*((uword volatile *) 0xE95C))

// Port 10 Input/Output Control Register 15
#define P10_IOCR15             (*((uword volatile *) 0xE95E))

// Port 10 Output Modification Register High
#define P10_OMRH               (*((uword volatile *) 0xE9EA))

// Port 10 Output Modification Register Low
#define P10_OMRL               (*((uword volatile *) 0xE9E8))

// Port 10 Output Register
#define P10_OUT                (*((uword volatile *) 0xFFB6))
#define P10_OUT_P0                       ((T_Reg16 *) 0xFFB6)->bit0
#define P10_OUT_P1                       ((T_Reg16 *) 0xFFB6)->bit1
#define P10_OUT_P10                      ((T_Reg16 *) 0xFFB6)->bit10
#define P10_OUT_P11                      ((T_Reg16 *) 0xFFB6)->bit11
#define P10_OUT_P12                      ((T_Reg16 *) 0xFFB6)->bit12
#define P10_OUT_P13                      ((T_Reg16 *) 0xFFB6)->bit13
#define P10_OUT_P14                      ((T_Reg16 *) 0xFFB6)->bit14
#define P10_OUT_P15                      ((T_Reg16 *) 0xFFB6)->bit15
#define P10_OUT_P2                       ((T_Reg16 *) 0xFFB6)->bit2
#define P10_OUT_P3                       ((T_Reg16 *) 0xFFB6)->bit3
#define P10_OUT_P4                       ((T_Reg16 *) 0xFFB6)->bit4
#define P10_OUT_P5                       ((T_Reg16 *) 0xFFB6)->bit5
#define P10_OUT_P6                       ((T_Reg16 *) 0xFFB6)->bit6
#define P10_OUT_P7                       ((T_Reg16 *) 0xFFB6)->bit7
#define P10_OUT_P8                       ((T_Reg16 *) 0xFFB6)->bit8
#define P10_OUT_P9                       ((T_Reg16 *) 0xFFB6)->bit9

// Port 10 Output Control Register
#define P10_POCON              (*((uword volatile *) 0xE8B4))

// Port 11 Input Register
#define P11_IN                 (*((uword volatile *) 0xFF96))
#define P11_IN_P0                       ((T_Reg16 *) 0xFF96)->bit0
#define P11_IN_P1                       ((T_Reg16 *) 0xFF96)->bit1
#define P11_IN_P10                      ((T_Reg16 *) 0xFF96)->bit10
#define P11_IN_P11                      ((T_Reg16 *) 0xFF96)->bit11
#define P11_IN_P12                      ((T_Reg16 *) 0xFF96)->bit12
#define P11_IN_P13                      ((T_Reg16 *) 0xFF96)->bit13
#define P11_IN_P14                      ((T_Reg16 *) 0xFF96)->bit14
#define P11_IN_P15                      ((T_Reg16 *) 0xFF96)->bit15
#define P11_IN_P2                       ((T_Reg16 *) 0xFF96)->bit2
#define P11_IN_P3                       ((T_Reg16 *) 0xFF96)->bit3
#define P11_IN_P4                       ((T_Reg16 *) 0xFF96)->bit4
#define P11_IN_P5                       ((T_Reg16 *) 0xFF96)->bit5
#define P11_IN_P6                       ((T_Reg16 *) 0xFF96)->bit6
#define P11_IN_P7                       ((T_Reg16 *) 0xFF96)->bit7
#define P11_IN_P8                       ((T_Reg16 *) 0xFF96)->bit8
#define P11_IN_P9                       ((T_Reg16 *) 0xFF96)->bit9

// Port 11 Input/Output Control Register 00
#define P11_IOCR00             (*((uword volatile *) 0xE960))

// Port 11 Input/Output Control Register 01
#define P11_IOCR01             (*((uword volatile *) 0xE962))

// Port 11 Input/Output Control Register 02
#define P11_IOCR02             (*((uword volatile *) 0xE964))

// Port 11 Input/Output Control Register 03
#define P11_IOCR03             (*((uword volatile *) 0xE966))

// Port 11 Input/Output Control Register 04
#define P11_IOCR04             (*((uword volatile *) 0xE968))

// Port 11 Input/Output Control Register 05
#define P11_IOCR05             (*((uword volatile *) 0xE96A))

// Port 11 Output Modification Register Low
#define P11_OMRL               (*((uword volatile *) 0xE9EC))

// Port 11 Output Register
#define P11_OUT                (*((uword volatile *) 0xFFB8))
#define P11_OUT_P0                       ((T_Reg16 *) 0xFFB8)->bit0
#define P11_OUT_P1                       ((T_Reg16 *) 0xFFB8)->bit1
#define P11_OUT_P10                      ((T_Reg16 *) 0xFFB8)->bit10
#define P11_OUT_P11                      ((T_Reg16 *) 0xFFB8)->bit11
#define P11_OUT_P12                      ((T_Reg16 *) 0xFFB8)->bit12
#define P11_OUT_P13                      ((T_Reg16 *) 0xFFB8)->bit13
#define P11_OUT_P14                      ((T_Reg16 *) 0xFFB8)->bit14
#define P11_OUT_P15                      ((T_Reg16 *) 0xFFB8)->bit15
#define P11_OUT_P2                       ((T_Reg16 *) 0xFFB8)->bit2
#define P11_OUT_P3                       ((T_Reg16 *) 0xFFB8)->bit3
#define P11_OUT_P4                       ((T_Reg16 *) 0xFFB8)->bit4
#define P11_OUT_P5                       ((T_Reg16 *) 0xFFB8)->bit5
#define P11_OUT_P6                       ((T_Reg16 *) 0xFFB8)->bit6
#define P11_OUT_P7                       ((T_Reg16 *) 0xFFB8)->bit7
#define P11_OUT_P8                       ((T_Reg16 *) 0xFFB8)->bit8
#define P11_OUT_P9                       ((T_Reg16 *) 0xFFB8)->bit9

// Port 11 Output Control Register
#define P11_POCON              (*((uword volatile *) 0xE8B6))

// Port 15 Digital Input Disable Register
#define P15_DIDIS              (*((uword volatile *) 0xFE9E))

// Port 15 Input Register
#define P15_IN                 (*((uword volatile *) 0xFF9E))
#define P15_IN_P0                       ((T_Reg16 *) 0xFF9E)->bit0
#define P15_IN_P1                       ((T_Reg16 *) 0xFF9E)->bit1
#define P15_IN_P10                      ((T_Reg16 *) 0xFF9E)->bit10
#define P15_IN_P11                      ((T_Reg16 *) 0xFF9E)->bit11
#define P15_IN_P12                      ((T_Reg16 *) 0xFF9E)->bit12
#define P15_IN_P13                      ((T_Reg16 *) 0xFF9E)->bit13
#define P15_IN_P14                      ((T_Reg16 *) 0xFF9E)->bit14
#define P15_IN_P15                      ((T_Reg16 *) 0xFF9E)->bit15
#define P15_IN_P2                       ((T_Reg16 *) 0xFF9E)->bit2
#define P15_IN_P3                       ((T_Reg16 *) 0xFF9E)->bit3
#define P15_IN_P4                       ((T_Reg16 *) 0xFF9E)->bit4
#define P15_IN_P5                       ((T_Reg16 *) 0xFF9E)->bit5
#define P15_IN_P6                       ((T_Reg16 *) 0xFF9E)->bit6
#define P15_IN_P7                       ((T_Reg16 *) 0xFF9E)->bit7
#define P15_IN_P8                       ((T_Reg16 *) 0xFF9E)->bit8
#define P15_IN_P9                       ((T_Reg16 *) 0xFF9E)->bit9

// Port 1 Input Register
#define P1_IN                  (*((uword volatile *) 0xFF82))
#define P1_IN_P0                       ((T_Reg16 *) 0xFF82)->bit0
#define P1_IN_P1                       ((T_Reg16 *) 0xFF82)->bit1
#define P1_IN_P10                      ((T_Reg16 *) 0xFF82)->bit10
#define P1_IN_P11                      ((T_Reg16 *) 0xFF82)->bit11
#define P1_IN_P12                      ((T_Reg16 *) 0xFF82)->bit12
#define P1_IN_P13                      ((T_Reg16 *) 0xFF82)->bit13
#define P1_IN_P14                      ((T_Reg16 *) 0xFF82)->bit14
#define P1_IN_P15                      ((T_Reg16 *) 0xFF82)->bit15
#define P1_IN_P2                       ((T_Reg16 *) 0xFF82)->bit2
#define P1_IN_P3                       ((T_Reg16 *) 0xFF82)->bit3
#define P1_IN_P4                       ((T_Reg16 *) 0xFF82)->bit4
#define P1_IN_P5                       ((T_Reg16 *) 0xFF82)->bit5
#define P1_IN_P6                       ((T_Reg16 *) 0xFF82)->bit6
#define P1_IN_P7                       ((T_Reg16 *) 0xFF82)->bit7
#define P1_IN_P8                       ((T_Reg16 *) 0xFF82)->bit8
#define P1_IN_P9                       ((T_Reg16 *) 0xFF82)->bit9

// Port 1 Input/Output Control Register 00
#define P1_IOCR00              (*((uword volatile *) 0xE820))

// Port 1 Input/Output Control Register 01
#define P1_IOCR01              (*((uword volatile *) 0xE822))

// Port 1 Input/Output Control Register 02
#define P1_IOCR02              (*((uword volatile *) 0xE824))

// Port 1 Input/Output Control Register 03
#define P1_IOCR03              (*((uword volatile *) 0xE826))

// Port 1 Input/Output Control Register 04
#define P1_IOCR04              (*((uword volatile *) 0xE828))

// Port 1 Input/Output Control Register 05
#define P1_IOCR05              (*((uword volatile *) 0xE82A))

// Port 1 Input/Output Control Register 06
#define P1_IOCR06              (*((uword volatile *) 0xE82C))

// Port 1 Input/Output Control Register 07
#define P1_IOCR07              (*((uword volatile *) 0xE82E))

// Port 1 Output Modification Register Low
#define P1_OMRL                (*((uword volatile *) 0xE9C4))

// Port 1 Output Register
#define P1_OUT                 (*((uword volatile *) 0xFFA4))
#define P1_OUT_P0                       ((T_Reg16 *) 0xFFA4)->bit0
#define P1_OUT_P1                       ((T_Reg16 *) 0xFFA4)->bit1
#define P1_OUT_P10                      ((T_Reg16 *) 0xFFA4)->bit10
#define P1_OUT_P11                      ((T_Reg16 *) 0xFFA4)->bit11
#define P1_OUT_P12                      ((T_Reg16 *) 0xFFA4)->bit12
#define P1_OUT_P13                      ((T_Reg16 *) 0xFFA4)->bit13
#define P1_OUT_P14                      ((T_Reg16 *) 0xFFA4)->bit14
#define P1_OUT_P15                      ((T_Reg16 *) 0xFFA4)->bit15
#define P1_OUT_P2                       ((T_Reg16 *) 0xFFA4)->bit2
#define P1_OUT_P3                       ((T_Reg16 *) 0xFFA4)->bit3
#define P1_OUT_P4                       ((T_Reg16 *) 0xFFA4)->bit4
#define P1_OUT_P5                       ((T_Reg16 *) 0xFFA4)->bit5
#define P1_OUT_P6                       ((T_Reg16 *) 0xFFA4)->bit6
#define P1_OUT_P7                       ((T_Reg16 *) 0xFFA4)->bit7
#define P1_OUT_P8                       ((T_Reg16 *) 0xFFA4)->bit8
#define P1_OUT_P9                       ((T_Reg16 *) 0xFFA4)->bit9

// Port 1 Output Control Register
#define P1_POCON               (*((uword volatile *) 0xE8A2))

// Port 2 Input Register
#define P2_IN                  (*((uword volatile *) 0xFF84))
#define P2_IN_P0                       ((T_Reg16 *) 0xFF84)->bit0
#define P2_IN_P1                       ((T_Reg16 *) 0xFF84)->bit1
#define P2_IN_P10                      ((T_Reg16 *) 0xFF84)->bit10
#define P2_IN_P11                      ((T_Reg16 *) 0xFF84)->bit11
#define P2_IN_P12                      ((T_Reg16 *) 0xFF84)->bit12
#define P2_IN_P13                      ((T_Reg16 *) 0xFF84)->bit13
#define P2_IN_P14                      ((T_Reg16 *) 0xFF84)->bit14
#define P2_IN_P15                      ((T_Reg16 *) 0xFF84)->bit15
#define P2_IN_P2                       ((T_Reg16 *) 0xFF84)->bit2
#define P2_IN_P3                       ((T_Reg16 *) 0xFF84)->bit3
#define P2_IN_P4                       ((T_Reg16 *) 0xFF84)->bit4
#define P2_IN_P5                       ((T_Reg16 *) 0xFF84)->bit5
#define P2_IN_P6                       ((T_Reg16 *) 0xFF84)->bit6
#define P2_IN_P7                       ((T_Reg16 *) 0xFF84)->bit7
#define P2_IN_P8                       ((T_Reg16 *) 0xFF84)->bit8
#define P2_IN_P9                       ((T_Reg16 *) 0xFF84)->bit9

// Port 2 Input/Output Control Register 00
#define P2_IOCR00              (*((uword volatile *) 0xE840))

// Port 2 Input/Output Control Register 01
#define P2_IOCR01              (*((uword volatile *) 0xE842))

// Port 2 Input/Output Control Register 02
#define P2_IOCR02              (*((uword volatile *) 0xE844))

// Port 2 Input/Output Control Register 03
#define P2_IOCR03              (*((uword volatile *) 0xE846))

// Port 2 Input/Output Control Register 04
#define P2_IOCR04              (*((uword volatile *) 0xE848))

// Port 2 Input/Output Control Register 05
#define P2_IOCR05              (*((uword volatile *) 0xE84A))

// Port 2 Input/Output Control Register 06
#define P2_IOCR06              (*((uword volatile *) 0xE84C))

// Port 2 Input/Output Control Register 07
#define P2_IOCR07              (*((uword volatile *) 0xE84E))

// Port 2 Input/Output Control Register 08
#define P2_IOCR08              (*((uword volatile *) 0xE850))

// Port 2 Input/Output Control Register 09
#define P2_IOCR09              (*((uword volatile *) 0xE852))

// Port 2 Input/Output Control Register 10
#define P2_IOCR10              (*((uword volatile *) 0xE854))

// Port 2 Input/Output Control Register 11
#define P2_IOCR11              (*((uword volatile *) 0xE856))

// Port 2 Input/Output Control Register 12
#define P2_IOCR12              (*((uword volatile *) 0xE858))

// Port 2 Input/Output Control Register 13
#define P2_IOCR13              (*((uword volatile *) 0xE85A))

// Port 2 Output Modification Register High
#define P2_OMRH                (*((uword volatile *) 0xE9CA))

// Port 2 Output Modification Register Low
#define P2_OMRL                (*((uword volatile *) 0xE9C8))

// Port 2 Output Register
#define P2_OUT                 (*((uword volatile *) 0xFFA6))
#define P2_OUT_P0                       ((T_Reg16 *) 0xFFA6)->bit0
#define P2_OUT_P1                       ((T_Reg16 *) 0xFFA6)->bit1
#define P2_OUT_P10                      ((T_Reg16 *) 0xFFA6)->bit10
#define P2_OUT_P11                      ((T_Reg16 *) 0xFFA6)->bit11
#define P2_OUT_P12                      ((T_Reg16 *) 0xFFA6)->bit12
#define P2_OUT_P13                      ((T_Reg16 *) 0xFFA6)->bit13
#define P2_OUT_P14                      ((T_Reg16 *) 0xFFA6)->bit14
#define P2_OUT_P15                      ((T_Reg16 *) 0xFFA6)->bit15
#define P2_OUT_P2                       ((T_Reg16 *) 0xFFA6)->bit2
#define P2_OUT_P3                       ((T_Reg16 *) 0xFFA6)->bit3
#define P2_OUT_P4                       ((T_Reg16 *) 0xFFA6)->bit4
#define P2_OUT_P5                       ((T_Reg16 *) 0xFFA6)->bit5
#define P2_OUT_P6                       ((T_Reg16 *) 0xFFA6)->bit6
#define P2_OUT_P7                       ((T_Reg16 *) 0xFFA6)->bit7
#define P2_OUT_P8                       ((T_Reg16 *) 0xFFA6)->bit8
#define P2_OUT_P9                       ((T_Reg16 *) 0xFFA6)->bit9

// Port 2 Output Control Register
#define P2_POCON               (*((uword volatile *) 0xE8A4))

// Port 3 Input Register
#define P3_IN                  (*((uword volatile *) 0xFF86))
#define P3_IN_P0                       ((T_Reg16 *) 0xFF86)->bit0
#define P3_IN_P1                       ((T_Reg16 *) 0xFF86)->bit1
#define P3_IN_P10                      ((T_Reg16 *) 0xFF86)->bit10
#define P3_IN_P11                      ((T_Reg16 *) 0xFF86)->bit11
#define P3_IN_P12                      ((T_Reg16 *) 0xFF86)->bit12
#define P3_IN_P13                      ((T_Reg16 *) 0xFF86)->bit13
#define P3_IN_P14                      ((T_Reg16 *) 0xFF86)->bit14
#define P3_IN_P15                      ((T_Reg16 *) 0xFF86)->bit15
#define P3_IN_P2                       ((T_Reg16 *) 0xFF86)->bit2
#define P3_IN_P3                       ((T_Reg16 *) 0xFF86)->bit3
#define P3_IN_P4                       ((T_Reg16 *) 0xFF86)->bit4
#define P3_IN_P5                       ((T_Reg16 *) 0xFF86)->bit5
#define P3_IN_P6                       ((T_Reg16 *) 0xFF86)->bit6
#define P3_IN_P7                       ((T_Reg16 *) 0xFF86)->bit7
#define P3_IN_P8                       ((T_Reg16 *) 0xFF86)->bit8
#define P3_IN_P9                       ((T_Reg16 *) 0xFF86)->bit9

// Port 3 Input/Output Control Register 00
#define P3_IOCR00              (*((uword volatile *) 0xE860))

// Port 3 Input/Output Control Register 01
#define P3_IOCR01              (*((uword volatile *) 0xE862))

// Port 3 Input/Output Control Register 02
#define P3_IOCR02              (*((uword volatile *) 0xE864))

// Port 3 Input/Output Control Register 03
#define P3_IOCR03              (*((uword volatile *) 0xE866))

// Port 3 Input/Output Control Register 04
#define P3_IOCR04              (*((uword volatile *) 0xE868))

// Port 3 Input/Output Control Register 05
#define P3_IOCR05              (*((uword volatile *) 0xE86A))

// Port 3 Input/Output Control Register 06
#define P3_IOCR06              (*((uword volatile *) 0xE86C))

// Port 3 Input/Output Control Register 07
#define P3_IOCR07              (*((uword volatile *) 0xE86E))

// Port 3 Output Modification Register Low
#define P3_OMRL                (*((uword volatile *) 0xE9CC))

// Port 3 Output Register
#define P3_OUT                 (*((uword volatile *) 0xFFA8))
#define P3_OUT_P0                       ((T_Reg16 *) 0xFFA8)->bit0
#define P3_OUT_P1                       ((T_Reg16 *) 0xFFA8)->bit1
#define P3_OUT_P10                      ((T_Reg16 *) 0xFFA8)->bit10
#define P3_OUT_P11                      ((T_Reg16 *) 0xFFA8)->bit11
#define P3_OUT_P12                      ((T_Reg16 *) 0xFFA8)->bit12
#define P3_OUT_P13                      ((T_Reg16 *) 0xFFA8)->bit13
#define P3_OUT_P14                      ((T_Reg16 *) 0xFFA8)->bit14
#define P3_OUT_P15                      ((T_Reg16 *) 0xFFA8)->bit15
#define P3_OUT_P2                       ((T_Reg16 *) 0xFFA8)->bit2
#define P3_OUT_P3                       ((T_Reg16 *) 0xFFA8)->bit3
#define P3_OUT_P4                       ((T_Reg16 *) 0xFFA8)->bit4
#define P3_OUT_P5                       ((T_Reg16 *) 0xFFA8)->bit5
#define P3_OUT_P6                       ((T_Reg16 *) 0xFFA8)->bit6
#define P3_OUT_P7                       ((T_Reg16 *) 0xFFA8)->bit7
#define P3_OUT_P8                       ((T_Reg16 *) 0xFFA8)->bit8
#define P3_OUT_P9                       ((T_Reg16 *) 0xFFA8)->bit9

// Port 3 Output Control Register
#define P3_POCON               (*((uword volatile *) 0xE8A6))

// Port 4 Input Register
#define P4_IN                  (*((uword volatile *) 0xFF88))
#define P4_IN_P0                       ((T_Reg16 *) 0xFF88)->bit0
#define P4_IN_P1                       ((T_Reg16 *) 0xFF88)->bit1
#define P4_IN_P10                      ((T_Reg16 *) 0xFF88)->bit10
#define P4_IN_P11                      ((T_Reg16 *) 0xFF88)->bit11
#define P4_IN_P12                      ((T_Reg16 *) 0xFF88)->bit12
#define P4_IN_P13                      ((T_Reg16 *) 0xFF88)->bit13
#define P4_IN_P14                      ((T_Reg16 *) 0xFF88)->bit14
#define P4_IN_P15                      ((T_Reg16 *) 0xFF88)->bit15
#define P4_IN_P2                       ((T_Reg16 *) 0xFF88)->bit2
#define P4_IN_P3                       ((T_Reg16 *) 0xFF88)->bit3
#define P4_IN_P4                       ((T_Reg16 *) 0xFF88)->bit4
#define P4_IN_P5                       ((T_Reg16 *) 0xFF88)->bit5
#define P4_IN_P6                       ((T_Reg16 *) 0xFF88)->bit6
#define P4_IN_P7                       ((T_Reg16 *) 0xFF88)->bit7
#define P4_IN_P8                       ((T_Reg16 *) 0xFF88)->bit8
#define P4_IN_P9                       ((T_Reg16 *) 0xFF88)->bit9

// Port 4 Input/Output Control Register 00
#define P4_IOCR00              (*((uword volatile *) 0xE880))

// Port 4 Input/Output Control Register 01
#define P4_IOCR01              (*((uword volatile *) 0xE882))

// Port 4 Input/Output Control Register 02
#define P4_IOCR02              (*((uword volatile *) 0xE884))

// Port 4 Input/Output Control Register 03
#define P4_IOCR03              (*((uword volatile *) 0xE886))

// Port 4 Input/Output Control Register 04
#define P4_IOCR04              (*((uword volatile *) 0xE888))

// Port 4 Input/Output Control Register 05
#define P4_IOCR05              (*((uword volatile *) 0xE88A))

// Port 4 Input/Output Control Register 06
#define P4_IOCR06              (*((uword volatile *) 0xE88C))

// Port 4 Input/Output Control Register 07
#define P4_IOCR07              (*((uword volatile *) 0xE88E))

// Port 4 Output Modification Register Low
#define P4_OMRL                (*((uword volatile *) 0xE9D0))

// Port 4 Output Register
#define P4_OUT                 (*((uword volatile *) 0xFFAA))
#define P4_OUT_P0                       ((T_Reg16 *) 0xFFAA)->bit0
#define P4_OUT_P1                       ((T_Reg16 *) 0xFFAA)->bit1
#define P4_OUT_P10                      ((T_Reg16 *) 0xFFAA)->bit10
#define P4_OUT_P11                      ((T_Reg16 *) 0xFFAA)->bit11
#define P4_OUT_P12                      ((T_Reg16 *) 0xFFAA)->bit12
#define P4_OUT_P13                      ((T_Reg16 *) 0xFFAA)->bit13
#define P4_OUT_P14                      ((T_Reg16 *) 0xFFAA)->bit14
#define P4_OUT_P15                      ((T_Reg16 *) 0xFFAA)->bit15
#define P4_OUT_P2                       ((T_Reg16 *) 0xFFAA)->bit2
#define P4_OUT_P3                       ((T_Reg16 *) 0xFFAA)->bit3
#define P4_OUT_P4                       ((T_Reg16 *) 0xFFAA)->bit4
#define P4_OUT_P5                       ((T_Reg16 *) 0xFFAA)->bit5
#define P4_OUT_P6                       ((T_Reg16 *) 0xFFAA)->bit6
#define P4_OUT_P7                       ((T_Reg16 *) 0xFFAA)->bit7
#define P4_OUT_P8                       ((T_Reg16 *) 0xFFAA)->bit8
#define P4_OUT_P9                       ((T_Reg16 *) 0xFFAA)->bit9

// Port 4 Output Control Register
#define P4_POCON               (*((uword volatile *) 0xE8A8))

// Port 5 Digital Input Disable Register
#define P5_DIDIS               (*((uword volatile *) 0xFE8A))

// Port 5 Input Register
#define P5_IN                  (*((uword volatile *) 0xFF8A))
#define P5_IN_P0                       ((T_Reg16 *) 0xFF8A)->bit0
#define P5_IN_P1                       ((T_Reg16 *) 0xFF8A)->bit1
#define P5_IN_P10                      ((T_Reg16 *) 0xFF8A)->bit10
#define P5_IN_P11                      ((T_Reg16 *) 0xFF8A)->bit11
#define P5_IN_P12                      ((T_Reg16 *) 0xFF8A)->bit12
#define P5_IN_P13                      ((T_Reg16 *) 0xFF8A)->bit13
#define P5_IN_P14                      ((T_Reg16 *) 0xFF8A)->bit14
#define P5_IN_P15                      ((T_Reg16 *) 0xFF8A)->bit15
#define P5_IN_P2                       ((T_Reg16 *) 0xFF8A)->bit2
#define P5_IN_P3                       ((T_Reg16 *) 0xFF8A)->bit3
#define P5_IN_P4                       ((T_Reg16 *) 0xFF8A)->bit4
#define P5_IN_P5                       ((T_Reg16 *) 0xFF8A)->bit5
#define P5_IN_P6                       ((T_Reg16 *) 0xFF8A)->bit6
#define P5_IN_P7                       ((T_Reg16 *) 0xFF8A)->bit7
#define P5_IN_P8                       ((T_Reg16 *) 0xFF8A)->bit8
#define P5_IN_P9                       ((T_Reg16 *) 0xFF8A)->bit9

// Port 6 Input Register
#define P6_IN                  (*((uword volatile *) 0xFF8C))
#define P6_IN_P0                       ((T_Reg16 *) 0xFF8C)->bit0
#define P6_IN_P1                       ((T_Reg16 *) 0xFF8C)->bit1
#define P6_IN_P10                      ((T_Reg16 *) 0xFF8C)->bit10
#define P6_IN_P11                      ((T_Reg16 *) 0xFF8C)->bit11
#define P6_IN_P12                      ((T_Reg16 *) 0xFF8C)->bit12
#define P6_IN_P13                      ((T_Reg16 *) 0xFF8C)->bit13
#define P6_IN_P14                      ((T_Reg16 *) 0xFF8C)->bit14
#define P6_IN_P15                      ((T_Reg16 *) 0xFF8C)->bit15
#define P6_IN_P2                       ((T_Reg16 *) 0xFF8C)->bit2
#define P6_IN_P3                       ((T_Reg16 *) 0xFF8C)->bit3
#define P6_IN_P4                       ((T_Reg16 *) 0xFF8C)->bit4
#define P6_IN_P5                       ((T_Reg16 *) 0xFF8C)->bit5
#define P6_IN_P6                       ((T_Reg16 *) 0xFF8C)->bit6
#define P6_IN_P7                       ((T_Reg16 *) 0xFF8C)->bit7
#define P6_IN_P8                       ((T_Reg16 *) 0xFF8C)->bit8
#define P6_IN_P9                       ((T_Reg16 *) 0xFF8C)->bit9

// Port 6 Input/Output Control Register 00
#define P6_IOCR00              (*((uword volatile *) 0xE8C0))

// Port 6 Input/Output Control Register 01
#define P6_IOCR01              (*((uword volatile *) 0xE8C2))

// Port 6 Input/Output Control Register 02
#define P6_IOCR02              (*((uword volatile *) 0xE8C4))

// Port 6 Input/Output Control Register 03
#define P6_IOCR03              (*((uword volatile *) 0xE8C6))

// Port 6 Output Modification Register Low
#define P6_OMRL                (*((uword volatile *) 0xE9D8))

// Port 6 Output Register
#define P6_OUT                 (*((uword volatile *) 0xFFAE))
#define P6_OUT_P0                       ((T_Reg16 *) 0xFFAE)->bit0
#define P6_OUT_P1                       ((T_Reg16 *) 0xFFAE)->bit1
#define P6_OUT_P10                      ((T_Reg16 *) 0xFFAE)->bit10
#define P6_OUT_P11                      ((T_Reg16 *) 0xFFAE)->bit11
#define P6_OUT_P12                      ((T_Reg16 *) 0xFFAE)->bit12
#define P6_OUT_P13                      ((T_Reg16 *) 0xFFAE)->bit13
#define P6_OUT_P14                      ((T_Reg16 *) 0xFFAE)->bit14
#define P6_OUT_P15                      ((T_Reg16 *) 0xFFAE)->bit15
#define P6_OUT_P2                       ((T_Reg16 *) 0xFFAE)->bit2
#define P6_OUT_P3                       ((T_Reg16 *) 0xFFAE)->bit3
#define P6_OUT_P4                       ((T_Reg16 *) 0xFFAE)->bit4
#define P6_OUT_P5                       ((T_Reg16 *) 0xFFAE)->bit5
#define P6_OUT_P6                       ((T_Reg16 *) 0xFFAE)->bit6
#define P6_OUT_P7                       ((T_Reg16 *) 0xFFAE)->bit7
#define P6_OUT_P8                       ((T_Reg16 *) 0xFFAE)->bit8
#define P6_OUT_P9                       ((T_Reg16 *) 0xFFAE)->bit9

// Port 6 Output Control Register
#define P6_POCON               (*((uword volatile *) 0xE8AC))

// Port 7 Input Register
#define P7_IN                  (*((uword volatile *) 0xFF8E))
#define P7_IN_P0                       ((T_Reg16 *) 0xFF8E)->bit0
#define P7_IN_P1                       ((T_Reg16 *) 0xFF8E)->bit1
#define P7_IN_P10                      ((T_Reg16 *) 0xFF8E)->bit10
#define P7_IN_P11                      ((T_Reg16 *) 0xFF8E)->bit11
#define P7_IN_P12                      ((T_Reg16 *) 0xFF8E)->bit12
#define P7_IN_P13                      ((T_Reg16 *) 0xFF8E)->bit13
#define P7_IN_P14                      ((T_Reg16 *) 0xFF8E)->bit14
#define P7_IN_P15                      ((T_Reg16 *) 0xFF8E)->bit15
#define P7_IN_P2                       ((T_Reg16 *) 0xFF8E)->bit2
#define P7_IN_P3                       ((T_Reg16 *) 0xFF8E)->bit3
#define P7_IN_P4                       ((T_Reg16 *) 0xFF8E)->bit4
#define P7_IN_P5                       ((T_Reg16 *) 0xFF8E)->bit5
#define P7_IN_P6                       ((T_Reg16 *) 0xFF8E)->bit6
#define P7_IN_P7                       ((T_Reg16 *) 0xFF8E)->bit7
#define P7_IN_P8                       ((T_Reg16 *) 0xFF8E)->bit8
#define P7_IN_P9                       ((T_Reg16 *) 0xFF8E)->bit9

// Port 7 Input/Output Control Register 00
#define P7_IOCR00              (*((uword volatile *) 0xE8E0))

// Port 7 Input/Output Control Register 01
#define P7_IOCR01              (*((uword volatile *) 0xE8E2))

// Port 7 Input/Output Control Register 02
#define P7_IOCR02              (*((uword volatile *) 0xE8E4))

// Port 7 Input/Output Control Register 03
#define P7_IOCR03              (*((uword volatile *) 0xE8E6))

// Port 7 Input/Output Control Register 04
#define P7_IOCR04              (*((uword volatile *) 0xE8E8))

// Port 7 Output Modification Register Low
#define P7_OMRL                (*((uword volatile *) 0xE9DC))

// Port 7 Output Register
#define P7_OUT                 (*((uword volatile *) 0xFFB0))
#define P7_OUT_P0                       ((T_Reg16 *) 0xFFB0)->bit0
#define P7_OUT_P1                       ((T_Reg16 *) 0xFFB0)->bit1
#define P7_OUT_P10                      ((T_Reg16 *) 0xFFB0)->bit10
#define P7_OUT_P11                      ((T_Reg16 *) 0xFFB0)->bit11
#define P7_OUT_P12                      ((T_Reg16 *) 0xFFB0)->bit12
#define P7_OUT_P13                      ((T_Reg16 *) 0xFFB0)->bit13
#define P7_OUT_P14                      ((T_Reg16 *) 0xFFB0)->bit14
#define P7_OUT_P15                      ((T_Reg16 *) 0xFFB0)->bit15
#define P7_OUT_P2                       ((T_Reg16 *) 0xFFB0)->bit2
#define P7_OUT_P3                       ((T_Reg16 *) 0xFFB0)->bit3
#define P7_OUT_P4                       ((T_Reg16 *) 0xFFB0)->bit4
#define P7_OUT_P5                       ((T_Reg16 *) 0xFFB0)->bit5
#define P7_OUT_P6                       ((T_Reg16 *) 0xFFB0)->bit6
#define P7_OUT_P7                       ((T_Reg16 *) 0xFFB0)->bit7
#define P7_OUT_P8                       ((T_Reg16 *) 0xFFB0)->bit8
#define P7_OUT_P9                       ((T_Reg16 *) 0xFFB0)->bit9

// Port 7 Output Control Register
#define P7_POCON               (*((uword volatile *) 0xE8AE))

// Port 8 Input Register
#define P8_IN                  (*((uword volatile *) 0xFF90))
#define P8_IN_P0                       ((T_Reg16 *) 0xFF90)->bit0
#define P8_IN_P1                       ((T_Reg16 *) 0xFF90)->bit1
#define P8_IN_P10                      ((T_Reg16 *) 0xFF90)->bit10
#define P8_IN_P11                      ((T_Reg16 *) 0xFF90)->bit11
#define P8_IN_P12                      ((T_Reg16 *) 0xFF90)->bit12
#define P8_IN_P13                      ((T_Reg16 *) 0xFF90)->bit13
#define P8_IN_P14                      ((T_Reg16 *) 0xFF90)->bit14
#define P8_IN_P15                      ((T_Reg16 *) 0xFF90)->bit15
#define P8_IN_P2                       ((T_Reg16 *) 0xFF90)->bit2
#define P8_IN_P3                       ((T_Reg16 *) 0xFF90)->bit3
#define P8_IN_P4                       ((T_Reg16 *) 0xFF90)->bit4
#define P8_IN_P5                       ((T_Reg16 *) 0xFF90)->bit5
#define P8_IN_P6                       ((T_Reg16 *) 0xFF90)->bit6
#define P8_IN_P7                       ((T_Reg16 *) 0xFF90)->bit7
#define P8_IN_P8                       ((T_Reg16 *) 0xFF90)->bit8
#define P8_IN_P9                       ((T_Reg16 *) 0xFF90)->bit9

// Port 8 Input/Output Control Register 00
#define P8_IOCR00              (*((uword volatile *) 0xE900))

// Port 8 Input/Output Control Register 01
#define P8_IOCR01              (*((uword volatile *) 0xE902))

// Port 8 Input/Output Control Register 02
#define P8_IOCR02              (*((uword volatile *) 0xE904))

// Port 8 Input/Output Control Register 03
#define P8_IOCR03              (*((uword volatile *) 0xE906))

// Port 8 Input/Output Control Register 04
#define P8_IOCR04              (*((uword volatile *) 0xE908))

// Port 8 Input/Output Control Register 05
#define P8_IOCR05              (*((uword volatile *) 0xE90A))

// Port 8 Input/Output Control Register 06
#define P8_IOCR06              (*((uword volatile *) 0xE90C))

// Port 8 Output Modification Register Low
#define P8_OMRL                (*((uword volatile *) 0xE9E0))

// Port 8 Output Register
#define P8_OUT                 (*((uword volatile *) 0xFFB2))
#define P8_OUT_P0                       ((T_Reg16 *) 0xFFB2)->bit0
#define P8_OUT_P1                       ((T_Reg16 *) 0xFFB2)->bit1
#define P8_OUT_P10                      ((T_Reg16 *) 0xFFB2)->bit10
#define P8_OUT_P11                      ((T_Reg16 *) 0xFFB2)->bit11
#define P8_OUT_P12                      ((T_Reg16 *) 0xFFB2)->bit12
#define P8_OUT_P13                      ((T_Reg16 *) 0xFFB2)->bit13
#define P8_OUT_P14                      ((T_Reg16 *) 0xFFB2)->bit14
#define P8_OUT_P15                      ((T_Reg16 *) 0xFFB2)->bit15
#define P8_OUT_P2                       ((T_Reg16 *) 0xFFB2)->bit2
#define P8_OUT_P3                       ((T_Reg16 *) 0xFFB2)->bit3
#define P8_OUT_P4                       ((T_Reg16 *) 0xFFB2)->bit4
#define P8_OUT_P5                       ((T_Reg16 *) 0xFFB2)->bit5
#define P8_OUT_P6                       ((T_Reg16 *) 0xFFB2)->bit6
#define P8_OUT_P7                       ((T_Reg16 *) 0xFFB2)->bit7
#define P8_OUT_P8                       ((T_Reg16 *) 0xFFB2)->bit8
#define P8_OUT_P9                       ((T_Reg16 *) 0xFFB2)->bit9

// Port 8 Output Control Register
#define P8_POCON               (*((uword volatile *) 0xE8B0))

// Port 9 Input Register
#define P9_IN                  (*((uword volatile *) 0xFF92))
#define P9_IN_P0                       ((T_Reg16 *) 0xFF92)->bit0
#define P9_IN_P1                       ((T_Reg16 *) 0xFF92)->bit1
#define P9_IN_P10                      ((T_Reg16 *) 0xFF92)->bit10
#define P9_IN_P11                      ((T_Reg16 *) 0xFF92)->bit11
#define P9_IN_P12                      ((T_Reg16 *) 0xFF92)->bit12
#define P9_IN_P13                      ((T_Reg16 *) 0xFF92)->bit13
#define P9_IN_P14                      ((T_Reg16 *) 0xFF92)->bit14
#define P9_IN_P15                      ((T_Reg16 *) 0xFF92)->bit15
#define P9_IN_P2                       ((T_Reg16 *) 0xFF92)->bit2
#define P9_IN_P3                       ((T_Reg16 *) 0xFF92)->bit3
#define P9_IN_P4                       ((T_Reg16 *) 0xFF92)->bit4
#define P9_IN_P5                       ((T_Reg16 *) 0xFF92)->bit5
#define P9_IN_P6                       ((T_Reg16 *) 0xFF92)->bit6
#define P9_IN_P7                       ((T_Reg16 *) 0xFF92)->bit7
#define P9_IN_P8                       ((T_Reg16 *) 0xFF92)->bit8
#define P9_IN_P9                       ((T_Reg16 *) 0xFF92)->bit9

// Port 9 Input/Output Control Register 00
#define P9_IOCR00              (*((uword volatile *) 0xE920))

// Port 9 Input/Output Control Register 01
#define P9_IOCR01              (*((uword volatile *) 0xE922))

// Port 9 Input/Output Control Register 02
#define P9_IOCR02              (*((uword volatile *) 0xE924))

// Port 9 Input/Output Control Register 03
#define P9_IOCR03              (*((uword volatile *) 0xE926))

// Port 9 Input/Output Control Register 04
#define P9_IOCR04              (*((uword volatile *) 0xE928))

// Port 9 Input/Output Control Register 05
#define P9_IOCR05              (*((uword volatile *) 0xE92A))

// Port 9 Input/Output Control Register 06
#define P9_IOCR06              (*((uword volatile *) 0xE92C))

// Port 9 Input/Output Control Register 07
#define P9_IOCR07              (*((uword volatile *) 0xE92E))

// Port 9 Output Modification Register Low
#define P9_OMRL                (*((uword volatile *) 0xE9E4))

// Port 9 Output Register
#define P9_OUT                 (*((uword volatile *) 0xFFB4))
#define P9_OUT_P0                       ((T_Reg16 *) 0xFFB4)->bit0
#define P9_OUT_P1                       ((T_Reg16 *) 0xFFB4)->bit1
#define P9_OUT_P10                      ((T_Reg16 *) 0xFFB4)->bit10
#define P9_OUT_P11                      ((T_Reg16 *) 0xFFB4)->bit11
#define P9_OUT_P12                      ((T_Reg16 *) 0xFFB4)->bit12
#define P9_OUT_P13                      ((T_Reg16 *) 0xFFB4)->bit13
#define P9_OUT_P14                      ((T_Reg16 *) 0xFFB4)->bit14
#define P9_OUT_P15                      ((T_Reg16 *) 0xFFB4)->bit15
#define P9_OUT_P2                       ((T_Reg16 *) 0xFFB4)->bit2
#define P9_OUT_P3                       ((T_Reg16 *) 0xFFB4)->bit3
#define P9_OUT_P4                       ((T_Reg16 *) 0xFFB4)->bit4
#define P9_OUT_P5                       ((T_Reg16 *) 0xFFB4)->bit5
#define P9_OUT_P6                       ((T_Reg16 *) 0xFFB4)->bit6
#define P9_OUT_P7                       ((T_Reg16 *) 0xFFB4)->bit7
#define P9_OUT_P8                       ((T_Reg16 *) 0xFFB4)->bit8
#define P9_OUT_P9                       ((T_Reg16 *) 0xFFB4)->bit9

// Port 9 Output Control Register
#define P9_POCON               (*((uword volatile *) 0xE8B2))

// PEC Channel Control Reg. 0
#define PECC0                  (*((uword volatile *) 0xFEC0))

// PEC Channel Control Reg. 1
#define PECC1                  (*((uword volatile *) 0xFEC2))

// PEC Channel Control Reg. 2
#define PECC2                  (*((uword volatile *) 0xFEC4))

// PEC Channel Control Reg. 3
#define PECC3                  (*((uword volatile *) 0xFEC6))

// PEC Channel Control Reg. 4
#define PECC4                  (*((uword volatile *) 0xFEC8))

// PEC Channel Control Reg. 5
#define PECC5                  (*((uword volatile *) 0xFECA))

// PEC Channel Control Reg. 6
#define PECC6                  (*((uword volatile *) 0xFECC))

// PEC Channel Control Reg. 7
#define PECC7                  (*((uword volatile *) 0xFECE))

// PEC Intr. Sub Node Control
#define PECISNC                (*((uword volatile *) 0xFFD8))
#define PECISNC_C0IE                     ((T_Reg16 *) 0xFFD8)->bit0
#define PECISNC_C0IR                     ((T_Reg16 *) 0xFFD8)->bit1
#define PECISNC_C1IE                     ((T_Reg16 *) 0xFFD8)->bit2
#define PECISNC_C1IR                     ((T_Reg16 *) 0xFFD8)->bit3
#define PECISNC_C2IE                     ((T_Reg16 *) 0xFFD8)->bit4
#define PECISNC_C2IR                     ((T_Reg16 *) 0xFFD8)->bit5
#define PECISNC_C3IE                     ((T_Reg16 *) 0xFFD8)->bit6
#define PECISNC_C3IR                     ((T_Reg16 *) 0xFFD8)->bit7
#define PECISNC_C4IE                     ((T_Reg16 *) 0xFFD8)->bit8
#define PECISNC_C4IR                     ((T_Reg16 *) 0xFFD8)->bit9
#define PECISNC_C5IE                     ((T_Reg16 *) 0xFFD8)->bit10
#define PECISNC_C5IR                     ((T_Reg16 *) 0xFFD8)->bit11
#define PECISNC_C6IE                     ((T_Reg16 *) 0xFFD8)->bit12
#define PECISNC_C6IR                     ((T_Reg16 *) 0xFFD8)->bit13
#define PECISNC_C7IE                     ((T_Reg16 *) 0xFFD8)->bit14
#define PECISNC_C7IR                     ((T_Reg16 *) 0xFFD8)->bit15

// PEC Segment Pointer 0
#define PECSEG0                (*((uword volatile *) 0xEC80))

// PEC Segment Pointer 1
#define PECSEG1                (*((uword volatile *) 0xEC82))

// PEC Segment Pointer 2
#define PECSEG2                (*((uword volatile *) 0xEC84))

// PEC Segment Pointer 3
#define PECSEG3                (*((uword volatile *) 0xEC86))

// PEC Segment Pointer 4
#define PECSEG4                (*((uword volatile *) 0xEC88))

// PEC Segment Pointer 5
#define PECSEG5                (*((uword volatile *) 0xEC8A))

// PEC Segment Pointer 6
#define PECSEG6                (*((uword volatile *) 0xEC8C))

// PEC Segment Pointer 7
#define PECSEG7                (*((uword volatile *) 0xEC8E))

// Program Flash Interrupt
#define PFM_IC                 (*((uword volatile *) 0xF19A))
#define PFM_IC_GPX                      ((T_Reg16 *) 0xF19A)->bit8
#define PFM_IC_IE                       ((T_Reg16 *) 0xF19A)->bit6
#define PFM_IC_IR                       ((T_Reg16 *) 0xF19A)->bit7

// Processor Status Word
#define PSW                    (*((uword volatile *) 0xFF10))
#define PSW_C                        ((T_Reg16 *) 0xFF10)->bit1
#define PSW_E                        ((T_Reg16 *) 0xFF10)->bit4
#define PSW_HLDEN_PL1                ((T_Reg16 *) 0xFF10)->bit10
#define PSW_IEN                      ((T_Reg16 *) 0xFF10)->bit11
#define PSW_N                        ((T_Reg16 *) 0xFF10)->bit0
#define PSW_PL0                      ((T_Reg16 *) 0xFF10)->bit5
#define PSW_USR0                     ((T_Reg16 *) 0xFF10)->bit6
#define PSW_USR1                     ((T_Reg16 *) 0xFF10)->bit7
#define PSW_V                        ((T_Reg16 *) 0xFF10)->bit2
#define PSW_Z                        ((T_Reg16 *) 0xFF10)->bit3

// Offset Register
#define QR0                    (*((uword volatile *) 0xF004))

// Offset Register
#define QR1                    (*((uword volatile *) 0xF006))

// Offset Register
#define QX0                    (*((uword volatile *) 0xF000))

// Offset Register
#define QX1                    (*((uword volatile *) 0xF002))

// Control Register
#define RTC_CON                (*((uword volatile *) 0xF110))
#define RTC_CON_ACCPOS                   ((T_Reg16 *) 0xF110)->bit15
#define RTC_CON_PRE                      ((T_Reg16 *) 0xF110)->bit1
#define RTC_CON_REFCLK                   ((T_Reg16 *) 0xF110)->bit4
#define RTC_CON_RUN                      ((T_Reg16 *) 0xF110)->bit0
#define RTC_CON_T14DEC                   ((T_Reg16 *) 0xF110)->bit2
#define RTC_CON_T14INC                   ((T_Reg16 *) 0xF110)->bit3

// Real Time Clock Interrupt
#define RTC_IC                 (*((uword volatile *) 0xF19C))
#define RTC_IC_GPX                      ((T_Reg16 *) 0xF19C)->bit8
#define RTC_IC_IE                       ((T_Reg16 *) 0xF19C)->bit6
#define RTC_IC_IR                       ((T_Reg16 *) 0xF19C)->bit7

// Identification Register
#define RTC_ID                 (*((uword volatile *) 0xFFF8))

// Interrupt Sub Node Control
#define RTC_ISNC               (*((uword volatile *) 0xF10C))
#define RTC_ISNC_CNT0IE                   ((T_Reg16 *) 0xF10C)->bit2
#define RTC_ISNC_CNT0IR                   ((T_Reg16 *) 0xF10C)->bit3
#define RTC_ISNC_CNT1IE                   ((T_Reg16 *) 0xF10C)->bit4
#define RTC_ISNC_CNT1IR                   ((T_Reg16 *) 0xF10C)->bit5
#define RTC_ISNC_CNT2IE                   ((T_Reg16 *) 0xF10C)->bit6
#define RTC_ISNC_CNT2IR                   ((T_Reg16 *) 0xF10C)->bit7
#define RTC_ISNC_CNT3IE                   ((T_Reg16 *) 0xF10C)->bit8
#define RTC_ISNC_CNT3IR                   ((T_Reg16 *) 0xF10C)->bit9
#define RTC_ISNC_T14IE                    ((T_Reg16 *) 0xF10C)->bit0
#define RTC_ISNC_T14IR                    ((T_Reg16 *) 0xF10C)->bit1

// RTC Kernel State Con. Register
#define RTC_KSCCFG             (*((uword volatile *) 0xF010))

// RTC Reload Register High
#define RTC_RELH               (*((uword volatile *) 0xF0CE))

// RTC Reload Register Low
#define RTC_RELL               (*((uword volatile *) 0xF0CC))

// RTC Count Register High
#define RTC_RTCH               (*((uword volatile *) 0xF0D6))

// RTC Count Register Low
#define RTC_RTCL               (*((uword volatile *) 0xF0D4))

// T14 Count Register
#define RTC_T14                (*((uword volatile *) 0xF0D2))

// T14 Reload Register
#define RTC_T14REL             (*((uword volatile *) 0xF0D0))

// Data Register in RW Mode
#define RWDATA                 (*((uword volatile *) 0xF06A))

// SBRAM Data Register 0
#define SBRAM_DATA0            (*((uword volatile *) 0xFEE0))

// SBRAM Data Register 0
#define SBRAM_DATA0            (*((uword volatile *) 0xFEE0))

// SBRAM Data Register 1
#define SBRAM_DATA1            (*((uword volatile *) 0xFEE2))

// SBRAM Data Register 1
#define SBRAM_DATA1            (*((uword volatile *) 0xFEE2))

// SBRAM Read Address Register
#define SBRAM_RADD             (*((uword volatile *) 0xFEDC))

// SBRAM Read Address Reg.
#define SBRAM_RADD             (*((uword volatile *) 0xFEDC))

// SBRAM Write Address Register
#define SBRAM_WADD             (*((uword volatile *) 0xFEDE))

// SBRAM Write Address Reg.
#define SBRAM_WADD             (*((uword volatile *) 0xFEDE))

// SCU 0
#define SCU_0IC                (*((uword volatile *) 0xF198))
#define SCU_0IC_GPX                      ((T_Reg16 *) 0xF198)->bit8
#define SCU_0IC_IE                       ((T_Reg16 *) 0xF198)->bit6
#define SCU_0IC_IR                       ((T_Reg16 *) 0xF198)->bit7

// SCU 1
#define SCU_1IC                (*((uword volatile *) 0xF196))
#define SCU_1IC_GPX                      ((T_Reg16 *) 0xF196)->bit8
#define SCU_1IC_IE                       ((T_Reg16 *) 0xF196)->bit6
#define SCU_1IC_IR                       ((T_Reg16 *) 0xF196)->bit7

// Clear ESR1 External Status Register
#define SCU_CLRESREXSTAT1      (*((uword volatile *) 0xFF3A))
#define SCU_CLRESREXSTAT1_ESR                      ((T_Reg16 *) 0xFF3A)->bit0
#define SCU_CLRESREXSTAT1_IN0                      ((T_Reg16 *) 0xFF3A)->bit1
#define SCU_CLRESREXSTAT1_IN1                      ((T_Reg16 *) 0xFF3A)->bit2
#define SCU_CLRESREXSTAT1_IN10                     ((T_Reg16 *) 0xFF3A)->bit11
#define SCU_CLRESREXSTAT1_IN11                     ((T_Reg16 *) 0xFF3A)->bit12
#define SCU_CLRESREXSTAT1_IN2                      ((T_Reg16 *) 0xFF3A)->bit3
#define SCU_CLRESREXSTAT1_IN3                      ((T_Reg16 *) 0xFF3A)->bit4
#define SCU_CLRESREXSTAT1_IN4                      ((T_Reg16 *) 0xFF3A)->bit5
#define SCU_CLRESREXSTAT1_IN5                      ((T_Reg16 *) 0xFF3A)->bit6
#define SCU_CLRESREXSTAT1_IN6                      ((T_Reg16 *) 0xFF3A)->bit7
#define SCU_CLRESREXSTAT1_IN7                      ((T_Reg16 *) 0xFF3A)->bit8
#define SCU_CLRESREXSTAT1_IN8                      ((T_Reg16 *) 0xFF3A)->bit9
#define SCU_CLRESREXSTAT1_IN9                      ((T_Reg16 *) 0xFF3A)->bit10

// Clear ESR2 External Status Register
#define SCU_CLRESREXSTAT2      (*((uword volatile *) 0xFF3C))
#define SCU_CLRESREXSTAT2_ESR                      ((T_Reg16 *) 0xFF3C)->bit0
#define SCU_CLRESREXSTAT2_IN0                      ((T_Reg16 *) 0xFF3C)->bit1
#define SCU_CLRESREXSTAT2_IN1                      ((T_Reg16 *) 0xFF3C)->bit2
#define SCU_CLRESREXSTAT2_IN10                     ((T_Reg16 *) 0xFF3C)->bit11
#define SCU_CLRESREXSTAT2_IN11                     ((T_Reg16 *) 0xFF3C)->bit12
#define SCU_CLRESREXSTAT2_IN2                      ((T_Reg16 *) 0xFF3C)->bit3
#define SCU_CLRESREXSTAT2_IN3                      ((T_Reg16 *) 0xFF3C)->bit4
#define SCU_CLRESREXSTAT2_IN4                      ((T_Reg16 *) 0xFF3C)->bit5
#define SCU_CLRESREXSTAT2_IN5                      ((T_Reg16 *) 0xFF3C)->bit6
#define SCU_CLRESREXSTAT2_IN6                      ((T_Reg16 *) 0xFF3C)->bit7
#define SCU_CLRESREXSTAT2_IN7                      ((T_Reg16 *) 0xFF3C)->bit8
#define SCU_CLRESREXSTAT2_IN8                      ((T_Reg16 *) 0xFF3C)->bit9
#define SCU_CLRESREXSTAT2_IN9                      ((T_Reg16 *) 0xFF3C)->bit10

// Debug Pin Routing Register
#define SCU_DBGPRR             (*((uword volatile *) 0xF06E))

// DMP_M Int. and Trap Trigger Register
#define SCU_DMPMIT             (*((uword volatile *) 0xFE96))

// DMP_M Int. and Trap Clear Register
#define SCU_DMPMITCLR          (*((uword volatile *) 0xFE98))

// ECC Clear Status Register
#define SCU_ECCCLRSTAT         (*((uword volatile *) 0xF0DE))

// ECC Control Register
#define SCU_ECCCON             (*((uword volatile *) 0xF0A8))

// ECC Status Register
#define SCU_ECCSTAT            (*((uword volatile *) 0xF0AA))

// SCU External Request 0
#define SCU_ERU_0IC            (*((uword volatile *) 0xF190))
#define SCU_ERU_0IC_GPX                      ((T_Reg16 *) 0xF190)->bit8
#define SCU_ERU_0IC_IE                       ((T_Reg16 *) 0xF190)->bit6
#define SCU_ERU_0IC_IR                       ((T_Reg16 *) 0xF190)->bit7

// SCU External Request 1
#define SCU_ERU_1IC            (*((uword volatile *) 0xF192))
#define SCU_ERU_1IC_GPX                      ((T_Reg16 *) 0xF192)->bit8
#define SCU_ERU_1IC_IE                       ((T_Reg16 *) 0xF192)->bit6
#define SCU_ERU_1IC_IR                       ((T_Reg16 *) 0xF192)->bit7

// SCU External Request 2
#define SCU_ERU_2IC            (*((uword volatile *) 0xF194))
#define SCU_ERU_2IC_GPX                      ((T_Reg16 *) 0xF194)->bit8
#define SCU_ERU_2IC_IE                       ((T_Reg16 *) 0xF194)->bit6
#define SCU_ERU_2IC_IR                       ((T_Reg16 *) 0xF194)->bit7

// SCU External Request 1
#define SCU_ERU_3IC            (*((uword volatile *) 0xF19A))
#define SCU_ERU_3IC_GPX                      ((T_Reg16 *) 0xF19A)->bit8
#define SCU_ERU_3IC_IE                       ((T_Reg16 *) 0xF19A)->bit6
#define SCU_ERU_3IC_IR                       ((T_Reg16 *) 0xF19A)->bit7

// ESR0 Configuration Register
#define SCU_ESRCFG0            (*((uword volatile *) 0xF100))
#define SCU_ESRCFG0_DFEN                     ((T_Reg16 *) 0xF100)->bit4
#define SCU_ESRCFG0_IN                       ((T_Reg16 *) 0xF100)->bit6
#define SCU_ESRCFG0_OUT                      ((T_Reg16 *) 0xF100)->bit5

// ESR1 Configuration Register
#define SCU_ESRCFG1            (*((uword volatile *) 0xF102))
#define SCU_ESRCFG1_DFEN                     ((T_Reg16 *) 0xF102)->bit4
#define SCU_ESRCFG1_IN                       ((T_Reg16 *) 0xF102)->bit6
#define SCU_ESRCFG1_OUT                      ((T_Reg16 *) 0xF102)->bit5

// ESR2 Configuration Register
#define SCU_ESRCFG2            (*((uword volatile *) 0xF104))
#define SCU_ESRCFG2_DFEN                     ((T_Reg16 *) 0xF104)->bit4
#define SCU_ESRCFG2_IN                       ((T_Reg16 *) 0xF104)->bit6
#define SCU_ESRCFG2_OUT                      ((T_Reg16 *) 0xF104)->bit5

// ESR Data Register
#define SCU_ESRDAT             (*((uword volatile *) 0xF106))

// ESR1 External Control Register
#define SCU_ESREXCON1          (*((uword volatile *) 0xFF32))
#define SCU_ESREXCON1_ESREN                    ((T_Reg16 *) 0xFF32)->bit0
#define SCU_ESREXCON1_ESRIN0EN                 ((T_Reg16 *) 0xFF32)->bit1
#define SCU_ESREXCON1_ESRIN10EN                ((T_Reg16 *) 0xFF32)->bit11
#define SCU_ESREXCON1_ESRIN11EN                ((T_Reg16 *) 0xFF32)->bit12
#define SCU_ESREXCON1_ESRIN12EN                ((T_Reg16 *) 0xFF32)->bit13
#define SCU_ESREXCON1_ESRIN1EN                 ((T_Reg16 *) 0xFF32)->bit2
#define SCU_ESREXCON1_ESRIN2EN                 ((T_Reg16 *) 0xFF32)->bit3
#define SCU_ESREXCON1_ESRIN3EN                 ((T_Reg16 *) 0xFF32)->bit4
#define SCU_ESREXCON1_ESRIN4EN                 ((T_Reg16 *) 0xFF32)->bit5
#define SCU_ESREXCON1_ESRIN5EN                 ((T_Reg16 *) 0xFF32)->bit6
#define SCU_ESREXCON1_ESRIN6EN                 ((T_Reg16 *) 0xFF32)->bit7
#define SCU_ESREXCON1_ESRIN7EN                 ((T_Reg16 *) 0xFF32)->bit8
#define SCU_ESREXCON1_ESRIN8EN                 ((T_Reg16 *) 0xFF32)->bit9
#define SCU_ESREXCON1_ESRIN9EN                 ((T_Reg16 *) 0xFF32)->bit10
#define SCU_ESREXCON1_ESRNIN10EN               ((T_Reg16 *) 0xFF32)->bit14
#define SCU_ESREXCON1_ESRNIN11EN               ((T_Reg16 *) 0xFF32)->bit15

// ESR2 External Control Register
#define SCU_ESREXCON2          (*((uword volatile *) 0xFF34))
#define SCU_ESREXCON2_ESREN                    ((T_Reg16 *) 0xFF34)->bit0
#define SCU_ESREXCON2_ESRIN0EN                 ((T_Reg16 *) 0xFF34)->bit1
#define SCU_ESREXCON2_ESRIN10EN                ((T_Reg16 *) 0xFF34)->bit11
#define SCU_ESREXCON2_ESRIN11EN                ((T_Reg16 *) 0xFF34)->bit12
#define SCU_ESREXCON2_ESRIN12EN                ((T_Reg16 *) 0xFF34)->bit13
#define SCU_ESREXCON2_ESRIN1EN                 ((T_Reg16 *) 0xFF34)->bit2
#define SCU_ESREXCON2_ESRIN2EN                 ((T_Reg16 *) 0xFF34)->bit3
#define SCU_ESREXCON2_ESRIN3EN                 ((T_Reg16 *) 0xFF34)->bit4
#define SCU_ESREXCON2_ESRIN4EN                 ((T_Reg16 *) 0xFF34)->bit5
#define SCU_ESREXCON2_ESRIN5EN                 ((T_Reg16 *) 0xFF34)->bit6
#define SCU_ESREXCON2_ESRIN6EN                 ((T_Reg16 *) 0xFF34)->bit7
#define SCU_ESREXCON2_ESRIN7EN                 ((T_Reg16 *) 0xFF34)->bit8
#define SCU_ESREXCON2_ESRIN8EN                 ((T_Reg16 *) 0xFF34)->bit9
#define SCU_ESREXCON2_ESRIN9EN                 ((T_Reg16 *) 0xFF34)->bit10
#define SCU_ESREXCON2_ESRNIN10EN               ((T_Reg16 *) 0xFF34)->bit14
#define SCU_ESREXCON2_ESRNIN11EN               ((T_Reg16 *) 0xFF34)->bit15

// ESR1 External Status Register
#define SCU_ESREXSTAT1         (*((uword volatile *) 0xFF36))
#define SCU_ESREXSTAT1_ESR                      ((T_Reg16 *) 0xFF36)->bit0
#define SCU_ESREXSTAT1_IN0                      ((T_Reg16 *) 0xFF36)->bit1
#define SCU_ESREXSTAT1_IN1                      ((T_Reg16 *) 0xFF36)->bit2
#define SCU_ESREXSTAT1_IN10                     ((T_Reg16 *) 0xFF36)->bit11
#define SCU_ESREXSTAT1_IN11                     ((T_Reg16 *) 0xFF36)->bit12
#define SCU_ESREXSTAT1_IN2                      ((T_Reg16 *) 0xFF36)->bit3
#define SCU_ESREXSTAT1_IN3                      ((T_Reg16 *) 0xFF36)->bit4
#define SCU_ESREXSTAT1_IN4                      ((T_Reg16 *) 0xFF36)->bit5
#define SCU_ESREXSTAT1_IN5                      ((T_Reg16 *) 0xFF36)->bit6
#define SCU_ESREXSTAT1_IN6                      ((T_Reg16 *) 0xFF36)->bit7
#define SCU_ESREXSTAT1_IN7                      ((T_Reg16 *) 0xFF36)->bit8
#define SCU_ESREXSTAT1_IN8                      ((T_Reg16 *) 0xFF36)->bit9
#define SCU_ESREXSTAT1_IN9                      ((T_Reg16 *) 0xFF36)->bit10

// ESR2 External Status Register
#define SCU_ESREXSTAT2         (*((uword volatile *) 0xFF38))
#define SCU_ESREXSTAT2_ESR                      ((T_Reg16 *) 0xFF38)->bit0
#define SCU_ESREXSTAT2_IN0                      ((T_Reg16 *) 0xFF38)->bit1
#define SCU_ESREXSTAT2_IN1                      ((T_Reg16 *) 0xFF38)->bit2
#define SCU_ESREXSTAT2_IN10                     ((T_Reg16 *) 0xFF38)->bit11
#define SCU_ESREXSTAT2_IN11                     ((T_Reg16 *) 0xFF38)->bit12
#define SCU_ESREXSTAT2_IN2                      ((T_Reg16 *) 0xFF38)->bit3
#define SCU_ESREXSTAT2_IN3                      ((T_Reg16 *) 0xFF38)->bit4
#define SCU_ESREXSTAT2_IN4                      ((T_Reg16 *) 0xFF38)->bit5
#define SCU_ESREXSTAT2_IN5                      ((T_Reg16 *) 0xFF38)->bit6
#define SCU_ESREXSTAT2_IN6                      ((T_Reg16 *) 0xFF38)->bit7
#define SCU_ESREXSTAT2_IN7                      ((T_Reg16 *) 0xFF38)->bit8
#define SCU_ESREXSTAT2_IN8                      ((T_Reg16 *) 0xFF38)->bit9
#define SCU_ESREXSTAT2_IN9                      ((T_Reg16 *) 0xFF38)->bit10

// EVR_1 Control 0 Register
#define SCU_EVR1CON0           (*((uword volatile *) 0xF088))

// EVR_1 Setting for 1.0V Register
#define SCU_EVR1SET10V         (*((uword volatile *) 0xF098))

// EVR_1 Setting for 1.5V HP Register
#define SCU_EVR1SET15VHP       (*((uword volatile *) 0xF09E))

// EVR_1 Setting for 1.5V LP Register
#define SCU_EVR1SET15VLP       (*((uword volatile *) 0xF09C))

// EVR_1 Status Register
#define SCU_EVR1STAT           (*((uword volatile *) 0xF08E))

// EVR_M Control 0 Register
#define SCU_EVRMCON0           (*((uword volatile *) 0xF084))

// EVR_M Control 1 Register
#define SCU_EVRMCON1           (*((uword volatile *) 0xF086))

// EVR_M Setting for 1.0V Register
#define SCU_EVRMSET10V         (*((uword volatile *) 0xF090))

// EVR_M Setting for 1.5V HP Register
#define SCU_EVRMSET15VHP       (*((uword volatile *) 0xF096))

// EVR_M Setting for 1.5V LP Register
#define SCU_EVRMSET15VLP       (*((uword volatile *) 0xF094))

// EVR_M Status Register
#define SCU_EVRMSTAT           (*((uword volatile *) 0xF08C))

// External Input Control 0 Register
#define SCU_EXICON0            (*((uword volatile *) 0xF030))

// External Input Control 1 Register
#define SCU_EXICON1            (*((uword volatile *) 0xF032))

// External Input Control 2 Register
#define SCU_EXICON2            (*((uword volatile *) 0xF034))

// External Input Control 3 Register
#define SCU_EXICON3            (*((uword volatile *) 0xF036))

// External Input Select Register
#define SCU_EXISEL             (*((uword volatile *) 0xF1A0))

// External Output Trigger Control 0 Register
#define SCU_EXOCON0            (*((uword volatile *) 0xFE30))

// External Output Trigger Control 1 Register
#define SCU_EXOCON1            (*((uword volatile *) 0xFE32))

// External Output Trigger Control 2 Register
#define SCU_EXOCON2            (*((uword volatile *) 0xFE34))

// External Output Trigger Control 3 Register
#define SCU_EXOCON3            (*((uword volatile *) 0xFE36))

// External Clock Control Register
#define SCU_EXTCON             (*((uword volatile *) 0xFF5E))
#define SCU_EXTCON_EN                       ((T_Reg16 *) 0xFF5E)->bit0
#define SCU_EXTCON_FOEN                     ((T_Reg16 *) 0xFF5E)->bit15
#define SCU_EXTCON_FOSS                     ((T_Reg16 *) 0xFF5E)->bit14
#define SCU_EXTCON_FOTL                     ((T_Reg16 *) 0xFF5E)->bit6

// GSC Enable Register
#define SCU_GSCEN              (*((uword volatile *) 0xFF16))
#define SCU_GSCEN_ESR0EN                   ((T_Reg16 *) 0xFF16)->bit5
#define SCU_GSCEN_ESR1EN                   ((T_Reg16 *) 0xFF16)->bit6
#define SCU_GSCEN_ESR2EN                   ((T_Reg16 *) 0xFF16)->bit7
#define SCU_GSCEN_GPTEN                    ((T_Reg16 *) 0xFF16)->bit10
#define SCU_GSCEN_ITCEN                    ((T_Reg16 *) 0xFF16)->bit9
#define SCU_GSCEN_OCDSENEN                 ((T_Reg16 *) 0xFF16)->bit14
#define SCU_GSCEN_OCDSEXEN                 ((T_Reg16 *) 0xFF16)->bit4
#define SCU_GSCEN_PSCAENEN                 ((T_Reg16 *) 0xFF16)->bit3
#define SCU_GSCEN_PSCAEXEN                 ((T_Reg16 *) 0xFF16)->bit2
#define SCU_GSCEN_PSCBENEN                 ((T_Reg16 *) 0xFF16)->bit1
#define SCU_GSCEN_PSCBEXEN                 ((T_Reg16 *) 0xFF16)->bit0
#define SCU_GSCEN_SW1EN                    ((T_Reg16 *) 0xFF16)->bit11
#define SCU_GSCEN_SW2EN                    ((T_Reg16 *) 0xFF16)->bit12
#define SCU_GSCEN_WUTEN                    ((T_Reg16 *) 0xFF16)->bit8

// GSC Peripheral Status Register
#define SCU_GSCPERSTAT         (*((uword volatile *) 0xFF1A))
#define SCU_GSCPERSTAT_ADC                      ((T_Reg16 *) 0xFF1A)->bit0
#define SCU_GSCPERSTAT_CC2                      ((T_Reg16 *) 0xFF1A)->bit3
#define SCU_GSCPERSTAT_CCU60                    ((T_Reg16 *) 0xFF1A)->bit5
#define SCU_GSCPERSTAT_CCU61                    ((T_Reg16 *) 0xFF1A)->bit6
#define SCU_GSCPERSTAT_CCU62                    ((T_Reg16 *) 0xFF1A)->bit7
#define SCU_GSCPERSTAT_CCU63                    ((T_Reg16 *) 0xFF1A)->bit8
#define SCU_GSCPERSTAT_FL                       ((T_Reg16 *) 0xFF1A)->bit11
#define SCU_GSCPERSTAT_GPT12E                   ((T_Reg16 *) 0xFF1A)->bit1
#define SCU_GSCPERSTAT_MCAN                     ((T_Reg16 *) 0xFF1A)->bit4
#define SCU_GSCPERSTAT_MCHK                     ((T_Reg16 *) 0xFF1A)->bit2
#define SCU_GSCPERSTAT_MEM                      ((T_Reg16 *) 0xFF1A)->bit10
#define SCU_GSCPERSTAT_RTC                      ((T_Reg16 *) 0xFF1A)->bit9
#define SCU_GSCPERSTAT_USIC0                    ((T_Reg16 *) 0xFF1A)->bit12
#define SCU_GSCPERSTAT_USIC1                    ((T_Reg16 *) 0xFF1A)->bit13
#define SCU_GSCPERSTAT_USIC2                    ((T_Reg16 *) 0xFF1A)->bit14
#define SCU_GSCPERSTAT_USIC3                    ((T_Reg16 *) 0xFF1A)->bit15

// GSC Peripheral Status Enable Register
#define SCU_GSCPERSTATEN       (*((uword volatile *) 0xFF04))
#define SCU_GSCPERSTATEN_ADC                      ((T_Reg16 *) 0xFF04)->bit0
#define SCU_GSCPERSTATEN_CC2                      ((T_Reg16 *) 0xFF04)->bit3
#define SCU_GSCPERSTATEN_CCU60                    ((T_Reg16 *) 0xFF04)->bit5
#define SCU_GSCPERSTATEN_CCU61                    ((T_Reg16 *) 0xFF04)->bit6
#define SCU_GSCPERSTATEN_CCU62                    ((T_Reg16 *) 0xFF04)->bit7
#define SCU_GSCPERSTATEN_CCU63                    ((T_Reg16 *) 0xFF04)->bit8
#define SCU_GSCPERSTATEN_FL                       ((T_Reg16 *) 0xFF04)->bit11
#define SCU_GSCPERSTATEN_GPT12E                   ((T_Reg16 *) 0xFF04)->bit1
#define SCU_GSCPERSTATEN_MCAN                     ((T_Reg16 *) 0xFF04)->bit4
#define SCU_GSCPERSTATEN_MEM                      ((T_Reg16 *) 0xFF04)->bit10
#define SCU_GSCPERSTATEN_RTC                      ((T_Reg16 *) 0xFF04)->bit9
#define SCU_GSCPERSTATEN_USIC0                    ((T_Reg16 *) 0xFF04)->bit12
#define SCU_GSCPERSTATEN_USIC1                    ((T_Reg16 *) 0xFF04)->bit13
#define SCU_GSCPERSTATEN_USIC2                    ((T_Reg16 *) 0xFF04)->bit14
#define SCU_GSCPERSTATEN_USIC3                    ((T_Reg16 *) 0xFF04)->bit15

// GSC Status Register
#define SCU_GSCSTAT            (*((uword volatile *) 0xFF18))
#define SCU_GSCSTAT_ERR                      ((T_Reg16 *) 0xFF18)->bit8
#define SCU_GSCSTAT_PEN                      ((T_Reg16 *) 0xFF18)->bit9

// GSC Software Request Register
#define SCU_GSCSWREQ           (*((uword volatile *) 0xFF14))
#define SCU_GSCSWREQ_SWTRG1                   ((T_Reg16 *) 0xFF14)->bit0
#define SCU_GSCSWREQ_SWTRG2                   ((T_Reg16 *) 0xFF14)->bit1

// High Precision OSC Control Register
#define SCU_HPOSCCON           (*((uword volatile *) 0xF1B4))
#define SCU_HPOSCCON_EMCLKEN                  ((T_Reg16 *) 0xF1B4)->bit9
#define SCU_HPOSCCON_EMFINDISEN               ((T_Reg16 *) 0xF1B4)->bit10
#define SCU_HPOSCCON_OSC2L0                   ((T_Reg16 *) 0xF1B4)->bit12
#define SCU_HPOSCCON_OSC2L1                   ((T_Reg16 *) 0xF1B4)->bit11
#define SCU_HPOSCCON_OSCWDTRST                ((T_Reg16 *) 0xF1B4)->bit1
#define SCU_HPOSCCON_PLLV                     ((T_Reg16 *) 0xF1B4)->bit0
#define SCU_HPOSCCON_SHBY                     ((T_Reg16 *) 0xF1B4)->bit8
#define SCU_HPOSCCON_X1D                      ((T_Reg16 *) 0xF1B4)->bit6
#define SCU_HPOSCCON_X1DEN                    ((T_Reg16 *) 0xF1B4)->bit7

// Chip Identification Register
#define SCU_IDCHIP             (*((uword volatile *) 0xF07C))

// DMP_1 Module Identification Register
#define SCU_IDDMP1             (*((uword volatile *) 0xFFE4))

// DMP_M Module Identification Register
#define SCU_IDDMPM             (*((uword volatile *) 0xFFE2))

// Manufacturer Identification Register
#define SCU_IDMANUF            (*((uword volatile *) 0xF07E))

// Program Memory Identification Register
#define SCU_IDMEM              (*((uword volatile *) 0xF07A))

// Programming Voltage Id. Register
#define SCU_IDPROG             (*((uword volatile *) 0xF078))

// Interrupt Clear Register
#define SCU_INTCLR             (*((uword volatile *) 0xFE82))

// Interrupt Disable Register
#define SCU_INTDIS             (*((uword volatile *) 0xFE84))

// Interrupt Node Pointer 0 Register
#define SCU_INTNP0             (*((uword volatile *) 0xFE86))

// Interrupt Node Pointer 1 Register
#define SCU_INTNP1             (*((uword volatile *) 0xFE88))

// Interrupt Set Register
#define SCU_INTSET             (*((uword volatile *) 0xFE80))

// Interrupt Status Register
#define SCU_INTSTAT            (*((uword volatile *) 0xFF00))
#define SCU_INTSTAT_GSCI                     ((T_Reg16 *) 0xFF00)->bit9
#define SCU_INTSTAT_MCHKI                    ((T_Reg16 *) 0xFF00)->bit12
#define SCU_INTSTAT_PFI                      ((T_Reg16 *) 0xFF00)->bit13
#define SCU_INTSTAT_PVC1I1                   ((T_Reg16 *) 0xFF00)->bit4
#define SCU_INTSTAT_PVC1I2                   ((T_Reg16 *) 0xFF00)->bit5
#define SCU_INTSTAT_PVCMI1                   ((T_Reg16 *) 0xFF00)->bit2
#define SCU_INTSTAT_PVCMI2                   ((T_Reg16 *) 0xFF00)->bit3
#define SCU_INTSTAT_STM0I                    ((T_Reg16 *) 0xFF00)->bit10
#define SCU_INTSTAT_STM1I                    ((T_Reg16 *) 0xFF00)->bit11
#define SCU_INTSTAT_SWDI1                    ((T_Reg16 *) 0xFF00)->bit0
#define SCU_INTSTAT_SWDI2                    ((T_Reg16 *) 0xFF00)->bit1
#define SCU_INTSTAT_WDTI                     ((T_Reg16 *) 0xFF00)->bit8
#define SCU_INTSTAT_WUI                      ((T_Reg16 *) 0xFF00)->bit7
#define SCU_INTSTAT_WUTI                     ((T_Reg16 *) 0xFF00)->bit6

// Interrupt Source Select Register
#define SCU_ISSR               (*((uword volatile *) 0xFF2E))
#define SCU_ISSR_ISS0                     ((T_Reg16 *) 0xFF2E)->bit0
#define SCU_ISSR_ISS1                     ((T_Reg16 *) 0xFF2E)->bit1
#define SCU_ISSR_ISS10                    ((T_Reg16 *) 0xFF2E)->bit10
#define SCU_ISSR_ISS11                    ((T_Reg16 *) 0xFF2E)->bit11
#define SCU_ISSR_ISS12                    ((T_Reg16 *) 0xFF2E)->bit12
#define SCU_ISSR_ISS13                    ((T_Reg16 *) 0xFF2E)->bit13
#define SCU_ISSR_ISS14                    ((T_Reg16 *) 0xFF2E)->bit14
#define SCU_ISSR_ISS15                    ((T_Reg16 *) 0xFF2E)->bit15
#define SCU_ISSR_ISS2                     ((T_Reg16 *) 0xFF2E)->bit2
#define SCU_ISSR_ISS3                     ((T_Reg16 *) 0xFF2E)->bit3
#define SCU_ISSR_ISS4                     ((T_Reg16 *) 0xFF2E)->bit4
#define SCU_ISSR_ISS5                     ((T_Reg16 *) 0xFF2E)->bit5
#define SCU_ISSR_ISS6                     ((T_Reg16 *) 0xFF2E)->bit6
#define SCU_ISSR_ISS7                     ((T_Reg16 *) 0xFF2E)->bit7
#define SCU_ISSR_ISS8                     ((T_Reg16 *) 0xFF2E)->bit8
#define SCU_ISSR_ISS9                     ((T_Reg16 *) 0xFF2E)->bit9

// Memory Checking Control Register
#define SCU_MCHKCON            (*((uword volatile *) 0xF0DC))

// Marker Memory 0 Register
#define SCU_MKMEM0             (*((uword volatile *) 0xFED0))

// Marker Memory 1 Register
#define SCU_MKMEM1             (*((uword volatile *) 0xFED2))

// Marker Memory 2 Register
#define SCU_MKMEM2             (*((uword volatile *) 0xFED4))

// Marker Memory 3 Register
#define SCU_MKMEM3             (*((uword volatile *) 0xFED6))

// Parity Error Control Register
#define SCU_PECON              (*((uword volatile *) 0xF0DA))

// Parity Error Enable Register
#define SCU_PEEN               (*((uword volatile *) 0xF0C4))

// PLL Configuration 0 Register
#define SCU_PLLCON0            (*((uword volatile *) 0xF1B8))
#define SCU_PLLCON0_INSEL                    ((T_Reg16 *) 0xF1B8)->bit6
#define SCU_PLLCON0_NACK                     ((T_Reg16 *) 0xF1B8)->bit15
#define SCU_PLLCON0_REGENCLR                 ((T_Reg16 *) 0xF1B8)->bit4
#define SCU_PLLCON0_REGENSET                 ((T_Reg16 *) 0xF1B8)->bit5
#define SCU_PLLCON0_VCOBY                    ((T_Reg16 *) 0xF1B8)->bit0
#define SCU_PLLCON0_VCOPWD                   ((T_Reg16 *) 0xF1B8)->bit1

// PLL Configuration 1 Register
#define SCU_PLLCON1            (*((uword volatile *) 0xF1BA))
#define SCU_PLLCON1_AOSCSEL                  ((T_Reg16 *) 0xF1BA)->bit3
#define SCU_PLLCON1_EMCLKEN                  ((T_Reg16 *) 0xF1BA)->bit5
#define SCU_PLLCON1_EMFINDISEN               ((T_Reg16 *) 0xF1BA)->bit6
#define SCU_PLLCON1_OSCSEL                   ((T_Reg16 *) 0xF1BA)->bit1
#define SCU_PLLCON1_PACK                     ((T_Reg16 *) 0xF1BA)->bit15
#define SCU_PLLCON1_PLLPWD                   ((T_Reg16 *) 0xF1BA)->bit0
#define SCU_PLLCON1_RESLD                    ((T_Reg16 *) 0xF1BA)->bit2

// PLL Configuration 2 Register
#define SCU_PLLCON2            (*((uword volatile *) 0xF1BC))
#define SCU_PLLCON2_K1ACK                    ((T_Reg16 *) 0xF1BC)->bit15

// PLL Configuration 3 Register
#define SCU_PLLCON3            (*((uword volatile *) 0xF1BE))
#define SCU_PLLCON3_K2ACK                    ((T_Reg16 *) 0xF1BE)->bit15

// PLL OSC Configuration Register
#define SCU_PLLOSCCON          (*((uword volatile *) 0xF1B6))
#define SCU_PLLOSCCON_OSCPD                    ((T_Reg16 *) 0xF1B6)->bit0

// PLL Status Register
#define SCU_PLLSTAT            (*((uword volatile *) 0xF0BC))

// Parity Memory Test Pattern Register
#define SCU_PMTPR              (*((uword volatile *) 0xF0E4))

// Parity Memory Test Select Register
#define SCU_PMTSR              (*((uword volatile *) 0xF0E6))

// PSC Status Register
#define SCU_PSCSTAT            (*((uword volatile *) 0xFFE8))

// PVC_1 Control Step 0 Register
#define SCU_PVC1CON0           (*((uword volatile *) 0xF014))

// PVC_1 Control for Step 1Set A Register
#define SCU_PVC1CONA1          (*((uword volatile *) 0xF016))

// PVC_1 Control for Step 2 Set A Register
#define SCU_PVC1CONA2          (*((uword volatile *) 0xF018))

// PVC_1 Control for Step 3 Set A Register
#define SCU_PVC1CONA3          (*((uword volatile *) 0xF01A))

// PVC_1 Control for Step 4 Set A Register
#define SCU_PVC1CONA4          (*((uword volatile *) 0xF01C))

// PVC_1 Control for Step 5 Set A Register
#define SCU_PVC1CONA5          (*((uword volatile *) 0xF01E))

// PVC_1 Control for Step 6 Set A Register
#define SCU_PVC1CONA6          (*((uword volatile *) 0xF020))

// PVC_1 Control for Step 1 Set B Register
#define SCU_PVC1CONB1          (*((uword volatile *) 0xF024))

// PVC_1 Control for Step 2 Set B Register
#define SCU_PVC1CONB2          (*((uword volatile *) 0xF026))

// PVC_1 Control for Step 3 Set B Register
#define SCU_PVC1CONB3          (*((uword volatile *) 0xF028))

// PVC_1 Control for Step 4 Set B Register
#define SCU_PVC1CONB4          (*((uword volatile *) 0xF02A))

// PVC_1 Control for Step 5 Set B Register
#define SCU_PVC1CONB5          (*((uword volatile *) 0xF02C))

// PVC_1 Control for Step 6 Set B Register
#define SCU_PVC1CONB6          (*((uword volatile *) 0xF02E))

// PVC_M Control Step 0 Register
#define SCU_PVCMCON0           (*((uword volatile *) 0xF1E4))

// PVC_M Control for Step 1 Set A Register
#define SCU_PVCMCONA1          (*((uword volatile *) 0xF1E6))

// PVC_M Control for Step 2 Set A Register
#define SCU_PVCMCONA2          (*((uword volatile *) 0xF1E8))

// PVC_M Control for Step 3 Set A Register
#define SCU_PVCMCONA3          (*((uword volatile *) 0xF1EA))

// PVC_M Control for Step 4 Set A Register
#define SCU_PVCMCONA4          (*((uword volatile *) 0xF1EC))

// PVC_M Control for Step 5 Set A Register
#define SCU_PVCMCONA5          (*((uword volatile *) 0xF1EE))

// PVC_M Control for Step 6 Set A Register
#define SCU_PVCMCONA6          (*((uword volatile *) 0xF1F0))

// PVC_M Control for Step 1 Set B Register
#define SCU_PVCMCONB1          (*((uword volatile *) 0xF1F4))

// PVC_M Control for Step 2 Set B Register
#define SCU_PVCMCONB2          (*((uword volatile *) 0xF1F6))

// PVC_M Control for Step 3 Set B Register
#define SCU_PVCMCONB3          (*((uword volatile *) 0xF1F8))

// PVC_M Control for Step 4 Set B Register
#define SCU_PVCMCONB4          (*((uword volatile *) 0xF1FA))

// PVC_M Control for Step 5 Set B Register
#define SCU_PVCMCONB5          (*((uword volatile *) 0xF1FC))

// PVC_M Control for Step 6 Set B Register
#define SCU_PVCMCONB6          (*((uword volatile *) 0xF1FE))

// Reset Counter Control Register
#define SCU_RSTCNTCON          (*((uword volatile *) 0xF1B2))

// Reset Configuration 0 Register
#define SCU_RSTCON0            (*((uword volatile *) 0xF0B8))

// Reset Configuration 1 Register
#define SCU_RSTCON1            (*((uword volatile *) 0xF0BA))

// Reset Status 0 Register
#define SCU_RSTSTAT0           (*((uword volatile *) 0xF0B2))

// Reset Status 1 Register
#define SCU_RSTSTAT1           (*((uword volatile *) 0xF0B4))

// Reset Status 2 Register
#define SCU_RSTSTAT2           (*((uword volatile *) 0xF0B6))

// RTC Clock Control Register
#define SCU_RTCCLKCON          (*((uword volatile *) 0xFF4E))
#define SCU_RTCCLKCON_RTCCM                    ((T_Reg16 *) 0xFF4E)->bit2

// Sequence Step 1 for Set A Register
#define SCU_SEQASTEP1          (*((uword volatile *) 0xFEE6))

// Sequence Step 2 for Set A Register
#define SCU_SEQASTEP2          (*((uword volatile *) 0xFEE8))

// Sequence Step 3 for Set A Register
#define SCU_SEQASTEP3          (*((uword volatile *) 0xFEEA))

// Sequence Step 4 for Set A Register
#define SCU_SEQASTEP4          (*((uword volatile *) 0xFEEC))

// Sequence Step 5 for Set A Register
#define SCU_SEQASTEP5          (*((uword volatile *) 0xFEEE))

// Sequence Step 6 for Set A Register
#define SCU_SEQASTEP6          (*((uword volatile *) 0xFEF0))

// Sequence Step 1 for Set B Register
#define SCU_SEQBSTEP1          (*((uword volatile *) 0xFEF4))

// Sequence Step 2 for Set B Register
#define SCU_SEQBSTEP2          (*((uword volatile *) 0xFEF6))

// Sequence Step 3 for Set B Register
#define SCU_SEQBSTEP3          (*((uword volatile *) 0xFEF8))

// Sequence Step 4 for Set B Register
#define SCU_SEQBSTEP4          (*((uword volatile *) 0xFEFA))

// Sequence Step 5 for Set B Register
#define SCU_SEQBSTEP5          (*((uword volatile *) 0xFEFC))

// Sequence Step 6 for Set B Register
#define SCU_SEQBSTEP6          (*((uword volatile *) 0xFEFE))

// Sequence Control Register
#define SCU_SEQCON             (*((uword volatile *) 0xFEE4))

// Security Level Command Register
#define SCU_SLC                (*((uword volatile *) 0xF0C0))

// Security Level Status Register
#define SCU_SLS                (*((uword volatile *) 0xF0C2))

// Status Clear 0 Register
#define SCU_STATCLR0           (*((uword volatile *) 0xF0E0))

// Status Clear 1 Register
#define SCU_STATCLR1           (*((uword volatile *) 0xF0E2))

// Step 0 Register
#define SCU_STEP0              (*((uword volatile *) 0xFEF2))

// STM Control Register
#define SCU_STMCON             (*((uword volatile *) 0xF1AA))
#define SCU_STMCON_RUN                      ((T_Reg16 *) 0xF1AA)->bit0

// Start-up Memory 0 Register
#define SCU_STMEM0             (*((uword volatile *) 0xF0A0))

// STM Reload Register
#define SCU_STMREL             (*((uword volatile *) 0xF1A8))

// Start-up Status Register
#define SCU_STSTAT             (*((uword volatile *) 0xF1E0))

// SWD Control 0 Register
#define SCU_SWDCON0            (*((uword volatile *) 0xF080))

// SWD Control 1 Register
#define SCU_SWDCON1            (*((uword volatile *) 0xF082))

// Software Reset Control Register
#define SCU_SWRSTCON           (*((uword volatile *) 0xF0AE))

// System Control 0 Register
#define SCU_SYSCON0            (*((uword volatile *) 0xFF4A))
#define SCU_SYSCON0_EMCLKSELEN               ((T_Reg16 *) 0xFF4A)->bit6
#define SCU_SYSCON0_EMSOSC                   ((T_Reg16 *) 0xFF4A)->bit12
#define SCU_SYSCON0_EMSVCO                   ((T_Reg16 *) 0xFF4A)->bit13
#define SCU_SYSCON0_SELSTAT                  ((T_Reg16 *) 0xFF4A)->bit15

// System Control 1 Register
#define SCU_SYSCON1            (*((uword volatile *) 0xFF4C))
#define SCU_SYSCON1_GLCCST                   ((T_Reg16 *) 0xFF4C)->bit3
#define SCU_SYSCON1_OCDSEN                   ((T_Reg16 *) 0xFF4C)->bit2

// Temperature Compensation Register
#define SCU_TCCR               (*((uword volatile *) 0xF1AC))
#define SCU_TCCR_TCE                      ((T_Reg16 *) 0xF1AC)->bit7

// Temperature Comp. Level Register
#define SCU_TCLR               (*((uword volatile *) 0xF0AC))

// Trap Clear Register
#define SCU_TRAPCLR            (*((uword volatile *) 0xFE8E))

// Trap Disable Register
#define SCU_TRAPDIS            (*((uword volatile *) 0xFE90))

// Trap Node Pointer Register
#define SCU_TRAPNP             (*((uword volatile *) 0xFE92))

// Trap Node Pointer 1 Register
#define SCU_TRAPNP1            (*((uword volatile *) 0xFE94))

// Trap Set Register
#define SCU_TRAPSET            (*((uword volatile *) 0xFE8C))

// Trap Status Register
#define SCU_TRAPSTAT           (*((uword volatile *) 0xFF02))
#define SCU_TRAPSTAT_ECCT                     ((T_Reg16 *) 0xFF02)->bit8
#define SCU_TRAPSTAT_ESR0T                    ((T_Reg16 *) 0xFF02)->bit1
#define SCU_TRAPSTAT_ESR1T                    ((T_Reg16 *) 0xFF02)->bit2
#define SCU_TRAPSTAT_ESR2T                    ((T_Reg16 *) 0xFF02)->bit3
#define SCU_TRAPSTAT_FAT                      ((T_Reg16 *) 0xFF02)->bit0
#define SCU_TRAPSTAT_OSCWDTT                  ((T_Reg16 *) 0xFF02)->bit4
#define SCU_TRAPSTAT_PET                      ((T_Reg16 *) 0xFF02)->bit6
#define SCU_TRAPSTAT_RAT                      ((T_Reg16 *) 0xFF02)->bit5
#define SCU_TRAPSTAT_VCOLCKT                  ((T_Reg16 *) 0xFF02)->bit7

// WDT Control and Status Register
#define SCU_WDTCS              (*((uword volatile *) 0xF0C6))

// WDT Reload Register
#define SCU_WDTREL             (*((uword volatile *) 0xF0C8))

// WDT Timer Register
#define SCU_WDTTIM             (*((uword volatile *) 0xF0CA))

// Wake-up Control Register
#define SCU_WUCR               (*((uword volatile *) 0xF1B0))
#define SCU_WUCR_AON                      ((T_Reg16 *) 0xF1B0)->bit9
#define SCU_WUCR_ASP                      ((T_Reg16 *) 0xF1B0)->bit10
#define SCU_WUCR_CLRTRG                   ((T_Reg16 *) 0xF1B0)->bit7
#define SCU_WUCR_RUN                      ((T_Reg16 *) 0xF1B0)->bit8
#define SCU_WUCR_TTSTAT                   ((T_Reg16 *) 0xF1B0)->bit14
#define SCU_WUCR_WUTRG                    ((T_Reg16 *) 0xF1B0)->bit15

// Wake-up OSC Control Register
#define SCU_WUOSCCON           (*((uword volatile *) 0xF1AE))
#define SCU_WUOSCCON_DIS                      ((T_Reg16 *) 0xF1AE)->bit4

// Wake-up Timer Reload Register
#define SCU_WUTREL             (*((uword volatile *) 0xF0B0))

// Stack Pointer
#define SP                     (*((uword volatile *) 0xFE12))

// Stack Pointer Segment
#define SPSEG                  (*((uword volatile *) 0xFF0C))

// PEC Source Pointer 0
#define SRCP0                  (*((uword volatile *) 0xEC40))

// PEC Source Pointer 1
#define SRCP1                  (*((uword volatile *) 0xEC44))

// PEC Source Pointer 2
#define SRCP2                  (*((uword volatile *) 0xEC48))

// PEC Source Pointer 3
#define SRCP3                  (*((uword volatile *) 0xEC4C))

// PEC Source Pointer 4
#define SRCP4                  (*((uword volatile *) 0xEC50))

// PEC Source Pointer 5
#define SRCP5                  (*((uword volatile *) 0xEC54))

// PEC Source Pointer 6
#define SRCP6                  (*((uword volatile *) 0xEC58))

// PEC Source Pointer 7
#define SRCP7                  (*((uword volatile *) 0xEC5C))

// Stack Overflow Pointer
#define STKOV                  (*((uword volatile *) 0xFE14))

// Stack Underflow Pointer
#define STKUN                  (*((uword volatile *) 0xFE16))

// Timing Cfg. Reg. for CS0
#define TCONCS0                (*((uword volatile *) 0xEE10))

// Timing Cfg. Reg. for CS1
#define TCONCS1                (*((uword volatile *) 0xEE18))

// Timing Cfg. Reg. for CS2
#define TCONCS2                (*((uword volatile *) 0xEE20))

// Timing Cfg. Reg. for CS3
#define TCONCS3                (*((uword volatile *) 0xEE28))

// Timing Cfg. Reg. for CS4
#define TCONCS4                (*((uword volatile *) 0xEE30))

// Trap Flag Register
#define TFR                    (*((uword volatile *) 0xFFAC))
#define TFR_ACER                     ((T_Reg16 *) 0xFFAC)->bit4
#define TFR_ILLOPA                   ((T_Reg16 *) 0xFFAC)->bit2
#define TFR_MPR                      ((T_Reg16 *) 0xFFAC)->bit10
#define TFR_MPW                      ((T_Reg16 *) 0xFFAC)->bit9
#define TFR_MPX                      ((T_Reg16 *) 0xFFAC)->bit8
#define TFR_PRTFLT                   ((T_Reg16 *) 0xFFAC)->bit3
#define TFR_SOFTBRK                  ((T_Reg16 *) 0xFFAC)->bit12
#define TFR_SR0                      ((T_Reg16 *) 0xFFAC)->bit15
#define TFR_SR1                      ((T_Reg16 *) 0xFFAC)->bit11
#define TFR_STKOF                    ((T_Reg16 *) 0xFFAC)->bit14
#define TFR_STKUF                    ((T_Reg16 *) 0xFFAC)->bit13
#define TFR_UNDOPC                   ((T_Reg16 *) 0xFFAC)->bit7

// USIC Interrupt Control Reg. 0
#define U0C0_0IC               (*((uword volatile *) 0xF120))
#define U0C0_0IC_GPX                      ((T_Reg16 *) 0xF120)->bit8
#define U0C0_0IC_IE                       ((T_Reg16 *) 0xF120)->bit6
#define U0C0_0IC_IR                       ((T_Reg16 *) 0xF120)->bit7

// USIC Interrupt Control Reg. 1
#define U0C0_1IC               (*((uword volatile *) 0xF122))
#define U0C0_1IC_GPX                      ((T_Reg16 *) 0xF122)->bit8
#define U0C0_1IC_IE                       ((T_Reg16 *) 0xF122)->bit6
#define U0C0_1IC_IR                       ((T_Reg16 *) 0xF122)->bit7

// USIC Interrupt Control Reg. 2
#define U0C0_2IC               (*((uword volatile *) 0xF124))
#define U0C0_2IC_GPX                      ((T_Reg16 *) 0xF124)->bit8
#define U0C0_2IC_IE                       ((T_Reg16 *) 0xF124)->bit6
#define U0C0_2IC_IR                       ((T_Reg16 *) 0xF124)->bit7

// Baud Rate Generator Register H
#define U0C0_BRGH              (*((uword volatile far *) 0x20401E))

// Baud Rate Generator Register L
#define U0C0_BRGL              (*((uword volatile far *) 0x20401C))

// Bypass Data Register
#define U0C0_BYP               (*((uword volatile far *) 0x204100))

// Bypass Control Register H
#define U0C0_BYPCRH            (*((uword volatile far *) 0x204106))

// Bypass Control Register L
#define U0C0_BYPCRL            (*((uword volatile far *) 0x204104))

// Channel Configuration Register
#define U0C0_CCFG              (*((uword volatile far *) 0x204018))

// Channel Control Register
#define U0C0_CCR               (*((uword volatile far *) 0x204010))

// Input Control Register 0
#define U0C0_DX0CR             (*((uword volatile far *) 0x204020))

// Input Control Register 1
#define U0C0_DX1CR             (*((uword volatile far *) 0x204024))

// Input Control Register 2
#define U0C0_DX2CR             (*((uword volatile far *) 0x204028))

// Fractional Divider Register H
#define U0C0_FDRH              (*((uword volatile far *) 0x204006))

// Fractional Divider Register L
#define U0C0_FDRL              (*((uword volatile far *) 0x204004))

// Flag Modification Register H
#define U0C0_FMRH              (*((uword volatile far *) 0x20403A))

// Flag Modification Register L
#define U0C0_FMRL              (*((uword volatile far *) 0x204038))

// Transmit FIFO Buffer Input Location 00
#define U0C0_IN00              (*((uword volatile far *) 0x204180))

// Transmit FIFO Buffer Input Location 01
#define U0C0_IN01              (*((uword volatile far *) 0x204184))

// Transmit FIFO Buffer Input Location 02
#define U0C0_IN02              (*((uword volatile far *) 0x204188))

// Transmit FIFO Buffer Input Location 03
#define U0C0_IN03              (*((uword volatile far *) 0x20418C))

// Transmit FIFO Buffer Input Location 04
#define U0C0_IN04              (*((uword volatile far *) 0x204190))

// Transmit FIFO Buffer Input Location 05
#define U0C0_IN05              (*((uword volatile far *) 0x204194))

// Transmit FIFO Buffer Input Location 06
#define U0C0_IN06              (*((uword volatile far *) 0x204198))

// Transmit FIFO Buffer Input Location 07
#define U0C0_IN07              (*((uword volatile far *) 0x20419C))

// Transmit FIFO Buffer Input Location 08
#define U0C0_IN08              (*((uword volatile far *) 0x2041A0))

// Transmit FIFO Buffer Input Location 09
#define U0C0_IN09              (*((uword volatile far *) 0x2041A4))

// Transmit FIFO Buffer Input Location 10
#define U0C0_IN10              (*((uword volatile far *) 0x2041A8))

// Transmit FIFO Buffer Input Location 11
#define U0C0_IN11              (*((uword volatile far *) 0x2041AC))

// Transmit FIFO Buffer Input Location 12
#define U0C0_IN12              (*((uword volatile far *) 0x2041B0))

// Transmit FIFO Buffer Input Location 13
#define U0C0_IN13              (*((uword volatile far *) 0x2041B4))

// Transmit FIFO Buffer Input Location 14
#define U0C0_IN14              (*((uword volatile far *) 0x2041B8))

// Transmit FIFO Buffer Input Location 15
#define U0C0_IN15              (*((uword volatile far *) 0x2041BC))

// Transmit FIFO Buffer Input Location 16
#define U0C0_IN16              (*((uword volatile far *) 0x2041C0))

// Transmit FIFO Buffer Input Location 17
#define U0C0_IN17              (*((uword volatile far *) 0x2041C4))

// Transmit FIFO Buffer Input Location 18
#define U0C0_IN18              (*((uword volatile far *) 0x2041C8))

// Transmit FIFO Buffer Input Location 19
#define U0C0_IN19              (*((uword volatile far *) 0x2041CC))

// Transmit FIFO Buffer Input Location 20
#define U0C0_IN20              (*((uword volatile far *) 0x2041D0))

// Transmit FIFO Buffer Input Location 21
#define U0C0_IN21              (*((uword volatile far *) 0x2041D4))

// Transmit FIFO Buffer Input Location 22
#define U0C0_IN22              (*((uword volatile far *) 0x2041D8))

// Transmit FIFO Buffer Input Location 23
#define U0C0_IN23              (*((uword volatile far *) 0x2041DC))

// Transmit FIFO Buffer Input Location 24
#define U0C0_IN24              (*((uword volatile far *) 0x2041E0))

// Transmit FIFO Buffer Input Location 25
#define U0C0_IN25              (*((uword volatile far *) 0x2041E4))

// Transmit FIFO Buffer Input Location 26
#define U0C0_IN26              (*((uword volatile far *) 0x2041E8))

// Transmit FIFO Buffer Input Location 27
#define U0C0_IN27              (*((uword volatile far *) 0x2041EC))

// Transmit FIFO Buffer Input Location 28
#define U0C0_IN28              (*((uword volatile far *) 0x2041F0))

// Transmit FIFO Buffer Input Location 29
#define U0C0_IN29              (*((uword volatile far *) 0x2041F4))

// Transmit FIFO Buffer Input Location 30
#define U0C0_IN30              (*((uword volatile far *) 0x2041F8))

// Transmit FIFO Buffer Input Location 31
#define U0C0_IN31              (*((uword volatile far *) 0x2041FC))

// Interrupt Node Pointer Register H
#define U0C0_INPRH             (*((uword volatile far *) 0x204016))

// Interrupt Node Pointer Register L
#define U0C0_INPRL             (*((uword volatile far *) 0x204014))

// Kernel State Configuration Register
#define U0C0_KSCFG             (*((uword volatile far *) 0x20400C))

// Receiver Buffer Output Register H for Debugger
#define U0C0_OUTDRH            (*((uword volatile far *) 0x204126))

// Receiver Buffer Output Register L for Debugger
#define U0C0_OUTDRL            (*((uword volatile far *) 0x204124))

// Receiver Buffer Output Register H
#define U0C0_OUTRH             (*((uword volatile far *) 0x204122))

// Receiver Buffer Output Register L
#define U0C0_OUTRL             (*((uword volatile far *) 0x204120))

// Protocol Control Register H
#define U0C0_PCRH              (*((uword volatile far *) 0x204042))

// Protocol Control Register L
#define U0C0_PCRL              (*((uword volatile far *) 0x204040))

// Protocol Status Clear Register
#define U0C0_PSCR              (*((uword volatile far *) 0x204048))

// Protocol Status Register
#define U0C0_PSR               (*((uword volatile far *) 0x204044))

// Receiver Buffer Control Register H
#define U0C0_RBCTRH            (*((uword volatile far *) 0x204116))

// Receiver Buffer Control Register L
#define U0C0_RBCTRL            (*((uword volatile far *) 0x204114))

// Receiver Buffer Register
#define U0C0_RBUF              (*((uword volatile far *) 0x20405C))

// Receiver Buffer Register 0
#define U0C0_RBUF0             (*((uword volatile far *) 0x204050))

// Receiver Buffer 01 Status Register H
#define U0C0_RBUF01SRH         (*((uword volatile far *) 0x204062))

// Receiver Buffer 01 Status Register L
#define U0C0_RBUF01SRL         (*((uword volatile far *) 0x204060))

// Receiver Buffer Register 1
#define U0C0_RBUF1             (*((uword volatile far *) 0x204054))

// Receiver Buffer Reg. for Debugger
#define U0C0_RBUFD             (*((uword volatile far *) 0x20404C))

// Receiver Buffer Status Register
#define U0C0_RBUFSR            (*((uword volatile far *) 0x204058))

// Shift Control Register H
#define U0C0_SCTRH             (*((uword volatile far *) 0x204032))

// Shift Control Register L
#define U0C0_SCTRL             (*((uword volatile far *) 0x204030))

// Transmitter Buffer Control Reg. H
#define U0C0_TBCTRH            (*((uword volatile far *) 0x204112))

// Transmitter Buffer Control Reg. L
#define U0C0_TBCTRL            (*((uword volatile far *) 0x204110))

// Transmit Buffer Input Location 00
#define U0C0_TBUF00            (*((uword volatile far *) 0x204080))

// Transmit Buffer Input Location 01
#define U0C0_TBUF01            (*((uword volatile far *) 0x204084))

// Transmit Buffer Input Location 02
#define U0C0_TBUF02            (*((uword volatile far *) 0x204088))

// Transmit Buffer Input Location 03
#define U0C0_TBUF03            (*((uword volatile far *) 0x20408C))

// Transmit Buffer Input Location 04
#define U0C0_TBUF04            (*((uword volatile far *) 0x204090))

// Transmit Buffer Input Location 05
#define U0C0_TBUF05            (*((uword volatile far *) 0x204094))

// Transmit Buffer Input Location 06
#define U0C0_TBUF06            (*((uword volatile far *) 0x204098))

// Transmit Buffer Input Location 07
#define U0C0_TBUF07            (*((uword volatile far *) 0x20409C))

// Transmit Buffer Input Location 08
#define U0C0_TBUF08            (*((uword volatile far *) 0x2040A0))

// Transmit Buffer Input Location 09
#define U0C0_TBUF09            (*((uword volatile far *) 0x2040A4))

// Transmit Buffer Input Location 10
#define U0C0_TBUF10            (*((uword volatile far *) 0x2040A8))

// Transmit Buffer Input Location 11
#define U0C0_TBUF11            (*((uword volatile far *) 0x2040AC))

// Transmit Buffer Input Location 12
#define U0C0_TBUF12            (*((uword volatile far *) 0x2040B0))

// Transmit Buffer Input Location 13
#define U0C0_TBUF13            (*((uword volatile far *) 0x2040B4))

// Transmit Buffer Input Location 14
#define U0C0_TBUF14            (*((uword volatile far *) 0x2040B8))

// Transmit Buffer Input Location 15
#define U0C0_TBUF15            (*((uword volatile far *) 0x2040BC))

// Transmit Buffer Input Location 16
#define U0C0_TBUF16            (*((uword volatile far *) 0x2040C0))

// Transmit Buffer Input Location 17
#define U0C0_TBUF17            (*((uword volatile far *) 0x2040C4))

// Transmit Buffer Input Location 18
#define U0C0_TBUF18            (*((uword volatile far *) 0x2040C8))

// Transmit Buffer Input Location 19
#define U0C0_TBUF19            (*((uword volatile far *) 0x2040CC))

// Transmit Buffer Input Location 20
#define U0C0_TBUF20            (*((uword volatile far *) 0x2040D0))

// Transmit Buffer Input Location 21
#define U0C0_TBUF21            (*((uword volatile far *) 0x2040D4))

// Transmit Buffer Input Location 22
#define U0C0_TBUF22            (*((uword volatile far *) 0x2040D8))

// Transmit Buffer Input Location 23
#define U0C0_TBUF23            (*((uword volatile far *) 0x2040DC))

// Transmit Buffer Input Location 24
#define U0C0_TBUF24            (*((uword volatile far *) 0x2040E0))

// Transmit Buffer Input Location 25
#define U0C0_TBUF25            (*((uword volatile far *) 0x2040E4))

// Transmit Buffer Input Location 26
#define U0C0_TBUF26            (*((uword volatile far *) 0x2040E8))

// Transmit Buffer Input Location 27
#define U0C0_TBUF27            (*((uword volatile far *) 0x2040EC))

// Transmit Buffer Input Location 28
#define U0C0_TBUF28            (*((uword volatile far *) 0x2040F0))

// Transmit Buffer Input Location 29
#define U0C0_TBUF29            (*((uword volatile far *) 0x2040F4))

// Transmit Buffer Input Location 30
#define U0C0_TBUF30            (*((uword volatile far *) 0x2040F8))

// Transmit Buffer Input Location 31
#define U0C0_TBUF31            (*((uword volatile far *) 0x2040FC))

// Transmit Control/Status Register H
#define U0C0_TCSRH             (*((uword volatile far *) 0x20403E))

// Transmit Control/Status Register L
#define U0C0_TCSRL             (*((uword volatile far *) 0x20403C))

// Transmit / Receive Buffer Pointer Reg H
#define U0C0_TRBPTRH           (*((uword volatile far *) 0x20410A))

// Transmit / Receive Buffer Pointer Reg L
#define U0C0_TRBPTRL           (*((uword volatile far *) 0x204108))

// Transmit / Receive Buffer Status Clear Reg
#define U0C0_TRBSCR            (*((uword volatile far *) 0x20411C))

// Transmit / Receive Buffer Status Reg H
#define U0C0_TRBSRH            (*((uword volatile far *) 0x20411A))

// Transmit / Receive Buffer Status Reg. L
#define U0C0_TRBSRL            (*((uword volatile far *) 0x204118))

// USIC Interrupt Control Reg. 0
#define U0C1_0IC               (*((uword volatile *) 0xF126))
#define U0C1_0IC_GPX                      ((T_Reg16 *) 0xF126)->bit8
#define U0C1_0IC_IE                       ((T_Reg16 *) 0xF126)->bit6
#define U0C1_0IC_IR                       ((T_Reg16 *) 0xF126)->bit7

// USIC Interrupt Control Reg. 1
#define U0C1_1IC               (*((uword volatile *) 0xF128))
#define U0C1_1IC_GPX                      ((T_Reg16 *) 0xF128)->bit8
#define U0C1_1IC_IE                       ((T_Reg16 *) 0xF128)->bit6
#define U0C1_1IC_IR                       ((T_Reg16 *) 0xF128)->bit7

// USIC Interrupt Control Reg. 2
#define U0C1_2IC               (*((uword volatile *) 0xF12A))
#define U0C1_2IC_GPX                      ((T_Reg16 *) 0xF12A)->bit8
#define U0C1_2IC_IE                       ((T_Reg16 *) 0xF12A)->bit6
#define U0C1_2IC_IR                       ((T_Reg16 *) 0xF12A)->bit7

// Baud Rate Generator Register H
#define U0C1_BRGH              (*((uword volatile far *) 0x20421E))

// Baud Rate Generator Register L
#define U0C1_BRGL              (*((uword volatile far *) 0x20421C))

// Bypass Data Register
#define U0C1_BYP               (*((uword volatile far *) 0x204300))

// Bypass Control Register H
#define U0C1_BYPCRH            (*((uword volatile far *) 0x204306))

// Bypass Control Register L
#define U0C1_BYPCRL            (*((uword volatile far *) 0x204304))

// Channel Configuration Register
#define U0C1_CCFG              (*((uword volatile far *) 0x204218))

// Channel Control Register
#define U0C1_CCR               (*((uword volatile far *) 0x204210))

// Input Control Register 0
#define U0C1_DX0CR             (*((uword volatile far *) 0x204220))

// Input Control Register 1
#define U0C1_DX1CR             (*((uword volatile far *) 0x204224))

// Input Control Register 2
#define U0C1_DX2CR             (*((uword volatile far *) 0x204228))

// Fractional Divider Register H
#define U0C1_FDRH              (*((uword volatile far *) 0x204206))

// Fractional Divider Register L
#define U0C1_FDRL              (*((uword volatile far *) 0x204204))

// Flag Modification Register H
#define U0C1_FMRH              (*((uword volatile far *) 0x20423A))

// Flag Modification Register L
#define U0C1_FMRL              (*((uword volatile far *) 0x204238))

// Transmit FIFO Buffer Input Location 00
#define U0C1_IN00              (*((uword volatile far *) 0x204380))

// Transmit FIFO Buffer Input Location 01
#define U0C1_IN01              (*((uword volatile far *) 0x204384))

// Transmit FIFO Buffer Input Location 02
#define U0C1_IN02              (*((uword volatile far *) 0x204388))

// Transmit FIFO Buffer Input Location 03
#define U0C1_IN03              (*((uword volatile far *) 0x20438C))

// Transmit FIFO Buffer Input Location 04
#define U0C1_IN04              (*((uword volatile far *) 0x204390))

// Transmit FIFO Buffer Input Location 05
#define U0C1_IN05              (*((uword volatile far *) 0x204394))

// Transmit FIFO Buffer Input Location 06
#define U0C1_IN06              (*((uword volatile far *) 0x204398))

// Transmit FIFO Buffer Input Location 07
#define U0C1_IN07              (*((uword volatile far *) 0x20439C))

// Transmit FIFO Buffer Input Location 08
#define U0C1_IN08              (*((uword volatile far *) 0x2043A0))

// Transmit FIFO Buffer Input Location 09
#define U0C1_IN09              (*((uword volatile far *) 0x2043A4))

// Transmit FIFO Buffer Input Location 10
#define U0C1_IN10              (*((uword volatile far *) 0x2043A8))

// Transmit FIFO Buffer Input Location 11
#define U0C1_IN11              (*((uword volatile far *) 0x2043AC))

// Transmit FIFO Buffer Input Location 12
#define U0C1_IN12              (*((uword volatile far *) 0x2043B0))

// Transmit FIFO Buffer Input Location 13
#define U0C1_IN13              (*((uword volatile far *) 0x2043B4))

// Transmit FIFO Buffer Input Location 14
#define U0C1_IN14              (*((uword volatile far *) 0x2043B8))

// Transmit FIFO Buffer Input Location 15
#define U0C1_IN15              (*((uword volatile far *) 0x2043BC))

// Transmit FIFO Buffer Input Location 16
#define U0C1_IN16              (*((uword volatile far *) 0x2043C0))

// Transmit FIFO Buffer Input Location 17
#define U0C1_IN17              (*((uword volatile far *) 0x2043C4))

// Transmit FIFO Buffer Input Location 18
#define U0C1_IN18              (*((uword volatile far *) 0x2043C8))

// Transmit FIFO Buffer Input Location 19
#define U0C1_IN19              (*((uword volatile far *) 0x2043CC))

// Transmit FIFO Buffer Input Location 20
#define U0C1_IN20              (*((uword volatile far *) 0x2043D0))

// Transmit FIFO Buffer Input Location 21
#define U0C1_IN21              (*((uword volatile far *) 0x2043D4))

// Transmit FIFO Buffer Input Location 22
#define U0C1_IN22              (*((uword volatile far *) 0x2043D8))

// Transmit FIFO Buffer Input Location 23
#define U0C1_IN23              (*((uword volatile far *) 0x2043DC))

// Transmit FIFO Buffer Input Location 24
#define U0C1_IN24              (*((uword volatile far *) 0x2043E0))

// Transmit FIFO Buffer Input Location 25
#define U0C1_IN25              (*((uword volatile far *) 0x2043E4))

// Transmit FIFO Buffer Input Location 26
#define U0C1_IN26              (*((uword volatile far *) 0x2043E8))

// Transmit FIFO Buffer Input Location 27
#define U0C1_IN27              (*((uword volatile far *) 0x2043EC))

// Transmit FIFO Buffer Input Location 28
#define U0C1_IN28              (*((uword volatile far *) 0x2043F0))

// Transmit FIFO Buffer Input Location 29
#define U0C1_IN29              (*((uword volatile far *) 0x2043F4))

// Transmit FIFO Buffer Input Location 30
#define U0C1_IN30              (*((uword volatile far *) 0x2043F8))

// Transmit FIFO Buffer Input Location 31
#define U0C1_IN31              (*((uword volatile far *) 0x2043FC))

// Interrupt Node Pointer Register H
#define U0C1_INPRH             (*((uword volatile far *) 0x204216))

// Interrupt Node Pointer Register L
#define U0C1_INPRL             (*((uword volatile far *) 0x204214))

// Kernel State Configuration Register
#define U0C1_KSCFG             (*((uword volatile far *) 0x20420C))

// Receiver Buffer Output Register H for Debugger
#define U0C1_OUTDRH            (*((uword volatile far *) 0x204326))

// Receiver Buffer Output Register L for Debugger
#define U0C1_OUTDRL            (*((uword volatile far *) 0x204324))

// Receiver Buffer Output Register H
#define U0C1_OUTRH             (*((uword volatile far *) 0x204322))

// Receiver Buffer Output Register L
#define U0C1_OUTRL             (*((uword volatile far *) 0x204320))

// Protocol Control Register H
#define U0C1_PCRH              (*((uword volatile far *) 0x204242))

// Protocol Control Register L
#define U0C1_PCRL              (*((uword volatile far *) 0x204240))

// Protocol Status Clear Register
#define U0C1_PSCR              (*((uword volatile far *) 0x204248))

// Protocol Status Register
#define U0C1_PSR               (*((uword volatile far *) 0x204244))

// Receiver Buffer Control Register H
#define U0C1_RBCTRH            (*((uword volatile far *) 0x204316))

// Receiver Buffer Control Register L
#define U0C1_RBCTRL            (*((uword volatile far *) 0x204314))

// Receiver Buffer Register
#define U0C1_RBUF              (*((uword volatile far *) 0x20425C))

// Receiver Buffer Register 0
#define U0C1_RBUF0             (*((uword volatile far *) 0x204250))

// Receiver Buffer 01 Status Register H
#define U0C1_RBUF01SRH         (*((uword volatile far *) 0x204262))

// Receiver Buffer 01 Status Register L
#define U0C1_RBUF01SRL         (*((uword volatile far *) 0x204260))

// Receiver Buffer Register 1
#define U0C1_RBUF1             (*((uword volatile far *) 0x204254))

// Receiver Buffer Reg. for Debugger
#define U0C1_RBUFD             (*((uword volatile far *) 0x20424C))

// Receiver Buffer Status Register
#define U0C1_RBUFSR            (*((uword volatile far *) 0x204258))

// Shift Control Register H
#define U0C1_SCTRH             (*((uword volatile far *) 0x204232))

// Shift Control Register L
#define U0C1_SCTRL             (*((uword volatile far *) 0x204230))

// Transmitter Buffer Control Reg. H
#define U0C1_TBCTRH            (*((uword volatile far *) 0x204312))

// Transmitter Buffer Control Reg. L
#define U0C1_TBCTRL            (*((uword volatile far *) 0x204310))

// Transmit Buffer Input Location 00
#define U0C1_TBUF00            (*((uword volatile far *) 0x204280))

// Transmit Buffer Input Location 01
#define U0C1_TBUF01            (*((uword volatile far *) 0x204284))

// Transmit Buffer Input Location 02
#define U0C1_TBUF02            (*((uword volatile far *) 0x204288))

// Transmit Buffer Input Location 03
#define U0C1_TBUF03            (*((uword volatile far *) 0x20428C))

// Transmit Buffer Input Location 04
#define U0C1_TBUF04            (*((uword volatile far *) 0x204290))

// Transmit Buffer Input Location 05
#define U0C1_TBUF05            (*((uword volatile far *) 0x204294))

// Transmit Buffer Input Location 06
#define U0C1_TBUF06            (*((uword volatile far *) 0x204298))

// Transmit Buffer Input Location 07
#define U0C1_TBUF07            (*((uword volatile far *) 0x20429C))

// Transmit Buffer Input Location 08
#define U0C1_TBUF08            (*((uword volatile far *) 0x2042A0))

// Transmit Buffer Input Location 09
#define U0C1_TBUF09            (*((uword volatile far *) 0x2042A4))

// Transmit Buffer Input Location 10
#define U0C1_TBUF10            (*((uword volatile far *) 0x2042A8))

// Transmit Buffer Input Location 11
#define U0C1_TBUF11            (*((uword volatile far *) 0x2042AC))

// Transmit Buffer Input Location 12
#define U0C1_TBUF12            (*((uword volatile far *) 0x2042B0))

// Transmit Buffer Input Location 13
#define U0C1_TBUF13            (*((uword volatile far *) 0x2042B4))

// Transmit Buffer Input Location 14
#define U0C1_TBUF14            (*((uword volatile far *) 0x2042B8))

// Transmit Buffer Input Location 15
#define U0C1_TBUF15            (*((uword volatile far *) 0x2042BC))

// Transmit Buffer Input Location 16
#define U0C1_TBUF16            (*((uword volatile far *) 0x2042C0))

// Transmit Buffer Input Location 17
#define U0C1_TBUF17            (*((uword volatile far *) 0x2042C4))

// Transmit Buffer Input Location 18
#define U0C1_TBUF18            (*((uword volatile far *) 0x2042C8))

// Transmit Buffer Input Location 19
#define U0C1_TBUF19            (*((uword volatile far *) 0x2042CC))

// Transmit Buffer Input Location 20
#define U0C1_TBUF20            (*((uword volatile far *) 0x2042D0))

// Transmit Buffer Input Location 21
#define U0C1_TBUF21            (*((uword volatile far *) 0x2042D4))

// Transmit Buffer Input Location 22
#define U0C1_TBUF22            (*((uword volatile far *) 0x2042D8))

// Transmit Buffer Input Location 23
#define U0C1_TBUF23            (*((uword volatile far *) 0x2042DC))

// Transmit Buffer Input Location 24
#define U0C1_TBUF24            (*((uword volatile far *) 0x2042E0))

// Transmit Buffer Input Location 25
#define U0C1_TBUF25            (*((uword volatile far *) 0x2042E4))

// Transmit Buffer Input Location 26
#define U0C1_TBUF26            (*((uword volatile far *) 0x2042E8))

// Transmit Buffer Input Location 27
#define U0C1_TBUF27            (*((uword volatile far *) 0x2042EC))

// Transmit Buffer Input Location 28
#define U0C1_TBUF28            (*((uword volatile far *) 0x2042F0))

// Transmit Buffer Input Location 29
#define U0C1_TBUF29            (*((uword volatile far *) 0x2042F4))

// Transmit Buffer Input Location 30
#define U0C1_TBUF30            (*((uword volatile far *) 0x2042F8))

// Transmit Buffer Input Location 31
#define U0C1_TBUF31            (*((uword volatile far *) 0x2042FC))

// Transmit Control/Status Register H
#define U0C1_TCSRH             (*((uword volatile far *) 0x20423E))

// Transmit Control/Status Register L
#define U0C1_TCSRL             (*((uword volatile far *) 0x20423C))

// Transmit / Receive Buffer Pointer Reg H
#define U0C1_TRBPTRH           (*((uword volatile far *) 0x20430A))

// Transmit / Receive Buffer Pointer Reg L
#define U0C1_TRBPTRL           (*((uword volatile far *) 0x204308))

// Transmit / Receive Buffer Status Clear Reg
#define U0C1_TRBSCR            (*((uword volatile far *) 0x20431C))

// Transmit / Receive Buffer Status Reg H
#define U0C1_TRBSRH            (*((uword volatile far *) 0x20431A))

// Transmit / Receive Buffer Status Reg. L
#define U0C1_TRBSRL            (*((uword volatile far *) 0x204318))

// USIC Interrupt Control Reg. 0
#define U1C0_0IC               (*((uword volatile *) 0xF12C))
#define U1C0_0IC_GPX                      ((T_Reg16 *) 0xF12C)->bit8
#define U1C0_0IC_IE                       ((T_Reg16 *) 0xF12C)->bit6
#define U1C0_0IC_IR                       ((T_Reg16 *) 0xF12C)->bit7

// USIC Interrupt Control Reg. 1
#define U1C0_1IC               (*((uword volatile *) 0xF12E))
#define U1C0_1IC_GPX                      ((T_Reg16 *) 0xF12E)->bit8
#define U1C0_1IC_IE                       ((T_Reg16 *) 0xF12E)->bit6
#define U1C0_1IC_IR                       ((T_Reg16 *) 0xF12E)->bit7

// USIC Interrupt Control Reg. 2
#define U1C0_2IC               (*((uword volatile *) 0xF130))
#define U1C0_2IC_GPX                      ((T_Reg16 *) 0xF130)->bit8
#define U1C0_2IC_IE                       ((T_Reg16 *) 0xF130)->bit6
#define U1C0_2IC_IR                       ((T_Reg16 *) 0xF130)->bit7

// Baud Rate Generator Register H
#define U1C0_BRGH              (*((uword volatile far *) 0x20481E))

// Baud Rate Generator Register L
#define U1C0_BRGL              (*((uword volatile far *) 0x20481C))

// Bypass Data Register
#define U1C0_BYP               (*((uword volatile far *) 0x204900))

// Bypass Control Register H
#define U1C0_BYPCRH            (*((uword volatile far *) 0x204906))

// Bypass Control Register L
#define U1C0_BYPCRL            (*((uword volatile far *) 0x204904))

// Channel Configuration Register
#define U1C0_CCFG              (*((uword volatile far *) 0x204818))

// Channel Control Register
#define U1C0_CCR               (*((uword volatile far *) 0x204810))

// Input Control Register 0
#define U1C0_DX0CR             (*((uword volatile far *) 0x204820))

// Input Control Register 1
#define U1C0_DX1CR             (*((uword volatile far *) 0x204824))

// Input Control Register 2
#define U1C0_DX2CR             (*((uword volatile far *) 0x204828))

// Fractional Divider Register H
#define U1C0_FDRH              (*((uword volatile far *) 0x204806))

// Fractional Divider Register L
#define U1C0_FDRL              (*((uword volatile far *) 0x204804))

// Flag Modification Register H
#define U1C0_FMRH              (*((uword volatile far *) 0x20483A))

// Flag Modification Register L
#define U1C0_FMRL              (*((uword volatile far *) 0x204838))

// Transmit FIFO Buffer Input Location 00
#define U1C0_IN00              (*((uword volatile far *) 0x204980))

// Transmit FIFO Buffer Input Location 01
#define U1C0_IN01              (*((uword volatile far *) 0x204984))

// Transmit FIFO Buffer Input Location 02
#define U1C0_IN02              (*((uword volatile far *) 0x204988))

// Transmit FIFO Buffer Input Location 03
#define U1C0_IN03              (*((uword volatile far *) 0x20498C))

// Transmit FIFO Buffer Input Location 04
#define U1C0_IN04              (*((uword volatile far *) 0x204990))

// Transmit FIFO Buffer Input Location 05
#define U1C0_IN05              (*((uword volatile far *) 0x204994))

// Transmit FIFO Buffer Input Location 06
#define U1C0_IN06              (*((uword volatile far *) 0x204998))

// Transmit FIFO Buffer Input Location 07
#define U1C0_IN07              (*((uword volatile far *) 0x20499C))

// Transmit FIFO Buffer Input Location 08
#define U1C0_IN08              (*((uword volatile far *) 0x2049A0))

// Transmit FIFO Buffer Input Location 09
#define U1C0_IN09              (*((uword volatile far *) 0x2049A4))

// Transmit FIFO Buffer Input Location 10
#define U1C0_IN10              (*((uword volatile far *) 0x2049A8))

// Transmit FIFO Buffer Input Location 11
#define U1C0_IN11              (*((uword volatile far *) 0x2049AC))

// Transmit FIFO Buffer Input Location 12
#define U1C0_IN12              (*((uword volatile far *) 0x2049B0))

// Transmit FIFO Buffer Input Location 13
#define U1C0_IN13              (*((uword volatile far *) 0x2049B4))

// Transmit FIFO Buffer Input Location 14
#define U1C0_IN14              (*((uword volatile far *) 0x2049B8))

// Transmit FIFO Buffer Input Location 15
#define U1C0_IN15              (*((uword volatile far *) 0x2049BC))

// Transmit FIFO Buffer Input Location 16
#define U1C0_IN16              (*((uword volatile far *) 0x2049C0))

// Transmit FIFO Buffer Input Location 17
#define U1C0_IN17              (*((uword volatile far *) 0x2049C4))

// Transmit FIFO Buffer Input Location 18
#define U1C0_IN18              (*((uword volatile far *) 0x2049C8))

// Transmit FIFO Buffer Input Location 19
#define U1C0_IN19              (*((uword volatile far *) 0x2049CC))

// Transmit FIFO Buffer Input Location 20
#define U1C0_IN20              (*((uword volatile far *) 0x2049D0))

// Transmit FIFO Buffer Input Location 21
#define U1C0_IN21              (*((uword volatile far *) 0x2049D4))

// Transmit FIFO Buffer Input Location 22
#define U1C0_IN22              (*((uword volatile far *) 0x2049D8))

// Transmit FIFO Buffer Input Location 23
#define U1C0_IN23              (*((uword volatile far *) 0x2049DC))

// Transmit FIFO Buffer Input Location 24
#define U1C0_IN24              (*((uword volatile far *) 0x2049E0))

// Transmit FIFO Buffer Input Location 25
#define U1C0_IN25              (*((uword volatile far *) 0x2049E4))

// Transmit FIFO Buffer Input Location 26
#define U1C0_IN26              (*((uword volatile far *) 0x2049E8))

// Transmit FIFO Buffer Input Location 27
#define U1C0_IN27              (*((uword volatile far *) 0x2049EC))

// Transmit FIFO Buffer Input Location 28
#define U1C0_IN28              (*((uword volatile far *) 0x2049F0))

// Transmit FIFO Buffer Input Location 29
#define U1C0_IN29              (*((uword volatile far *) 0x2049F4))

// Transmit FIFO Buffer Input Location 30
#define U1C0_IN30              (*((uword volatile far *) 0x2049F8))

// Transmit FIFO Buffer Input Location 31
#define U1C0_IN31              (*((uword volatile far *) 0x2049FC))

// Interrupt Node Pointer Register H
#define U1C0_INPRH             (*((uword volatile far *) 0x204816))

// Interrupt Node Pointer Register L
#define U1C0_INPRL             (*((uword volatile far *) 0x204814))

// Kernel State Configuration Register
#define U1C0_KSCFG             (*((uword volatile far *) 0x20480C))

// Receiver Buffer Output Register H for Debugger
#define U1C0_OUTDRH            (*((uword volatile far *) 0x204926))

// Receiver Buffer Output Register L for Debugger
#define U1C0_OUTDRL            (*((uword volatile far *) 0x204924))

// Receiver Buffer Output Register H
#define U1C0_OUTRH             (*((uword volatile far *) 0x204922))

// Receiver Buffer Output Register L
#define U1C0_OUTRL             (*((uword volatile far *) 0x204920))

// Protocol Control Register H
#define U1C0_PCRH              (*((uword volatile far *) 0x204842))

// Protocol Control Register L
#define U1C0_PCRL              (*((uword volatile far *) 0x204840))

// Protocol Status Clear Register
#define U1C0_PSCR              (*((uword volatile far *) 0x204848))

// Protocol Status Register
#define U1C0_PSR               (*((uword volatile far *) 0x204844))

// Receiver Buffer Control Register H
#define U1C0_RBCTRH            (*((uword volatile far *) 0x204916))

// Receiver Buffer Control Register L
#define U1C0_RBCTRL            (*((uword volatile far *) 0x204914))

// Receiver Buffer Register
#define U1C0_RBUF              (*((uword volatile far *) 0x20485C))

// Receiver Buffer Register 0
#define U1C0_RBUF0             (*((uword volatile far *) 0x204850))

// Receiver Buffer 01 Status Register H
#define U1C0_RBUF01SRH         (*((uword volatile far *) 0x204862))

// Receiver Buffer 01 Status Register L
#define U1C0_RBUF01SRL         (*((uword volatile far *) 0x204860))

// Receiver Buffer Register 1
#define U1C0_RBUF1             (*((uword volatile far *) 0x204854))

// Receiver Buffer Reg. for Debugger
#define U1C0_RBUFD             (*((uword volatile far *) 0x20484C))

// Receiver Buffer Status Register
#define U1C0_RBUFSR            (*((uword volatile far *) 0x204858))

// Shift Control Register H
#define U1C0_SCTRH             (*((uword volatile far *) 0x204832))

// Shift Control Register L
#define U1C0_SCTRL             (*((uword volatile far *) 0x204830))

// Transmitter Buffer Control Reg. H
#define U1C0_TBCTRH            (*((uword volatile far *) 0x204912))

// Transmitter Buffer Control Reg. L
#define U1C0_TBCTRL            (*((uword volatile far *) 0x204910))

// Transmit Buffer Input Location 00
#define U1C0_TBUF00            (*((uword volatile far *) 0x204880))

// Transmit Buffer Input Location 01
#define U1C0_TBUF01            (*((uword volatile far *) 0x204884))

// Transmit Buffer Input Location 02
#define U1C0_TBUF02            (*((uword volatile far *) 0x204888))

// Transmit Buffer Input Location 03
#define U1C0_TBUF03            (*((uword volatile far *) 0x20488C))

// Transmit Buffer Input Location 04
#define U1C0_TBUF04            (*((uword volatile far *) 0x204890))

// Transmit Buffer Input Location 05
#define U1C0_TBUF05            (*((uword volatile far *) 0x204894))

// Transmit Buffer Input Location 06
#define U1C0_TBUF06            (*((uword volatile far *) 0x204898))

// Transmit Buffer Input Location 07
#define U1C0_TBUF07            (*((uword volatile far *) 0x20489C))

// Transmit Buffer Input Location 08
#define U1C0_TBUF08            (*((uword volatile far *) 0x2048A0))

// Transmit Buffer Input Location 09
#define U1C0_TBUF09            (*((uword volatile far *) 0x2048A4))

// Transmit Buffer Input Location 10
#define U1C0_TBUF10            (*((uword volatile far *) 0x2048A8))

// Transmit Buffer Input Location 11
#define U1C0_TBUF11            (*((uword volatile far *) 0x2048AC))

// Transmit Buffer Input Location 12
#define U1C0_TBUF12            (*((uword volatile far *) 0x2048B0))

// Transmit Buffer Input Location 13
#define U1C0_TBUF13            (*((uword volatile far *) 0x2048B4))

// Transmit Buffer Input Location 14
#define U1C0_TBUF14            (*((uword volatile far *) 0x2048B8))

// Transmit Buffer Input Location 15
#define U1C0_TBUF15            (*((uword volatile far *) 0x2048BC))

// Transmit Buffer Input Location 16
#define U1C0_TBUF16            (*((uword volatile far *) 0x2048C0))

// Transmit Buffer Input Location 17
#define U1C0_TBUF17            (*((uword volatile far *) 0x2048C4))

// Transmit Buffer Input Location 18
#define U1C0_TBUF18            (*((uword volatile far *) 0x2048C8))

// Transmit Buffer Input Location 19
#define U1C0_TBUF19            (*((uword volatile far *) 0x2048CC))

// Transmit Buffer Input Location 20
#define U1C0_TBUF20            (*((uword volatile far *) 0x2048D0))

// Transmit Buffer Input Location 21
#define U1C0_TBUF21            (*((uword volatile far *) 0x2048D4))

// Transmit Buffer Input Location 22
#define U1C0_TBUF22            (*((uword volatile far *) 0x2048D8))

// Transmit Buffer Input Location 23
#define U1C0_TBUF23            (*((uword volatile far *) 0x2048DC))

// Transmit Buffer Input Location 24
#define U1C0_TBUF24            (*((uword volatile far *) 0x2048E0))

// Transmit Buffer Input Location 25
#define U1C0_TBUF25            (*((uword volatile far *) 0x2048E4))

// Transmit Buffer Input Location 26
#define U1C0_TBUF26            (*((uword volatile far *) 0x2048E8))

// Transmit Buffer Input Location 27
#define U1C0_TBUF27            (*((uword volatile far *) 0x2048EC))

// Transmit Buffer Input Location 28
#define U1C0_TBUF28            (*((uword volatile far *) 0x2048F0))

// Transmit Buffer Input Location 29
#define U1C0_TBUF29            (*((uword volatile far *) 0x2048F4))

// Transmit Buffer Input Location 30
#define U1C0_TBUF30            (*((uword volatile far *) 0x2048F8))

// Transmit Buffer Input Location 31
#define U1C0_TBUF31            (*((uword volatile far *) 0x2048FC))

// Transmit Control/Status Register H
#define U1C0_TCSRH             (*((uword volatile far *) 0x20483E))

// Transmit Control/Status Register L
#define U1C0_TCSRL             (*((uword volatile far *) 0x20483C))

// Transmit / Receive Buffer Pointer Reg H
#define U1C0_TRBPTRH           (*((uword volatile far *) 0x20490A))

// Transmit / Receive Buffer Pointer Reg L
#define U1C0_TRBPTRL           (*((uword volatile far *) 0x204908))

// Transmit / Receive Buffer Status Clear Reg
#define U1C0_TRBSCR            (*((uword volatile far *) 0x20491C))

// Transmit / Receive Buffer Status Reg H
#define U1C0_TRBSRH            (*((uword volatile far *) 0x20491A))

// Transmit / Receive Buffer Status Reg. L
#define U1C0_TRBSRL            (*((uword volatile far *) 0x204918))

// USIC Interrupt Control Reg. 0
#define U1C1_0IC               (*((uword volatile *) 0xF132))
#define U1C1_0IC_GPX                      ((T_Reg16 *) 0xF132)->bit8
#define U1C1_0IC_IE                       ((T_Reg16 *) 0xF132)->bit6
#define U1C1_0IC_IR                       ((T_Reg16 *) 0xF132)->bit7

// USIC Interrupt Control Reg. 1
#define U1C1_1IC               (*((uword volatile *) 0xF134))
#define U1C1_1IC_GPX                      ((T_Reg16 *) 0xF134)->bit8
#define U1C1_1IC_IE                       ((T_Reg16 *) 0xF134)->bit6
#define U1C1_1IC_IR                       ((T_Reg16 *) 0xF134)->bit7

// USIC Interrupt Control Reg. 2
#define U1C1_2IC               (*((uword volatile *) 0xF136))
#define U1C1_2IC_GPX                      ((T_Reg16 *) 0xF136)->bit8
#define U1C1_2IC_IE                       ((T_Reg16 *) 0xF136)->bit6
#define U1C1_2IC_IR                       ((T_Reg16 *) 0xF136)->bit7

// Baud Rate Generator Register H
#define U1C1_BRGH              (*((uword volatile far *) 0x204A1E))

// Baud Rate Generator Register L
#define U1C1_BRGL              (*((uword volatile far *) 0x204A1C))

// Bypass Data Register
#define U1C1_BYP               (*((uword volatile far *) 0x204B00))

// Bypass Control Register H
#define U1C1_BYPCRH            (*((uword volatile far *) 0x204B06))

// Bypass Control Register L
#define U1C1_BYPCRL            (*((uword volatile far *) 0x204B04))

// Channel Configuration Register
#define U1C1_CCFG              (*((uword volatile far *) 0x204A18))

// Channel Control Register
#define U1C1_CCR               (*((uword volatile far *) 0x204A10))

// Input Control Register 0
#define U1C1_DX0CR             (*((uword volatile far *) 0x204A20))

// Input Control Register 1
#define U1C1_DX1CR             (*((uword volatile far *) 0x204A24))

// Input Control Register 2
#define U1C1_DX2CR             (*((uword volatile far *) 0x204A28))

// Fractional Divider Register H
#define U1C1_FDRH              (*((uword volatile far *) 0x204A06))

// Fractional Divider Register L
#define U1C1_FDRL              (*((uword volatile far *) 0x204A04))

// Flag Modification Register H
#define U1C1_FMRH              (*((uword volatile far *) 0x204A3A))

// Flag Modification Register L
#define U1C1_FMRL              (*((uword volatile far *) 0x204A38))

// Transmit FIFO Buffer Input Location 00
#define U1C1_IN00              (*((uword volatile far *) 0x204B80))

// Transmit FIFO Buffer Input Location 01
#define U1C1_IN01              (*((uword volatile far *) 0x204B84))

// Transmit FIFO Buffer Input Location 02
#define U1C1_IN02              (*((uword volatile far *) 0x204B88))

// Transmit FIFO Buffer Input Location 03
#define U1C1_IN03              (*((uword volatile far *) 0x204B8C))

// Transmit FIFO Buffer Input Location 04
#define U1C1_IN04              (*((uword volatile far *) 0x204B90))

// Transmit FIFO Buffer Input Location 05
#define U1C1_IN05              (*((uword volatile far *) 0x204B94))

// Transmit FIFO Buffer Input Location 06
#define U1C1_IN06              (*((uword volatile far *) 0x204B98))

// Transmit FIFO Buffer Input Location 07
#define U1C1_IN07              (*((uword volatile far *) 0x204B9C))

// Transmit FIFO Buffer Input Location 08
#define U1C1_IN08              (*((uword volatile far *) 0x204BA0))

// Transmit FIFO Buffer Input Location 09
#define U1C1_IN09              (*((uword volatile far *) 0x204BA4))

// Transmit FIFO Buffer Input Location 10
#define U1C1_IN10              (*((uword volatile far *) 0x204BA8))

// Transmit FIFO Buffer Input Location 11
#define U1C1_IN11              (*((uword volatile far *) 0x204BAC))

// Transmit FIFO Buffer Input Location 12
#define U1C1_IN12              (*((uword volatile far *) 0x204BB0))

// Transmit FIFO Buffer Input Location 13
#define U1C1_IN13              (*((uword volatile far *) 0x204BB4))

// Transmit FIFO Buffer Input Location 14
#define U1C1_IN14              (*((uword volatile far *) 0x204BB8))

// Transmit FIFO Buffer Input Location 15
#define U1C1_IN15              (*((uword volatile far *) 0x204BBC))

// Transmit FIFO Buffer Input Location 16
#define U1C1_IN16              (*((uword volatile far *) 0x204BC0))

// Transmit FIFO Buffer Input Location 17
#define U1C1_IN17              (*((uword volatile far *) 0x204BC4))

// Transmit FIFO Buffer Input Location 18
#define U1C1_IN18              (*((uword volatile far *) 0x204BC8))

// Transmit FIFO Buffer Input Location 19
#define U1C1_IN19              (*((uword volatile far *) 0x204BCC))

// Transmit FIFO Buffer Input Location 20
#define U1C1_IN20              (*((uword volatile far *) 0x204BD0))

// Transmit FIFO Buffer Input Location 21
#define U1C1_IN21              (*((uword volatile far *) 0x204BD4))

// Transmit FIFO Buffer Input Location 22
#define U1C1_IN22              (*((uword volatile far *) 0x204BD8))

// Transmit FIFO Buffer Input Location 23
#define U1C1_IN23              (*((uword volatile far *) 0x204BDC))

// Transmit FIFO Buffer Input Location 24
#define U1C1_IN24              (*((uword volatile far *) 0x204BE0))

// Transmit FIFO Buffer Input Location 25
#define U1C1_IN25              (*((uword volatile far *) 0x204BE4))

// Transmit FIFO Buffer Input Location 26
#define U1C1_IN26              (*((uword volatile far *) 0x204BE8))

// Transmit FIFO Buffer Input Location 27
#define U1C1_IN27              (*((uword volatile far *) 0x204BEC))

// Transmit FIFO Buffer Input Location 28
#define U1C1_IN28              (*((uword volatile far *) 0x204BF0))

// Transmit FIFO Buffer Input Location 29
#define U1C1_IN29              (*((uword volatile far *) 0x204BF4))

// Transmit FIFO Buffer Input Location 30
#define U1C1_IN30              (*((uword volatile far *) 0x204BF8))

// Transmit FIFO Buffer Input Location 31
#define U1C1_IN31              (*((uword volatile far *) 0x204BFC))

// Interrupt Node Pointer Register H
#define U1C1_INPRH             (*((uword volatile far *) 0x204A16))

// Interrupt Node Pointer Register L
#define U1C1_INPRL             (*((uword volatile far *) 0x204A14))

// Kernel State Configuration Register
#define U1C1_KSCFG             (*((uword volatile far *) 0x204A0C))

// Receiver Buffer Output Register H for Debugger
#define U1C1_OUTDRH            (*((uword volatile far *) 0x204B26))

// Receiver Buffer Output Register L for Debugger
#define U1C1_OUTDRL            (*((uword volatile far *) 0x204B24))

// Receiver Buffer Output Register H
#define U1C1_OUTRH             (*((uword volatile far *) 0x204B22))

// Receiver Buffer Output Register L
#define U1C1_OUTRL             (*((uword volatile far *) 0x204B20))

// Protocol Control Register H
#define U1C1_PCRH              (*((uword volatile far *) 0x204A42))

// Protocol Control Register L
#define U1C1_PCRL              (*((uword volatile far *) 0x204A40))

// Protocol Status Clear Register
#define U1C1_PSCR              (*((uword volatile far *) 0x204A48))

// Protocol Status Register
#define U1C1_PSR               (*((uword volatile far *) 0x204A44))

// Receiver Buffer Control Register H
#define U1C1_RBCTRH            (*((uword volatile far *) 0x204B16))

// Receiver Buffer Control Register L
#define U1C1_RBCTRL            (*((uword volatile far *) 0x204B14))

// Receiver Buffer Register
#define U1C1_RBUF              (*((uword volatile far *) 0x204A5C))

// Receiver Buffer Register 0
#define U1C1_RBUF0             (*((uword volatile far *) 0x204A50))

// Receiver Buffer 01 Status Register H
#define U1C1_RBUF01SRH         (*((uword volatile far *) 0x204A62))

// Receiver Buffer 01 Status Register L
#define U1C1_RBUF01SRL         (*((uword volatile far *) 0x204A60))

// Receiver Buffer Register 1
#define U1C1_RBUF1             (*((uword volatile far *) 0x204A54))

// Receiver Buffer Reg. for Debugger
#define U1C1_RBUFD             (*((uword volatile far *) 0x204A4C))

// Receiver Buffer Status Register
#define U1C1_RBUFSR            (*((uword volatile far *) 0x204A58))

// Shift Control Register H
#define U1C1_SCTRH             (*((uword volatile far *) 0x204A32))

// Shift Control Register L
#define U1C1_SCTRL             (*((uword volatile far *) 0x204A30))

// Transmitter Buffer Control Reg. H
#define U1C1_TBCTRH            (*((uword volatile far *) 0x204B12))

// Transmitter Buffer Control Reg. L
#define U1C1_TBCTRL            (*((uword volatile far *) 0x204B10))

// Transmit Buffer Input Location 00
#define U1C1_TBUF00            (*((uword volatile far *) 0x204A80))

// Transmit Buffer Input Location 01
#define U1C1_TBUF01            (*((uword volatile far *) 0x204A84))

// Transmit Buffer Input Location 02
#define U1C1_TBUF02            (*((uword volatile far *) 0x204A88))

// Transmit Buffer Input Location 03
#define U1C1_TBUF03            (*((uword volatile far *) 0x204A8C))

// Transmit Buffer Input Location 04
#define U1C1_TBUF04            (*((uword volatile far *) 0x204A90))

// Transmit Buffer Input Location 05
#define U1C1_TBUF05            (*((uword volatile far *) 0x204A94))

// Transmit Buffer Input Location 06
#define U1C1_TBUF06            (*((uword volatile far *) 0x204A98))

// Transmit Buffer Input Location 07
#define U1C1_TBUF07            (*((uword volatile far *) 0x204A9C))

// Transmit Buffer Input Location 08
#define U1C1_TBUF08            (*((uword volatile far *) 0x204AA0))

// Transmit Buffer Input Location 09
#define U1C1_TBUF09            (*((uword volatile far *) 0x204AA4))

// Transmit Buffer Input Location 10
#define U1C1_TBUF10            (*((uword volatile far *) 0x204AA8))

// Transmit Buffer Input Location 11
#define U1C1_TBUF11            (*((uword volatile far *) 0x204AAC))

// Transmit Buffer Input Location 12
#define U1C1_TBUF12            (*((uword volatile far *) 0x204AB0))

// Transmit Buffer Input Location 13
#define U1C1_TBUF13            (*((uword volatile far *) 0x204AB4))

// Transmit Buffer Input Location 14
#define U1C1_TBUF14            (*((uword volatile far *) 0x204AB8))

// Transmit Buffer Input Location 15
#define U1C1_TBUF15            (*((uword volatile far *) 0x204ABC))

// Transmit Buffer Input Location 16
#define U1C1_TBUF16            (*((uword volatile far *) 0x204AC0))

// Transmit Buffer Input Location 17
#define U1C1_TBUF17            (*((uword volatile far *) 0x204AC4))

// Transmit Buffer Input Location 18
#define U1C1_TBUF18            (*((uword volatile far *) 0x204AC8))

// Transmit Buffer Input Location 19
#define U1C1_TBUF19            (*((uword volatile far *) 0x204ACC))

// Transmit Buffer Input Location 20
#define U1C1_TBUF20            (*((uword volatile far *) 0x204AD0))

// Transmit Buffer Input Location 21
#define U1C1_TBUF21            (*((uword volatile far *) 0x204AD4))

// Transmit Buffer Input Location 22
#define U1C1_TBUF22            (*((uword volatile far *) 0x204AD8))

// Transmit Buffer Input Location 23
#define U1C1_TBUF23            (*((uword volatile far *) 0x204ADC))

// Transmit Buffer Input Location 24
#define U1C1_TBUF24            (*((uword volatile far *) 0x204AE0))

// Transmit Buffer Input Location 25
#define U1C1_TBUF25            (*((uword volatile far *) 0x204AE4))

// Transmit Buffer Input Location 26
#define U1C1_TBUF26            (*((uword volatile far *) 0x204AE8))

// Transmit Buffer Input Location 27
#define U1C1_TBUF27            (*((uword volatile far *) 0x204AEC))

// Transmit Buffer Input Location 28
#define U1C1_TBUF28            (*((uword volatile far *) 0x204AF0))

// Transmit Buffer Input Location 29
#define U1C1_TBUF29            (*((uword volatile far *) 0x204AF4))

// Transmit Buffer Input Location 30
#define U1C1_TBUF30            (*((uword volatile far *) 0x204AF8))

// Transmit Buffer Input Location 31
#define U1C1_TBUF31            (*((uword volatile far *) 0x204AFC))

// Transmit Control/Status Register H
#define U1C1_TCSRH             (*((uword volatile far *) 0x204A3E))

// Transmit Control/Status Register L
#define U1C1_TCSRL             (*((uword volatile far *) 0x204A3C))

// Transmit / Receive Buffer Pointer Reg H
#define U1C1_TRBPTRH           (*((uword volatile far *) 0x204B0A))

// Transmit / Receive Buffer Pointer Reg L
#define U1C1_TRBPTRL           (*((uword volatile far *) 0x204B08))

// Transmit / Receive Buffer Status Clear Reg
#define U1C1_TRBSCR            (*((uword volatile far *) 0x204B1C))

// Transmit / Receive Buffer Status Reg H
#define U1C1_TRBSRH            (*((uword volatile far *) 0x204B1A))

// Transmit / Receive Buffer Status Reg. L
#define U1C1_TRBSRL            (*((uword volatile far *) 0x204B18))

// USIC Interrupt Control Reg. 0
#define U2C0_0IC               (*((uword volatile *) 0xF138))
#define U2C0_0IC_GPX                      ((T_Reg16 *) 0xF138)->bit8
#define U2C0_0IC_IE                       ((T_Reg16 *) 0xF138)->bit6
#define U2C0_0IC_IR                       ((T_Reg16 *) 0xF138)->bit7

// USIC Interrupt Control Reg. 1
#define U2C0_1IC               (*((uword volatile *) 0xF13A))
#define U2C0_1IC_GPX                      ((T_Reg16 *) 0xF13A)->bit8
#define U2C0_1IC_IE                       ((T_Reg16 *) 0xF13A)->bit6
#define U2C0_1IC_IR                       ((T_Reg16 *) 0xF13A)->bit7

// USIC Interrupt Control Reg. 2
#define U2C0_2IC               (*((uword volatile *) 0xF13C))
#define U2C0_2IC_GPX                      ((T_Reg16 *) 0xF13C)->bit8
#define U2C0_2IC_IE                       ((T_Reg16 *) 0xF13C)->bit6
#define U2C0_2IC_IR                       ((T_Reg16 *) 0xF13C)->bit7

// Baud Rate Generator Register H
#define U2C0_BRGH              (*((uword volatile far *) 0x20501E))

// Baud Rate Generator Register L
#define U2C0_BRGL              (*((uword volatile far *) 0x20501C))

// Bypass Data Register
#define U2C0_BYP               (*((uword volatile far *) 0x205100))

// Bypass Control Register H
#define U2C0_BYPCRH            (*((uword volatile far *) 0x205106))

// Bypass Control Register L
#define U2C0_BYPCRL            (*((uword volatile far *) 0x205104))

// Channel Configuration Register
#define U2C0_CCFG              (*((uword volatile far *) 0x205018))

// Channel Control Register
#define U2C0_CCR               (*((uword volatile far *) 0x205010))

// Input Control Register 0
#define U2C0_DX0CR             (*((uword volatile far *) 0x205020))

// Input Control Register 1
#define U2C0_DX1CR             (*((uword volatile far *) 0x205024))

// Input Control Register 2
#define U2C0_DX2CR             (*((uword volatile far *) 0x205028))

// Fractional Divider Register H
#define U2C0_FDRH              (*((uword volatile far *) 0x205006))

// Fractional Divider Register L
#define U2C0_FDRL              (*((uword volatile far *) 0x205004))

// Flag Modification Register H
#define U2C0_FMRH              (*((uword volatile far *) 0x20503A))

// Flag Modification Register L
#define U2C0_FMRL              (*((uword volatile far *) 0x205038))

// Transmit FIFO Buffer Input Location 00
#define U2C0_IN00              (*((uword volatile far *) 0x205180))

// Transmit FIFO Buffer Input Location 01
#define U2C0_IN01              (*((uword volatile far *) 0x205184))

// Transmit FIFO Buffer Input Location 02
#define U2C0_IN02              (*((uword volatile far *) 0x205188))

// Transmit FIFO Buffer Input Location 03
#define U2C0_IN03              (*((uword volatile far *) 0x20518C))

// Transmit FIFO Buffer Input Location 04
#define U2C0_IN04              (*((uword volatile far *) 0x205190))

// Transmit FIFO Buffer Input Location 05
#define U2C0_IN05              (*((uword volatile far *) 0x205194))

// Transmit FIFO Buffer Input Location 06
#define U2C0_IN06              (*((uword volatile far *) 0x205198))

// Transmit FIFO Buffer Input Location 07
#define U2C0_IN07              (*((uword volatile far *) 0x20519C))

// Transmit FIFO Buffer Input Location 08
#define U2C0_IN08              (*((uword volatile far *) 0x2051A0))

// Transmit FIFO Buffer Input Location 09
#define U2C0_IN09              (*((uword volatile far *) 0x2051A4))

// Transmit FIFO Buffer Input Location 10
#define U2C0_IN10              (*((uword volatile far *) 0x2051A8))

// Transmit FIFO Buffer Input Location 11
#define U2C0_IN11              (*((uword volatile far *) 0x2051AC))

// Transmit FIFO Buffer Input Location 12
#define U2C0_IN12              (*((uword volatile far *) 0x2051B0))

// Transmit FIFO Buffer Input Location 13
#define U2C0_IN13              (*((uword volatile far *) 0x2051B4))

// Transmit FIFO Buffer Input Location 14
#define U2C0_IN14              (*((uword volatile far *) 0x2051B8))

// Transmit FIFO Buffer Input Location 15
#define U2C0_IN15              (*((uword volatile far *) 0x2051BC))

// Transmit FIFO Buffer Input Location 16
#define U2C0_IN16              (*((uword volatile far *) 0x2051C0))

// Transmit FIFO Buffer Input Location 17
#define U2C0_IN17              (*((uword volatile far *) 0x2051C4))

// Transmit FIFO Buffer Input Location 18
#define U2C0_IN18              (*((uword volatile far *) 0x2051C8))

// Transmit FIFO Buffer Input Location 19
#define U2C0_IN19              (*((uword volatile far *) 0x2051CC))

// Transmit FIFO Buffer Input Location 20
#define U2C0_IN20              (*((uword volatile far *) 0x2051D0))

// Transmit FIFO Buffer Input Location 21
#define U2C0_IN21              (*((uword volatile far *) 0x2051D4))

// Transmit FIFO Buffer Input Location 22
#define U2C0_IN22              (*((uword volatile far *) 0x2051D8))

// Transmit FIFO Buffer Input Location 23
#define U2C0_IN23              (*((uword volatile far *) 0x2051DC))

// Transmit FIFO Buffer Input Location 24
#define U2C0_IN24              (*((uword volatile far *) 0x2051E0))

// Transmit FIFO Buffer Input Location 25
#define U2C0_IN25              (*((uword volatile far *) 0x2051E4))

// Transmit FIFO Buffer Input Location 26
#define U2C0_IN26              (*((uword volatile far *) 0x2051E8))

// Transmit FIFO Buffer Input Location 27
#define U2C0_IN27              (*((uword volatile far *) 0x2051EC))

// Transmit FIFO Buffer Input Location 28
#define U2C0_IN28              (*((uword volatile far *) 0x2051F0))

// Transmit FIFO Buffer Input Location 29
#define U2C0_IN29              (*((uword volatile far *) 0x2051F4))

// Transmit FIFO Buffer Input Location 30
#define U2C0_IN30              (*((uword volatile far *) 0x2051F8))

// Transmit FIFO Buffer Input Location 31
#define U2C0_IN31              (*((uword volatile far *) 0x2051FC))

// Interrupt Node Pointer Register H
#define U2C0_INPRH             (*((uword volatile far *) 0x205016))

// Interrupt Node Pointer Register L
#define U2C0_INPRL             (*((uword volatile far *) 0x205014))

// Kernel State Configuration Register
#define U2C0_KSCFG             (*((uword volatile far *) 0x20500C))

// Receiver Buffer Output Register H for Debugger
#define U2C0_OUTDRH            (*((uword volatile far *) 0x205126))

// Receiver Buffer Output Register L for Debugger
#define U2C0_OUTDRL            (*((uword volatile far *) 0x205124))

// Receiver Buffer Output Register H
#define U2C0_OUTRH             (*((uword volatile far *) 0x205122))

// Receiver Buffer Output Register L
#define U2C0_OUTRL             (*((uword volatile far *) 0x205120))

// Protocol Control Register H
#define U2C0_PCRH              (*((uword volatile far *) 0x205042))

// Protocol Control Register L
#define U2C0_PCRL              (*((uword volatile far *) 0x205040))

// Protocol Status Clear Register
#define U2C0_PSCR              (*((uword volatile far *) 0x205048))

// Protocol Status Register
#define U2C0_PSR               (*((uword volatile far *) 0x205044))

// Receiver Buffer Control Register H
#define U2C0_RBCTRH            (*((uword volatile far *) 0x205116))

// Receiver Buffer Control Register L
#define U2C0_RBCTRL            (*((uword volatile far *) 0x205114))

// Receiver Buffer Register
#define U2C0_RBUF              (*((uword volatile far *) 0x20505C))

// Receiver Buffer Register 0
#define U2C0_RBUF0             (*((uword volatile far *) 0x205050))

// Receiver Buffer 01 Status Register H
#define U2C0_RBUF01SRH         (*((uword volatile far *) 0x205062))

// Receiver Buffer 01 Status Register L
#define U2C0_RBUF01SRL         (*((uword volatile far *) 0x205060))

// Receiver Buffer Register 1
#define U2C0_RBUF1             (*((uword volatile far *) 0x205054))

// Receiver Buffer Reg. for Debugger
#define U2C0_RBUFD             (*((uword volatile far *) 0x20504C))

// Receiver Buffer Status Register
#define U2C0_RBUFSR            (*((uword volatile far *) 0x205058))

// Shift Control Register H
#define U2C0_SCTRH             (*((uword volatile far *) 0x205032))

// Shift Control Register L
#define U2C0_SCTRL             (*((uword volatile far *) 0x205030))

// Transmitter Buffer Control Reg. H
#define U2C0_TBCTRH            (*((uword volatile far *) 0x205112))

// Transmitter Buffer Control Reg. L
#define U2C0_TBCTRL            (*((uword volatile far *) 0x205110))

// Transmit Buffer Input Location 00
#define U2C0_TBUF00            (*((uword volatile far *) 0x205080))

// Transmit Buffer Input Location 01
#define U2C0_TBUF01            (*((uword volatile far *) 0x205084))

// Transmit Buffer Input Location 02
#define U2C0_TBUF02            (*((uword volatile far *) 0x205088))

// Transmit Buffer Input Location 03
#define U2C0_TBUF03            (*((uword volatile far *) 0x20508C))

// Transmit Buffer Input Location 04
#define U2C0_TBUF04            (*((uword volatile far *) 0x205090))

// Transmit Buffer Input Location 05
#define U2C0_TBUF05            (*((uword volatile far *) 0x205094))

// Transmit Buffer Input Location 06
#define U2C0_TBUF06            (*((uword volatile far *) 0x205098))

// Transmit Buffer Input Location 07
#define U2C0_TBUF07            (*((uword volatile far *) 0x20509C))

// Transmit Buffer Input Location 08
#define U2C0_TBUF08            (*((uword volatile far *) 0x2050A0))

// Transmit Buffer Input Location 09
#define U2C0_TBUF09            (*((uword volatile far *) 0x2050A4))

// Transmit Buffer Input Location 10
#define U2C0_TBUF10            (*((uword volatile far *) 0x2050A8))

// Transmit Buffer Input Location 11
#define U2C0_TBUF11            (*((uword volatile far *) 0x2050AC))

// Transmit Buffer Input Location 12
#define U2C0_TBUF12            (*((uword volatile far *) 0x2050B0))

// Transmit Buffer Input Location 13
#define U2C0_TBUF13            (*((uword volatile far *) 0x2050B4))

// Transmit Buffer Input Location 14
#define U2C0_TBUF14            (*((uword volatile far *) 0x2050B8))

// Transmit Buffer Input Location 15
#define U2C0_TBUF15            (*((uword volatile far *) 0x2050BC))

// Transmit Buffer Input Location 16
#define U2C0_TBUF16            (*((uword volatile far *) 0x2050C0))

// Transmit Buffer Input Location 17
#define U2C0_TBUF17            (*((uword volatile far *) 0x2050C4))

// Transmit Buffer Input Location 18
#define U2C0_TBUF18            (*((uword volatile far *) 0x2050C8))

// Transmit Buffer Input Location 19
#define U2C0_TBUF19            (*((uword volatile far *) 0x2050CC))

// Transmit Buffer Input Location 20
#define U2C0_TBUF20            (*((uword volatile far *) 0x2050D0))

// Transmit Buffer Input Location 21
#define U2C0_TBUF21            (*((uword volatile far *) 0x2050D4))

// Transmit Buffer Input Location 22
#define U2C0_TBUF22            (*((uword volatile far *) 0x2050D8))

// Transmit Buffer Input Location 23
#define U2C0_TBUF23            (*((uword volatile far *) 0x2050DC))

// Transmit Buffer Input Location 24
#define U2C0_TBUF24            (*((uword volatile far *) 0x2050E0))

// Transmit Buffer Input Location 25
#define U2C0_TBUF25            (*((uword volatile far *) 0x2050E4))

// Transmit Buffer Input Location 26
#define U2C0_TBUF26            (*((uword volatile far *) 0x2050E8))

// Transmit Buffer Input Location 27
#define U2C0_TBUF27            (*((uword volatile far *) 0x2050EC))

// Transmit Buffer Input Location 28
#define U2C0_TBUF28            (*((uword volatile far *) 0x2050F0))

// Transmit Buffer Input Location 29
#define U2C0_TBUF29            (*((uword volatile far *) 0x2050F4))

// Transmit Buffer Input Location 30
#define U2C0_TBUF30            (*((uword volatile far *) 0x2050F8))

// Transmit Buffer Input Location 31
#define U2C0_TBUF31            (*((uword volatile far *) 0x2050FC))

// Transmit Control/Status Register H
#define U2C0_TCSRH             (*((uword volatile far *) 0x20503E))

// Transmit Control/Status Register L
#define U2C0_TCSRL             (*((uword volatile far *) 0x20503C))

// Transmit / Receive Buffer Pointer Reg H
#define U2C0_TRBPTRH           (*((uword volatile far *) 0x20510A))

// Transmit / Receive Buffer Pointer Reg L
#define U2C0_TRBPTRL           (*((uword volatile far *) 0x205108))

// Transmit / Receive Buffer Status Clear Reg
#define U2C0_TRBSCR            (*((uword volatile far *) 0x20511C))

// Transmit / Receive Buffer Status Reg H
#define U2C0_TRBSRH            (*((uword volatile far *) 0x20511A))

// Transmit / Receive Buffer Status Reg. L
#define U2C0_TRBSRL            (*((uword volatile far *) 0x205118))

// USIC Interrupt Control Reg.
#define U2C1_0IC               (*((uword volatile *) 0xF13E))
#define U2C1_0IC_GPX                      ((T_Reg16 *) 0xF13E)->bit8
#define U2C1_0IC_IE                       ((T_Reg16 *) 0xF13E)->bit6
#define U2C1_0IC_IR                       ((T_Reg16 *) 0xF13E)->bit7

// USIC Interrupt Control Reg.
#define U2C1_1IC               (*((uword volatile *) 0xF180))
#define U2C1_1IC_GPX                      ((T_Reg16 *) 0xF180)->bit8
#define U2C1_1IC_IE                       ((T_Reg16 *) 0xF180)->bit6
#define U2C1_1IC_IR                       ((T_Reg16 *) 0xF180)->bit7

// USIC Interrupt Control Reg.
#define U2C1_2IC               (*((uword volatile *) 0xF182))
#define U2C1_2IC_GPX                      ((T_Reg16 *) 0xF182)->bit8
#define U2C1_2IC_IE                       ((T_Reg16 *) 0xF182)->bit6
#define U2C1_2IC_IR                       ((T_Reg16 *) 0xF182)->bit7

// Baud Rate Generator Register H
#define U2C1_BRGH              (*((uword volatile far *) 0x20521E))

// Baud Rate Generator Register L
#define U2C1_BRGL              (*((uword volatile far *) 0x20521C))

// Bypass Data Register
#define U2C1_BYP               (*((uword volatile far *) 0x205300))

// Bypass Control Register H
#define U2C1_BYPCRH            (*((uword volatile far *) 0x205306))

// Bypass Control Register L
#define U2C1_BYPCRL            (*((uword volatile far *) 0x205304))

// Channel Configuration Register
#define U2C1_CCFG              (*((uword volatile far *) 0x205218))

// Channel Control Register
#define U2C1_CCR               (*((uword volatile far *) 0x205210))

// Input Control Register 0
#define U2C1_DX0CR             (*((uword volatile far *) 0x205220))

// Input Control Register 1
#define U2C1_DX1CR             (*((uword volatile far *) 0x205224))

// Input Control Register 2
#define U2C1_DX2CR             (*((uword volatile far *) 0x205228))

// Fractional Divider Register H
#define U2C1_FDRH              (*((uword volatile far *) 0x205206))

// Fractional Divider Register L
#define U2C1_FDRL              (*((uword volatile far *) 0x205204))

// Flag Modification Register H
#define U2C1_FMRH              (*((uword volatile far *) 0x20523A))

// Flag Modification Register L
#define U2C1_FMRL              (*((uword volatile far *) 0x205238))

// Transmit FIFO Buffer Input Location 00
#define U2C1_IN00              (*((uword volatile far *) 0x205380))

// Transmit FIFO Buffer Input Location 01
#define U2C1_IN01              (*((uword volatile far *) 0x205384))

// Transmit FIFO Buffer Input Location 02
#define U2C1_IN02              (*((uword volatile far *) 0x205388))

// Transmit FIFO Buffer Input Location 03
#define U2C1_IN03              (*((uword volatile far *) 0x20538C))

// Transmit FIFO Buffer Input Location 04
#define U2C1_IN04              (*((uword volatile far *) 0x205390))

// Transmit FIFO Buffer Input Location 05
#define U2C1_IN05              (*((uword volatile far *) 0x205394))

// Transmit FIFO Buffer Input Location 06
#define U2C1_IN06              (*((uword volatile far *) 0x205398))

// Transmit FIFO Buffer Input Location 07
#define U2C1_IN07              (*((uword volatile far *) 0x20539C))

// Transmit FIFO Buffer Input Location 08
#define U2C1_IN08              (*((uword volatile far *) 0x2053A0))

// Transmit FIFO Buffer Input Location 09
#define U2C1_IN09              (*((uword volatile far *) 0x2053A4))

// Transmit FIFO Buffer Input Location 10
#define U2C1_IN10              (*((uword volatile far *) 0x2053A8))

// Transmit FIFO Buffer Input Location 11
#define U2C1_IN11              (*((uword volatile far *) 0x2053AC))

// Transmit FIFO Buffer Input Location 12
#define U2C1_IN12              (*((uword volatile far *) 0x2053B0))

// Transmit FIFO Buffer Input Location 13
#define U2C1_IN13              (*((uword volatile far *) 0x2053B4))

// Transmit FIFO Buffer Input Location 14
#define U2C1_IN14              (*((uword volatile far *) 0x2053B8))

// Transmit FIFO Buffer Input Location 15
#define U2C1_IN15              (*((uword volatile far *) 0x2053BC))

// Transmit FIFO Buffer Input Location 16
#define U2C1_IN16              (*((uword volatile far *) 0x2053C0))

// Transmit FIFO Buffer Input Location 17
#define U2C1_IN17              (*((uword volatile far *) 0x2053C4))

// Transmit FIFO Buffer Input Location 18
#define U2C1_IN18              (*((uword volatile far *) 0x2053C8))

// Transmit FIFO Buffer Input Location 19
#define U2C1_IN19              (*((uword volatile far *) 0x2053CC))

// Transmit FIFO Buffer Input Location 20
#define U2C1_IN20              (*((uword volatile far *) 0x2053D0))

// Transmit FIFO Buffer Input Location 21
#define U2C1_IN21              (*((uword volatile far *) 0x2053D4))

// Transmit FIFO Buffer Input Location 22
#define U2C1_IN22              (*((uword volatile far *) 0x2053D8))

// Transmit FIFO Buffer Input Location 23
#define U2C1_IN23              (*((uword volatile far *) 0x2053DC))

// Transmit FIFO Buffer Input Location 24
#define U2C1_IN24              (*((uword volatile far *) 0x2053E0))

// Transmit FIFO Buffer Input Location 25
#define U2C1_IN25              (*((uword volatile far *) 0x2053E4))

// Transmit FIFO Buffer Input Location 26
#define U2C1_IN26              (*((uword volatile far *) 0x2053E8))

// Transmit FIFO Buffer Input Location 27
#define U2C1_IN27              (*((uword volatile far *) 0x2053EC))

// Transmit FIFO Buffer Input Location 28
#define U2C1_IN28              (*((uword volatile far *) 0x2053F0))

// Transmit FIFO Buffer Input Location 29
#define U2C1_IN29              (*((uword volatile far *) 0x2053F4))

// Transmit FIFO Buffer Input Location 30
#define U2C1_IN30              (*((uword volatile far *) 0x2053F8))

// Transmit FIFO Buffer Input Location 31
#define U2C1_IN31              (*((uword volatile far *) 0x2053FC))

// Interrupt Node Pointer Register H
#define U2C1_INPRH             (*((uword volatile far *) 0x205216))

// Interrupt Node Pointer Register L
#define U2C1_INPRL             (*((uword volatile far *) 0x205214))

// Kernel State Configuration Register
#define U2C1_KSCFG             (*((uword volatile far *) 0x20520C))

// Receiver Buffer Output Register H for Debugger
#define U2C1_OUTDRH            (*((uword volatile far *) 0x205326))

// Receiver Buffer Output Register L for Debugger
#define U2C1_OUTDRL            (*((uword volatile far *) 0x205324))

// Receiver Buffer Output Register H
#define U2C1_OUTRH             (*((uword volatile far *) 0x205322))

// Receiver Buffer Output Register L
#define U2C1_OUTRL             (*((uword volatile far *) 0x205320))

// Protocol Control Register H
#define U2C1_PCRH              (*((uword volatile far *) 0x205242))

// Protocol Control Register L
#define U2C1_PCRL              (*((uword volatile far *) 0x205240))

// Protocol Status Clear Register
#define U2C1_PSCR              (*((uword volatile far *) 0x205248))

// Protocol Status Register
#define U2C1_PSR               (*((uword volatile far *) 0x205244))

// Receiver Buffer Control Register H
#define U2C1_RBCTRH            (*((uword volatile far *) 0x205316))

// Receiver Buffer Control Register L
#define U2C1_RBCTRL            (*((uword volatile far *) 0x205314))

// Receiver Buffer Register
#define U2C1_RBUF              (*((uword volatile far *) 0x20525C))

// Receiver Buffer Register 0
#define U2C1_RBUF0             (*((uword volatile far *) 0x205250))

// Receiver Buffer 01 Status Register H
#define U2C1_RBUF01SRH         (*((uword volatile far *) 0x205262))

// Receiver Buffer 01 Status Register L
#define U2C1_RBUF01SRL         (*((uword volatile far *) 0x205260))

// Receiver Buffer Register 1
#define U2C1_RBUF1             (*((uword volatile far *) 0x205254))

// Receiver Buffer Reg. for Debugger
#define U2C1_RBUFD             (*((uword volatile far *) 0x20524C))

// Receiver Buffer Status Register
#define U2C1_RBUFSR            (*((uword volatile far *) 0x205258))

// Shift Control Register H
#define U2C1_SCTRH             (*((uword volatile far *) 0x205232))

// Shift Control Register L
#define U2C1_SCTRL             (*((uword volatile far *) 0x205230))

// Transmitter Buffer Control Reg. H
#define U2C1_TBCTRH            (*((uword volatile far *) 0x205312))

// Transmitter Buffer Control Reg. L
#define U2C1_TBCTRL            (*((uword volatile far *) 0x205310))

// Transmit Buffer Input Location 00
#define U2C1_TBUF00            (*((uword volatile far *) 0x205280))

// Transmit Buffer Input Location 01
#define U2C1_TBUF01            (*((uword volatile far *) 0x205284))

// Transmit Buffer Input Location 02
#define U2C1_TBUF02            (*((uword volatile far *) 0x205288))

// Transmit Buffer Input Location 03
#define U2C1_TBUF03            (*((uword volatile far *) 0x20528C))

// Transmit Buffer Input Location 04
#define U2C1_TBUF04            (*((uword volatile far *) 0x205290))

// Transmit Buffer Input Location 05
#define U2C1_TBUF05            (*((uword volatile far *) 0x205294))

// Transmit Buffer Input Location 06
#define U2C1_TBUF06            (*((uword volatile far *) 0x205298))

// Transmit Buffer Input Location 07
#define U2C1_TBUF07            (*((uword volatile far *) 0x20529C))

// Transmit Buffer Input Location 08
#define U2C1_TBUF08            (*((uword volatile far *) 0x2052A0))

// Transmit Buffer Input Location 09
#define U2C1_TBUF09            (*((uword volatile far *) 0x2052A4))

// Transmit Buffer Input Location 10
#define U2C1_TBUF10            (*((uword volatile far *) 0x2052A8))

// Transmit Buffer Input Location 11
#define U2C1_TBUF11            (*((uword volatile far *) 0x2052AC))

// Transmit Buffer Input Location 12
#define U2C1_TBUF12            (*((uword volatile far *) 0x2052B0))

// Transmit Buffer Input Location 13
#define U2C1_TBUF13            (*((uword volatile far *) 0x2052B4))

// Transmit Buffer Input Location 14
#define U2C1_TBUF14            (*((uword volatile far *) 0x2052B8))

// Transmit Buffer Input Location 15
#define U2C1_TBUF15            (*((uword volatile far *) 0x2052BC))

// Transmit Buffer Input Location 16
#define U2C1_TBUF16            (*((uword volatile far *) 0x2052C0))

// Transmit Buffer Input Location 17
#define U2C1_TBUF17            (*((uword volatile far *) 0x2052C4))

// Transmit Buffer Input Location 18
#define U2C1_TBUF18            (*((uword volatile far *) 0x2052C8))

// Transmit Buffer Input Location 19
#define U2C1_TBUF19            (*((uword volatile far *) 0x2052CC))

// Transmit Buffer Input Location 20
#define U2C1_TBUF20            (*((uword volatile far *) 0x2052D0))

// Transmit Buffer Input Location 21
#define U2C1_TBUF21            (*((uword volatile far *) 0x2052D4))

// Transmit Buffer Input Location 22
#define U2C1_TBUF22            (*((uword volatile far *) 0x2052D8))

// Transmit Buffer Input Location 23
#define U2C1_TBUF23            (*((uword volatile far *) 0x2052DC))

// Transmit Buffer Input Location 24
#define U2C1_TBUF24            (*((uword volatile far *) 0x2052E0))

// Transmit Buffer Input Location 25
#define U2C1_TBUF25            (*((uword volatile far *) 0x2052E4))

// Transmit Buffer Input Location 26
#define U2C1_TBUF26            (*((uword volatile far *) 0x2052E8))

// Transmit Buffer Input Location 27
#define U2C1_TBUF27            (*((uword volatile far *) 0x2052EC))

// Transmit Buffer Input Location 28
#define U2C1_TBUF28            (*((uword volatile far *) 0x2052F0))

// Transmit Buffer Input Location 29
#define U2C1_TBUF29            (*((uword volatile far *) 0x2052F4))

// Transmit Buffer Input Location 30
#define U2C1_TBUF30            (*((uword volatile far *) 0x2052F8))

// Transmit Buffer Input Location 31
#define U2C1_TBUF31            (*((uword volatile far *) 0x2052FC))

// Transmit Control/Status Register H
#define U2C1_TCSRH             (*((uword volatile far *) 0x20523E))

// Transmit Control/Status Register L
#define U2C1_TCSRL             (*((uword volatile far *) 0x20523C))

// Transmit / Receive Buffer Pointer Reg H
#define U2C1_TRBPTRH           (*((uword volatile far *) 0x20530A))

// Transmit / Receive Buffer Pointer Reg L
#define U2C1_TRBPTRL           (*((uword volatile far *) 0x205308))

// Transmit / Receive Buffer Status Clear Reg
#define U2C1_TRBSCR            (*((uword volatile far *) 0x20531C))

// Transmit / Receive Buffer Status Reg H
#define U2C1_TRBSRH            (*((uword volatile far *) 0x20531A))

// Transmit / Receive Buffer Status Reg. L
#define U2C1_TRBSRL            (*((uword volatile far *) 0x205318))

// USIC Interrupt Control Reg. 0
#define U3C0_0IC               (*((uword volatile *) 0xF184))
#define U3C0_0IC_GPX                      ((T_Reg16 *) 0xF184)->bit8
#define U3C0_0IC_IE                       ((T_Reg16 *) 0xF184)->bit6
#define U3C0_0IC_IR                       ((T_Reg16 *) 0xF184)->bit7

// USIC Interrupt Control Reg. 1
#define U3C0_1IC               (*((uword volatile *) 0xF186))
#define U3C0_1IC_GPX                      ((T_Reg16 *) 0xF186)->bit8
#define U3C0_1IC_IE                       ((T_Reg16 *) 0xF186)->bit6
#define U3C0_1IC_IR                       ((T_Reg16 *) 0xF186)->bit7

// USIC Interrupt Control Reg. 2
#define U3C0_2IC               (*((uword volatile *) 0xF188))
#define U3C0_2IC_GPX                      ((T_Reg16 *) 0xF188)->bit8
#define U3C0_2IC_IE                       ((T_Reg16 *) 0xF188)->bit6
#define U3C0_2IC_IR                       ((T_Reg16 *) 0xF188)->bit7

// Baud Rate Generator Register H
#define U3C0_BRGH              (*((uword volatile far *) 0x20581E))

// Baud Rate Generator Register L
#define U3C0_BRGL              (*((uword volatile far *) 0x20581C))

// Bypass Data Register
#define U3C0_BYP               (*((uword volatile far *) 0x205900))

// Bypass Control Register H
#define U3C0_BYPCRH            (*((uword volatile far *) 0x205906))

// Bypass Control Register L
#define U3C0_BYPCRL            (*((uword volatile far *) 0x205904))

// Channel Configuration Register
#define U3C0_CCFG              (*((uword volatile far *) 0x205818))

// Channel Control Register
#define U3C0_CCR               (*((uword volatile far *) 0x205810))

// Input Control Register 0
#define U3C0_DX0CR             (*((uword volatile far *) 0x205820))

// Input Control Register 1
#define U3C0_DX1CR             (*((uword volatile far *) 0x205824))

// Input Control Register 2
#define U3C0_DX2CR             (*((uword volatile far *) 0x205828))

// Fractional Divider Register H
#define U3C0_FDRH              (*((uword volatile far *) 0x205806))

// Fractional Divider Register L
#define U3C0_FDRL              (*((uword volatile far *) 0x205804))

// Flag Modification Register H
#define U3C0_FMRH              (*((uword volatile far *) 0x20583A))

// Flag Modification Register L
#define U3C0_FMRL              (*((uword volatile far *) 0x205838))

// Transmit FIFO Buffer Input Location 00
#define U3C0_IN00              (*((uword volatile far *) 0x205980))

// Transmit FIFO Buffer Input Location 01
#define U3C0_IN01              (*((uword volatile far *) 0x205984))

// Transmit FIFO Buffer Input Location 02
#define U3C0_IN02              (*((uword volatile far *) 0x205988))

// Transmit FIFO Buffer Input Location 03
#define U3C0_IN03              (*((uword volatile far *) 0x20598C))

// Transmit FIFO Buffer Input Location 04
#define U3C0_IN04              (*((uword volatile far *) 0x205990))

// Transmit FIFO Buffer Input Location 05
#define U3C0_IN05              (*((uword volatile far *) 0x205994))

// Transmit FIFO Buffer Input Location 06
#define U3C0_IN06              (*((uword volatile far *) 0x205998))

// Transmit FIFO Buffer Input Location 07
#define U3C0_IN07              (*((uword volatile far *) 0x20599C))

// Transmit FIFO Buffer Input Location 08
#define U3C0_IN08              (*((uword volatile far *) 0x2059A0))

// Transmit FIFO Buffer Input Location 09
#define U3C0_IN09              (*((uword volatile far *) 0x2059A4))

// Transmit FIFO Buffer Input Location 10
#define U3C0_IN10              (*((uword volatile far *) 0x2059A8))

// Transmit FIFO Buffer Input Location 11
#define U3C0_IN11              (*((uword volatile far *) 0x2059AC))

// Transmit FIFO Buffer Input Location 12
#define U3C0_IN12              (*((uword volatile far *) 0x2059B0))

// Transmit FIFO Buffer Input Location 13
#define U3C0_IN13              (*((uword volatile far *) 0x2059B4))

// Transmit FIFO Buffer Input Location 14
#define U3C0_IN14              (*((uword volatile far *) 0x2059B8))

// Transmit FIFO Buffer Input Location 15
#define U3C0_IN15              (*((uword volatile far *) 0x2059BC))

// Transmit FIFO Buffer Input Location 16
#define U3C0_IN16              (*((uword volatile far *) 0x2059C0))

// Transmit FIFO Buffer Input Location 17
#define U3C0_IN17              (*((uword volatile far *) 0x2059C4))

// Transmit FIFO Buffer Input Location 18
#define U3C0_IN18              (*((uword volatile far *) 0x2059C8))

// Transmit FIFO Buffer Input Location 19
#define U3C0_IN19              (*((uword volatile far *) 0x2059CC))

// Transmit FIFO Buffer Input Location 20
#define U3C0_IN20              (*((uword volatile far *) 0x2059D0))

// Transmit FIFO Buffer Input Location 21
#define U3C0_IN21              (*((uword volatile far *) 0x2059D4))

// Transmit FIFO Buffer Input Location 22
#define U3C0_IN22              (*((uword volatile far *) 0x2059D8))

// Transmit FIFO Buffer Input Location 23
#define U3C0_IN23              (*((uword volatile far *) 0x2059DC))

// Transmit FIFO Buffer Input Location 24
#define U3C0_IN24              (*((uword volatile far *) 0x2059E0))

// Transmit FIFO Buffer Input Location 25
#define U3C0_IN25              (*((uword volatile far *) 0x2059E4))

// Transmit FIFO Buffer Input Location 26
#define U3C0_IN26              (*((uword volatile far *) 0x2059E8))

// Transmit FIFO Buffer Input Location 27
#define U3C0_IN27              (*((uword volatile far *) 0x2059EC))

// Transmit FIFO Buffer Input Location 28
#define U3C0_IN28              (*((uword volatile far *) 0x2059F0))

// Transmit FIFO Buffer Input Location 29
#define U3C0_IN29              (*((uword volatile far *) 0x2059F4))

// Transmit FIFO Buffer Input Location 30
#define U3C0_IN30              (*((uword volatile far *) 0x2059F8))

// Transmit FIFO Buffer Input Location 31
#define U3C0_IN31              (*((uword volatile far *) 0x2059FC))

// Interrupt Node Pointer Register H
#define U3C0_INPRH             (*((uword volatile far *) 0x205816))

// Interrupt Node Pointer Register L
#define U3C0_INPRL             (*((uword volatile far *) 0x205814))

// Kernel State Configuration Register
#define U3C0_KSCFG             (*((uword volatile far *) 0x20580C))

// Receiver Buffer Output Register H for Debugger
#define U3C0_OUTDRH            (*((uword volatile far *) 0x205926))

// Receiver Buffer Output Register L for Debugger
#define U3C0_OUTDRL            (*((uword volatile far *) 0x205924))

// Receiver Buffer Output Register H
#define U3C0_OUTRH             (*((uword volatile far *) 0x205922))

// Receiver Buffer Output Register L
#define U3C0_OUTRL             (*((uword volatile far *) 0x205920))

// Protocol Control Register H
#define U3C0_PCRH              (*((uword volatile far *) 0x205842))

// Protocol Control Register L
#define U3C0_PCRL              (*((uword volatile far *) 0x205840))

// Protocol Status Clear Register
#define U3C0_PSCR              (*((uword volatile far *) 0x205848))

// Protocol Status Register
#define U3C0_PSR               (*((uword volatile far *) 0x205844))

// Receiver Buffer Control Register H
#define U3C0_RBCTRH            (*((uword volatile far *) 0x205916))

// Receiver Buffer Control Register L
#define U3C0_RBCTRL            (*((uword volatile far *) 0x205914))

// Receiver Buffer Register
#define U3C0_RBUF              (*((uword volatile far *) 0x20585C))

// Receiver Buffer Register 0
#define U3C0_RBUF0             (*((uword volatile far *) 0x205850))

// Receiver Buffer 01 Status Register H
#define U3C0_RBUF01SRH         (*((uword volatile far *) 0x205862))

// Receiver Buffer 01 Status Register L
#define U3C0_RBUF01SRL         (*((uword volatile far *) 0x205860))

// Receiver Buffer Register 1
#define U3C0_RBUF1             (*((uword volatile far *) 0x205854))

// Receiver Buffer Reg. for Debugger
#define U3C0_RBUFD             (*((uword volatile far *) 0x20584C))

// Receiver Buffer Status Register
#define U3C0_RBUFSR            (*((uword volatile far *) 0x205858))

// Shift Control Register H
#define U3C0_SCTRH             (*((uword volatile far *) 0x205832))

// Shift Control Register L
#define U3C0_SCTRL             (*((uword volatile far *) 0x205830))

// Transmitter Buffer Control Reg. H
#define U3C0_TBCTRH            (*((uword volatile far *) 0x205912))

// Transmitter Buffer Control Reg. L
#define U3C0_TBCTRL            (*((uword volatile far *) 0x205910))

// Transmit Buffer Input Location 00
#define U3C0_TBUF00            (*((uword volatile far *) 0x205880))

// Transmit Buffer Input Location 01
#define U3C0_TBUF01            (*((uword volatile far *) 0x205884))

// Transmit Buffer Input Location 02
#define U3C0_TBUF02            (*((uword volatile far *) 0x205888))

// Transmit Buffer Input Location 03
#define U3C0_TBUF03            (*((uword volatile far *) 0x20588C))

// Transmit Buffer Input Location 04
#define U3C0_TBUF04            (*((uword volatile far *) 0x205890))

// Transmit Buffer Input Location 05
#define U3C0_TBUF05            (*((uword volatile far *) 0x205894))

// Transmit Buffer Input Location 06
#define U3C0_TBUF06            (*((uword volatile far *) 0x205898))

// Transmit Buffer Input Location 07
#define U3C0_TBUF07            (*((uword volatile far *) 0x20589C))

// Transmit Buffer Input Location 08
#define U3C0_TBUF08            (*((uword volatile far *) 0x2058A0))

// Transmit Buffer Input Location 09
#define U3C0_TBUF09            (*((uword volatile far *) 0x2058A4))

// Transmit Buffer Input Location 10
#define U3C0_TBUF10            (*((uword volatile far *) 0x2058A8))

// Transmit Buffer Input Location 11
#define U3C0_TBUF11            (*((uword volatile far *) 0x2058AC))

// Transmit Buffer Input Location 12
#define U3C0_TBUF12            (*((uword volatile far *) 0x2058B0))

// Transmit Buffer Input Location 13
#define U3C0_TBUF13            (*((uword volatile far *) 0x2058B4))

// Transmit Buffer Input Location 14
#define U3C0_TBUF14            (*((uword volatile far *) 0x2058B8))

// Transmit Buffer Input Location 15
#define U3C0_TBUF15            (*((uword volatile far *) 0x2058BC))

// Transmit Buffer Input Location 16
#define U3C0_TBUF16            (*((uword volatile far *) 0x2058C0))

// Transmit Buffer Input Location 17
#define U3C0_TBUF17            (*((uword volatile far *) 0x2058C4))

// Transmit Buffer Input Location 18
#define U3C0_TBUF18            (*((uword volatile far *) 0x2058C8))

// Transmit Buffer Input Location 19
#define U3C0_TBUF19            (*((uword volatile far *) 0x2058CC))

// Transmit Buffer Input Location 20
#define U3C0_TBUF20            (*((uword volatile far *) 0x2058D0))

// Transmit Buffer Input Location 21
#define U3C0_TBUF21            (*((uword volatile far *) 0x2058D4))

// Transmit Buffer Input Location 22
#define U3C0_TBUF22            (*((uword volatile far *) 0x2058D8))

// Transmit Buffer Input Location 23
#define U3C0_TBUF23            (*((uword volatile far *) 0x2058DC))

// Transmit Buffer Input Location 24
#define U3C0_TBUF24            (*((uword volatile far *) 0x2058E0))

// Transmit Buffer Input Location 25
#define U3C0_TBUF25            (*((uword volatile far *) 0x2058E4))

// Transmit Buffer Input Location 26
#define U3C0_TBUF26            (*((uword volatile far *) 0x2058E8))

// Transmit Buffer Input Location 27
#define U3C0_TBUF27            (*((uword volatile far *) 0x2058EC))

// Transmit Buffer Input Location 28
#define U3C0_TBUF28            (*((uword volatile far *) 0x2058F0))

// Transmit Buffer Input Location 29
#define U3C0_TBUF29            (*((uword volatile far *) 0x2058F4))

// Transmit Buffer Input Location 30
#define U3C0_TBUF30            (*((uword volatile far *) 0x2058F8))

// Transmit Buffer Input Location 31
#define U3C0_TBUF31            (*((uword volatile far *) 0x2058FC))

// Transmit Control/Status Register H
#define U3C0_TCSRH             (*((uword volatile far *) 0x20583E))

// Transmit Control/Status Register L
#define U3C0_TCSRL             (*((uword volatile far *) 0x20583C))

// Transmit / Receive Buffer Pointer Reg H
#define U3C0_TRBPTRH           (*((uword volatile far *) 0x20590A))

// Transmit / Receive Buffer Pointer Reg L
#define U3C0_TRBPTRL           (*((uword volatile far *) 0x205908))

// Transmit / Receive Buffer Status Clear Reg
#define U3C0_TRBSCR            (*((uword volatile far *) 0x20591C))

// Transmit / Receive Buffer Status Reg H
#define U3C0_TRBSRH            (*((uword volatile far *) 0x20591A))

// Transmit / Receive Buffer Status Reg. L
#define U3C0_TRBSRL            (*((uword volatile far *) 0x205918))

// USIC Interrupt Control Reg. 0
#define U3C1_0IC               (*((uword volatile *) 0xF18A))
#define U3C1_0IC_GPX                      ((T_Reg16 *) 0xF18A)->bit8
#define U3C1_0IC_IE                       ((T_Reg16 *) 0xF18A)->bit6
#define U3C1_0IC_IR                       ((T_Reg16 *) 0xF18A)->bit7

// USIC Interrupt Control Reg. 1
#define U3C1_1IC               (*((uword volatile *) 0xF18C))
#define U3C1_1IC_GPX                      ((T_Reg16 *) 0xF18C)->bit8
#define U3C1_1IC_IE                       ((T_Reg16 *) 0xF18C)->bit6
#define U3C1_1IC_IR                       ((T_Reg16 *) 0xF18C)->bit7

// USIC Interrupt Control Reg. 2
#define U3C1_2IC               (*((uword volatile *) 0xF18E))
#define U3C1_2IC_GPX                      ((T_Reg16 *) 0xF18E)->bit8
#define U3C1_2IC_IE                       ((T_Reg16 *) 0xF18E)->bit6
#define U3C1_2IC_IR                       ((T_Reg16 *) 0xF18E)->bit7

// Baud Rate Generator Register H
#define U3C1_BRGH              (*((uword volatile far *) 0x205A1E))

// Baud Rate Generator Register L
#define U3C1_BRGL              (*((uword volatile far *) 0x205A1C))

// Bypass Data Register
#define U3C1_BYP               (*((uword volatile far *) 0x205B00))

// Bypass Control Register H
#define U3C1_BYPCRH            (*((uword volatile far *) 0x205B06))

// Bypass Control Register L
#define U3C1_BYPCRL            (*((uword volatile far *) 0x205B04))

// Channel Configuration Register
#define U3C1_CCFG              (*((uword volatile far *) 0x205A18))

// Channel Control Register
#define U3C1_CCR               (*((uword volatile far *) 0x205A10))

// Input Control Register 0
#define U3C1_DX0CR             (*((uword volatile far *) 0x205A20))

// Input Control Register 1
#define U3C1_DX1CR             (*((uword volatile far *) 0x205A24))

// Input Control Register 2
#define U3C1_DX2CR             (*((uword volatile far *) 0x205A28))

// Fractional Divider Register H
#define U3C1_FDRH              (*((uword volatile far *) 0x205A06))

// Fractional Divider Register L
#define U3C1_FDRL              (*((uword volatile far *) 0x205A04))

// Flag Modification Register H
#define U3C1_FMRH              (*((uword volatile far *) 0x205A3A))

// Flag Modification Register L
#define U3C1_FMRL              (*((uword volatile far *) 0x205A38))

// Transmit FIFO Buffer Input Location 00
#define U3C1_IN00              (*((uword volatile far *) 0x205B80))

// Transmit FIFO Buffer Input Location 01
#define U3C1_IN01              (*((uword volatile far *) 0x205B84))

// Transmit FIFO Buffer Input Location 02
#define U3C1_IN02              (*((uword volatile far *) 0x205B88))

// Transmit FIFO Buffer Input Location 03
#define U3C1_IN03              (*((uword volatile far *) 0x205B8C))

// Transmit FIFO Buffer Input Location 04
#define U3C1_IN04              (*((uword volatile far *) 0x205B90))

// Transmit FIFO Buffer Input Location 05
#define U3C1_IN05              (*((uword volatile far *) 0x205B94))

// Transmit FIFO Buffer Input Location 06
#define U3C1_IN06              (*((uword volatile far *) 0x205B98))

// Transmit FIFO Buffer Input Location 07
#define U3C1_IN07              (*((uword volatile far *) 0x205B9C))

// Transmit FIFO Buffer Input Location 08
#define U3C1_IN08              (*((uword volatile far *) 0x205BA0))

// Transmit FIFO Buffer Input Location 09
#define U3C1_IN09              (*((uword volatile far *) 0x205BA4))

// Transmit FIFO Buffer Input Location 10
#define U3C1_IN10              (*((uword volatile far *) 0x205BA8))

// Transmit FIFO Buffer Input Location 11
#define U3C1_IN11              (*((uword volatile far *) 0x205BAC))

// Transmit FIFO Buffer Input Location 12
#define U3C1_IN12              (*((uword volatile far *) 0x205BB0))

// Transmit FIFO Buffer Input Location 13
#define U3C1_IN13              (*((uword volatile far *) 0x205BB4))

// Transmit FIFO Buffer Input Location 14
#define U3C1_IN14              (*((uword volatile far *) 0x205BB8))

// Transmit FIFO Buffer Input Location 15
#define U3C1_IN15              (*((uword volatile far *) 0x205BBC))

// Transmit FIFO Buffer Input Location 16
#define U3C1_IN16              (*((uword volatile far *) 0x205BC0))

// Transmit FIFO Buffer Input Location 17
#define U3C1_IN17              (*((uword volatile far *) 0x205BC4))

// Transmit FIFO Buffer Input Location 18
#define U3C1_IN18              (*((uword volatile far *) 0x205BC8))

// Transmit FIFO Buffer Input Location 19
#define U3C1_IN19              (*((uword volatile far *) 0x205BCC))

// Transmit FIFO Buffer Input Location 20
#define U3C1_IN20              (*((uword volatile far *) 0x205BD0))

// Transmit FIFO Buffer Input Location 21
#define U3C1_IN21              (*((uword volatile far *) 0x205BD4))

// Transmit FIFO Buffer Input Location 22
#define U3C1_IN22              (*((uword volatile far *) 0x205BD8))

// Transmit FIFO Buffer Input Location 23
#define U3C1_IN23              (*((uword volatile far *) 0x205BDC))

// Transmit FIFO Buffer Input Location 24
#define U3C1_IN24              (*((uword volatile far *) 0x205BE0))

// Transmit FIFO Buffer Input Location 25
#define U3C1_IN25              (*((uword volatile far *) 0x205BE4))

// Transmit FIFO Buffer Input Location 26
#define U3C1_IN26              (*((uword volatile far *) 0x205BE8))

// Transmit FIFO Buffer Input Location 27
#define U3C1_IN27              (*((uword volatile far *) 0x205BEC))

// Transmit FIFO Buffer Input Location 28
#define U3C1_IN28              (*((uword volatile far *) 0x205BF0))

// Transmit FIFO Buffer Input Location 29
#define U3C1_IN29              (*((uword volatile far *) 0x205BF4))

// Transmit FIFO Buffer Input Location 30
#define U3C1_IN30              (*((uword volatile far *) 0x205BF8))

// Transmit FIFO Buffer Input Location 31
#define U3C1_IN31              (*((uword volatile far *) 0x205BFC))

// Interrupt Node Pointer Register H
#define U3C1_INPRH             (*((uword volatile far *) 0x205A16))

// Interrupt Node Pointer Register L
#define U3C1_INPRL             (*((uword volatile far *) 0x205A14))

// Kernel State Configuration Register
#define U3C1_KSCFG             (*((uword volatile far *) 0x205A0C))

// Receiver Buffer Output Register H for Debugger
#define U3C1_OUTDRH            (*((uword volatile far *) 0x205B26))

// Receiver Buffer Output Register L for Debugger
#define U3C1_OUTDRL            (*((uword volatile far *) 0x205B24))

// Receiver Buffer Output Register H
#define U3C1_OUTRH             (*((uword volatile far *) 0x205B22))

// Receiver Buffer Output Register L
#define U3C1_OUTRL             (*((uword volatile far *) 0x205B20))

// Protocol Control Register H
#define U3C1_PCRH              (*((uword volatile far *) 0x205A42))

// Protocol Control Register L
#define U3C1_PCRL              (*((uword volatile far *) 0x205A40))

// Protocol Status Clear Register
#define U3C1_PSCR              (*((uword volatile far *) 0x205A48))

// Protocol Status Register
#define U3C1_PSR               (*((uword volatile far *) 0x205A44))

// Receiver Buffer Control Register H
#define U3C1_RBCTRH            (*((uword volatile far *) 0x205B16))

// Receiver Buffer Control Register L
#define U3C1_RBCTRL            (*((uword volatile far *) 0x205B14))

// Receiver Buffer Register
#define U3C1_RBUF              (*((uword volatile far *) 0x205A5C))

// Receiver Buffer Register 0
#define U3C1_RBUF0             (*((uword volatile far *) 0x205A50))

// Receiver Buffer 01 Status Register H
#define U3C1_RBUF01SRH         (*((uword volatile far *) 0x205A62))

// Receiver Buffer 01 Status Register L
#define U3C1_RBUF01SRL         (*((uword volatile far *) 0x205A60))

// Receiver Buffer Register 1
#define U3C1_RBUF1             (*((uword volatile far *) 0x205A54))

// Receiver Buffer Reg. for Debugger
#define U3C1_RBUFD             (*((uword volatile far *) 0x205A4C))

// Receiver Buffer Status Register
#define U3C1_RBUFSR            (*((uword volatile far *) 0x205A58))

// Shift Control Register H
#define U3C1_SCTRH             (*((uword volatile far *) 0x205A32))

// Shift Control Register L
#define U3C1_SCTRL             (*((uword volatile far *) 0x205A30))

// Transmitter Buffer Control Reg. H
#define U3C1_TBCTRH            (*((uword volatile far *) 0x205B12))

// Transmitter Buffer Control Reg. L
#define U3C1_TBCTRL            (*((uword volatile far *) 0x205B10))

// Transmit Buffer Input Location 00
#define U3C1_TBUF00            (*((uword volatile far *) 0x205A80))

// Transmit Buffer Input Location 01
#define U3C1_TBUF01            (*((uword volatile far *) 0x205A84))

// Transmit Buffer Input Location 02
#define U3C1_TBUF02            (*((uword volatile far *) 0x205A88))

// Transmit Buffer Input Location 03
#define U3C1_TBUF03            (*((uword volatile far *) 0x205A8C))

// Transmit Buffer Input Location 04
#define U3C1_TBUF04            (*((uword volatile far *) 0x205A90))

// Transmit Buffer Input Location 05
#define U3C1_TBUF05            (*((uword volatile far *) 0x205A94))

// Transmit Buffer Input Location 06
#define U3C1_TBUF06            (*((uword volatile far *) 0x205A98))

// Transmit Buffer Input Location 07
#define U3C1_TBUF07            (*((uword volatile far *) 0x205A9C))

// Transmit Buffer Input Location 08
#define U3C1_TBUF08            (*((uword volatile far *) 0x205AA0))

// Transmit Buffer Input Location 09
#define U3C1_TBUF09            (*((uword volatile far *) 0x205AA4))

// Transmit Buffer Input Location 10
#define U3C1_TBUF10            (*((uword volatile far *) 0x205AA8))

// Transmit Buffer Input Location 11
#define U3C1_TBUF11            (*((uword volatile far *) 0x205AAC))

// Transmit Buffer Input Location 12
#define U3C1_TBUF12            (*((uword volatile far *) 0x205AB0))

// Transmit Buffer Input Location 13
#define U3C1_TBUF13            (*((uword volatile far *) 0x205AB4))

// Transmit Buffer Input Location 14
#define U3C1_TBUF14            (*((uword volatile far *) 0x205AB8))

// Transmit Buffer Input Location 15
#define U3C1_TBUF15            (*((uword volatile far *) 0x205ABC))

// Transmit Buffer Input Location 16
#define U3C1_TBUF16            (*((uword volatile far *) 0x205AC0))

// Transmit Buffer Input Location 17
#define U3C1_TBUF17            (*((uword volatile far *) 0x205AC4))

// Transmit Buffer Input Location 18
#define U3C1_TBUF18            (*((uword volatile far *) 0x205AC8))

// Transmit Buffer Input Location 19
#define U3C1_TBUF19            (*((uword volatile far *) 0x205ACC))

// Transmit Buffer Input Location 20
#define U3C1_TBUF20            (*((uword volatile far *) 0x205AD0))

// Transmit Buffer Input Location 21
#define U3C1_TBUF21            (*((uword volatile far *) 0x205AD4))

// Transmit Buffer Input Location 22
#define U3C1_TBUF22            (*((uword volatile far *) 0x205AD8))

// Transmit Buffer Input Location 23
#define U3C1_TBUF23            (*((uword volatile far *) 0x205ADC))

// Transmit Buffer Input Location 24
#define U3C1_TBUF24            (*((uword volatile far *) 0x205AE0))

// Transmit Buffer Input Location 25
#define U3C1_TBUF25            (*((uword volatile far *) 0x205AE4))

// Transmit Buffer Input Location 26
#define U3C1_TBUF26            (*((uword volatile far *) 0x205AE8))

// Transmit Buffer Input Location 27
#define U3C1_TBUF27            (*((uword volatile far *) 0x205AEC))

// Transmit Buffer Input Location 28
#define U3C1_TBUF28            (*((uword volatile far *) 0x205AF0))

// Transmit Buffer Input Location 29
#define U3C1_TBUF29            (*((uword volatile far *) 0x205AF4))

// Transmit Buffer Input Location 30
#define U3C1_TBUF30            (*((uword volatile far *) 0x205AF8))

// Transmit Buffer Input Location 31
#define U3C1_TBUF31            (*((uword volatile far *) 0x205AFC))

// Transmit Control/Status Register H
#define U3C1_TCSRH             (*((uword volatile far *) 0x205A3E))

// Transmit Control/Status Register L
#define U3C1_TCSRL             (*((uword volatile far *) 0x205A3C))

// Transmit / Receive Buffer Pointer Reg H
#define U3C1_TRBPTRH           (*((uword volatile far *) 0x205B0A))

// Transmit / Receive Buffer Pointer Reg L
#define U3C1_TRBPTRL           (*((uword volatile far *) 0x205B08))

// Transmit / Receive Buffer Status Clear Reg
#define U3C1_TRBSCR            (*((uword volatile far *) 0x205B1C))

// Transmit / Receive Buffer Status Reg H
#define U3C1_TRBSRH            (*((uword volatile far *) 0x205B1A))

// Transmit / Receive Buffer Status Reg. L
#define U3C1_TRBSRL            (*((uword volatile far *) 0x205B18))

// Module Identification Register H
#define USIC0_IDH              (*((uword volatile far *) 0x20400A))

// Module Identification Register L
#define USIC0_IDL              (*((uword volatile far *) 0x204008))

// Module Identification Register H
#define USIC1_IDH              (*((uword volatile far *) 0x20480A))

// Module Identification Register L
#define USIC1_IDL              (*((uword volatile far *) 0x204808))

// Module Identification Register H
#define USIC2_IDH              (*((uword volatile far *) 0x20500A))

// Module Identification Register L
#define USIC2_IDL              (*((uword volatile far *) 0x205008))

// Module Identification Register H
#define USIC3_IDH              (*((uword volatile far *) 0x20580A))

// Module Identification Register L
#define USIC3_IDL              (*((uword volatile far *) 0x205808))

// Vector Segment Pointer
#define VECSEG                 (*((uword volatile *) 0xFF12))

// Constant Zeros Register
#define ZEROS                  (*((uword volatile *) 0xFF1C))


#endif  // ifndef _XC23xxBREGS_H_

#include "MPC5634M_MLQB80.h"
#include <stdio.h>
#include <stdarg.h>
#include "portable.h"
#include "Os.h"

#if(CPU_FREQUENCY==8000000)
#define SYNCR_V 0x36100000
#endif
#if(CPU_FREQUENCY==16000000)
#define SYNCR_V 0x16100000
#endif
#if(CPU_FREQUENCY==20000000)
#define SYNCR_V 0x18100000
#endif
#if(CPU_FREQUENCY==32000000)
#define SYNCR_V 0x16080000
#endif
#if(CPU_FREQUENCY==40000000)
#define SYNCR_V 0x18080000
#endif
#if(CPU_FREQUENCY==50000000)
#define SYNCR_V 0x1A880000
#endif
#if(CPU_FREQUENCY==60000000)
#define SYNCR_V 0x15800000
#endif
#if(CPU_FREQUENCY==64000000)
#define SYNCR_V 0x16000000	/**PREFDIV=1,MFD=12,RFD=0,->Fsys=64MHZ*/
#endif
#if(CPU_FREQUENCY==80000000) /**PREFDIV=1,MFD=16,RFD=0,->Fsys=80MHZ*/
#define SYNCR_V 0x18000000
#endif
void SystemClockInit()
{
/**
 * Fref=8MHZ(CRYSTAL OSCILLATOR CLOCK)
 * In legacy mode:Fsys=Fref*(MFD+4)/(PREFDIV+1)/(2^RFD)
 * In enhanced mode:Fsys=Fref*(EMFD)/(EPREFDIV+1)/(2^(ERFD+1))
 */
	FMPLL.ESYNCR1.B.CLKCFG = 0X7;
	FMPLL.SYNCR.R = 0x16080000;/**PREFDIV=1,MFD=12,RFD=1,->Fsys=32MHZ*/
	while (FMPLL.SYNSR.B.LOCK != 1) {};
	FMPLL.SYNCR.R = SYNCR_V;
}
#define BAUDRATE 115200
void InitializeUART(void)
{
	ESCI_A.CR2.R = 0x2000;
	ESCI_A.CR1.R =(((CPU_FREQUENCY/(16*BAUDRATE))<<16)|0x0000000c);
    SIU.PCR[89].R = 0x400;
    SIU.PCR[90].R = 0x400;	
}
char ReadUARTN(void)
{
	while (ESCI_A.SR.B.RDRF == 0) {}    /* Wait for receive data reg full = 1 */
	ESCI_A.SR.R = 0x20000000;           /* Clear RDRF flag */
	return ESCI_A.DR.B.D;               /* Read byte of Data*/
}
void WriteUARTN(char ch)
{
	while (ESCI_A.SR.B.TDRE == 0) {}      
	ESCI_A.SR.R = 0x80000000;             
	ESCI_A.DR.B.D = ch;    		
}

int printf(const char* fmt,...)
{
	va_list args;
	unsigned long length;
	int i =0 ;
	static char buf[128];
	int imask;

	DI(imask);
	va_start(args, fmt);
	length = vsprintf((char*)buf,(char *)fmt,args);
	while('\0'!=buf[i]&&i<length)  WriteUARTN(buf[i++]); 
	va_end(args);
	EI(imask);
}  

int main(void) {
  SystemClockInit();
  InitializeUART();
  printf("Start OS.\r\n");
  StartOS(0);
  for(;;);
}




#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "Std_Types.h"
#include <stdio.h>
#include "Os.h"
#include "osek_os.h"


void TERMIO_PutChar(char c)
{
    while(!SCI0SR1_TDRE);       /* 等待发送数据寄存器（缓冲器）为空 */
	SCI0DRL = c;
}
static void Sci_Init()
{
	SCI0BD = CPU_FREQUENCY/16/115200;   /* 设置SCI0波特率为115200 */
	SCI0CR1 = 0x00;       /* 设置SCI0为正常模式，八位数据位，无奇偶校验*/
	SCI0CR2 = 0x08;       /* 允许发送数据，禁止中断功能 */
}

static void SystemClockInit(void)
{
    CRGINT = 0;                  //关中断
    CLKSEL_PLLSEL = 0;           //在未初始化PLL前不使用PLL的输出作为CPU时钟
    
  #if(CPU_FREQUENCY == 40000000) 
    SYNR = 4;
  #elif(CPU_FREQUENCY == 32000000)
    SYNR = 3;     
  #elif(CPU_FREQUENCY == 24000000)
    SYNR = 2;
  #endif 

    REFDV = 1;                   //PLLCLK=2×OSCCLK×(SYNR+1)/(REFDV+1)＝64MHz ,fbus=32M
    PLLCTL_PLLON = 1;            //开PLL
    PLLCTL_AUTO = 1;             //选取自动模式
    while (CRGFLG_LOCK == 0);    //等待PLL锁定频率
    CLKSEL_PLLSEL = 1;           //选择系统时钟由PLL产生
}

#define BOOT_MESSAGE    \
"GaInOS-TK is really a copy of uTenux.\r\n"  \
"Author: parai\r\n"   \
"Email:parai@foxmail.com"

void main(void) {
    SystemClockInit();
    Sci_Init();
    printf("\r\nStart OS.%s\r\n",BOOT_MESSAGE);
    StartOS(OSDEFAULTAPPMODE);
}

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

#define BOOT_MESSAGE    \
"GaInOS-TK is really a copy of uTenux.\r\n"  \
"Author: parai\r\n"   \
"Email:parai@foxmail.com"

void main(void) {
    Sci_Init();
    printf("\r\nStart OS.%s\r\n",BOOT_MESSAGE);
    StartOS(OSDEFAULTAPPMODE);
}

#include "board.h"
#include <stdio.h>
#include "Os.h"
#include "vPort.h"

#define BOOT_MESSAGE    \
"GaInOS-TK is really a copy of uTenux.\r\n"  \
"Author: parai\r\n"   \
"Email:parai@foxmail.com"
int main()
{
    WDT_Disable(WDT); 
    CLOCK_SetConfig(2);
    /* I don't know why, the baudrate is 38400 = 115200/3 */
    UART_Configure(115200, 64000000/3);// so I add this to solve the problem
    //don't ask me why... I am not good at driver
    printf("\r\nStart OS.%s\r\n",BOOT_MESSAGE);
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

#include "board.h"
#include <stdio.h>
#include "Os.h"
#include "portable.h"

int main()
{
    WDT_Disable(WDT); 
    /* Set 3 FWS for Embedded Flash Access */
    EFC->EEFC_FMR = EEFC_FMR_FWS(3);
    CLOCK_SetConfig(2);
    /* I don't know why, the baudrate is 38400 = 115200/3 */
    UART_Configure(115200, 64000000/3);// so I add this to solve the problem
    printf("Start GaInOS-TK.\r\n");
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

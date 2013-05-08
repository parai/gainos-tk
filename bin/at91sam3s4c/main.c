#include "board.h"
#include <stdio.h>
#include "Os.h"

#define BOOT_MESSAGE    \
"GaInOS-TK is really a copy of uTenux.\r\n"  \
"Author: parai\r\n"   \
"Email:parai@foxmail.com"
int main()
{
    CLOCK_SetConfig(2);
    printf("\r\nStart OS.%s\r\n",BOOT_MESSAGE);
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

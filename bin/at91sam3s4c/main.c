#include "chip.h"
#include <stdio.h>
#include "Os.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
int __io_putchar(int ch)
#else
int fputc(int ch,FILE *f)
#endif /* __GNUC__ */
{
  return ch;
}
void Usart_Init(void)
{
}
void SystemClockInit(void)
{
}
#define BOOT_MESSAGE    \
"GaInOS-TK is really a copy of uTenux.\r\n"  \
"Author: parai\r\n"   \
"Email:parai@foxmail.com"
int main()
{
    SystemClockInit();
    Usart_Init();
    printf("\r\nStart OS.%s\r\n",BOOT_MESSAGE);
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

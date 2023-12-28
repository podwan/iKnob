#ifndef _UART0_H_
#define _UART0_H_
#include "cms80f761xx.h"
#include "uart.h"

extern void UART0_Config(void);
extern void UART0_SendChar (char ch);

#endif
#ifndef __UART_H
#define __UART_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_uart.h"
#include "stdio.h"

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

#define GETCHAR_PROTOTYPE int __io_getchar(void)

void uart_2_transmit(uint8_t pData);

uint8_t uart_2_receive();

void uart_3_transmit(uint8_t data);

uint8_t uart_3_receive();

void uart_2_print_string(char* s);

#endif /*__UART_H*/

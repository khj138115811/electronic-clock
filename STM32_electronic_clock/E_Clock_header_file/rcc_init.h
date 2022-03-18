#ifndef __RCC_INIT_H
#define __RCC_INIT_H
#include "stm32f1xx.h"

void stm32_rcc_init();
void uart_2_rcc_init();
void uart_3_rcc_init();
void spi_1_rcc_init();
void i2c_1_rcc_init();
void timer_3_rcc_init();

#endif /*__RCC_INIT_H*/

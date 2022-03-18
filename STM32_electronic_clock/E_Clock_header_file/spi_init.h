#ifndef __SPI_INIT_H
#define __SPI_INIT_H

#include "main.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"

void spi_1_init();
void spi_1_chip_select();
void spi_1_chip_deselect();
void spi_1_write_data(uint8_t data);
void spi_1_receive_start();
uint8_t spi_1_receive_data();


#endif /*__SPI_INIT_H*/

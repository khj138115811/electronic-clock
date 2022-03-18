/*
 * spi.h
 *
 * Created: 2021-04-11 오후 4:14:26
 *  Author: khs94
 */ 


#ifndef SPI_H_
#define SPI_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define cs_pin PB0
#define mosi_pin PB2
#define miso_pin PB3
#define sck_pin PB1

void spi_init();
void spi_chip_select();
void spi_chip_deselect();
void spi_write_data(const uint8_t data);
void spi_receive_start();
uint8_t spi_receive_data();


#endif /* SPI_H_ */
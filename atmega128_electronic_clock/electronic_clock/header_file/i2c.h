/*
 * i2c.h
 *
 * Created: 2021-04-10 오후 8:24:45
 *  Author: khs94
 */ 


#ifndef I2C_H_
#define I2C_H_

#define i2c_init_Fail 0
#define i2c_init_Success 1

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <util/twi.h>

uint8_t i2c_init(uint16_t clock_khz);

void i2c_start();

void i2c_transmit(uint8_t data);

void i2c_send_address_write(uint8_t address);

void i2c_send_address_read(uint8_t address);

void i2c_send_data_ACK(uint8_t data);

uint8_t i2c_receive_ACK();

uint8_t i2c_receive_NACK();

void i2c_stop();

uint8_t find_8bit_address();



#endif /* I2C_H_ */
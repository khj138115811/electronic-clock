/*
 * uart0.h
 *
 * Created: 2021-05-19 오전 10:30:25
 *  Author: khs94
 */ 


#ifndef UART0_H_
#define UART0_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void uart0_init();
int uart0_transmit(char data);
int uart0_receive();




#endif /* UART0_H_ */
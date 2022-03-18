/*
 * uart1.h
 *
 * Created: 2021-05-19 오전 10:26:05
 *  Author: khs94
 */ 


#ifndef UART1_H_
#define UART1_H_

#define F_CPU 16000000UL
#define BAUD 9600

#include <avr/io.h>
#include <util/setbaud.h>
#include <stdio.h>

void uart1_init();
int uart1_transmit(char data, FILE* f);
int uart1_receive(FILE* f);



#endif /* UART1_H_ */
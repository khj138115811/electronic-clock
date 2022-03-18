/*
 * uart1.c
 *
 * Created: 2021-05-19 오전 10:26:36
 *  Author: khs94
 */ 
#include "uart1.h"

FILE IOPUT = FDEV_SETUP_STREAM(uart1_transmit,uart1_receive,_FDEV_SETUP_RW);

void uart1_init()
{
	UBRR1H = 0;
	UBRR1L = 8;
	UCSR1B = _BV(RXEN1) | _BV(TXEN1);
	stdin = stdout = &IOPUT;
}

int uart1_transmit(char data, FILE* f)
{
	while(!(UCSR1A & _BV(UDRE1)));
	UDR1 = data;
	return 0;
}

int uart1_receive(FILE* f)
{
	while(!(UCSR1A & _BV(RXC1)));
	return UDR1;
}
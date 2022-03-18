/*
 * uart0.c
 *
 * Created: 2021-05-19 오전 10:30:38
 *  Author: khs94
 */ 
#include "uart0.h"

void uart0_init()
{
	UBRR0H = 0;
	UBRR0L = 8;
	UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0);
}
int uart0_transmit(char data)
{
	while(!(UCSR0A & _BV(UDRE0)));
	UDR0 = data;
	return 0;
}
int uart0_receive()
{
	while(!(UCSR0A & _BV(RXC0)));
	return UDR0;
}
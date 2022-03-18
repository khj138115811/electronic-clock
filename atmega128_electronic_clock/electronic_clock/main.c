/*
 * electronic_clock.c
 *
 * Created: 2021-04-11 오후 2:51:27
 * Author : khs94
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "ILI9341_LCD_input_data.h"
#include "uart1.h"

int main(void)
{
	sei();
	uart1_init();
	ILI9341_LCD_input_data_init();
	while(1)
	{
		ILI9341_LCD_input_data_update();
	}
}
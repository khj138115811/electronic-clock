/*
 * ADC.c
 *
 * Created: 2021-05-27 오전 11:42:48
 *  Author: khs94
 */ 

#include "ADC.h"

void ADC_init(uint8_t channel)
{
	DDRE = 0x00;
	ADMUX = _BV(REFS0);
	ADMUX |= channel;
	ADCSRA |= 0x87;
}

uint16_t ADC_result(uint8_t channel)
{
	ADMUX = _BV(REFS0) | channel;
	ADCSRA |= _BV(ADSC);
	while(!(ADCSRA & _BV(ADIF)));
	return ADC;
}

void istouched()
{
	uint16_t xm, xp, ym, yp;
	uint8_t count = 250;
	uint8_t touchcount = 0;
	while(count--)
	{
		xp = ADC_result(1);
		ym = ADC_result(2);
		if((xp) == (yp))
		{
			touchcount++;
		}
		else
		{
			
		}
	}
	if(touchcount >= 90)
	{
		printf("touched\n\r");
	}
}
/*
 * Timer8.c
 *
 * Created: 2021-05-22 오전 11:08:40
 *  Author: khs94
 */ 
#include "Timer8.h"

void Timer8_use2_init(uint8_t isenable, uint16_t prescaler)
{
	if(isenable == disable)
	{
		TCCR2 = 0x0;
		return;
	}
	else if(isenable == enable)
	{
		TCNT2 = 0;
		OCR2 = 250;
		TIMSK |= _BV(OCIE2);
		TCCR2 |= _BV(WGM21);
		if(prescaler == 1)
		{
			TCCR2 |= 0x1;
		}
		else if(prescaler == 8)
		{
			TCCR2 |= 0x2;
		}
		else if(prescaler == 64)
		{
			TCCR2 |= 0x3;
		}
		else if(prescaler == 256)
		{
			TCCR2 |= 0x4;
		}
		else if(prescaler == 1024)
		{
			TCCR2 |= 0x5;
		}
	}
}
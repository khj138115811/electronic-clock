/*
 * Timer16.c
 *
 * Created: 2021-05-22 오전 10:15:56
 *  Author: khs94
 */ 
#include "Timer16.h"

void Timer16_use1_init(uint8_t is_timer_enable, uint16_t prescaler)
{
	if(is_timer_enable == Disable)
	{
		return;
	}
	if(is_timer_enable == enable)
	{
		if(prescaler == 1)
		{
			TCCR1B |= 0x1;
		}
		else if(prescaler == 8)
		{
			TCCR1B |= 0x2;
		}
		else if(prescaler == 64)
		{
			TCCR1B |= 0x3;
		}
		else if(prescaler == 256)
		{
			TCCR1B |= 0x4;
		}
		else if(prescaler == 1024)
		{
			TCCR1B |= 0x5;
		}
	}
}

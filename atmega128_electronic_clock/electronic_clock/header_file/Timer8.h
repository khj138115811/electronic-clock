/*
 * Timer8.h
 *
 * Created: 2021-05-22 오전 11:08:30
 *  Author: khs94
 */ 


#ifndef TIMER8_H_
#define TIMER8_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define disable 0
#define enable 1

void Timer8_use2_init(uint8_t isenable, uint16_t prescaler);




#endif /* TIMER8_H_ */
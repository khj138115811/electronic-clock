/*
 * Exinterrupt.c
 *
 * Created: 2021-05-28 오후 2:11:55
 *  Author: khs94
 */ 
#include "Exinterrupt.h"

void exinterrupt_init()
{
	DDRE = 0x00;
	PORTE = 0x30;
	EICRB = 0x0A;
	EIMSK = 0x30;
}
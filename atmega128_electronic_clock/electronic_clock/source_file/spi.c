/*
 * spi.c
 *
 * Created: 2021-04-11 오후 4:14:41
 *  Author: khs94
 */ 
#include "spi.h"

void spi_init()
{
	DDRB = 0x17;
	PORTB |= _BV(cs_pin);
	
	/*uint16_t sck_prescaler[7] = {8000,4000,2000,1000,500,250,125};
	
	if(clock_khz >= sck_prescaler[0])
	{
		SPSR |= 0x01;
	}
	else if(clock_khz >= sck_prescaler[1])
	{
		;
	}
	else if(clock_khz >= sck_prescaler[2])
	{
		SPSR |= 0x01;
		SPCR |= 0x01;
	}
	else if(clock_khz >= sck_prescaler[3])
	{
		SPCR |= 0x01;
	}
	else if(clock_khz >= sck_prescaler[4])
	{
		SPSR |= 0x01;
		SPCR |= 0x02;
	}
	else if(clock_khz >= sck_prescaler[5])
	{
		SPCR |= 0x02;
	}
	else if(clock_khz >= sck_prescaler[6])
	{
		SPCR |= 0x03;
	}
	
	if(mode_select == spi_Master_mode)
	{
		SPCR |= _BV(MSTR);
	}
	else if(mode_select == spi_Slave_mode)
	{
		;
	}
	
	if(data_order == MSB_first)
	{
		;
	}
	else if(data_order == LSB_first)
	{
		SPCR |= LSB_first;
	}*/
	SPCR |= _BV(MSTR);
	SPCR |= _BV(SPE);
}

void spi_chip_select()
{
	PORTB &= ~_BV(cs_pin);
}

void spi_chip_deselect()
{
	PORTB |= _BV(cs_pin);
}
void spi_write_data(const uint8_t data)
{
	SPDR = data;
	while(!(SPSR & _BV(SPIF)));
}

void spi_receive_start()
{
	SPDR = 0x00;
	while(!(SPSR & _BV(SPIF)));
}

uint8_t spi_receive_data()
{
	return (SPDR & 0xFF);
}
/*
 * i2c.c
 *
 * Created: 2021-04-10 오후 8:24:18
 *  Author: khs94
 */ 
#include "i2c.h"

uint8_t i2c_init(uint16_t clock_khz)
{
	if(clock_khz > 400)
	{
		return i2c_init_Fail;
	}
	else
	{
		uint16_t base_value = (((F_CPU/1000) / clock_khz) - 16)/2;
		if(base_value / 4 <= 255 && base_value / 4 != 0)
		{
			TWSR |= 0x00;
			TWBR = base_value / 4;
		}
		else if(base_value / 256 <= 255 && base_value / 256 != 0)
		{
			TWSR |= 0x01;
			TWBR = base_value / 256;
		}
	}
	DDRD = 0x03;
	return i2c_init_Success;
}

void i2c_start()
{
	TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
	while(!(TWCR & _BV(TWINT)));
	if((TW_STATUS == TW_START))
	{
		printf("Start condition Success\n\r");
	}
	else
	{
		printf("Start condition Fail\n\r");
	}
}

void i2c_transmit(uint8_t data)
{
	TWDR = data;
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);
	while(!(TWCR & _BV(TWINT)));
}

void i2c_send_address_write(uint8_t address)
{
	i2c_transmit((address << 1) + TW_WRITE);
	if((TW_STATUS == TW_MT_SLA_ACK))
	{
		printf("SLA+W transmitted, ACK received Success\n\r");
	}
	else
	{
		printf("SLA+W transmitted, ACK received Fail\n\r");
	}
}

void i2c_send_address_read(uint8_t address)
{
	i2c_transmit((address << 1) + TW_READ);
	if((TW_STATUS == TW_MR_SLA_ACK))
	{
		printf("SLA+R transmitted, ACK received Success\n\r");
	}
	else
	{
		printf("SLA+R transmitted, ACK received Fail\n\r");
	}
}

void i2c_send_data_ACK(uint8_t data)
{
	i2c_transmit(data);
	if((TW_STATUS == TW_MT_DATA_ACK))
	{
		printf("data transmitted, ACK received Success : 0x%X\n\r", TWSR);
	}
	else
	{
		printf("data transmitted, ACK received Fail : 0x%X\n\r", TWSR);
	}
}

uint8_t i2c_receive_ACK()
{
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWEA);
	while(!(TWCR &  _BV(TWINT)));
	if(TW_STATUS == TW_MR_DATA_ACK)
	{
		printf("data received, ACK returned Success\n\r");
	}
	else
	{
		printf("data received, ACK returned Fail\n\r");
	}
	return TWDR;
}

uint8_t i2c_receive_NACK()
{
	TWCR = _BV(TWINT) | _BV(TWEN);
	while(!(TWCR &  _BV(TWINT)));
	if(TW_STATUS == TW_MR_DATA_NACK)
	{
		printf("data received, NACK returned Success\n\r");
	}
	else
	{
		printf("data received, NACK returned Fail\n\r");
	}
	return TWDR;
}

void i2c_stop()
{
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTO);
	printf("i2c Stop\n\r");
}

uint8_t find_8bit_address()
{
	uint8_t addr = 0x00;
	for(uint8_t i = 0; i < 255; i++)
	{
		i2c_start();
		i2c_transmit(addr);
		_delay_ms(500);
		if(TWSR == 0x18)
		{
			printf("write addr : 0x%X\n\r", addr);
		}
		if(TWSR == 0x40)
		{
			printf("read addr : 0x%X\n\r", addr);
		}
		addr++;
	}
	return addr;
}
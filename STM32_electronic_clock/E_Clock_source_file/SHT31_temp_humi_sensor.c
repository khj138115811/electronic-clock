/*
 * SHT31_temp_humi_sensor.c
 *
 * Created: 2021-05-18 오후 10:41:56
 *  Author: khs94
 */ 
#include "SHT31_temp_humi_sensor.h"

volatile uint32_t temperature = 0;
volatile uint32_t humidity = 0;

void SHT31_init()
{
  SHT31_Measure_period(Measure_period_1sec_high);
  _delay_ms(50);
}

uint8_t SHT31_CRC8(volatile uint8_t* data_bytes, uint8_t nums)
{
	uint8_t crc = 0xFF;
	const uint8_t polynomial = 0x31;
	for(uint8_t i = 0; i < nums; i++)
	{
		crc ^= *data_bytes++;
		for(uint8_t i = 0; i < 8; i++)
		{
			crc = (crc & 0x80) ? (crc << 1) ^ polynomial : (crc << 1);
		}
	}
	return crc;
}

/*void SHT31_start_address_write(uint8_t address)
{
	i2c_1_start();
	i2c_1_send_address_write(address);
}

void SHT31_start_address_read(uint8_t address)
{
	i2c_1_start();
	i2c_1_send_address_read(address);
}

void SHT31_send_command(uint16_t command)
{
	uint8_t cmd[2];
	cmd[0] = command >> 8;
	cmd[1] = command & 0xFF;
	i2c_1_send_data_ACK(cmd[0]);
	i2c_1_send_data_ACK(cmd[1]);
}

void SHT31_receive_data(volatile uint8_t* data_bytes, uint8_t nums)
{
	printf("receive data ready\n\r");
	for(uint8_t i = 0; i < nums - 1; i++)
	{
		data_bytes[i] = i2c_1_receive_ACK();
	}
	data_bytes[nums-1] = i2c_1_receive_NACK();
}*/

void SHT31_Measure_single(uint16_t command)
{
	volatile uint8_t data_bytes[6] = {0};
	volatile uint8_t send_bytes[2];
	send_bytes[0] = command >> 8;
	send_bytes[1] = command & 0xFF;
	uint32_t temp = 0;
	uint32_t humi = 0;
	i2c_1_start_send_addr_send_data_stop(SHT31_address,send_bytes,2);
	/*SHT31_start_address_write(SHT31_address);
	SHT31_send_command(command);
	i2c_1_stop();*/
	/*if((command & 0x2400) == 0x2400)
	{
		_delay_ms(60);
		SHT31_start_address_read(SHT31_address);
	}
	else if((command & 0x2C00) == 0x2C00)
	{
		_delay_ms(60);
		SHT31_start_address_read(SHT31_address);
		_delay_ms(60);
	}
	SHT31_receive_data(data_bytes,6);
	i2c_1_stop();*/
	i2c_1_start_receive_addr_receive_data_stop(SHT31_address,data_bytes,6);
	if(data_bytes[2] != SHT31_CRC8(data_bytes,2) || data_bytes[5] != SHT31_CRC8(data_bytes+3,2))
	{
		printf("CRC8 Failed");
	}
	else
	{
		temp = ((data_bytes[0] << 8) + data_bytes[1]);
		humi = ((data_bytes[3] << 8) + data_bytes[4]);
		printf("before convert temp : %ld, humi : %ld\n\r", temp, humi);
		printf("humi data_bytes : 0x%X, 0x%X\n\r", data_bytes[3], data_bytes[4]);
		SHT31_convert_temp_humi(temp,humi);
	}
	printf("temp : %ld, humi : %ld\n\r", temperature, humidity);
	
}

void SHT31_Measure_period(uint16_t command)
{
	volatile uint8_t send_bytes[2];
	send_bytes[0] = command >> 8;
	send_bytes[1] = command & 0xFF;

	i2c_1_start_send_addr_send_data_stop(SHT31_address,send_bytes,2);

	/*SHT31_start_address_write(SHT31_address);
	SHT31_send_command(command);*/
}

void SHT31_read_period()
{
	volatile uint8_t data_bytes[6] = {0};
	uint32_t temp = 0;
	uint32_t humi = 0;
	volatile uint8_t send_bytes[2];
	send_bytes[0] = Read_period_data >> 8;
	send_bytes[1] = Read_period_data & 0xFF;

	i2c_1_start_send_addr_send_data_stop(SHT31_address,send_bytes,2);
	/*SHT31_start_address_write(SHT31_address);
	SHT31_send_command(Read_period_data);*/
	_delay_ms(10);
	/*SHT31_start_address_read(SHT31_address);
	SHT31_receive_data(data_bytes,6);
	i2c_1_stop();*/
	i2c_1_start_receive_addr_receive_data_stop(SHT31_address,data_bytes,6);
	if(data_bytes[2] != SHT31_CRC8(data_bytes,2) || data_bytes[5] != SHT31_CRC8(data_bytes+3,2))
	{
		printf("CRC8 Failed");
	}
	else
	{
		temp = (((uint16_t)data_bytes[0] << 8) + (uint16_t)data_bytes[1]);
		humi = (((uint16_t)data_bytes[3] << 8) + (uint16_t)data_bytes[4]);
		printf("before convert temp : %ld, humi : %ld\n\r", temp, humi);
		printf("humi data_bytes : 0x%X, 0x%X\n\r", data_bytes[3], data_bytes[4]);
		SHT31_convert_temp_humi(temp,humi);
	}
	printf("temp : %ld, humi : %ld\n\r", temperature, humidity);
}

void SHT31_convert_temp_humi(uint32_t temp, uint32_t humi)
{
	uint32_t temp_temperature = (temp * 175);
	temp_temperature >>= 16;
	temp_temperature -= 44;
	uint32_t temp_humidity = (humi * 100);
	temp_humidity >>= 16;
	temp_humidity++;
	temperature = temp_temperature;
	humidity = temp_humidity;
}

void SHT31_read_Status()
{
	volatile uint8_t data_bytes[3] = {0};
	volatile uint8_t send_bytes[2];
	send_bytes[0] = SHT31_Status >> 8;
	send_bytes[1] = SHT31_Status & 0xFF;
	i2c_1_start_send_addr_send_data_stop(SHT31_address,send_bytes,2);

	i2c_1_start_receive_addr_receive_data_stop(SHT31_address,data_bytes,3);
	/*SHT31_start_address_write(SHT31_address);
	SHT31_send_command(SHT31_Status);
	SHT31_start_address_read(SHT31_address);
	SHT31_receive_data(data_bytes,3);
	i2c_1_stop();*/
}
void SHT31_soft_reset()
{
	volatile uint8_t send_bytes[2];
	send_bytes[0] = SHT31_softreset >> 8;
	send_bytes[1] = SHT31_softreset & 0xFF;
	i2c_1_start_send_addr_send_data_stop(SHT31_address,send_bytes,2);

	/*SHT31_start_address_write(SHT31_address);
	SHT31_send_command(SHT31_softreset);
	i2c_1_stop();*/
}

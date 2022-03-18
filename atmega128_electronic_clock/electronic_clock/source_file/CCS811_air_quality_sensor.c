/*
 * CCS811_air_quality_sensor.c
 *
 * Created: 2021-05-18 오후 10:44:14
 *  Author: khs94
 */ 
#include "CCS811_air_quality_sensor.h"

volatile uint32_t CO2 = 0;
volatile uint32_t TVOC = 0;

void CCS811_init()
{
	i2c_init(100);
	_delay_ms(20);
	CCS811_soft_reset();
	_delay_ms(100);
	if(CCS811_read_hardware_ID() == 0x81)
	{
		_delay_ms(50);
		printf("HW ID OK\n\r");
		if((CCS811_read_Status() & 0x10) == 0x10)
		{
			printf("APP vaild OK\n\r");
			CCS811_bootloader_start();
			_delay_ms(50);
			if((CCS811_read_Status() & 0x80) == 0x80)
			{
				printf("FW OK\n\r");
				CCS811_set_Measure_mode();
				_delay_ms(50);
			}
		}
	}
}

void CCS811_start_address_write(uint8_t address)
{
	i2c_start();
	i2c_send_address_write(address);
}

void CCS811_start_address_read(uint8_t address)
{
	i2c_start();
	i2c_send_address_read(address);
}

void CCS811_send_command_and_data(uint8_t command, volatile uint8_t* data_bytes, uint8_t nums)
{
	i2c_send_data_ACK(command);
	for(uint8_t i = 0; i < nums; i++)
	{
		i2c_send_data_ACK(data_bytes[i]);
	}
	i2c_stop();
}

void CCS811_receive_1bytes_data(volatile uint8_t* data_bytes)
{
	*data_bytes = i2c_receive_NACK();
	i2c_stop();
}

void CCS811_receive_2bytes_data(volatile uint8_t* data_bytes)
{
	*data_bytes = i2c_receive_ACK();
	data_bytes++;
	*data_bytes = i2c_receive_NACK();
	i2c_stop();
}

void CCS811_set_Measure_mode()
{
	volatile uint8_t data_bytes[1] = {0x10};
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(Measure_mode,data_bytes,1);
}

uint8_t CCS811_read_Measure_mode()
{
	volatile uint8_t cur_measure_mode;
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(Measure_mode,NULL,0);
	CCS811_start_address_read(CCS811_address);
	CCS811_receive_1bytes_data(&cur_measure_mode);
	printf("\n\r\n\r measure mode : 0x%X \n\r\n\r", cur_measure_mode);
	return cur_measure_mode;
}

void CCS811_read_CO2_TVOC()
{
	volatile uint8_t CO2_data_bytes[2];
	volatile uint8_t TVOC_data_bytes[2];
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(Alg_result_data,NULL,0);
	CCS811_start_address_read(CCS811_address);
	CO2_data_bytes[0] = i2c_receive_ACK();
	CO2_data_bytes[1] = i2c_receive_ACK();
	TVOC_data_bytes[0] = i2c_receive_ACK();
	TVOC_data_bytes[1] = i2c_receive_NACK();
	i2c_stop();
	CO2 = (((uint16_t)CO2_data_bytes[0] << 8) | (uint16_t)CO2_data_bytes[1]);
	TVOC = (((uint16_t)TVOC_data_bytes[0] << 8) | (uint16_t)TVOC_data_bytes[1]);
	printf("CO2 : %ld, TVOC : %ld\n\r", CO2, TVOC);
}

uint8_t CCS811_read_Status()
{
	volatile uint8_t status_data = 0; 
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(CCS811_Status,NULL,0);
	CCS811_start_address_read(CCS811_address);
	CCS811_receive_1bytes_data(&status_data);
	printf("status : 0x%X\n\r", status_data);
	return status_data;
}

void CCS811_check_error()
{
	volatile uint8_t error;
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(Error_id,NULL,0);
	CCS811_start_address_read(CCS811_address);
	CCS811_receive_1bytes_data(&error);
	printf("Error ID : 0x%X\n\r", error);
}

void CCS811_write_baseline(volatile uint8_t* baseline_bytes)
{
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(Baseline,baseline_bytes,2);
}

void CCS811_store_baseline()
{
	volatile uint8_t baseline_bytes[2];
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(Baseline,NULL,0);
	CCS811_start_address_read(CCS811_address);
	CCS811_receive_2bytes_data(baseline_bytes);
	CCS811_write_baseline(baseline_bytes);
}

void CCS811_soft_reset()
{
	volatile uint8_t soft_reg[4] = {0x11,0xE5,0x72,0x8A};
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(CCS811_SW_reset,soft_reg,4);
}

void CCS811_bootloader_start()
{
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(CCS811_app_start,NULL,0);
}

void CCS811_bootloader_verify()
{
	volatile uint8_t verify_data[1] = {0x20};
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(CCS811_app_verify,verify_data,1);
}

uint8_t CCS811_read_hardware_ID()
{
	volatile uint8_t _Hardware_id = 0;
	CCS811_start_address_write(CCS811_address);
	CCS811_send_command_and_data(HW_ID,NULL,0);
	CCS811_start_address_read(CCS811_address);
	CCS811_receive_1bytes_data(&_Hardware_id);
	return _Hardware_id;
}
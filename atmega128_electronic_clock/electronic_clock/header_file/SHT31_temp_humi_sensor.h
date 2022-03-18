/*
 * SHT31_temp_humi_sensor.h
 *
 * Created: 2021-05-18 오후 10:41:47
 *  Author: khs94
 */ 


#ifndef SHT31_TEMP_HUMI_SENSOR_H_
#define SHT31_TEMP_HUMI_SENSOR_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "i2c.h"

#define SHT31_address 0x44
// clock stretching disable
#define Measure_single_high 0x2400
#define Measure_single_medium 0x240B
#define Measure_single_low 0x2416

#define Measure_period_500milisec_high 0x2032
#define Measure_period_500milisec_medium 0x2024
#define Measure_period_500milisec_low 0x202F

#define Measure_period_1sec_high 0x2130
#define Measure_period_1sec_medium 0x2126
#define Measure_period_1sec_low 0x212D

#define Measure_period_2sec_high 0x2236
#define Measure_period_2sec_medium 0x2220
#define Measure_period_2sec_low 0x222B

#define Measure_period_4sec_high 0x2334
#define Measure_period_4sec_medium 0x2322
#define Measure_period_4sec_low 0x2329

#define Measure_period_10sec_high 0x2737
#define Measure_period_10sec_medium 0x2721
#define Measure_period_10sec_low 0x272A

#define Read_period_data 0xE000
#define Break_command 0x3093
#define SHT31_Status 0xF32D
#define SHT31_softreset 0x30A2

void SHT31_init();
uint8_t SHT31_CRC8(volatile uint8_t* data_bytes, uint8_t nums);
void SHT31_start_address_write(uint8_t address);
void SHT31_start_address_read(uint8_t address);
void SHT31_send_command(uint16_t command);
void SHT31_receive_data(volatile uint8_t* data_bytes, uint8_t nums);
void SHT31_Measure_single(uint16_t command);
void SHT31_Measure_period(uint16_t command);
void SHT31_read_period();
void SHT31_convert_temp_humi(uint32_t temp, uint32_t humi);
void SHT31_read_Status();
void SHT31_soft_reset();

#endif /* SHT31_TEMP_HUMI_SENSOR_H_ */
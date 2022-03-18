/*
 * CCS811_air_quality_sensor.h
 *
 * Created: 2021-05-18 오후 10:44:05
 *  Author: khs94
 */ 


#ifndef CCS811_AIR_QUALITY_SENSOR_H_
#define CCS811_AIR_QUALITY_SENSOR_H_
#include "stm32f1xx.h"
#include "i2c_init.h"
#include "stdio.h"
#include "stm32_delay_user_set.h"

#define CCS811_Status 0x00
#define Measure_mode 0x01
#define Alg_result_data 0x02
#define Raw_data 0x03
#define Env_data 0x05
#define NTC 0x06
#define Thresholds 0x10
#define Baseline 0x11
#define HW_ID 0x20
#define HW_version 0x21
#define FW_boot_version 0x23
#define FW_app_version 0x24
#define Error_id 0xE0
#define CCS811_SW_reset 0xFF

#define CCS811_app_start 0xF4
#define CCS811_app_verify 0xF3

#define CCS811_address 0x5A

void CCS811_init();
void CCS811_start_address_write(uint8_t address);
void CCS811_start_address_read(uint8_t address);
void CCS811_send_command_and_data(uint8_t command, volatile uint8_t* data_bytes, uint8_t nums);
void CCS811_receive_1bytes_data(volatile uint8_t* data_bytes);
void CCS811_receive_2bytes_data(volatile uint8_t* data_bytes);
void CCS811_set_Measure_mode();
uint8_t CCS811_read_Measure_mode();
void CCS811_read_CO2_TVOC();
uint8_t CCS811_read_Status();
void CCS811_check_error();
void CCS811_store_baseline();
void CCS811_write_baseline(uint8_t* baseline_bytes);
void CCS811_soft_reset();
void CCS811_bootloader_start();
void CCS811_bootloader_verify();
uint8_t CCS811_read_hardware_ID();


#endif /* CCS811_AIR_QUALITY_SENSOR_H_ */

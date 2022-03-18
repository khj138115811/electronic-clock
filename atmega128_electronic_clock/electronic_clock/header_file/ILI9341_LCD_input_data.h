/*
 * ILI9341_LCD_input_data.h
 *
 * Created: 2021-05-18 오후 10:09:12
 *  Author: khs94
 */ 


#ifndef ILI9341_LCD_INPUT_DATA_H_
#define ILI9341_LCD_INPUT_DATA_H_
#include <avr/io.h>
#include "Timer8.h"
#include "ESP8266.h"
#include "ILI9341_TFT_LCD.h"
#include "CCS811_air_quality_sensor.h"
#include "SHT31_temp_humi_sensor.h"
#include "Exinterrupt.h"

#define need_Update 1
#define Updated 0

#define display_false 0
#define display_true 1

#define Time_display_mode 0
#define Temp_Humi_display_mode 1
#define Air_quality_display_mode 2

struct current_time_data
{
	uint8_t seconds_index[2];
	uint8_t minute_index[2];
	uint8_t hour_index[2];
	uint8_t day_index;
	uint8_t day_index_num[2];
	uint8_t month_index;
	uint8_t year_index[4];
};

void ILI9341_LCD_input_data_init();
void ILI9341_current_time_data_init(volatile struct current_time_data* user_define);
void ILI9341_convert_received_time_string(volatile char* str);
void ILI9341_check_0h_11h_or_12h_23h(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_hour(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_minutes(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_day_num(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_date(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_month(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_year(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_LCD_input_data_time();
void ILI9341_LCD_input_data_temperature_humidity();
void ILI9341_LCD_input_data_air_quality();
void ILI9341_LCD_input_data_update();



#endif /* ILI9341_LCD_INPUT_DATA_H_ */
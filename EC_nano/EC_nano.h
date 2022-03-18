#ifndef _EC_NANO_H
#define _EC_NANO_H

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"
#include "Adafruit_CCS811.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "string.h"
#include <EEPROM.h>

#define TFT_DC 9
#define TFT_CS 10

#define init 0
#define receive_time 1

enum {
	kor_day_0h_11h_1_mv = 0, 
	kor_day_0h_11h_2_mv = 29,
	kor_day_12h_23h_1_mv = 58,
	kor_day_12h_23h_2_mv = 87,
	kor_mon_mv = 116,
	kor_tue_mv = 145,
	kor_wed_mv = 174,
	kor_thu_mv = 203,
	kor_fri_mv = 232,
	kor_sat_mv = 261,
	kor_sun_mv = 290,
	kor_year_mv = 319,
	kor_month_mv = 348,
	kor_day_mv = 377,
	kor_date_1_mv = 406,
	kor_date_2_mv = 435,
	kor_air_1_mv = 464,
	kor_air_2_mv = 493,
	kor_bad_1_mv = 522,
	kor_bad_2_mv = 551,
	kor_normal_1_mv = 580,
	kor_normal_2_mv = 609,
	kor_good_1_mv = 638,
	kor_good_2_mv = 667,
	parts_per_million_symbol_mv = 696,
	parts_per_billion_symbol_mv = 725,
	kor_temperature_1_mv = 754,
	kor_temperature_2_mv = 783,
	kor_humidity_1_mv = 812,
	kor_humidity_2_mv = 841,
	celsius_symbol_mv = 870,
	percent_symbol_mv = 899
};

void EC_nano_init();
void ILI9341_fill_screen(uint16_t color);
void ILI9341_write_char_5x5(uint16_t bg_color, uint16_t font_color, uint8_t font_size, uint32_t char_buffer, uint16_t sx, uint16_t sy);
void ILI9341_write_char_15x15(uint32_t bg_color, uint32_t font_color, uint8_t font_size, uint32_t* char_buffer, uint16_t sx, uint16_t sy);
void EC_nano_update();
void Timer_init();
void exinterrupt_init();
void ILI9341_convert_time(volatile char* str);

void ILI9341_check_0h_11h_or_12h_23h(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_hour(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_minutes(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_day_num(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_date(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_month(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_check_year(uint16_t col, uint16_t row, uint16_t width);
void ILI9341_LCD_time();

void ILI9341_LCD_input_data_temperature_humidity();
void ILI9341_LCD_input_data_air_quality();

void EEPROM_write_page(uint16_t page_addr, uint32_t* data_bytes);
uint8_t convert_25_to_8_bit(uint32_t data, uint8_t num);
uint32_t convert_8_to_25_bit(uint16_t addr);
void EEPROM_read_page(uint16_t page_addr, volatile uint32_t* data_bytes);





#endif /*_EC_NANO_H*/

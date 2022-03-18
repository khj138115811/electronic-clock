#include "EC_nano.h"

Adafruit_CCS811 ccs;
Adafruit_SHT31 sht31 = Adafruit_SHT31();
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

volatile uint8_t hour = 0;
volatile uint8_t minute = 0;
volatile uint8_t seconds = 0;
volatile uint16_t mili_sec = 0;

char month_string[12][4] = { {'J','a','n','\0'},{'F','e','b','\0'},{'M','a','r','\0'},{'A','p','r','\0'},{'M','a','y','\0'},{'J','u','n','\0'},
  {'J','u','l','\0'},{'A','u','g','\0'},{'S','e','p','\0'},{'O','c','t','\0'},{'N','o','v','\0'},{'D','e','c','\0'} };

char day_string[7][4] = { {'M','o','n','\0'},{'T','u','e','\0'},{'W','e','d','\0'},{'T','h','u','\0'},{'F','r','i','\0'},{'S','a','t','\0'},{'S','u','n','\0'} };

bool time_update_status = true;

volatile uint8_t time_index[12];
volatile uint8_t current_month = 0;
volatile uint8_t current_date = 0;

uint32_t check_char[25] = { 0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000,0x10000,0x20000,0x40000,0x80000,0x100000,0x200000,0x400000,0x800000,0x1000000 };

// 5bit x 5   25bit   5pixel x 5pixel
uint32_t dot_mv = 0x400000; // .
uint32_t colon_mv = 0x420084; // :

uint32_t numbers_mv[10] = { 0x1F8C63F,0x1F210E4,0x1F0FE1F,0x1F87E1F,0x847D29,0x1F87C3F,0x1F8FC3F,0x108463F,0x1F8FE3F,0x1F87E3F }; // 0 - 9
uint32_t upper_alphabet_mv[26] = { 0x11FC544,0xF8BE2F,0x1E0843E,0xF8C62F,0x1F0FC3F,0x10FC3F,0x1E8F43E,0x118FE31,0x1F2109F,0x62909F,0x1928CB9,0x1F08421,0x118D771,0x11CD671,0xE8C62E,
0x10BE2F,0x164D62E,0x114BE2F,0xF8383E,0x42109F,0xE8C631,0x452A31,0xAAD6B5,0x1151151,0x421151,0x1F1111F }; // A - Z
uint32_t lower_alphabet_mv[26] = { 0x174A52E,0x1F8FC21,0x1E0843E,0xFCFE10,0x1F0FE2E,0x10FC3E,0xE8F24C,0x118BC21,0x421004,0x229004,0x1D19721,0x421084,0x15AD6BF,0x118C67D,0xE8C62E,
0x109D27,0x84392E,0x108DA1,0x74182E,0x1C211C4,0x164A529,0x454620,0xAAD6A0,0x1151151,0xE87A31,0x1F1111F }; // a - z

volatile uint32_t receive_kor_arr[9] = { 0 };

volatile uint8_t CO2_index[4] = { 0 };
volatile uint8_t TVOC_index[4] = { 0 };

volatile uint32_t CO2_temp = 0;
volatile uint32_t TVOC_temp = 0;
volatile uint32_t CO2 = 0;
volatile uint32_t TVOC = 0;
volatile uint16_t CO2_color = 0;
volatile uint16_t TVOC_color = 0;

void EC_nano_init()
{
	sei();
	sht31.begin(0x44);
	ccs.begin();
	while (!ccs.available());
	while (ccs.readData());
	tft.begin();
	tft.setRotation(1);
}

void ILI9341_fill_screen(uint16_t color)
{
	tft.fillScreen(color);
}

void ILI9341_write_char_5x5(uint16_t bg_color, uint16_t font_color, uint8_t font_size, uint32_t char_buffer, uint16_t sx, uint16_t sy)
{
	uint8_t init_addr[11] = { 0,4,9,14,19,24,29,34,39,44,49 };
	tft.startWrite();
	tft.setAddrWindow(sx, sy, init_addr[font_size]+1, init_addr[font_size]+1);
	for (uint8_t check_nums = 0; check_nums < 5; check_nums++)
	{
		for (uint8_t font_width = 0; font_width < font_size; font_width++)
		{
			for (uint8_t check_bits = (check_nums * 5); check_bits < (5 * check_nums) + 5; check_bits++)
			{
				for (uint8_t font_height = 0; font_height < font_size; font_height++)
				{
					if (char_buffer & check_char[check_bits])
					{
						tft.SPI_WRITE16(font_color);
					}
					else
					{
						tft.SPI_WRITE16(bg_color);
					}
				}
			}
		}
	}
	tft.writeCommand(ILI9341_NOP);
	tft.endWrite();
}

void ILI9341_write_char_15x15(uint32_t bg_color, uint32_t font_color, uint8_t font_size, uint32_t* char_buffer, uint16_t sx, uint16_t sy)
{
	uint8_t init_addr[11] = { 0,4,9,14,19,24,29,34,39,44,49 };

	uint16_t kor_start_x[9] = { sx,sx + init_addr[font_size] + 1,sx + ((init_addr[font_size] + 1) * 2),sx,sx + init_addr[font_size] + 1,sx + ((init_addr[font_size] + 1) * 2),sx,sx + init_addr[font_size] + 1,sx + ((init_addr[font_size] + 1) * 2) };
	uint16_t kor_start_y[9] = { sy,sy,sy,sy + init_addr[font_size] + 1,sy + init_addr[font_size] + 1,sy + init_addr[font_size] + 1,sy + ((init_addr[font_size] + 1) * 2),sy + ((init_addr[font_size] + 1) * 2),sy + ((init_addr[font_size] + 1) * 2) };

	for (uint8_t idx = 0; idx < 9; idx++)
	{
		ILI9341_write_char_5x5(bg_color, font_color, font_size, char_buffer[idx], kor_start_x[idx], kor_start_y[idx]);
	}
}

void EC_nano_update()
{
	
}

void ILI9341_convert_time(volatile char* str)
{
	uint8_t index = 0;
	for (uint8_t i = 0; i < 12; i++)
	{
		if (strstr((const char*)str, month_string[i]))
		{
			current_month = i;
			break;
		}
	}
	for (uint8_t i = 0; i < 7; i++)
	{
		if (strstr((const char*)str, day_string[i]))
		{
			current_date = i;
			break;
		}
	}
	for (uint8_t i = 0; i < strlen((const char*)str); i++)
	{
		if (isdigit(str[i]))
		{
			time_index[index++] = (str[i] - '0');
		}
		if (index == 12)
		{
			break;
		}
	}
	seconds += (time_index[6] * 10) + time_index[7];
	minute += (time_index[4] * 10) + time_index[5];
	hour += (time_index[2] * 10) + time_index[3];
}



void ILI9341_check_0h_11h_or_12h_23h(uint16_t col, uint16_t row, uint16_t width)
{
	if (hour >= 12)
	{
		EEPROM_read_page(kor_day_12h_23h_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col, row);
		EEPROM_read_page(kor_day_12h_23h_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col + width, row);
	}
	else if (hour <= 11)
	{
		EEPROM_read_page(kor_day_0h_11h_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col, row);
		EEPROM_read_page(kor_day_0h_11h_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col + width, row);
	}
}
void ILI9341_check_hour(uint16_t col, uint16_t row, uint16_t width)
{
	uint8_t temp_hour = 0;
	temp_hour = hour;
	if (temp_hour > 12)
	{
		temp_hour -= 12;
	}
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 10, temp_hour/10 ? numbers_mv[temp_hour / 10] : 0x00, col, row);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 10, numbers_mv[temp_hour % 10], col + width, row);
	
}
void ILI9341_check_minutes(uint16_t col, uint16_t row, uint16_t width)
{
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 10, numbers_mv[minute / 10], col, row);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 10, numbers_mv[minute % 10], col + width, row);
}

void ILI9341_check_day_num(uint16_t col, uint16_t row, uint16_t width)
{
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, time_index[0] ? numbers_mv[time_index[0]] : 0x00, col, row);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, numbers_mv[time_index[1]], col + width, row);
	EEPROM_read_page(kor_day_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col + width + width, row);
}
void ILI9341_check_date(uint16_t col, uint16_t row, uint16_t width)
{
	uint16_t data_color = 0;
	if (current_date == 5)
	{
		data_color = ILI9341_BLUE;
	}
	else if (current_date == 6)
	{
		data_color = ILI9341_RED;
	}
	else
	{
		data_color = ILI9341_GREEN;
	}
	switch (current_date)
	{
	case 0:
		EEPROM_read_page(kor_mon_mv, receive_kor_arr);
		break;
	case 1:
		EEPROM_read_page(kor_tue_mv, receive_kor_arr);
		break;
	case 2:
		EEPROM_read_page(kor_wed_mv, receive_kor_arr);
		break;
	case 3:
		EEPROM_read_page(kor_thu_mv, receive_kor_arr);
		break;
	case 4:
		EEPROM_read_page(kor_fri_mv, receive_kor_arr);
		break;
	case 5:
		EEPROM_read_page(kor_sat_mv, receive_kor_arr);
		break;
	case 6:
		EEPROM_read_page(kor_sun_mv, receive_kor_arr);
		break;
	default:
		break;
	}
	ILI9341_write_char_15x15(ILI9341_BLACK, data_color, 2, receive_kor_arr, col, row);
	EEPROM_read_page(kor_date_1_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, data_color, 2, receive_kor_arr, col + width, row);
	EEPROM_read_page(kor_date_2_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, data_color, 2, receive_kor_arr, col + width + width, row);
}

void ILI9341_check_month(uint16_t col, uint16_t row, uint16_t width)
{
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, current_month / 10 ? numbers_mv[(current_month / 10) + 1] : 0x00, col, row);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, numbers_mv[(current_month % 10) + 1], col + width, row);
	EEPROM_read_page(kor_month_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col + width + width, row);
}

void ILI9341_check_year(uint16_t col, uint16_t row, uint16_t width)
{
	for (uint8_t i = 0; i < 4; i++)
	{
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, numbers_mv[time_index[8+i]], col+(width*i), row);
	}
	EEPROM_read_page(kor_year_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, col + width + width + width + width, row);
}

void ILI9341_LCD_time()
{
	ILI9341_check_0h_11h_or_12h_23h(250, 15, 30);
	ILI9341_check_hour(30, 60, 60);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 10, colon_mv, 140, 60);
	ILI9341_check_minutes(190, 60, 60);
	ILI9341_check_year(160, 150, 30);
	ILI9341_check_month(20, 200, 30);
	ILI9341_check_day_num(120, 200, 30);
	ILI9341_check_date(220, 200, 30);
}

void ILI9341_LCD_input_data_temperature_humidity()
{
	uint16_t temperature = sht31.readTemperature();
	uint16_t humidity = sht31.readHumidity();
	if (temperature < 100 && humidity < 100)
	{
		uint8_t temp_index[2];
		temp_index[0] = temperature / 10;
		temp_index[1] = temperature % 10;
		uint8_t humi_index[2];
		humi_index[0] = humidity / 10;
		humi_index[1] = humidity % 10;
		EEPROM_read_page(kor_temperature_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 3, receive_kor_arr, 20, 50);
		EEPROM_read_page(kor_temperature_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 3, receive_kor_arr, 60, 50);
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, colon_mv, 110, 50);
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, numbers_mv[temp_index[0]], 160, 50);
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, numbers_mv[temp_index[1]], 210, 50);
		EEPROM_read_page(celsius_symbol_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 3, receive_kor_arr, 260, 50);

		EEPROM_read_page(kor_humidity_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 3, receive_kor_arr, 20, 150);
		EEPROM_read_page(kor_humidity_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 3, receive_kor_arr, 60, 150);
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, colon_mv, 110, 150);
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, numbers_mv[humi_index[0]], 160, 150);
		ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, numbers_mv[humi_index[1]], 210, 150);
		EEPROM_read_page(percent_symbol_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 3, receive_kor_arr, 260, 150);
	}
}

void ILI9341_LCD_input_data_air_quality()
{

	if (ccs.available() && !ccs.readData())
	{
		CO2 = ccs.geteCO2();
		TVOC = ccs.getTVOC();
		CO2_temp = CO2;
		TVOC_temp = TVOC;
		CO2_index[0] = CO2_temp / 1000;
		CO2_temp %= 1000;
		CO2_index[1] = CO2_temp / 100;
		CO2_temp %= 100;
		CO2_index[2] = CO2_temp / 10;
		CO2_temp %= 10;
		CO2_index[3] = CO2_temp;

		TVOC_index[0] = TVOC_temp / 1000;
		TVOC_temp %= 1000;
		TVOC_index[1] = TVOC_temp / 100;
		TVOC_temp %= 100;
		TVOC_index[2] = TVOC_temp / 10;
		TVOC_temp %= 10;
		TVOC_index[3] = TVOC_temp;
	}
	EEPROM_read_page(kor_air_1_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 4, receive_kor_arr, 10, 40);
	EEPROM_read_page(kor_air_2_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 4, receive_kor_arr, 75, 40);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 9, colon_mv, 140, 45);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 6, upper_alphabet_mv[2], 20, 150);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 6, upper_alphabet_mv['O' - 'A'], 60, 150);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 3, numbers_mv[2], 100, 170);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, upper_alphabet_mv['t' - 'a'], 0, 200);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, upper_alphabet_mv['v' - 'a'], 30, 200);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, upper_alphabet_mv['o' - 'a'], 60, 200);
	ILI9341_write_char_5x5(ILI9341_BLACK, ILI9341_WHITE, 5, upper_alphabet_mv['c' - 'a'], 90, 200);
	if (TVOC >= 500)
	{
		TVOC_color = ILI9341_RED;
	}
	else
	{
		TVOC_color = ILI9341_GREEN;
	}
	if (CO2 >= 2000 || TVOC >= 500)
	{
		CO2_color = ILI9341_RED;
		EEPROM_read_page(kor_bad_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, CO2_color, 4, receive_kor_arr, 190, 40);
		EEPROM_read_page(kor_bad_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, CO2_color, 4, receive_kor_arr, 255, 40);
	}
	else if (CO2 >= 1000)
	{
		CO2_color = ILI9341_CYAN;
		EEPROM_read_page(kor_normal_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, CO2_color, 4, receive_kor_arr, 190, 40);
		EEPROM_read_page(kor_normal_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, CO2_color, 4, receive_kor_arr, 255, 40);
	}
	else if (CO2 < 1000)
	{
		CO2_color = ILI9341_GREEN;
		EEPROM_read_page(kor_good_1_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, CO2_color, 4, receive_kor_arr, 190, 40);
		EEPROM_read_page(kor_good_2_mv, receive_kor_arr);
		ILI9341_write_char_15x15(ILI9341_BLACK, CO2_color, 4, receive_kor_arr, 255, 40);
	}
	ILI9341_write_char_5x5(ILI9341_BLACK, CO2_color, 6, CO2_index[0] ? numbers_mv[CO2_index[0]] : 0x00, 120, 150);
	ILI9341_write_char_5x5(ILI9341_BLACK, CO2_color, 6, numbers_mv[CO2_index[1]], 160, 150);
	ILI9341_write_char_5x5(ILI9341_BLACK, CO2_color, 6, numbers_mv[CO2_index[2]], 200, 150);
	ILI9341_write_char_5x5(ILI9341_BLACK, CO2_color, 6, numbers_mv[CO2_index[3]], 240, 150);

	EEPROM_read_page(parts_per_million_symbol_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, 280, 150);

	ILI9341_write_char_5x5(ILI9341_BLACK, TVOC_color, 6, TVOC_index[0] ? numbers_mv[TVOC_index[0]] : 0x00, 120, 200);
	ILI9341_write_char_5x5(ILI9341_BLACK, TVOC_color, 6, TVOC_index[0] || TVOC_index[1] ? numbers_mv[TVOC_index[1]] : 0x00, 160, 200);
	ILI9341_write_char_5x5(ILI9341_BLACK, TVOC_color, 6, TVOC_index[0] || TVOC_index[1]|| TVOC_index[2] ? numbers_mv[TVOC_index[2]] : 0x00, 200, 200);
	ILI9341_write_char_5x5(ILI9341_BLACK, TVOC_color, 6, numbers_mv[TVOC_index[3]], 240, 200);

	EEPROM_read_page(parts_per_billion_symbol_mv, receive_kor_arr);
	ILI9341_write_char_15x15(ILI9341_BLACK, ILI9341_WHITE, 2, receive_kor_arr, 280, 200);
}

void Timer_init()
{
	TCNT0 = 0;
	OCR0A = 250;
	TIMSK0 |= _BV(OCIE0A);
	TCCR0B |= 0x3;
}

void exinterrupt_init()
{
	DDRD |= 0x00;
	PORTD |= 0xC0;
	EICRA = _BV(ISC11) | _BV(ISC01);
	EIMSK = 0x03;
}

void EEPROM_write_page(uint16_t page_addr, uint32_t* data_bytes)
{
	uint8_t send_bytes[29] = { 0 };
	for (uint8_t i = 0; i < 27; i++)
	{
		send_bytes[i] = convert_25_to_8_bit(data_bytes[i / 3], (i % 3));
	}
	send_bytes[27] = 0;
	for (uint8_t i = 0; i < 8; i++)
	{
		send_bytes[27] |= ((data_bytes[i] & 0x01) << i);
	}
	send_bytes[28] = data_bytes[8] & 0x01;
	for (uint8_t i = 0; i < 29; i++)
	{
		EEPROM.update(page_addr + i, send_bytes[i]);
	}
}

uint8_t convert_25_to_8_bit(uint32_t data, uint8_t num)
{
	uint8_t return_data = 0;
	if (num == 0)
	{
		return_data = (uint8_t)((data & 0x1FE0000) >> 17);
	}
	else if (num == 1)
	{
		return_data = (uint8_t)((data & 0x1FE00) >> 9);
	}
	else if (num == 2)
	{
		return_data = (uint8_t)((data & 0x1FE) >> 1);
	}
	return return_data;
}

uint32_t convert_8_to_25_bit(uint16_t addr)
{
	uint32_t return_data = 0;
	volatile uint32_t temp_data[3] = { 0 };
	for (uint8_t i = 0; i < 3; i++)
	{
		temp_data[i] = EEPROM.read(addr + i);
	}
	return_data |= (temp_data[0] << 17) | (temp_data[1] << 9) | (temp_data[2] << 1);
	return return_data;
}

void EEPROM_read_page(uint16_t page_addr, volatile uint32_t* data_bytes)
{
	volatile uint8_t temp_data;
	for (uint8_t i = 0; i < 9; i++)
	{
		data_bytes[i] = convert_8_to_25_bit(page_addr + (i * 3));
	}
	temp_data = EEPROM.read(page_addr + 27);
	for (uint8_t i = 0; i < 8; i++)
	{
		data_bytes[i] |= (temp_data & (1 << i)) ? 0x01 : 0x00;
	}
	temp_data = EEPROM.read(page_addr + 28);
	data_bytes[8] |= temp_data;
}
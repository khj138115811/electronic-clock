/*
 * ILI9341_LCD_input_data.c
 *
 * Created: 2021-05-18 오후 10:09:21
 *  Author: khs94
 */ 
#include "ILI9341_LCD_input_data.h"

// 5bit x 5   25bit   5pixel x 5pixel
uint32_t dot_mv = 0x400000; // .
uint32_t colon_mv = 0x420084; // :

uint32_t numbers_mv[10] = {0x1F8C63F,0x1F210E4,0x1F0FE1F,0x1F87E1F,0x847D29,0x1F87C3F,0x1F8FC3F,0x108463F,0x1F8FE3F,0x1F87E3F}; // 0 - 9
uint32_t upper_alphabet_mv[26] = {0x11FC544,0xF8BE2F,0x1E0843E,0xF8C62F,0x1F0FC3F,0x10FC3F,0x1E8F43E,0x118FE31,0x1F2109F,0x62909F,0x1928CB9,0x1F08421,0x118D771,0x11CD671,0xE8C62E,
0x10BE2F,0x164D62E,0x114BE2F,0xF8383E,0x42109F,0xE8C631,0x452A31,0xAAD6B5,0x1151151,0x421151,0x1F1111F}; // A - Z
uint32_t lower_alphabet_mv[26] = {0x174A52E,0x1F8FC21,0x1E0843E,0xFCFE10,0x1F0FE2E,0x10FC3E,0xE8F24C,0x118BC21,0x421004,0x229004,0x1D19721,0x421084,0x15AD6BF,0x118C67D,0xE8C62E,
0x109D27,0x84392E,0x108DA1,0x74182E,0x1C211C4,0x164A529,0x454620,0xAAD6A0,0x1151151,0xE87A31,0x1F1111F}; // a - z

// (5bit x 5) x 9   225bit   15pixel x 15pixel
// top-left, top-middle, top-right, middle-left, middle-middle, middle-right, bottom-left, bottom-middle, bottom-right
uint32_t kor_day_0h_11h_1_mv[9] = {0x842110,0x1F,0x210841,0x10,0x42101F,0x1,0x1C00000,0x1F21084,0x700000}; // 오
uint32_t kor_day_0h_11h_2_mv[9] = {0x100001C,0xD3885F,0x843D09,0x1198,0x218,0x842528,0x1842108,0x1F00000,0x700008}; // 전
uint32_t kor_day_12h_23h_1_mv[9] = {0x842110,0x1F,0x210841,0x10,0x42101F,0x1,0x1C00000,0x1F21084,0x700000}; // 오
uint32_t kor_day_12h_23h_2_mv[9] = {0x1007010,0x1F07C1F,0x101C01,0x82108,0xF8000,0x8842,0x1E,0x42109F,0xF}; // 후

uint32_t kor_mon_mv[9] = {0x1042110,0xF8420F,0x421080,0x380,0x887E0,0x4390A4,0x1846018,0x1F07C1F,0x701C87}; // 월
uint32_t kor_tue_mv[9] = {0xF0300,0xF80E0,0x210840,0x1821098,0x742107,0x217842,0x1E00000,0x1F08420,0x210842}; // 화
uint32_t kor_wed_mv[9] = {0x1880000,0x8EDC4,0x308000,0x1F008CC,0x1F00000,0x1F02186,0x000000,0x421084,0x000000}; // 수
uint32_t kor_thu_mv[9] = {0x1842118,0x1F0001F,0x310843,0xE0000,0xF9080,0x38000,0x18,0x1F,0x210843}; // 목
uint32_t kor_fri_mv[9] = {0x18,0x1F,0x210843,0x8C0380,0xF83E0,0x2180E0,0x1842108,0x1F00000,0x310842}; // 금
uint32_t kor_sat_mv[9] = {0x8C2118,0xF801F,0x18003,0x308,0x4203E0,0x60,0x1C00000,0x1F21084,0x700000}; // 토
uint32_t kor_sun_mv[9] = {0x421098,0x1F,0x5294A4,0xC0018,0xF801F,0x438084,0x1842300,0x1F003E0,0x7000E4}; // 일
uint32_t kor_year_mv[9] = {0x842108,0x1806000,0x721C84,0x6108,0x7C00,0x421484,0x1084210,0x1F00000,0x700000}; // 년
uint32_t kor_month_mv[9] = {0x1042110,0xF8420F,0x421080,0x380,0x887E0,0x4390A4,0x1846018,0x1F07C1F,0x701C87}; // 월
uint32_t kor_day_mv[9] = {0x421098,0x1F,0x5294A4,0xC0018,0xF801F,0x438084,0x1842300,0x1F003E0,0x7000E4}; // 일
	
uint32_t kor_date_1_mv[9] = {0x842110,0x1F,0x210841,0x10,0x118C41F,0x1,0x1C00000,0x1F8C631,0x700000}; // 요
uint32_t kor_date_2_mv[9] = {0x421098,0x1F,0x5294A4,0xC0018,0xF801F,0x438084,0x1842300,0x1F003E0,0x7000E4}; // 일

uint32_t* kor_date_mv[7] = {kor_mon_mv, kor_tue_mv, kor_wed_mv, kor_thu_mv, kor_fri_mv, kor_sat_mv, kor_sun_mv};

uint32_t kor_air_1_mv[9] = {0x18,0x20001F,0x210843,0x1007000,0x1F07C42,0x101C00,0x1042108,0x1F00000,0x110842}; // 공
uint32_t kor_air_2_mv[9] = {0x1C,0x108421F,0x421084,0x000000,0x1084210,0x421084,0x000000,0x1084210,0x421084}; // 기
	
uint32_t kor_bad_1_mv[9] = {0x421000,0x0000,0x108400,0x421084,0x0000,0x10BC21,0x384,0x1E0,0x421}; // 나
uint32_t kor_bad_2_mv[9] = {0x846108,0x427C84,0x210C42,0x1807018,0x1F07C1F,0x301C03,0x1842108,0x1F00000,0x310842}; // 쁨
	
uint32_t kor_normal_1_mv[9] = {0x846108,0x7C00,0x210C42,0x18,0x42101F,0x3,0x1C00000,0x1F21084,0x700000}; // 보
uint32_t kor_normal_2_mv[9] = {0x1846118,0x1F07C1F,0x300C03,0xE0000,0xF9080,0x38000,0x1042110,0x1F0001F,0x110841}; // 통
	
uint32_t kor_good_1_mv[9] = {0x1000018,0x8A89F,0x100003,0x7008,0x407C84,0x1C02,0x1044018,0x1F07C1F,0x110403}; // 좋
uint32_t kor_good_2_mv[9] = {0x1042110,0x1F0001F,0x110841,0x8C0380,0xF83E0,0x2180E0,0x1842108,0x1F00000,0x310842}; // 음

uint32_t kor_temperature_1_mv[9] = {0x1042110,0x1F0001F,0x110841,0xE0000,0xF9080,0x38000,0x1842108,0x1F00000,0x300000}; // 온
uint32_t kor_temperature_2_mv[9] = {0x842118,0x1F,0x3,0x18,0x42101F,0x3,0x1C00000,0x1F21084,0x700000}; // 도
	
uint32_t kor_humidity_1_mv[9] = {0x880000,0x4544,0x208000,0x807004,0x7C00,0x201C04,0x1842308,0x1F003E0,0x310862}; // 습
uint32_t kor_humidity_2_mv[9] = {0x842118,0x1F,0x3,0x18,0x42101F,0x3,0x1C00000,0x1F21084,0x700000}; // 도

uint32_t celsius_symbol_mv[9] = {0xC94980,0x426000,0x1C00,0x000000,0x410844,0x000000,0x000000,0x6084,0x1C00}; // ℃
uint32_t parts_per_million_symbol_mv[9] = {0x700000,0x700000,0x1500000,0x109D29,0x109D29,0x118C63B,0x1,0x1,0x11}; // ppm
uint32_t parts_per_billion_symbol_mv[9] = {0x700000,0x700000,0x100000,0x109D29,0x109D29,0x949C21,0x1,0x1,0x7}; // ppm
uint32_t percent_symbol_mv[9] = {0x426000,0x108000,0x111000,0x18,0x111110,0x300000,0x1110,0x210,0xC84}; // %


volatile uint8_t hour = 0;
volatile uint8_t minute = 0;
volatile uint8_t seconds = 0;
volatile uint16_t mili_sec = 0;

volatile struct current_time_data current_time;

char month_string[12][4] = {{'J','a','n','\0'},{'F','e','b','\0'},{'M','a','r','\0'},{'A','p','r','\0'},{'M','a','y','\0'},{'J','u','n','\0'},
	{'J','u','l','\0'},{'A','u','g','\0'},{'S','e','p','\0'},{'O','c','t','\0'},{'N','o','v','\0'},{'D','e','c','\0'}};

char day_string[7][4] = {{'M','o','n','\0'},{'T','u','e','\0'},{'W','e','d','\0'},{'T','h','u','\0'},{'F','r','i','\0'},{'S','a','t','\0'},{'S','u','n','\0'}};

volatile uint8_t time_index[12];

volatile uint8_t Display_mode = Time_display_mode;
volatile uint8_t Display_mode_count = 0;
volatile uint8_t isdisplay_changed = display_false;
volatile uint8_t is_time_update = need_Update;

extern volatile char received_time_string[2][101];
extern volatile uint8_t esp8266_user_status;

extern volatile uint32_t CO2;
extern volatile uint32_t TVOC;

extern volatile uint32_t temperature;
extern volatile uint32_t humidity;

ISR(TIMER2_COMP_vect)
{
	mili_sec++;
	if(mili_sec >= 1000)
	{
		seconds++;
		mili_sec %= 1000;
	}
	if(seconds == 60)
	{
		minute++;
		seconds = 0;
		if(minute == 60)
		{
			hour++;
			minute %= 60;
			if(hour == 24)
			{
				hour = 0;
			}
		}
		current_time.minute_index[0] = minute / 10;
		current_time.minute_index[1] = minute % 10;
		current_time.hour_index[0] = hour / 10;
		current_time.hour_index[1] = hour % 10;
		is_time_update = need_Update;
	}
}

ISR(INT4_vect)
{
	if((PINE & 0x10) == 0x00)
	{
		_delay_ms(100);
		if((PINE & 0x10) == 0x00)
		{
			mili_sec += 100;
			Display_mode_count++;
			Display_mode_count %= 3;
			Display_mode = Display_mode_count;
			isdisplay_changed = display_true;
			if(Display_mode == Time_display_mode)
			{
				is_time_update = need_Update;
			}
			printf("INT4 interrupt\n\r");
		}
	}
}

ISR(INT5_vect)
{
	if((PINE & 0x20) == 0x00)
	{
		_delay_ms(100);
		if((PINE & 0x20) == 0x00)
		{
			hour = 0;
			minute = 0;
			seconds = 0;
			mili_sec = 0;
			esp8266_user_status = Ready_to_receive_time_data;
			is_time_update = need_Update;
			printf("INT5 interrupt\n\r");
		}
	}
}


void ILI9341_LCD_input_data_init()
{
	SHT31_init();
	CCS811_init();
	ILI9341_current_time_data_init(&current_time);
	ILI9341_init();
	Timer8_use2_init(enable,64);
	printf("\n\r%d, %d\n\r", seconds, mili_sec);
	ESP8266_init();
	printf("\n\r%d, %d\n\r", seconds, mili_sec);
	if(esp8266_user_status == Success)
	{
		ILI9341_convert_received_time_string(received_time_string[1]);
	}
	Display_mode = Time_display_mode;
	ILI9341_fill_screen(BLACK);
	SHT31_read_period();
	CCS811_read_CO2_TVOC();
	ILI9341_LCD_input_data_update();
	exinterrupt_init();
}

void ILI9341_current_time_data_init(volatile struct current_time_data* user_define)
{
	user_define->seconds_index[0] = 0;
	user_define->seconds_index[1] = 0;
	user_define->minute_index[0] = 0;
	user_define->minute_index[1] = 0;
	user_define->hour_index[0] = 0;
	user_define->hour_index[1] = 0;
	user_define->day_index = 0;
	user_define->day_index_num[0] = 0;
	user_define->day_index_num[1] = 0;
	user_define->month_index = 0;
	user_define->year_index[0] = 0;
	user_define->year_index[1] = 0;
	user_define->year_index[2] = 0;
	user_define->year_index[3] = 0;
}

void ILI9341_convert_received_time_string(volatile char* str)
{
	uint8_t index = 0;
	for(uint8_t i = 0; i < 12; i++)
	{
		if(strstr((const char*)str,month_string[i]))
		{
			current_time.month_index = i;
			break;
		}
	}
	for(uint8_t i = 0; i < 7; i++)
	{
		if(strstr((const char*)str,day_string[i]))
		{
			current_time.day_index = i;
			break;
		}
	}
	for(uint8_t i = 0; i < strlen((const char*)str); i++)
	{
		if(isdigit(str[i]))
		{
			time_index[index++] = (str[i] - '0');
		}
		if(index == 12)
		{
			break;
		}
	}
	seconds += (time_index[6] * 10) + time_index[7];
	minute += (time_index[4] * 10) + time_index[5];
	hour += (time_index[2] * 10) + time_index[3];
	current_time.day_index_num[0] = time_index[0];
	current_time.day_index_num[1] = time_index[1];
	current_time.hour_index[0] = hour / 10;
	current_time.hour_index[1] = hour % 10;
	current_time.minute_index[0] = minute / 10;
	current_time.minute_index[1] = minute % 10;
	current_time.seconds_index[0] = seconds / 10;
	current_time.seconds_index[1] = seconds % 10;
	current_time.year_index[0] = time_index[8];
	current_time.year_index[1] = time_index[9];
	current_time.year_index[2] = time_index[10];
	current_time.year_index[3] = time_index[11];
}

void ILI9341_check_0h_11h_or_12h_23h(uint16_t col, uint16_t row, uint16_t width)
{
	if(hour >= 12)
	{
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_day_12h_23h_1_mv,col,row);
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_day_12h_23h_2_mv,col+width,row);
	}
	else if(hour <= 11)
	{
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_day_0h_11h_1_mv,col,row);
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_day_0h_11h_2_mv,col+width,row);
	}
}
void ILI9341_check_hour(uint16_t col, uint16_t row, uint16_t width)
{
	if(hour < 10)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,10,0x00,col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[1]],col+width,row);
	}
	else if(hour > 9 && hour < 13)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[0]],col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[1]],col+width,row);
	}
	else if(hour > 12 && hour < 20) 
	{
		ILI9341_write_char_5x5(BLACK,WHITE,10,0x00,col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[1] - 2],col+width,row);
	}
	else if(hour > 19 && hour < 22) 
	{
		ILI9341_write_char_5x5(BLACK,WHITE,10,0x00,col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[1] + 8],col+width,row);
	}
	else if(hour > 21 && hour < 24)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[0] - 1],col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.hour_index[1] - 2],col+width,row);
	}
}
void ILI9341_check_minutes(uint16_t col, uint16_t row, uint16_t width)
{
	ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.minute_index[0]],col,row);
	ILI9341_write_char_5x5(BLACK,WHITE,10,numbers_mv[current_time.minute_index[1]],col+width,row);
}

void ILI9341_check_day_num(uint16_t col, uint16_t row, uint16_t width)
{
	if(current_time.day_index_num[0] > 0)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.day_index_num[0]],col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.day_index_num[1]],col+width,row);
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_day_mv,col+width+width,row);
	}
	else if(current_time.day_index_num[0] == 0)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,5,0x00,col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.day_index_num[1]],col+width,row);
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_day_mv,col+width+width,row);
	}
}
void ILI9341_check_date(uint16_t col, uint16_t row, uint16_t width)
{
	if(current_time.day_index == 5)
	{
		ILI9341_write_char_15x15(BLACK,BLUE,2,kor_date_mv[current_time.day_index],col,row);
		ILI9341_write_char_15x15(BLACK,BLUE,2,kor_date_1_mv,col+width,row);
		ILI9341_write_char_15x15(BLACK,BLUE,2,kor_date_2_mv,col+width+width,row);
	}
	else if(current_time.day_index == 6)
	{
		ILI9341_write_char_15x15(BLACK,RED,2,kor_date_mv[current_time.day_index],col,row);
		ILI9341_write_char_15x15(BLACK,RED,2,kor_date_1_mv,col+width,row);
		ILI9341_write_char_15x15(BLACK,RED,2,kor_date_2_mv,col+width+width,row);
	}
	else
	{
		ILI9341_write_char_15x15(BLACK,GREEN,2,kor_date_mv[current_time.day_index],col,row);
		ILI9341_write_char_15x15(BLACK,GREEN,2,kor_date_1_mv,col+width,row);
		ILI9341_write_char_15x15(BLACK,GREEN,2,kor_date_2_mv,col+width+width,row);
	}	
}

void ILI9341_check_month(uint16_t col, uint16_t row, uint16_t width)
{
	if(current_time.month_index < 10)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,5,0x00,col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.month_index + 1],col+width,row);
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_month_mv,col+width+width,row);
	}
	else if(current_time.month_index >= 10)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[(current_time.month_index / 10) + 1],col,row);
		ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[(current_time.month_index % 10) + 1],col+width,row);
		ILI9341_write_char_15x15(BLACK,WHITE,2,kor_month_mv,col+width+width,row);
	}
}
void ILI9341_check_year(uint16_t col, uint16_t row, uint16_t width)
{
	ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.year_index[0]],col,row);
	ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.year_index[1]],col+width,row);
	ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.year_index[2]],col+width+width,row);
	ILI9341_write_char_5x5(BLACK,WHITE,5,numbers_mv[current_time.year_index[3]],col+width+width+width,row);
	ILI9341_write_char_15x15(BLACK,WHITE,2,kor_year_mv,col+width+width+width+width,row);
}

void ILI9341_LCD_input_data_time()
{
	ILI9341_check_0h_11h_or_12h_23h(250,15,30);
	ILI9341_check_hour(30,60,60);
	ILI9341_write_char_5x5(BLACK,WHITE,10,colon_mv,140,60);
	ILI9341_check_minutes(190,60,60);
	ILI9341_check_year(160,150,30);
	ILI9341_check_month(20,200,30);
	ILI9341_check_day_num(120,200,30);
	ILI9341_check_date(220,200,30);
}



void ILI9341_LCD_input_data_temperature_humidity()
{
	if(temperature < 100 && humidity < 100)
	{
		uint8_t temp_index[2];
		temp_index[0] = temperature / 10;
		temp_index[1] = temperature % 10;
		uint8_t humi_index[2];
		humi_index[0] = humidity / 10;
		humi_index[1] = humidity % 10;
		ILI9341_write_char_15x15(BLACK,WHITE,3,kor_temperature_1_mv,20,50);
		ILI9341_write_char_15x15(BLACK,WHITE,3,kor_temperature_2_mv,60,50);
		ILI9341_write_char_5x5(BLACK,WHITE,9,colon_mv,110,50);
		ILI9341_write_char_5x5(BLACK,WHITE,9,numbers_mv[temp_index[0]],160,50);
		ILI9341_write_char_5x5(BLACK,WHITE,9,numbers_mv[temp_index[1]],210,50);
		ILI9341_write_char_15x15(BLACK,WHITE,3,celsius_symbol_mv,260,50);
	
		ILI9341_write_char_15x15(BLACK,WHITE,3,kor_humidity_1_mv,20,150);
		ILI9341_write_char_15x15(BLACK,WHITE,3,kor_humidity_2_mv,60,150);
		ILI9341_write_char_5x5(BLACK,WHITE,9,colon_mv,110,150);
		ILI9341_write_char_5x5(BLACK,WHITE,9,numbers_mv[humi_index[0]],160,150);
		ILI9341_write_char_5x5(BLACK,WHITE,9,numbers_mv[humi_index[1]],210,150);
		ILI9341_write_char_15x15(BLACK,WHITE,3,percent_symbol_mv,260,150);
	}
}

void ILI9341_LCD_input_data_air_quality()
{
	uint8_t CO2_index[4];
	uint8_t TVOC_index[4];
	
	uint32_t CO2_temp = CO2;
	uint32_t TVOC_temp = TVOC;
	
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
	ILI9341_write_char_15x15(BLACK,WHITE,4,kor_air_1_mv,10,40);
	ILI9341_write_char_15x15(BLACK,WHITE,4,kor_air_2_mv,75,40);
	ILI9341_write_char_5x5(BLACK,WHITE,9,colon_mv,140,45);
	ILI9341_write_char_5x5(BLACK,WHITE,6,upper_alphabet_mv[2],20,150);
	ILI9341_write_char_5x5(BLACK,WHITE,6,upper_alphabet_mv['O'-'A'],60,150);
	ILI9341_write_char_5x5(BLACK,WHITE,3,numbers_mv[2],100,170);
	ILI9341_write_char_5x5(BLACK,WHITE,5,upper_alphabet_mv['t'-'a'],0,200);
	ILI9341_write_char_5x5(BLACK,WHITE,5,upper_alphabet_mv['v'-'a'],30,200);
	ILI9341_write_char_5x5(BLACK,WHITE,5,upper_alphabet_mv['o'-'a'],60,200);
	ILI9341_write_char_5x5(BLACK,WHITE,5,upper_alphabet_mv['c'-'a'],90,200);
	if(CO2 >= 2000 || TVOC >= 500)
	{
		ILI9341_write_char_15x15(BLACK,RED,4,kor_bad_1_mv,190,40);
		ILI9341_write_char_15x15(BLACK,RED,4,kor_bad_2_mv,255,40);
	}
	else if(CO2 >= 1000)
	{
		ILI9341_write_char_15x15(BLACK,SKYBLUE,4,kor_normal_1_mv,190,40);
		ILI9341_write_char_15x15(BLACK,SKYBLUE,4,kor_normal_2_mv,255,40);
	}
	else if(CO2 < 1000)
	{
		ILI9341_write_char_15x15(BLACK,GREEN,4,kor_good_1_mv,190,40);
		ILI9341_write_char_15x15(BLACK,GREEN,4,kor_good_2_mv,255,40);
	}
	if(CO2 >= 1000)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[0]],120,150);
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[1]],160,150);
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[2]],200,150);
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[3]],240,150);
	}
	else if(CO2 < 1000)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[1]],160,150);
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[2]],200,150);
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[CO2_index[3]],240,150);
	}
	ILI9341_write_char_15x15(BLACK,WHITE,2,parts_per_million_symbol_mv,280,150);
	if(TVOC >= 1000)
	{
		ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[0]],120,200);
		ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[1]],160,200);
		ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[2]],200,200);
		ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[3]],240,200);
	}
	else if(TVOC >= 100)
	{
		if(TVOC >= 500)
		{
			ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[1]],160,200);
			ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[2]],200,200);
			ILI9341_write_char_5x5(BLACK,RED,6,numbers_mv[TVOC_index[3]],240,200);
		}
		else
		{
			ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[TVOC_index[1]],160,200);
			ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[TVOC_index[2]],200,200);
			ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[TVOC_index[3]],240,200);
		}
	}
	else if(TVOC >= 10)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[TVOC_index[2]],200,200);
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[TVOC_index[3]],240,200);
	}
	else if(TVOC >= 0)
	{
		ILI9341_write_char_5x5(BLACK,WHITE,6,numbers_mv[TVOC_index[3]],240,200);
	}
	ILI9341_write_char_15x15(BLACK,WHITE,2,parts_per_billion_symbol_mv,280,200);
}

void ILI9341_LCD_input_data_update()
{
	uint32_t timewait = 0xFFFFF*2;
	if(isdisplay_changed == display_true)
	{
		ILI9341_fill_screen(BLACK);
		isdisplay_changed = display_false;
	}
	if(esp8266_user_status == Ready_to_receive_time_data)
	{
		ESP8266_leave_modem_sleep_mode();
		ESP8266_receive_time();
		if(esp8266_user_status == Success)
		{
			ILI9341_convert_received_time_string(received_time_string[1]);
		}
		ESP8266_enter_modem_sleep_mode();
	}
	if(Display_mode == Time_display_mode)
	{
		if(is_time_update == need_Update)
		{
			ILI9341_LCD_input_data_time();
			is_time_update = Updated;
		}
	}
	else if(Display_mode == Temp_Humi_display_mode)
	{
		SHT31_read_period();
		while(timewait--);
		timewait = 0xFFFFF*2;
		ILI9341_LCD_input_data_temperature_humidity();
		while(timewait--);
	}
	else if(Display_mode == Air_quality_display_mode)
	{
		CCS811_read_CO2_TVOC();
		while(timewait--);
		timewait = 0xFFFFF*2;
		ILI9341_LCD_input_data_air_quality();
		while(timewait--);
	}
}
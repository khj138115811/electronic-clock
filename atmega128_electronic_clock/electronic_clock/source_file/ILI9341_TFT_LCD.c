/*
 * ILI9341_TFT_LCD.c
 *
 * Created: 2021-04-11 오후 8:26:52
 *  Author: khs94
 */ 
#include "ILI9341_TFT_LCD.h"

volatile uint8_t touch_count = 0;

uint32_t check_char[25] = {0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000,0x10000,0x20000,0x40000,0x80000,0x100000,0x200000,0x400000,0x800000,0x1000000};
extern uint32_t numbers_mv[10];
extern uint32_t upper_alphabet_mv[26];
extern uint32_t lower_alphabet_mv[26];
extern uint32_t dot_mv;
extern uint32_t colon_mv;
extern volatile uint8_t Display_mode;

void ILI9341_init()
{
	spi_init();
	_delay_ms(120);
	ILI9341_software_reset();
	ILI9341_after_reset_init();
	ILI9341_sleep_out();
	ILI9341_display_on();
	ILI9341_display_init();
}
void ILI9341_chip_select()
{
	spi_chip_select();
	_delay_us(1);
}
void ILI9341_chip_deselect()
{
	spi_chip_deselect();
	_delay_us(1);
}

void ILI9341_select_send_command()
{
	if((PORTB & (1 << 4)) == 0x10)
	{
		PORTB &= ~(1 << 4);
	}
}
void ILI9341_select_send_data()
{
	if((PORTB & (1 << 4)) == 0x00)
	{
		PORTB |= (1 << 4);
	}
}

void ILI9341_write_data(uint8_t command, const uint8_t nums, uint8_t* data_bytes)
{
	ILI9341_chip_select();
	ILI9341_select_send_command();
	spi_write_data(command);
	ILI9341_select_send_data();
	for(int i = 0; i < nums; i++)
	{
		spi_write_data(data_bytes[i]);
	}
	ILI9341_chip_deselect();
}

void ILI9341_write_pixel(uint32_t color)
{
	uint8_t red_value = (uint8_t)((color & 0x3F000) >> 10);
	uint8_t green_value = (uint8_t)((color & 0x00FC0) >> 4);
	uint8_t blue_value = (uint8_t)((color & 0x0003F) << 2);
	
	spi_write_data(red_value);
	spi_write_data(green_value);
	spi_write_data(blue_value);
}

void ILI9341_read_data(uint8_t command, const uint8_t nums, volatile uint8_t* data_bytes)
{
	uint8_t dummy = 0;
	ILI9341_chip_select();
	ILI9341_select_send_command();
	spi_write_data(command);
	ILI9341_select_send_data();
	spi_receive_start();
	dummy++;
	dummy = spi_receive_data();
	for(int i = 0; i < nums; i++)
	{
		data_bytes[i] = spi_receive_data();
	}
	ILI9341_chip_deselect();
}

void ILI9341_software_reset()
{
	ILI9341_write_data(Software_reset,0,NULL);
	_delay_ms(120);
}

void ILI9341_after_reset_init()
{
	setting_all();
}

void ILI9341_read_display_id_information()
{
	uint8_t manufacturer_id = 0, version_id = 0, driver_id = 0;
	volatile uint8_t data_bytes[3];
	ILI9341_read_data(Read_display_id_information, 3, data_bytes);
	manufacturer_id = data_bytes[0];
	version_id = data_bytes[1];
	driver_id = data_bytes[2];
	printf("manufacturer_id : 0x%X\n\r",manufacturer_id);
	printf("version_id : 0x%X\n\r", version_id);
	printf("driver_id : 0x%X\n\r", driver_id);
}

void ILI9341_read_display_status()
{
	volatile uint8_t data_bytes[4];
	ILI9341_read_data(Read_display_status,4,data_bytes);
	for(uint8_t i = 0; i < 4; i++)
	{
		printf("status %d : 0x%X\n\r", i, data_bytes[i]);
	}
}

void ILI9341_read_display_power_mode()
{
	volatile uint8_t data_bytes[1];
	ILI9341_read_data(Read_display_power_mode, 1, data_bytes);
	printf("power mode : 0x%X\n\r",(data_bytes[0] & 0xFC));
}

void ILI9341_read_display_MADCTL()
{
	volatile uint8_t data_bytes[1];
	ILI9341_read_data(Read_display_MADCTL, 1, data_bytes);
	printf("MADCTL : 0x%X\n\r", (data_bytes[0] & 0xFC));
}

void ILI9341_read_display_pixel_format()
{
	volatile uint8_t data_bytes[1];
	ILI9341_read_data(Read_display_pixel_format, 1, data_bytes);
	printf("pixel_format : 0x%X\n\r", data_bytes[0]);
}
void ILI9341_read_display_image_format()
{
	volatile uint8_t data_bytes[1];
	ILI9341_read_data(Read_display_image_format, 1, data_bytes);
	printf("image_format : 0x%X\n\r", data_bytes[0]);
}
void ILI9341_read_display_signal_mode()
{
	
}
void ILI9341_read_dispaly_self_diagnostic_result()
{
	volatile uint8_t data_bytes[1];
	ILI9341_read_data(Read_dispaly_self_diagnostic_result, 1, data_bytes);
	printf("RDDSDR : 0x%X\n\r", (data_bytes[0] & 0xC0));
}

void ILI9341_display_on()
{
	ILI9341_write_data(Display_ON, 0, NULL);
	_delay_ms(150);
}

void ILI9341_display_off()
{
	ILI9341_write_data(Dispaly_off, 0, NULL);
	_delay_ms(150);
}

void ILI9341_display_init()
{
	ILI9341_enter_scroll_mode();
}

void ILI9341_tearing_effect_line_off()
{
	
}
void ILI9341_tearing_effect_line_on()
{
	
}

void ILI9341_normal_display_mode_on()
{
	ILI9341_write_data(Normal_display_mode_on, 0, NULL);
}

void ILI9341_partial_mode_on(uint16_t sr, uint16_t er)
{
	ILI9341_set_partial_area(sr,er);
	ILI9341_write_data(Partial_mode_on, 0, NULL);
}

void ILI9341_partial_mode_off()
{
	ILI9341_display_off();
	ILI9341_normal_display_mode_on();
	ILI9341_write_data(Memory_write,0,NULL);
	ILI9341_display_on();
}

void ILI9341_set_partial_area(uint16_t sr, uint16_t er)
{
	uint8_t data_bytes[4];
	data_bytes[0] = sr >> 8;
	data_bytes[1] = sr & 0xFF;
	data_bytes[2] = er >> 8;
	data_bytes[3] = er & 0xFF;
	ILI9341_write_data(Partial_area,4,data_bytes);
}

void ILI9341_set_column_address(uint16_t sc, uint16_t ec)
{
	uint8_t data_bytes[4];
	data_bytes[0] = sc >> 8;
	data_bytes[1] = sc & 0xff;
	data_bytes[2] = ec >> 8;
	data_bytes[3] = ec & 0xff;
	ILI9341_write_data(Column_address_set,4,data_bytes);
}

void ILI9341_set_page_address(uint16_t sp, uint16_t ep)
{
	uint8_t data_bytes[4];
	data_bytes[0] = sp >> 8;
	data_bytes[1] = sp & 0xff;
	data_bytes[2] = ep >> 8;
	data_bytes[3] = ep & 0xff;
	ILI9341_write_data(Page_address_set,4,data_bytes);
}

void ILI9341_vertical_scrolling_definition(uint16_t TFA, uint16_t VSA, uint16_t BFA)
{
	uint8_t data_bytes[6];
	data_bytes[0] = TFA >> 8;
	data_bytes[1] = TFA & 0xFF;
	data_bytes[2] = VSA >> 8;
	data_bytes[3] = VSA & 0xFF;
	data_bytes[4] = BFA >> 8;
	data_bytes[5] = BFA & 0xFF;
	ILI9341_write_data(Vertical_scrolling_def,6,data_bytes);
}

void ILI9341_vertical_scrolling_start_address(uint16_t VSP)
{
	uint8_t data_bytes[2];
	data_bytes[0] = VSP >> 8;
	data_bytes[1] = VSP & 0xFF;
	ILI9341_write_data(Vertical_scrolling_start_address,2,data_bytes);
}

void ILI9341_enter_scroll_mode()
{
	ILI9341_normal_display_mode_on();
	ILI9341_vertical_scrolling_definition(0x0000, 320, 0x0000);
	ILI9341_set_column_address(0x0000, 0x013F);
	ILI9341_set_page_address(0x0000, 0x00EF);
	//optional setting MADCTL
	//ILI9341_set_memory_data_access_control(uint8_t isDefault);
	ILI9341_write_data(Memory_write,0,NULL);
	ILI9341_vertical_scrolling_start_address(0x0000);
}
void ILI9341_run_continue_scroll_mode()
{
	
}
void ILI9341_leave_scroll_mode()
{
	ILI9341_display_off();
	ILI9341_normal_display_mode_on();
	ILI9341_write_data(Memory_write,0,NULL);
	ILI9341_display_on();
}



void ILI9341_sleep_out()
{
	ILI9341_write_data(Sleep_out, 0, NULL);
	_delay_ms(150);
}

uint8_t color_convert_8_to_6(uint8_t color)
{
	return ((color / 4) & 0x3F);
}

uint32_t color_convert_to_data(uint8_t red, uint8_t green, uint8_t blue)
{
	uint32_t converted_color = 0;
	uint32_t temp = 0;
	temp = color_convert_8_to_6(red);
	temp <<= 12;
	converted_color |= temp;
	temp = 0;
	temp = color_convert_8_to_6(green);
	temp <<= 6;
	converted_color |= temp;
	converted_color |= color_convert_8_to_6(blue);
	return converted_color;
}

void ILI9341_fill_screen(uint32_t color)
{
	//ILI9341_display_off();
	ILI9341_set_column_address(0x0000,0x013F);
	ILI9341_set_page_address(0x0000,0x00EF);
	ILI9341_chip_select();
	ILI9341_select_send_command();
	spi_write_data(Memory_write);
	ILI9341_select_send_data();
	for(uint32_t i = 0; i < 76800; i++)
	{
		ILI9341_write_pixel(color);
	}
	ILI9341_chip_deselect();
	ILI9341_write_data(NOP,0,NULL);
	//ILI9341_display_on();
}

void ILI9341_write_char_5x5(uint32_t bg_color,uint32_t font_color,uint8_t font_size, uint32_t char_buffer, uint16_t sx, uint16_t sy)
{
	uint8_t init_addr[15] = {0,4,9,14,19,24,29,34,39,44,49,54,59,64,69};
	uint8_t size = font_size;
	uint16_t start_x = sx, end_x = sx + init_addr[font_size];
	uint16_t start_y = sy, end_y = sy + init_addr[font_size];
	ILI9341_set_column_address(start_x,end_x);
	ILI9341_set_page_address(start_y,end_y);
	ILI9341_chip_select();
	ILI9341_select_send_command();
	spi_write_data(Memory_write);
	ILI9341_select_send_data();
	for(uint8_t check_nums = 0; check_nums < 5; check_nums++)
	{
		for(uint8_t font_width = 0; font_width < size; font_width++)
		{
			for(uint8_t check_bits = (check_nums * 5); check_bits < (5 * check_nums) + 5; check_bits++)
			{
				for(uint8_t font_height = 0; font_height < size; font_height++)
				{
					if(char_buffer & check_char[check_bits])
					{
						ILI9341_write_pixel(font_color);
					}
					else
					{
						ILI9341_write_pixel(bg_color);
					}
				}
			}
		}
	}
	ILI9341_chip_deselect();
	ILI9341_write_data(NOP,0,NULL);
}

void ILI9341_write_string(uint32_t bg_color,uint32_t font_color,uint8_t font_size, char* str, uint16_t sx, uint16_t sy)
{
	uint8_t init_addr[15] = {0,4,9,14,19,24,29,34,39,44,49,54,59,64,69};
	uint16_t start_x = sx, start_y = sy;
	for(int i = 0; str[i]; i++)
	{
		if(isupper(str[i]) != 0)
		{
			ILI9341_write_char_5x5(bg_color,font_color,font_size,upper_alphabet_mv[str[i] - 'A'],start_x,start_y);
		}
		else if(islower(str[i]) != 0)
		{
			ILI9341_write_char_5x5(bg_color,font_color,font_size,lower_alphabet_mv[str[i] - 'a'],start_x,start_y);
		}
		else if(isdigit(str[i]) != 0)
		{
			ILI9341_write_char_5x5(bg_color,font_color,font_size,numbers_mv[str[i] - '0'],start_x,start_y);
		}
		else if(isspace(str[i]) != 0)
		{
			if(str[i] == '\n')
			{
				start_y = start_y + (init_addr[font_size] + 2);
				continue;
			}
			if(str[i] == '\r')
			{
				start_x = sx;
				continue;
			}
		}
		else if(ispunct(str[i]) != 0)
		{
			if(str[i] == '.')
			{
				ILI9341_write_char_5x5(bg_color,font_color,font_size,dot_mv,start_x,start_y);
			}
			else if(str[i] == ':')
			{
				ILI9341_write_char_5x5(bg_color,font_color,font_size,colon_mv,start_x,start_y);
			}
		}
		start_x = start_x + (init_addr[font_size] + 2);
	}
}

void ILI9341_write_char_15x15(uint32_t bg_color,uint32_t font_color,uint8_t font_size, uint32_t* char_buffer, uint16_t sx, uint16_t sy)
{
	uint8_t init_addr[15] = {0,4,9,14,19,24,29,34,39,44,49,54,59,64,69};
	uint8_t size = font_size;
	uint16_t start_left_x = sx;
	uint16_t start_middle_x = start_left_x + init_addr[font_size] + 1;
	uint16_t start_right_x = start_middle_x + init_addr[font_size] + 1 ;
	
	uint16_t start_left_y = sy;
	uint16_t start_middle_y = start_left_y + init_addr[font_size] + 1;
	uint16_t start_right_y = start_middle_y + init_addr[font_size] + 1;
	
	uint16_t end_left_x = start_left_x + init_addr[font_size];
	uint16_t end_middle_x = start_middle_x + init_addr[font_size];
	uint16_t end_right_x = start_right_x + init_addr[font_size];
	
	uint16_t end_left_y = start_left_y + init_addr[font_size];
	uint16_t end_middle_y = start_middle_y + init_addr[font_size];
	uint16_t end_right_y = start_right_y + init_addr[font_size];
	
	uint16_t kor_start_addr[18] = {start_left_x,start_left_y,start_middle_x,start_left_y,start_right_x,start_left_y,
		start_left_x,start_middle_y,start_middle_x,start_middle_y,start_right_x,start_middle_y,
		start_left_x,start_right_y,start_middle_x,start_right_y,start_right_x,start_right_y};
		
	uint16_t kor_end_addr[18] = {end_left_x,end_left_y,end_middle_x,end_left_y,end_right_x,end_left_y,
		end_left_x,end_middle_y,end_middle_x,end_middle_y,end_right_x,end_middle_y,
		end_left_x,end_right_y,end_middle_x,end_right_y,end_right_x,end_right_y};
		
	for(uint8_t kor_addr_index = 0; kor_addr_index < 9; kor_addr_index++)
	{
		ILI9341_set_column_address(kor_start_addr[kor_addr_index*2],kor_end_addr[kor_addr_index*2]);
		ILI9341_set_page_address(kor_start_addr[kor_addr_index*2+1],kor_end_addr[kor_addr_index*2+1]);
		ILI9341_chip_select();
		ILI9341_select_send_command();
		spi_write_data(Memory_write);
		ILI9341_select_send_data();
		for(uint8_t check_nums = 0; check_nums < 5; check_nums++)
		{
			for(uint8_t font_width = 0; font_width < size; font_width++)
			{
				for(uint8_t check_bits = (check_nums * 5); check_bits < (5 * check_nums) + 5; check_bits++)
				{
					for(uint8_t font_height = 0; font_height < size; font_height++)
					{
						if(char_buffer[kor_addr_index] & check_char[check_bits])
						{
							ILI9341_write_pixel(font_color);
						}
						else
						{
							ILI9341_write_pixel(bg_color);
						}
					}
				}
			}
		}
		ILI9341_chip_deselect();
		ILI9341_write_data(NOP,0,NULL);
	}
}
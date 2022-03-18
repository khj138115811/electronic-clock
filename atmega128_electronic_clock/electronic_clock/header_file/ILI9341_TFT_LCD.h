/*
 * ILI9341_TFT_LCD.h
 *
 * Created: 2021-04-11 오후 8:26:26
 *  Author: khs94
 */ 


#ifndef ILI9341_TFT_LCD_H_
#define ILI9341_TFT_LCD_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <ctype.h>
#include "spi.h"

//Regulative Command Set
#define NOP 0x00
#define Software_reset 0x01
#define Read_display_id_information 0x04
#define Read_display_status 0x09
#define Read_display_power_mode 0x0A
#define Read_display_MADCTL 0x0B
#define Read_display_pixel_format 0x0C
#define Read_display_image_format 0x0D
#define Read_display_signal_mode 0x0E
#define Read_dispaly_self_diagnostic_result 0x0F
#define Enter_sleep_mode 0x10
#define Sleep_out 0x11
#define Partial_mode_on 0x12
#define Normal_display_mode_on 0x13
#define Display_inversion_off 0x20
#define Display_inversion_on 0x21
#define Gamma_set 0x26
#define Dispaly_off 0x28
#define Display_ON 0x29
#define Column_address_set 0x2A
#define Page_address_set 0x2B
#define Memory_write 0x2C
#define Color_set 0x2D
#define Memory_read 0x2E
#define Partial_area 0x30
#define Vertical_scrolling_def 0x33
#define Tearing_effect_line_off 0x34
#define Tearing_effect_line_on 0x35
#define Memory_access_control 0x36
#define Vertical_scrolling_start_address 0x37
#define Idle_mode_off 0x38
#define Idle_mode_on 0x39
#define Pixel_format_set 0x3A
#define Write_memory_continue 0x3C
#define Read_memory_continue 0x3E
#define Set_tear_scanline 0x44
#define Get_tear_scanline 0x45
#define Write_display_brightness 0x51
#define Read_display_brightness 0x52
#define Write_CTRL_display 0x53
#define Read_CTRL_display 0x54
#define Write_content_adaptive_brightness_control 0x55
#define Read_content_adaptive_brightness_control 0x56
#define Write_CABC_minimun_brightness 0x5E
#define Read_CABC_minimun_brightness 0x5F
#define Read_ID1 0xDA
#define Read_ID2 0xDB
#define Read_ID3 0xDC

//Extended Command Set
#define RGB_interface_signal_control 0xB0
#define Frame_control_in_Normal_mode 0xB1
#define Frame_control_in_Idle_mode 0xB2
#define Frame_control_in_Partial_mode 0xB3
#define Display_inversion_control 0xB4
#define Blanking_porch_control 0xB5
#define Display_function_control 0xB6
#define Entry_mode_set 0xB7
#define Backlight_control_1 0xB8
#define Backlight_control_2 0xB9
#define Backlight_control_3 0xBA
#define Backlight_control_4 0xBB
#define Backlight_control_5 0xBC
#define Backlight_control_7 0xBE
#define Backlight_control_8 0xBF
#define Power_control_1 0xC0
#define Power_control_2 0xC1
#define VCOM_control_1 0xC5
#define VCOM_control_2 0xC7
#define NV_memory_write 0xD0
#define NV_memory_protection_key 0xD1
#define NV_memory_status_read 0xD2
#define Read_ID4 0xD3
#define Positive_Gamma_correction 0xE0
#define Negative_Gamma_correction 0xE1
#define Digital_Gamma_control_1 0xE2
#define Digital_Gamma_control_2 0xE3
#define Interface_control 0xF6

#define Power_control_A 0xCB
#define Power_control_B 0xCF
#define Driver_timming_control_A 0xE8
#define Driver_timming_control_A_ 0xE9
#define Driver_timming_control_B 0xEA
#define Power_sequence_control 0xED
#define Enable_3G 0xF2
#define Pump_ratio_control 0xF7

#define Default 1

//color - 18bit
#define BLACK 0x00000000
#define WHITE 0x0003FFFF
#define RED 0x0003F000
#define BLUE 0x0000003F
#define GREEN 0x00000FC0
#define GRAY 0x00020820
#define PINK 0x0003F83F
#define YELLOW 0x0003FFE0
#define SKYBLUE 0x00020FFF

void ILI9341_init();
void ILI9341_chip_select();
void ILI9341_chip_deselect();
void ILI9341_select_send_command();
void ILI9341_select_send_data();
void ILI9341_write_data(uint8_t command, const uint8_t nums, uint8_t* data_bytes);
void ILI9341_read_data(uint8_t command, const uint8_t nums, volatile uint8_t* data_bytes);
void ILI9341_write_pixel(uint32_t color);

void ILI9341_software_reset();
void ILI9341_after_reset_init();

void ILI9341_gamma_set(uint8_t isDefault);
void ILI9341_color_set();
void ILI9341_pixel_format_set(uint8_t isDefault);
void ILI9341_set_memory_data_access_control(uint8_t isDefault);

void ILI9341_RGB_interface_signal_control(uint8_t isDefault);
void ILI9341_Frame_control_in_Normal_mode(uint8_t isDefault);
void ILI9341_Frame_control_in_Idle_mode(uint8_t isDefault);
void ILI9341_Frame_control_in_Partial_mode(uint8_t isDefault);
void ILI9341_blanking_porch_control(uint8_t isDefault);
void ILI9341_display_function_control(uint8_t isDefault);
void ILI9341_Enable_3G(uint8_t isDefault);
void ILI9341_positive_Gamma_correction();
void ILI9341_negative_Gamma_correction();
void ILI9341_digital_Gamma_control_1();
void ILI9341_digital_Gamma_control_2();
void ILI9341_interface_control(uint8_t isDefault);

void ILI9341_entry_mode_set(uint8_t isDefault);
void ILI9341_Backlight_control_1(uint8_t isDefault);
void ILI9341_Backlight_control_2(uint8_t isDefault);
void ILI9341_Backlight_control_3(uint8_t isDefault);
void ILI9341_Backlight_control_4(uint8_t isDefault);
void ILI9341_Backlight_control_5(uint8_t isDefault);
void ILI9341_Backlight_control_7(uint8_t isDefault);
void ILI9341_Backlight_control_8(uint8_t isDefault);
void ILI9341_power_control_1(uint8_t isDefault);
void ILI9341_power_control_2(uint8_t isDefault);
void ILI9341_VCOM_control_1(uint8_t isDefault);
void ILI9341_VCOM_control_2(uint8_t isDefault);

void ILI9341_power_control_A(uint8_t isDefault);
void ILI9341_power_control_B(uint8_t isDefault);
void ILI9341_driver_timming_control_A(uint8_t isDefault);
void ILI9341_driver_timming_control_A_(uint8_t isDefault);
void ILI9341_driver_timming_control_B(uint8_t isDefault);
void ILI9341_power_sequence_control(uint8_t isDefault);
void ILI9341_pump_ratio_control(uint8_t isDefault);


void setting_all();

void ILI9341_read_display_id_information();
void ILI9341_read_display_status();
void ILI9341_read_display_power_mode();
void ILI9341_read_display_MADCTL();
void ILI9341_read_display_pixel_format();
void ILI9341_read_display_image_format();
void ILI9341_read_display_signal_mode();
void ILI9341_read_dispaly_self_diagnostic_result();

void ILI9341_tearing_effect_line_off();
void ILI9341_tearing_effect_line_on();

void ILI9341_normal_display_mode_on();
void ILI9341_partial_mode_on(uint16_t sr, uint16_t er);
void ILI9341_set_partial_area(uint16_t sr, uint16_t er);
void ILI9341_display_on();
void ILI9341_display_off();
void ILI9341_display_init();
void ILI9341_set_column_address(uint16_t sc, uint16_t ec);
void ILI9341_set_page_address(uint16_t sp, uint16_t ep);
void ILI9341_vertical_scrolling_definition(uint16_t TFA, uint16_t VSA, uint16_t BFA);
void ILI9341_vertical_scrolling_start_address(uint16_t VSP);
void ILI9341_enter_scroll_mode();
void ILI9341_run_continue_scroll_mode();
void ILI9341_leave_scroll_mode();

uint8_t color_convert_8_to_6(uint8_t color);
uint32_t color_convert_to_data(uint8_t red, uint8_t green, uint8_t blue);

void ILI9341_sleep_out();

void ILI9341_read_id1();

void ILI9341_fill_screen(uint32_t color);

void ILI9341_write_char_5x5(uint32_t bg_color,uint32_t font_color,uint8_t font_size, uint32_t char_buffer, uint16_t sx, uint16_t sy);
void ILI9341_write_string(uint32_t bg_color,uint32_t font_color,uint8_t font_size, char* str, uint16_t sx, uint16_t sy);
void ILI9341_write_char_15x15(uint32_t bg_color,uint32_t font_color,uint8_t font_size, uint32_t* char_buffer, uint16_t sx, uint16_t sy);

#endif /* ILI9341_TFT_LCD_H_ */
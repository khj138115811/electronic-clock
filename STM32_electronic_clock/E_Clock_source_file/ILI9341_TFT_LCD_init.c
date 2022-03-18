/*
 * ILI9341_TFT_LCD_init.c
 *
 * Created: 2021-05-09 오후 5:04:40
 *  Author: khs94
 */ 
#include "ILI9341_TFT_LCD.h"

void ILI9341_gamma_set(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x01};
	uint8_t User_bytes[1] = {0x01};
	if(isDefault == Default)
	{
		ILI9341_write_data(Gamma_set,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Gamma_set,1,User_bytes);
	}
}
void ILI9341_color_set()
{
	
}
void ILI9341_pixel_format_set(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x66};
	uint8_t User_bytes[1] = {0x55};
	if(isDefault == Default)
	{
		ILI9341_write_data(Pixel_format_set,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Pixel_format_set,1,User_bytes);
	}
}

void ILI9341_set_memory_data_access_control(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x00};
	//uint8_t adafruit_bytes[1] = {0x48};
	uint8_t User_bytes[1] = {0x28};
	if(isDefault == Default)
	{
		ILI9341_write_data(Memory_access_control,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Memory_access_control,1,User_bytes);
	}
}

void ILI9341_RGB_interface_signal_control(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x40};
	if(isDefault == Default)
	{
		ILI9341_write_data(RGB_interface_signal_control,1,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Frame_control_in_Normal_mode(uint8_t isDefault)
{
	uint8_t Default_bytes[2] = {0x00,0x1B};
	uint8_t User_bytes[2] = {0x00, 0x18};
	if(isDefault == Default)
	{
		ILI9341_write_data(Frame_control_in_Normal_mode,2,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Frame_control_in_Normal_mode,2,User_bytes);
	}
}
void ILI9341_Frame_control_in_Idle_mode(uint8_t isDefault)
{
	uint8_t Default_bytes[2] = {0x00,0x1B};
	if(isDefault == Default)
	{
		ILI9341_write_data(Frame_control_in_Idle_mode,2,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Frame_control_in_Partial_mode(uint8_t isDefault)
{
	uint8_t Default_bytes[2] = {0x00,0x1B};
	if(isDefault == Default)
	{
		ILI9341_write_data(Frame_control_in_Partial_mode,2,Default_bytes);
	}
	else
	{
		
	}
}
// HSYNC, DOTCLK
void ILI9341_blanking_porch_control(uint8_t isDefault)
{
	uint8_t Default_bytes[4] = {0x02,0x02,0x0A,0x14};
	if(isDefault == Default)
	{
		ILI9341_write_data(Blanking_porch_control,4,Default_bytes);
	}
	else
	{
		
	}
}

void ILI9341_display_function_control(uint8_t isDefault)
{
	uint8_t Default_bytes[3] = {0x0A,0x82,0x27};
	uint8_t User_bytes[3] = {0x08, 0x82, 0x27};
	if(isDefault == Default)
	{
		ILI9341_write_data(Display_function_control,3,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Display_function_control,3,User_bytes);
	}
}

void ILI9341_Enable_3G(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x02};
	uint8_t User_bytes[1] = {0x00};
	if(isDefault == Default)
	{
		ILI9341_write_data(Enable_3G,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Enable_3G,1,User_bytes);
	}
}

void ILI9341_positive_Gamma_correction()
{
	uint8_t User_bytes[15] = {0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08,
		0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00};
	ILI9341_write_data(Positive_Gamma_correction,15,User_bytes);
}
void ILI9341_negative_Gamma_correction()
{
	uint8_t User_bytes[15] = {0x00, 0x0E, 0x14, 0x03, 0x11, 0x07,
		0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F};
	ILI9341_write_data(Negative_Gamma_correction,15,User_bytes);
}
void ILI9341_digital_Gamma_control_1()
{
	
}
void ILI9341_digital_Gamma_control_2()
{
	
}


void ILI9341_interface_control(uint8_t isDefault)
{
	uint8_t Default_bytes[3] = {0x01,0x00,0x00};
	if(isDefault == Default)
	{
		ILI9341_write_data(Interface_control,3,Default_bytes);
	}
	else
	{
		
	}
}

void ILI9341_Backlight_control_1(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x0C};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_1,1,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Backlight_control_2(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0xCC};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_2,1,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Backlight_control_3(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x04};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_3,1,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Backlight_control_4(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x65};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_4,1,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Backlight_control_5(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x44};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_5,1,Default_bytes);
	}
	else
	{
		
	}
}

void ILI9341_Backlight_control_7(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x0F};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_7,1,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_Backlight_control_8(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x00};
	if(isDefault == Default)
	{
		ILI9341_write_data(Backlight_control_8,1,Default_bytes);
	}
	else
	{
		
	}
}

void ILI9341_entry_mode_set(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x06};
	if(isDefault == Default)
	{
		ILI9341_write_data(Entry_mode_set,1,Default_bytes);
	}
	else
	{
		
	}
}

void ILI9341_power_control_1(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x21};
	uint8_t User_bytes[1] = {0x23};
	if(isDefault == Default)
	{
		ILI9341_write_data(Power_control_1,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Power_control_1,1,User_bytes);
	}
}
void ILI9341_power_control_2(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x10};
	uint8_t User_bytes[1] = {0x10};
	if(isDefault == Default)
	{
		ILI9341_write_data(Power_control_2,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Power_control_2,1,User_bytes);
	}
}
void ILI9341_VCOM_control_1(uint8_t isDefault)
{
	uint8_t Default_bytes[2] = {0x31,0x3C};
	uint8_t User_bytes[2] = {0x3E, 0x28};
	if(isDefault == Default)
	{
		ILI9341_write_data(VCOM_control_1,2,Default_bytes);
	}
	else
	{
		ILI9341_write_data(VCOM_control_1,2,User_bytes);
	}
}
void ILI9341_VCOM_control_2(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0xC0};
	uint8_t User_bytes[1] = {0x86};
	if(isDefault == Default)
	{
		ILI9341_write_data(VCOM_control_2,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(VCOM_control_2,1,User_bytes);
	}
}

void ILI9341_power_control_A(uint8_t isDefault)
{
	uint8_t Default_bytes[5] = {0x39,0x2C,0x00,0x34,0x02};
	uint8_t User_bytes[5] = {0x39, 0x2C, 0x00, 0x34, 0x02};
	if(isDefault == Default)
	{
		ILI9341_write_data(Power_control_A,5,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Power_control_A,5,User_bytes);
	}
}
void ILI9341_power_control_B(uint8_t isDefault)
{
	uint8_t Default_bytes[3] = {0x00,0x81,0x30};
	uint8_t User_bytes[3] = {0x00, 0xC1, 0x30};
	if(isDefault == Default)
	{
		ILI9341_write_data(Power_control_B,3,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Power_control_B,3,User_bytes);
	}
}
void ILI9341_driver_timming_control_A(uint8_t isDefault)
{
	uint8_t Default_bytes[3] = {0x84,0x11,0x7A};
	if(isDefault == Default)
	{
		ILI9341_write_data(Driver_timming_control_A,3,Default_bytes);
	}
	else
	{
		
	}
}
void ILI9341_driver_timming_control_A_(uint8_t isDefault)
{
	uint8_t Default_bytes[3] = {0x84,0x11,0x7A};
	uint8_t User_bytes[3] = {0x85, 0x00, 0x78};
	if(isDefault == Default)
	{
		ILI9341_write_data(Driver_timming_control_A_,3,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Driver_timming_control_A_,3,User_bytes);
	}
}
void ILI9341_driver_timming_control_B(uint8_t isDefault)
{
	uint8_t Default_bytes[2] = {0x66,0x00};
	uint8_t User_bytes[2] = {0x00,0x00};
	if(isDefault == Default)
	{
		ILI9341_write_data(Driver_timming_control_B,2,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Driver_timming_control_B,2,User_bytes);
	}
}
void ILI9341_power_sequence_control(uint8_t isDefault)
{
	uint8_t Default_bytes[4] = {0x55,0x01,0x23,0x01};
	uint8_t User_bytes[4] = {0x64, 0x03, 0x12, 0x81};
	if(isDefault == Default)
	{
		ILI9341_write_data(Power_sequence_control,4,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Power_sequence_control,4,User_bytes);
	}
}
void ILI9341_pump_ratio_control(uint8_t isDefault)
{
	uint8_t Default_bytes[1] = {0x10};
	uint8_t User_bytes[1] = {0x20};
	if(isDefault == Default)
	{
		ILI9341_write_data(Pump_ratio_control,1,Default_bytes);
	}
	else
	{
		ILI9341_write_data(Pump_ratio_control,1,User_bytes);
	}
}

void setting_all()
{
	ILI9341_gamma_set(!Default);
	
	ILI9341_pixel_format_set(Default);
	ILI9341_set_memory_data_access_control(!Default);

	ILI9341_RGB_interface_signal_control(Default);
	ILI9341_Frame_control_in_Normal_mode(!Default);
	ILI9341_Frame_control_in_Idle_mode(Default);
	ILI9341_Frame_control_in_Partial_mode(Default);
	ILI9341_blanking_porch_control(Default);
	ILI9341_display_function_control(!Default);
	ILI9341_Enable_3G(!Default);
	ILI9341_positive_Gamma_correction();
	ILI9341_negative_Gamma_correction();
	
	ILI9341_interface_control(Default);

	ILI9341_entry_mode_set(Default);
	ILI9341_Backlight_control_1(Default);
	ILI9341_Backlight_control_2(Default);
	ILI9341_Backlight_control_3(Default);
	ILI9341_Backlight_control_4(Default);
	ILI9341_Backlight_control_5(Default);
	ILI9341_Backlight_control_7(Default);
	ILI9341_Backlight_control_8(Default);
	ILI9341_power_control_1(!Default);
	ILI9341_power_control_2(!Default);
	ILI9341_VCOM_control_1(!Default);
	ILI9341_VCOM_control_2(!Default);

	ILI9341_power_control_A(!Default);
	ILI9341_power_control_B(!Default);
	ILI9341_driver_timming_control_A(!Default);
	ILI9341_driver_timming_control_A_(Default);
	ILI9341_driver_timming_control_B(!Default);
	ILI9341_power_sequence_control(!Default);
	ILI9341_pump_ratio_control(!Default);
}
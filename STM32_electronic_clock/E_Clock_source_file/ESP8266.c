/*
 * ESP8266.c
 *
 * Created: 2021-05-18 오후 10:08:38
 *  Author: khs94
 */ 
#include "ESP8266.h"

extern volatile uint8_t seconds;

struct send_string_ESP8266 send_string[5] = {{"AT"},{"AT+CWMODE=1"},{"AT+CWJAP=\"와이파이30000\",\"01044565908\""},{"AT+CIPSNTPCFG=1,9,\"pool.ntp.org\""},{"AT+CIPSNTPTIME?"}};

volatile uint8_t command_transmit_index = 0;
volatile uint8_t command_receive_index = 0;
volatile uint8_t receive_time_first_index = 0;
volatile uint8_t receive_time_index = 0;
volatile uint8_t sleep_mode_index = 0;

volatile char result_receive_string[5][101];
volatile char received_time_string[2][101];
volatile uint8_t esp8266_user_status;
volatile char receive_sleep_mode_string[1][101];

volatile uint16_t first_receive_time_mili_sec = 0;
volatile uint8_t first_receive_time_sec = 0;
volatile uint16_t second_receive_time_mili_sec = 0;
volatile uint8_t second_receive_time_sec = 0;
volatile uint16_t receive_time_diff = 0;

extern volatile uint16_t mili_sec;
extern volatile uint8_t seconds;

uint8_t ESP8266_init()
{
	uint32_t get_timeout = 0xFFFFF*2;
	command_transmit_index = 0;
	command_receive_index = 0;
	if(ESP8266_get_time_init() == Success)
	{
		esp8266_user_status = Ready_to_receive_time_data;
		for(int i = 0; i < 7; i++)
		{
			printf("%s",result_receive_string[i]);
		}
	}
	else
	{
		return Fail;
	}
	while(get_timeout--);
	if(ESP8266_receive_time() == Success)
	{
		printf("%s", received_time_string[0]);
	}
	else
	{
		printf("Fail to receive time\n\r");
		return Fail;
	}
	ESP8266_enter_modem_sleep_mode();
	return Success;
}

void ESP8266_send_AT_command(char* command)
{
  for(uint8_t i = 0; command[i]; i++)
  {
    uart_3_transmit(command[i]);
  }
  uart_3_transmit(0x0D);
  uart_3_transmit(0x0A);
  //printf("transmit : %s\n\r", command);
}

uint8_t ESP8266_receive_time()
{
	uint8_t count = 0;
	uint32_t get_timeout = 0xFFFFF*3;
	esp8266_user_status = Ready_to_receive_time_data;
	memset(received_time_string[0],0,100);
	receive_time_first_index = 0;
	seconds = 0;
	mili_sec = 0;
	while(count != 10)
	{
		get_timeout = 0xFFFFF*3;
		receive_time_index = 0;
		ESP8266_send_AT_command(send_string[4].str);
		while(strstr((const char*)received_time_string[0],"OK") == NULL || strstr((const char*)received_time_string[0],"1970") || strlen((const char*)received_time_string[0]) != 60)
		{
			get_timeout--;
			if(get_timeout == 0)
			{
				break;
			}
		}
		if(strstr((const char*)received_time_string[0],"OK") != NULL && strstr((const char*)received_time_string[0],"1970") == NULL && strlen((const char*)received_time_string[0]) == 60)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	first_receive_time_sec = seconds;
	first_receive_time_mili_sec = mili_sec;
	receive_time_first_index++;
	count = 0;
	while(count != 10)
	{
		get_timeout = 0xFFFFF*3;
		memset(received_time_string[1],0,100);
		receive_time_index = 0;
		ESP8266_send_AT_command(send_string[4].str);
		while(strstr((const char*)received_time_string[1],"OK") == NULL || strstr((const char*)received_time_string[1],"1970") || strlen((const char*)received_time_string[1]) != 60)
		{
			get_timeout--;
			if(get_timeout == 0)
			{
				break;
			}
		}
		if(strstr((const char*)received_time_string[1],"OK") != NULL && strstr((const char*)received_time_string[1],"1970") == NULL && strlen((const char*)received_time_string[1]) == 60)
		{
			if(strcmp((const char*)received_time_string[0],(const char*)received_time_string[1]) == 0)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			count++;
		}
	}
	second_receive_time_sec = seconds;
	second_receive_time_mili_sec = mili_sec;
	if(count == 10)
	{
		esp8266_user_status = Fail;
	}
	if(esp8266_user_status != Fail)
	{
		receive_time_diff = (((uint16_t)second_receive_time_sec * 1000) + second_receive_time_mili_sec) - (((uint16_t)first_receive_time_sec * 1000) + first_receive_time_mili_sec);
		mili_sec = receive_time_diff;
		seconds = 0;
		esp8266_user_status = Success;
	}
	printf("%s", received_time_string[0]);
	printf("%s", received_time_string[1]);
	printf("difftime : %ld\n\r", receive_time_diff);
	return esp8266_user_status;
}

uint8_t ESP8266_check_receive_data(volatile char* data)
{
	if(strstr((const char*)data,"OK"))
	{
		return Success;
	}
	else
	{
		return Fail;
	}
}

uint8_t ESP8266_get_time_init()
{
	uint32_t get_timeout;
	uint8_t count = 0;
	while(command_transmit_index < 5)
	{
		get_timeout = 0xFFFFF*3;
		command_receive_index = 0;
		ESP8266_send_AT_command(send_string[command_transmit_index].str);
		while(ESP8266_check_receive_data(result_receive_string[command_transmit_index]) == Fail)
		{
			get_timeout--;
			if(get_timeout == 0)
			{
				count++;
				break;
			}
		}
		if(ESP8266_check_receive_data(result_receive_string[command_transmit_index]) == Success)
		{
			command_transmit_index++;
		}
		if(count == 20)
		{
			printf("ESP8266 init Fail\n\r");
			return Fail;
		}
	}
	return Success;
}

uint8_t ESP8266_enter_modem_sleep_mode()
{
	uint32_t get_timeout;
	uint8_t count = 0;
	esp8266_user_status = Change_sleep_mode;
	memset(receive_sleep_mode_string[0],0,100);
	while(count != 10)
	{
		get_timeout = 0xFFFFF*2;
		sleep_mode_index = 0;
		ESP8266_send_AT_command("AT+SLEEP=2");
		while(ESP8266_check_receive_data(receive_sleep_mode_string[0]) == Fail || strstr(receive_sleep_mode_string[0],"AT+SLEEP=2") == NULL)
		{
			get_timeout--;
			if(get_timeout == 0)
			{
				count++;
				break;
			}
		}
		if(ESP8266_check_receive_data(receive_sleep_mode_string[0]) == Success && strstr(receive_sleep_mode_string[0],"AT+SLEEP=2"))
		{
			esp8266_user_status = Success;
			break;
		}
		if(count == 10)
		{
			esp8266_user_status = Fail;
			break;
		}
	}
	printf("sleep mode status : ");
	printf("%s", receive_sleep_mode_string[0]);
	return esp8266_user_status;
}
uint8_t ESP8266_leave_modem_sleep_mode()
{
  uint32_t get_timeout;
  uint8_t count = 0;
  esp8266_user_status = Change_sleep_mode;
  memset(receive_sleep_mode_string[0],0,100);
  while(count != 10)
  {
    get_timeout = 0xFFFFF*2;
    sleep_mode_index = 0;
    ESP8266_send_AT_command("AT+SLEEP=0");
    while(ESP8266_check_receive_data(receive_sleep_mode_string[0]) == Fail || strstr(receive_sleep_mode_string[0],"AT+SLEEP=0") == NULL)
    {
		get_timeout--;
		if(get_timeout == 0)
		{
			   break;
		}
    }
    if(ESP8266_check_receive_data(receive_sleep_mode_string[0]) == Success && strstr(receive_sleep_mode_string[0],"AT+SLEEP=0"))
    {
		esp8266_user_status = Success;
		break;
	}
    if(count == 10)
    {
      esp8266_user_status = Fail;
      break;
    }
  }
  printf("sleep mode status : ");
  printf("%s", receive_sleep_mode_string[0]);
  return esp8266_user_status;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(command_transmit_index >= 0 && command_transmit_index < 5)
  {
    result_receive_string[command_transmit_index][command_receive_index++] = uart_3_receive();
    result_receive_string[command_transmit_index][command_receive_index] = '\0';
  }
  else if(esp8266_user_status == Ready_to_receive_time_data)
  {
    received_time_string[receive_time_first_index][receive_time_index++] = uart_3_receive();
    received_time_string[receive_time_first_index][receive_time_index] = '\0';
  }
  else if(esp8266_user_status == Change_sleep_mode)
  {
    receive_sleep_mode_string[0][sleep_mode_index++] = uart_3_receive();
    receive_sleep_mode_string[0][sleep_mode_index] = '\0';
  }
  else
  {
    printf("%c",uart_3_receive());
  }
}

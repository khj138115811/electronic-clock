/*
 * ESP8266.h
 *
 * Created: 2021-05-18 오후 10:08:25
 *  Author: khs94
 */ 


#ifndef ESP8266_H_
#define ESP8266_H_
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "uart0.h"

#define Fail 0
#define Success 1

#define Ready_to_receive_time_data 0xF
#define Change_sleep_mode 0xE

struct send_string_ESP8266
{
	char str[50];
};



uint8_t ESP8266_init();
void ESP8266_send_AT_command(char* command);
uint8_t ESP8266_receive_time();
uint8_t ESP8266_check_receive_data();
uint8_t ESP8266_get_time_init();
uint8_t ESP8266_enter_modem_sleep_mode();
uint8_t ESP8266_leave_modem_sleep_mode();

#endif /* ESP8266_H_ */
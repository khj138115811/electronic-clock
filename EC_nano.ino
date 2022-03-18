#include "EC_nano.h"
#include <SoftwareSerial.h>

SoftwareSerial esp8266(4, 5);

#define status_init 1
#define receive_time 2
#define status_default 3
#define EN_sleep_mode 4
#define DI_sleep_mode 5

#define time_mode 0
#define TH_mode 1
#define air_mode 2

uint8_t ESP8266_status = 1;

uint8_t display_mode = 0;

bool is_display_changed = true;
bool TH_sensor_update = true;
bool air_sensor_update = true;

bool send_sleep_mode = true;
bool send_wakeup_mode = false;

volatile char receive_init_string[101];
volatile char receive_time_string[2][71];
volatile char sleep_mode_string[2][31];
uint8_t t_index = 0;
uint8_t r_index = 0;
uint8_t pre_t_index = 5;
bool time_request = false;
char* esp8266_cmd_str[5] = { "AT\r\n","AT+CWMODE=1\r\n","AT+CWJAP=\"와이파이2.4\",\"0419365908\"\r\n","AT+CIPSNTPCFG=1,9,\"pool.ntp.org\"\r\n","AT+CIPSNTPTIME?\r\n" };
char enter_sleep_mode[15] = "AT+SLEEP=2\r\n";
char leave_sleep_mode[15] = "AT+SLEEP=0\r\n";
extern volatile uint8_t hour;
extern volatile uint8_t minute;
extern volatile uint8_t seconds;
extern volatile uint16_t mili_sec;

extern bool time_update_status;

void setup() {
  esp8266.begin(57600);
  EC_nano_init();
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),change_display,FALLING);
}

void loop() {
  if(ESP8266_status == status_default)
  {
    if(is_display_changed == true)
    {
      ILI9341_fill_screen(ILI9341_BLACK);
      is_display_changed = false;
    }
    if(display_mode == time_mode && time_update_status == true)
    {
      ILI9341_LCD_time();
      time_update_status = false;
    }
    else if(display_mode == TH_mode && TH_sensor_update == true)
    {
      ILI9341_LCD_input_data_temperature_humidity();
      TH_sensor_update = false;
    }
    else if(display_mode == air_mode && air_sensor_update == true)
    {
      ILI9341_LCD_input_data_air_quality();
      air_sensor_update = false;
    }
  }
  else
  {  
    ESP8266_receive();
    ESP8266_init();
    ESP8266_wakeup();
    ESP8266_get_time();
    ESP8266_sleep();
  }
}

void ESP8266_init()
{
  if (ESP8266_status == status_init)
  {
    if (pre_t_index != t_index)
    {
      r_index = 0;
      memset(receive_init_string, 0, 100);
      esp8266.print(esp8266_cmd_str[t_index]);
      pre_t_index = t_index;
    }
    if (strstr(receive_init_string, "OK"))
    {
      t_index++;
    }
    if (t_index == 5)
    {
      ESP8266_status = DI_sleep_mode;
      t_index = 0;
      delay(2000);
    }
  }
}

void ESP8266_receive()
{
  if (esp8266.available())
  {
    if (ESP8266_status == status_init)
    {
      receive_init_string[r_index++] = esp8266.read();
      receive_init_string[r_index] = '\0';
    }
    else if (ESP8266_status == receive_time)
    {
      receive_time_string[t_index][r_index++] = esp8266.read();
      receive_time_string[t_index][r_index] = '\0';
    }
    else if(ESP8266_status == DI_sleep_mode)
    {
      sleep_mode_string[0][r_index++] = esp8266.read();
      sleep_mode_string[0][r_index] = '\0';
    }
    else if(ESP8266_status == EN_sleep_mode)
    {
      sleep_mode_string[1][r_index++] = esp8266.read();
      sleep_mode_string[1][r_index] = '\0';
    }
  }
}

void ESP8266_wakeup()
{
  if(ESP8266_status == DI_sleep_mode)
  {
    if(send_wakeup_mode == false && send_sleep_mode == true)
    {
        r_index = 0;
        memset(sleep_mode_string[0],0,30);
        esp8266.print(leave_sleep_mode);
        send_wakeup_mode = true;
        send_sleep_mode = false;
    }
    if(strstr(sleep_mode_string[0],"AT+SLEEP=0") && strstr(sleep_mode_string[0],"OK"))
    {
      ESP8266_status = receive_time;
    }
  }
}

void ESP8266_sleep()
{
  if(ESP8266_status == EN_sleep_mode)
  {
    if(send_sleep_mode == false && send_wakeup_mode == true)
    {
      r_index = 0;
      memset(sleep_mode_string[1],0,30);
      esp8266.print(enter_sleep_mode);
      send_sleep_mode = true;
    }
    if(strstr(sleep_mode_string[1],"AT+SLEEP=2") && strstr(sleep_mode_string[1],"OK"))
    {
      ESP8266_status = status_default;
    }
  }
}

void ESP8266_get_time()
{
  if (ESP8266_status == receive_time)
  {
    if (time_request == false)
    {
      r_index = 0;
      memset(receive_time_string[t_index], 0, 70);
      esp8266.print(esp8266_cmd_str[4]);
      time_request = true;
    }
    if (strstr(receive_time_string[t_index], "OK") && strstr(receive_time_string[t_index], "1970") == NULL && strlen(receive_time_string[t_index]) == 60)
    {
      if (t_index == 0)
      {
        t_index = 1;
        r_index = 0;
        time_request = false;
      }
      else
      {
        if (check_string(receive_time_string[0], receive_time_string[1]))
        {    
          r_index = 0;
          time_request = false;
        }
        else
        {
          hour = 0;
          minute = 0;
          seconds = 0;
          mili_sec = 0;
          Timer_init();
          t_index = 0;
          ILI9341_convert_time(receive_time_string[1]);
          ESP8266_status = EN_sleep_mode;
        }
      }
    }
  }
}

bool check_string(char* s1, char* s2)
{
  char temp1[71];
  char temp2[71];
  String str1;
  String str2;
  uint8_t idx1 = 0;
  uint8_t idx2 = 0;
  for (uint8_t i = 0; s1[i]; i++)
  {
    if (!isSpace(s1[i]))
    {
      temp1[idx1++] = s1[i];
    }
    if (!isSpace(s2[i]))
    {
      temp2[idx2++] = s2[i];
    }
  }
  temp1[idx1] = '\0';
  temp2[idx2] = '\0';
  str1 = temp1;
  str2 = temp2;
  return str1.equals(str2);
}

void change_display()
{
  if(digitalRead(2) == LOW)
  {
    delay(500);
    if(digitalRead(2) == LOW)
    {
      display_mode++;
      display_mode %= 3;
      is_display_changed = true;
      TH_sensor_update = true;
      air_sensor_update = true;
      time_update_status = true;
      if(display_mode == time_mode)
      {
        ESP8266_status = DI_sleep_mode;
        time_request = false;
        send_wakeup_mode = false;
      }
    }
  }
}

void receive_time_again()
{
  if(digitalRead(3) == LOW)
  {
    delay(500);
    if(digitalRead(3) == LOW)
    {    
      hour = 0;
      minute = 0;
      seconds = 0;
      mili_sec = 0;
      ESP8266_status = DI_sleep_mode;
      time_update_status = true;
      time_request = false;
      send_wakeup_mode = false;
    }
  }
}

ISR(TIMER0_COMPA_vect)
{
  mili_sec++;
  if(mili_sec == 1000)
  {
    seconds += (mili_sec / 1000);
    mili_sec %= 1000;
  }
  if (seconds >= 59)
  {
    time_update_status = true;
    minute++;
    seconds %= 59;
    TH_sensor_update = true;
    air_sensor_update = true;
    if (minute == 60)
    {
      ESP8266_status = DI_sleep_mode;
      time_update_status = true;
      time_request = false;
      send_wakeup_mode = false;
    }
  }
}

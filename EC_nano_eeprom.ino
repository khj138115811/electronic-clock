#include <EEPROM.h>

uint32_t kor_day_0h_11h_1_mv[9] = { 0x842110,0x1F,0x210841,0x10,0x42101F,0x1,0x1C00000,0x1F21084,0x700000 }; // 오
uint32_t kor_day_0h_11h_2_mv[9] = { 0x100001C,0xD3885F,0x843D09,0x1198,0x218,0x842528,0x1842108,0x1F00000,0x700008 }; // 전
uint32_t kor_day_12h_23h_1_mv[9] = { 0x842110,0x1F,0x210841,0x10,0x42101F,0x1,0x1C00000,0x1F21084,0x700000 }; // 오
uint32_t kor_day_12h_23h_2_mv[9] = { 0x1007010,0x1F07C1F,0x101C01,0x82108,0xF8000,0x8842,0x1E,0x42109F,0xF }; // 후

uint32_t kor_mon_mv[9] = { 0x1042110,0xF8420F,0x421080,0x380,0x887E0,0x4390A4,0x1846018,0x1F07C1F,0x701C87 }; // 월
uint32_t kor_tue_mv[9] = { 0xF0300,0xF80E0,0x210840,0x1821098,0x742107,0x217842,0x1E00000,0x1F08420,0x210842 }; // 화
uint32_t kor_wed_mv[9] = { 0x1880000,0x8EDC4,0x308000,0x1F008CC,0x1F00000,0x1F02186,0x000000,0x421084,0x000000 }; // 수
uint32_t kor_thu_mv[9] = { 0x1842118,0x1F0001F,0x310843,0xE0000,0xF9080,0x38000,0x18,0x1F,0x210843 }; // 목
uint32_t kor_fri_mv[9] = { 0x18,0x1F,0x210843,0x8C0380,0xF83E0,0x2180E0,0x1842108,0x1F00000,0x310842 }; // 금
uint32_t kor_sat_mv[9] = { 0x8C2118,0xF801F,0x18003,0x308,0x4203E0,0x60,0x1C00000,0x1F21084,0x700000 }; // 토
uint32_t kor_sun_mv[9] = { 0x421098,0x1F,0x5294A4,0xC0018,0xF801F,0x438084,0x1842300,0x1F003E0,0x7000E4 }; // 일
uint32_t kor_year_mv[9] = { 0x842108,0x1806000,0x721C84,0x6108,0x7C00,0x421484,0x1084210,0x1F00000,0x700000 }; // 년
uint32_t kor_month_mv[9] = { 0x1042110,0xF8420F,0x421080,0x380,0x887E0,0x4390A4,0x1846018,0x1F07C1F,0x701C87 }; // 월
uint32_t kor_day_mv[9] = { 0x421098,0x1F,0x5294A4,0xC0018,0xF801F,0x438084,0x1842300,0x1F003E0,0x7000E4 }; // 일

uint32_t kor_date_1_mv[9] = { 0x842110,0x1F,0x210841,0x10,0x118C41F,0x1,0x1C00000,0x1F8C631,0x700000 }; // 요
uint32_t kor_date_2_mv[9] = { 0x421098,0x1F,0x5294A4,0xC0018,0xF801F,0x438084,0x1842300,0x1F003E0,0x7000E4 }; // 일

uint32_t kor_air_1_mv[9] = { 0x18,0x20001F,0x210843,0x1007000,0x1F07C42,0x101C00,0x1042108,0x1F00000,0x110842 }; // 공
uint32_t kor_air_2_mv[9] = { 0x1C,0x108421F,0x421084,0x000000,0x1084210,0x421084,0x000000,0x1084210,0x421084 }; // 기

uint32_t kor_bad_1_mv[9] = { 0x421000,0x0000,0x108400,0x421084,0x0000,0x10BC21,0x384,0x1E0,0x421 }; // 나
uint32_t kor_bad_2_mv[9] = { 0x846108,0x427C84,0x210C42,0x1807018,0x1F07C1F,0x301C03,0x1842108,0x1F00000,0x310842 }; // 쁨

uint32_t kor_normal_1_mv[9] = { 0x846108,0x7C00,0x210C42,0x18,0x42101F,0x3,0x1C00000,0x1F21084,0x700000 }; // 보
uint32_t kor_normal_2_mv[9] = { 0x1846118,0x1F07C1F,0x300C03,0xE0000,0xF9080,0x38000,0x1042110,0x1F0001F,0x110841 }; // 통

uint32_t kor_good_1_mv[9] = { 0x1000018,0x8A89F,0x100003,0x7008,0x407C84,0x1C02,0x1044018,0x1F07C1F,0x110403 }; // 좋
uint32_t kor_good_2_mv[9] = { 0x1042110,0x1F0001F,0x110841,0x8C0380,0xF83E0,0x2180E0,0x1842108,0x1F00000,0x310842 }; // 음

uint32_t kor_temperature_1_mv[9] = { 0x1042110,0x1F0001F,0x110841,0xE0000,0xF9080,0x38000,0x1842108,0x1F00000,0x300000 }; // 온
uint32_t kor_temperature_2_mv[9] = { 0x842118,0x1F,0x3,0x18,0x42101F,0x3,0x1C00000,0x1F21084,0x700000 }; // 도

uint32_t kor_humidity_1_mv[9] = { 0x880000,0x4544,0x208000,0x807004,0x7C00,0x201C04,0x1842308,0x1F003E0,0x310862 }; // 습
uint32_t kor_humidity_2_mv[9] = { 0x842118,0x1F,0x3,0x18,0x42101F,0x3,0x1C00000,0x1F21084,0x700000 }; // 도

uint32_t celsius_symbol_mv[9] = { 0xC94980,0x426000,0x1C00,0x000000,0x410844,0x000000,0x000000,0x6084,0x1C00 }; // ℃
uint32_t parts_per_million_symbol_mv[9] = { 0x700000,0x700000,0x1500000,0x109D29,0x109D29,0x118C63B,0x1,0x1,0x11 }; // ppm
uint32_t parts_per_billion_symbol_mv[9] = { 0x700000,0x700000,0x100000,0x109D29,0x109D29,0x949C21,0x1,0x1,0x7 }; // ppm
uint32_t percent_symbol_mv[9] = { 0x426000,0x108000,0x111000,0x18,0x111110,0x300000,0x1110,0x210,0xC84 }; // %
uint32_t* kor_arr[32] = {kor_day_0h_11h_1_mv,kor_day_0h_11h_2_mv,kor_day_12h_23h_1_mv,kor_day_12h_23h_2_mv,kor_mon_mv, kor_tue_mv, kor_wed_mv, kor_thu_mv, kor_fri_mv, kor_sat_mv, kor_sun_mv,kor_year_mv,kor_month_mv,kor_day_mv,
  kor_date_1_mv,kor_date_2_mv,kor_air_1_mv,kor_air_2_mv,kor_bad_1_mv,kor_bad_2_mv,kor_normal_1_mv,kor_normal_2_mv,kor_good_1_mv,kor_good_2_mv,parts_per_million_symbol_mv,parts_per_billion_symbol_mv,
  kor_temperature_1_mv,kor_temperature_2_mv,kor_humidity_1_mv,kor_humidity_2_mv,celsius_symbol_mv,percent_symbol_mv};

uint16_t kor_index[32] = {0,29,58,87,116,145,174,203,232,261,290,319,348,377,406,435,464,493,522,551,580,609,638,667,696,725,754,783,812,841,870,899};

volatile uint32_t receive_arr[9] = {0};

void setup() {
  Serial.begin(9600);
  for(uint8_t i = 0; i < 32; i++)
  {
    EEPROM_write_page(kor_index[i],kor_arr[i]);
  }
  for(uint8_t i = 0; i < 32; i++)
  {
    EEPROM_read_page(kor_index[i],receive_arr);
    for(uint8_t j = 0; j < 9; j++)
    {
      Serial.print("0x");
      Serial.println(receive_arr[j],HEX);
    }
  }
}

void loop() {
  
}

void EEPROM_write_page(uint16_t page_addr, uint32_t* data_bytes)
{
  uint8_t send_bytes[29] = {0};
  for(uint8_t i = 0; i < 27; i++)
  {
    send_bytes[i] = convert_25_to_8_bit(data_bytes[i/3], (i % 3));
  }
  send_bytes[27] = 0;
  for(uint8_t i = 0; i < 8; i++)
  {
    send_bytes[27] |= ((data_bytes[i] & 0x01) << i);
  }
  send_bytes[28] = data_bytes[8] & 0x01;
  for(uint8_t i = 0; i < 29; i++)
  {
    EEPROM.update(page_addr+i,send_bytes[i]);
  }
}

uint8_t convert_25_to_8_bit(uint32_t data, uint8_t num)
{
  uint8_t return_data = 0;
  if(num == 0)
  {
    return_data = (uint8_t)((data & 0x1FE0000) >> 17);
  }
  else if(num == 1)
  {
    return_data = (uint8_t)((data & 0x1FE00) >> 9);
  }
  else if(num == 2)
  {
    return_data = (uint8_t)((data & 0x1FE) >> 1);
  }
  return return_data;
}

uint32_t convert_8_to_25_bit(uint16_t addr)
{
  uint32_t return_data = 0;
  volatile uint32_t temp_data[3] = {0};
  for(uint8_t i = 0; i < 3; i++)
  {
    temp_data[i] = EEPROM.read(addr+i);
  }
  return_data |= (temp_data[0] << 17) | (temp_data[1] << 9) | (temp_data[2] << 1);
  return return_data;
}

void EEPROM_read_page(uint16_t page_addr, volatile uint32_t* data_bytes)
{
  volatile uint8_t temp_data;
  for(uint8_t i = 0; i < 9; i++)
  {
    data_bytes[i] = convert_8_to_25_bit(page_addr+(i*3));
  }
  temp_data = EEPROM.read(page_addr+27);
  for(uint8_t i = 0; i < 8; i++)
  {
    data_bytes[i] |= (temp_data & (1 << i)) ? 0x01 : 0x00;
  }
  temp_data = EEPROM.read(page_addr+28);
  data_bytes[8] |= temp_data;
}

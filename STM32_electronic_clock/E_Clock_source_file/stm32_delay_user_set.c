#include "stm32_delay_user_set.h"

void _delay_s(uint32_t ncount)
{
  uint64_t count = ncount * 2000000;
  while (count != 0)
  {
    count--;
  }
}
void _delay_ms(uint32_t ncount)
{
  uint64_t count = ncount * 2000;
  while (count != 0)
  {
    count--;
  }
}
void _delay_us(uint32_t ncount)
{
  uint64_t count = ncount * 2;
  while (count != 0)
  {
    count--;
  }
}
#include "timer_init.h"

extern TIM_HandleTypeDef htim3;

void timer_3_init()
{
	__HAL_TIM_SET_COUNTER(&htim3, 0);
	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
	__HAL_TIM_ENABLE(&htim3);
}

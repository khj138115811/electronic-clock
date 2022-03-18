#include "uart.h"

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

void uart_2_transmit(uint8_t pData)
{
	while((HAL_UART_GetState(&huart2) == HAL_UART_STATE_BUSY_TX));
	while(!(HAL_UART_Transmit(&huart2, &pData, 1, 10000) == HAL_OK));
}

uint8_t uart_2_receive()
{
	uint8_t pData;
	while((HAL_UART_GetState(&huart2) == HAL_UART_STATE_BUSY_RX));
	while(!(HAL_UART_Receive(&huart2, &pData, 1, 10000) == HAL_OK));
	return pData;
}

void uart_3_transmit(uint8_t pData)
{
	while((HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX));
	while(!(HAL_UART_Transmit(&huart3, &pData, 1, 10000) == HAL_OK));
}

uint8_t uart_3_receive()
{
	uint8_t pData;
	while((HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_RX));
	while(!(HAL_UART_Receive(&huart3, &pData, 1, 1000) == HAL_OK));
	return pData;
}

PUTCHAR_PROTOTYPE
{
	uart_2_transmit(ch);
	return ch;
}

GETCHAR_PROTOTYPE
{
	int ch = uart_2_receive();
	return ch;
}

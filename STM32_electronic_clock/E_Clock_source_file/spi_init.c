#include "spi_init.h"

extern SPI_HandleTypeDef hspi1;

void spi_1_chip_select()
{
	HAL_GPIO_WritePin(GPIOA, SPI_CS_Pin, GPIO_PIN_RESET);
}
void spi_1_chip_deselect()
{
	HAL_GPIO_WritePin(GPIOA, SPI_CS_Pin, GPIO_PIN_SET);
}
void spi_1_write_data(uint8_t pData)
{
	while(HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_BUSY_TX);
	HAL_SPI_Transmit(&hspi1, &pData, 1, 100);
}
void spi_1_receive_start()
{
	spi_1_write_data(0x00);
}
uint8_t spi_1_receive_data()
{
	uint8_t pData;
	while(!(HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_BUSY_RX));
	HAL_SPI_Receive(&hspi1, &pData, 1, 100);
	return pData;
}

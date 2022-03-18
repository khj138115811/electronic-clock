#include "i2c_init.h"

extern I2C_HandleTypeDef hi2c1;

void i2c_1_start_send_addr_send_data_stop(uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
	while(!(HAL_I2C_Master_Transmit(&hi2c1, (DevAddress << 1), pData, Size, 1000) == HAL_OK));
}

void i2c_1_start_receive_addr_receive_data_stop(uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
	while(!(HAL_I2C_Master_Receive(&hi2c1, (DevAddress << 1)+1, pData, Size, 1000) == HAL_OK));
}

#ifndef __I2C_INIT_H
#define __I2C_INIT_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_i2c.h"

void i2c_1_start_send_addr_send_data_stop(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
void i2c_1_start_receive_addr_receive_data_stop(uint16_t DevAddress, uint8_t *pData, uint16_t Size);


#endif /*__I2C_INIT_H*/

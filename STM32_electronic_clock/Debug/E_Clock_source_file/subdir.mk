################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../E_Clock_source_file/CCS811_air_quality_sensor.c \
../E_Clock_source_file/ESP8266.c \
../E_Clock_source_file/ILI9341_LCD_input_data.c \
../E_Clock_source_file/ILI9341_TFT_LCD.c \
../E_Clock_source_file/ILI9341_TFT_LCD_init.c \
../E_Clock_source_file/SHT31_temp_humi_sensor.c \
../E_Clock_source_file/gpio_init.c \
../E_Clock_source_file/i2c_init.c \
../E_Clock_source_file/interrupt_init.c \
../E_Clock_source_file/rcc_init.c \
../E_Clock_source_file/spi_init.c \
../E_Clock_source_file/stm32_delay_user_set.c \
../E_Clock_source_file/timer_init.c \
../E_Clock_source_file/uart.c 

OBJS += \
./E_Clock_source_file/CCS811_air_quality_sensor.o \
./E_Clock_source_file/ESP8266.o \
./E_Clock_source_file/ILI9341_LCD_input_data.o \
./E_Clock_source_file/ILI9341_TFT_LCD.o \
./E_Clock_source_file/ILI9341_TFT_LCD_init.o \
./E_Clock_source_file/SHT31_temp_humi_sensor.o \
./E_Clock_source_file/gpio_init.o \
./E_Clock_source_file/i2c_init.o \
./E_Clock_source_file/interrupt_init.o \
./E_Clock_source_file/rcc_init.o \
./E_Clock_source_file/spi_init.o \
./E_Clock_source_file/stm32_delay_user_set.o \
./E_Clock_source_file/timer_init.o \
./E_Clock_source_file/uart.o 

C_DEPS += \
./E_Clock_source_file/CCS811_air_quality_sensor.d \
./E_Clock_source_file/ESP8266.d \
./E_Clock_source_file/ILI9341_LCD_input_data.d \
./E_Clock_source_file/ILI9341_TFT_LCD.d \
./E_Clock_source_file/ILI9341_TFT_LCD_init.d \
./E_Clock_source_file/SHT31_temp_humi_sensor.d \
./E_Clock_source_file/gpio_init.d \
./E_Clock_source_file/i2c_init.d \
./E_Clock_source_file/interrupt_init.d \
./E_Clock_source_file/rcc_init.d \
./E_Clock_source_file/spi_init.d \
./E_Clock_source_file/stm32_delay_user_set.d \
./E_Clock_source_file/timer_init.d \
./E_Clock_source_file/uart.d 


# Each subdirectory must supply rules for building sources it contributes
E_Clock_source_file/CCS811_air_quality_sensor.o: ../E_Clock_source_file/CCS811_air_quality_sensor.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/CCS811_air_quality_sensor.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/ESP8266.o: ../E_Clock_source_file/ESP8266.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/ESP8266.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/ILI9341_LCD_input_data.o: ../E_Clock_source_file/ILI9341_LCD_input_data.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/ILI9341_LCD_input_data.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/ILI9341_TFT_LCD.o: ../E_Clock_source_file/ILI9341_TFT_LCD.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/ILI9341_TFT_LCD.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/ILI9341_TFT_LCD_init.o: ../E_Clock_source_file/ILI9341_TFT_LCD_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/ILI9341_TFT_LCD_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/SHT31_temp_humi_sensor.o: ../E_Clock_source_file/SHT31_temp_humi_sensor.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/SHT31_temp_humi_sensor.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/gpio_init.o: ../E_Clock_source_file/gpio_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/gpio_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/i2c_init.o: ../E_Clock_source_file/i2c_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/i2c_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/interrupt_init.o: ../E_Clock_source_file/interrupt_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/interrupt_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/rcc_init.o: ../E_Clock_source_file/rcc_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/rcc_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/spi_init.o: ../E_Clock_source_file/spi_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/spi_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/stm32_delay_user_set.o: ../E_Clock_source_file/stm32_delay_user_set.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/stm32_delay_user_set.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/timer_init.o: ../E_Clock_source_file/timer_init.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/timer_init.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"
E_Clock_source_file/uart.o: ../E_Clock_source_file/uart.c E_Clock_source_file/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_header_file" -I"C:/Users/khs94/Desktop/STM32_IDE/E_Clock_source_file" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"E_Clock_source_file/uart.d" -MT"$@"  -mfloat-abi=soft -mthumb -o "$@"


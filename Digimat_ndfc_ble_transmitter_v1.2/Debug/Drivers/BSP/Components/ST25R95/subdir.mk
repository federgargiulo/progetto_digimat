################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/ST25R95/st25r95.c \
../Drivers/BSP/Components/ST25R95/st25r95_com.c \
../Drivers/BSP/Components/ST25R95/st25r95_com_spi.c \
../Drivers/BSP/Components/ST25R95/st25r95_com_uart.c \
../Drivers/BSP/Components/ST25R95/timer.c 

OBJS += \
./Drivers/BSP/Components/ST25R95/st25r95.o \
./Drivers/BSP/Components/ST25R95/st25r95_com.o \
./Drivers/BSP/Components/ST25R95/st25r95_com_spi.o \
./Drivers/BSP/Components/ST25R95/st25r95_com_uart.o \
./Drivers/BSP/Components/ST25R95/timer.o 

C_DEPS += \
./Drivers/BSP/Components/ST25R95/st25r95.d \
./Drivers/BSP/Components/ST25R95/st25r95_com.d \
./Drivers/BSP/Components/ST25R95/st25r95_com_spi.d \
./Drivers/BSP/Components/ST25R95/st25r95_com_uart.d \
./Drivers/BSP/Components/ST25R95/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ST25R95/%.o Drivers/BSP/Components/ST25R95/%.su Drivers/BSP/Components/ST25R95/%.cyclo: ../Drivers/BSP/Components/ST25R95/%.c Drivers/BSP/Components/ST25R95/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_LOGGER -DST25R95 -DUSE_HAL_DRIVER -DSTM32F401xE -DSTM32F401xx -c -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../Core/Inc -I../Drivers/BSP/STM32F4xx_Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -I../Drivers/BSP/Components/ST25R95 -I../Middlewares/ST/ndef/Inc/message -I../Middlewares/ST/ndef/Inc/poller -I../Middlewares/ST/rfal/Inc/ -I../Middlewares/ST/rfal/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-ST25R95

clean-Drivers-2f-BSP-2f-Components-2f-ST25R95:
	-$(RM) ./Drivers/BSP/Components/ST25R95/st25r95.cyclo ./Drivers/BSP/Components/ST25R95/st25r95.d ./Drivers/BSP/Components/ST25R95/st25r95.o ./Drivers/BSP/Components/ST25R95/st25r95.su ./Drivers/BSP/Components/ST25R95/st25r95_com.cyclo ./Drivers/BSP/Components/ST25R95/st25r95_com.d ./Drivers/BSP/Components/ST25R95/st25r95_com.o ./Drivers/BSP/Components/ST25R95/st25r95_com.su ./Drivers/BSP/Components/ST25R95/st25r95_com_spi.cyclo ./Drivers/BSP/Components/ST25R95/st25r95_com_spi.d ./Drivers/BSP/Components/ST25R95/st25r95_com_spi.o ./Drivers/BSP/Components/ST25R95/st25r95_com_spi.su ./Drivers/BSP/Components/ST25R95/st25r95_com_uart.cyclo ./Drivers/BSP/Components/ST25R95/st25r95_com_uart.d ./Drivers/BSP/Components/ST25R95/st25r95_com_uart.o ./Drivers/BSP/Components/ST25R95/st25r95_com_uart.su ./Drivers/BSP/Components/ST25R95/timer.cyclo ./Drivers/BSP/Components/ST25R95/timer.d ./Drivers/BSP/Components/ST25R95/timer.o ./Drivers/BSP/Components/ST25R95/timer.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-ST25R95


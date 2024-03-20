################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BlueNRG_MS/Target/hci_tl_interface.c 

OBJS += \
./BlueNRG_MS/Target/hci_tl_interface.o 

C_DEPS += \
./BlueNRG_MS/Target/hci_tl_interface.d 


# Each subdirectory must supply rules for building sources it contributes
BlueNRG_MS/Target/%.o BlueNRG_MS/Target/%.su BlueNRG_MS/Target/%.cyclo: ../BlueNRG_MS/Target/%.c BlueNRG_MS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_LOGGER -DST25R95 -DUSE_HAL_DRIVER -DSTM32F401xE -DSTM32F401xx -c -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../Core/Inc -I../Drivers/BSP/STM32F4xx_Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -I../Drivers/BSP/Components/ST25R95 -I../Middlewares/ST/ndef/Inc/message -I../Middlewares/ST/ndef/Inc/poller -I../Middlewares/ST/rfal/Inc/ -I../Middlewares/ST/rfal/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BlueNRG_MS-2f-Target

clean-BlueNRG_MS-2f-Target:
	-$(RM) ./BlueNRG_MS/Target/hci_tl_interface.cyclo ./BlueNRG_MS/Target/hci_tl_interface.d ./BlueNRG_MS/Target/hci_tl_interface.o ./BlueNRG_MS/Target/hci_tl_interface.su

.PHONY: clean-BlueNRG_MS-2f-Target


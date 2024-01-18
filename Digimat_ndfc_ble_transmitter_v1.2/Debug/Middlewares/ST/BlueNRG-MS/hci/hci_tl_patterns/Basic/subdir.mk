################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.c 

OBJS += \
./Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.o 

C_DEPS += \
./Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/%.o Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/%.su Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/%.cyclo: ../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/%.c Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_LOGGER -DST25R95 -DUSE_HAL_DRIVER -DSTM32F401xE -DSTM32F401xx -c -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../Core/Inc -I../Drivers/BSP/STM32F4xx_Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -I../Drivers/BSP/Components/ST25R95 -I../Middlewares/ST/ndef/Inc/message -I../Middlewares/ST/ndef/Inc/poller -I../Middlewares/ST/rfal/Inc/ -I../Middlewares/ST/rfal/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-BlueNRG-2d-MS-2f-hci-2f-hci_tl_patterns-2f-Basic

clean-Middlewares-2f-ST-2f-BlueNRG-2d-MS-2f-hci-2f-hci_tl_patterns-2f-Basic:
	-$(RM) ./Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.cyclo ./Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.d ./Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.o ./Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.su

.PHONY: clean-Middlewares-2f-ST-2f-BlueNRG-2d-MS-2f-hci-2f-hci_tl_patterns-2f-Basic


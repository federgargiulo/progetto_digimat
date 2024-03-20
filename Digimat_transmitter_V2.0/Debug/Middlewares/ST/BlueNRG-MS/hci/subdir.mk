################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/BlueNRG-MS/hci/hci_le.c 

OBJS += \
./Middlewares/ST/BlueNRG-MS/hci/hci_le.o 

C_DEPS += \
./Middlewares/ST/BlueNRG-MS/hci/hci_le.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/BlueNRG-MS/hci/%.o Middlewares/ST/BlueNRG-MS/hci/%.su Middlewares/ST/BlueNRG-MS/hci/%.cyclo: ../Middlewares/ST/BlueNRG-MS/hci/%.c Middlewares/ST/BlueNRG-MS/hci/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../X-CUBE-MEMS1/Target -I../Core/Inc -I../Drivers/BSP/STM32F4xx_Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -I../Drivers/BSP/Components/lsm6dso -I../Drivers/BSP/Components/lis2dw12 -I../Drivers/BSP/Components/lis2mdl -I../Drivers/BSP/Components/hts221 -I../Drivers/BSP/Components/lps22hh -I../Drivers/BSP/Components/stts751 -I../Drivers/BSP/IKS01A3 -I../Drivers/BSP/Components/Common -I../Middlewares/ST/ARM/DSP/Inc -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-BlueNRG-2d-MS-2f-hci

clean-Middlewares-2f-ST-2f-BlueNRG-2d-MS-2f-hci:
	-$(RM) ./Middlewares/ST/BlueNRG-MS/hci/hci_le.cyclo ./Middlewares/ST/BlueNRG-MS/hci/hci_le.d ./Middlewares/ST/BlueNRG-MS/hci/hci_le.o ./Middlewares/ST/BlueNRG-MS/hci/hci_le.su

.PHONY: clean-Middlewares-2f-ST-2f-BlueNRG-2d-MS-2f-hci


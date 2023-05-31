################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/lis2dw12/lis2dw12.c \
../Drivers/BSP/Components/lis2dw12/lis2dw12_reg.c 

OBJS += \
./Drivers/BSP/Components/lis2dw12/lis2dw12.o \
./Drivers/BSP/Components/lis2dw12/lis2dw12_reg.o 

C_DEPS += \
./Drivers/BSP/Components/lis2dw12/lis2dw12.d \
./Drivers/BSP/Components/lis2dw12/lis2dw12_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/lis2dw12/%.o Drivers/BSP/Components/lis2dw12/%.su Drivers/BSP/Components/lis2dw12/%.cyclo: ../Drivers/BSP/Components/lis2dw12/%.c Drivers/BSP/Components/lis2dw12/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../BlueNRG_MS/App -I../BlueNRG_MS/Target -I../X-CUBE-MEMS1/Target -I../Core/Inc -I../Drivers/BSP/STM32F4xx_Nucleo -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/BlueNRG-MS/utils -I../Middlewares/ST/BlueNRG-MS/includes -I../Drivers/BSP/Components/lsm6dso -I../Drivers/BSP/Components/lis2dw12 -I../Drivers/BSP/Components/lis2mdl -I../Drivers/BSP/Components/hts221 -I../Drivers/BSP/Components/lps22hh -I../Drivers/BSP/Components/stts751 -I../Drivers/BSP/IKS01A3 -I../Drivers/BSP/Components/Common -I../Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-lis2dw12

clean-Drivers-2f-BSP-2f-Components-2f-lis2dw12:
	-$(RM) ./Drivers/BSP/Components/lis2dw12/lis2dw12.cyclo ./Drivers/BSP/Components/lis2dw12/lis2dw12.d ./Drivers/BSP/Components/lis2dw12/lis2dw12.o ./Drivers/BSP/Components/lis2dw12/lis2dw12.su ./Drivers/BSP/Components/lis2dw12/lis2dw12_reg.cyclo ./Drivers/BSP/Components/lis2dw12/lis2dw12_reg.d ./Drivers/BSP/Components/lis2dw12/lis2dw12_reg.o ./Drivers/BSP/Components/lis2dw12/lis2dw12_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-lis2dw12


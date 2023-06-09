################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/iis3dwb/iis3dwb.c \
../Drivers/BSP/Components/iis3dwb/iis3dwb_reg.c 

OBJS += \
./Drivers/BSP/Components/iis3dwb/iis3dwb.o \
./Drivers/BSP/Components/iis3dwb/iis3dwb_reg.o 

C_DEPS += \
./Drivers/BSP/Components/iis3dwb/iis3dwb.d \
./Drivers/BSP/Components/iis3dwb/iis3dwb_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/iis3dwb/%.o Drivers/BSP/Components/iis3dwb/%.su Drivers/BSP/Components/iis3dwb/%.cyclo: ../Drivers/BSP/Components/iis3dwb/%.c Drivers/BSP/Components/iis3dwb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../Drivers/BSP/Components/iis3dwb -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components-2f-iis3dwb

clean-Drivers-2f-BSP-2f-Components-2f-iis3dwb:
	-$(RM) ./Drivers/BSP/Components/iis3dwb/iis3dwb.cyclo ./Drivers/BSP/Components/iis3dwb/iis3dwb.d ./Drivers/BSP/Components/iis3dwb/iis3dwb.o ./Drivers/BSP/Components/iis3dwb/iis3dwb.su ./Drivers/BSP/Components/iis3dwb/iis3dwb_reg.cyclo ./Drivers/BSP/Components/iis3dwb/iis3dwb_reg.d ./Drivers/BSP/Components/iis3dwb/iis3dwb_reg.o ./Drivers/BSP/Components/iis3dwb/iis3dwb_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components-2f-iis3dwb


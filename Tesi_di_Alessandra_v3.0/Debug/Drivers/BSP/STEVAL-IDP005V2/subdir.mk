################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.c 

OBJS += \
./Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.o 

C_DEPS += \
./Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STEVAL-IDP005V2/%.o Drivers/BSP/STEVAL-IDP005V2/%.su Drivers/BSP/STEVAL-IDP005V2/%.cyclo: ../Drivers/BSP/STEVAL-IDP005V2/%.c Drivers/BSP/STEVAL-IDP005V2/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../X-CUBE-MEMS1/Target -I../Drivers/BSP/STEVAL-IDP005V2 -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/iis3dwb -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STEVAL-2d-IDP005V2

clean-Drivers-2f-BSP-2f-STEVAL-2d-IDP005V2:
	-$(RM) ./Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.cyclo ./Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.d ./Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.o ./Drivers/BSP/STEVAL-IDP005V2/steval_idp005v2_bus.su

.PHONY: clean-Drivers-2f-BSP-2f-STEVAL-2d-IDP005V2


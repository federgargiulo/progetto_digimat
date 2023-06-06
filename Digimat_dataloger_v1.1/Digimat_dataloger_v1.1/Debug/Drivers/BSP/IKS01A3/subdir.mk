################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/IKS01A3/iks01a3_env_sensors.c \
../Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.c \
../Drivers/BSP/IKS01A3/iks01a3_motion_sensors.c \
../Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.c 

OBJS += \
./Drivers/BSP/IKS01A3/iks01a3_env_sensors.o \
./Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.o \
./Drivers/BSP/IKS01A3/iks01a3_motion_sensors.o \
./Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.o 

C_DEPS += \
./Drivers/BSP/IKS01A3/iks01a3_env_sensors.d \
./Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.d \
./Drivers/BSP/IKS01A3/iks01a3_motion_sensors.d \
./Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/IKS01A3/%.o Drivers/BSP/IKS01A3/%.su Drivers/BSP/IKS01A3/%.cyclo: ../Drivers/BSP/IKS01A3/%.c Drivers/BSP/IKS01A3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../FATFS/Target -I../FATFS/App -I../X-CUBE-MEMS1/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/lsm6dso -I../Drivers/BSP/Components/lis2dw12 -I../Drivers/BSP/Components/lis2mdl -I../Drivers/BSP/Components/hts221 -I../Drivers/BSP/Components/lps22hh -I../Drivers/BSP/Components/stts751 -I../Drivers/BSP/IKS01A3 -I../Drivers/BSP/Components/Common -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-IKS01A3

clean-Drivers-2f-BSP-2f-IKS01A3:
	-$(RM) ./Drivers/BSP/IKS01A3/iks01a3_env_sensors.cyclo ./Drivers/BSP/IKS01A3/iks01a3_env_sensors.d ./Drivers/BSP/IKS01A3/iks01a3_env_sensors.o ./Drivers/BSP/IKS01A3/iks01a3_env_sensors.su ./Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.cyclo ./Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.d ./Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.o ./Drivers/BSP/IKS01A3/iks01a3_env_sensors_ex.su ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors.cyclo ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors.d ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors.o ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors.su ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.cyclo ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.d ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.o ./Drivers/BSP/IKS01A3/iks01a3_motion_sensors_ex.su

.PHONY: clean-Drivers-2f-BSP-2f-IKS01A3


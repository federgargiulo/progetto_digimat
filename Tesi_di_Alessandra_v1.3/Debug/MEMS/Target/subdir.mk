################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MEMS/Target/com.c \
../MEMS/Target/custom_mems_control.c \
../MEMS/Target/custom_mems_control_ex.c \
../MEMS/Target/demo_serial.c \
../MEMS/Target/motion_ac2_manager.c \
../MEMS/Target/serial_protocol.c 

OBJS += \
./MEMS/Target/com.o \
./MEMS/Target/custom_mems_control.o \
./MEMS/Target/custom_mems_control_ex.o \
./MEMS/Target/demo_serial.o \
./MEMS/Target/motion_ac2_manager.o \
./MEMS/Target/serial_protocol.o 

C_DEPS += \
./MEMS/Target/com.d \
./MEMS/Target/custom_mems_control.d \
./MEMS/Target/custom_mems_control_ex.d \
./MEMS/Target/demo_serial.d \
./MEMS/Target/motion_ac2_manager.d \
./MEMS/Target/serial_protocol.d 


# Each subdirectory must supply rules for building sources it contributes
MEMS/Target/%.o MEMS/Target/%.su MEMS/Target/%.cyclo: ../MEMS/Target/%.c MEMS/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F469xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/iis3dwb -I../MEMS/App -I../MEMS/Target -I../Drivers/BSP/custom -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MEMS-2f-Target

clean-MEMS-2f-Target:
	-$(RM) ./MEMS/Target/com.cyclo ./MEMS/Target/com.d ./MEMS/Target/com.o ./MEMS/Target/com.su ./MEMS/Target/custom_mems_control.cyclo ./MEMS/Target/custom_mems_control.d ./MEMS/Target/custom_mems_control.o ./MEMS/Target/custom_mems_control.su ./MEMS/Target/custom_mems_control_ex.cyclo ./MEMS/Target/custom_mems_control_ex.d ./MEMS/Target/custom_mems_control_ex.o ./MEMS/Target/custom_mems_control_ex.su ./MEMS/Target/demo_serial.cyclo ./MEMS/Target/demo_serial.d ./MEMS/Target/demo_serial.o ./MEMS/Target/demo_serial.su ./MEMS/Target/motion_ac2_manager.cyclo ./MEMS/Target/motion_ac2_manager.d ./MEMS/Target/motion_ac2_manager.o ./MEMS/Target/motion_ac2_manager.su ./MEMS/Target/serial_protocol.cyclo ./MEMS/Target/serial_protocol.d ./MEMS/Target/serial_protocol.o ./MEMS/Target/serial_protocol.su

.PHONY: clean-MEMS-2f-Target


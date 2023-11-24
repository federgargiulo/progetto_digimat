################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/ndef/Src/poller/ndef_poller.c \
../Middlewares/ST/ndef/Src/poller/ndef_t2t.c \
../Middlewares/ST/ndef/Src/poller/ndef_t3t.c \
../Middlewares/ST/ndef/Src/poller/ndef_t4t.c \
../Middlewares/ST/ndef/Src/poller/ndef_t5t.c 

OBJS += \
./Middlewares/ST/ndef/Src/poller/ndef_poller.o \
./Middlewares/ST/ndef/Src/poller/ndef_t2t.o \
./Middlewares/ST/ndef/Src/poller/ndef_t3t.o \
./Middlewares/ST/ndef/Src/poller/ndef_t4t.o \
./Middlewares/ST/ndef/Src/poller/ndef_t5t.o 

C_DEPS += \
./Middlewares/ST/ndef/Src/poller/ndef_poller.d \
./Middlewares/ST/ndef/Src/poller/ndef_t2t.d \
./Middlewares/ST/ndef/Src/poller/ndef_t3t.d \
./Middlewares/ST/ndef/Src/poller/ndef_t4t.d \
./Middlewares/ST/ndef/Src/poller/ndef_t5t.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/ndef/Src/poller/%.o Middlewares/ST/ndef/Src/poller/%.su Middlewares/ST/ndef/Src/poller/%.cyclo: ../Middlewares/ST/ndef/Src/poller/%.c Middlewares/ST/ndef/Src/poller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Middlewares/ST/ndef/Inc/message -I../Middlewares/ST/ndef/Inc/poller -I../Middlewares/ST/rfal/Src -I../Middlewares/ST/rfal/Inc/ -I../Drivers/BSP/Components/ST25R95 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-ndef-2f-Src-2f-poller

clean-Middlewares-2f-ST-2f-ndef-2f-Src-2f-poller:
	-$(RM) ./Middlewares/ST/ndef/Src/poller/ndef_poller.cyclo ./Middlewares/ST/ndef/Src/poller/ndef_poller.d ./Middlewares/ST/ndef/Src/poller/ndef_poller.o ./Middlewares/ST/ndef/Src/poller/ndef_poller.su ./Middlewares/ST/ndef/Src/poller/ndef_t2t.cyclo ./Middlewares/ST/ndef/Src/poller/ndef_t2t.d ./Middlewares/ST/ndef/Src/poller/ndef_t2t.o ./Middlewares/ST/ndef/Src/poller/ndef_t2t.su ./Middlewares/ST/ndef/Src/poller/ndef_t3t.cyclo ./Middlewares/ST/ndef/Src/poller/ndef_t3t.d ./Middlewares/ST/ndef/Src/poller/ndef_t3t.o ./Middlewares/ST/ndef/Src/poller/ndef_t3t.su ./Middlewares/ST/ndef/Src/poller/ndef_t4t.cyclo ./Middlewares/ST/ndef/Src/poller/ndef_t4t.d ./Middlewares/ST/ndef/Src/poller/ndef_t4t.o ./Middlewares/ST/ndef/Src/poller/ndef_t4t.su ./Middlewares/ST/ndef/Src/poller/ndef_t5t.cyclo ./Middlewares/ST/ndef/Src/poller/ndef_t5t.d ./Middlewares/ST/ndef/Src/poller/ndef_t5t.o ./Middlewares/ST/ndef/Src/poller/ndef_t5t.su

.PHONY: clean-Middlewares-2f-ST-2f-ndef-2f-Src-2f-poller


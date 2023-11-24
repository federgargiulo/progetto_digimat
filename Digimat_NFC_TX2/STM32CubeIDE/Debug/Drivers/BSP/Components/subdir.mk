################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/Components/ST25DV/st25dv.c \
C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/Components/ST25DV/st25dv_reg.c 

OBJS += \
./Drivers/BSP/Components/st25dv.o \
./Drivers/BSP/Components/st25dv_reg.o 

C_DEPS += \
./Drivers/BSP/Components/st25dv.d \
./Drivers/BSP/Components/st25dv_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/st25dv.o: C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/Components/ST25DV/st25dv.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../NFC/App -I../../NFC/Target -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ST25DV -I../../Drivers/BSP/NFC04A1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/BSP/Components/st25dv.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/st25dv_reg.o: C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/Components/ST25DV/st25dv_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../NFC/App -I../../NFC/Target -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ST25DV -I../../Drivers/BSP/NFC04A1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/BSP/Components/st25dv_reg.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/st25dv.cyclo ./Drivers/BSP/Components/st25dv.d ./Drivers/BSP/Components/st25dv.o ./Drivers/BSP/Components/st25dv.su ./Drivers/BSP/Components/st25dv_reg.cyclo ./Drivers/BSP/Components/st25dv_reg.d ./Drivers/BSP/Components/st25dv_reg.o ./Drivers/BSP/Components/st25dv_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components


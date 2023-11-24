################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/NFC/App/app_nfc.c 

OBJS += \
./Application/User/NFC/App/app_nfc.o 

C_DEPS += \
./Application/User/NFC/App/app_nfc.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/NFC/App/app_nfc.o: C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/NFC/App/app_nfc.c Application/User/NFC/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../NFC/App -I../../NFC/Target -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ST25DV -I../../Drivers/BSP/NFC04A1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Application/User/NFC/App/app_nfc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-NFC-2f-App

clean-Application-2f-User-2f-NFC-2f-App:
	-$(RM) ./Application/User/NFC/App/app_nfc.cyclo ./Application/User/NFC/App/app_nfc.d ./Application/User/NFC/App/app_nfc.o ./Application/User/NFC/App/app_nfc.su

.PHONY: clean-Application-2f-User-2f-NFC-2f-App


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/NFC04A1/nfc04a1.c \
C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/NFC04A1/nfc04a1_nfctag.c 

OBJS += \
./Drivers/BSP/NFC04A1/nfc04a1.o \
./Drivers/BSP/NFC04A1/nfc04a1_nfctag.o 

C_DEPS += \
./Drivers/BSP/NFC04A1/nfc04a1.d \
./Drivers/BSP/NFC04A1/nfc04a1_nfctag.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/NFC04A1/nfc04a1.o: C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/NFC04A1/nfc04a1.c Drivers/BSP/NFC04A1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../NFC/App -I../../NFC/Target -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ST25DV -I../../Drivers/BSP/NFC04A1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/BSP/NFC04A1/nfc04a1.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/NFC04A1/nfc04a1_nfctag.o: C:/Users/federico/Documents/Borse\ di\ Ricerca/gennaio-dicembre\ 2023/git/Digimat_NFC_TX2/Drivers/BSP/NFC04A1/nfc04a1_nfctag.c Drivers/BSP/NFC04A1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../../NFC/App -I../../NFC/Target -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/Components/ST25DV -I../../Drivers/BSP/NFC04A1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/BSP/NFC04A1/nfc04a1_nfctag.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-NFC04A1

clean-Drivers-2f-BSP-2f-NFC04A1:
	-$(RM) ./Drivers/BSP/NFC04A1/nfc04a1.cyclo ./Drivers/BSP/NFC04A1/nfc04a1.d ./Drivers/BSP/NFC04A1/nfc04a1.o ./Drivers/BSP/NFC04A1/nfc04a1.su ./Drivers/BSP/NFC04A1/nfc04a1_nfctag.cyclo ./Drivers/BSP/NFC04A1/nfc04a1_nfctag.d ./Drivers/BSP/NFC04A1/nfc04a1_nfctag.o ./Drivers/BSP/NFC04A1/nfc04a1_nfctag.su

.PHONY: clean-Drivers-2f-BSP-2f-NFC04A1


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/ST/BlueNRG-MS/utils/subdir.mk
-include Middlewares/ST/BlueNRG-MS/hci/hci_tl_patterns/Basic/subdir.mk
-include Middlewares/ST/BlueNRG-MS/hci/controller/subdir.mk
-include Middlewares/ST/BlueNRG-MS/hci/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32F4xx_Nucleo/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include BlueNRG_MS/Target/subdir.mk
-include BlueNRG_MS/App/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := NFC_BLE_Tx
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
NFC_BLE_Tx.elf \

MAP_FILES += \
NFC_BLE_Tx.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NFC_BLE_Tx.list \


# All Target
all: main-build

# Main-build Target
main-build: NFC_BLE_Tx.elf secondary-outputs

# Tool invocations
NFC_BLE_Tx.elf NFC_BLE_Tx.map: $(OBJS) $(USER_OBJS) C:\Users\federico\Documents\Borse\ di\ Ricerca\gennaio-dicembre\ 2023\git\NFC_BLE_Tx\STM32F401RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "NFC_BLE_Tx.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\federico\Documents\Borse di Ricerca\gennaio-dicembre 2023\git\NFC_BLE_Tx\STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NFC_BLE_Tx.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NFC_BLE_Tx.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NFC_BLE_Tx.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) NFC_BLE_Tx.elf NFC_BLE_Tx.list NFC_BLE_Tx.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

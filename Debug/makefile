################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ioLibrary_Driver-master/Internet/FTPServer/subdir.mk
-include ioLibrary_Driver-master/Ethernet/W5500/subdir.mk
-include ioLibrary_Driver-master/Ethernet/W5300/subdir.mk
-include ioLibrary_Driver-master/Ethernet/W5200/subdir.mk
-include ioLibrary_Driver-master/Ethernet/W5100S/subdir.mk
-include ioLibrary_Driver-master/Ethernet/W5100/subdir.mk
-include ioLibrary_Driver-master/Ethernet/subdir.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32G4xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/STM32G4xx_Nucleo/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := FTP_SD_STM32G4
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FTP_SD_STM32G4.elf \

MAP_FILES += \
FTP_SD_STM32G4.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FTP_SD_STM32G4.list \


# All Target
all: main-build

# Main-build Target
main-build: FTP_SD_STM32G4.elf secondary-outputs

# Tool invocations
FTP_SD_STM32G4.elf FTP_SD_STM32G4.map: $(OBJS) $(USER_OBJS) C:\Users\pc\Documents\STM32_Pruebas\FTP_SD_STM32G4\STM32G474RETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "FTP_SD_STM32G4.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\pc\Documents\STM32_Pruebas\FTP_SD_STM32G4\STM32G474RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FTP_SD_STM32G4.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FTP_SD_STM32G4.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FTP_SD_STM32G4.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) FTP_SD_STM32G4.elf FTP_SD_STM32G4.list FTP_SD_STM32G4.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

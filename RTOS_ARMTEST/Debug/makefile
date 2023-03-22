################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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


BUILD_ARTIFACT_NAME := ARTOS_ARMTEST
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ARTOS_ARMTEST.elf \

MAP_FILES += \
ARTOS_ARMTEST.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARTOS_ARMTEST.list \

OBJCOPY_HEX += \
ARTOS_ARMTEST.hex \


# All Target
all: main-build

# Main-build Target
main-build: ARTOS_ARMTEST.elf secondary-outputs

# Tool invocations
ARTOS_ARMTEST.elf ARTOS_ARMTEST.map: $(OBJS) $(USER_OBJS) F:\communication\ engineering\embedded\ system\nti\ARM\ARM\ EX\ARTOS_ARMTEST\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ARTOS_ARMTEST.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"F:\communication engineering\embedded system\nti\ARM\ARM EX\ARTOS_ARMTEST\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARTOS_ARMTEST.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ARTOS_ARMTEST.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARTOS_ARMTEST.list"
	@echo 'Finished building: $@'
	@echo ' '

ARTOS_ARMTEST.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "ARTOS_ARMTEST.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ARTOS_ARMTEST.elf ARTOS_ARMTEST.hex ARTOS_ARMTEST.list ARTOS_ARMTEST.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

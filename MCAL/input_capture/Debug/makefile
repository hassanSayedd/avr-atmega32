################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
input_capture.lss \

FLASH_IMAGE += \
input_capture.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: input_capture.elf secondary-outputs

# Tool invocations
input_capture.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,input_capture.map -mmcu=atmega32 -o "input_capture.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

input_capture.lss: input_capture.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S input_capture.elf  >"input_capture.lss"
	@echo 'Finished building: $@'
	@echo ' '

input_capture.hex: input_capture.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex input_capture.elf  "input_capture.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: input_capture.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 input_capture.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) input_capture.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

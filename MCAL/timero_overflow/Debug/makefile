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
timero_overflow.lss \

FLASH_IMAGE += \
timero_overflow.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: timero_overflow.elf secondary-outputs

# Tool invocations
timero_overflow.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,timero_overflow.map -mmcu=atmega32 -o "timero_overflow.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

timero_overflow.lss: timero_overflow.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S timero_overflow.elf  >"timero_overflow.lss"
	@echo 'Finished building: $@'
	@echo ' '

timero_overflow.hex: timero_overflow.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex timero_overflow.elf  "timero_overflow.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: timero_overflow.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 timero_overflow.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) timero_overflow.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

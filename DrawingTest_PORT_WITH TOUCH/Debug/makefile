################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L5xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
RUT_LCD_TOUCH_DEMO.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
RUT_LCD_TOUCH_DEMO.list \

OBJCOPY_BIN += \
RUT_LCD_TOUCH_DEMO.bin \


# All Target
all: RUT_LCD_TOUCH_DEMO.elf secondary-outputs

# Tool invocations
RUT_LCD_TOUCH_DEMO.elf: $(OBJS) $(USER_OBJS) C:\Users\IUS\Documents\PROJECTS\RUT_LCD_FW\DrawingTest_PORT_WITH\ TOUCH\STM32L562ZETXQ_FLASH.ld
	arm-none-eabi-gcc -o "RUT_LCD_TOUCH_DEMO.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"C:\Users\IUS\Documents\PROJECTS\RUT_LCD_FW\DrawingTest_PORT_WITH TOUCH\STM32L562ZETXQ_FLASH.ld" -Wl,-Map="RUT_LCD_TOUCH_DEMO.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

RUT_LCD_TOUCH_DEMO.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "RUT_LCD_TOUCH_DEMO.list"
	@echo 'Finished building: $@'
	@echo ' '

RUT_LCD_TOUCH_DEMO.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "RUT_LCD_TOUCH_DEMO.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

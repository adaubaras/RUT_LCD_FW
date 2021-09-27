################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/0.c \
../Core/Src/16.c \
../Core/Src/19.c \
../Core/Src/20.c \
../Core/Src/21.c \
../Core/Src/22.c \
../Core/Src/24.c \
../Core/Src/25.c \
../Core/Src/26.c \
../Core/Src/CY8CMBR3xxx_APIs.c \
../Core/Src/CY8CMBR3xxx_CRC.c \
../Core/Src/CY8CMBR3xxx_HostFunctions.c \
../Core/Src/gui.c \
../Core/Src/ili9341.c \
../Core/Src/logo-rutronik-big.c \
../Core/Src/logo-rutronik.c \
../Core/Src/logo_320_240_24bit.c \
../Core/Src/main.c \
../Core/Src/r24_desktop.c \
../Core/Src/rgb.c \
../Core/Src/stm32l5xx_hal_msp.c \
../Core/Src/stm32l5xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l5xx.c 

OBJS += \
./Core/Src/0.o \
./Core/Src/16.o \
./Core/Src/19.o \
./Core/Src/20.o \
./Core/Src/21.o \
./Core/Src/22.o \
./Core/Src/24.o \
./Core/Src/25.o \
./Core/Src/26.o \
./Core/Src/CY8CMBR3xxx_APIs.o \
./Core/Src/CY8CMBR3xxx_CRC.o \
./Core/Src/CY8CMBR3xxx_HostFunctions.o \
./Core/Src/gui.o \
./Core/Src/ili9341.o \
./Core/Src/logo-rutronik-big.o \
./Core/Src/logo-rutronik.o \
./Core/Src/logo_320_240_24bit.o \
./Core/Src/main.o \
./Core/Src/r24_desktop.o \
./Core/Src/rgb.o \
./Core/Src/stm32l5xx_hal_msp.o \
./Core/Src/stm32l5xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l5xx.o 

C_DEPS += \
./Core/Src/0.d \
./Core/Src/16.d \
./Core/Src/19.d \
./Core/Src/20.d \
./Core/Src/21.d \
./Core/Src/22.d \
./Core/Src/24.d \
./Core/Src/25.d \
./Core/Src/26.d \
./Core/Src/CY8CMBR3xxx_APIs.d \
./Core/Src/CY8CMBR3xxx_CRC.d \
./Core/Src/CY8CMBR3xxx_HostFunctions.d \
./Core/Src/gui.d \
./Core/Src/ili9341.d \
./Core/Src/logo-rutronik-big.d \
./Core/Src/logo-rutronik.d \
./Core/Src/logo_320_240_24bit.d \
./Core/Src/main.d \
./Core/Src/r24_desktop.d \
./Core/Src/rgb.d \
./Core/Src/stm32l5xx_hal_msp.d \
./Core/Src/stm32l5xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l5xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/0.o: ../Core/Src/0.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/0.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/16.o: ../Core/Src/16.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/16.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/19.o: ../Core/Src/19.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/19.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/20.o: ../Core/Src/20.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/20.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/21.o: ../Core/Src/21.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/21.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/22.o: ../Core/Src/22.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/22.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/24.o: ../Core/Src/24.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/24.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/25.o: ../Core/Src/25.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/25.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/26.o: ../Core/Src/26.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/26.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/CY8CMBR3xxx_APIs.o: ../Core/Src/CY8CMBR3xxx_APIs.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/CY8CMBR3xxx_APIs.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/CY8CMBR3xxx_CRC.o: ../Core/Src/CY8CMBR3xxx_CRC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/CY8CMBR3xxx_CRC.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/CY8CMBR3xxx_HostFunctions.o: ../Core/Src/CY8CMBR3xxx_HostFunctions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/CY8CMBR3xxx_HostFunctions.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/gui.o: ../Core/Src/gui.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/gui.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/ili9341.o: ../Core/Src/ili9341.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/ili9341.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/logo-rutronik-big.o: ../Core/Src/logo-rutronik-big.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/logo-rutronik-big.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/logo-rutronik.o: ../Core/Src/logo-rutronik.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/logo-rutronik.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/logo_320_240_24bit.o: ../Core/Src/logo_320_240_24bit.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/logo_320_240_24bit.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/r24_desktop.o: ../Core/Src/r24_desktop.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/r24_desktop.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/rgb.o: ../Core/Src/rgb.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/rgb.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32l5xx_hal_msp.o: ../Core/Src/stm32l5xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32l5xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/stm32l5xx_it.o: ../Core/Src/stm32l5xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32l5xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/system_stm32l5xx.o: ../Core/Src/system_stm32l5xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L562xx -DDEBUG -c -I../TouchGFX/target/generated -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32L5xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../TouchGFX/App -I../TouchGFX/target -I../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32l5xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


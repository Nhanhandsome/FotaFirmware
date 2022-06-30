################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/FlashFirmwareApp/Service/debug.c \
../Core/FlashFirmwareApp/Service/fota_struct.c \
../Core/FlashFirmwareApp/Service/intelhex.c \
../Core/FlashFirmwareApp/Service/ringbuffer.c \
../Core/FlashFirmwareApp/Service/utils.c 

OBJS += \
./Core/FlashFirmwareApp/Service/debug.o \
./Core/FlashFirmwareApp/Service/fota_struct.o \
./Core/FlashFirmwareApp/Service/intelhex.o \
./Core/FlashFirmwareApp/Service/ringbuffer.o \
./Core/FlashFirmwareApp/Service/utils.o 

C_DEPS += \
./Core/FlashFirmwareApp/Service/debug.d \
./Core/FlashFirmwareApp/Service/fota_struct.d \
./Core/FlashFirmwareApp/Service/intelhex.d \
./Core/FlashFirmwareApp/Service/ringbuffer.d \
./Core/FlashFirmwareApp/Service/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/FlashFirmwareApp/Service/%.o Core/FlashFirmwareApp/Service/%.su: ../Core/FlashFirmwareApp/Service/%.c Core/FlashFirmwareApp/Service/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F051x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Admin/STM32CubeIDE/workspace_1.9.0/FlashFirmware/FlashFirmware/Core/FlashFirmwareApp/Service" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.9.0/FlashFirmware/FlashFirmware/Core/FlashFirmwareApp/HAL" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.9.0/FlashFirmware/FlashFirmware/Core/FlashFirmwareApp/Component" -I"C:/Users/Admin/STM32CubeIDE/workspace_1.9.0/FlashFirmware/FlashFirmware/Core/FlashFirmwareApp/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-FlashFirmwareApp-2f-Service

clean-Core-2f-FlashFirmwareApp-2f-Service:
	-$(RM) ./Core/FlashFirmwareApp/Service/debug.d ./Core/FlashFirmwareApp/Service/debug.o ./Core/FlashFirmwareApp/Service/debug.su ./Core/FlashFirmwareApp/Service/fota_struct.d ./Core/FlashFirmwareApp/Service/fota_struct.o ./Core/FlashFirmwareApp/Service/fota_struct.su ./Core/FlashFirmwareApp/Service/intelhex.d ./Core/FlashFirmwareApp/Service/intelhex.o ./Core/FlashFirmwareApp/Service/intelhex.su ./Core/FlashFirmwareApp/Service/ringbuffer.d ./Core/FlashFirmwareApp/Service/ringbuffer.o ./Core/FlashFirmwareApp/Service/ringbuffer.su ./Core/FlashFirmwareApp/Service/utils.d ./Core/FlashFirmwareApp/Service/utils.o ./Core/FlashFirmwareApp/Service/utils.su

.PHONY: clean-Core-2f-FlashFirmwareApp-2f-Service


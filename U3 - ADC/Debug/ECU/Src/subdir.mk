################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU/Src/DWT_Delay.c \
../ECU/Src/LCD16x2.c \
../ECU/Src/LCD16x2_cfg.c 

OBJS += \
./ECU/Src/DWT_Delay.o \
./ECU/Src/LCD16x2.o \
./ECU/Src/LCD16x2_cfg.o 

C_DEPS += \
./ECU/Src/DWT_Delay.d \
./ECU/Src/LCD16x2.d \
./ECU/Src/LCD16x2_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
ECU/Src/%.o ECU/Src/%.su ECU/Src/%.cyclo: ../ECU/Src/%.c ECU/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../ECU/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ECU-2f-Src

clean-ECU-2f-Src:
	-$(RM) ./ECU/Src/DWT_Delay.cyclo ./ECU/Src/DWT_Delay.d ./ECU/Src/DWT_Delay.o ./ECU/Src/DWT_Delay.su ./ECU/Src/LCD16x2.cyclo ./ECU/Src/LCD16x2.d ./ECU/Src/LCD16x2.o ./ECU/Src/LCD16x2.su ./ECU/Src/LCD16x2_cfg.cyclo ./ECU/Src/LCD16x2_cfg.d ./ECU/Src/LCD16x2_cfg.o ./ECU/Src/LCD16x2_cfg.su

.PHONY: clean-ECU-2f-Src


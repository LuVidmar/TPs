################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitives/Src/DWT_Delay.c \
../Primitives/Src/LCD16x2.c \
../Primitives/Src/LCD16x2_cfg.c 

OBJS += \
./Primitives/Src/DWT_Delay.o \
./Primitives/Src/LCD16x2.o \
./Primitives/Src/LCD16x2_cfg.o 

C_DEPS += \
./Primitives/Src/DWT_Delay.d \
./Primitives/Src/LCD16x2.d \
./Primitives/Src/LCD16x2_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Primitives/Src/%.o Primitives/Src/%.su Primitives/Src/%.cyclo: ../Primitives/Src/%.c Primitives/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Primitives/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Primitives-2f-Src

clean-Primitives-2f-Src:
	-$(RM) ./Primitives/Src/DWT_Delay.cyclo ./Primitives/Src/DWT_Delay.d ./Primitives/Src/DWT_Delay.o ./Primitives/Src/DWT_Delay.su ./Primitives/Src/LCD16x2.cyclo ./Primitives/Src/LCD16x2.d ./Primitives/Src/LCD16x2.o ./Primitives/Src/LCD16x2.su ./Primitives/Src/LCD16x2_cfg.cyclo ./Primitives/Src/LCD16x2_cfg.d ./Primitives/Src/LCD16x2_cfg.o ./Primitives/Src/LCD16x2_cfg.su

.PHONY: clean-Primitives-2f-Src


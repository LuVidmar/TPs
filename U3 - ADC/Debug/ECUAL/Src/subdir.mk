################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Src/DWT_Delay.c \
../ECUAL/Src/LCD16x2.c \
../ECUAL/Src/LCD16x2_cfg.c 

OBJS += \
./ECUAL/Src/DWT_Delay.o \
./ECUAL/Src/LCD16x2.o \
./ECUAL/Src/LCD16x2_cfg.o 

C_DEPS += \
./ECUAL/Src/DWT_Delay.d \
./ECUAL/Src/LCD16x2.d \
./ECUAL/Src/LCD16x2_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Src/%.o ECUAL/Src/%.su ECUAL/Src/%.cyclo: ../ECUAL/Src/%.c ECUAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../ECUAL/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ECUAL-2f-Src

clean-ECUAL-2f-Src:
	-$(RM) ./ECUAL/Src/DWT_Delay.cyclo ./ECUAL/Src/DWT_Delay.d ./ECUAL/Src/DWT_Delay.o ./ECUAL/Src/DWT_Delay.su ./ECUAL/Src/LCD16x2.cyclo ./ECUAL/Src/LCD16x2.d ./ECUAL/Src/LCD16x2.o ./ECUAL/Src/LCD16x2.su ./ECUAL/Src/LCD16x2_cfg.cyclo ./ECUAL/Src/LCD16x2_cfg.d ./ECUAL/Src/LCD16x2_cfg.o ./ECUAL/Src/LCD16x2_cfg.su

.PHONY: clean-ECUAL-2f-Src


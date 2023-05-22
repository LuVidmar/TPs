################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primites/Src/DWT_Delay.c \
../Primites/Src/LCD16x2.c \
../Primites/Src/LCD16x2_cfg.c 

OBJS += \
./Primites/Src/DWT_Delay.o \
./Primites/Src/LCD16x2.o \
./Primites/Src/LCD16x2_cfg.o 

C_DEPS += \
./Primites/Src/DWT_Delay.d \
./Primites/Src/LCD16x2.d \
./Primites/Src/LCD16x2_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Primites/Src/%.o Primites/Src/%.su Primites/Src/%.cyclo: ../Primites/Src/%.c Primites/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../TP1/Primites/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Primites-2f-Src

clean-Primites-2f-Src:
	-$(RM) ./Primites/Src/DWT_Delay.cyclo ./Primites/Src/DWT_Delay.d ./Primites/Src/DWT_Delay.o ./Primites/Src/DWT_Delay.su ./Primites/Src/LCD16x2.cyclo ./Primites/Src/LCD16x2.d ./Primites/Src/LCD16x2.o ./Primites/Src/LCD16x2.su ./Primites/Src/LCD16x2_cfg.cyclo ./Primites/Src/LCD16x2_cfg.d ./Primites/Src/LCD16x2_cfg.o ./Primites/Src/LCD16x2_cfg.su

.PHONY: clean-Primites-2f-Src


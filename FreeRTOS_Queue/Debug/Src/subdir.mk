################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/spi.c \
../Src/syscalls.c 

OBJS += \
./Src/main.o \
./Src/spi.o \
./Src/syscalls.o 

C_DEPS += \
./Src/main.d \
./Src/spi.d \
./Src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32G070RBTx -DSTM32 -DSTM32G0 -c -I"C:/Users/HP/STM32CubeIDE/Chip_Headers/CMSIS/Device/ST/STM32G0xx/Include" -I"C:/Users/HP/STM32CubeIDE/workspace_2.0.0/FreeRTOS_Queue/ThirdParty/FreeRTOS" -I"C:/Users/HP/STM32CubeIDE/workspace_2.0.0/FreeRTOS_Queue/ThirdParty/FreeRTOS/include" -I"C:/Users/HP/STM32CubeIDE/workspace_2.0.0/FreeRTOS_Queue/ThirdParty/FreeRTOS/portable/GCC/ARM_CM0" -I"C:/Users/HP/STM32CubeIDE/Chip_Headers/CMSIS/Include" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/spi.cyclo ./Src/spi.d ./Src/spi.o ./Src/spi.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su

.PHONY: clean-Src


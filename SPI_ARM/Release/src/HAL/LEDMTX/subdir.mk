################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/HAL/LEDMTX/LEDMTX_cfg.c \
../src/HAL/LEDMTX/LEDMTX_prg.c 

OBJS += \
./src/HAL/LEDMTX/LEDMTX_cfg.o \
./src/HAL/LEDMTX/LEDMTX_prg.o 

C_DEPS += \
./src/HAL/LEDMTX/LEDMTX_cfg.d \
./src/HAL/LEDMTX/LEDMTX_prg.d 


# Each subdirectory must supply rules for building sources it contributes
src/HAL/LEDMTX/%.o: ../src/HAL/LEDMTX/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DNDEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=18000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



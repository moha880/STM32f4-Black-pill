################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/_initialize_hardware.c \
../src/croutine.c \
../src/event_groups.c \
../src/heap_4.c \
../src/list.c \
../src/main.c \
../src/port.c \
../src/queue.c \
../src/stm32f4xx_hal_msp.c \
../src/stream_buffer.c \
../src/tasks.c \
../src/timers.c 

OBJS += \
./src/_initialize_hardware.o \
./src/croutine.o \
./src/event_groups.o \
./src/heap_4.o \
./src/list.o \
./src/main.o \
./src/port.o \
./src/queue.o \
./src/stm32f4xx_hal_msp.o \
./src/stream_buffer.o \
./src/tasks.o \
./src/timers.o 

C_DEPS += \
./src/_initialize_hardware.d \
./src/croutine.d \
./src/event_groups.d \
./src/heap_4.d \
./src/list.d \
./src/main.d \
./src/port.d \
./src/queue.d \
./src/stm32f4xx_hal_msp.d \
./src/stream_buffer.d \
./src/tasks.d \
./src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DNDEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DrawLine.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/extint.c \
../src/ssp.c 

OBJS += \
./src/DrawLine.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/extint.o \
./src/ssp.o 

C_DEPS += \
./src/DrawLine.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/extint.d \
./src/ssp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC17xx -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Gnanadeep\Documents\MCUXpressoIDE_10.1.1_606\workspace\CMSIS_CORE_LPC17xx\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



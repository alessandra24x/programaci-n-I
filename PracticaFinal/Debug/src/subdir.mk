################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/Parser.c \
../src/main.c \
../src/utn.c \
../src/vendedor.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/Parser.o \
./src/main.o \
./src/utn.o \
./src/vendedor.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/Parser.d \
./src/main.d \
./src/utn.d \
./src/vendedor.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



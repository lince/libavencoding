################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/test1.cpp \
../test/test2.cpp \
../test/test3.cpp \
../test/test4.cpp \
../test/test5.cpp \
../test/test6.cpp \
../test/test7.cpp \
../test/test8.cpp 

OBJS += \
./test/test1.o \
./test/test2.o \
./test/test3.o \
./test/test4.o \
./test/test5.o \
./test/test6.o \
./test/test7.o \
./test/test8.o 

CPP_DEPS += \
./test/test1.d \
./test/test2.d \
./test/test3.d \
./test/test4.d \
./test/test5.d \
./test/test6.d \
./test/test7.d \
./test/test8.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/java/include -I/opt/java/include/linux -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



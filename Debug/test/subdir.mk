################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/screenshotTest.cpp \
../test/test1.cpp \
../test/test2.cpp \
../test/test3.cpp \
../test/test4.cpp \
../test/test7.cpp \
../test/test8.cpp \
../test/videoFileToFileTest.cpp 

OBJS += \
./test/screenshotTest.o \
./test/test1.o \
./test/test2.o \
./test/test3.o \
./test/test4.o \
./test/test7.o \
./test/test8.o \
./test/videoFileToFileTest.o 

CPP_DEPS += \
./test/screenshotTest.d \
./test/test1.d \
./test/test2.d \
./test/test3.d \
./test/test4.d \
./test/test7.d \
./test/test8.d \
./test/videoFileToFileTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



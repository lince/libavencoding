################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AVEncoder.cpp \
../src/AVInputFile.cpp \
../src/AVOutputFile.cpp \
../src/AVSource.cpp \
../src/DeviceInterface.cpp \
../src/ImageShotter.cpp \
../src/RTPStream.cpp \
../src/SharedBuffer.cpp \
../src/Streaming.cpp \
../src/UDPMpegTS.cpp \
../src/X11Terminal.cpp 

OBJS += \
./src/AVEncoder.o \
./src/AVInputFile.o \
./src/AVOutputFile.o \
./src/AVSource.o \
./src/DeviceInterface.o \
./src/ImageShotter.o \
./src/RTPStream.o \
./src/SharedBuffer.o \
./src/Streaming.o \
./src/UDPMpegTS.o \
./src/X11Terminal.o 

CPP_DEPS += \
./src/AVEncoder.d \
./src/AVInputFile.d \
./src/AVOutputFile.d \
./src/AVSource.d \
./src/DeviceInterface.d \
./src/ImageShotter.d \
./src/RTPStream.d \
./src/SharedBuffer.d \
./src/Streaming.d \
./src/UDPMpegTS.d \
./src/X11Terminal.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/java/include -I/opt/java/include/linux -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bindings/java/AVEncoder.cpp \
../bindings/java/AVInputFile.cpp \
../bindings/java/AVOutputFile.cpp \
../bindings/java/ImageShotter.cpp \
../bindings/java/RTPStream.cpp \
../bindings/java/SharedBuffer.cpp \
../bindings/java/UDPMpegTS.cpp \
../bindings/java/X11Terminal.cpp 

OBJS += \
./bindings/java/AVEncoder.o \
./bindings/java/AVInputFile.o \
./bindings/java/AVOutputFile.o \
./bindings/java/ImageShotter.o \
./bindings/java/RTPStream.o \
./bindings/java/SharedBuffer.o \
./bindings/java/UDPMpegTS.o \
./bindings/java/X11Terminal.o 

CPP_DEPS += \
./bindings/java/AVEncoder.d \
./bindings/java/AVInputFile.d \
./bindings/java/AVOutputFile.d \
./bindings/java/ImageShotter.d \
./bindings/java/RTPStream.d \
./bindings/java/SharedBuffer.d \
./bindings/java/UDPMpegTS.d \
./bindings/java/X11Terminal.d 


# Each subdirectory must supply rules for building sources it contributes
bindings/java/%.o: ../bindings/java/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



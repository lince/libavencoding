################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/audioCaptureTest.cpp \
../test/audioFileToFileTest.cpp \
../test/captureCamAndMicTest.cpp \
../test/fileshotTest.cpp \
../test/muxingVideoAndAudioTest.cpp \
../test/screenshotTest.cpp \
../test/streamingRtpScreenTest.cpp \
../test/streamingUDPTest.cpp \
../test/videoFileToFileTest.cpp 

OBJS += \
./test/audioCaptureTest.o \
./test/audioFileToFileTest.o \
./test/captureCamAndMicTest.o \
./test/fileshotTest.o \
./test/muxingVideoAndAudioTest.o \
./test/screenshotTest.o \
./test/streamingRtpScreenTest.o \
./test/streamingUDPTest.o \
./test/videoFileToFileTest.o 

CPP_DEPS += \
./test/audioCaptureTest.d \
./test/audioFileToFileTest.d \
./test/captureCamAndMicTest.d \
./test/fileshotTest.d \
./test/muxingVideoAndAudioTest.d \
./test/screenshotTest.d \
./test/streamingRtpScreenTest.d \
./test/streamingUDPTest.d \
./test/videoFileToFileTest.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



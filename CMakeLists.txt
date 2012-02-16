CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libavencoding)

SET(BUILD_SHARED_LIBS ON)
SET(CMAKE_BUILD_TYPE DEBUG)

IF(CMAKE_COMPILER_IS_GNUCXX)
	SET(CMAKE_CXX_FLAGS_DEBUG  "-g3")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

SET(CMAKE_CXX_FLAGS "-DTIXML_USE_TICPP")
SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined -fPIC")

ADD_LIBRARY(avencoding 
		src/AlsaDevice.cpp
		src/AspectRatio.cpp
		src/AudioCodec.cpp
		src/AVContainer.cpp
		src/AVEncoder.cpp
		src/AVInputFile.cpp
		src/AVOutputFile.cpp
		src/AVSource.cpp
		src/DeviceInterface.cpp
		src/ImageFormat.cpp
		src/ImageShotter.cpp
		src/RTPStream.cpp
		src/SharedBuffer.cpp
		src/Streaming.cpp
		src/UDPMpegTS.cpp
		src/V4L2Device.cpp
		src/VideoCodec.cpp
		src/WowzaUDPInput.cpp
		src/X11Terminal.cpp)
			
SET(install_headers
		include/AlsaDevice.h
		include/AspectRatio.h
		include/AudioCodec.h
		include/AVContainer.h
		include/AVEncoder.h
		include/AVInputFile.h
		include/AVOutputFile.h
		include/AVSource.h
		include/DeviceException.h
		include/DeviceInterface.h
		include/ImageFormat.h
		include/ImageShotter.h
		include/RTPStream.h
		include/SharedBuffer.h
		include/Streaming.h
		include/Transcoder.h
		include/TranscodingException.h
		include/UDPMpegTS.h
		include/V4L2Device.h
		include/VideoCodec.h
		include/WowzaUDPInput.h
		include/X11Terminal.h)
			

			
TARGET_LINK_LIBRARIES (avencoding ffmpeg cpputil X11)

LINK_DIRECTORIES (${libavencoding_BINARY_DIR})

INCLUDE_DIRECTORIES (${libavencoding_SOURCE_DIR}/include)

ADD_EXECUTABLE(audioCaptureTest test/audioCaptureTest.cpp)
TARGET_LINK_LIBRARIES (audioCaptureTest avencoding)

ADD_EXECUTABLE(audioFileToFileTest test/audioFileToFileTest.cpp)
TARGET_LINK_LIBRARIES (audioFileToFileTest avencoding)

ADD_EXECUTABLE(captureCamAndMicTest test/captureCamAndMicTest.cpp)
TARGET_LINK_LIBRARIES (captureCamAndMicTest avencoding)

ADD_EXECUTABLE(fileshotTest test/fileshotTest.cpp)
TARGET_LINK_LIBRARIES (fileshotTest avencoding)

ADD_EXECUTABLE(muxingVideoAndAudioTest test/muxingVideoAndAudioTest.cpp)
TARGET_LINK_LIBRARIES (muxingVideoAndAudioTest avencoding)

ADD_EXECUTABLE(screenshotTest test/screenshotTest.cpp)
TARGET_LINK_LIBRARIES (screenshotTest avencoding)

ADD_EXECUTABLE(streamingRtpScreenTest test/streamingRtpScreenTest.cpp)
TARGET_LINK_LIBRARIES (streamingRtpScreenTest avencoding)

ADD_EXECUTABLE(streamingUDPTest test/streamingUDPTest.cpp)
TARGET_LINK_LIBRARIES (streamingUDPTest avencoding)

ADD_EXECUTABLE(videoFileToFileTest test/videoFileToFileTest.cpp)
TARGET_LINK_LIBRARIES (videoFileToFileTest avencoding)



INSTALL (TARGETS avencoding LIBRARY DESTINATION lib)

# INSTALL (TARGETS avencoding ARCHIVE DESTINATION lib)

INSTALL (FILES ${install_headers} DESTINATION include/libavencoding)
CC=g++
HEADES_DIR= /usr/local/include/libavencoding
LIB_DIR= /usr/local/lib

INCLUDES=	include/AVEncoder.h \
			include/AVInputFile.h \
			include/AVOutputFile.h \
			include/AVSource.h \
			include/DeviceInterface.h \
			include/ImageShotter.h \
			include/RTPStream.h \
			include/SharedBuffer.h \
			include/Streaming.h \
			include/Transcoder.h \
			include/UDPMpegTS.h \
			include/X11Terminal.h \
			include/WowzaUDPInput.h \
			include/DeviceException.h \
			include/V4L2Device.h \
			include/AlsaDevice.h
			
SOURCES=	src/AVEncoder.cpp \
			src/AVInputFile.cpp \
			src/AVOutputFile.cpp \
			src/AVSource.cpp \
			src/ImageShotter.cpp \
			src/RTPStream.cpp \
			src/SharedBuffer.cpp \
			src/Streaming.cpp \
			src/UDPMpegTS.cpp \
			src/X11Terminal.cpp \
			src/WowzaUDPInput.cpp \
			src/V4L2Device.cpp \
			src/AlsaDevice.cpp \
			src/DeviceInterface.cpp
			
LIBS= 		-lffmpeg -lcpputil -lX11



ALL: libavencoding.so

libavencoding.so: $(INCLUDES) $(SOURCES)
	$(CC) $(SOURCES) $(LIBS) \
		-shared -o libavencoding.so -g
	
clean:
	rm -f libavencoding.so
		
install: libavencoding.so
	install -d $(HEADES_DIR)
	install -t $(HEADES_DIR) $(INCLUDES)
	install -t $(LIB_DIR) libavencoding.so
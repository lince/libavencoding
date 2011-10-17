CC=g++
HEADES_DIR= /usr/local/include/streaming
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
			src/DeviceInterface.cpp \
			src/ImageShotter.cpp \
			src/RTPStream.cpp \
			src/SharedBuffer.cpp \
			src/Streaming.cpp \
			src/UDPMpegTS.cpp \
			src/X11Terminal.cpp \
			src/WowzaUDPInput.cpp \
			src/DeviceException.cpp \
			src/V4L2Device.cpp \
			src/AlsaDevice.cpp
			
LIBS= 		-lffmpeg -lcpputil -lX11



ALL: libstreaming.so

libstreaming.so: $(INCLUDES) $(SOURCES)
	$(CC) $(SOURCES) $(LIBS) \
		-shared -fPIC -o libstreaming.so -g
	
clean:
	rm -f libstreaming.so
		
install: libstreaming.so
	install -d $(HEADES_DIR)
	install -t $(HEADES_DIR) $(INCLUDES)
	install -t $(LIB_DIR) libstreaming.so
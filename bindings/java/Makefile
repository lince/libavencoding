CC=gcc

INCLUDES= 	br_ufscar_lince_streaming_AVEncoder.h \
			br_ufscar_lince_streaming_RTPStream.h \
			br_ufscar_lince_streaming_X11Terminal.h \
			br_ufscar_lince_streaming_SharedBuffer.h \
			br_ufscar_lince_streaming_AVInputFile.h \
			br_ufscar_lince_streaming_AVOutputFile.h \
			br_ufscar_lince_streaming_ImageShotter.h \
			br_ufscar_lince_streaming_UDPMpegTS.h
			
SOURCES=	RTPStream.cpp \
			X11Terminal.cpp \
			AVEncoder.cpp \
			SharedBuffer.cpp \
			AVInputFile.cpp \
			UDPMpegTS.cpp \
			AVOutputFile.cpp \
			ImageShotter.cpp
			
ALL: libstreamingjava.so

libstreamingjava.so: $(SOURCES) $(INCLUDES)
	g++ -o libstreamingjava.so -shared $(SOURCES) \
		-I/opt/java/include/ -I/opt/java/include/linux/ -I../../include -L../../ \
		-lstreaming
		
clean:
	rm libstreamingjava.so
	
install:
	cp libstreamingjava.so /usr/local/lib

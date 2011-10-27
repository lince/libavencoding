CC=g++

PROGRAMS= \
		streamingRtpScreenTest videoFileToFileTest screenshotTest muxingVideoAndAudioTest \
		streamingUDPTest audioFileToFileTest fileshotTest captureCamAndMicTest

TAGS= -L.. -lavenconding -g -O0

ALL: $(PROGRAMS)

streamingRtpScreenTest: streamingRtpScreenTest.cpp
	$(CC) streamingRtpScreenTest.cpp -o streamingRtpScreenTest $(TAGS)
	
muxingVideoAndAudioTest: muxingVideoAndAudioTest.cpp
	$(CC) muxingVideoAndAudioTest.cpp -o muxingVideoAndAudioTest $(TAGS)
	
streamingUDPTest: streamingUDPTest.cpp
	$(CC) streamingUDPTest.cpp -o streamingUDPTest $(TAGS)
	
audioFileToFileTest: audioFileToFileTest.cpp
	$(CC) audioFileToFileTest.cpp -o audioFileToFileTest $(TAGS)
	
videoFileToFileTest: videoFileToFileTest.cpp
	$(CC) videoFileToFileTest.cpp -o videoFileToFileTest $(TAGS)
	
screenshotTest: screenshotTest.cpp
	$(CC) screenshotTest.cpp -o screenshotTest -lcpputil $(TAGS)
	
fileshotTest: fileshotTest.cpp
	$(CC) fileshotTest.cpp -o fileshotTest $(TAGS)
	
captureCamAndMicTest: captureCamAndMicTest.cpp
	$(CC) captureCamAndMicTest.cpp -o captureCamAndMicTest $(TAGS)
	
clean:
	rm -f $(PROGRAMS)
	


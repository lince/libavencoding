/*
 * videoFileToFileTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program transcodes the content of file called "videosample.mp4" into a new file, using the
 * video codec H264 and audio codec AAC, generating a new file called "newfile.mp4".
 * It resizes the video to 400x400 during the transcode process.
 */
#include "AVInputFile.h"
#include "AVEncoder.h"
#include "AVOutputFile.h"

using namespace ::br::ufscar::lince::avencoding;

#include <iostream>
#include <cstdlib>
using namespace std;

class ExceptionHandler : public cpputil::ThreadExceptionListener {
public:
	void catchExceptionOnThread(cpputil::SimpleException& ex) throw() {
		cout << ex.what();
		exit(1);
	}
};

int main(int argc, char** argv) {
	ExceptionHandler* handler = new ExceptionHandler();

	AVSource* videoInput = new AVInputFile("videosample.mp4", AVContainer::MP4);

	AVEncoder* videoEnc = new AVEncoder(videoInput);
	videoEnc->setVideoCodec(VideoCodec::VP8);
	videoEnc->setVideoBitrate(15000);

	AVEncoder* audioEnc = new AVEncoder(videoInput);
	audioEnc->setAudioCodec(AudioCodec::VORBIS);

	AVOutputFile* videoOutput = new AVOutputFile("newfile.webm", AVContainer::WEBM, true);
	videoOutput->addStream(videoEnc);
	videoOutput->addStream(audioEnc);
	videoOutput->setExceptionListener(handler);
	videoOutput->start();

	videoOutput->waitFinishing();
	return 0;
}

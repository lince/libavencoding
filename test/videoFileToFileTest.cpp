/**
 * File: videoFileToFileTest.cpp
 * Created by: Caio César Viel
 * Contact: caioviel@gmail.com
 * Last Modification: 02-16-2012
 *
 * Copyright (c) 2012 LINCE-UFSCar
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * -------------------------------------------------------------------------------------------------
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
	videoEnc->setVideoCodec(VideoCodec::H264);
	videoEnc->setVideoBitrate(15000);

	AVEncoder* audioEnc = new AVEncoder(videoInput);
	audioEnc->setAudioCodec(AudioCodec::AC3);

	AVOutputFile* videoOutput = new AVOutputFile("video.mkv", AVContainer::MKV, true);
	videoOutput->addStream(videoEnc);
	videoOutput->addStream(audioEnc);
	videoOutput->setExceptionListener(handler);
	videoOutput->start();

	videoOutput->waitFinishing();
	return 0;
}

/**
 * File: audioCaptureTest.cpp
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
 * This program transcodes the content of a audio file called "audiosample.acc" into a new file, using the
 * audio codec libmp3lame, generating a new file called "newaudio.mp3".
 */

#include <libcpputil/logger/LoggerManager.h>
using namespace cpputil::logger;

#include "AlsaDevice.h"
#include "X11Terminal.h"
#include "AVEncoder.h"
#include "AVOutputFile.h"
#include "AVInputFile.h"
using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	LoggerManager* lm = LoggerManager::getInstance();
	lm->readConfigurationFile("config.xml");

	/*X11Terminal* alsa = new X11Terminal(25);
	//alsa->setChannelsNumber(1);*/

	AlsaDevice* alsa = new AlsaDevice(0,0);

	AVEncoder* audioEnc = new AVEncoder(alsa);
	audioEnc->setAudioCodec(AudioCodec::MP3);

	AVOutputFile* mp3File = new AVOutputFile("capturedAudio0.mp3");
	mp3File->addStream(audioEnc);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();

	mp3File = new AVOutputFile("capturedAudio1.mp3");
	mp3File->addStream(audioEnc);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();

	mp3File = new AVOutputFile("capturedAudio2.mp3");
	mp3File->addStream(audioEnc);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();

	return 0;
}

/**
 * File: captureCamAndMicTest.cpp
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
 * This program captures the camera 0 and alsa mic 0:0 for 10 seconds and generates
 * a file named "outputfile1.mp4" with the grabbed content.
 * It uses the video codec H264 and the audio codec AAC.
 */

#include "X11Terminal.h"
#include "AlsaDevice.h"
#include "AVEncoder.h"
#include "AVOutputFile.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	AVSource* x11Device = new X11Terminal(1280, 1024, 25);
	AVSource* alsaDevice = new AlsaDevice(0, 0);

	AVEncoder* encoderVid = new AVEncoder(x11Device);
	encoderVid->setVideoCodec(VideoCodec::H264);
	encoderVid->setVideoPreset("baseline");
	encoderVid->setPropertyValue("crf", "22");

	AVEncoder* encoderAud = new AVEncoder(alsaDevice);
	encoderAud->setAudioCodec(AudioCodec::AAC);
	encoderAud->setAudioBitrate(192);

	AVOutputFile* ofile = new AVOutputFile("outputfile1.mp4", AVContainer::MP4);
	ofile->addStream(encoderVid);
	ofile->addStream(encoderAud);
	ofile->start();

	sleep(10);
	ofile->stop();
	ofile->waitFinishing();

	return 0;
}

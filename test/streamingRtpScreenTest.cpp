/**
 * File: streamingRtpScreenTest.cpp
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
 * This program capture the content of X11 (screen) and transcodes it using the video codec H264 for 10 seconds.
 * The trancoded video is them streaming using RTP protocol to the localhost on port 5004.
 */

#include "X11Terminal.h"
#include "AVEncoder.h"
#include "RTPStream.h"

#include <string>

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	AVSource* device = new X11Terminal(1280, 1024, 25);

	AVEncoder* encoderVid = new AVEncoder(device);
	encoderVid->setVideoCodec(VideoCodec::H264);
	encoderVid->setVideoPreset("ipod320");
	encoderVid->setPropertyValue("crf", "22");


	Streaming* streammer = new RTPStream("127.0.0.1", 5004);
	streammer->addStream(encoderVid);
	streammer->start();

	sleep(10);

	streammer->stop();
	streammer->waitFinishing();

	return 0;
}

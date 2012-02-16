/**
 * File: streamingUDPTest.cpp
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
 * This transcode the content of the file "videosample.mp4", encapsules it in Mpeg-TS
 * and streams it using the UDP protocol to localhost on port 1234.
 * It uses the video codec MPEG2Video and the audio codec AAC.
 */

#include "AVInputFile.h"
#include "AVEncoder.h"
#include "UDPMpegTS.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {

	AVSource* avfile = new AVInputFile("videosample.mp4", AVContainer::MP4);

	AVEncoder* encoderVid = new AVEncoder(avfile, 0);
	encoderVid->setVideoCodec(VideoCodec::MPEG2);

	AVEncoder* encoderAud = new AVEncoder(avfile, 1);
	encoderAud->setAudioCodec(AudioCodec::AAC);

	Streaming* streammer = new UDPMpegTS("127.0.0.1", 1234);
	streammer->addStream(encoderVid);
	streammer->addStream(encoderAud);
	streammer->start();

	streammer->waitFinishing();

	return 0;
}

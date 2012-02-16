/**
 * File: muxingVideoAndAudioTest.cpp
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
 * This program join the video content from the file "videosample.mp4" with
 * the audio content of the file "audiosample.acc", creating a new
 * file called "outputfile.mp4".
 * It uses the video codec H264 and audio codec AAC.
 */

#include "AVOutputFile.h"
#include "AVInputFile.h"
#include "AVEncoder.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	AVSource* vfile = new AVInputFile("videosample.mp4", AVContainer::MP4);
	AVSource* afile = new AVInputFile("audiosample.aac", AVContainer::AAC);

	AVEncoder* encoderVid = new AVEncoder(vfile);
	encoderVid->setVideoCodec(VideoCodec::H264);
	encoderVid->setVideoPreset("ipod320");
	encoderVid->setPropertyValue("crf", "22");

	AVEncoder* encoderAud = new AVEncoder(afile);
	encoderAud->setAudioCodec(AudioCodec::AAC);

	AVOutputFile* outFile = new AVOutputFile("outputfile.mp4");
	outFile->addStream(encoderVid);
	outFile->addStream(encoderAud);
	outFile->start();

	outFile->waitFinishing();

	return 0;
}

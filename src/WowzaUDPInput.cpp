/**
 * File: WowzaUDPInput.cpp
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
 */

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
using namespace cpputil;

#include "WowzaUDPInput.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::WowzaUDPInput"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

WowzaUDPInput::WowzaUDPInput(string ip, int port) : Streaming(),
		logger::Loggable(CLASS_NAME){

	trace("begin constructor");

	this->ip = ip;
	this->port = port;
	source = NULL;
	encoder = NULL;
	FFMpeg_init(5);
}

WowzaUDPInput::~WowzaUDPInput() {
	trace("begin destrcutor");

	if (source) {
		delete source;
	}
	if (encoder) {
		delete encoder;
	}
}

void WowzaUDPInput::addStream(AVEncoder *stream) {
	trace("begin addStream(AVEncoder*)");

	source = stream->getSource();
	encoder = stream;
}

void WowzaUDPInput::run() {
	trace("begin run()");

	configure(source, (void*)NULL);
	configure(encoder, (void*)NULL);

	if (FFMpeg_setVideoPreset((char*)"baseline") != FFMpeg_SUCCESS) {
		error("Error trying to set video preset as baseline.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_setOther((char*)"g", (char*)"60") != FFMpeg_SUCCESS) {
		error("Error trying to set property g as 60.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_setVideoBitrate((char*)"150000")!= FFMpeg_SUCCESS) {
		error("Error trying to set video bitrate as 150000.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_setFormat((char*)"mpegts") != FFMpeg_SUCCESS) {
		error("Error trying to set format as mpegts.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_setVideoBitstreamFilter((char*)"h264_mp4toannexb") != FFMpeg_SUCCESS) {
		error("Error trying to set video bitstream filter as h264_mp4toannexb.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	string outputfile = "udp://" + ip + ":" +
			Functions::numberToString(port) + "?pkt_size=1316";

	debug("UDP output file name: " + outputfile);

	if (FFMpeg_setOutputFile((char*) outputfile.c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set UDP output file: " + outputfile);
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_transcode() != FFMpeg_SUCCESS) {
		error("Error during transcode process.");
		throw TranscodingException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	FFMpeg_reset(__LINE__);
	finished = true;
	Thread::unlockConditionSatisfied();
}



void WowzaUDPInput::stop() {
	trace("stop");

	if (!started) {
		throw new cpputil::InitializationException(
				"Transconding Process haven't started yet",
				CLASS_NAME,
				"stop()");
	}
	FFMpeg_stop();
}

}
}
}
}

/*
 ffmpeg -s 400  -re -vcodec libx264
 -vpre default -vpre baseline -g 60
 -vb 150000 -strict experimental -acodec aac
 -ab 128000 -ar 48000 -ac 2 -vbsf h264_mp4toannexb
 -f mpegts udp://200.18.98.27:10000?pkt_size=1316
*/

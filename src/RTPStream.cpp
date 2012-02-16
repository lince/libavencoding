/**
 * File: RTPStream.cpp
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

#include "RTPStream.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::RTPStream"


namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

RTPStream::RTPStream(string ip, int port) : Streaming(),
		logger::Loggable(CLASS_NAME) {

	trace("begin constructor");

	this->ip = ip;
	this->port = port;
	this->output = NULL;
	FFMpeg_init(5);
}

RTPStream::~RTPStream() {
	trace("begin destructor()");

}

void RTPStream::addStream(AVEncoder *stream) {
	trace("begin addStream(AVEncoder* ");

	if (!output) {
		this->output = stream;
	} else {
		throw InitializationException(
				"Trying to set a second stream to a RTPStream",
				CLASS_NAME,
				"addStream(AVEncoder* )");
	}
}


inline void RTPStream::run() {
	trace("begin run()");

	AVSource* source = output->getSource();
	configure(source, (void*)NULL);
	configure(output, (void*)NULL);

	if (FFMpeg_setFormat((char*) "rtp") != FFMpeg_SUCCESS) {
		error("Error trying to set format rtp");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}
	string outputfile = "rtp://" + ip + ":" + Functions::numberToString(port);
	debug("RTP output file name: " + outputfile);

	if (FFMpeg_setOutputFile((char*) outputfile.c_str()) ) {
		error("Error trying to set rtp output file: " + outputfile);
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

void RTPStream::stop() {
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

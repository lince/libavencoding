/**
 * File: UDPMpegTS.cpp
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

#include "UDPMpegTS.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::UDPMpegTS"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

UDPMpegTS::UDPMpegTS(string ip, int port) : Streaming(),
		logger::Loggable(CLASS_NAME ){

	trace("begin constructor");

	this->ip = ip;
	this->port = port;
	sources = new vector<AVSource*>();
	encoders = new 	vector<AVEncoder*>();
	FFMpeg_init(5);
}

UDPMpegTS::~UDPMpegTS() {
	trace("begin destructor");

	vector<AVSource*>::iterator it;
	for (it = sources->begin(); it != sources->end(); it++) {
		AVSource* source = *it;
		delete source;
	}
	delete sources;

	vector<AVEncoder*>::iterator it2;
	for (it2 = encoders->begin(); it2 != encoders->end(); it2++) {
		AVEncoder* encoder = *it2;
		delete encoder;
	}
	delete encoders;
}

void UDPMpegTS::addStream(AVEncoder *stream) {
	trace("begin addStream(AVEncoder* ");

	//TODO: Check stream.

	sources->push_back(stream->getSource());
	encoders->push_back(stream);
}

void UDPMpegTS::run() {
	vector<AVSource*>::iterator it;
	map<AVSource*, string> sourcesById;
	map<AVSource*, int> sourcesByStream;
	int idCount = 0;
	for (it = sources->begin(); it != sources->end(); it++) {
		AVSource* source = *it;
		map<AVSource*, string>::iterator itMap;
		itMap = sourcesById.find(source);
		if (itMap == sourcesById.end()) {
			sourcesById[source] = Functions::numberToString(idCount++);
			sourcesByStream[source] = 0;
			configure(source, (void*) NULL);
		}
	}

	vector<AVEncoder*>::iterator it2;
	for (it2 = encoders->begin(); it2 != encoders->end(); it2++) {
		AVEncoder* encoder = *it2;
		configure(encoder, (void*) NULL);
	}

	for (int i=0; i < sources->size(); i++) {
		string fileId = sourcesById[sources->at(i)];
		int stream = encoders->at(i)->getStreamId();
		if (stream == -1) {
			stream = sourcesByStream[sources->at(i)]++;
		}
		string streamId = Functions::numberToString(stream);

		string mapOpp = fileId + "." + streamId;
		cout << mapOpp << endl;
		if (FFMpeg_setMap((char*) mapOpp.c_str()) != FFMpeg_SUCCESS) {
			error("Error trying to map the i/o streams.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}
	}

	if (FFMpeg_setFormat((char*) "mpegts") != FFMpeg_SUCCESS) {
		error("Error trying the format mpegts.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	string outputfile = "udp://" + ip + ":" + Functions::numberToString(port);
	debug("UDP output file name: " + outputfile);

	if (FFMpeg_setOutputFile((char*) outputfile.c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set the UDP output file: " + outputfile);
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



void UDPMpegTS::stop() {
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

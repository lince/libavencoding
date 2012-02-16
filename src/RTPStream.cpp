/*
 * RTPStream.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
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

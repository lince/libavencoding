/*
 * RTPStream.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */
#include <sstream>
#include <iostream>
#include <string.h>

using namespace std;

#include <libcpputil/Functions.h>
using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

#include "../include/RTPStream.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

RTPStream::RTPStream(string ip, int port) : Streaming() {
	this->ip = ip;
	this->port = port;
	this->output = NULL;
	FFMpeg_init(1);
}

RTPStream::~RTPStream() {

}

void RTPStream::addStream(AVEncoder *stream) {
	if (!output) {
		this->output = stream;
	} else {
		throw InitializationException(
				"void RTPStream::addStream(AVEncoder *stream)\n"
				"Trying to set a second stream to a RTPStream",
				"br::ufscar::lince::RTPStream",
				"addStream(AVEncoder* )");
	}
}


inline void RTPStream::run() {
	AVSource* source = output->getSource();
	configure(source, (void*)NULL);
	configure(output, (void*)NULL);

	/*if (output->getVideoCodec() != NONE) {
		ffrapper->setEnableAudio(false);
	} else {
		//TODO desabilita o video
	}*/

	FFMpeg_setFormat((char*) "rtp");
	string outputfile = "rtp://" + ip + ":" + Functions::numberToString(port);
	FFMpeg_setOutputFile((char*) outputfile.c_str());
	FFMpeg_transcode();
	FFMpeg_reset(__LINE__);
	finished = true;
	Thread::unlockConditionSatisfied();
}

void RTPStream::stop() {
	FFMpeg_stop();
}

}
}
}
}

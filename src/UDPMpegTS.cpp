/*
 * UDPMpegTS.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libcpputil/Functions.h>
using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

#include <iostream>
using namespace std;

#include "../include/UDPMpegTS.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

UDPMpegTS::UDPMpegTS(string ip, int port) : Streaming() {
	this->ip = ip;
	this->port = port;
	sources = new vector<AVSource*>();
	encoders = new 	vector<AVEncoder*>();
	FFMpeg_init(5);
}

UDPMpegTS::~UDPMpegTS() {
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
		FFMpeg_setMap((char*) mapOpp.c_str());
	}

	FFMpeg_setFormat((char*) "mpegts");
	string outputfile = "udp://" + ip + ":" + Functions::numberToString(port);
	FFMpeg_setOutputFile((char*) outputfile.c_str());
	FFMpeg_transcode();
	FFMpeg_reset(__LINE__);
	finished = true;
	Thread::unlockConditionSatisfied();
}



void UDPMpegTS::stop() {
	FFMpeg_stop();
}

}
}
}
}

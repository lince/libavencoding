/*
 * AVOutoutFile.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libffmpeg/libffmpeg.h>

#include <cpputil/Functions.h>
using namespace cpputil;

#include <iostream>
using namespace std;

#include "../include/AVOutputFile.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

AVOutputFile::AVOutputFile(string filename, string format, bool fileOverwrite) : Transcoder() {
	finished = false;
	started = false;
	this->filename = filename;
	this->format = format;
	this->fileOverwrite = fileOverwrite;
	sources = new vector<AVSource*>();
	encoders = new vector<AVEncoder*>();
	FFMpeg_init(5);
}

AVOutputFile::~AVOutputFile() {
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

void AVOutputFile::run() {
	vector<AVSource*>::iterator it;
	for (it = sources->begin(); it != sources->end(); it++) {
		AVSource* source = *it;
		configure(source, (void*) NULL);
	}

	vector<AVEncoder*>::iterator it2;
	for (it2 = encoders->begin(); it2 != encoders->end(); it2++) {
		AVEncoder* encoder = *it2;
		configure(encoder, (void*) NULL);
	}

	for (int i=0; i < sources->size(); i++) {
		string mapOpp = Functions::numberToString(i);
		mapOpp += "." + Functions::numberToString(i);
		//mapOpp += ":0";
		FFMpeg_setMap((char*) mapOpp.c_str());
	}

	if (fileOverwrite) {
		FFMpeg_setOverwriteFile(1);
	}

	if (format != "") {
		FFMpeg_setFormat((char*) format.c_str());
	}

	if (FFMpeg_setOutputFile((char*) filename.c_str())
			!= FFMpeg_SUCCESS) {

		cerr << FFMpeg_getErrorStr() << endl;
		return;
	}

	if (FFMpeg_transcode() != FFMpeg_SUCCESS) {
		cerr << FFMpeg_getErrorStr() << endl;
	}


	FFMpeg_reset(__LINE__);
	finished = true;
	Thread::unlockConditionSatisfied();
}

void AVOutputFile::stop() {
	FFMpeg_stop();
}

void AVOutputFile::addStream(AVEncoder *stream) {
	//TODO: Tratamento para verificar se stream adicionados estão coerentes
	sources->push_back(stream->getSource());
	encoders->push_back(stream);
}

string AVOutputFile::getFilename() {
	return filename;
}

bool AVOutputFile::isFinished() {
	return finished;
}

void AVOutputFile::waitFinishing() {
	if (!started) {
		throw new InitializationException(
				"Transconding Process haven't started yet",
				"br::ufscar::lince::streaming::AVOutputFile",
				"waitFinishing()");
	}
	Thread::waitForUnlockCondition();
}

void AVOutputFile::start() {
	started = true;
	finished = false;
	Thread::start();
}

}
}
}
}

/*
 * AVOutoutFile.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libffmpeg/libffmpeg.h>
#include <libcpputil/Functions.h>
using namespace cpputil;

#include "AVOutputFile.h"
using namespace std;

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

AVOutputFile::AVOutputFile(string filename, AVContainer container, bool fileOverwrite)
		: Transcoder(), Thread(), Loggable("br::ufscar::lince::avencoding::AVOutputFile") {

	trace("begin constructor");

	finished = false;
	started = false;
	this->filename = filename;
	this->container = container;
	this->fileOverwrite = fileOverwrite;
	sources = new vector<AVSource*>();
	encoders = new vector<AVEncoder*>();
	FFMpeg_init(5);
}

AVOutputFile::~AVOutputFile() {
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

void AVOutputFile::run() {
	trace("begin run()");

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
		if (FFMpeg_setMap((char*) mapOpp.c_str()) != FFMpeg_SUCCESS) {
			error("Error trying to map the i/o streams.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					"br::ufscar::lince::avencoding::AVOutputFile",
					"run()");
		}
	}

	if (fileOverwrite) {
		if (FFMpeg_setOverwriteFile(1) != FFMpeg_SUCCESS) {
			error("Error trying to set the overwrite file option.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					"br::ufscar::lince::avencoding::AVOutputFile",
					"run()");
		}
	}

	if (container != AVContainer::NONE) {
		std::string format = Functions::toLowerCase(container.toString());
		if (FFMpeg_setFormat((char*) format.c_str()) != FFMpeg_SUCCESS) {
			error("Error trying to set output file format: " + format);
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					"br::ufscar::lince::avencoding::AVOutputFile",
					"run()");
		}
	}

	if (FFMpeg_setOutputFile((char*) filename.c_str())
			!= FFMpeg_SUCCESS) {

		error("Error trying to set output file name: " + filename);
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVOutputFile",
				"run()");
	}

	if (FFMpeg_transcode() != FFMpeg_SUCCESS) {
		error("Error during transcode process.");
		throw TranscodingException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVOutputFile",
				"run()");
	}

	FFMpeg_reset(__LINE__);
	finished = true;
	Thread::unlockConditionSatisfied();
}

void AVOutputFile::stop() {
	trace("begin stop()");

	FFMpeg_stop();
}

void AVOutputFile::addStream(AVEncoder *stream) {
	trace("begin addStream(AVEncoder*)");

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
	trace("begin waitFinishing()");

	if (!started) {
		throw InitializationException(
				"Transconding Process haven't started yet",
				"br::ufscar::lince::avencoding::AVOutputFile",
				"waitFinishing()");
	}
	Thread::waitForUnlockCondition();
}

void AVOutputFile::start() {
	trace("begin start()");

	started = true;
	finished = false;
	Thread::start();
}


double AVOutputFile::getCurrentTime() {
	return FFMpeg_getTime();
}

AVContainer AVOutputFile::getContainer() {
	return container;
}

}
}
}
}

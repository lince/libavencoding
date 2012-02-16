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

#define CLASS_NAME "br::ufscar::lince::avencoding::AVOutputFile"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

AVOutputFile::AVOutputFile(string filename, AVContainer container, bool fileOverwrite)
		: Transcoder(), Thread(), Loggable(CLASS_NAME) {

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
					CLASS_NAME,
					"run()");
		}
	}

	if (fileOverwrite) {
		if (FFMpeg_setOverwriteFile(1) != FFMpeg_SUCCESS) {
			error("Error trying to set the overwrite file option.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}
	}

	if (container != AVContainer::NONE) {
		char* format = (char*) "";
		if (container == AVContainer::WEBM) {
			format = (char*) "webm\0";
		} else if (container == AVContainer::MP4) {
			format = (char*) "mp4\0";
		} else if (container == AVContainer::AVI) {
			format = (char*) "avi\0";
		}  else if (container == AVContainer::MPEG) {
			format = (char*) "mpeg\0";
		}  else if (container == AVContainer::OGG) {
			format = (char*) "ogg\0";
		}  else if (container == AVContainer::FLV) {
			format = (char*) "flv\0";
		}  else if (container == AVContainer::MKV) {
			format = (char*) "matroska\0";
		}  else if (container == AVContainer::MP3) {
			format = (char*) "mp3\0";
		}  else if (container == AVContainer::AAC) {
			format = (char*) "adts\0";
		}  else if (container == AVContainer::WAV) {
			format = (char*) "wav\0";
		} else if (container == AVContainer::OGA) {
			format = (char*) "ogg\0";
		} else if (container == AVContainer::FLA) {
			format = (char*) "flac\0";
		} else if (container == AVContainer::MKA) {
			format = (char*) "matroska\0";
		} else if (container == AVContainer::MOV) {
			format = (char*) "mov\0";
		} else if (container == AVContainer::AC3) {
			format = (char*) "ac3\0";
		}


		info((string)"Container Format: " + format);
		if (FFMpeg_setFormat(format) != FFMpeg_SUCCESS) {
			error((string)"Error trying to set output file format: " + format);
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}
	}

	if (FFMpeg_setOutputFile((char*) filename.c_str())
			!= FFMpeg_SUCCESS) {

		error("Error trying to set output file name: " + filename);
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

void AVOutputFile::stop() {
	trace("begin stop()");

	if (!started) {
		throw InitializationException(
				"Transconding Process haven't started yet",
				CLASS_NAME,
				"stop()");
	}

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
				"Transconding Process hasn't started yet",
				CLASS_NAME,
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

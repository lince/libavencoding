/*
 * AVInputFile.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 */

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
using namespace cpputil;

#include "AVInputFile.h"
using namespace std;

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

AVInputFile::AVInputFile(std::string filename, AVContainer container) :
		AVSource(Functions::toUpperCase(container.toString())),
		logger::Loggable("br::ufscar::lince::avencoding::AVInputFile") {

	trace("begin constructor");

	this->filename = filename;
	this->container = container;
}

std::string AVInputFile::getFilename() {
	return filename;
}

void AVInputFile::configure(void *ffrapper_) {
	trace("begin configure(void*)");
	/*if (configured) {
		return;
	}*/
	configured = true;

	string format = getFormat();
	if (format != "") {
		if (FFMpeg_setFormat( (char*) getFormat().c_str()) != FFMpeg_SUCCESS) {
			error("Error trying to set the format.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					"br::ufscar::lince::avencoding::AVInputFile",
					"configure(void*)");
		}
	} else {
		info("Trying to get the format by the file name");
	}

	if (FFMpeg_setInputFile( (char*) getFilename().c_str())
			!= FFMpeg_SUCCESS) {

		error("Error trying to set the input file name.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVInputFile",
				"configure(void*)");
	}

	if (startTime != -1) {
		info("Setting StartTime");
		if (FFMpeg_setStartTime1((char*) Functions::numberToString(startTime).c_str()) != FFMpeg_SUCCESS) {

			error("Error trying to set the input file start point.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					"br::ufscar::lince::avencoding::AVInputFile",
					"configure(void*)");

		}
	}

	if (durationTime != -1) {
		info("Setting DurationTime");
		if (FFMpeg_setRecordingTime1((char*) Functions::numberToString(durationTime).c_str()) != FFMpeg_SUCCESS) {
			error("Error trying to set the input file duration.");
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					"br::ufscar::lince::avencoding::AVInputFile",
					"configure(void*)");
		}
	}
}

AVInputFile::~AVInputFile() {
	trace("begin destructor");
}

AVContainer AVInputFile::getContainer() {
	return container;
}

}
}
}
}

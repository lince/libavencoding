/*
 * AVInputFile.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 */

#include <libffmpeg/libffmpeg.h>
#include "../include/AVInputFile.h"

#include <string>
using namespace std;

#include <libcpputil/IllegalParameterException.h>
using namespace cpputil;

#include <libcpputil/logger/Logger.h>
using namespace cpputil::logger;

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

AVInputFile::AVInputFile(std::string filename, std::string format) :
		AVSource(format), Loggable("br::ufscar::lince::avencoding::AVInputFile") {
	this->trace("begin constructor");

	this->filename = filename;
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

	if (FFMpeg_setFormat( (char*) getFormat().c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set the format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVInputFile",
				"configure(void*)");
	}

	if (FFMpeg_setInputFile( (char*) getFilename().c_str())
			!= FFMpeg_SUCCESS) {

		error("Error trying to set the output file name.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVInputFile",
				"configure(void*)");
	}
}

AVInputFile::~AVInputFile() {
	trace("begin destructor");
	this->unregister();
}

}
}
}
}

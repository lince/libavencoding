/**
 * File: AVInputFile.cpp
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


	if (container != AVContainer::NONE) {
		string format = getFormat();
		if (container == AVContainer::MKV) {
			format = "matroska\0";
		} else if (container == AVContainer::MPEG) {
			format = "mpeg\0";
		} else if (container == AVContainer::MOV) {
			format = "mov\0";
		} else if (container == AVContainer::OGA) {
			format = "ogg\0";
		} else if (container == AVContainer::MKA) {
			format = "matroska\0";
		} else if (container == AVContainer::FLA) {
			format = "flac\0";
		}

		if (FFMpeg_setFormat( (char*) format.c_str()) != FFMpeg_SUCCESS) {
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

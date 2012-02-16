/**
 * File: V4L2Device.cpp
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

#include "V4L2Device.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::V4L2Device"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

V4L2Device::V4L2Device(int deviceId, int fps) :
		AVSource("video4linux2"), logger::Loggable(CLASS_NAME) {

	trace("begin constructor");

	if (deviceId > 0) {
		deviceId = 0;
	}
	deviceName += "/dev/video" + Functions::numberToString(deviceId);
	this->fps = fps;
}


V4L2Device::V4L2Device(std::string path, int fps) :
		AVSource("video4linux2"), logger::Loggable(CLASS_NAME) {

	trace("begin constructor");
	this->deviceName = path;
	this->fps = fps;
}

V4L2Device::~V4L2Device() {
	trace("begin destructor");
}


int V4L2Device::getWidth() {
	throw NotImplementedException(
			"This functionality haven't been implemented yet.",
			CLASS_NAME,
			"getWidth()");
}


int V4L2Device::getHeight() {
	throw NotImplementedException(
			"This functionality haven't been implemented yet.",
			CLASS_NAME,
			"getHeight()");
}


int V4L2Device::getFps() {
	/*throw NotImplementedException(
			"This functionality haven't been implemented yet.",
			"br::ufscar::lince::streaming::V4L2Device",
			"getFps()");*/
	return fps;
}


std::string V4L2Device::getDeviceName() {
	return this->deviceName;
}

/* ffmpeg -f alsa -r 16000 -i hw:1,0 -f video4linux2
 * -s 800x600 -i /dev/video0 -r 30 -f avi -vcodec mpeg4 -vtag xvid -sameq -acodec mp2 -ab 96k output.avi
 */

void V4L2Device::configure(void* ffrapper) {
	configured = true;

	if (FFMpeg_setFormat((char*) "video4linux2") != FFMpeg_SUCCESS) {
		error("Error trying to set the format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");
	}

	if (FFMpeg_setFramerate((char*)
			Functions::numberToString(fps).c_str()) != FFMpeg_SUCCESS) {

		error("Error trying to set the framerate.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");

	}

	//FFMpeg_setFrameSize1(width, height);
	debug("VL42 Device:" + deviceName);
	if (FFMpeg_setInputFile((char*) deviceName.c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set the format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");
	}
}

}
}
}
}

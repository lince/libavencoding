/*
 * V4L2Device.cpp
 *
 *  Created on: Sep 27, 2011
 *      Author: caioviel
 */

#include "../include/V4L2Device.h"
using namespace std;

#include <libcpputil/NotImplementedException.h>
#include <libcpputil/IllegalParameterException.h>
#include <libcpputil/Functions.h>
using namespace cpputil;

#include <libcpputil/logger/Logger.h>
using namespace cpputil::logger;

#include <libffmpeg/libffmpeg.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

V4L2Device::V4L2Device(int deviceId, int fps) :
		AVSource("video4linux2"), Loggable("br::ufscar::lince::avencoding::V4L2Device") {

	trace("begin constructor");

	if (deviceId > 0) {
		deviceId = 0;
	}
	deviceName += "/dev/video" + Functions::numberToString(deviceId);
	this->fps = fps;
}


V4L2Device::V4L2Device(std::string path, int fps) :
		AVSource("video4linux2"), Loggable("br::ufscar::lince::avencoding::V4L2Device") {

	trace("begin constructor");
	this->deviceName = path;
	this->fps = fps;
}

V4L2Device::~V4L2Device() {
	trace("begin destructor");
	unregister();
}


int V4L2Device::getWidth() {
	throw NotImplementedException(
			"This functionality haven't been implemented yet.",
			"br::ufscar::lince::streaming::V4L2Device",
			"getWidth()");
}


int V4L2Device::getHeight() {
	throw NotImplementedException(
			"This functionality haven't been implemented yet.",
			"br::ufscar::lince::streaming::V4L2Device",
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
				"br::ufscar::lince::avenconding::AVInputFile",
				"configure(void*)");
	}

	if (FFMpeg_setFramerate((char*)
			Functions::numberToString(fps).c_str()) != FFMpeg_SUCCESS) {

		error("Error trying to set the framerate.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVInputFile",
				"configure(void*)");

	}

	//FFMpeg_setFrameSize1(width, height);
	debug("VL42 Device:" + deviceName);
	if (FFMpeg_setInputFile((char*) deviceName.c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set the format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AVInputFile",
				"configure(void*)");
	}
}

}
}
}
}

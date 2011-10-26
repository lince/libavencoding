/*
 * V4L2Device.cpp
 *
 *  Created on: Sep 27, 2011
 *      Author: caioviel
 */

#include "../include/V4L2Device.h"
using namespace std;

#include <cpputil/NotImplementedException.h>
#include <cpputil/Functions.h>
using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

V4L2Device::V4L2Device(int deviceId) : AVSource("video4linux2") {
	if (deviceId > 0) {
		deviceId = 0;
	}
	deviceName = "/dev/video";
	deviceName += Functions::numberToString(deviceId);
}


V4L2Device::V4L2Device(std::string path) : AVSource("video4linux2") {
	this->deviceName = path;
}

V4L2Device::~V4L2Device() {

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
	throw NotImplementedException(
			"This functionality haven't been implemented yet.",
			"br::ufscar::lince::streaming::V4L2Device",
			"getFps()");
}


std::string V4L2Device::getDeviceName() {
	return this->deviceName;
}

/* ffmpeg -f alsa -r 16000 -i hw:1,0 -f video4linux2
 * -s 800x600 -i /dev/video0 -r 30 -f avi -vcodec mpeg4 -vtag xvid -sameq -acodec mp2 -ab 96k output.avi
 */

void V4L2Device::configure(void* ffrapper) {
	configured = true;

	FFMpeg_setFormat((char*) "video4linux2");
	//FFMpeg_setFramerate((char*) Functions::numberToString(fps).c_str());
	//FFMpeg_setFrameSize1(width, height);
	FFMpeg_setInputFile((char*) deviceName.c_str());
}

}
}
}
}

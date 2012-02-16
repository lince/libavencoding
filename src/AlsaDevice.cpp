/**
 * File: AlsaDevice.cpp
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

#include "AlsaDevice.h"
using namespace cpputil::logger;
#define CLASS_NAME "br::ufscar::lince::avencoding::AlsaDevice"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

AlsaDevice::AlsaDevice(int cardId, int interfaceId, int captureRate) :
		AVSource("alsa"),  Loggable(CLASS_NAME) {

	trace("begin constructor");

	this->cardId = cardId;
	this->interfaceId = interfaceId;
	this->captureRate = captureRate;
	this->channelsNumber = 2;
}

AlsaDevice::~AlsaDevice() {
	trace("begin destructor");

}

int AlsaDevice::getCardId() {
	return cardId;
}

int AlsaDevice::getInterfaceId() {
	return interfaceId;
}

int AlsaDevice::getCaptureRate() {
	return captureRate;
}

void AlsaDevice::configure(void* ffrapper) {
	trace("begin configure(void*)");

	/*if (configured) {
		return;
	}
	configured = true;*/

	if (FFMpeg_setFormat((char*) "alsa") != FFMpeg_SUCCESS) {
		error("Error trying to set format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AlsaDevice",
				"configure(void*)");
	}

	if (FFMpeg_setAudioRate(captureRate) != FFMpeg_SUCCESS) {
		error("Error trying to set audio sample rate.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AlsaDevice",
				"configure(void*)");
	}

	if (FFMpeg_setAudioChannels(channelsNumber) != FFMpeg_SUCCESS) {
		error("Error trying to set audio channels number.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AlsaDevice",
				"configure(void*)");
	}

	std::string deviceName = "hw:";
	deviceName += Functions::numberToString(cardId);
	deviceName += ",";
	deviceName += Functions::numberToString(interfaceId);

	debug("Alsa Input: " + deviceName);
	if (FFMpeg_setInputFile((char*) deviceName.c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set the alsa device.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::AlsaDevice",
				"configure(void*)");
	}
}

void AlsaDevice::setChannelsNumber(int channelsNumber) {
	this->channelsNumber = channelsNumber;
}

int AlsaDevice::getChannelsNumber() {
	return this->channelsNumber;
}

}
}
}
}

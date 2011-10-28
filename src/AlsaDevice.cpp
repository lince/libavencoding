/*
 * AlsaDevice.cpp
 *
 *  Created on: Sep 28, 2011
 *      Author: caioviel
 */

#include "../include/AlsaDevice.h"

#include <libcpputil/Functions.h>
#include <libcpputil/IllegalParameterException.h>
using namespace cpputil;

#include <libcpputil/logger/Logger.h>
using namespace cpputil::logger;

#include <libffmpeg/libffmpeg.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

AlsaDevice::AlsaDevice(int cardId, int interfaceId, int captureRate) :
		AVSource("alsa"),  Loggable("br::ufscar::lince::avencoding::AlsaDevice") {

	trace("begin constructor");

	this->cardId = cardId;
	this->interfaceId = interfaceId;
	this->captureRate = captureRate;
}

AlsaDevice::~AlsaDevice() {
	trace("begin destructor");
	this->unregister();

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

}
}
}
}

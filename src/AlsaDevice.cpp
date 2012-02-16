/*
 * AlsaDevice.cpp
 *
 *  Created on: Sep 28, 2011
 *      Author: caioviel
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

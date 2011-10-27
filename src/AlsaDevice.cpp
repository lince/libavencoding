/*
 * AlsaDevice.cpp
 *
 *  Created on: Sep 27, 2011
 *      Author: caioviel
 */

#include "../include/AlsaDevice.h"

#include <libcpputil/Functions.h>
using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

AlsaDevice::AlsaDevice(int cardId, int interfaceId, int captureRate) : AVSource("alsa") {
	this->cardId = cardId;
	this->interfaceId = interfaceId;
	this->captureRate = captureRate;
}

AlsaDevice::~AlsaDevice() {

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
	FFMpeg_setFormat((char*) "alsa");
	//FFMpeg_setFramerate((char*) captureRate);
	//FFMpeg_setFrameSize1(width, height);
	/* hw:1,0 */
	string deviceName = "hw:";
	deviceName += Functions::numberToString(cardId);
	deviceName += ",";
	deviceName += Functions::numberToString(interfaceId);
	FFMpeg_setInputFile((char*) deviceName.c_str());
}

}
}
}
}

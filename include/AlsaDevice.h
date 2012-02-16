/**
 * File: AlsaDevice.h
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

#ifndef ALSADEVICE_H_
#define ALSADEVICE_H_

#include <string>

#include <libcpputil/logger/Logger.h>
#include <libcpputil/IllegalParameterException.h>

#include "AVSource.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * This class is used to grab audio data from Alsa compatible devices.
 * Which instance of AlsaDevice is bounded with a Alsa compatible device.
 * This bound is represented by the identification number of the card and
 * by the interface number.
 * It's necessary inform the capture rate of the audio and the number of channels.
 * Those values should be supported by the device, or it will result in errors.
 */
class AlsaDevice : public AVSource, public cpputil::logger::Loggable {
public:
	/**
	 * Constructor
	 * @param cardId The identification number of the device's card from.
	 * @param interfaceId The identification number of the interface.
	 * @param captureRate The frequency which the audio will be captured. Default 16000.
	 */
	AlsaDevice(int cardId, int interfaceId, int captureRate=16000);

	/**
	 * Destructor.
	 */
	virtual ~AlsaDevice();

	/**
	 * Return the identification number of the device's card bounded with this instance.
	 * @return identification number of the device's card.
	 */
	int getCardId();

	/**
	 * Return the identification number of the interface of the card from which the audio will be grab.
	 * @return identification number interface of the card.
	 */
	int getInterfaceId();

	/**
	 * Return a integer representing the audio's capture rate of this instance.
	 * @return audio's capture rate
	 */
	int getCaptureRate();

	/**
	 * This method allow the set the number of audio channels that will be by this instance.
	 * The default value is 2.
	 * @param channelsNumber The number of audio channels to be captured.
	 */
	void setChannelsNumber(int channelsNumber);

	/**
	 * Return the number of audio channels that will be captured by this instance.
	 * @return number of audio channels.
	 */
	int getChannelsNumber();

protected:
	/**
	 * This protected method is internally used to allow the Transcoder instance to configure
	 * the transcoding process with the parameters of this instance.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw IllegalParameterException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	int cardId;
	int interfaceId;
	int captureRate;
	int channelsNumber;
};

}
}
}
}

#endif /* ALSADEVICE_H_ */

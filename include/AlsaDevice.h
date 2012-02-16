/*
 * AlsaDevice.h
 *
 *  Created on: Sep 27, 2011
 *      Author: caioviel
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

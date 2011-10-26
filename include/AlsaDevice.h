/*
 * AlsaDevice.h
 *
 *  Created on: Sep 27, 2011
 *      Author: caioviel
 */

#ifndef ALSADEVICE_H_
#define ALSADEVICE_H_

#include "AVSource.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

class AlsaDevice : public AVSource {
public:
	AlsaDevice(int cardId, int interfaceId, int captureRate=16000);

	virtual ~AlsaDevice();

	int getCardId();

	int getInterfaceId();

	int getCaptureRate();

protected:
	/**
	 * This protected method is internally used to allow the X11Terminal's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	int cardId;
	int interfaceId;
	int captureRate;
};

}
}
}
}

#endif /* ALSADEVICE_H_ */

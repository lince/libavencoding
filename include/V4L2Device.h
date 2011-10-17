/*
 * V4L2Device.h
 *
 *  Created on: Sep 27, 2011
 *      Author: caioviel
 */

#ifndef V4L2DEVICE_H_
#define V4L2DEVICE_H_

#include "AVSource.h"

namespace br {
namespace ufscar {
namespace lince {
namespace streaming {

class V4L2Device : public AVSource {
public:
	/**
	 * Construtor.
	 * Uses the integer X informed as a parameter to open the video device /dev/videoX.
	 * Default value is 0, resulting in /dev/video0. If a negative parameter was informed,
	 * it will be assumed the 0 value.
	 * @param deviceId the id of the video device.
	 */
	V4L2Device(int deviceId=0);

	/**
	 * Construtor.
	 * @param path the path of the device to open.
	 */
	V4L2Device(std::string path);

	/**
	 * Virtual Destructor
	 */
	virtual ~V4L2Device();

	/**
	 * Return the screen width.
	 * @return screen width
	 */
	int getWidth();

	/**
	 * Return the screen height.
	 * @return screen height
	 */
	int getHeight();

	/**
	 * Return the screen frames per second frequency.
	 * @return frames per second.
	 */
	int getFps();

	/**
	 * Return the video device path
	 * @return A string with the device path
	 */
	std::string getDeviceName();

protected:
	/**
	 * This protected method is internally used to allow the X11Terminal's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	std::string deviceName;
};

}
}
}
}
#endif /* V4L2DEVICE_H_ */

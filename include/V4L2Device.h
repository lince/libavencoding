/**
 * File: V4L2Device.h
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

#ifndef V4L2DEVICE_H_
#define V4L2DEVICE_H_

//TODO: Obter informações sobre o device via api v4l2.
#include <libcpputil/logger/Logger.h>
#include <libcpputil/NotImplementedException.h>
#include <libcpputil/IllegalParameterException.h>

#include "AVSource.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {


/**
 * This class is used to grab video data from Video4Linux compatible devices.
 * Which instance of V4L2Device is bounded with a Video4Linux compatible device.
 * This bound is represented by the identification number of the device.
 */
class V4L2Device : public AVSource, public cpputil::logger::Loggable {
public:
	/**
	 * Construtor.
	 * Uses the integer X informed as a parameter to open the video device /dev/videoX.
	 * Default value is 0, resulting in /dev/video0. If a negative parameter was informed,
	 * it will be assumed the 0 value.
	 * @param deviceId the id of the video device.
	 */
	V4L2Device(int deviceId=0, int fps=24);

	/**
	 * Construtor.
	 * @param path the path of the device to open.
	 */
	V4L2Device(std::string path, int fps=24);

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
	 * This protected method is internally used to allow the V4L2Device instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw IllegalParameterException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	std::string deviceName;
	int fps;
};

}
}
}
}
#endif /* V4L2DEVICE_H_ */

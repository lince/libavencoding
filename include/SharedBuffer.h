/**
 * File: SharedBuffer.h
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

#ifndef SHAREDBUFFER_H_
#define SHAREDBUFFER_H_

#include <libcpputil/logger/Logger.h>
#include <libcpputil/IllegalParameterException.h>

#include "AVSource.h"
#include "DeviceInterface.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * This class represents a input device that used the Unix Shared Memory to generate images.
 * Using this AVSource, the transcoding process will utilize images in a
 * specific buffer in memory as a raw images to generate video.
 * An application that generate image and video must put its in a shared buffer, using the
 * DeviceInterface class.
 */
class SharedBuffer : public AVSource, public cpputil::logger::Loggable {
public:
	/**
	 * Construtor
	 */
	SharedBuffer();

	/**
	 * Virtual Destructor
	 */
	virtual ~SharedBuffer();

	/**
	 * Return the current width of the images in the buffer.
	 * @return width of the Images
	 */
	int getWidth();

	/**
	 * Return the current height of the images in the buffer.
	 * @return height of the Images
	 */
	int getHeight();

protected:
	/**
	 * This protected method is internally used to allow the SharedBuffer's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw IllegalParameterException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	DeviceInterface* device;

};

}
}
}
}

#endif /* SHAREDBUFFER_H_ */

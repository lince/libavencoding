/**
 * File: AVSource.h
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

#ifndef AVSOURCE_H
#define AVSOURCE_H

#include <string>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

class Transcoder;

/**
 * This abstract class represents a generic audio/video source.
 * The classes that represents a less-generic audio/video source
 * (such a device, a inputfile a network stream) should implement this class.
 */
class AVSource {

/**
 * This class is a friend of Transcoder because transcoder need to call the
 * configure AVSource's method to processed with the transcoding process.
 */
friend class Transcoder;

public:
	/**
	 * Format Construtor.
	 * Various audio/video sources can provide content in different formats, so it's important
	 * inform implicitly the used format.
	 * @param format the format of the audio/video of the source.
	 */
	AVSource(std::string format);

	/**
	 * Return the format of the audio/video of the source
	 * @return the format of the source.
	 */
	virtual std::string getFormat();

	/**
	 * Virtual Destroctor
	 */
	virtual ~AVSource() {};

	/**
	 * This method is used to explicit define the start point of the source in seconds..
	 * @param seconds The time of the start point of the source in seconds.
	 */
	void setStartTime(int seconds);

	/**
	 * This method is used to explicit define the duration of the source in seconds
	 * @param seconds The time of duration of the source in seconds.
	 */
	void setDurationTime(int seconds);

protected:
	/**
	 * This protected method is internally used to allow the AVSource's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw IllegalParameterException when parameters are wrong or invalids.
	 */
	virtual void configure(void* ffrapper)=0;

	bool configured;
	int startTime;
	int durationTime;
	std::string format;

};


}
}
}
}

#endif //AVSOURCE_H

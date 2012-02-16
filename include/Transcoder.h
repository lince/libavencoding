/**
 * File: Transcoder.h
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

#ifndef TRANSCODER_H_
#define TRANSCODER_H_

#include "AVEncoder.h"
#include "AVSource.h"
#include "TranscodingException.h"

namespace br{
namespace ufscar{
namespace lince {
namespace avencoding {

/**
 * Realize generic a transcoding process.
 *
 * This abstract class must be implemented by all the classes that realize a
 * transcoding process.
 */
class Transcoder {
public:

	/**
	 * Virtual Destructor.
	 */
	virtual ~Transcoder() {};

	/**
	 * This method returns true if the transcoding process is finished.
	 * It can be used to create a non-block program, that will not sleep until the coding
	 * is finished.
	 * @return True if the transcoding process is finished; false otherwise.
	 */
	virtual bool isFinished() = 0;

	/**
	 * This method waits until the transcoding process is finished.
	 * It can be used to create a block program, that will sleep until the coding is finished.
	 * @throw InitializationException when the transcoding process hasn't begun.
	 */
	virtual void waitFinishing() = 0;

	/**
	 * This method retorns the current time of the audio/video that is been captured.
	 * It only works in continuous media transcoder processes.
	 * @return The current time in seconds.
	 */
	virtual double getCurrentTime() = 0;

protected:
	/**
	 * This protected method is internally used to allow the classes configure the transcoding
	 * process with her parameters.
	 * The AVEncoders classes are friends of Transcoder, so he can call their protected method
	 * configure.
	 * @param enc the encoder parameters that will be configured.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw InitializationException when parameters are wrong or invalids.
	 */
	void configure(AVEncoder* enc, void* ffrapper) {
		enc->configure(ffrapper);
	}

	/**
	 * This protected method is internally used to allow the classes configure the transcoding
	 * process with her parameters.
	 * The AVSources classes are friends of Transcoder, so he can call their protected method
	 * configure.
	 * @param src the source parameters that will be configured.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw InitializationException when parameters are wrong or invalids.
	 */
	void configure(AVSource* src, void* ffrapper) {
		src->configure(ffrapper);
	}
};

}
}
}
}

#endif /* TRANSCODER_H_ */

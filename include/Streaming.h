/**
 * File: Streaming.h
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

#ifndef STREAMING_H_
#define STREAMING_H_

#include <libcpputil/Thread.h>
#include <libcpputil/InitializationException.h>
#include <libcpputil/IllegalParameterException.h>

#include "Transcoder.h"
#include "TranscodingException.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

/**
 * Streaming a audio/video stream encoded by some encoder.
 *
 * This abstract class must be implemented by all the classes that realize a
 * transcoding process and the output format is a network stream, like rpt, udp and etc.
 */
class Streaming : public cpputil::Thread, public Transcoder {
public:
	/**
	 * Construtor.
	 * Initialize the control variables.
	 */
	Streaming();

	/**
	 * Virtual Destructor.
	 */
	virtual ~Streaming() {};

	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * @param stream the audio-video stream.
	 */
	virtual void addStream(AVEncoder* stream)=0;

	/**
	 * Start the transcoding and streaming process.
	 * This method should be called after the streaming and transcoding process was defined.
	 * It creates a new theard that will process with the process.
	 * @throw InitializationException if no stream was add.
	 * @throw IllegalParameterException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 * @see addStream
	 */
	virtual void start();

	/**
	 * Abort the transcoding process.
	 * @throw InitializationException if the process hasn't begun.
	 */
	virtual void stop() = 0;

	virtual bool isFinished();

	virtual void waitFinishing();

	virtual double getCurrentTime();

protected:
	bool finished;
	bool started;

};


}
}
}
}

#endif //STREAMING_H_

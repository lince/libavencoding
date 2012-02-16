/**
 * File: RTPStream.h
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

#ifndef RTPSTREAM_H_
#define RTPSTREAM_H_

#include <libcpputil/InitializationException.h>
#include <libcpputil/logger/Loggable.h>
using namespace cpputil;

#include "Streaming.h"
#include "AVEncoder.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * This class is used to generate a RTP Stream of a audio/video coded of a source.
 * Only one audio/video stream can be send by a single RTP stream.
 */
class RTPStream : public Streaming, public cpputil::logger::Loggable {

public:
	/**
	 * Construtor
	 * @param ip The ip address of the destiny host.
	 * @param ip The port number of the destiny process.
	 */
	RTPStream(std::string ip, int port);

	/**
	 * Virtual Destructor
	 * It will delete all the AVSource and AVEncoder associated.
	 */
	virtual ~RTPStream();

	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * RTPStream just suport one audio/video stream.
	 * @throw InitializationException when try to add a second stream.
	 * @param stream the audio-video stream.
	 */
	void addStream(AVEncoder* stream);

	void stop();

private:
	void run();
	AVEncoder* output;
	std::string ip;
	int port;
};

}
}
}
}

#endif /* RTPSTREAM_H_ */

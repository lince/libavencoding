/*
 * RTPStream.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef RTPSTREAM_H_
#define RTPSTREAM_H_

#include <libcpputil/InitializationException.h>
using namespace cpputil;

#include "Streaming.h"
#include "AVEncoder.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

/**
 * This class is used to generate a RTP Stream of a audio/video coded of a source.
 * Only one audio/video stream can be send by a single RTP stream.
 */
class RTPStream : public Streaming {

public:
	/**
	 * Construtor
	 * @param ip The ip address of the destiny host.
	 * @param ip The port number of the destiny process.
	 */
	RTPStream(string ip, int port);

	/**
	 * Virtual Destructor
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

	/**
	 * Abort the transcoding process.
	 * @throw InitializationException if the process hasn't begun.
	 */
	void stop();

private:
	void run();
	AVEncoder* output;
	string ip;
	int port;
};

}
}
}
}

#endif /* RTPSTREAM_H_ */

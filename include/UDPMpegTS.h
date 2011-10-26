/*
 * UDPMpegTS.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef UDPMPEGTS_H_
#define UDPMPEGTS_H_

#include <cpputil/Functions.h>
using namespace cpputil;

#include "Streaming.h"

#include <vector>
#include <string>
using namespace std;

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

/**
 * This class is used to generate a MpegTS of several audio/video streams and streaming
 * this MpegTS using the UDP protocol.
 * Several different audio and video streams can be encapsulate in a MpegTS
 */
class UDPMpegTS : public Streaming {
public:
	/**
	 * Construtor
	 * @param ip The ip address of the destiny host.
	 * @param ip The port number of the destiny process.
	 */
	UDPMpegTS(string ip, int port);

	/**
	 * Virtual Destructor
	 */
	virtual ~UDPMpegTS();

	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
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
	vector<AVSource*>* sources;
	vector<AVEncoder*>* encoders;
	string ip;
	int port;
	void run();

};

}
}
}
}

#endif /* UDPMPEGTS_H_ */

/*
 * UDPMpegTS.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef UDPMPEGTS_H_
#define UDPMPEGTS_H_

#include <libcpputil/Functions.h>
#include <libcpputil/IllegalParameterException.h>
#include <libcpputil/logger/Loggable.h>
using namespace cpputil;

#include "Streaming.h"

#include <vector>
#include <string>
using namespace std;

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

/**
 * This class is used to generate a MpegTS of several audio/video streams and streaming
 * this MpegTS using the UDP protocol.
 * Several different audio and video streams can be encapsulate in a MpegTS
 */
class UDPMpegTS : public Streaming, public cpputil::logger::Loggable {
public:
	/**
	 * Construtor
	 * @param ip The ip address of the destiny host.
	 * @param ip The port number of the destiny process.
	 */
	UDPMpegTS(string ip, int port);

	/**
	 * Virtual Destructor
	 * It will delete all the AVSource and AVEncoder associated.
	 */
	virtual ~UDPMpegTS();

	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * @throw InitializationException when try to add invalid streams
	 * @param stream the audio-video stream.
	 */
	void addStream(AVEncoder* stream);

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

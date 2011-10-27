/*
 * WowzaUDPInput.h
 *
 *  Last Change: Nov 30, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef WOWZAUDPINPUT_H_
#define WOWZAUDPINPUT_H_

#include <libcpputil/Functions.h>
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
 * This class is used to generate a MpegTS of a audio and video stream addressed to the
 * wowza media server.
 */
class WowzaUDPInput : public Streaming {
public:
	/**
	 * Construtor
	 * @param ip The ip address of the wowza mediaserver.
	 * @param ip The port number of the wowza mediaserver.
	 */
	WowzaUDPInput(string ip, int port);

	/**
	 * Virtual Destructor
	 */
	virtual ~WowzaUDPInput();

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
	AVSource* source;
	AVEncoder* encoder;
	string ip;
	int port;
	void run();

};

}
}
}
}

#endif /* WOWZAUDPINPUT_H_ */

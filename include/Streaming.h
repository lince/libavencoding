/*
 * Streaming.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef STREAMING_H_
#define STREAMING_H_

#include <libcpputil/Thread.h>
#include <libcpputil/InitializationException.h>
using namespace cpputil;

#include "Transcoder.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

/**
 * Streaming a audio/video stream encoded by some encoder.
 *
 * This abstract class must be implemented by all the classes that realize a
 * transcoding process and the output format is a network stream, like rpt, udp and etc.
 */
class Streaming : public Thread, public Transcoder {
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
	 * @throw OptionException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 * @see addStream
	 */
	virtual void start();

	/**
	 * Abort the transcoding process.
	 * @throw InitializationException if the process hasn't begun.
	 */
	virtual void stop()=0;

	/**
	 * This method returns true if the transcoding process is finished.
	 * It can be used to create a non-block program, that will not sleep until the coding
	 * is finished.
	 * @return True if the transcoding process is finished; false otherwise.
	 */
	virtual bool isFinished();

	/**
	 * This method waits until the transcoding process is finished.
	 * It can be used to create a block program, that will sleep until the coding is finished.
	 * @throw InitializationException when the transcoding process hasn't begun.
	 * @throw InitializationException when the transcoding process hasn't begun.
	 */
	virtual void waitFinishing();

protected:
	bool finished;
	bool started;

};


}
}
}
}

#endif //STREAMING_H_

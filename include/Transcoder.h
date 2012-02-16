/*
 * Transcoder
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
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

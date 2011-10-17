/*
 * SharedBuffer.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef SHAREDBUFFER_H_
#define SHAREDBUFFER_H_

#include "AVSource.h"
#include "DeviceInterface.h"

namespace br{
namespace ufscar{
namespace lince{
namespace streaming{

/**
 * This class represents a input device that used the Unix Shared Memory to generate images.
 * Using this AVSource, the transcoding process will utilize images in a
 * specific buffer in memory as a raw images to generate video.
 * An application that generate image and video must put its in a shared buffer, using the
 * DeviceInterface class.
 */
class SharedBuffer : public AVSource {
public:
	/**
	 * Construtor
	 */
	SharedBuffer();

	/**
	 * Virtual Destructor
	 */
	virtual ~SharedBuffer();

	/**
	 * Return the current width of the images in the buffer.
	 * @return width of the Images
	 */
	int getWidth();

	/**
	 * Return the current height of the images in the buffer.
	 * @return height of the Images
	 */
	int getHeight();

protected:
	/**
	 * This protected method is internally used to allow the SharedBuffer's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	DeviceInterface* device;

};

}
}
}
}

#endif /* SHAREDBUFFER_H_ */

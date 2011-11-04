/*
 * AVSource.h
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 */

#ifndef AVSOURCE_H
#define AVSOURCE_H

#include <string>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

class Transcoder;

/**
 * This abstract class represents a generic audio/video source.
 * The classes that represents a less-generic audio/video source
 * (such a device, a inputfile a network stream) should implement this class.
 */
class AVSource {

/**
 * This class is a friend of Transcoder because transcoder need to call the
 * configure AVSource's method to processed with the transcoding process.
 */
friend class Transcoder;

public:
	/**
	 * Format Construtor.
	 * Various audio/video sources can provide content in different formats, so it's important
	 * inform implicitly the used format.
	 * @param format the format of the audio/video of the source.
	 */
	AVSource(std::string format);

	/**
	 * Return the format of the audio/video of the source
	 * @return
	 */
	virtual std::string getFormat();

	/**
	 * Virtual Destroctor
	 */
	virtual ~AVSource() {};


	void setStartTime(int seconds);

	void setDurationTime(int seconds);

protected:
	/**
	 * This protected method is internally used to allow the AVSource's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	virtual void configure(void* ffrapper)=0;

	bool configured;
	int startTime;
	int durationTime;

private:
	std::string format;

};


}
}
}
}

#endif //AVSOURCE_H

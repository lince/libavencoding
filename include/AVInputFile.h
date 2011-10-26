/*
 * AVInputFile.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef AVINPUTFILE_H_
#define AVINPUTFILE_H_

#include "AVSource.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

/**
 * This class represents a audio/video file that will be used as a input for trascoding process.
 */
class AVInputFile : public AVSource {
public:
	/**
	 * Constructor.
	 * @param filename The name of the file.
	 * @format The format of the audio/video in the file.
	 */
	AVInputFile(string filename, string format);

	/**
	 * Virtual Destructor
	 */
	virtual ~AVInputFile();

	/**
	 * Return the name of the file.
	 * @return name of the file.
	 */
	string getFilename();

protected:
	/**
	 * This protected method is internally used to allow the AVInputFile's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	string filename;

};

}
}
}
}

#endif /* AVINPUTFILE_H_ */

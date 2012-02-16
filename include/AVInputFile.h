/**
 * File: AVInputFile.h
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

#ifndef AVINPUTFILE_H_
#define AVINPUTFILE_H_

#include <libcpputil/logger/Logger.h>
#include <libcpputil/IllegalParameterException.h>
#include <string>

#include "AVSource.h"
#include "AVContainer.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

//TODO: Permitir abrir o arquivo e obter infomrações sobre ele.

/**
 * This class represents a audio/video file that will be used as a input for trascoding process.
 */
class AVInputFile : public AVSource, public cpputil::logger::Loggable  {
public:
	/**
	 * Constructor.
	 * @param filename The name of the file.
	 * @param container The container of the audio/video in the file.
	 */
	AVInputFile(std::string filename, AVContainer container = AVContainer::NONE);

	/**
	 * Virtual Destructor
	 */
	virtual ~AVInputFile();

	/**
	 * Returns the name of the file.
	 * @return name of the file.
	 */
	std::string getFilename();

	/**
	 * Returns the container of the file
	 * @return The Container.
	 */
	AVContainer getContainer();

protected:
	/**
	 * This protected method is internally used to allow the AVInputFile's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	std::string filename;
	AVContainer container;

};

}
}
}
}

#endif /* AVINPUTFILE_H_ */

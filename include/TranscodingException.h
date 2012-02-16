/**
 * File: TranscodingException.h
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

#ifndef TRANSCODINGEXCEPTION_H_
#define	TRANSCODINGEXCEPTION_H_

#include <libcpputil/SimpleException.h>

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

/**
 * Exception throwed when some error occurs during the transcoding process.
 */
class TranscodingException : public cpputil::SimpleException {
public:

	/**
	 * Complete Constructor.
	 * @param e The raw error message.
	 * @param c The class where the exception occurs.
	 * @param m The method where the exception was throwed.
	 */
	TranscodingException(std::string e, std::string c, std::string m) :
		cpputil::SimpleException (e, c, m){

		setExceptionSign("br::ufscar::lince::avencoding::TranscodingException");
	}

	/**
	 * Simple Constructor.
	 * The values to class and method will be omitted.
	 * @param e The raw error message.
	 */
	TranscodingException(std::string e) : cpputil::SimpleException(e) {
		setExceptionSign("br::ufscar::lince::avencoding::TranscodingException");
	}
};

}
}
}
}

#endif	/* TRANSCODINGEXCEPTION_H_ */


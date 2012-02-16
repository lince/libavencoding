/**
 * File: SharedBuffer.cpp
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

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
using namespace cpputil;

#include "SharedBuffer.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::SharedBuffer"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

SharedBuffer::SharedBuffer() :
		AVSource("shmgrab"), logger::Loggable(CLASS_NAME) {

	trace("begin constructor");
	device = DeviceInterface::getInstance();
}

SharedBuffer::~SharedBuffer() {
	trace("begin destructor");
}

int SharedBuffer::getHeight() {
	return device->getHeight();
}

int SharedBuffer::getWidth() {
	return device->getWidth();
}

void SharedBuffer::configure(void* _ffrapper) {
	trace("begin configure(void*)");

	if (configured) {
		return;
	}
	configured = true;

	if(FFMpeg_setFormat((char*) "shmgrab") != FFMpeg_SUCCESS) {
		error("Error trying to set the format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");
	}

	if (FFMpeg_setFramerate((char*)
			Functions::numberToString(device->getFPS()).c_str() ) != FFMpeg_SUCCESS) {

		error("Error trying to set the frame rate.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");
	}

	if (FFMpeg_setInputFile((char*) "shmgrab") != FFMpeg_SUCCESS) {
		error("Error trying to set the file name.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");

	}
}

}
}
}
}

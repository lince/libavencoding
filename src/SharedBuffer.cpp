/*
 * SharedBuffer.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include "../include/SharedBuffer.h"

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
#include <libcpputil/IllegalParameterException.h>
using namespace cpputil;

using namespace cpputil::logger;

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

SharedBuffer::SharedBuffer() :
		AVSource("shmgrab"), Loggable("br::ufscar::lince::avencoding::SharedBuffer") {

	trace("begin constructor");
	device = DeviceInterface::getInstance();
}

SharedBuffer::~SharedBuffer() {
	// TODO Auto-generated destructor stub
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
				"br::ufscar::lince::avencoding::SharedBuffer",
				"configure(void*)");
	}

	if (FFMpeg_setFramerate((char*)
			Functions::numberToString(device->getFPS()).c_str() ) != FFMpeg_SUCCESS) {

		error("Error trying to set the frame rate.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::SharedBuffer",
				"configure(void*)");
	}

	if (FFMpeg_setInputFile((char*) "shmgrab") != FFMpeg_SUCCESS) {
		error("Error trying to set the file name.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				"br::ufscar::lince::avencoding::SharedBuffer",
				"configure(void*)");

	}
}

}
}
}
}

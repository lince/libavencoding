/*
 * SharedBuffer.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libffmpeg/libffmpeg.h>

#include <cpputil/Functions.h>
using namespace cpputil;

#include "../include/SharedBuffer.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

SharedBuffer::SharedBuffer() : AVSource("shmgrab") {
	device = DeviceInterface::getInstance();
}

SharedBuffer::~SharedBuffer() {
	// TODO Auto-generated destructor stub
}

int SharedBuffer::getHeight() {
	return device->getHeight();
}



int SharedBuffer::getWidth() {
	return device->getWidth();
}

void SharedBuffer::configure(void* _ffrapper) {
	if (configured) {
		return;
	}
	configured = true;

	FFMpeg_setFormat((char*) "shmgrab");
	FFMpeg_setFramerate((char*) Functions::numberToString(device->getFPS()).c_str() );
	FFMpeg_setInputFile((char*) "shmgrab");
}

}
}
}
}

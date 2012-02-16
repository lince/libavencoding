/*
 * AVSource.h
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 */

#include "AVSource.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

AVSource::AVSource(std::string format) {

	this->format = format;
	configured = false;
	startTime = -1;
	durationTime = -1;
}

std::string AVSource::getFormat() {
	return this->format;
}

void AVSource::setStartTime(int seconds) {
	this->startTime = seconds;
}

void AVSource::setDurationTime(int seconds) {
	this->durationTime = seconds;
}

}
}
}
}

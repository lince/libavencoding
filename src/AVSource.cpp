/*
 * AVSource.h
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 */

#include "../include/AVSource.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

AVSource::AVSource(std::string format) {

	this->format = format;
	configured = false;
}

std::string AVSource::getFormat() {
	return this->format;
}

}
}
}
}

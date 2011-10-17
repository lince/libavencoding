/*
 * AVSource.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include "../include/AVSource.h"

namespace br{
namespace ufscar{
namespace lince{
namespace streaming{

AVSource::AVSource(string format) {
	this->format = format;
	configured = false;
}

string AVSource::getFormat() {
	return this->format;
}

}
}
}
}

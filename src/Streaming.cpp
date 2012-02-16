/*
 * Streaming.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include "Streaming.h"

#include <libffmpeg/libffmpeg.h>

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

Streaming::Streaming() : Transcoder() {
	finished = false;
	started = false;
}

bool Streaming::isFinished() {
	return finished;
}

void Streaming::waitFinishing() {
	if (!started) {
		throw new cpputil::InitializationException(
				"Transconding Process haven't started yet",
				"br::ufscar::lince::avencoding::Streaming",
				"waitFinishing()");
	}
	Thread::waitForUnlockCondition();
}

void Streaming::start() {
	started = true;
	finished = false;
	Thread::start();
}

double Streaming::getCurrentTime() {
	return FFMpeg_getTime();
}


}
}
}
}

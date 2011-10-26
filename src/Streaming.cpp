/*
 * Streaming.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include "../include/Streaming.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

	Streaming::Streaming() : Transcoder() {
		finished = false;
		started = false;
	}

	bool Streaming::isFinished() {
		return finished;
	}

	void Streaming::waitFinishing() {
		if (!started) {
			throw new InitializationException(
					"Transconding Process haven't started yet",
					 "br::ufscar::lince::streaming::Streaming",
					 "waitFinishing()");
		}
		Thread::waitForUnlockCondition();
	}

	void Streaming::start() {
		started = true;
		finished = false;
		Thread::start();
	}


}
}
}
}

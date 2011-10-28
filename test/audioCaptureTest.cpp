/*
 * audioFileToFileTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program transcodes the content of a audio file called "audiosample.acc" into a new file, using the
 * audio codec libmp3lame, generating a new file called "newaudio.mp3".
 */

#include <libcpputil/logger/LoggerManager.h>
using namespace cpputil::logger;

#include "../include/AlsaDevice.h"
#include "../include/X11Terminal.h"
#include "../include/AVEncoder.h"
#include "../include/AVOutputFile.h"
using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	LoggerManager* lm = LoggerManager::getInstance();
	lm->readConfigurationFile("config.xml");

	X11Terminal* alsa = new X11Terminal(25);
	//alsa->setChannelsNumber(1);

	AVEncoder* endocer = new AVEncoder(alsa);
	endocer->setVideoCodec(MPEG2);
	//endocer->setAudioBitrate(192);

	AVOutputFile* mp3File = new AVOutputFile("newaudio0.mp4");
	mp3File->addStream(endocer);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();
	delete mp3File;

	mp3File = new AVOutputFile((string) "newaudio1.mp4");
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();
	delete mp3File;

	mp3File = new AVOutputFile((string) "newaudio2.mp4");
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();
	delete mp3File;

	return 0;
}

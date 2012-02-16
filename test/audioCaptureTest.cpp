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
#include "../include/AVInputFile.h"
using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	LoggerManager* lm = LoggerManager::getInstance();
	lm->readConfigurationFile("config.xml");

	/*X11Terminal* alsa = new X11Terminal(25);
	//alsa->setChannelsNumber(1);*/

	AlsaDevice* alsa = new AlsaDevice(0,0);

	AVEncoder* audioEnc = new AVEncoder(alsa);
	audioEnc->setAudioCodec(AudioCodec::MP3);

	AVOutputFile* mp3File = new AVOutputFile("capturedAudio0.mp3");
	mp3File->addStream(audioEnc);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();

	mp3File = new AVOutputFile("capturedAudio1.mp3");
	mp3File->addStream(audioEnc);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();

	mp3File = new AVOutputFile("capturedAudio2.mp3");
	mp3File->addStream(audioEnc);
	mp3File->start();
	sleep(5);
	mp3File->stop();
	mp3File->waitFinishing();

	return 0;
}

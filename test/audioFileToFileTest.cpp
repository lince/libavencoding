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

#include "../include/AVInputFile.h"
#include "../include/AVEncoder.h"
#include "../include/AVOutputFile.h"
using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	LoggerManager* lm = LoggerManager::getInstance();
	lm->readConfigurationFile("config.xml");

	AVSource* accFile = new AVInputFile("audiosample.aac", "aac");

	AVEncoder* endocer = new AVEncoder(accFile);
	endocer->setAudioCodec(AudioCodec::MP3);
	endocer->setAudioChannelsNumber(2);
	endocer->setAudioBitrate(192);

	AVOutputFile* mp3File = new AVOutputFile("newaudio.mp3");
	mp3File->addStream(endocer);
	mp3File->start();

	mp3File->waitFinishing();
	return 0;
}

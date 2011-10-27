/*
 * test4.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program transcodes the content of a audio file called audio.mp3 into a new file, using the
 * audio codec acc, generating a new file called "output.mp4"
 */

#include "../include/AVInputFile.h"
#include "../include/AVEncoder.h"
#include "../include/AVOutputFile.h"
using namespace ::br::ufscar::lince::avenconding;


#include <iostream>
using namespace std;

int main() {
	AVSource* mp3File = new AVInputFile("audio.mp3", "mp3");

	AVEncoder* endocer = new AVEncoder(mp3File);
	endocer->setAudioCodec(AAC);
	endocer->setAudioBitrate(320);

	AVOutputFile* aacFile = new AVOutputFile((string) "output.mp4");
	aacFile->addStream(endocer);
	aacFile->start();

	while(!aacFile->isFinished()) {
		usleep(1000000);
	}

	return 0;
}

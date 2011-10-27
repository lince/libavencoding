/*
 * muxingVideoAndAudioTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program join the video content from the file "videosample.mp4" with
 * the audio content of the file "audiosample.acc", creating a new
 * file called "outputfile.mp4".
 * It uses the video codec H264 and audio codec AAC.
 */

#include "../include/AVOutputFile.h"
#include "../include/AVInputFile.h"
#include "../include/AVEncoder.h"

using namespace ::br::ufscar::lince::avenconding;

int main(int argc, char** argv) {
	AVSource* vfile = new AVInputFile("videosample.mp4", "mp4");
	AVSource* afile = new AVInputFile("audiosample.aac", "aac");

	AVEncoder* encoderVid = new AVEncoder(vfile);
	encoderVid->setVideoCodec(H264);
	encoderVid->setVideoPreset("ipod320");
	encoderVid->setPropertyValue("crf", "22");

	AVEncoder* encoderAud = new AVEncoder(afile);
	encoderAud->setAudioCodec(AAC);

	AVOutputFile* outFile = new AVOutputFile("outputfile.mp4");
	outFile->addStream(encoderVid);
	outFile->addStream(encoderAud);
	outFile->start();

	outFile->waitFinishing();

	return 0;
}

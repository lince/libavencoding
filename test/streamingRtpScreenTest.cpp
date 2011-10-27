/*
 * test2.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program transcodes the content of the shared buffer into a video using the codec h264 and
 * a transcodes a audio from the file audio.mp3 using the codec aac. The coded video and
 * audio are used to generate a MpegTS, that is streamed using the UDP protocol addressed
 * to the localhost on port 5004.
 */

#include "../include/X11Terminal.h"
#include "../include/AVInputFile.h"
#include "../include/AVSource.h"
#include "../include/AVEncoder.h"
#include "../include/Streaming.h"
#include "../include/UDPMpegTS.h"
#include "../include/RTPStream.h"

using namespace ::br::ufscar::lince::avenconding;

int main() {
	AVSource* device = new X11Terminal(1280, 1024, 25);
	//AVSource* file = new AVInputFile("audio.mp3", "mp3");

	AVEncoder* encoderVid = new AVEncoder(device);
	encoderVid->setVideoCodec(H264);
	encoderVid->setVideoPreset("ipod320");
	encoderVid->setPropertyValue("crf", "22");

	//AVEncoder* encoderAud = new AVEncoder(file);
	//encoderAud->setAudioCodec(AAC);

	Streaming* streammer = new RTPStream("127.0.0.1", 5004);
	streammer->addStream(encoderVid);
	//streammer->addStream(encoderAud);
	streammer->start();

	streammer->waitFinishing();

	return 0;
}

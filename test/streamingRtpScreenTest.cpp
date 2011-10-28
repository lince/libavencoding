/*
 * streamingRtpScreenTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program capture the content of X11 (screen) and transcodes it using the video codec H264 for 10 seconds.
 * The trancoded video is them streaming using RTP protocol to the localhost on port 5004.
 */

#include "../include/X11Terminal.h"
#include "../include/AVEncoder.h"
#include "../include/RTPStream.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	AVSource* device = new X11Terminal(1280, 1024, 25);

	AVEncoder* encoderVid = new AVEncoder(device);
	encoderVid->setVideoCodec(H264);
	encoderVid->setVideoPreset("ipod320");
	encoderVid->setPropertyValue("crf", "22");


	Streaming* streammer = new RTPStream("127.0.0.1", 5004);
	streammer->addStream(encoderVid);
	streammer->start();

	sleep(10);

	streammer->stop();
	streammer->waitFinishing();

	return 0;
}

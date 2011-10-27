/*
 * test1.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program transcodes the content of the X11 Terminal into a video using the codec h264.
 * The coded video is used to generate a RTP Stream addressed to the localhost on port 5004.
 */

#include "../include/X11Terminal.h"
#include "../include/AVSource.h"
#include "../include/AVEncoder.h"
#include "../include/Streaming.h"
#include "../include/RTPStream.h"

using namespace ::br::ufscar::lince::avenconding;

int main() {
	AVSource* source = new X11Terminal(25);

	AVEncoder* encoder = new AVEncoder(source);
	encoder->setVideoCodec(H264);
	encoder->setVideoPreset("ultrafast");
	encoder->setPropertyValue("crf", "22");

	Streaming* streammer = new RTPStream("127.0.0.1", 5004);
	streammer->addStream(encoder);
	streammer->start();

	streammer->waitFinishing();

	return 0;
}

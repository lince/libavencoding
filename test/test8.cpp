/*
 * test8.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program transcodes the content of the X11 (screen) into a video using the codec h264.
 * The coded video is used to generate a RTP Stream addressed to the localhost on port 5004
 * for 8 seconds, after this time, the transcoding process is aborted by the method stop.
 */

#include <streaming/X11Terminal.h>
#include <streaming/AVEncoder.h>
#include <streaming/RTPStream.h>

using namespace ::br::ufscar::lince::streaming;

int main() {
	AVSource* device = new X11Terminal(1280, 1024, 25);

	AVEncoder* encoderVid = new AVEncoder(device);
	encoderVid->setVideoCodec(H264);
	encoderVid->setVideoPreset("ultrafast");
	encoderVid->setPropertyValue("crf", "22");

	Streaming* streammer = new RTPStream("127.0.0.1", 5004);
	streammer->addStream(encoderVid);
	streammer->start();

	while (!streammer->isFinished()) {
		usleep(8000000);
		streammer->stop();
	}

	return 0;
}

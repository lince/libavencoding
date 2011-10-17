/*
 * test3.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program transcodes the content of the X11 (screen) into a video using the codec h264.
 * The coded video is used to generate a RTP Stream addressed to the localhost on port 5004.
 */

#include <streaming/X11Terminal.h>
#include <streaming/AVEncoder.h>
#include <streaming/RTPStream.h>

using namespace ::br::ufscar::lince::streaming;

int main(int argc, char** argv) {
	/*if (!(argc == 1) || !(argc == 3) {
		cout<<"Wrong Arguments!"<<endl;
		cout<<"Try: test3 <ip-address> <port>"<<endl;
		cout<<"If you Call without arguments, we will assume the default."<<endl;

	}*/

	AVSource* device = new X11Terminal(1280, 1024, 25);

	AVEncoder* encoderVid = new AVEncoder(device);
	encoderVid->setVideoCodec(MPEG2);

	Streaming* streammer = new RTPStream("192.168.231.128", 5006);
	streammer->addStream(encoderVid);
	streammer->start();

	streammer->waitFinishing();

	return 0;
}

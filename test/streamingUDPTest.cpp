/*
 * streamingUDPTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This transcode the content of the file "videosample.mp4", encapsules it in Mpeg-TS
 * and streams it using the UDP protocol to localhost on port 1234.
 * It uses the video codec MPEG2Video and the audio codec AAC.
 */

#include "../include/AVInputFile.h"
#include "../include/AVEncoder.h"
#include "../include/UDPMpegTS.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {

	AVSource* avfile = new AVInputFile("videosample.mp4", "mp4");

	AVEncoder* encoderVid = new AVEncoder(avfile, 0);
	encoderVid->setVideoCodec(VideoCodec::MPEG2);

	AVEncoder* encoderAud = new AVEncoder(avfile, 1);
	encoderAud->setAudioCodec(AudioCodec::AAC);

	Streaming* streammer = new UDPMpegTS("127.0.0.1", 1234);
	streammer->addStream(encoderVid);
	streammer->addStream(encoderAud);
	streammer->start();

	streammer->waitFinishing();

	return 0;
}

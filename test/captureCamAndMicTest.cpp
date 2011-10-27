/*
 * captureCamAndMicTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program captures the camera 0 and alsa mic 0:0 for 10 seconds and generates
 * a file named "outputfile1.mp4" with the grabbed content.
 * It uses the video codec H264 and the audio codec AAC.
 */

#include "../include/X11Terminal.h"
#include "../include/AlsaDevice.h"
#include "../include/AVEncoder.h"
#include "../include/AVOutputFile.h"

using namespace ::br::ufscar::lince::avenconding;

int main(int argc, char** argv) {
	AVSource* x11Device = new X11Terminal(1280, 1024, 25);
	AVSource* alsaDevice = new AlsaDevice(0, 0);

	AVEncoder* encoderVid = new AVEncoder(x11Device);
	encoderVid->setVideoCodec(H264);
	encoderVid->setVideoPreset("baseline");
	encoderVid->setPropertyValue("crf", "22");

	AVEncoder* encoderAud = new AVEncoder(alsaDevice);
	encoderAud->setAudioCodec(AAC);
	encoderAud->setAudioBitrate(192);

	AVOutputFile* ofile = new AVOutputFile("outputfile1.mp4", "mp4");
	ofile->addStream(encoderVid);
	ofile->addStream(encoderAud);
	ofile->start();

	sleep(10);
	ofile->stop();
	ofile->waitFinishing();

	return 0;
}

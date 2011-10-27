/*
 * test5.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program transcodes the content of a audio/video file called video.mp4 into a new file,
 * using the video codec h264 and coping the original audio stream to the new file. It's generating
 * a new file called outputfile.mp4
 */
#include "../include/AVInputFile.h"
#include "../include/AVEncoder.h"
#include "../include/AVOutputFile.h"

using namespace ::br::ufscar::lince::avenconding;

int main() {
	AVSource* videoInput = new AVInputFile("sintel_trailer-720p.mp4", "mp4");

	AVEncoder* encoder = new AVEncoder(videoInput);
	encoder->setVideoCodec(H264);
	encoder->setVideoPreset("veryslow");
	encoder->setPropertyValue("crf", "24");
	encoder->setVideoSize(400, 400);
	AVEncoder* audio = new AVEncoder(videoInput);
	audio->setAudioCodec(MP3);

	AVOutputFile* videoOutput = new AVOutputFile("outputfile.mp4");
	videoOutput->addStream(encoder);
	videoOutput->addStream(audio);
	videoOutput->start();

	videoOutput->waitFinishing();
	return 0;
}

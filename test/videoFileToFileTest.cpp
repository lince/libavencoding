/*
 * videoFileToFileTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program transcodes the content of file called "videosample.mp4" into a new file, using the
 * video codec H264 and audio codec AAC, generating a new file called "newfile.mp4".
 * It resizes the video to 400x400 during the transcode process.
 */
#include "../include/AVInputFile.h"
#include "../include/AVEncoder.h"
#include "../include/AVOutputFile.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	AVSource* videoInput = new AVInputFile("videosample.mp4", "mp4");

	AVEncoder* encoder = new AVEncoder(videoInput);
	encoder->setVideoCodec(VideoCodec::H264);
	encoder->setVideoPreset("ipod320");
	encoder->setPropertyValue("crf", "24");
	encoder->setVideoSize(400, 400);
	AVEncoder* audio = new AVEncoder(videoInput);
	audio->setAudioCodec(AudioCodec::AAC);

	AVOutputFile* videoOutput = new AVOutputFile("newfile.mp4");
	videoOutput->addStream(encoder);
	videoOutput->addStream(audio);
	videoOutput->start();

	videoOutput->waitFinishing();
	return 0;
}

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
#include <streaming/AVInputFile.h>
#include <streaming/AVEncoder.h>
#include <streaming/AVOutputFile.h>

using namespace ::br::ufscar::lince::streaming;

int main() {
	AVSource* videoInput = new AVInputFile("video.mp4", "mp4");

	AVEncoder* encoder = new AVEncoder(videoInput);
	encoder->setVideoCodec(H264);
	encoder->setVideoPreset("veryslow");
	encoder->setPropertyValue("crf", "24");
	encoder->setVideoSize(1280, 720);
	AVEncoder* audio = new AVEncoder(videoInput);
	audio->setAudioCodec(A_COPY);

	AVOutputFile* videoOutput = new AVOutputFile("outputfile.mp4");
	videoOutput->addStream(encoder);
	videoOutput->addStream(audio);
	videoOutput->start();

	while(!videoOutput->isFinished()) {
		usleep(1000);
	}

	return 0;
}

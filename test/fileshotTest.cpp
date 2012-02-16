/*
 * fileshotTest.cpp
 *
 *  Last Change: Oct 27, 2011
 *       Author: Caio César Viel
 *        Email: caio_viel@dc.ufscar.br
 *
 * This program take two shot of a video file named at the moment 10, 11 and 12 seconds,
 * generating images files called fileshot1.jpg, fileshot2.jpg and fileshot3.jpg.
 * It uses the image codec MJPEG.
 */

#include "../include/AVInputFile.h"
#include "../include/ImageShotter.h"

using namespace ::br::ufscar::lince::avencoding;

int main(int argc, char** argv) {
	AVInputFile* inputfile = new AVInputFile("videosample.mp4", AVContainer::MP4);
	ImageShotter* shotter = new ImageShotter(inputfile);

	shotter->setImageSize(200,100);
	shotter->takeShot("fileshot1.jpg", "10");
	shotter->waitFinishing();

	shotter->takeShot("fileshot2.jpg", "11");
	shotter->waitFinishing();

	shotter->setImageSize(900, 600);
	shotter->takeShot("fileshot3.jpg", "12");
	shotter->waitFinishing();
	return 0;
}

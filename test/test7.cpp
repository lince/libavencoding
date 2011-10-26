/*
 * test7.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program take two shot of a video file at the moment 40 seconds and generate a
 * images files called fileshot.jpg using the image codec mjpeg.
 */

#include <avenconding/AVInputFile.h>
#include <avenconding/ImageShotter.h>

using namespace ::br::ufscar::lince::avenconding;

int main(int argc, char** argv) {
	AVInputFile* inputfile = new AVInputFile("/home/caioviel/Desktop/Videos/arg_ger.mp4", "mp4");
	ImageShotter* shotter = new ImageShotter(inputfile);

	shotter->setImageSize(800, 600);
	shotter->takeShot("fileshot.jpg", "40");
	shotter->waitFinishing();
	return 0;
}

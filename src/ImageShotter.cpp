/*
 * ImageShotter.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libcpputil/Functions.h>

using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

#include "ImageShotter.h"
using namespace std;

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

ImageShotter::ImageShotter(AVSource* source, ImageFormat format) : Thread(),
		cpputil::logger::Loggable("br::ufscar::lince::avencoding::ImageShotter") {

	trace("begin constructor");

	this->source = source;
	imageFormat = format;
	width = height = 0;
	started = false;
	finished = false;
}

ImageShotter::~ImageShotter() {
	trace("begin destrutor");

}

bool ImageShotter::isFinished() {
	return finished;
}

void ImageShotter::waitFinishing() {
	trace("begin waitFinishing()");

	if (!started) {
		throw new InitializationException(
				"Transconding Process haven't started yet",
				"br::ufscar::lince::avencoding::ImageShotter",
				"waitFinishing()");
	}
	Thread::waitForUnlockCondition();
}


void ImageShotter::takeShot(string nfilename) {
	trace("begin takeShot(string)");

	settedTime = false;
	filename = nfilename;
	started = true;
	finished = false;
	start();
}

void ImageShotter::takeShot(string nfilename, int ltime) {
	trace("begin takeShot(string, int)");

	settedTime = true;
	time = Functions::numberToString(ltime);
	filename = nfilename;
	started = true;
	finished = false;
	start();
}
void ImageShotter::takeShot(string nfilename, string stime) {
	trace("begin trakeShot(string, string)");

	settedTime = true;
	time = stime;
	filename = nfilename;
	started = true;
	finished = false;
	start();
}

void ImageShotter::setImageSize(int width, int heigh) {
	this->width = width;
	this->height = heigh;
}

int ImageShotter::getImageWidht() {
	return this->width;
}

int ImageShotter::getImageHeight() {
	return this->height;
}

void ImageShotter::setImageFormat(ImageFormat format) {
	this->imageFormat = format;
}

void ImageShotter::setImageFormat(string str) {
	try {
		this->imageFormat = ImageFormat(str);
	} catch (SimpleException& ex) {
		throw IllegalParameterException(
				"Tyring to convert a invalid string '" + str
				+ "' into a ImageFormat",
				"br::ufscar::lince::avencoding::ImageShotter",
				"setImageFormat(string)");
	}
}

ImageFormat ImageShotter::getImageFormat() {
	return imageFormat;
}

void ImageShotter::run() {
	trace("begin run()");

	static bool iniciado = false;
	if (!iniciado) {
		cout<<"Vamos Chamar o Init!"<<endl;
		FFMpeg_init(5);
		iniciado = true;
	}
	configure(source, (void*) NULL);

	FFMpeg_setRecordingTime1((char*)"1");
	if (settedTime) {
		cout<<"\n\ttempo inicial setado='"<<time<<"'"<<endl;
		FFMpeg_setStartTime1((char*) time.c_str());
	}

	if (imageFormat == ImageFormat::JPEG) {
		FFMpeg_setFormat((char*)"mjpeg");
	} else {
		throw NotImplementedException(
				"Just JPEG ImageFormat is supported for now.",
				"br::ufscar::lince::avencoding::ImageShotter",
				"run()");
	}
	if (height != 0 && width != 0) {
		FFMpeg_setFrameSize2(width, height);
	}

	FFMpeg_setOutputFile((char*) filename.c_str());

	FFMpeg_transcode();

	FFMpeg_reset(__LINE__);

	finished = true;
	started = false;
	Thread::unlockConditionSatisfied();
}

double ImageShotter::getCurrentTime() {
	error("Method getCurrentTime called by an instance of ImageShotter.");
	throw InitializationException(
			"You shoudn't call this method with a ImageShotter instances.",
			"br::ufscar::lince::avencoding::ImageShotter",
			"getCurrentTime()");
}

}
}
}
}

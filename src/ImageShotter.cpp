/**
 * File: ImageShotter.cpp
 * Created by: Caio César Viel
 * Contact: caioviel@gmail.com
 * Last Modification: 02-16-2012
 *
 * Copyright (c) 2012 LINCE-UFSCar
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <cstdlib>
using namespace std;

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
using namespace cpputil;

#include "ImageShotter.h"

#define CLASS_NAME	"br::ufscar::lince::avencoding::ImageShotter"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

ImageShotter::ImageShotter(AVSource* source, ImageFormat format) : Thread(),
		cpputil::logger::Loggable(CLASS_NAME) {

	trace("begin constructor");

	if (source == NULL) {
		throw IllegalParameterException(
				"AVSource informed as parameter is NULL.",
				CLASS_NAME,
				"ImageShotter(AVSource*, ImageFormat)");
	}

	this->source = source;
	imageFormat = format;
	width = height = 0;
	started = false;
	finished = false;
	FFMpeg_init(5);
}

ImageShotter::~ImageShotter() {
	trace("begin destrutor");

	delete source;

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

	if (ltime < 0) {
		throw cpputil::IllegalParameterException(
				"Invalid time informed: " + Functions::numberToString(ltime),
				CLASS_NAME,
				"takeShot(string, int)");
	}

	settedTime = true;
	time = Functions::numberToString(ltime);
	filename = nfilename;
	started = true;
	finished = false;
	start();
}
void ImageShotter::takeShot(string nfilename, string stime) {
	trace("begin trakeShot(string, string)");

	//TODO Check parameter stime.
	settedTime = true;
	time = stime;
	filename = nfilename;
	started = true;
	finished = false;
	start();
}

void ImageShotter::setImageSize(int width, int heigh) {
	if (width < 0 || height < 0) {
		throw cpputil::IllegalParameterException(
				"Invalid size informed.",
				CLASS_NAME,
				"setImageSize(int, int)");
	}

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
				CLASS_NAME,
				"setImageFormat(string)");
	}
}

ImageFormat ImageShotter::getImageFormat() {
	return imageFormat;
}

void ImageShotter::run() {
	trace("begin run()");

	configure(source, (void*) NULL);

	if (FFMPeg_setVideoMaxFrames(1) != FFMpeg_SUCCESS) {
		error("Error trying to set max frame number to 1");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	/*if (FFMpeg_setRecordingTime1((char*)"1") != FFMpeg_SUCCESS) {
		error("Error trying to set recording time to 1");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}*/
	if (settedTime) {
		if (FFMpeg_setStartTime1((char*) time.c_str()) != FFMpeg_SUCCESS) {
			error("Error trying to positioning to take the shot at: " + time);
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}
	}

	if (imageFormat == ImageFormat::JPEG) {
		char* format = "";
		char* vcodec = "";

		if (imageFormat == ImageFormat::JPEG) {
			vcodec = (char*) "mjpeg\0";
			format = (char*) "mjpeg\0";
		} else if (imageFormat == ImageFormat::GIF) {
			format = (char*) "gif\0";
			vcodec = (char*) "gif\0";
		} else if (imageFormat == ImageFormat::TIFF) {
			format = (char*) "tiff\0";
			vcodec = (char*) "tiff\0";
		} else if (imageFormat == ImageFormat::PNG) {
			format = (char*) "rawvideo\0";
			vcodec = (char*) "png\0";
		}

		if (FFMpeg_setVideoCodec(vcodec) != FFMpeg_SUCCESS) {
			error((string) "Error trying to set codec: " + vcodec);
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}

		if (FFMpeg_setFormat(format) != FFMpeg_SUCCESS) {
			error((string) "Error trying to set format: " + format);
			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}

	} else {
		throw NotImplementedException(
				"Just JPEG ImageFormat is supported for now.",
				CLASS_NAME,
				"run()");
	}

	if (height != 0 && width != 0) {
		if (FFMpeg_setFrameSize2(width, height) != FFMpeg_SUCCESS) {
			error("Error trying to set the image size: " +
					Functions::numberToString(height) + "x" +
					Functions::numberToString(width));

			throw IllegalParameterException(
					FFMpeg_getErrorStr(),
					CLASS_NAME,
					"run()");
		}
	}


	if (FFMpeg_setVideoSameQuality(1) != FFMpeg_SUCCESS) {
		error("Error trying to set video same as true");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_setOutputFile((char*) filename.c_str()) != FFMpeg_SUCCESS) {
		error("Error trying to set the output file name as: " + filename);
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

	if (FFMpeg_transcode() != FFMpeg_SUCCESS) {
		error("Error during transcode process.");
		throw TranscodingException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"run()");
	}

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


}
}
}
}

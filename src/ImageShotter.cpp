/*
 * ImageShotter.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libcpputil/Functions.h>
#include <libcpputil/InitializationException.h>
using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

#include <iostream>
using namespace std;

#include "../include/ImageShotter.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

ImageShotter::ImageShotter(AVSource* source) : Thread() {
	this->source = source;
	codec = MJPEG;
	width = height = 0;
	started = false;
	finished = false;
}

ImageShotter::~ImageShotter() {

}

bool ImageShotter::isFinished() {
	return finished;
}

void ImageShotter::waitFinishing() {
	if (!started) {
		throw new InitializationException(
				"Transconding Process haven't started yet",
				"br::ufscar::lince::avencoding::ImageShotter",
				"waitFinishing()");
	}
	Thread::waitForUnlockCondition();
}


void ImageShotter::takeShot(string nfilename) {
	settedTime = false;
	filename = nfilename;
	started = true;
	finished = false;
	start();
}

void ImageShotter::takeShot(string nfilename, int ltime) {
	settedTime = true;
	time = Functions::numberToString(ltime);
	filename = nfilename;
	started = true;
	finished = false;
	start();
}
void ImageShotter::takeShot(string nfilename, string stime) {
	settedTime = true;
	time = stime;
	filename = nfilename;
	cout<<"Vamos chamar o start"<<endl;
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

void ImageShotter::setImageCodec(ImageCodec codec) {
	this->codec = codec;
}

void ImageShotter::setImageCodec(string vcodec) {
	//TODO: Implementar
}

ImageCodec ImageShotter::getImageCodec() {
	return codec;
}

void ImageShotter::run() {
	cout<<"Run chamado!"<<endl;
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
	cout<<"Vamos setar o formato"<<endl;
	FFMpeg_setFormat((char*)"mjpeg");
	if (height != 0 && width != 0) {
		FFMpeg_setFrameSize2(width, height);
	}
	cout<<"Vamos setar o outputfile"<<endl;
	FFMpeg_setOutputFile((char*) filename.c_str());

	cout<<"Vamos chamar o Transcode"<<"'"<<endl;
	FFMpeg_transcode();

	cout<<"ImageShotter::run() - Vamos chamar o reset"<<"'"<<endl;
	FFMpeg_reset(__LINE__);

	cout<<"saindo do ImageShotter::run()\n\n\n";
	finished = true;
	started = false;
	Thread::unlockConditionSatisfied();
}

}
}
}
}

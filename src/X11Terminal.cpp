/*
 * X11Terminal.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <X11/Xlib.h>

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
using namespace cpputil;

#include "../include/X11Terminal.h"

#include <iostream>
using namespace std;

namespace br {
namespace ufscar {
namespace lince {
namespace avenconding {

X11Terminal::X11Terminal(int width, int height, int fps) : AVSource("x11grab") {
	this->width = width;
	this->height = height;
	this->fps = fps;
}

X11Terminal::X11Terminal(int fps) : AVSource("x11grab") {
	XWindowAttributes wAttributes;
	Display* display = XOpenDisplay(NULL);
	Screen* screen = XScreenOfDisplay(display, DefaultScreen(display));
	int width = WidthOfScreen(screen);
	int height = HeightOfScreen(screen);
	cout<<"screen size: "<< width <<"x" << height << endl;
	this->width = width;
	this->height = height;
	this->fps = fps;
}

X11Terminal::X11Terminal() : AVSource("x11grab") {
	X11Terminal(25);
}

X11Terminal::~X11Terminal() {
	// TODO Auto-generated destructor stub
}


int X11Terminal::getFps() {
	return fps;
}

void X11Terminal::configure(void *_ffrapper) {
	/*if (configured) {
		return;
	}*/
	configured = true;

	FFMpeg_setFormat((char*) "x11grab");
	FFMpeg_setFramerate((char*) Functions::numberToString(fps).c_str());
	FFMpeg_setFrameSize2(width, height);
	if (FFMpeg_setInputFile((char*) ":0.0") != FFMpeg_SUCCESS) {
		cout << FFMpeg_getErrorStr() << endl;
	}
}

int X11Terminal::getHeight() {
	return height;
}

int X11Terminal::getWidth() {
	return width;
}

}
}
}
}

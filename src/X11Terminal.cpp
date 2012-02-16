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

#include "X11Terminal.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::X11Terminal"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

X11Terminal::X11Terminal(int width, int height, int fps) :
		AVSource("x11grab"), logger::Loggable(CLASS_NAME) {

	trace("begin Constructor");

	this->width = width;
	this->height = height;
	this->fps = fps;
}

X11Terminal::X11Terminal(int fps) :
		AVSource("x11grab"), logger::Loggable(CLASS_NAME) {

	trace("begin Constructor");

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


X11Terminal::~X11Terminal() {
	// TODO Auto-generated destructor stub
}


int X11Terminal::getFps() {
	return fps;
}

void X11Terminal::configure(void *_ffrapper) {
	trace("begin configure(void*)");
	/*if (configured) {
		return;
	}*/
	configured = true;

	if (FFMpeg_setFormat((char*) "x11grab") != FFMpeg_SUCCESS) {
		error("Error trying to set the format.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");
	}

	if (FFMpeg_setFramerate((char*)
			Functions::numberToString(fps).c_str()) != FFMpeg_SUCCESS) {

		error("Error trying to set the frame rate.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");


	}
	if (FFMpeg_setFrameSize2(width, height) != FFMpeg_SUCCESS) {
		error("Error trying to set the frame size.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");

	}

	if (FFMpeg_setInputFile((char*) ":0.0") != FFMpeg_SUCCESS) {
		error("Error trying to set the device 0:0.");
		throw IllegalParameterException(
				FFMpeg_getErrorStr(),
				CLASS_NAME,
				"configure(void*)");
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

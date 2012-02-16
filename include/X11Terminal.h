/*
 * X11Terminal.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef X11TERMINAL_H_
#define X11TERMINAL_H_

#include <libcpputil/IllegalParameterException.h>
#include <libcpputil/logger/Logger.h>

#include "AVSource.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * This class allow to use the X11 Terminal as a video source.
 */
class X11Terminal: public AVSource, public cpputil::logger::Loggable {
public:
	/**
	 * Construtor.
	 * @param width The width of the screen.
	 * @param width The height of the screen.
	 * @param fps The frames per second frequency of the screen.
	 */
	X11Terminal(int width, int height, int fps);

	/**
	 * Construtor.
	 * It will retrieve the size of current screen as width and height.
	 * If fps is omitted, it will assume value 25 frames per second frequency.
	 * @param fps The frames per second frequency of the screen.
	 */
	X11Terminal(int fps=25);

	/**
	 * Virtual Destructor
	 */
	virtual ~X11Terminal();

	/**
	 * Return the screen width.
	 * @return screen width
	 */
	int getWidth();

	/**
	 * Return the screen height.
	 * @return screen height
	 */
	int getHeight();

	/**
	 * Return the screen frames per second frequency.
	 * @return frames per second.
	 */
	int getFps();

protected:
	void configure(void* ffrapper);

private:
	int width;
	int height;
	int fps;
};

}
}
}
}

#endif /* X11TERMINAL_H_ */

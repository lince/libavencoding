/**
 * File: X11Terminal.h
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

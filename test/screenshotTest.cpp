/**
 * File: screenshotTest.cpp
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
 *
 * -------------------------------------------------------------------------------------------------
 *
 * This program take shots of the x11 (screen) and generate a images files called screenshotX.jpg
 * It uses the image codec MJPEG.
 */

#include "X11Terminal.h"
#include "ImageShotter.h"
using namespace ::br::ufscar::lince::avencoding;

#include <libcpputil/Functions.h>
using namespace ::cpputil;

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	AVSource* x11terminal = new X11Terminal(24);
	ImageShotter* shotter = new ImageShotter(x11terminal, ImageFormat::JPEG);

	shotter->setImageSize(1920, 1080);
	shotter->takeShot("screenshot.jpg");
	shotter->waitFinishing();

	shotter->takeShot("screenshot2.jpg");
	while (!shotter->isFinished()) {
		usleep(50000);
	}

	bool continueLoop;
	int index = 3;
	do {
		string resp;

		continueLoop = false;
		string resposta;
		shotter->takeShot("screenshot" +
				Functions::numberToString(index++) + ".jpg");
		shotter->waitFinishing();
		cout << "Continue take screenshots? (Y/N)";
		cin >> resp;
		if (resp == "y" || resp == "Y") {
			continueLoop = true;
		}
	} while(continueLoop);

	return 0;
}

/**
 * File: fileshotTest.cpp
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
 * This program take two shot of a video file named at the moment 10, 11 and 12 seconds,
 * generating images files called fileshot1.jpg, fileshot2.jpg and fileshot3.jpg.
 * It uses the image codec MJPEG.
 */

#include "AVInputFile.h"
#include "ImageShotter.h"

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

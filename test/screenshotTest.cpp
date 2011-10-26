/*
 * test6.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 *
 * This program take two shot of the x11 (screen) and generate a images files called screenshot1.jpg
 * and screenshot2.jpg. It uses the image codec MJPEG.
 */

#include <avenconding/X11Terminal.h>
#include <avenconding/ImageShotter.h>
#include <cpputil/Functions.h>

#include <iostream>
#include <string>
using namespace std;

using namespace ::br::ufscar::lince::avenconding;
using namespace ::cpputil;

int main() {
	AVSource* x11terminal = new X11Terminal(1280, 1024, 24);
	ImageShotter* shotter = new ImageShotter(x11terminal);

	shotter->setImageSize(800, 600);
	shotter->takeShot("screenshot1.jpg");
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

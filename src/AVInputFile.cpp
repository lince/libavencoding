/*
 * AVInputFile.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <libffmpeg/libffmpeg.h>
#include "../include/AVInputFile.h"

#include <iostream>
using namespace std;

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

AVInputFile::AVInputFile(string filename,
		string format) : AVSource(format) {

	this->filename = filename;
}

string AVInputFile::getFilename() {
	return filename;
}

void AVInputFile::configure(void *ffrapper_) {
	/*if (configured) {
		return;
	}*/
	configured = true;

	FFMpeg_setFormat( (char*) getFormat().c_str());
	if (FFMpeg_setInputFile( (char*) getFilename().c_str())
			!= FFMpeg_SUCCESS) {

		cerr << FFMpeg_getErrorStr() << endl;
	}
}

AVInputFile::~AVInputFile() {
	// TODO Auto-generated destructor stub
}

}
}
}
}

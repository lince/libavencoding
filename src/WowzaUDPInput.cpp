/*
 * WowzaUDPInput.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#include <cpputil/Functions.h>
using namespace cpputil;

#include <libffmpeg/libffmpeg.h>

#include <iostream>
using namespace std;

#include "../include/WowzaUDPInput.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

WowzaUDPInput::WowzaUDPInput(string ip, int port) : Streaming() {
	this->ip = ip;
	this->port = port;
	source = NULL;
	encoder = NULL;
	FFMpeg_init(0);
}

WowzaUDPInput::~WowzaUDPInput() {
	if (source) {
		delete source;
	}
	if (encoder) {
		delete encoder;
	}
}

void WowzaUDPInput::addStream(AVEncoder *stream) {
	source = stream->getSource();
	encoder = stream;
}

void WowzaUDPInput::run() {
	vector<AVSource*>::iterator it;
	configure(source, (void*)NULL);

	configure(encoder, (void*)NULL);
	FFMpeg_setVideoPreset((char*)"baseline");
	FFMpeg_setOther((char*)"g", (char*)"60");
	FFMpeg_setVideoBitrate((char*)"150000");

	FFMpeg_setFormat((char*)"mpegts");
	FFMpeg_setVideoBitstreamFilter((char*)"h264_mp4toannexb");
	string outputfile = "udp://" + ip + ":" +
			Functions::numberToString(port) + "?pkt_size=1316";

	FFMpeg_setOutputFile((char*) outputfile.c_str());
	FFMpeg_transcode();
	FFMpeg_reset(__LINE__);
	finished = true;
	Thread::unlockConditionSatisfied();
}



void WowzaUDPInput::stop() {
	FFMpeg_stop();
}

}
}
}
}

/*
 ffmpeg -s 400  -re -vcodec libx264
 -vpre default -vpre baseline -g 60
 -vb 150000 -strict experimental -acodec aac
 -ab 128000 -ar 48000 -ac 2 -vbsf h264_mp4toannexb
 -f mpegts udp://200.18.98.27:10000?pkt_size=1316
*/

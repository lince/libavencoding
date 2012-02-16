/*
 * AVEncoder.cpp
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

//TODO: Implement all parameters verification

#include <libffmpeg/libffmpeg.h>

#include <libcpputil/Functions.h>
using namespace cpputil;

#include "AVEncoder.h"
using namespace std;

#define CLASS_NAME "br::ufscar::lince::avencoding::AVEncoder"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

int AVEncoder::NONE = -1;

AVEncoder::AVEncoder(AVSource* avSource, int nStreamId) {
	if (avSource == NULL) {
		throw InitializationException(
				"AVEncoder::AVEncoder(AVSource* avSource)\n"
				"Informed a NULL AVSource.",
				"br::ufscar::lince::streaming",
				"AVEncoder(AVSource* )");
	}
	source = avSource;
	streamId = nStreamId;
	videoBitrate = NONE;
	videoFps = NONE;
	vWidth = NONE;
	vHeight = NONE;
	audioSamplingRate = NONE;
	audioBitrate = NONE;
	audioChannelsNumber = NONE;
	threadsNumber = NONE;
	vpreset = "";
	apreset = "";
	properties = new map<string, string>();
	audioEnable = videoEnable = true;
	videoSameQuality = false;
}

AVEncoder::AVEncoder(AVEncoder* copyAVEncoder) {
	source = copyAVEncoder->source;
	videoBitrate = copyAVEncoder->videoBitrate;
	videoFps = copyAVEncoder->videoFps;
	aspectRatio = copyAVEncoder->aspectRatio;
	vWidth = copyAVEncoder->vWidth;
	vHeight = copyAVEncoder->vHeight;
	vcodec = copyAVEncoder->vcodec;
	acodec = copyAVEncoder->acodec;
	audioSamplingRate = copyAVEncoder->audioSamplingRate;
	audioBitrate = copyAVEncoder->audioBitrate;
	audioChannelsNumber = copyAVEncoder->audioChannelsNumber;
	threadsNumber = copyAVEncoder->threadsNumber;
	vpreset =  copyAVEncoder->vpreset;
	apreset = copyAVEncoder->apreset;

	properties = new map<string, string>();
	map<string, string>::iterator it;
	map<string, string>* copyProp = copyAVEncoder->properties;
	for (it = copyProp->begin(); it != copyProp->end(); it++) {
		(*properties)[it->first] = it->second;
	}

}

AVEncoder::~AVEncoder() {
	delete properties;
}

void AVEncoder::setVideoBitrate(int videoBitrate) {
	this->videoBitrate = videoBitrate;
}

int AVEncoder::getVideoBitrate() {
	return this->videoBitrate;
}

void AVEncoder::setFramesPerSecond(int fps) {
	this->videoFps = fps;
}

int AVEncoder::getFramesPerSecond() {
	return videoFps;
}

void AVEncoder::setAspectRatio(AspectRatio aspectRatio) {
	this->aspectRatio = aspectRatio;
}

void AVEncoder::setAspectRatio(string aspectRatio) {
	try {
		this->aspectRatio = AspectRatio(aspectRatio);
	} catch (SimpleException& ex) {
		throw IllegalParameterException(
				"Tyring to convert a invalid string '" + aspectRatio
				+ "' into a AspectRatio",
				"br::ufscar::lince::avencoding::AVEncoder",
				"setAspectRatio(string)");
	}
}

AspectRatio AVEncoder::getAspectRatio() {
	return aspectRatio;
}

void AVEncoder::setVideoSize(int width, int height) {
	this->vHeight = height;
	this->vWidth = width;
}

void AVEncoder::setVideoSize(string videoSize) {
	//TODO Implementar
	throw NotImplementedException(
			"Please, use the setVideoSize(int, int) instead.",
			"br::ufscar::lince::avenconding::AVEncoder",
			"setVideoSize(string)");
}

int AVEncoder::getVideoWidht() {
	return vHeight;
}

int AVEncoder::getVideoHeight() {
	return vHeight;
}

void AVEncoder::setVideoCodec(VideoCodec vcodec) {
	this->vcodec = vcodec;
}

void AVEncoder::setVideoCodec(string vcodec) {
	try {
		this->vcodec = VideoCodec(vcodec);
	} catch (SimpleException& ex) {
		throw IllegalParameterException(
				"Tyring to convert a invalid string '" + vcodec
				+ "' into a VideoCodec",
				"br::ufscar::lince::avencoding::AVEncoder",
				"setVideoCodec(string)");
	}
}

VideoCodec AVEncoder::getVideoCodec() {
	return vcodec;
}

void AVEncoder::setAudioSamplingRate(int samplingRate) {
	this->audioSamplingRate = samplingRate;
}

int AVEncoder::getAudioSamplingRate() {
	return audioSamplingRate;
}

void AVEncoder::setAudioBitrate(int audioBitrate) {
	this->audioBitrate = audioBitrate;
}

int AVEncoder::getAudioBitrate() {
	return audioBitrate;
}

void AVEncoder::setAudioChannelsNumber(int channelsNumber) {
	this->audioChannelsNumber = channelsNumber;
}

int AVEncoder::getAudioChannelsNumber() {
	return audioChannelsNumber;
}

void AVEncoder::setAudioCodec(AudioCodec acodec) {
	this->acodec = acodec;
}

void AVEncoder::setAudioCodec(string acodec) {
	try {
		this->acodec = AudioCodec(acodec);
	} catch (SimpleException& ex) {
		throw IllegalParameterException(
				"Tyring to convert a invalid string '" + acodec
				+ "' into a AudioCodec",
				"br::ufscar::lince::avencoding::AVEncoder",
				"setAudioCodec(string)");
	}
}

AudioCodec AVEncoder::getAudioCodec() {
	return acodec;
}

void AVEncoder::setThreadsNumber(int threads) {
	this->threadsNumber = threads;
}

int AVEncoder::getThreadsNumber() {
	return threadsNumber;
}

AVSource* AVEncoder::getSource() {
	return source;
}

void AVEncoder::setPropertyValue(string name, string value) {
	(*properties)[name] = value;
}

string AVEncoder::getPropertyValue(string name) {
	return (*properties)[name];
}

void AVEncoder::configure(void* vffrapper) {

	if (videoBitrate != NONE) {
		string videoBitrate = Functions::numberToString(this->videoBitrate);
		videoBitrate += "k";
		FFMpeg_setVideoBitrate((char*) videoBitrate.c_str());
	}

	if (videoFps != NONE) {
		FFMpeg_setFramerate((char*) (Functions::numberToString(videoFps)).c_str() );
	}

	if (aspectRatio != AspectRatio::NONE) {
		if (aspectRatio == AspectRatio::AR_4X3) {
			FFMpeg_setFramerate((char*)"4x3");
		} else {
			FFMpeg_setFramerate((char*)"16x9");
		}
	}

	if (vWidth != NONE && vHeight != NONE) {
		FFMpeg_setFrameSize2(vWidth, vHeight);
	}

	if (vcodec != VideoCodec::NONE) {
		std::string aux = "";
		if (vcodec == VideoCodec::H264) {
			aux = "libx264";
		} else if (vcodec == VideoCodec::MPEG2){
			aux = "mpeg2video";
		} else if (vcodec == VideoCodec::COPY) {
			aux = "copy";
		} else if (vcodec == VideoCodec::MPEG1) {
			aux = "mpeg1video";
		} else if (vcodec == VideoCodec::THEORA) {
			aux = "libtheora";
		} else if (vcodec == VideoCodec::VP8) {
			aux = "libvpx";
		} else if (vcodec == VideoCodec::XVID) {
			aux = "libxvid";
		}

		if (FFMpeg_setVideoCodec((char*)aux.c_str()) != FFMpeg_SUCCESS) {
			throw IllegalParameterException(
					"Error trying to set videocodec as: " + vcodec.toString(),
					CLASS_NAME,
					"configure(void*)");
		}

	}

	if (acodec != AudioCodec::NONE) {
		std::string aux = "";
		if (acodec ==  AudioCodec::AAC) {
			aux = "libfaac";
		} else if (acodec == AudioCodec::MP3){
			aux = "libmp3lame";
		} else if (acodec == AudioCodec::COPY) {
			aux = "copy";
		} else if (acodec == AudioCodec::VORBIS) {
			aux = "libvorbis";
		} else if (acodec == AudioCodec::PCM16) {

		} else if (acodec == AudioCodec::PCM32) {

		}

		if (FFMpeg_setAudioCodec((char*) aux.c_str()) != FFMpeg_SUCCESS) {
			throw IllegalParameterException(
					"Error trying to set audiocodec as: " + acodec.toString(),
					CLASS_NAME,
					"configure(void*)");
		}
	}

	if (!videoEnable) {
		FFMpeg_setDisableAudio(1);
	}

	if (!audioEnable) {
		FFMpeg_setDisableAudio(1);
	}

	if (videoSameQuality) {
		FFMpeg_setVideoSameQuality(1);
	}

	if (audioSamplingRate != NONE) {
		FFMpeg_setAudioRate(audioSamplingRate);
	}

	if (audioBitrate != NONE) {
		string aux = Functions::numberToString(audioBitrate);
		aux +="k";
		cout << "Trying to set audiobitrate -> " << aux << endl;
		FFMpeg_setAudioBitrate((char*) aux.c_str());
	}

	if (audioChannelsNumber != NONE) {
		FFMpeg_setAudioChannels(audioChannelsNumber);
	}

	if (threadsNumber != NONE) {
		FFMpeg_setThreadCount(threadsNumber);
	}

	if (vpreset != "") {
		FFMpeg_setVideoPreset((char*) vpreset.c_str());
	}

	if (apreset != "") {
		FFMpeg_setAudioPreset((char*) apreset.c_str());
	}

	map<string, string>::iterator it;
	it = properties->begin();
	while (it != properties->end()) {
		string name = it->first;
		string value = it->second;
		FFMpeg_setOther((char*) name.c_str(), (char*) value.c_str());
		it++;
	}
}

void AVEncoder::enableCopyVideo() {
	this->vcodec = VideoCodec::COPY;

}

void AVEncoder::enableCopyAudio() {
	this->acodec = AudioCodec::COPY;
}


void AVEncoder::setVideoPreset(string preset) {
	this->vpreset = preset;
}


void AVEncoder::setAudioPreset(string preset) {
	this->apreset = preset;
}


string AVEncoder::getVideoPreset() {
	return this->vpreset;
}


string AVEncoder::getAudioPreset() {
	return this->apreset;
}

int AVEncoder::getStreamId() {
	return this->streamId;
}

void AVEncoder::setStreamId(int id) {
	this->streamId = id;
}

void AVEncoder::setVideoEnable(bool value) {
	this->videoEnable = value;
}

void AVEncoder::setAudioEnable(bool value) {
	this->audioEnable = value;
}

bool AVEncoder::isVideoEnable() {
	return videoEnable;
}

bool AVEncoder::isAudioEnable() {
	return audioEnable;
}

void AVEncoder::setVideoSameQuality(bool value) {
	this->videoSameQuality = value;
}

bool AVEncoder::isVideoSameQuality() {
	return this->videoSameQuality;
}

}
}
}
}

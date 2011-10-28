/*
 * AVEncoding.h
 *
 *   Created on: Oct 28, 2011
 *  Last Chance: 2:39:56 PM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#ifndef AVENCODING_H_
#define AVENCODING_H_

#include <libcpputil/Enum.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

class VideoCodec : public cpputil::Enum {
public:
	static const VideoCodec H264;
	static const VideoCodec MPEG1_VIDEO;
	static const VideoCodec MPEG2_VIDEO;
	static const VideoCodec MPEG4;
	static const VideoCodec XVID;
	static const VideoCodec FLV;
	static const VideoCodec THEORA;

private:
	VideoCodec(int i, std::string s);
};

class AudioCodec : public cpputil::Enum {
public:
	static const AudioCodec AC3;
	static const AudioCodec AAC;
	static const AudioCodec PCM_16;
	static const AudioCodec MP3;
	static const AudioCodec FLAC;
	static const AudioCodec VORBIS;

private:
	AudioCodec(int i, std::string s);
};

class ImageCodec : public cpputil::Enum {
public:
	static const ImageCodec GIF;
	static const ImageCodec JPEG;
	static const ImageCodec PNG;

private:
	ImageCodec(int i, std::string s);
};

class AspectRatio : public cpputil::Enum {
public:
	static const AspectRatio AR_4X3;
	static const AspectRatio AR_16X9;
	static const AspectRatio AR_16X10;

private:
	AspectRatio(int i, std::string s);
};

class FileFormat : public cpputil::Enum {
public:
	static const FileFormat AVI;
	static const FileFormat MP4;
	static const FileFormat AAC;
	static const FileFormat FLC;
	static const FileFormat FLAC;
	static const FileFormat H264;
	static const FileFormat MKV;
	static const FileFormat MKA;
	static const FileFormat MOV;
	static const FileFormat MP3;
	static const FileFormat MP4;
	static const FileFormat OGG;
	static const FileFormat WAV;
	static const FileFormat MPEGTS;

private:
	FileFormat(int i, std::string s);
};


}
}
}
}

#endif /* AVENCODING_H_ */

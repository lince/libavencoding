/*
 * AVEncoding.cpp
 *
 *   Created on: Oct 28, 2011
 *  Last Chance: 2:39:56 PM
 *       Author: caioviel
 *       E-mail: caio_viel@dc.ufscar.br
 */

#include "../include/AVEncoding.h"

using namespace cpputil;

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

VideoCodec::VideoCodec(int i, std::string s) : Enum(i, s) {

}

const VideoCodec VideoCodec::H264 = VideoCodec(0, "h264");
const VideoCodec VideoCodec::MPEG1_VIDEO = VideoCodec(1, "mpeg1video");
const VideoCodec VideoCodec::MPEG2_VIDEO = VideoCodec(2,"mpeg2video");
const VideoCodec VideoCodec::MPEG4 = VideoCodec(3, "mpeg4");
const VideoCodec VideoCodec::XVID = VideoCodec(4,"xvid");
const VideoCodec VideoCodec::FLV = VideoCodec(5,"flv");
const VideoCodec VideoCodec::THEORA =VideoCodec(6,"theora");

AudioCodec::AudioCodec(int i, std::string s) : Enum(i, s) {

}

const AudioCodec AudioCodec::AC3 = AudioCodec(0, "ac3");
const AudioCodec AudioCodec::AAC = AudioCodec(1, "aac");
const AudioCodec AudioCodec::PCM_16 = AudioCodec(2, "pcm16");
const AudioCodec AudioCodec::MP3 = AudioCodec(3, "mp3");
const AudioCodec AudioCodec::FLAC = AudioCodec(4, "flac");
const AudioCodec AudioCodec::VORBIS = AudioCodec(5, "vorbis");

ImageCodec::ImageCodec(int i, std::string s) : Enum(i, s) {

}

const ImageCodec ImageCodec::GIF = ImageCodec(0, "gif");
const ImageCodec ImageCodec::JPEG = ImageCodec(1, "jpeg");
const ImageCodec ImageCodec::PNG = ImageCodec(2, "png");

AspectRatio::AspectRatio(int i, std::string s) : Enum(i, s) {

}

const AspectRatio::AspectRatio AR_4X3 = AspectRatio(0, "4x3");
const AspectRatio::AspectRatio AR_16X9 = AspectRatio(1, "16x9");
const AspectRatio::AspectRatio AR_16X10 = AspectRatio(2, "16x10");

FileFormat::FileFormat(int i, std::string s) : Enum(i, s ){

}

const FileFormat FileFormat::AVI = FileFormat(0, "avi");
const FileFormat FileFormat::MP4 = FileFormat(1, "mp4");
const FileFormat FileFormat::AAC = FileFormat(2, "aac");
const FileFormat FileFormat::FLC = FileFormat(3, "flc");
const FileFormat FileFormat::MKV = FileFormat(4, "mkv");
const FileFormat FileFormat::MKA = FileFormat(5, "mka");
const FileFormat FileFormat::MOV = FileFormat(6, "mov");
const FileFormat FileFormat::MP3 = FileFormat(7, "mp3");
const FileFormat FileFormat::MP4 = FileFormat(8, "mp4");
const FileFormat FileFormat::WAV = FileFormat(9, "wac");
const FileFormat FileFormat::OGG = FileFormat(10, "ogg");
const FileFormat FileFormat::FLAC = FileFormat(11, "flac");
const FileFormat FileFormat::H264 = FileFormat(12, "h264");
const FileFormat FileFormat::MPEGTS = FileFormat(13, "mpegts");


}
}
}
}

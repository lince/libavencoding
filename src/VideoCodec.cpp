#include "VideoCodec.h"
#include <libcpputil/SimpleException.h>
#include <libcpputil/Functions.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

VideoCodec::VideoCodec() {
	this->type = types[0];
	this->str = strTypes[0];
}

VideoCodec::VideoCodec(VideoCodec::Type type) {
	this->type = type;
	this->str = typeToString(type);
}

VideoCodec::VideoCodec(const VideoCodec& obj) {
	this->type = obj.type;
	this->str = obj.str;
}

VideoCodec::VideoCodec(const std::string& str) {
	for (int i = 0; i <7; i++) {
		if (str == strTypes[i]) {
			this->type = types[i];
			this->str = strTypes[i];
			return;
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::VideoCodec",
			"VideoCodec(const string&)");
}

VideoCodec& VideoCodec::operator=(const VideoCodec& obj) {
	if (this->type != obj.type) {
		this->type = obj.type;
		this->str = obj.str;
	}
	return *this;
}

VideoCodec& VideoCodec::operator=(VideoCodec::Type type) {
	if (this->type != type) {
		this->type = type;
		this->str = typeToString(type);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const VideoCodec& obj) {	out << obj.toString();
	return out;
}

bool VideoCodec::operator==(const VideoCodec& obj) const {
	return (this->type == obj.type);
}

bool VideoCodec::operator==(VideoCodec::Type type) const {
	return (this->type == type);
}

bool VideoCodec::operator!=(const VideoCodec& obj) const {
	return (this->type != obj.type);
}

bool VideoCodec::operator!=(VideoCodec::Type type) const {
	return (this->type != type);
}

std::string VideoCodec::toString() const {
	return str;
}

VideoCodec::Type VideoCodec::getType() const {
	return type;
}

char* VideoCodec::typeToString(VideoCodec::Type type) {
	for (int i = 0; i < 8; i++) {
		if (type == types[i]) {
			return strTypes[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid VideoCodec::Type",
			"br::ufscar::lince::avencoding::VideoCodec",
			"typeToString(VideoCodec::Type)");
}

VideoCodec::Type VideoCodec::stringToType(const std::string& str) {
	std::string aux = cpputil::Functions::toUpperCase(str);
	for (int i = 0; i < 8; i++) {
		if (aux == strTypes[i]) {
			return types[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::VideoCodec",
			"stringToType(const string&)");
}

char** VideoCodec::initializeStrTypes() {
	char** aux = new char*[8];
	aux[0] = (char*) "NONE";
	aux[1] = (char*) "THEORA";
	aux[2] = (char*) "H264";
	aux[3] = (char*) "MPEG2";
	aux[4] = (char*) "MPEG1";
	aux[5] = (char*) "VP8";
	aux[6] = (char*) "XVID";
	aux[7] = (char*) "COPY";
	return aux;
}

char** VideoCodec::strTypes = VideoCodec::initializeStrTypes();

VideoCodec::Type* VideoCodec::initializeTypes() {
	VideoCodec::Type* aux = new VideoCodec::Type[8];
	aux[0] = NONE;
	aux[1] = THEORA;
	aux[2] = H264;
	aux[3] = MPEG2;
	aux[4] = MPEG1;
	aux[5] = VP8;
	aux[6] = XVID;
	aux[7] = COPY;
	return aux;
}

VideoCodec::Type* VideoCodec::types = VideoCodec::initializeTypes();

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

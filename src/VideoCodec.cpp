/**
 * File: VideoCodec.cpp
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
	for (int i = 0; i < 9; i++) {
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
	for (int i = 0; i < 9; i++) {
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
	char** aux = new char*[9];
	aux[0] = (char*) "NONE";
	aux[1] = (char*) "THEORA";
	aux[2] = (char*) "H264";
	aux[3] = (char*) "MPEG2";
	aux[4] = (char*) "MPEG1";
	aux[5] = (char*) "VP8";
	aux[6] = (char*) "XVID";
	aux[7] = (char*) "COPY";
	aux[8] = (char*) "FLV";
	return aux;
}

char** VideoCodec::strTypes = VideoCodec::initializeStrTypes();

VideoCodec::Type* VideoCodec::initializeTypes() {
	VideoCodec::Type* aux = new VideoCodec::Type[9];
	aux[0] = NONE;
	aux[1] = THEORA;
	aux[2] = H264;
	aux[3] = MPEG2;
	aux[4] = MPEG1;
	aux[5] = VP8;
	aux[6] = XVID;
	aux[7] = COPY;
	aux[8] = FLV;
	return aux;
}

VideoCodec::Type* VideoCodec::types = VideoCodec::initializeTypes();

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

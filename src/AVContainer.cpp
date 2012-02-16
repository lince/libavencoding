/**
 * File: AVContainer.cpp
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

#include "AVContainer.h"
#include <libcpputil/SimpleException.h>
#include <libcpputil/Functions.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

AVContainer::AVContainer() {
	this->type = types[0];
	this->str = strTypes[0];
}

AVContainer::AVContainer(AVContainer::Type type) {
	this->type = type;
	this->str = typeToString(type);
}

AVContainer::AVContainer(const AVContainer& obj) {
	this->type = obj.type;
	this->str = obj.str;
}

AVContainer::AVContainer(const std::string& str) {
	for (int i = 0; i <14; i++) {
		if (str == strTypes[i]) {
			this->type = types[i];
			this->str = strTypes[i];
			return;
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::AVContainer",
			"AVContainer(const string&)");
}

AVContainer& AVContainer::operator=(const AVContainer& obj) {
	if (this->type != obj.type) {
		this->type = obj.type;
		this->str = obj.str;
	}
	return *this;
}

AVContainer& AVContainer::operator=(AVContainer::Type type) {
	if (this->type != type) {
		this->type = type;
		this->str = typeToString(type);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const AVContainer& obj) {	out << obj.toString();
	return out;
}

bool AVContainer::operator==(const AVContainer& obj) const {
	return (this->type == obj.type);
}

bool AVContainer::operator==(AVContainer::Type type) const {
	return (this->type == type);
}

bool AVContainer::operator!=(const AVContainer& obj) const {
	return (this->type != obj.type);
}

bool AVContainer::operator!=(AVContainer::Type type) const {
	return (this->type != type);
}

std::string AVContainer::toString() const {
	return str;
}

AVContainer::Type AVContainer::getType() const {
	return type;
}

char* AVContainer::typeToString(AVContainer::Type type) {
	for (int i = 0; i < 16; i++) {
		if (type == types[i]) {
			return strTypes[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid AVContainer::Type",
			"br::ufscar::lince::avencoding::AVContainer",
			"typeToString(AVContainer::Type)");
}

AVContainer::Type AVContainer::stringToType(const std::string& str) {
	std::string aux = cpputil::Functions::toUpperCase(str);
	for (int i = 0; i < 16; i++) {
		if (aux == strTypes[i]) {
			return types[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::AVContainer",
			"stringToType(const string&)");
}

char** AVContainer::initializeStrTypes() {
	char** aux = new char*[16];
	aux[0] = (char*) "NONE";
	aux[1] = (char*) "MPEG";
	aux[2] = (char*) "AVI";
	aux[3] = (char*) "MP4";
	aux[4] = (char*) "OGG";
	aux[5] = (char*) "WEBM";
	aux[6] = (char*) "FLV";
	aux[7] = (char*) "MKV";
	aux[8] = (char*) "MP3";
	aux[9] = (char*) "AAC";
	aux[10] = (char*) "WAV";
	aux[11] = (char*) "OGA";
	aux[12] = (char*) "FLA";
	aux[13] = (char*) "MKA";
	aux[14] = (char*) "MOV";
	aux[15] = (char*) "AC3";;
	return aux;
}

char** AVContainer::strTypes = AVContainer::initializeStrTypes();

AVContainer::Type* AVContainer::initializeTypes() {
	AVContainer::Type* aux = new AVContainer::Type[16];
	aux[0] = NONE;
	aux[1] = MPEG;
	aux[2] = AVI;
	aux[3] = MP4;
	aux[4] = OGG;
	aux[5] = WEBM;
	aux[6] = FLV;
	aux[7] = MKV;
	aux[8] = MP3;
	aux[9] = AAC;
	aux[10] = WAV;
	aux[11] = OGA;
	aux[12] = FLA;
	aux[13] = MKA;
	aux[14] = MOV;
	aux[15] = AC3;
	return aux;
}

AVContainer::Type* AVContainer::types = AVContainer::initializeTypes();

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

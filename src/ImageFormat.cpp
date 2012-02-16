/**
 * File: ImageFormat.cpp
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

#include "ImageFormat.h"
#include <libcpputil/SimpleException.h>
#include <libcpputil/Functions.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

ImageFormat::ImageFormat() {
	this->type = types[0];
	this->str = strTypes[0];
}

ImageFormat::ImageFormat(ImageFormat::Type type) {
	this->type = type;
	this->str = typeToString(type);
}

ImageFormat::ImageFormat(const ImageFormat& obj) {
	this->type = obj.type;
	this->str = obj.str;
}

ImageFormat::ImageFormat(const std::string& str) {
	for (int i = 0; i <5; i++) {
		if (str == strTypes[i]) {
			this->type = types[i];
			this->str = strTypes[i];
			return;
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::ImageFormat",
			"ImageFormat(const string&)");
}

ImageFormat& ImageFormat::operator=(const ImageFormat& obj) {
	if (this->type != obj.type) {
		this->type = obj.type;
		this->str = obj.str;
	}
	return *this;
}

ImageFormat& ImageFormat::operator=(ImageFormat::Type type) {
	if (this->type != type) {
		this->type = type;
		this->str = typeToString(type);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const ImageFormat& obj) {	out << obj.toString();
	return out;
}

bool ImageFormat::operator==(const ImageFormat& obj) const {
	return (this->type == obj.type);
}

bool ImageFormat::operator==(ImageFormat::Type type) const {
	return (this->type == type);
}

bool ImageFormat::operator!=(const ImageFormat& obj) const {
	return (this->type != obj.type);
}

bool ImageFormat::operator!=(ImageFormat::Type type) const {
	return (this->type != type);
}

std::string ImageFormat::toString() const {
	return str;
}

ImageFormat::Type ImageFormat::getType() const {
	return type;
}

char* ImageFormat::typeToString(ImageFormat::Type type) {
	for (int i = 0; i < 5; i++) {
		if (type == types[i]) {
			return strTypes[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid ImageFormat::Type",
			"br::ufscar::lince::avencoding::ImageFormat",
			"typeToString(ImageFormat::Type)");
}

ImageFormat::Type ImageFormat::stringToType(const std::string& str) {
	std::string aux = cpputil::Functions::toUpperCase(str);
	for (int i = 0; i < 5; i++) {
		if (aux == strTypes[i]) {
			return types[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::ImageFormat",
			"stringToType(const string&)");
}

char** ImageFormat::initializeStrTypes() {
	char** aux = new char*[5];
	aux[0] = (char*) "NONE";
	aux[1] = (char*) "PNG";
	aux[2] = (char*) "JPEG";
	aux[3] = (char*) "GIF";
	aux[4] = (char*) "TIFF";
	return aux;
}

char** ImageFormat::strTypes = ImageFormat::initializeStrTypes();

ImageFormat::Type* ImageFormat::initializeTypes() {
	ImageFormat::Type* aux = new ImageFormat::Type[5];
	aux[0] = NONE;
	aux[1] = PNG;
	aux[2] = JPEG;
	aux[3] = GIF;
	aux[4] = TIFF;
	return aux;
}

ImageFormat::Type* ImageFormat::types = ImageFormat::initializeTypes();

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

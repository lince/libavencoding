/**
 * File: AspectRatio.cpp
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

#include "AspectRatio.h"
#include <libcpputil/SimpleException.h>
#include <libcpputil/Functions.h>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

AspectRatio::AspectRatio() {
	this->type = types[0];
	this->str = strTypes[0];
}

AspectRatio::AspectRatio(AspectRatio::Type type) {
	this->type = type;
	this->str = typeToString(type);
}

AspectRatio::AspectRatio(const AspectRatio& obj) {
	this->type = obj.type;
	this->str = obj.str;
}

AspectRatio::AspectRatio(const std::string& str) {
	for (int i = 0; i <3; i++) {
		if (str == strTypes[i]) {
			this->type = types[i];
			this->str = strTypes[i];
			return;
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::AspectRatio",
			"AspectRatio(const string&)");
}

AspectRatio& AspectRatio::operator=(const AspectRatio& obj) {
	if (this->type != obj.type) {
		this->type = obj.type;
		this->str = obj.str;
	}
	return *this;
}

AspectRatio& AspectRatio::operator=(AspectRatio::Type type) {
	if (this->type != type) {
		this->type = type;
		this->str = typeToString(type);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const AspectRatio& obj) {	out << obj.toString();
	return out;
}

bool AspectRatio::operator==(const AspectRatio& obj) const {
	return (this->type == obj.type);
}

bool AspectRatio::operator==(AspectRatio::Type type) const {
	return (this->type == type);
}

bool AspectRatio::operator!=(const AspectRatio& obj) const {
	return (this->type != obj.type);
}

bool AspectRatio::operator!=(AspectRatio::Type type) const {
	return (this->type != type);
}

std::string AspectRatio::toString() const {
	return str;
}

AspectRatio::Type AspectRatio::getType() const {
	return type;
}

char* AspectRatio::typeToString(AspectRatio::Type type) {
	for (int i = 0; i < 3; i++) {
		if (type == types[i]) {
			return strTypes[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid AspectRatio::Type",
			"br::ufscar::lince::avencoding::AspectRatio",
			"typeToString(AspectRatio::Type)");
}

AspectRatio::Type AspectRatio::stringToType(const std::string& str) {
	std::string aux = cpputil::Functions::toUpperCase(str);
	for (int i = 0; i < 3; i++) {
		if (aux == strTypes[i]) {
			return types[i];
		}
	}
	throw cpputil::SimpleException(
			"Trying to convert a invalid string: " + str,
			"br::ufscar::lince::avencoding::AspectRatio",
			"stringToType(const string&)");
}

char** AspectRatio::initializeStrTypes() {
	char** aux = new char*[3];
	aux[0] = (char*) "NONE";
	aux[1] = (char*) "AR_4X3";
	aux[2] = (char*) "AR_16X9";
	return aux;
}

char** AspectRatio::strTypes = AspectRatio::initializeStrTypes();

AspectRatio::Type* AspectRatio::initializeTypes() {
	AspectRatio::Type* aux = new AspectRatio::Type[3];
	aux[0] = NONE;
	aux[1] = AR_4X3;
	aux[2] = AR_16X9;
	return aux;
}

AspectRatio::Type* AspectRatio::types = AspectRatio::initializeTypes();

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

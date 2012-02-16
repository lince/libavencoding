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

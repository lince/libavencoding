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
	for (int i = 0; i < 14; i++) {
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
	for (int i = 0; i < 14; i++) {
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
	char** aux = new char*[14];
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
	return aux;
}

char** AVContainer::strTypes = AVContainer::initializeStrTypes();

AVContainer::Type* AVContainer::initializeTypes() {
	AVContainer::Type* aux = new AVContainer::Type[14];
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
	return aux;
}

AVContainer::Type* AVContainer::types = AVContainer::initializeTypes();

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

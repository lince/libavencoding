/**
 * File: AVContainer.h
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

#ifndef AVContainer_H_
#define AVContainer_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * A class that wrappers the AVContainer enumeration options.
 */
class AVContainer{
public:
	enum Type {
		NONE=0, // Demuxer, Muxer
		MPEG, // mpeg, mpeg				Checked
		AVI, // avi, avi				Checked
		MP4, // _, mp4 -> 				Checked
		OGG, // ogg, ogg				Checked
		WEBM, // _, webm -> 			Checked
		FLV, // flv, flc				Checked
		MKV, // matroska, matroska		Checked
		MP3, // mp3, mp3				Checked
		AAC, // aac, adts				Checked
		WAV, // wav, wav				Checked
		OGA, //ogg, ogg					Checked
		FLA, // flac, flac				Checked
		MKA, // _, matroska_audio		Checked
		MOV, // mov, mov				Checked
		AC3, // ac3, ac3				Checked*
	};

public:
	//Default constructor will use the first element of the enumeration for initializations
	AVContainer();
	AVContainer(AVContainer::Type type);
	AVContainer(const AVContainer& obj);
	AVContainer(const std::string& str);

	AVContainer& operator=(const AVContainer& obj);
	AVContainer& operator=(AVContainer::Type type);

	bool operator==(const AVContainer& obj) const;
	bool operator==(AVContainer::Type type) const;

	bool operator!=(const AVContainer& obj) const;
	bool operator!=(AVContainer::Type type) const;

	friend std::ostream& operator<<(std::ostream &out,
			const AVContainer& obj);

	std::string toString() const;
	AVContainer::Type getType() const;

private:
	AVContainer::Type type;
	char* str;

	static char** initializeStrTypes();
	static char** strTypes;
	static AVContainer::Type* initializeTypes();
	static AVContainer::Type* types;

	static char* typeToString(AVContainer::Type);
	static AVContainer::Type stringToType(const std::string& str);

};

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

#endif /* AVContainer_H_ */

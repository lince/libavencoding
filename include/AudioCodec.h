/**
 * File: AudioCodec.h
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

#ifndef AudioCodec_H_
#define AudioCodec_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

//TODO: Add fla audio

/**
 * A class that wrappers the AudioCodec enumeration options.
 */
class AudioCodec{
public:
	enum Type {
		NONE=0,
		VORBIS, //libvorbis -> 			Checked
		PCM16, //pcm_u16le				Checked
		PCM32, //pcm_u32le				Checked
		AAC, //libfaac -> 				Checked
		AC3, //ac3						Checked
		MP3, //libmp3lame				Checked
		COPY, //						Checked
		FLAC, //flac					Checked*
	};

public:
	//Default constructor will use the first element of the enumeration for initializations
	AudioCodec();
	AudioCodec(AudioCodec::Type type);
	AudioCodec(const AudioCodec& obj);
	AudioCodec(const std::string& str);

	AudioCodec& operator=(const AudioCodec& obj);
	AudioCodec& operator=(AudioCodec::Type type);

	bool operator==(const AudioCodec& obj) const;
	bool operator==(AudioCodec::Type type) const;

	bool operator!=(const AudioCodec& obj) const;
	bool operator!=(AudioCodec::Type type) const;

	friend std::ostream& operator<<(std::ostream &out,
			const AudioCodec& obj);

	std::string toString() const;
	AudioCodec::Type getType() const;

private:
	AudioCodec::Type type;
	char* str;

	static char** initializeStrTypes();
	static char** strTypes;
	static AudioCodec::Type* initializeTypes();
	static AudioCodec::Type* types;

	static char* typeToString(AudioCodec::Type);
	static AudioCodec::Type stringToType(const std::string& str);

};

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

#endif /* AudioCodec_H_ */

/**
 * File: VideoCodec.h
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

#ifndef VideoCodec_H_
#define VideoCodec_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * A class that wrappers the VideoCodec enumeration options.
 */
class VideoCodec{
public:
	enum Type {
		NONE,
		THEORA, //libtheora -> 			Checked
		H264, //libx264 -> 				Checked
		MPEG2, //mpeg2video -> 			Checked
		MPEG1, //mpeg1video ->			Checked
		VP8, //libvpx ->				Checked
		XVID, //libxvid ->				Checked
		COPY, //						Checked
		FLV, //FLV						Checked*
	};

public:
	//Default constructor will use the first element of the enumeration for initializations
	VideoCodec();
	VideoCodec(VideoCodec::Type type);
	VideoCodec(const VideoCodec& obj);
	VideoCodec(const std::string& str);

	VideoCodec& operator=(const VideoCodec& obj);
	VideoCodec& operator=(VideoCodec::Type type);

	bool operator==(const VideoCodec& obj) const;
	bool operator==(VideoCodec::Type type) const;

	bool operator!=(const VideoCodec& obj) const;
	bool operator!=(VideoCodec::Type type) const;

	friend std::ostream& operator<<(std::ostream &out,
			const VideoCodec& obj);

	std::string toString() const;
	VideoCodec::Type getType() const;

private:
	VideoCodec::Type type;
	char* str;

	static char** initializeStrTypes();
	static char** strTypes;
	static VideoCodec::Type* initializeTypes();
	static VideoCodec::Type* types;

	static char* typeToString(VideoCodec::Type);
	static VideoCodec::Type stringToType(const std::string& str);

};

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

#endif /* VideoCodec_H_ */

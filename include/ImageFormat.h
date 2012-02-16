/**
 * File: ImageFormat.h
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

#ifndef ImageFormat_H_
#define ImageFormat_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * A class that wrappers the ImageFormat options.
 */
class ImageFormat{
public:
	enum Type {
		NONE=0,
		PNG, //png
		JPEG, //mjpeg
		GIF, //gif
		TIFF, //tiff
	};

public:
	//Default constructor will use the first element of the enumeration for initializations
	ImageFormat();
	ImageFormat(ImageFormat::Type type);
	ImageFormat(const ImageFormat& obj);
	ImageFormat(const std::string& str);

	ImageFormat& operator=(const ImageFormat& obj);
	ImageFormat& operator=(ImageFormat::Type type);

	bool operator==(const ImageFormat& obj) const;
	bool operator==(ImageFormat::Type type) const;

	bool operator!=(const ImageFormat& obj) const;
	bool operator!=(ImageFormat::Type type) const;

	friend std::ostream& operator<<(std::ostream &out,
			const ImageFormat& obj);

	std::string toString() const;
	ImageFormat::Type getType() const;

private:
	ImageFormat::Type type;
	char* str;

	static char** initializeStrTypes();
	static char** strTypes;
	static ImageFormat::Type* initializeTypes();
	static ImageFormat::Type* types;

	static char* typeToString(ImageFormat::Type);
	static ImageFormat::Type stringToType(const std::string& str);

};

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

#endif /* ImageFormat_H_ */

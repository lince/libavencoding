/**
 * File: AspectRatio.h
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

#ifndef AspectRatio_H_
#define AspectRatio_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * A class that wrappers the AspectRatio enumeration options.
 */
class AspectRatio{
public:
	enum Type {
		NONE=0,
		AR_4X3,
		AR_16X9,
	};

public:
	//Default constructor will use the first element of the enumeration for initializations
	AspectRatio();
	AspectRatio(AspectRatio::Type type);
	AspectRatio(const AspectRatio& obj);
	AspectRatio(const std::string& str);

	AspectRatio& operator=(const AspectRatio& obj);
	AspectRatio& operator=(AspectRatio::Type type);

	bool operator==(const AspectRatio& obj) const;
	bool operator==(AspectRatio::Type type) const;

	bool operator!=(const AspectRatio& obj) const;
	bool operator!=(AspectRatio::Type type) const;

	friend std::ostream& operator<<(std::ostream &out,
			const AspectRatio& obj);

	std::string toString() const;
	AspectRatio::Type getType() const;

private:
	AspectRatio::Type type;
	char* str;

	static char** initializeStrTypes();
	static char** strTypes;
	static AspectRatio::Type* initializeTypes();
	static AspectRatio::Type* types;

	static char* typeToString(AspectRatio::Type);
	static AspectRatio::Type stringToType(const std::string& str);

};

} /* namespace br */
} /* namespace ufscar */
} /* namespace lince */
} /* namespace avencoding */

#endif /* AspectRatio_H_ */

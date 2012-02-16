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

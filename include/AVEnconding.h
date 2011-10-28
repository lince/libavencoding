#include <string>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

class MyEnum {
protected:
	int id;
	std::string str;

	MyEnum(int id, std::string str);

};

class ImageCodec {
public:
	static const ImageCodec* MJPEG;
	static const ImageCodec* GIF;
	static const ImageCodec* PNG;
	static ImageCodec* parseString(std::string str);

	std::string toStr();

private:
	ImageCodec(int id, std::string str);
	~ImageCodec() {}

	int id;
	std::string str;

};

class VideoCodec {

};

class AudioCodec {

};

class AVFormat {

};

}
}
}
}

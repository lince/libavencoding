#ifndef AudioCodec_H_
#define AudioCodec_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

class AudioCodec{
public:
	enum Type {
		NONE=0,
		VORBIS, //libvorbis
		PCM16, //pcm_u16le
		PCM32, //pcm_u32le
		AAC, //libfaac
		AC3, //ac3
		MP3, //libmp3lame
		COPY,
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

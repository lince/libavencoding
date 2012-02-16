#ifndef AVContainer_H_
#define AVContainer_H_

#include <string>
#include <iostream>

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

class AVContainer{
public:
	enum Type {
		NONE=0,
		MPEG,
		AVI,
		MP4,
		OGG,
		WEBM,
		FLV,
		MKV,
		MP3,
		AAC,
		WAV,
		OGA,
		FLA,
		MKA,
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
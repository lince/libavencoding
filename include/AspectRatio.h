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

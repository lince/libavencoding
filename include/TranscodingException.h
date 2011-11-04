#ifndef TRANSCODINGEXCEPTION_H_
#define	TRANSCODINGEXCEPTION_H_

#include <libcpputil/SimpleException.h>

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

class TranscodingException : public cpputil::SimpleException {
public:
	TranscodingException(std::string e, std::string c, std::string m) :
		cpputil::SimpleException (e, c, m){

		setExceptionSign("avencoding::TranscodingException");
	}

	TranscodingException(std::string e) : cpputil::SimpleException(e) {
		setExceptionSign("avencoding::TranscodingException");
	}
};

}
}
}
}

#endif	/* TRANSCODINGEXCEPTION_H_ */


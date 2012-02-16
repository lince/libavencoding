#ifndef TRANSCODINGEXCEPTION_H_
#define	TRANSCODINGEXCEPTION_H_

#include <libcpputil/SimpleException.h>

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

/**
 * Exception throwed when some error occurs during the transcoding process.
 */
class TranscodingException : public cpputil::SimpleException {
public:

	/**
	 * Complete Constructor.
	 * @param e The raw error message.
	 * @param c The class where the exception occurs.
	 * @param m The method where the exception was throwed.
	 */
	TranscodingException(std::string e, std::string c, std::string m) :
		cpputil::SimpleException (e, c, m){

		setExceptionSign("br::ufscar::lince::avencoding::TranscodingException");
	}

	/**
	 * Simple Constructor.
	 * The values to class and method will be omitted.
	 * @param e The raw error message.
	 */
	TranscodingException(std::string e) : cpputil::SimpleException(e) {
		setExceptionSign("br::ufscar::lince::avencoding::TranscodingException");
	}
};

}
}
}
}

#endif	/* TRANSCODINGEXCEPTION_H_ */


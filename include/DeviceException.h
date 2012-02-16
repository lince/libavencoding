/*
 * DeviceException.h
 *
 *  Created on: Mar 9, 2011
 *      Author: caioviel
 */

#ifndef DEVICEEXCEPTION_H_
#define DEVICEEXCEPTION_H_

#include <libcpputil/SimpleException.h>
#include <string>

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

/**
 * Exception that can be throwed when some errors occurs using the DeviceInterface
 * @see DeviceIntreface
 */
class DeviceException : public cpputil::SimpleException {
public:

	/**
	 * Constructor
	 * @param e The raw error message.
	 * @param c The class where the exception occurs.
	 * @param m The method where the exception was throwed.
	 */
	DeviceException(std::string e, std::string c, std::string m) :
			cpputil::SimpleException (e, c, m) {

		setExceptionSign("br::ufscar::lince::avencoding::DeviceException");
	}
};

}
}
}
}


#endif /* DEVICEEXCEPTION_H_ */

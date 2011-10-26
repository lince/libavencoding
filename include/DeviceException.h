/*
 * DeviceException.h
 *
 *  Created on: Mar 9, 2011
 *      Author: caioviel
 */

#ifndef DEVICEEXCEPTION_H_
#define DEVICEEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

namespace br{
namespace ufscar{
namespace lince{
namespace avenconding{

class DeviceException : public exception {
public:
	DeviceException(string m="Device Exception!");
	~DeviceException() throw();
	const char* what() const throw();

private:
	string msg;
};

}
}
}
}


#endif /* DEVICEEXCEPTION_H_ */

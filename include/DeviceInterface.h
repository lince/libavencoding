#ifndef DEVICEINTERFACE_H_
#define DEVICEINTERFACE_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

#include <libcpputil/logger/Logger.h>

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

/**
 * Provide a interface with the a virtual Device created in memory.
 * This class provide a interface with the shared buffer created in local memory
 * to allow the application communicate with the coding process, sending its image
 * frames.
 */
class DeviceInterface : public cpputil::logger::Loggable {
public:
	/**
	 * This methods returns the unique instance of the DeviceInterface.
	 * @return Pointer to the DeviceInterface singleton.
	 */
	static DeviceInterface* getInstance();

	/**
	 * This method can be used to mounted and define the characteristics of device.
	 * @param width The width of the images that will be generated by the device.
	 * @param height The height of the images that will be generated by the device.
	 * @param bitsPerPixel The number of bits per pixel from the images fo the device.
	 * @param fps Number the frames per second generated by the device.
	 * @throw IllegalParameterException When one or more parameters are invalid.
	 */
	virtual void mount(int width, int height, int bitsPerPixel, int fps);

	/**
	 * This method can be used to destroy the device.
	 */
	virtual void release();

	/**
	 * This method can be used to put a new image in the device without
	 * pixel format conversion.
	 * @param buffer The buffer that contains the image.
	 */
	virtual void putBuffer1(unsigned char* buffer);

	/**
	 * This method can be used to put a new image in the device
	 * with pixel format conversion.
	 * @param buffer The buffer that contains the image.
	 */
	virtual void putBuffer2(unsigned char* buffer);

	/**
	 * This method can be used to put a new image in the device
	 * with pixel format conversion.
	 * @param buffer The buffer that contains the image.
	 */
	virtual void putBuffer3(unsigned char* buffer);

	virtual void putBuffer4(unsigned char* buffer);

	/**
	 * This method returns the width of the device.
	 * @return width of the device
	 */
	virtual int getWidth();

	/**
	 * This method returns the height of the device.
	 * @return height of the device
	 */
	virtual int getHeight();

	/**
	 * This method returns the frames per second frequency of the device
	 * @return frames per second frequency of the device
	 */
	virtual int getFPS();

	/**
	 * This method returns the number bits per pixel of the device.
	 * @return number bits per pixel of the device
	 */
	virtual int getBitsPerPixel();

	/*
	virtual void registerImageProvider(ImageProvider* ImageProvider);
	*/

protected:
	/**
	 * This internal method is used to protect the device, barring alterations on its content.
	 * The content will be protect until the method unlock is called.
	 */
	void lock();

	/**
	 * This internal method is used to disable the protection the device,
	 * allow alterations on its contest.
	 * The content will be unprotected until the method lock is called.
	 */
	void unlock();

	/**
	 * This internal method export the characteristics of the device in a shared
	 * memory, allowing external process interact with the shared buffer.
	 */
	void initDeviceInfo();

private:
	static DeviceInterface* _instance;
	DeviceInterface();
	virtual ~DeviceInterface();

	bool unmounted;
	int shmid;
	int semid;
	unsigned char* shmdata;
	int fps;
	int shmsize;
	int width;
	int height;
	int bitsPerPixel;
};

}
}
}
}

#endif /* DEVICEINTERFACE_H_ */

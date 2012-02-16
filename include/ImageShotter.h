/*
 * ImageShotter.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef IMAGESHOTTER_H_
#define IMAGESHOTTER_H_

#include <string>

#include <libcpputil/logger/Loggable.h>
#include <libcpputil/Thread.h>
#include <libcpputil/InitializationException.h>
#include <libcpputil/IllegalParameterException.h>
#include <libcpputil/NotImplementedException.h>

#include "AVSource.h"
#include "Transcoder.h"
#include "ImageFormat.h"
#include "TranscodingException.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * This class can take shots of video sources and save then into files.
 * It can use video files or devices such as X11Terminal as sources.
 * You can take snapshots of determinate points by informing the time in seconds,
 * Also, It's possible to resize the snapshot before save it.
 */
class ImageShotter : public Transcoder,
					 protected cpputil::Thread,
					 public cpputil::logger::Loggable {
public:
	/**
	 * Constructor
	 * If format is omitted, it will be used ImageFormat::JPEG as default.
	 * @param source The source of the images.
	 * @param format The format desired to images that will be generated.
	 * @throw IllegalParameterException if source is NULL.
	 */
	ImageShotter(AVSource* source, ImageFormat format = ImageFormat::JPEG);

	/**
	 * Virtual Destructor.
	 * It will delete the AVSource* instance passed as parameter into the constructor.
	 */
	virtual ~ImageShotter();

	/**
	 * Take a shot of the actual state of the source and save in a file.
	 * This method create a thread that will proceed with snapeshot and transcoding process.
	 * Some the exceptions are throwed by the thread.
	 * For AVInputFile's source, the actual state is considered the first frame.
	 * @param filename The name of the file that will be create.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 */
	void takeShot(std::string filename);

	/**
	 * Take a shot of the specific moment of the source and save in a file.
	 * This method create a thread that will proceed with snapeshot and transcoding process.
	 * Some the exceptions are throwed by the thread.
	 * For real-time devices's source, the time informed will be counted from the current moment,
	 * is the same as a delayed shot.
	 * @param filename The name of the file that will be create.
	 * @param time The moment of the shot in seconds counted from the begin.
	 * @throw IllegalParameterException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 */
	void takeShot(std::string filename, int time);

	/**
	 * Take a shot of the specific moment of the source and save in a file.
	 * This method create a thread that will proceed with snapeshot and transcoding process.
	 * Some the exceptions are throwed by the thread.
	 * For real-time devices's source, the time informed will be counted from the current moment,
	 * is the same as a delayed shot.
	 * @param filename The name of the file that will be create.
	 * @param time a string in the format "HH:MM:SS" or in seconds with the moment of the shot.
	 * @throw IllegalParameterException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 */
	void takeShot(std::string filename, std::string time);

	/**
	 * This methods set the size of the captured images.
	 * If both parameters are 0, the ImageShotter will not perform resize.
	 * @param width The width of the images.
	 * @param height The height of the Images.
	 * @throw IllegalParameterException when parameters informed are wrong or invalids.
	 */
	void setImageSize(int width, int heigh);

	/**
	 * Return the width of the captured images.
	 * @return width
	 */
	int getImageWidht();

	/**
	 * Return the height of the captured images.
	 * @return height
	 */
	int getImageHeight();

	/**
	 * This methods set the image format used during the transcoding process.
	 * @param format the image format, defined by the enumeration ImageFormat.
	 * @see ImageFormat.
	 */
	void setImageFormat(ImageFormat format);

	/**
	 * This methods set the image format used during the transcoding process.
	 * @param str String that represents a image format.
	 * @throw IllegalParameterException When codec is bad formated or a invalid image format.
	*/
	void setImageFormat(std::string str);

	/**
	 * This method returns the current image format.
	 * @return A value from enumeration ImageFormat that represents the current image format.
	 * @see ImageFormat
	 */
	ImageFormat getImageFormat();

	/**
	 * This method returns true if the transcoding process is finished.
	 * It can be used to create a non-block program, that will not sleep until the coding
	 * is finished.
	 * @return True if the transcoding process is finished; false otherwise.
	 */
	bool isFinished();

	/**
	 * This method waits until the transcoding process is finished.
	 * It can be used to create a block program, that will sleep until the coding is finished.
	 * @throw InitializationException when the transcoding process hasn't begun.
	 */
	void waitFinishing();

	virtual double getCurrentTime();

private:
	void run();

	AVSource* source;
	int height;
	int width;
	void* ffrapper;
	bool settedTime;
	std::string time;
	std::string filename;
	ImageFormat imageFormat;

	bool finished;
	bool started;
};

}
}
}
}

#endif /* IMAGESHOTTER_H_ */

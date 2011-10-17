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
using namespace std;

#include <cpputil/Thread.h>
using namespace cpputil;

#include "AVSource.h"
#include "Transcoder.h"

namespace br {
namespace ufscar {
namespace lince {
namespace streaming {

/**
 * Enumeration with the image codecs supported.
 * 	- MJPEG The mjpeg (jpg) image codec.
 *  - GIF The gif image codec.
 */
enum ImageCodec {MJPEG=1, GIF};

/**
 * This class can take shots of video sources.
 */
class ImageShotter : public Transcoder, protected Thread {
public:
	/**
	 * Constructor
	 * @param source The source of the images.
	 */
	ImageShotter(AVSource* source);

	/**
	 * Virtual Destructor
	 */
	virtual ~ImageShotter();

	/**
	 * Take a shot of the actual state of the source and save in a file.
	 * This method create a thread that will handle with shot and transcoding process.
	 * For AVInputFile's source, the actual state is considered the first frame.
	 * @param filename The name of the file that will be create.
	 * @throw OptionException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 */
	void takeShot(string filename);

	/**
	 * Take a shot of the specific moment of the source and save in a file.
	 * This method create a thread that will handle with shot and transcoding process.
	 * For real-time devices's source, the time informed will be counted from the current moment,
	 * is the same as a delayed shot.
	 * @param filename The name of the file that will be create.
	 * @param time The moment of the shot in seconds counted from the begin.
	 * @throw OptionException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 */
	void takeShot(string filename, int time);

	/**
	 * Take a shot of the specific moment of the source and save in a file.
	 * This method create a thread that will handle with shot and transcoding process.
	 * For real-time devices's source, the time informed will be counted from the current moment,
	 * is the same as a delayed shot.
	 * @param filename The name of the file that will be create.
	 * @param time a string in the format "HH:MM:SS" with the moment of the shot.
	 * @throw OptionException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 */
	void takeShot(string filename, string time);

	/**
	 * This methods set the size of the captured images.
	 * @param width The width of the images.
	 * @param height The height of the Images.
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
	 * This methods set the image codec used during the transcoding process.
	 * @param codec the image codec, defined by the enumeration ImageCodec.
	 * @see ImageCodec.
	 */
	void setImageCodec(ImageCodec codec);

	/**
	 * This methods set the image codec used during the transcoding process.
	 * @param codec String that represents a image codec.
	 * @throw IllegalParameterException When codec is bad formated or a invalid image codec.
	*/
	void setImageCodec(string codec);

	/**
	 * This method returns the current image codec.
	 * @return A value from enumeration ImageCodec that represents the current image codec.
	 * @see AspectRatio
	 */
	ImageCodec getImageCodec();

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
	 * @throw InitializationException when the transcoding process hasn't begun.
	 */
	void waitFinishing();

private:
	void run();

	AVSource* source;
	int height;
	int width;
	void* ffrapper;
	bool settedTime;
	string time;
	string filename;
	ImageCodec codec;

	bool finished;
	bool started;
};

}
}
}
}

#endif /* IMAGESHOTTER_H_ */

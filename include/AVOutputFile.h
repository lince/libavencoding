/*
 * AVOutoutFile.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef AVOUTPUTFILE_H_
#define AVOUTPUTFILE_H_

#include <vector>

#include <libcpputil/Thread.h>
#include <libcpputil/InitializationException.h>
#include <libcpputil/IllegalParameterException.h>
#include <libcpputil/logger/Logger.h>

#include "Transcoder.h"
#include "AVContainer.h"
#include "TranscodingException.h"

namespace br {
namespace ufscar {
namespace lince {
namespace avencoding {

/**
 * This class is used to generate a audio/video output file as result of a transcoding process.
 * It implements the abstract class Transcoder.
 */
class AVOutputFile: public Transcoder, public cpputil::Thread,
					public cpputil::logger::Loggable {

public:
	/**
	 * Construtor
	 * @param filename the name of the file that will be generated.
	 * @param format the format of the fila that will be generated.
	 */
	AVOutputFile(std::string filename, AVContainer container = AVContainer::NONE, bool fileOverwrite=false);

	/**
	 * Virtual Destructor
	 * It will delete all the AVSource and AVEncoder associated.
	 */
	virtual ~AVOutputFile();

	/**
	 * Return the name of the file that will be generate.
	 * @param the name of the file.
	 */
	std::string getFilename();

	/**
	 * Abort the transcoding process.
	 * @throw InitializationException if the process hasn't begun.
	 */
	void stop();

	/**
	 * Start the transcoding and streaming process.
	 * This method should be called after the streaming and transcoding process was defined.
	 * It creates a new theard that will process with the process.
	 * Some of the exceptions are throwed by the thread.
	 * @throw InitializationException if no stream was add.
	 * @throw IllegalParameterException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 * @see addStream
	 */
	virtual void start();

	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * @param stream the audio-video stream.
	 */
	void addStream(AVEncoder* stream);

	/**
	 * Returns the container that will be used to generate the audio/video file.
	 * @return The container.
	 */
	AVContainer getContainer();

	virtual double getCurrentTime();

	virtual bool isFinished();

	virtual void waitFinishing();

protected:
	bool finished;
	bool started;

private:
	void run();
	std::vector<AVSource*>* sources;
	std::vector<AVEncoder*>* encoders;
	std::string filename;

	bool fileOverwrite;
	AVContainer container;
};

}
}
}
}

#endif /* AVOUTPUTFILE_H_ */

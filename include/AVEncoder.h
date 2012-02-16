/*
 * AVEncoder.h
 *
 *  Last Change: Oct 6, 2010
 *       Author: Caio César Viel
 *        Email: caio_viel@comp.ufscar.br
 */

#ifndef AVENCODER_H
#define AVENCODER_H

#include <string>
#include <map>

#include <libcpputil/InitializationException.h>
#include <libcpputil/IllegalParameterException.h>
#include <libcpputil/NotImplementedException.h>

#include "AVSource.h"
#include "AudioCodec.h"
#include "VideoCodec.h"
#include "AspectRatio.h"

namespace br{
namespace ufscar{
namespace lince{
namespace avencoding{

class Transcoder;

/**
 * This class is used to define the video and audio coding parameters of some audio and
 * video source.
 *
 * An AVEnconder's instance can represent a single audio or video stream, coded
 * with the parameters specified by its methods. Each instance is associated with
 * a instance of AVSource. An AVEnconder can be multiplexing in a
 * instance and streamed by a instance of a Streaming. It also can be used to generate a output
 * file by a AVOutputfile's instance.
 */
class AVEncoder {

	/**
	 * This class is a friend of Transcoder because transcoder need to call the
	 * configure AVEncoder's method to processed with the transcoding process.
	 */
	friend class Transcoder;

public:
	/**
	 * AVSource Constructor
	 * Initialize the codecs with the default values and define the AVSource that
	 * that will be coding.
	 * If the streamId is omitted, it will be use used the first stream.
	 * @param avSource the audio/video source.
	 * @param streamId The id of the stream that will be considered during the transcoding process.
	 * @throw InitializationException if avSource is NULL.
	 */
	AVEncoder(AVSource* avSource, int streamId=-1);

	/**
	 * Copy Constructor
	 * Initialize the codecs with the values of other AVEnconder
	 * @param copyEncoder AVEnconder instance that will be used to initialize the new one.
	 */
	AVEncoder(AVEncoder* copyAVEncoder);

	/**
	 * Default Destructor
	 */
	virtual ~AVEncoder();

	/*Video coding parameters*/

	/**
	 * This method defines the Video bit rate.
	 * The video codec try to achieve the specified value, but no bit rate value is guaranteed.
	 * @param videoBitrate the value that will be used to set the bit rate.
	 * @throw IllegalParameterException When videoBitrate is a invalid video bitrate value.
	 */
	void setVideoBitrate(int videoBitrate);

	/**
	 * This method returns the current video bit rate defined.
	 * @return current Video bit rate.
	 */
	int getVideoBitrate();

	/**
	 * This method defines the number of frames per second of the video.
	 * If a zero ou negative value is informed, the value 1 is used instead.
	 * @param fps value that will be used to set the video frames per second.
	 * @throw IllegalParameterException When fps is a invalid video frames per second value.
	 */
	void setFramesPerSecond(int fps);

	/**
	 * This method returns the current video number of frames per second.
	 * @return Current number of frames per second.
	 */
	int getFramesPerSecond();

	/**
	 * This method defines the video aspect ratio.
	 * @param aspectRatio the video aspect ratio, defined by the enumeration AspectRatio.
	 * @see AspectRatio.
	 */
	void setAspectRatio(AspectRatio aspectRatio);

	/**
	 * This method defines the video aspect ratio.
	 * @param aspectRatio String that represents a aspect ratio. Must follow the pattern "X:Y", like "4:3".
	 * @throw IllegalParameterException When aspectRatio is bad formated or a invalid aspect ratio value.
	 */
	void setAspectRatio(std::string aspectRatio);

	/**
	 * This method returns the current video aspect ratio.
	 * @return A value from enumeration AspectRatio that represents the current video aspect ratio.
	 * @see AspectRatio
	 */
	AspectRatio getAspectRatio();

	/**
	 * This method defines the video size
	 * @param width The width of the video in pixels.
	 * @param height The height of the video in pixels.
	 * @throw IllegalParameterException When width and/or height are invalids values for video size.
	 */
	void setVideoSize(int width, int heigh);

	/**
	 * This method defines the video size
	 * @param videoSize String that defines the video size. Must follow the pattern "WxH", where W is the width e H is height in pixels.
	 * You can use video size name too, like "HDTV" or "VGA" as parameters.
	 * @throw IllegalParameterException When videoSize contains a invalid values for video size.
	 */
	void setVideoSize(std::string videoSize);

	/**
	 * This method returns the current video's width.
	 * @return Current video's width.
	 */
	int getVideoWidht();

	/**
	 * This method returns the current video's height.
	 * @return Current video's height.
	 */
	int getVideoHeight();

	/**
	 * This method defines the video codec.
	 * @param vcodec the video codec, defined by the enumeration VideoCodec.
	 * @see VideoCodec
	 */
	void setVideoCodec(VideoCodec vcodec);

	/**
	 * This method defines the video codec.
	 * @param vcodec A string that a represent a video codec. Some valid strings are "h264", "mpeg2video".
	 * @throw IllegalParameterException When vcodec contains a invalid video codec.
	 */
	void setVideoCodec(std::string vcodec);

	/**
	 * This method returns the current video codec.
	 * @return A instance of VideoCodec enumeration that represents the current video codec.
	 * @see VideoCodec
	 */
	VideoCodec getVideoCodec();

	/*Audio Coding parameters*/

	/**
	 * This method defines the audio sampling rate value.
	 * @param samplingRate The audio sampling rate value.
	 * throw IllegalParameterException When samplingRate contains a invalid audio sampling rate value.
	 */
	void setAudioSamplingRate(int samplingRate);

	/**
	 * This method returns the current audio sampling rate value.
	 * @return Current audio sampling rate.
	 */
	int getAudioSamplingRate();

	/**
	 * This method defines the audio bit rate value.
	 * The audio codec try to achieve the specified value, but no bit rate value is guaranteed.
	 * @throw IllegalParameterException When audioBitrate contains a invalid audio bit rate value.
	 */
	void setAudioBitrate(int audioBitrate);

	/**
	 * This method return the current audio bit rate value.
	 * @return audio bit rate value.
	 */
	int getAudioBitrate();

	/**
	 * This method defines the number of audio channels.
	 * @param channelsNumber The Number of audio channels.
	 * @throw IllegalParameterException When channelsNumber contains a invalid number of audio channels.
	 */
	void setAudioChannelsNumber(int channelsNumber);

	/**
	 * This method return the current number of audio channels.
	 * @return Current number of audio channels.
	 */
	int getAudioChannelsNumber();

	/**
	 * This method defines the audio codec.
	 * @param acodec the video audio, defined by the enumeration AudioCodec.
	 * @see AudioCodec
	 */
	void setAudioCodec(AudioCodec acodec);

	/**
	 * This method defines the audio codec.
	 * @param acodec A string that a represent a audio codec. Some valid strings are "mp3", "aac".
	 * @throw IllegalParameterException When acodec contains a invalid audio codec.
	 */
	void setAudioCodec(std::string acodec);

	/**
	 * This method returns the current audio codec.
	 * @return A instance of AudioCodec enumeration that represents the current audio codec.
	 * @see AudioCodec
	 */
	AudioCodec getAudioCodec();

	/*Other parameters*/

	/**
	 * This method defines the number of threads used in the video coding process.
	 * @param threads The number of threads.
	 * @throw IllegalParameterException When threds contains a invalid number of threads.
	 */
	void setThreadsNumber(int threads);

	/**
	 * This method returns the current number of threads that will be used in the video coding process.
	 * @return Current number of threads.
	 */
	int getThreadsNumber();

	/**
	 * This method returns the audio/video source associated with the AVEncoder.
	 * @return a instance of AVSource.
	 */
	AVSource* getSource();

	/**
	 * This method is used to set a ffmpeg-presets to the video coding process.
	 * ffmpeg-presets are a set of predefined configurations for several codecs.
	 * @param preset the ffmpeg preset.
	 */
	void setVideoPreset(std::string preset);

	/**
	 * This method is used to set a ffmpeg-presets to the audio coding process.
	 * ffmpeg-presets are a set of predefined configurations for several codecs.
	 * @param preset the ffmpeg preset.
	 */
	void setAudioPreset(std::string preset);

	/**
	 * This method returns the ffmpeg-presets used to coding video.
	 * @return the ffmpeg preset.
	 */
	std::string getVideoPreset();

	/**
	 * This method returns stream id that will be considered during the transcoding process.
	 * @return the stream id
	 */
	int getStreamId();

	/**
	 * This method is used to set the stream that will be used during the transcoding process.
	 * @param id the stream id.
	 */
	void setStreamId(int id);

	/**
	 * This method returns the ffmpeg-presets used to coding audio.
	 * @return the ffmpeg preset.
	 */
	std::string getAudioPreset();

	/**
	 * This method is used to set various video/audio coding dependent parameters.
	 * @param name The parameter name.
	 * @param value the new value of the parameter.
	 */
	void setPropertyValue(std::string name, std::string value);

	/**
	 * This method returns the value of various video/audio coding dependent parameters.
	 * @param name The parameter name.
	 * @return the current value of the parameter.
	 */
	std::string getPropertyValue(std::string name);

	/**
	 * This method force the coding process to copy the video of its source without transconding.
	 */
	void enableCopyVideo();

	/**
	 * This method force the coding process to copy the audio of its source without transconding.
	 */
	void enableCopyAudio();

	/**
	 * This method can be used to determine if the video stream will be considered during the transcoding process.
	 * @param value true, if you desire to use the video stream; false, otherwise.
	 */
	void setVideoEnable(bool value);

	/**
	 * This method can be used to determine if the audio stream will be considered during the transcoding process.
	 * @param value true, if you desire to use the audio stream; false, otherwise.
	 */
	void setAudioEnable(bool value);

	/**
	 * This method is used to verify if the video stream is enabled in the transcoding process.
	 * @return true, if the video is enable; false, otherwise.
	 */
	bool isVideoEnable();

	/**
	 * This method is used to verify if the audio stream is enabled in the transcoding process.
	 * @return true, if the audio is enable; false, otherwise.
	 */
	bool isAudioEnable();

	/**
	 * This method is used to determine if the output video will keep the same quality of the input video.
	 * It may not works for some codecs and containers.
	 * @param value true, if the quality is to be keeped; false, otherwise.
	 */
	void setVideoSameQuality(bool value);

	/**
	 * Verifies if the transcoding proccess will try to keep the input video quality into the output video.
	 * @return true, if the quality is to be keeped; false, otherwise.
	 */
	bool isVideoSameQuality();

protected:
	/**
	 * This protected method is internally used to allow the AVEncodere's instance to configure
	 * the transcoding process with her parameters.
	 * @param ffrapper a pointer to the FFrapper instance that will processed the transcoding.
	 * @throw OptionException when parameters are wrong or invalids.
	 */
	void configure(void* ffrapper);

private:
	int videoBitrate;
	int videoFps;
	AspectRatio aspectRatio;
	int vWidth;
	int vHeight;
	VideoCodec vcodec;
	AudioCodec acodec;
	int audioSamplingRate;
	int audioBitrate;
	int audioChannelsNumber;
	int threadsNumber;
	AVSource* source;
	int streamId;
	std::string vpreset, apreset;
	std::map<std::string, std::string>* properties;
	bool videoEnable;
	bool audioEnable;
	bool videoSameQuality;

	static int NONE;
};

}
}
}
}
#endif /*AVENCODER_H*/

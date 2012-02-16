package br.ufscar.lince.streaming;

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
public class AVEncoder extends JWrapper {
	
	/**
	 * AVSource Constructor
	 * Initialize the codecs with the default values and define the AVSource that
	 * that will be coding.
	 * @param avSource the audio/video source.
	 * @throwss InitializationException if avSource is NULL.
	 */
	public AVEncoder(AVSource avSource) {
		this.pointer = create(avSource);
		this.source = avSource;
	}
	
	/**
	 * Copy Constructor
	 * Initialize the codecs with the values of other AVEnconder
	 * @param copyEncoder AVEnconder instance that will be used to initialize the new one.
	 */
	public AVEncoder(AVEncoder copyAVEncoder) {
		this.pointer = create(copyAVEncoder);
		this.source = copyAVEncoder.source;
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}
	
	/*Video parameters*/
	
	/**
	 * This method defines the Video bit rate.
	 * The video codec try to achieve the specified value, but no bit rate value is guaranteed.
	 * @param videoBitrate the value that will be used to set the bit rate.
	 * @throwss IllegalParameterException When videoBitrate is a invalid video bitrate value.
	 */
	public native void setVideoBitrate(int videoBitrate);

	/**
	 * This method returns the current video bit rate defined.
	 * @return current Video bit rate.
	 */
	public native int getVideoBitrate();

	/**
	 * This method defines the number of frames per second of the video.
	 * If a zero ou negative value is informed, the value 1 is used instead.
	 * @param fps value that will be used to set the video frames per second.
	 * @throwss IllegalParameterException When fps is a invalid video frames per second value.
	 */
	public native void setFramesPerSecond(int fps);

	/**
	 * This method returns the current video number of frames per second.
	 * @return Current number of frames per second.
	 */
	public native int getFramesPerSecond();

	/**
	 * This method defines the video aspect ratio.
	 * @param aspectRatio the video aspect ratio, defined by the enumeration AspectRatio.
	 * @see AspectRatio.
	 */
	public void setAspectRatio(AspectRatio aspectRatio) {
		doSetAspectRatio(aspectRatio.value);
	}

	/**
	 * This method defines the video aspect ratio.
	 * @param aspectRatio String that represents a aspect ratio. Must follow the pattern "X:Y", like "4:3".
	 * @throwss IllegalParameterException When aspectRatio is bad formated or a invalid aspect ratio value.
	 */
	public native void setAspectRatio(String aspectRatio);

	/**
	 * This method returns the current video aspect ratio.
	 * @return A value from enumeration AspectRatio that represents the current video aspect ratio.
	 * @see AspectRatio
	 */
	public AspectRatio getAspectRatio() {
		throw new UnsupportedOperationException();
	}

	/**
	 * This method defines the video size
	 * @param width The width of the video in pixels.
	 * @param height The height of the video in pixels.
	 * @throwss IllegalParameterException When width and/or height are invalids values for video size.
	 */
	public native void setVideoSize(int width, int heigh);

	/**
	 * This method defines the video size
	 * @param videoSize String that defines the video size. Must follow the pattern "WxH", where W is the width e H is height in pixels.
	 * You can use video size name too, like "HDTV" or "VGA" as parameters.
	 * @throwss IllegalParameterException When videoSize contains a invalid values for video size.
	 */
	public native void setVideoSize(String videoSize);

	/**
	 * This method returns the current video's width.
	 * @return Current video's width.
	 */
	public native int getVideoWidht();

	/**
	 * This method returns the current video's height.
	 * @return Current video's height.
	 */
	public native int getVideoHeight();
	
	/**
	 * This method defines the video codec.
	 * @param vcodec the video codec, defined by the enumeration VideoCodec.
	 * @see VideoCodec
	 */
	public void setVideoCodec(VideoCodec vcodec) {
		doSetVideoCodec(vcodec.value);
	}

	/**
	 * This method returns the current video codec.
	 * @return A instance of VideoCodec enumeration that represents the current video codec.
	 * @see VideoCodec
	 */
	public native void setVideoCodec(String vcodec);

	/**
	 * This method returns the current video codec.
	 * @return A instance of VideoCodec enumeration that represents the current video codec.
	 * @see VideoCodec
	 */
	public VideoCodec getVideoCodec() {
		throw new UnsupportedOperationException();
	}
	
	/*Audio parameters*/
	/**
	 * This method defines the audio sampling rate value.
	 * @param samplingRate The audio sampling rate value.
	 * throw IllegalParameterException When samplingRate contains a invalid audio sampling rate value.
	 */
	public native void setAudioSamplingRate(int samplingRate);

	/**
	 * This method returns the current audio sampling rate value.
	 * @return Current audio sampling rate.
	 */
	public native int getAudioSamplingRate();

	/**
	 * This method defines the audio bit rate value.
	 * The audio codec try to achieve the specified value, but no bit rate value is guaranteed.
	 * @throwss IllegalParameterException When audioBitrate contains a invalid audio bit rate value.
	 */
	public native void setAudioBitrate(int audioBitrate);

	/**
	 * This method return the current audio bit rate value.
	 * @return audio bit rate value.
	 */
	public native int getAudioBitrate();

	/**
	 * This method defines the number of audio channels.
	 * @param channelsNumber The Number of audio channels.
	 * @throwss IllegalParameterException When channelsNumber contains a invalid number of audio channels.
	 */
	public native void setAudioChannelsNumber(int channelsNumber);

	/**
	 * This method return the current number of audio channels.
	 * @return Current number of audio channels.
	 */
	public native int getAudioChannelsNumber();

	/**
	 * This method defines the audio codec.
	 * @param acodec the video audio, defined by the enumeration AudioCodec.
	 * @see AudioCodec
	 */
	public void setAudioCodec(AudioCodec acodec) {
		doSetAudioCodec(acodec.value);
	}

	/**
	 * This method defines the audio codec.
	 * @param acodec A string that a represent a audio codec. Some valid strings are "mp3", "aac".
	 * @throwss IllegalParameterException When acodec contains a invalid audio codec.
	 */
	public native void setAudioCodec(String acodec);

	/**
	 * This method returns the current audio codec.
	 * @return A instance of AudioCodec enumeration that represents the current audio codec.
	 * @see AudioCodec
	 */
	public AudioCodec getAudioCodec() {
		throw new UnsupportedOperationException();
	}

	/*Other parameters*/
	/**
	 * This method defines the number of threads used in the video coding process.
	 * @param threads The number of threads.
	 * @throws IllegalParameterException When threds contains a invalid number of threads.
	 */
	public native void setThreadsNumber(int threads);

	/**
	 * This method returns the current number of threads that will be used in the video coding process.
	 * @return Current number of threads.
	 */
	public native int getThreadsNumber();

	/**
	 * This method returns the audio/video source associated with the AVEncoder.
	 * @return a instance of AVSource.
	 */
	public AVSource getSource() {
		return source;
	}
	/**
	 * This method is used to set a ffmpeg-presets to the video coding process.
	 * ffmpeg-presets are a set of predefined configurations for several codecs.
	 * @param preset the ffmpeg preset.
	 */
	public native void setVideoPreset(String preset);
	
	/**
	 * This method is used to set a ffmpeg-presets to the audio coding process.
	 * ffmpeg-presets are a set of predefined configurations for several codecs.
	 * @param preset the ffmpeg preset.
	 */
	public native void setAudioPreset(String preset);

	/**
	 * This method returns the ffmpeg-presets used to coding video.
	 * @return the ffmpeg preset.
	 */
	public native String getVideoPreset();

	/**
	 * This method returns the ffmpeg-presets used to coding audio.
	 * @return the ffmpeg preset.
	 */
	public native String getAudioPreset();
	
	/**
	 * This method is used to set various video/audio coding dependent parameters.
	 * @param name The parameter name.
	 * @value the new value of the parameter.
	 */
	public native void setPropertyValue(String name, String value);

	/**
	 * This method returns the value of various video/audio coding dependent parameters.
	 * @param name The parameter name.
	 * @return the current value of the parameter.
	 */
	public native String getPropertyValue(String name);

	/**
	 * This method force the coding process to copy the video of its source without transconding.
	 */
	public native void enableCopyVideo();

	/**
	 * This method force the coding process to copy the audio of its source without transconding.
	 */
	public native void enableCopyAudio();

	/*Private Native Methods*/
	
	private native long create(AVSource avSource);
	
	private native long create(AVEncoder copyAVEncoder);
	
	private native void destroy();
	
	private native void doSetVideoCodec(int vcodec);
	
	private native void doSetAspectRatio(int value);
	
	private native void doSetAudioCodec(int value);
	
	/*Atributo necessário*/
	
	private AVSource source;
}

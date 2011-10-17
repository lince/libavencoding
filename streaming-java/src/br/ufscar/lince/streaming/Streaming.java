package br.ufscar.lince.streaming;

/**
 * Streaming a audio/video stream encoded by some encoder.
 *
 * This abstract class must be implemented by all the classes that realize a
 * transcoding process and the output format is a network stream, like rpt, udp and etc.
 */
public interface Streaming extends Transcoder {
	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * @param stream the audio-video stream.
	 */
	public void addStream(AVEncoder encoder);
	
	/**
	 * Start the transcoding and streaming process.
	 * This method should be called after the streaming and transcoding process was defined.
	 * It creates a new theard that will process with the process.
	 * @throw InitializationException if no stream was add.
	 * @throw OptionException when parameters informed are wrong or invalids.
	 * @throw TranscodingException when errors occurs during the transcoding processes.
	 * @see addStream
	 */
	public void start();
	
	/**
	 * This method returns true if the transcoding process is finished.
	 * It can be used to create a non-block program, that will not sleep until the coding
	 * is finished.
	 * @return True if the transcoding process is finished; false otherwise.
	 */
	public void stop();
}

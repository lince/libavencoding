package br.ufscar.lince.streaming;

/**
 * This class is used to generate a RTP Stream of a audio/video coded of a source.
 * Only one audio/video stream can be send by a single RTP stream.
 */
public class RTPStream extends JWrapper implements Streaming {
	
	/**
	 * Construtor
	 * @param ip The ip address of the destiny host.
	 * @param ip The port number of the destiny process.
	 */
	public RTPStream(String ip, int port) {
		this.pointer = create(ip, port);
	}
	
	private native long create(String ip, int port);
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}
	
	private native void destroy();

	@Override
	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * RTPStream just suport one audio/video stream.
	 * @throw InitializationException when try to add a second stream.
	 * @param stream the audio-video stream.
	 */
	public native void addStream(AVEncoder encoder);

	@Override
	/**
	 * Abort the transcoding process.
	 * @throw InitializationException if the process hasn't begun.
	 */
	public native void stop();

	@Override
	public native void start();

	@Override
	public native void waitFinishing();

	@Override
	public native boolean isFinished();

}

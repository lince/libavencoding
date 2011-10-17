package br.ufscar.lince.streaming;

/**
 * This class is used to generate a MpegTS of several audio/video streams and streaming
 * this MpegTS using the UDP protocol.
 * Several different audio and video streams can be encapsulate in a MpegTS
 */
public class UDPMpegTS extends JWrapper implements Streaming {
	
	/**
	 * Construtor
	 * @param ip The ip address of the destiny host.
	 * @param ip The port number of the destiny process.
	 */
	public UDPMpegTS(String ip, int port) {
		this.pointer = create(ip, port);
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}

	@Override
	public native void waitFinishing();

	@Override
	public native boolean isFinished();
	
	@Override
	/**
	 * Abort the transcoding process.
	 * @throw InitializationException if the process hasn't begun.
	 */
	public native void stop();

	@Override
	public native void start();
	
	@Override
	/**
	 * This method is used to add a new audio-video stream
	 * to the network stream that will be generated.
	 * @throw InitializationException when try to add a second stream.
	 * @param stream the audio-video stream.
	 */
	public native void addStream(AVEncoder encoder);

	private native long create(String ip, int port);
	
	private native void destroy();
	
}

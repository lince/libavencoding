package br.ufscar.lince.streaming;

/**
 * This class is used to generate a audio/video output file as result of a transcoding process.
 * It implements the abstract class Transcoder.
 */
public class AVOutputFile extends JWrapper implements Transcoder {
		
	/**
	 * Construtor
	 * @param filename the name of the file that will be generated.
	 * @param format the format of the fila that will be generated.
	 */
	public AVOutputFile(String filename, String format) {
		this.pointer = create(filename, format);
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}
	
	/**
	 * Return the name of the file that will be generate.
	 * @param the name of the file.
	 */
	public native String getFilename();

	/**
	 * Abort the transcoding process.
	 * @throws InitializationException if the process hasn't begun.
	 */
	public native void stop();

	/**
	 * Start the transcoding and streaming process.
	 * This method should be called after the streaming and transcoding process was defined.
	 * It creates a new theard that will process with the process.
	 * @throws InitializationException if no stream was add.
	 * @throws OptionException when parameters informed are wrong or invalids.
	 * @throws TranscodingException when errors occurs during the transcoding processes.
	 * @see addStream
	 */
	public native void start();

	/**
	 * This method is used to add a new audio-video streamcp 
	 * to the network stream that will be generated.
	 * @param stream the audio-video stream.
	 */
	public native void addStream(AVEncoder stream);

	@Override
	public void waitFinishing() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean isFinished() {
		// TODO Auto-generated method stub
		return false;
	}
	
	private native long create(String filename, String format);
	
	private native void destroy();

}

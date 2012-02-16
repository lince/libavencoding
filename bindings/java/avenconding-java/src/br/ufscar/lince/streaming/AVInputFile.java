package br.ufscar.lince.streaming;

/**
 * This class represents a audio/video file that will be used as a input for trascoding process.
 */
public class AVInputFile extends JWrapper implements AVSource {
	
	/**
	 * Constructor.
	 * @param filename The name of the file.
	 * @format The format of the audio/video in the file.
	 */
	public AVInputFile(String filename, String format) {
		this.pointer = create(filename, format);
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}
	
	/**
	 * Return the name of the file.
	 * @return name of the file.
	 */
	public native String getFilename();
	
	public native String getFormat();
	
	private native long create(String filename, String format);
	
	private native void destroy();
}

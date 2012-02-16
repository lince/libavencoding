package br.ufscar.lince.streaming;

/**
 * This class can take shots of video sources.
 */
public class ImageShotter extends JWrapper implements Transcoder {
	
	/**
	 * Construtor.
	 * @param width The width of the screen.
	 * @param width The height of the screen.
	 * @param fps The frames per second frequency of the screen.
	 */
	public ImageShotter(AVSource source) {
		this.pointer = create(source);
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}
	
	/**
	 * Take a shot of the actual state of the source and save in a file.
	 * This method create a thread that will handle with shot and transcoding process.
	 * For AVInputFile's source, the actual state is considered the first frame.
	 * @param filename The name of the file that will be create.
	 * @throws OptionException when parameters informed are wrong or invalids.
	 * @throws TranscodingException when errors occurs during the transcoding processes.
	 */
	public native void takeShot(String filename);
	
	/**
	 * Take a shot of the specific moment of the source and save in a file.
	 * This method create a thread that will handle with shot and transcoding process.
	 * For real-time devices's source, the time informed will be counted from the current moment,
	 * is the same as a delayed shot.
	 * @param filename The name of the file that will be create.
	 * @param time The moment of the shot in seconds counted from the begin.
	 * @throws OptionException when parameters informed are wrong or invalids.
	 * @throws TranscodingException when errors occurs during the transcoding processes.
	 */
	public native void takeShot(String filename, int time);
	
	/**
	 * Take a shot of the specific moment of the source and save in a file.
	 * This method create a thread that will handle with shot and transcoding process.
	 * For real-time devices's source, the time informed will be counted from the current moment,
	 * is the same as a delayed shot.
	 * @param filename The name of the file that will be create.
	 * @param time a string in the format "HH:MM:SS" with the moment of the shot.
	 * @throws OptionException when parameters informed are wrong or invalids.
	 * @throws TranscodingException when errors occurs during the transcoding processes.
	 */
	public native void takeShot(String filename, String time);
	
	/**
	 * This methods set the size of the captured images.
	 * @param width The width of the images.
	 * @param height The height of the Images.
	 */
	public native void setImageSize(int width, int heigh);

	/**
	 * Return the width of the captured images.
	 * @return width
	 */
	public native int getImageWidht();

	/**
	 * Return the height of the captured images.
	 * @return height
	 */
	public native int getImageHeight();

	/**
	 * This methods set the image codec used during the transcoding process.
	 * @param codec the image codec, defined by the enumeration ImageCodec.
	 * @see ImageCodec.
	 */
	public void setImageCodec(ImageCodec codec) {
		doSetImageCodec(codec.value);
	}

	private native void doSetImageCodec(int value);

	/**
	 * This methods set the image codec used during the transcoding process.
	 * @param codec String that represents a image codec.
	 * @throws IllegalParameterException When codec is bad formated or a invalid image codec.
	*/
	public native void setImageCodec(String codec);

	/**
	 * This method returns the current image codec.
	 * @return A value from enumeration ImageCodec that represents the current image codec.
	 * @see AspectRatio
	 */
	public ImageCodec getImageCodec() {
		throw new UnsupportedOperationException();
	}
	
	@Override
	public native void waitFinishing();

	@Override
	public native boolean isFinished();
	
	native private void destroy();

	native private long create(AVSource source);

}

package br.ufscar.lince.streaming;

/**
 * This class represents a input device that used the Unix Shared Memory to generate images.
 * Using this AVSource, the transcoding process will utilize images in a
 * specific buffer in memory as a raw images to generate video.
 * An application that generate image and video must put its in a shared buffer, using the
 * DeviceInterface class.
 */
public class SharedBuffer extends JWrapper implements AVSource {

	@Override
	public native String getFormat();
	/**
	 * Return the current width of the images in the buffer.
	 * @return width of the Images
	 */
	public native int getWidth();
	
	/**
	 * Return the current height of the images in the buffer.
	 * @return height of the Images
	 */
	public native int getHeight();

	native private void destroy();

	native private long create();
	
	/**
	 * Construtor
	 */
	public SharedBuffer() {
		this.pointer = create();
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}
	

}

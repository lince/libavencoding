package br.ufscar.lince.streaming;

/**
 * This class allow to use the X11 Terminal as a video source.
 */
public class X11Terminal extends JWrapper implements AVSource {
	
	/**
	 * Construtor.
	 * @param width The width of the screen.
	 * @param width The height of the screen.
	 * @param fps The frames per second frequency of the screen.
	 */
	public X11Terminal(int width, int height, int fps) {
		this.pointer = create(width, height, fps);
	}
	
	/**
	 * This methods destroys the native C++ object.
	 */
	public void finalize() {
		destroy();
	}

	@Override
	public native String getFormat();
	
	/**
	 * Return the screen width.
	 * @return screen width
	 */
	public native int getWidth();
	
	/**
	 * Return the screen height.
	 * @return screen height
	 */
	public native int getHeight();
	
	/**
	 * Return the screen frames per second frequency.
	 * @return frames per second.
	 */
	public native int getFps();

	native private void destroy();

	native private long create(int width, int height, int fps);
}

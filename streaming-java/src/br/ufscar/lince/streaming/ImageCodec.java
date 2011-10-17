package br.ufscar.lince.streaming;

/**
 * Enumeration with the image codecs supported.
 * 	- MJPEG The mjpeg (jpg) image codec.
 *  - GIF The gif image codec.
 */
public enum ImageCodec {
	MJPEG(1), 
	GIF(2);
	
	public int value;
	ImageCodec(int value) {
		this.value = value;
	}

}

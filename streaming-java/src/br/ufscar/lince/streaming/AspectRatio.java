package br.ufscar.lince.streaming;

/**
 * Enumeration with the Aspect Ratios supported
 *  - AR_4X3 The letterbox aspect ratio.
 *  - AR_16X9 The widescreen aspect ratio.
 */
public enum AspectRatio {
	AR_4X3(1), 
	AR_16X9(2);
	
	public int value;
	AspectRatio(int value) {
		this.value = value;
	}
}

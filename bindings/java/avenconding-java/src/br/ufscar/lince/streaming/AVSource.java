package br.ufscar.lince.streaming;

/**
 * This abstract class represents a generic audio/video source.
 * The classes that represents a less-generic audio/video source
 * (such a device, a inputfile a network stream) should implement this class.
 */
public interface AVSource {
	/**
	 * Return the format of the audio/video of the source
	 * @return
	 */
	public String getFormat();

}

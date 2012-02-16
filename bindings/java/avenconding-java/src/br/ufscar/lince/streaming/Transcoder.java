package br.ufscar.lince.streaming;

/**
 * Realize generic a transcoding process.
 *
 * This abstract class must be implemented by all the classes that realize a
 * transcoding process.
 */
public interface Transcoder {
	/**
	 * This method waits until the transcoding process is finished.
	 * It can be used to create a block program, that will sleep until the coding is finished.
	 * @throws InitializationException when the transcoding process hasn't begun.
	 * @throws InitializationException when the transcoding process hasn't begun.
	 */
	public abstract void waitFinishing();
	
	/**
	 * This method returns true if the transcoding process is finished.
	 * It can be used to create a non-block program, that will not sleep until the coding
	 * is finished.
	 * @return True if the transcoding process is finished; false otherwise.
	 */
	public abstract boolean isFinished();
	
}

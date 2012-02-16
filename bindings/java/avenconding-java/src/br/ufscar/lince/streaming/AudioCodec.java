package br.ufscar.lince.streaming;

/**
 * Enumeration with the audio codecs supported.
 *  - AAC The aac (Advanced Audio Coding) audio codec.
 *  - MP3 The mpeg layer 3 audio codec.
 *  - A_COPY A special that can be used to force the output audio just copy the source audio.
 */
public enum AudioCodec {
	AAC(1), 
	MP3(2),
	A_COPY(3);
	
	public int value;
	AudioCodec(int value) {
		this.value = value;
	}
}

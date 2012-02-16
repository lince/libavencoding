package br.ufscar.lince.streaming;

/**
 * Enumeration with the video codecs supported.
 * 	- H264 The h264 (MPEG4 Advanced Video Coding) video codec.
 *  - MPEG2 The mpeg2 video codec.
 *  - V_COPY A special that can be used to force the output video just copy the source video.
 */
public enum VideoCodec {
	H264(1),
	MPEG2(2),
	V_COPY(3);
	
	public int value;
	VideoCodec(int value) {
		this.value = value;
	}
}

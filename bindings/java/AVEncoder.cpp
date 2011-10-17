#include <jni.h>
#include "br_ufscar_lince_streaming_AVEncoder.h"

#include <streaming/AVEncoder.h>
using namespace br::ufscar::lince::streaming;

AVEncoder* getAVEncoder(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (AVEncoder*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setVideoBitrate
  	  (JNIEnv *jenv, jobject jobj, jint bitrate) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setVideoBitrate(bitrate);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getVideoBitrate
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getVideoBitrate();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setFramesPerSecond
  	  (JNIEnv *jenv, jobject jobj, jint fps) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setFramesPerSecond(fps);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getFramesPerSecond
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getFramesPerSecond();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setAspectRatio
  	  (JNIEnv *jenv, jobject jobj, jstring aspectRatio) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string str = jenv->GetStringUTFChars(aspectRatio, 0);
	encoder->setAspectRatio(str);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setVideoSize__II
  	  (JNIEnv *jenv, jobject jobj, jint width, jint height) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setVideoSize(width, height);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setVideoSize__Ljava_lang_String_2
  	  (JNIEnv *jenv, jobject jobj, jstring videoSize) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string str = jenv->GetStringUTFChars(videoSize, 0);
	encoder->setVideoSize(str);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getVideoWidht
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getVideoWidht();
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getVideoHeight
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getVideoHeight();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setVideoCodec
  	  (JNIEnv *jenv, jobject jobj, jstring vcodec) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string str = jenv->GetStringUTFChars(vcodec, 0);
	encoder->setVideoCodec(str);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setAudioSamplingRate
  	  (JNIEnv *jenv, jobject jobj, jint asr) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setAudioSamplingRate(asr);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getAudioSamplingRate
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getAudioSamplingRate();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setAudioBitrate
  	  (JNIEnv *jenv, jobject jobj, jint abitrate) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setAudioBitrate(abitrate);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getAudioBitrate
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getAudioBitrate();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setAudioChannelsNumber
  	  (JNIEnv *jenv, jobject jobj, jint n) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setAudioChannelsNumber(n);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getAudioChannelsNumber
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getAudioChannelsNumber();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setAudioCodec
  	  (JNIEnv *jenv, jobject jobj, jstring acodec) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string str = jenv->GetStringUTFChars(acodec, 0);
	encoder->setAudioCodec(str);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setThreadsNumber
  	  (JNIEnv *jenv, jobject jobj, jint n) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setThreadsNumber(n);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getThreadsNumber
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	return encoder->getThreadsNumber();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setVideoPreset
  (JNIEnv *jenv, jobject jobj, jstring preset) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string sPreset = jenv->GetStringUTFChars(preset, 0 );
	encoder->setVideoPreset(sPreset);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setAudioPreset
  	  (JNIEnv *jenv, jobject jobj, jstring preset) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string sPreset = jenv->GetStringUTFChars(preset, 0 );
	encoder->setAudioPreset(sPreset);
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getVideoPreset
  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string preset = encoder->getVideoPreset();
	return jenv->NewStringUTF(preset.c_str());
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getAudioPreset
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string preset = encoder->getAudioPreset();
	return jenv->NewStringUTF(preset.c_str());
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_setPropertyValue
  	  (JNIEnv *jenv, jobject jobj, jstring property, jstring value) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string sProp = jenv->GetStringUTFChars(property, 0);
	string sValue = jenv->GetStringUTFChars(value, 0);
	encoder->setPropertyValue(sProp, sValue);
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_AVEncoder_getPropertyValue
  	  (JNIEnv *jenv, jobject jobj, jstring propName) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	string str = jenv->GetStringUTFChars(propName, 0);
	string value = encoder->getPropertyValue(str);
	return jenv->NewStringUTF(value.c_str());
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_enableCopyVideo
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->enableCopyVideo();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_enableCopyAudio
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->enableCopyAudio();
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_AVEncoder_create__Lbr_ufscar_lince_streaming_AVSource_2
  	  (JNIEnv *jenv, jobject jobj, jobject avSource) {

	jclass cls = jenv->GetObjectClass(avSource);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	AVSource* source = (AVSource*)jenv->GetLongField(avSource, fid);
	AVEncoder* encoder = new AVEncoder(source);
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_AVEncoder_create__Lbr_ufscar_lince_streaming_AVEncoder_2
  	  (JNIEnv *jenv, jobject jobj, jobject jencoder) {

	jclass cls = jenv->GetObjectClass(jencoder);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	AVEncoder* copy = (AVEncoder*)jenv->GetLongField(jencoder, fid);
	AVEncoder* encoder = new AVEncoder(copy);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_destroy
  	  (JNIEnv *jenv, jobject jobj) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	delete encoder;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_doSetVideoCodec
  	  (JNIEnv *jenv, jobject jobj, jint vcodec) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setVideoCodec((VideoCodec) vcodec);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_doSetAspectRatio
  	  (JNIEnv *jenv, jobject jobj, jint aspect) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setAspectRatio((AspectRatio) aspect);

}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVEncoder_doSetAudioCodec
  	  (JNIEnv *jenv, jobject jobj, jint acodec) {

	AVEncoder* encoder = getAVEncoder(jenv, jobj);
	encoder->setAudioCodec((AudioCodec) acodec);
}

#include <jni.h>
#include "br_ufscar_lince_streaming_UDPMpegTS.h"

#include <streaming/UDPMpegTS.h>
using namespace ::br::ufscar::lince::streaming;

UDPMpegTS* getUDPMpegTS(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (UDPMpegTS*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_addStream
  	  (JNIEnv *jenv, jobject jobj, jobject avEncoder) {

	UDPMpegTS* mpegTS = getUDPMpegTS(jenv, jobj);
	jclass cls = jenv->GetObjectClass(avEncoder);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return;
		}
	}
	AVEncoder* encoder = (AVEncoder*)jenv->GetLongField(avEncoder, fid);
	mpegTS->addStream(encoder);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_stop
  	  (JNIEnv *jenv, jobject jobj) {

	UDPMpegTS* mpegTS = getUDPMpegTS(jenv, jobj);
	mpegTS->stop();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_start
  	  (JNIEnv *jenv, jobject jobj) {

	UDPMpegTS* mpegTS = getUDPMpegTS(jenv, jobj);
	mpegTS->start();
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_create
  	  (JNIEnv *jenv, jobject jobj, jstring ip, jint port) {

	string _ip = jenv->GetStringUTFChars(ip, 0);
	UDPMpegTS* mpegTS = new UDPMpegTS(_ip, port);
	return (jlong) mpegTS;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_destroy
  	  (JNIEnv *jenv, jobject jobj) {

	UDPMpegTS* mpegTS = getUDPMpegTS(jenv, jobj);
	delete mpegTS;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_waitFinishing
  	  (JNIEnv *jenv, jobject jobj) {

	UDPMpegTS* mpegTS = getUDPMpegTS(jenv, jobj);
	mpegTS->waitFinishing();
}


JNIEXPORT jboolean JNICALL Java_br_ufscar_lince_streaming_UDPMpegTS_isFinished
  	  (JNIEnv *jenv, jobject jobj) {

	UDPMpegTS* mpegTS = getUDPMpegTS(jenv, jobj);
	return (jboolean) mpegTS->isFinished();
}

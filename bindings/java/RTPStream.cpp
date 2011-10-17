#include <jni.h>
#include "br_ufscar_lince_streaming_RTPStream.h"

#include <streaming/RTPStream.h>
using namespace ::br::ufscar::lince::streaming;


RTPStream* getRTPStream(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (RTPStream*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_RTPStream_create
  	  (JNIEnv *jenv, jobject jobj, jstring ip, jint port) {

	string sIp = jenv->GetStringUTFChars(ip, 0 );
	RTPStream* stream = new RTPStream(sIp, port);
	return (jlong) stream;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_RTPStream_destroy
  	  (JNIEnv *jenv, jobject jobj) {

	RTPStream* stream = getRTPStream(jenv, jobj);
	delete stream;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_RTPStream_addStream
		(JNIEnv *jenv, jobject jobj, jobject avEncoder) {

	RTPStream* stream = getRTPStream(jenv, jobj);
	jclass cls = jenv->GetObjectClass(avEncoder);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return;
		}
	}
	AVEncoder* encoder = (AVEncoder*)jenv->GetLongField(avEncoder, fid);
	stream->addStream(encoder);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_RTPStream_stop
  	  (JNIEnv *jenv, jobject jobj) {

	RTPStream* stream = getRTPStream(jenv, jobj);
	stream->stop();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_RTPStream_start
  	  (JNIEnv *jenv, jobject jobj) {

	RTPStream* stream = getRTPStream(jenv, jobj);
	stream->start();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_RTPStream_waitFinishing
  (JNIEnv *jenv, jobject jobj) {

	RTPStream* stream = getRTPStream(jenv, jobj);
	stream->waitFinishing();
}


JNIEXPORT jboolean JNICALL Java_br_ufscar_lince_streaming_RTPStream_isFinished
  (JNIEnv *jenv, jobject jobj) {

	RTPStream* stream = getRTPStream(jenv, jobj);
	return (jboolean) stream->isFinished();
}

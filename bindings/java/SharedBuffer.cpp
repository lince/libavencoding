#include <jni.h>
#include "br_ufscar_lince_streaming_SharedBuffer.h"

#include <streaming/SharedBuffer.h>
using namespace ::br::ufscar::lince::streaming;

SharedBuffer* getSharedBuffer(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (SharedBuffer*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_SharedBuffer_getFormat
  	  (JNIEnv * jenv, jobject jobj) {

	SharedBuffer* buffer = getSharedBuffer(jenv, jobj);
	string str = buffer->getFormat();
	return jenv->NewStringUTF(str.c_str());
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_SharedBuffer_getWidth
  	  (JNIEnv * jenv, jobject jobj) {

	SharedBuffer* buffer = getSharedBuffer(jenv, jobj);
	return buffer->getWidth();
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_SharedBuffer_getHeight
  	  (JNIEnv * jenv, jobject jobj) {

	SharedBuffer* buffer = getSharedBuffer(jenv, jobj);
	return buffer->getHeight();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_SharedBuffer_destroy
  	  (JNIEnv * jenv, jobject jobj) {

	SharedBuffer* buffer = getSharedBuffer(jenv, jobj);
	delete buffer;
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_SharedBuffer_create
  	  (JNIEnv * jenv, jobject jobj) {

	SharedBuffer* buffer = new SharedBuffer();
	return (jlong) buffer;
}

#include <jni.h>
#include "br_ufscar_lince_streaming_X11Terminal.h"

#include <streaming/X11Terminal.h>
using namespace ::br::ufscar::lince::streaming;

X11Terminal* getX11Terminal(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (X11Terminal*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_X11Terminal_getFormat
  	  (JNIEnv *jenv, jobject jobj) {
	X11Terminal* terminal = getX11Terminal(jenv, jobj);
	string str = terminal->getFormat();
	jstring jStr = jenv->NewStringUTF(str.c_str());
	return jStr;
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_X11Terminal_getWidth
  	  (JNIEnv *jenv, jobject jobj) {
	X11Terminal* terminal = getX11Terminal(jenv, jobj);
	return terminal->getWidth();
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_X11Terminal_getHeight
  	  (JNIEnv *jenv, jobject jobj) {
	X11Terminal* terminal = getX11Terminal(jenv, jobj);
	return terminal->getHeight();

}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_X11Terminal_getFps
  	  (JNIEnv *jenv, jobject jobj) {
	X11Terminal* terminal = getX11Terminal(jenv, jobj);
	return terminal->getFps();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_X11Terminal_destroy
	(JNIEnv *jenv, jobject jobj) {
	X11Terminal* terminal = getX11Terminal(jenv, jobj);
	delete terminal;
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_X11Terminal_create
  	  (JNIEnv *jenv, jobject jobj, jint width, jint height, jint fps) {
	X11Terminal* terminal = new X11Terminal(width, height, fps);
	return (jlong) terminal;
}

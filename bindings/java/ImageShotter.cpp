#include <jni.h>
#include "br_ufscar_lince_streaming_ImageShotter.h"

#include <streaming/ImageShotter.h>
using namespace ::br::ufscar::lince::streaming;

ImageShotter* getImageShotter(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (ImageShotter*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_takeShot__Ljava_lang_String_2
  	  (JNIEnv *jenv, jobject jobj, jstring jFilename) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	string filename = jenv->GetStringUTFChars(jFilename, 0);
	shotter->takeShot(filename);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_takeShot__Ljava_lang_String_2I
		(JNIEnv *jenv, jobject jobj, jstring jFilename, jint time) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	string filename = jenv->GetStringUTFChars(jFilename, 0);
	shotter->takeShot(filename, (int) time);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_takeShot__Ljava_lang_String_2Ljava_lang_String_2
		(JNIEnv *jenv, jobject jobj, jstring jFilename, jstring jTime) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	string filename = jenv->GetStringUTFChars(jFilename, 0);
	string time = jenv->GetStringUTFChars(jTime, 0);
	shotter->takeShot(filename, time);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_setImageSize
		(JNIEnv *jenv, jobject jobj, jint width, jint height) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	shotter->setImageSize((int) width, (int) height);
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_ImageShotter_getImageWidht
		(JNIEnv *jenv, jobject jobj) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	return (jint) shotter->getImageWidht();
}

JNIEXPORT jint JNICALL Java_br_ufscar_lince_streaming_ImageShotter_getImageHeight
		(JNIEnv *jenv, jobject jobj) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	return (jint) shotter->getImageHeight();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_doSetImageCodec
		(JNIEnv *jenv, jobject jobj, jint codec) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	shotter->setImageCodec((ImageCodec) codec);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_setImageCodec
		(JNIEnv *jenv, jobject jobj, jstring jCodec) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	string codec = jenv->GetStringUTFChars(jCodec, 0);
	shotter->setImageCodec(codec);
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_waitFinishing
		(JNIEnv *jenv, jobject jobj) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	shotter->waitFinishing();
}

JNIEXPORT jboolean JNICALL Java_br_ufscar_lince_streaming_ImageShotter_isFinished
		(JNIEnv *jenv, jobject jobj) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	return (jboolean) shotter->isFinished();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_ImageShotter_destroy
		(JNIEnv *jenv, jobject jobj) {

	ImageShotter* shotter = getImageShotter(jenv, jobj);
	delete shotter;
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_ImageShotter_create
		(JNIEnv *jenv, jobject jobj, jobject avSource) {


}

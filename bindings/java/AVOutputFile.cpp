#include <jni.h>
#include "br_ufscar_lince_streaming_AVOutputFile.h"

#include <streaming/AVOutputFile.h>
using namespace ::br::ufscar::lince::streaming;

AVOutputFile* getAVOutputFile(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (AVOutputFile*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_AVOutputFile_getFilename
  	  (JNIEnv *jenv, jobject jobj) {

	AVOutputFile* output = getAVOutputFile(jenv, jobj);
	string str = output->getFilename();
	jstring jStr = jenv->NewStringUTF(str.c_str());
	return jStr;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVOutputFile_stop
  	  (JNIEnv *jenv, jobject jobj) {

	AVOutputFile* output = getAVOutputFile(jenv, jobj);
	output->stop();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVOutputFile_start
  	  (JNIEnv *jenv, jobject jobj) {

	AVOutputFile* output = getAVOutputFile(jenv, jobj);
	output->start();
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVOutputFile_addStream
  	  (JNIEnv *jenv, jobject jobj, jobject avEncoder) {

	AVOutputFile* output = getAVOutputFile(jenv, jobj);
	jclass cls = jenv->GetObjectClass(avEncoder);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return;
		}
	}
	AVEncoder* encoder = (AVEncoder*)jenv->GetLongField(avEncoder, fid);
	output->addStream(encoder);
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_AVOutputFile_create
  	  (JNIEnv *jenv, jobject jobj, jstring jFilename, jstring jFormat) {

	string filename = jenv->GetStringUTFChars(jFilename, 0);
	string format = jenv->GetStringUTFChars(jFormat, 0);
	AVOutputFile* output = new AVOutputFile(filename, format);
	return (jlong) output;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVOutputFile_destroy
  	  (JNIEnv *jenv, jobject jobj) {

	AVOutputFile* output = getAVOutputFile(jenv, jobj);
	delete output;
}

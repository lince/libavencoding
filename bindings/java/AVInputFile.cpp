#include <jni.h>
#include "br_ufscar_lince_streaming_AVInputFile.h"

#include <streaming/AVInputFile.h>
using namespace ::br::ufscar::lince::streaming;

AVInputFile* getAVInputFile(JNIEnv *jenv, jobject jobj) {
	jclass cls = jenv->GetObjectClass(jobj);
	static jfieldID fid = NULL;
	if (fid == NULL) {
		fid = jenv->GetFieldID(cls, "pointer", "J");
		if (fid == NULL) {
			return NULL;
		}
	}
	return (AVInputFile*)jenv->GetLongField(jobj, fid);
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_AVInputFile_getFilename
  	  (JNIEnv *jenv, jobject jobj) {

	AVInputFile* ifile = getAVInputFile(jenv, jobj);
	string str = ifile->getFilename();
	return jenv->NewStringUTF(str.c_str());
}

JNIEXPORT jstring JNICALL Java_br_ufscar_lince_streaming_AVInputFile_getFormat
  	  (JNIEnv *jenv, jobject jobj) {

	AVInputFile* ifile = getAVInputFile(jenv, jobj);
	string str = ifile->getFormat();
	return jenv->NewStringUTF(str.c_str());
}

JNIEXPORT jlong JNICALL Java_br_ufscar_lince_streaming_AVInputFile_create
  	  (JNIEnv *jenv, jobject jobj, jstring filename, jstring format) {

	string _filename = jenv->GetStringUTFChars(filename, 0);
	string _format = jenv->GetStringUTFChars(format, 0);
	AVInputFile* ifile = new AVInputFile(_filename, _format);
	return (jlong) ifile;
}

JNIEXPORT void JNICALL Java_br_ufscar_lince_streaming_AVInputFile_destroy
  	  (JNIEnv *jenv, jobject jobj) {

	AVInputFile* ifile = getAVInputFile(jenv, jobj);
	delete ifile;
}

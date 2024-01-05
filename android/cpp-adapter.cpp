#include <jni.h>
#include "react-native-super-sqlite.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_supersqlite_SuperSqliteModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return supersqlite::multiply(a, b);
}

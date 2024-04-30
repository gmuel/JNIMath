/*
 * impl.cpp
 *
 *  Created on: 30.04.2024
 *      Author: stream
 */
#include "../include/de_iworks_jni_math_JNIMath.h"

double abs(double x) {
	return x>=0.0?x:-x;
}

JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_abs
  (JNIEnv *, jclass, jdouble a){
	return jdouble(abs(a));
}

double babel(double a, double x){
	return .5*(x+a/x);
}

JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_sqrt
  (JNIEnv *env, jclass jclzz, jdouble a){
	int count = 0, max = 200;
	double x = a, cp = a, eps = 5e-15;
	while(abs(x*x-cp)>eps&&count<max){
		x = babel(cp,x);
		++count;
	}
	return x;
}

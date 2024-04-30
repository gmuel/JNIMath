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
double babel2(double a, double x){
	return babel(a,babel(a,x));
}
double babelN(double a, double x, int i){
	return i<=0?x:i==1?babel(a,x):i==2?babel2(a,x):babelN(a,babel(a,x),--i);
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

JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_sqrt__DDI
  (JNIEnv *jenv, jclass jclzz, jdouble ja, jdouble jeps, jint jmax){
	return Java_de_iworks_jni_math_JNIMath_sqrt__DDII(jenv,jclzz,ja,jeps,jmax,2);
}


JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_sqrt__DDII
  (JNIEnv *, jclass , jdouble ja, jdouble jeps, jint jmax, jint jsteep){
	int count = 0, max = jmax>0?jmax:-jmax;
	double x = ja, a = ja, eps = jeps>5e-15?jeps:5e-15;
	while(abs(x*x-a)>eps&&count<max){
			x = babel(a,x);
			++count;
	}
	return x;
}

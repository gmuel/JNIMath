/*
 * impl.cpp
 *
 *  Created on: 04.05.2024
 *      Author: stream
 */


#include "../include/de_iworks_jni_math_JNIMath.h"
#include <iostream>
#include <sstream>
static double EPS = 5e-15;

double babel(double a, double x){
	return .5*(x+a/x);
}
double babel2(double a, double x){
	return jdouble(babel(a,babel(a,x)));
}
double babel22(double a, double x){
	double x2 = x*x, x2a = x2+a;
	return .25*(x2a*x2a+4*a*x2)/(x*x2a);
}
double abs(double x) {
	return x>.0?x:-x;
}
double varSqrt(double jx, double jEps, int jMaxStep, double (*jf)(double,double)){
	if(abs(jx-1.0)<EPS||abs(jx)<EPS) return jx;
	double x = jx>1?.5*jx:2*jx, cp = jx, eps = jEps>EPS?jEps:EPS;
	int count = 0, max = jMaxStep>0?jMaxStep:-jMaxStep;
#ifdef DEBUG_RUN
	std::stringstream s ;
#endif /*DEBUG_RUN*/
	while(abs(x*x-cp)>eps&&count<max){
		x = (*jf)(cp,x);
		++count;
#ifdef DEBUG_RUN
		s << "sqrt_";
		s <<(long) jf;
		s << "(";
		s << cp;
		s << ")_";
		s<<count;
		s <<" = ";
		s << x;
		s << "\n";
#endif /*DEBUG_RUN*/
	}
#ifdef DEBUG_RUN
	std::cout << s.str();
	std::cout << "\n";
#endif /*DEBUG_RUN*/
	return x;
}

double varSqrtRec(double ja, double jx, double jEps, int jMaxStep, double (*jf)(double,double)){
	if(abs(jx-1.0)<EPS||abs(jx)<EPS) return jx;
	return jMaxStep<=200&&jMaxStep>=1?abs(jx*jx-ja)>jEps?varSqrtRec(ja,(*jf)(ja,jx),jEps,--jMaxStep,jf):jx:jx;
}

JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_abs
  (JNIEnv *, jclass, jdouble a){
	return jdouble(abs(a));
}
JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_sqrt__D
  (JNIEnv *, jclass, jdouble a){
	return jdouble(varSqrt(a,EPS,200,babel));
}
JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_sqrt__DDI
  (JNIEnv *, jclass, jdouble ja, jdouble jeps, jint jmax){
	return jdouble(varSqrt(ja,jeps,jmax,babel));
}
JNIEXPORT jdouble JNICALL Java_de_iworks_jni_math_JNIMath_sqrt__DDII
  (JNIEnv *, jclass, jdouble ja, jdouble jeps, jint jmax, jint jsteep){
	return jsteep==2?jdouble(varSqrt(ja,jeps,jmax,babel22)):jdouble(varSqrt(ja,jeps,jmax,babel));
}

/*
 * impl.cpp
 *
 *  Created on: 04.05.2024
 *      Author: stream
 */


#include "../include/de_iworks_jni_math_JNIMath.h"

static double EPS = 5e-15;

double babel(double a, double x){
	return .5*(x+a/x);
}
double abs(double x) {
	return x>.0?x:-x;
}
double varSqrt(double jx, double jEps, int jMaxStep, double (*jf)(double,double)){
	if(abs(jx-1.0)<EPS||abs(jx)<EPS) return jx;
	double x = jx, eps = jEps>EPS?jEps:EPS;
	int count = 0, max = jMaxStep>0?jMaxStep:-jMaxStep;
	while(abs(x*x-jx)>eps&&count<max){
		x = jf(jx,x);
		++count;
	}
	return .0;
}

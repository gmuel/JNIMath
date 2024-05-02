package de.iworks.prec;

import de.iworks.jni.math.JNIMath;

public class PrecUtil {
	public static double EPS = 5e-15;
	public static Double stdSqrt(Double x) {return new Double (Math.sqrt(x.doubleValue()));}
	public static Double sqrt(Double x) {
		return new Double (JNIMath.sqrt(x.doubleValue()));
	}
	public static Double sqrt(Double x, Double eps, Long maxIter, Long steepness) {
		long max1 = maxIter.longValue(), steep1 = steepness.longValue();
		int max   = max1>5000?5000:max1<0?200:(int) max1;
		int steep = steep1>5?5:steep1<1?1:(int) steep1;
		double eps1 = eps.doubleValue(), eps0 = eps1>.5 || eps1<EPS?EPS:eps1;
		return new Double(JNIMath.sqrt(x, eps0, max, steep));
	}
	
	public static Long nanoSecs() {return new Long(System.nanoTime());}
}

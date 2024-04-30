package de.iworks.jni.math;

public class JNIMath {

	/**
	 * @param x
	 * @return absolute value of x
	 */
	public static native double abs(double x);
	/**
	 * @param x argument
	 * @return square root of arg 'x'
	 */
	public static native double sqrt(double x);
	/**
	 * @param x argument
	 * @param eps precision threshold
	 * @param maxIter maximal number of iterators
	 * @return
	 */
	public static native double sqrt(double x, double eps, int maxIter);
	/**
	 * @param x
	 * @param eps
	 * @param maxIter
	 * @param steepness
	 * @return
	 */
	public static native double sqrt(double x, double eps, int maxIter, int steepness);
	
	static {
		System.loadLibrary("../");
	}
	
}

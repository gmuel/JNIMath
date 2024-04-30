CC=g++ -O3 -Wall -fPIC
CJ=javac -h
BIN=bin/
LIB=lib/
INC=include/
JVH=/usr/lib/jvm/java-11-openjdk-amd64/include/
JVL=$(JVH)linux/
$(LIB)libjni_math.so : $(LIB)impl.o
	$(CC) -shared -o $@ $<
$(LIB)impl.o : $(LIB)impl.cpp $(INC)de_iworks_jni_math_JNIMath.h
	$(CC) -c -I$(JVH) -I$(JVL) $< -o $@
$(INC)de_iworks_jni_math_JNIMath.h : ../JNIMath/src/de/iworks/jni/math/JNIMath.java
	$(CJ) $(INC) $<
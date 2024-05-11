#!/usr/bin/make -f
CC=g++ -O3 -Wall -fPIC 
JC=javac -h
LN=ln -s
INC=include/
LIB=lib/
BIN=bin/
GIT=/home/${USER}/git/JNIMath/
HOM=$(GIT)JNIMathCpp01/
JVA=$(GIT)JNIMath/src/de/iworks/jni/math/JNIMath.java
JVH=/opt/ace-12.0.5.0/common/jdk/include/
JVL=$(JVH)linux/
all : $(HOM)$(LIB)libjni_math.so
# .PHONY : $(JVA)
$(HOM)$(LIB)libjni_math.so : $(HOM)$(LIB)libjni_math.so.1
	$(LN) $< $@
$(HOM)$(LIB)libjni_math.so.1 : $(HOM)$(LIB)libjni_math.so.1.0
	$(LN) $< $@
$(HOM)$(LIB)libjni_math.so.1.0 : $(HOM)$(LIB)libjni_math.so.1.0.1
	$(LN) $< $@
$(HOM)$(LIB)libjni_math.so.1.0.1 : $(BIN)impl.o
	$(CC) -shared -o $@ $<
$(BIN)impl.o : $(LIB)impl.cpp $(INC)de_iworks_jni_math_JNIMath.h
	$(CC) -o $@ -I$(JVH) -I$(JVL) -c $<
$(INC)de_iworks_jni_math_JNIMath.h : $(JVA)
	$(JC) $(INC) $<
clean :
	rm $(LIB)*.so*
	rm $(BIN)*.o
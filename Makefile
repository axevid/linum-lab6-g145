# Makefile for testresistance and libresistance.so
# Note that clean for subdirs and install are missing

# Which complier
CC = gcc

# Where are include files kept
#INCLUDE = .

# Options
CFLAGS = -O 

# all:	electrotest

.PHONY:	subdirs $(SUBDIRS)


#all: lib src/electrotest.c
all: lib electrotest
	ar rcs lib/libresistance.a lib/libresistance.o
	ar rcs lib/libpower.a lib/libpower.o
	ar rcs lib/libcomponent.a lib/libcomponent.o
	$(CC) -static src/electrotest.c -Llib -lpower -lresistance -lcomponent -o electrotest_static -lm -std=c99
	$(CC)  -o electrotest_dynamic src/electrotest.c -Wl,-rpath,$(CURDIR)/lib -L$(CURDIR)/lib -lpower -lresistance -lcomponent -lm -std=c99

lib: lib1 lib2 lib3

lib1: src/lib1/libresistance.c src/lib1/libresistance.h
	$(CC) $(CFLAGS) -c -fPIC src/lib1/libresistance.c -o lib/libresistance.o
	$(CC) -shared -o lib/libresistance.so lib/libresistance.o

lib2: src/lib2/libpower.c src/lib2/libpower.h 
	$(CC) -c -fPIC src/lib2/libpower.c -o lib/libpower.o -lm
	$(CC) -shared -o lib/libpower.so lib/libpower.o -lm

lib3: src/lib3/libcomponent.c src/lib3/libcomponent.h 
	$(CC) -c -fPIC src/lib3/libcomponent.c -o lib/libcomponent.o -lm -std=c99 
	$(CC) -shared -o lib/libcomponent.so lib/libcomponent.o -lm -std=c99    

electrotest: 
	$(CC) $(CFLAGS) -o electrotest src/electrotest.c -Wl,-rpath,$(CURDIR)/lib -L$(CURDIR)/lib -lresistance -lpower -lcomponent -lm -std=c99 


clean:
	rm -f lib/*.o lib/*.so lib/*.a electrotest electrotest_static electrotest_dynamic

install: installlib electrotest
	install electrotest /usr/local/bin

installlib: lib1 lib2 lib3
	install lib/libpower.so /usr/lib
	install lib/libresistance.so /usr/lib
	install lib/libcomponent.so /usr/lib

uninstall:
	rm -f  /usr/lib/libpower.so
	rm -f /usr/lib/libresistance.so
	rm -f /usr/lib/libcomponent.so
	rm -f /usr/local/bin/electrotest


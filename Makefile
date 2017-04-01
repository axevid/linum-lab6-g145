# Makefile for testresistance and libresistance.so
# Note that clean for subdirs and install are missing

# Which complier
CC = gcc

# Where are include files kept
#INCLUDE = .

# Options
CFLAGS = -O -Wall
SUBDIRS = lib1 lib2 lib3

# all:	electrotest

.PHONY:	subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)

$(SUBDIRS):	
	$(MAKE) -C $@



all: lib src/electrotest.c
	ar rcs lib/libresistance.a lib/libresistance.o
	ar rcs lib/libpower.a lib/libpower.o
	ar rcs lib/libcomponent.a lib/libcomponent.o
	$(CC) -static src/electrotest.c -lm -Llib -lpower -lresistance -lcomponent -o electrotest_static
#	$(CC) src/electrotest.c lib/libresistance.o lib/libpower.o lib/libcomponent.o -Llib -lpower -lresistance -lcomponent

lib: lib1 lib2 lib3

lib1: src/lib1/libresistance.c src/lib1/libresistance.h
	$(CC) $(CFLAGS) -c -fPIC src/lib1/libresistance.c -o lib/libresistance.o
	$(CC) -shared -o lib/libresistance.so lib/libresistance.o

lib2: src/lib2/libpower.c src/lib2/libpower.h 
	$(CC) -c -fPIC src/lib2/libpower.c -o lib/libpower.o -lm
	$(CC) -shared -o lib/libpower.so lib/libpower.o -lm

lib3: src/lib3/libcomponent.c src/lib3/libcomponent.h 
	$(CC) -c -fPIC src/lib3/libcomponent.c -lm -o lib/libcomponent.o
	$(CC) -shared -o lib/libcomponent.so lib/libcomponent.o -lm

electrotest: 
	$(CC) $(CFLAGS) -o electrotest src/electrotest.c -lresistance -lpower -lcomponent -lm

.PHONY:	clean

clean:
	rm -f lib/*.o lib/*.so lib/*.a electrotest electrotest_static

install: installlib electrotest
	install electrotest /usr/local/bin

installlib: lib1 lib2 lib3
	install lib/libpower.so /usr/local/lib
	install lib/libresistance.so /usr/local/lib
	install lib/libcomponent.so /usr/local/lib

uninstall:
	rm -f  /usr/local/lib/libpower.so
	rm -f /usr/local/lib/libresistance.so
	rm -f /usr/local/lib/libcomponent.so
	rm -f /usr/local/bin/electrotest


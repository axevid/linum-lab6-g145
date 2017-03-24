# Makefile for testresistance and libresistance .so

CC = gcc

all:	testresistance libresistance.so

testresistance:	test_libresistance.c libresistance.so
	$(CC) -Wall -o testresistance test_libresistance.c -L/home/antero/tests/harj6/linum-lab6-g145/src/lib1  -lresistance -lm

libresistance.o:	libresistance.c libresistance.h 
#	$(CC) -c -shared -fPIC libresistance.c -lm -o libresistance.so libresistance.o
	$(CC) -c -o libresistance.o libresistance.c -lm
libresistance.so:
	$(CC) -c -shared -fPIC libresistance.c 
	$(CC) -shared -o libresistance.so libresistance.o
clean:
	rm -f libresistance.so libresistance.o testresistance libresistance.so

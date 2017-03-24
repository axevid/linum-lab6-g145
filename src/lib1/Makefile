# .o file - the unlinked output of the compiler - an object file

# .a - out of using ar to pack several .o files into an object archive file. It is an efficient way of keeping track of and being able to access object modules during the link edit phase of compilation.

# .so - shared object library - created by the linker from .o files. These shared libraries
# are loaded into memory and accessed (all at one time) by lots of processes in the system. This saves memory.


CC = gcc
LIBFLAG = -L. -lgdb -Wl,-rpath,.

all:	testresistance libresistance.so

testresistance:	test_libresistance.c libresistance.o
	ar crv libresistance.a libresistance.o
	$(CC) test_libresistance.c libresistance.o  -o testresistance -L -lresistance -lm

libresistance.o:	libresistance.c libresistance.h 
#	$(CC) -c -shared -fPIC libresistance.c -lm -o libresistance.so libresistance.o
	$(CC) -c -o libresistance.o libresistance.c -lm
libresistance.so:
	$(CC) -c -shared -fPIC libresistance.c -lm -o libresistance.so
clean:
	rm -f libresistance.so libresistance.o testresistance libresistance.a libresistance.so

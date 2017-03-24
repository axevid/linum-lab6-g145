# .o file - the unlinked output of the compiler - an object file

# .a - out of using ar to pack several .o files into an object archive file. It is an efficient way of keeping track of and being able to access object modules during the link edit phase of compilation.

# .so - shared object library - created by the linker from .o files. These shared libraries
# are loaded into memory and accessed (all at one time) by lots of processes in the system. This saves memory.


CC = gcc
LIBFLAG = -L. -lgdb -Wl,-rpath,.

all:	testpower

testpower:	test_libpower.c libpower.o
	ar crv libpower.a libpower.o
	$(CC) test_libpower.c libpower.o  -o testpower -L -lpower -lm

libpower.o:	libpower.c libpower.h 
#	$(CC) -c -shared -fPIC libpower.c -lm -o libpower.so libpower.o
	$(CC) -c -o libpower.o libpower.c -lm

clean:
	rm -f libpower.so libpower.o testpower libpower.a

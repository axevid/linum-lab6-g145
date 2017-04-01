# .o file - the unlinked output of the compiler - an object file

# .a - out of using ar to pack several .o files into an object archive file. It is an efficient way of keeping track of and being able to access object modules during the link edit phase of compilation.

# .so - shared object library - created by the linker from .o files. These shared libraries
# are loaded into memory and accessed (all at one time) by lots of processes in the system. This saves memory.


CC = gcc

all:	testpower

testpower:	test_libpower.c libpower
	ar rcs libpower.a libpower.o
	$(CC) -static test_libpower.c -o testpower -L. -lpower -lm

libpower:	libpower.c libpower.h 
	$(CC) -c -fPIC libpower.c -lm
	$(CC) -shared -o libpower.so libpower.o -lm

install: libpower.so
	install libpower.so /usr/lib

uninstall: 
	rm -f /usr/lib/libpower.so

clean:
	rm -f libpower.so libpower.o testpower libpower.a

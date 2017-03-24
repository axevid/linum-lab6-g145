CC = gcc
LIBFLAG = -L. -lgdb -Wl,-rpath,.

all:	testpower

program:	main.c libpower.so
		$(CC) -g -o testpower test_libpower.c $(LIBFLAG)

libpower.so:	libpower.c libpower.h 
		$(CC) -g -c -fPIC libpower.c
		$(CC) -g -shared -fPIC -o libpower.so libpower.o

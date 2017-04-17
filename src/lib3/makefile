CC = gcc

all: test_libcomponent

test_libcomponent: test_libcomponent.c libcomponent.so

	$(CC) -o test_libcomponent test_libcomponent.c -L. libcomponent.so -Wl,-rpath,.

libcomponent.so: libcomponent.c
	$(CC) -c -fPIC libcomponent.c
	$(CC) -shared -fPIC -o libcomponent.so libcomponent.o
	rm libcomponent.o

.PHONY: lib
lib:
	$(CC) -c -fPIC libcomponent.c
	$(CC) -shared -fPIC -o libcomponent.so libcomponent.o
	rm libcomponent.o

.PHONY: clean
clean:
	rm *o test_libcomponent

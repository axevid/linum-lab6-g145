CC = gcc

objects = test_libcomponent.o libcomponent.so

all: test_libcomponent

test_libcomponent: $(objects)
	$(CC) -o test_libcomponent test_libcomponent.c -L. libcomponent.so -Wl,-rpath,.

test_libcomponent.o: test_libcomponent.c
	$(CC) -c libcomponent.c

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

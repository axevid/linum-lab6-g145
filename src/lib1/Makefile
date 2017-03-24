# Makefile for testresistance and libresistance.so

all:	testresistance libresistance.so

# Which complier
CC = gcc

# Where to install
INSTDIR = /usr/local/lib

# Where are include files kept
INCLUDE = .

# Options
CFLAGS = -O -Wall

testresistance:	test_libresistance.c libresistance.so
	$(CC) $(CFLAGS) -o testresistance test_libresistance.c -lresistance -lm

libresistance.so:
	$(CC) $(CFLAGS) -c -shared -fPIC libresistance.c 
	$(CC) -shared -o libresistance.so libresistance.o
clean:
	rm -f libresistance.so libresistance.o testresistance libresistance.so
install: libresistance.so
	@if [ -d $(INSTDIR) ]; \
	then \
	cp libresistance.so $(INSTDIR);\
	chmod a+x $(INSTDIR)/libresistance.so;\
	chmod og-w $(INSTDIR)/libresistance.so;\
	echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi
	ldconfig
uninstall:
	@echo "Uninstalling $(INSTDIR)/program1" ;\
	rm -f $(INSTDIR)/libresistance.so;
	ldconfig

# Makefile for testresistance and libresistance.so

# Which complier
CC = gcc

# Where to install
INSTDIR = /usr/local/lib
BININSTDIR = /usr/local/bin
# Where are include files kept
INCLUDE = .

# Options
CFLAGS = -O -Wall

all:	libresistance.so test_libresistance.c 
	$(CC) $(CFLAGS) -o test_libresistance test_libresistance.c -L$(CURDIR)/lib -lm -Wl,-rpath=$(LD_LIBRARY_PATH)$(CURDIR)/lib: -lresistance 


lib: libresistance.so

libresistance.so:
	mkdir -p $(CURDIR)/lib	
	$(CC) $(CFLAGS) -c -shared -fPIC libresistance.c 
	$(CC) -shared -o $(CURDIR)/lib/libresistance.so libresistance.o 

clean:
	rm -f $(CURDIR)/lib/libresistance.so libresistance.o test_libresistance libresistance.so test_libresistance_install
install: lib
	$(CC) $(CFLAGS) -o test_libresistance_install test_libresistance.c -lm -lresistance -L$(CURDIR)/lib
	@if [ -d $(INSTDIR) ]; \
	then \
	cp $(CURDIR)/lib/libresistance.so $(INSTDIR);\
	chmod a+x $(INSTDIR)/libresistance.so;\
	chmod og-w $(INSTDIR)/libresistance.so;\
	echo "Library installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist";\
	fi
	@if [ -d $(BININSTDIR) ]; \
	then \
	cp $(CURDIR)/test_libresistance_install $(BININSTDIR)/test_libresistance;\
	chmod a+x $(BININSTDIR)/test_libresistance;\
	chmod og-w $(BININSTDIR)/test_libresistance;\
	echo "Test binary installed in $(BININSTDIR)";\
	else \
		echo "Sorry, $(BININSTDIR) does not exist";\
	fi
	ldconfig

uninstall:
	@echo "Uninstalling $(INSTDIR)/program1" ;\
	rm -f $(INSTDIR)/libresistance.so;
	ldconfig

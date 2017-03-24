# Makefile for testresistance and libresistance.so
# Note that clean for subdirs and install are missing

# Which complier
CC = gcc

# Where are include files kept
#INCLUDE = .

# Options
CFLAGS = -O -Wall
SUBDIRS = lib1 lib2

all:	electrotest

.PHONY:	subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)

$(SUBDIRS):	
	$(MAKE) -C $@

electrotest:	subdirs electrotest.c 
	$(CC) $(CFLAGS) -o electrotest electrotest.c -lresistance -lm

.PHONY:	clean

clean:
	rm -f electrotest.o electrotest


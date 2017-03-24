# Makefile for testresistance and libresistance.so

all:	electrotest

# Which complier
CC = gcc

# Where are include files kept
#INCLUDE = .

# Options
CFLAGS = -O -Wall

electrotest:	electrotest.c 
	$(CC) $(CFLAGS) -o electrotest electrotest.c -lresistance -lm
clean:
	rm -f electrotest.o electrotest


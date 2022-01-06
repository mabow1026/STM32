CC = gcc
TARGET = a.out
TLIB = libvec.a
LIBS = -lvec -lm
CFLAGS = -O2 -Wall
OBJECTS = addvec.o avevec.o calcabs.o cmulvec.o inputvec.o printvec.o sumvec.o testfunc.o calcsquare.o subvec.o mulvec.o innervec.o calclen.o printvecrow.o univec.o
HEADERS = vector.h
MAIN = mainTest.c

$(TARGET):   $(MAIN)  $(TLIB)  $(HEADERS)
	$(CC)   -L.   $(MAIN)   $(LIBS)

$(TLIB):  $(OBJECTS)  $(HEADERS)
	ar  -rv   $@    $?

clean:
	rm   -f   $(TLIB)  $(OBJECTS)  $(TARGET)

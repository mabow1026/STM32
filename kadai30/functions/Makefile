CC = gcc
TARGET = a.exe
TLIB = libvec.a
LIBS = -lvec -lm
CFLAGS = -O2 -Wall
OBJECTS = addvec.o avevec.o calcabs.o cmulvec.o inputvec.o printvec.o sumvec.o testfunc.o calcsquare.o subvec.o mulvec.o innervec.o calclen.o univec.o printvecrow.o
HEADERS = vector.h test.h
MAIN = mainTest.c

$(TARGET): $(MAIN)  $(TLIB)  $(HEADERS)
	$(CC) $(CFLAGS) $(MAIN) -L. $(LIBS)

$(TLIB): $(OBJECTS) $(HEADERS)
	ar -rv $@ $?

.c.o:; $(CC) $(CFLAGS) -c $<

clean:; rm -f $(TLIB) $(OBJECTS) $(TARGET)

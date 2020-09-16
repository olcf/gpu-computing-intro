CCOMP = pgcc
#CFLAGS = -acc -Minfo=acc -ta=tesla:cc70 -fast
CFLAGS = -mp -Minfo=acc -ta=tesla:cc70 -fast
CFLAGS = -qreport -Ofast -lcudart
CCOMP = xlc-gpu
CFLAGS =   -qhot -qreport -lcudart
CCOMP0 = xlc
CFLAGS0 =   -qhot -qreport 

run: triad.o
	$(CCOMP) $(CFLAGS) triad.o -o run
triad.o: triad.c
	$(CCOMP) $(CFLAGS) -c triad.c
run0: triad.o
	$(CCOMP0) $(CFLAGS0) triad.c -o run0

.PHONY: clean

clean:
	rm -f run *.o


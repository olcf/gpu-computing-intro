CCOMP = pgcc
#CFLAGS = -acc -Minfo=acc -ta=tesla:cc70 -fast
CFLAGS = -mp -Minfo=acc -ta=tesla:cc70 -fast
CFLAGS = -qreport -Ofast -lcudart
CCOMP = xlc-gpu
CFLAGS =   -qhot -qreport -lcudart
CCOMP0  = xlc
CFLAGS0  = -qhot -qreport
run: vector_addition.o
	$(CCOMP) $(CFLAGS) vector_addition.o -o run
run0: omp_vector_addition.o
	$(CCOMP) $(CFLAGS) omp_vector_addition.o -o run0

rund: dvector_addition.o
	$(CCOMP0) $(CFLAGS0) dvector_addition.o -o rund
rung: gomp_vector_addition.o
	$(CCOMP) $(CFLAGS) gomp_vector_addition.o -o rung

dvector_addition.o: dvector_addition.c
	$(CCOMP0) $(CFLAGS0) -c dvector_addition.c
omp_vector_addition.o: omp_vector_addition.c
	$(CCOMP) $(CFLAGS) -qsmp=omp -c omp_vector_addition.c

Nomp_vector_addition.o: Nomp_vector_addition.c
	$(CCOMP) $(CFLAGS) -c Nomp_vector_addition.c

gomp_vector_addition.o: gomp_vector_addition.c
	$(CCOMP) $(CFLAGS) -c gomp_vector_addition.c
.PHONY: clean

clean:
	rm -f run *.o


CCOMP = xlc-gpu
CFLAGS = -qsmp=omp -qoffload -qtgtarch=sm_70  -qhot -qreport -lcudart
CFLAGS =  -qreport -Ofast -lcudart
run: laplace2d.o
	$(CCOMP) $(CFLAGS) laplace2d.o -o run
laplace2d.o: laplace2d.c
	$(CCOMP) $(CFLAGS) -c laplace2d.c

.PHONY:clean

clean:
	rm -f *.o *.a openmp.$(OPENMP_CC).x core

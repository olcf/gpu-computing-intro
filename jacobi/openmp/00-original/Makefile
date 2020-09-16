CCOMP = xlc 
CFLAGS = -qsmp=omp -qoffload -qtgtarch=sm_70  -qhot -qreport -L${OLCF_CUDA_ROOT}/lib64 -lcudart
CFLAGS =  -qreport -Ofast -L${OLCF_CUDA_ROOT}/lib64 -lcudart
run: laplace2d.o
	$(CCOMP) $(CFLAGS) laplace2d.o -o run
laplace2d.o: laplace2d.c
	$(CCOMP) $(CFLAGS) -c laplace2d.c

.PHONY:clean

clean:
	rm -f *.o *.a openmp.$(OPENMP_CC).x core

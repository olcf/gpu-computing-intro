CCOMP = xlc
CFLAGS = -qsmp=omp -qoffload -qtgtarch=sm_70  -qhot -qreport -lcudart

CFLAGS = -qsmp=omp  -qoffload -qarch=pwr8 -qtune=pwr8 -qreport -Ofast -lcudart

CFLAGS =  -fPIC -qfloat=nomaf -qstrict=precision  -qsmp=noopt -qoffload 

run: laplace2d.o
	$(CCOMP) $(CFLAGS) laplace2d.o -o run
laplace2d.o: laplace2d.c
	$(CCOMP) $(CFLAGS) -c laplace2d.c

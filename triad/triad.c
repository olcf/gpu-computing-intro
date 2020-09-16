#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Size of array
#define N 110485760

// Main program
int main()
{
	// Number of bytes to allocate for N doubles
	size_t bytes = N*sizeof(double);
         int i;
	// Allocate memory for arrays A, B, and C on host
	double *A = (double*)malloc(bytes);
	double *B = (double*)malloc(bytes);
	double *C = (double*)malloc(bytes);
        struct timeval start_time, stop_time, elapsed_time;
         double scalar = 10.0;
	// Fill host arrays A and B
	for( i=0; i<N; i++)
	{
		A[i] = 1.0;
		C[i] = 2.0;
	}
// Start timer
	gettimeofday(&start_time, NULL);


    #pragma omp target data map (to: C[0:N], B[0:N]) map(tofrom: A[0:N])
    #pragma omp target teams distribute parallel for


    for (i=0; i<N; i++)
    {
        A[i] = B[i]+scalar*C[i];
    }
// Stop timer
	gettimeofday(&stop_time, NULL);
	timersub(&stop_time, &start_time, &elapsed_time);
	double runtime = elapsed_time.tv_sec+elapsed_time.tv_usec/1000000.0;

	printf("Elapsed Time (s): %8.4f\n", runtime);


	// Free CPU memory
	free(A);
	free(B);
	free(C);

  printf("\n---------------------------\n");
	printf("__SUCCESS__\n");
	printf("---------------------------\n");
	printf("N                 = %d\n", N);
  printf("---------------------------\n\n");

	return 0;
}

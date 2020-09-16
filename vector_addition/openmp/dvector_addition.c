#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Size of array
#define N 110485760

// Main program
int main()
{
	// Number of bytes to allocate for N integers
	size_t bytes = N*sizeof(int);
         int i;
	// Allocate memory for arrays A, B, and C on host
	int *A = (int*)malloc(bytes);
	int *B = (int*)malloc(bytes);
	int *C = (int*)malloc(bytes);

	struct timeval start_time, stop_time, elapsed_time;

	// Fill host arrays A and B
	for( i=0; i<N; i++)
	{
		A[i] = 1;
		B[i] = 2;
	}
// Start timer
	gettimeofday(&start_time, NULL);

	  for( i=0; i<N; i++)
	{
		C[i] = A[i] + B[i];
	}

// Stop timer
	gettimeofday(&stop_time, NULL);
	timersub(&stop_time, &start_time, &elapsed_time);
	double runtime = elapsed_time.tv_sec+elapsed_time.tv_usec/1000000.0;

	printf("Elapsed Time (s): %8.4f\n", runtime);

	// Verify results
	for( i=0; i<N; i++)
	{
		if(C[i] != 3)
		{ 
			printf("\nError: value of C[%d] = %d instead of 3\n\n", i, C[i]);
			exit(-1);
		}
	}	

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

#include <stdio.h>
#include <stdlib.h>

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

	// Fill host arrays A and B
	for( i=0; i<N; i++)
	{
		A[i] = 1;
		B[i] = 2;
	}

	  for( i=0; i<N; i++)
	{
		C[i] = A[i] + B[i];
	}

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

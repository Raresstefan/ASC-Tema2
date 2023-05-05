/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	double *C = malloc(N * N * sizeof(double));
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			double sum = 0;
			for (int k = i; k <= j; k++) {
				if (A[i * N + k] != RLIM_INFINITY && B[k * N + j] != RLIM_INFINITY) {
					sum += A[i * N + k] * B[k * N + j];
				}
			}
			C[i * N + j] = sum;
		}
	}
	return C;
}

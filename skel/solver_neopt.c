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
	double *AB = calloc(N * N, sizeof(double));
	double *ABA_T = calloc(N * N, sizeof(double));
	double *B_T_B_T = calloc(N * N, sizeof(double));
	double *B_T = calloc(N * N, sizeof(double));

	// compute A * B and store result in AB
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			double sum = 0;
			for (int k = i; k < N; k++) {
				sum += A[i * N + k] * B[k * N + j];
			}
			AB[i * N + j] = sum;
		}
	}

	// compute AB * A_T and store result in ABA_T
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			double sum = 0;
			for (int k = i; k < N; k++) {
				sum += AB[i * N + k] * A[j * N + k];
			}
			ABA_T[i * N + j] = sum;
		}
	}

	// compute B_T * B_T and store result in B_T_B_T
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			double sum = 0;
			for (int k = 0; k < N; k++) {
				sum += B[k * N + i] * B[k * N + j];
			}
			B_T_B_T[i * N + j] = sum;
		}
	}

	for (int i = 0; i < N;i ++) {
		for (int j = 0; j < N; j++) {
			C[i * N + j] = ABA_T[i * N + j] + B_T_B_T[i * N + j];
		}
	}
	return C;
}

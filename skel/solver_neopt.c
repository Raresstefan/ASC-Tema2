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
	// A * B
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			double sum = 0;
			for (int k = i; k <= j; k++) {
				if (A[i * N + k] != 0 && B[k * N + j] != 0) {
					sum += A[i * N + k] * B[k * N + j];
				}
			}
			AB[i * N + j] = sum;
		}
	}
	// A * B * A_T
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = j; k < N; k++) {
				ABA_T[i * N + j] += AB[i * N + k] * A[j * N + k];
			}
		}
	}
	// B_T
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			B_T[i * N + j] = B[j * N + i];
		}
	}
	// B_T * B_T
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			double sum = 0;
			for (int k = i; k <= j; k++) {
				if (B_T[i * N + k] != 0 && B_T[k * N + j] != 0) {
					sum += B_T[i * N + k] * B_T[k * N + j];
				}
			}
			B_T_B_T[i * N + j] = sum;
		}
	}
	// ABA_T + B_T_B_T
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			C[i * N + j] = ABA_T[i * N + j] + B_T_B_T[i * N + j];
		}
	}
	return C;
}

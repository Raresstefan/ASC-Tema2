/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"
#include <string.h>
/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	printf("BLAS SOLVER\n");
	double *C = malloc(N * N * sizeof(double));
	double *AB = calloc(N * N, sizeof(double));
	double *ABA_T = calloc(N * N, sizeof(double));
	double *B_T_B_T = calloc(N * N, sizeof(double));
	double *B_T = calloc(N * N, sizeof(double));
	// AB = A * B
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, A, N, B, N, 1.0, AB, N);

	// ABA_T = AB * A_T
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N, 1.0, AB, N, A, N, 1.0, ABA_T, N);

	// calculate B_T, B_T_B_T = B_T
	cblas_dgemm(CblasRowMajor, CblasTrans, CblasTrans, N, N, N, 1.0, B, N, B, N, 1.0, B_T_B_T, N);

	for (int i = 0; i < N;i ++) {
		for (int j = i; j < N; j++) {
			C[i * N + j] = ABA_T[i * N + j] + B_T_B_T[i * N + j];
		}
	}

	free(AB);
	free(ABA_T);
	free(B_T_B_T);
	free(B_T);
	return C;
}

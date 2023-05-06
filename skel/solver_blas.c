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
	memcpy(AB, B, N * N * sizeof(double));
	// AB = A * AB = A * B
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, AB, N);

	// ABA_T = AB * A_T
	memcpy(ABA_T, AB, N * N * sizeof(double));
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1.0, A, N, ABA_T, N);

	// calculate B_T, B_T_B_T = B_T
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			B_T[i * N + j] = B[j * N + i];
		}
	}
	memcpy(B_T_B_T, B_T, N * N * sizeof(double));

	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, B_T, N, B_T_B_T, N);

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

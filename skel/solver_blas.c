/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"
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
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1.0, A, N, B, N);
	cblas_dsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, N, N, 1.0, AB, N, 0.0, ABA_T, N);
	cblas_dsyrk(CblasRowMajor, CblasUpper, CblasTrans, N, N, 1.0, B, N, 0.0, B_T_B_T, N);
	cblas_daxpy(N * N, 1.0, ABA_T, 1, B_T_B_T, 1);
	cblas_dcopy(N * N, B_T_B_T, 1, C, 1);

	free(AB);
	free(ABA_T);
	free(B_T_B_T);
	free(B_T);
	return C;
}

/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");
	register double *C = NULL;
	double *AB = calloc(N * N, sizeof(double));
	double *ABA_T = calloc(N * N, sizeof(double));
	register double *A_line = NULL;
	register double *AB_line = NULL;
	
	// compute A * B and store result in AB
	for (register int i = 0; i < N; i++) {
		A_line = A + i * N + i;
		C = AB + i * N;
		for (register int j = 0; j < N; j++) {
			register double *A_line_aux = A_line;
			register double *B_col = B + i * N + j;
			register double sum = 0;
			for (register int k = i; k < N; k++) {
				sum += *A_line_aux * *B_col;
				B_col += N;
				A_line_aux++;
			}
			*C = sum;
			C++;
		}
	}

	// compute AB * A_T and store result in ABA_T
	for (register int i = 0; i < N; i++) {
		AB_line = AB + i * N;
		C = ABA_T + i * N;
		for (register int j = 0; j < N; j++) {
			register double *AB_col_j = AB_line + j;
			register double *A_line_j = A + j * N + j;
			register double sum = 0;
			for (register int k = j; k < N; k++) {
				sum += *AB_col_j * *A_line_j;
				AB_col_j++;
				A_line_j++;
			}
			*C = sum;
			C++;
		}
	}

	// compute ABA_T + B_T * B_T and store result in C
	for (register int i = 0; i < N; i++) {
		register double *B_line_i = B + i;
		C = ABA_T + i * N;
		for (register int j = 0; j < N; j++) {
			register double *B_line_aux = B_line_i;
			register double *B_line_j = B + j * N;
			register double sum = *C;
			for (register int k = 0; k < N; k++) {
				sum += *B_line_aux * *B_line_j;
				B_line_aux += N;
				B_line_j++;
			}
			*C = sum;
			C++;
		}
	}
	free(AB);
	return ABA_T;	
}

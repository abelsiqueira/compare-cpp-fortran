#include "dense.h"
#include <stdlib.h>
#include <stdio.h>

dense * create_dense (int nrow, int ncol) {
  dense * A;
  int i, n;

  A = (dense *) malloc (sizeof(dense));
  A->nrow = nrow;
  A->ncol = ncol;
  n = nrow*ncol;
  A->x = (double *) malloc (sizeof(double) * n);
  for (i = 0; i < n; i++)
    A->x[i] = 0.0;

  return A;
}

void destroy_dense (dense ** A) {
  free(*A);
  *A = 0;
}

dense * read_dense () {
  int m, n, k, i, j;
  double x;
  dense *A;

  A = (dense *) malloc (sizeof(dense));
  scanf("%d %d", &m, &n);
  k = m*n;
  A->nrow = m;
  A->ncol = n;
  A->x = (double *) malloc (sizeof(double) * k);
  for (i = 0; i < k; i++) {
    scanf("%lf", &x);
    A->x[i] = x;
  }

  return A;
}

void print_dense (dense * A, char * name) {
  int i, j;
  printf("%s = \n", name);
  for (i = 0; i < A->nrow; i++) {
    for (j = 0; j < A->ncol; j++) {
      printf(" %5.2lf", A->x[i*A->ncol + j]);
    }
    printf("\n");
  }
}

void lu_factorization (dense * A) {
  int i, j, k;
  double ajj, aij;
  double * restrict px = A->x;

  for (j = 0; j < A->ncol; j++) {
    ajj = px[j*A->ncol + j];
    for (i = j+1; i < A->nrow; i++) {
      px[i*A->ncol + j] /= ajj;
      aij = px[i*A->ncol + j];
      for (k = j+1; k < A->ncol; k++) {
        px[i*A->ncol + k] -= px[j*A->ncol + k] * aij;
      }
    }
  }
}

void solve_lu (dense * LU, dense * rhs) {
  int i, j, n = LU->nrow;
  double * restrict px = rhs->x;

  for (i = 0; i < n; i++)
    for (j = 0; j < i; j++)
      px[i] -= LU->x[i*LU->ncol + j] * px[j];

  for (i = n-1; i >= 0; i--) {
    for (j = i+1; j < n; j++)
      px[i] -= LU->x[i*LU->ncol + j] * px[j];
    px[i] /= LU->x[i*LU->ncol + i];
  }
}


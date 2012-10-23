#include "dense.h"
#include <stdio.h>

int main () {
  int i, j, t, n;
  dense *A, *LU, *x, *b;
  double s = 0.0, xi;

  t = 10;

  A = read_dense ();
  b = read_dense ();

  n = b->nrow;

  for (j = 0; j < t; j++) {
    LU = copy_dense(A);
    x  = copy_dense(b);

    lu_factorization(LU);
    solve_lu(LU, x);

    for (i = 0; i < n; i++) {
      xi = x->x[i] - 1;
      s += xi*xi;
    }
    destroy_dense(&x);
    destroy_dense(&LU);
  }
  
  printf("|x - e|^2 = %10.8lf\n", s);

  destroy_dense(&b);
  destroy_dense(&A);

  return 0;
}

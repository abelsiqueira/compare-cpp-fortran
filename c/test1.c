#include "dense.h"
#include <stdio.h>

int main () {
  int i, n;
  dense *A, *x;
  double s = 0.0, xi;

  A = read_dense ();
  x = read_dense ();

  lu_factorization(A);
  solve_lu(A, x);
//  print_dense(x, "x");

  n = x->nrow;

  for (i = 0; i < n; i++) {
    xi = x->x[i] - 1;
    s += xi*xi;
  }
  
  printf("|x - e|^2 = %10.8lf\n", s);

  destroy_dense(&x);
  destroy_dense(&A);

  return 0;
}

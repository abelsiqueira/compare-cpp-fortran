#include "dense.h"
#include "vector.h"

int main () {
  Dense A;
  Vector x, y;

  A.Read();
  x.Read();
  y.DenseMult(A, x);
}

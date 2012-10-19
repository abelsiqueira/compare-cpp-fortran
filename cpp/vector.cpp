#include "vector.h"
#include "dense.h"

void Vector::Read (std::istream & in) {
  in >> size;
  if (size == 0)
    return;
  if (x != 0)
    delete []x;

  x = new float[size];
  for (size_t i = 0; i < size; i++)
    in >> x[i];
}

void Vector::Print (std::ostream & out) const {
  for (size_t i = 0; i < size; i++)
    out << x[i] << std::endl;
}

void Vector::DenseMult (const Dense & A, const Vector & v) {
  if (x == 0) {
    x = new float[A.nrow];
    size = A.nrow;
  } else if (size != A.nrow) {
    delete []x;
    x = new float[A.nrow];
    size = A.nrow;
  }
  size_t k = 0;
  for (size_t i = 0; i < A.nrow; i++) {
    x[i] = 0;
    for (size_t j = 0; j < A.ncol; j++) {
      x[i] += A.A[k++]*v.x[j];
    }
  }
}

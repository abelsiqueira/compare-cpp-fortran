#include "dense.h"
#include <iomanip>

void Dense::Read (std::istream & in) {
  in >> nrow >> ncol;
  if ( !nrow || !ncol )
    return;

  if (A != 0)
    delete []A;
  A = new float[nrow*ncol];

  size_t k = 0;
  for (size_t i = 0; i < nrow; i++) {
    for (size_t j = 0; j < ncol; j++) {
      in >> A[k++];
    }
  }
}

void Dense::Print (std::ostream & out) const {
  size_t k = 0;
  for (size_t i = 0; i < nrow; i++) {
    for (size_t j = 0; j < ncol; j++) {
      out << std::setw(3) << A[k++] << ' ';
    }
    out << std::endl;
  }
}

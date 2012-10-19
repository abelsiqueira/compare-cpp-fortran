#ifndef dense_h
#define dense_h

#include <iostream>
#include "vector.h"

class Dense {
  public:
    Dense () : ncol(0), nrow(0), A(0) { }
    Dense (size_t m, size_t n, float * x) : ncol(n), nrow(m) {
      size_t k = m*n;
      A = new float[k];
      for (size_t i = 0; i < k; i++)
        A[i] = x[i];
    }
    ~Dense () {
      if (A != 0)
        delete []A;
    }

    void Read (std::istream & = std::cin);
    void Print (std::ostream & = std::cout) const;

    float Get(size_t i, size_t j) const {
      return A[ncol*(i-1) + j - 1];
    }
    void Set(size_t i, size_t j, float x) {
      A[ncol*(i-1) + j - 1] = x;
    }
    friend class Vector;
  private:
    size_t ncol, nrow;
    float *A;
};

#endif

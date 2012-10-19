#ifndef vector_h
#define vector_h

#include <iostream>

class Dense;

class Vector {
  public:
    Vector () : size(0), x(0) { }
    Vector (size_t n, float * y) : size(n) {
      x = new float[n];
      for (size_t i = 0; i < n; i++)
        x[i] = y[i];
    }
    ~Vector () {
      if (x != 0)
        delete []x;
    }

    void Read (std::istream & = std::cin);
    void Print (std::ostream & = std::cout) const;

    float Get(size_t i) {
      return x[i-1];
    }
    void Set(size_t i, float a) {
      x[i-1] = a;
    }

    void DenseMult (const Dense & A, const Vector & x);
  private:
    size_t size;
    float *x;
};


#endif

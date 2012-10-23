#ifndef dense_h
#define dense_h

typedef struct _dense {
  double * x;
  int nrow, ncol;
} dense;

dense * create_dense (int nrow, int ncol);
void destroy_dense (dense ** A);
dense * read_dense ();
dense * copy_dense (dense *A);
void print_dense (dense * A, char * name);
void lu_factorization (dense * A);
void solve_lu (dense * LU, dense * rhs);

#endif

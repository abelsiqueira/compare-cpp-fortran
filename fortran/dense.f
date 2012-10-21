C     Dense Subroutines

      subroutine dense_print (A, nmax, nrow, ncol)

      implicit none

      integer nrow, ncol, nmax
      real A(nmax,*)

      integer i, j

      do i = 1,nrow
        write (*,"(100g15.5)") ( A(i,j), j = 1,ncol )
      enddo

      end

C     *******************************************
C     *******************************************

      subroutine lu_factorization (A, nmax, nrow, ncol)

      implicit none

      integer nrow, ncol, nmax
      real A(nmax,*)

      integer i, j, k

      do j = 1,nrow
        do i = j+1,nrow
          A(i,j) = A(i,j)/A(j,j)
          do k = j+1,ncol
            A(i,k) = A(i,k) - A(j,k) * A(i,j)
          enddo
        enddo
      enddo

      end
      
C     *******************************************
C     *******************************************

      subroutine lu_solve (LU, x, nmax, nvar)

      implicit none

      integer nmax, nvar
      real LU(nmax,*)
      real x(*)

      integer i, j

      do i = 1,nvar
        do j = 1,i-1
          x(i) = x(i) - LU(i,j)*x(j)
        enddo
      enddo

      do i = nvar,1,-1
        do j = i+1,nvar
          x(i) = x(i) - LU(i,j)*x(j)
        enddo
        x(i) = x(i)/LU(i,i)
      enddo


      end

      program main

      parameter (nmax=10000)

      real A(nmax,nmax), LU(nmax,nmax)
      real x(nmax), b(nmax)
      real s

      integer nrow, ncol, t
      integer i, j, k


      read (*,*) nrow, ncol
      if ( (nrow.gt.nmax) .or. (ncol.gt.nmax) ) then
        write(*,*) 'Increase nmax'
        stop
      endif
      do i = 1,nrow
        read (*,*) ( A(i,j), j = 1,ncol )
      enddo

      read (*,*) nrow, ncol
      do i = 1, nrow
        read (*,*) b(i)
      enddo

      t = 10
      s = 0.0D0

      do k = 1,t
        do i = 1,nrow
          x(i) = b(i)
          do j = 1,nrow
            LU(i,j) = A(i,j)
          enddo
        enddo

        call lu_factorization(LU, nmax, nrow, nrow)

        call lu_solve(LU, x, nmax, nrow)

        do i = 1,nrow
          s = s + (x(i) - 1.0D0) ** 2
        enddo
      enddo

      write (*,*) '|x - e|^2 = ', s

      end

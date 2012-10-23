      program main

      parameter (nmax=10000)

      real A(nmax,nmax)
      real x(nmax)
      real s

      integer nrow, ncol

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
        read (*,*) x(i)
      enddo

      call lu_factorization(A, nmax, nrow, nrow)

      call lu_solve(A, x, nmax, nrow)

      s = 0.0D0

      do i = 1,nrow
        s = s + (x(i) - 1.0D0) ** 2
      enddo

      write (*,*) '|x - e|^2 = ', s

      end

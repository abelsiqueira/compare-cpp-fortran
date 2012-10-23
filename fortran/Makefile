TESTS = test1.tst test2.tst
FFLAGS = 

all: dense.o $(TESTS)

clean:
	rm -f *.o *.tst

purge: clean


%.tst: %.f dense.o
	gfortran $< -o $@ $(FFLAGS) dense.o

%.o: %.f
	gfortran -c $< -o $@ $(FFLAGS)

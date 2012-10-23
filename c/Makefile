TESTS = test1.tst test2.tst
CFLAGS = -std=c99

all: dense.o $(TESTS)

clean:
	rm -f *.o *.tst

purge: clean


%.tst: %.c dense.o
	gcc $< -o $@ $(CFLAGS) dense.o

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS)

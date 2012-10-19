CXXFLAGS = -Wall -Wextra -ggdb
OBJS = vector.o dense.o

all: $(OBJS) test1.o
	g++ $(OBJS) test1.o -o test1.tst $(CXXFLAGS)
	./test1.tst < ../Tests/test1.in

clean:
	rm -f *.o *.tst

%.o: %.cpp
	g++ -c -o $@ $< $(CXXFLAGS)

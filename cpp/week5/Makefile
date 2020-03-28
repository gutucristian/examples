CC=c++
CXXFLAGS=-g --std=c++14

all: rval rvalInClass

rval: rval.o
	$(CC) $(CXXFLAGS) -o $@ $^

rvalInClass: rvalInClass.o
	$(CC) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.o *~ rval


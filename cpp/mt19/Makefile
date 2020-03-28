CC=c++
CXXFLAGS=-g --std=c++14

all: q1a q1c

q1a: q1a.o
	$(CC) -o $@ $(CXXFLAGS) $<

q1c: q1c.o
	$(CC) -o $@ $(CXXFLAGS) $<

clean:
	rm -rf *.o *~ q1a q1c


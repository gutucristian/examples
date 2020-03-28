CC=c++
CFLAGS=-g --std=c++14

all: poly1 poly2

poly1: poly1.o
	$(CC) -o $@ $(LFLAGS) $<

poly2: poly2.o
	$(CC) -o $@ $(LFLAGS) $<

%.o:%.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf *.o *~ poly1 poly2


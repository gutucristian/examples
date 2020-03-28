CC=c++
CFLAGS=-g -std=c++14
OFILES = graph.o

all: graph

graph.o : graph.cpp
	$(CC) -c $(CFLAGS) $<

graph: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

clean:
	rm -rf *.o graph *~

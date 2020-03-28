CC=c++
CFLAGS=-g -std=c++14
OFILES = action.o model.o main.o

all: svg 

model.o : model.cpp model.hpp
	$(CC) -c $(CFLAGS) $<

action.o: action.cpp action.hpp
	$(CC) -c $(CFLAGS) $<

main.o : main.cpp model.hpp action.hpp
	$(CC) -c $(CFLAGS) $<

svg: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

clean:
	rm -rf *.o *~ svg

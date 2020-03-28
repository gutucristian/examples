CC=c++
CFLAGS=-g -std=c++14
OFILES= main.o 

all: expr 

expr: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

clean:
	@rm -rf *.o *~ expr *.dSYM


CC=c++
CFLAGS=-g -std=c++14
OFILES= main.o recipient.o

all: mmerge 

mmerge: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

clean:
	@rm -rf *.o *~ mmerge *.dSYM


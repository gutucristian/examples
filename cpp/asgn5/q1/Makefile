CC=c++
CFLAGS=-std=c++14 -g
OFILES=List.o test.o

all:  list

list: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

%.o:%.cpp *.h
	$(CC) -c $(CFLAGS) $< 

clean:
	@echo "Cleanup..." 
	rm -rf *.o *~ *.core list

CC=c++
CFLAGS=-std=c++14
OFILES=List.o test.o

all:  list

list: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

%.o:%.cpp *.h
	$(CC) -c $(CFLAGS) $< 

clean:
	@echo "Cleanup..." 
	rm -rf *.o *~ *.core list

CC=c++
CFLAGS+=-std=c++14
OFILES=UF.o uftest.o

all:  uf

uf: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $@

%.o:%.cpp *.h
	$(CC) -c $(CFLAGS) $< 

clean:
	@echo "Cleanup..." 
	rm -rf *.o *~ *.core uf

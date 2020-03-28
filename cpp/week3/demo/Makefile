CC=c++
CFLAGS= -g -I. -std=c++14
LFLAGS= -g
OFILES= student.o main9.o

all: grade

grade: $(OFILES)
	$(CC) $(LFLAGS) $(OFILES) -o grade

student.o : student.cpp student.H 
	$(CC) -c $(CFLAGS) $<

main9.o : main9.cpp
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o *~

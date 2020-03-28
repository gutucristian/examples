CC=c++
CFLAGS=-g --std=c++14
Q1OFILES=q1.o
Q2OFILES=q2.o
Q3OFILES=q3.o
Q4OFILES=q4.o

all: q1 q2 q3 q4

q1: $(Q1OFILES)
	$(CC) $(CFLAGS) -o $@ $(Q1OFILES)

q2: $(Q2OFILES)
	$(CC) $(CFLAGS) -o $@ $(Q2OFILES)

q3: $(Q3OFILES)
	$(CC) $(CFLAGS) -o $@ $(Q3OFILES)

q4: $(Q4OFILES)
	$(CC) $(CFLAGS) -o $@ $(Q4OFILES)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

clean:
	@rm -rf *.o *~ q1 q2 q3 q4 *.dSYM


CC=c++
CFLAGS=-g -std=c++14


all: prod pal1 pal2

prod: prod.cpp
	$(CC) $(CFLAGS) $< -o $@

pal1: pal1.cpp
	$(CC) $(CFLAGS) $< -o $@

pal2: pal2.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *~


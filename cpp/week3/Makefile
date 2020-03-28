CC=c++
CFLAGS=	-g -I. -std=c++14
LFLAGS=	-g
OFILES=	main.o product.o order.o

all:	invoice

invoice:	$(OFILES)
		$(CC)	$(LFLAGS)	$(OFILES)	-o	invoice

product.o:	product.cpp	product.H
		$(CC)	-c $(CFLAGS)	$<

order.o:	order.cpp	order.H
		$(CC)	-c $(CFLAGS)	$<

main.o:	main.cpp
		$(CC)	-c $(CFLAGS)	$<

clean:
		rm -rf *.o *~ invoice

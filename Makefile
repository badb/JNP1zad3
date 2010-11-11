CC = g++
DEBUGOROPTIMALIZE = -DNDEBUG -O2
ifeq ($(debuglevel),1)
	DEBUGOROPTIMALIZE = -g
endif
CFLAGS = -Wall -c $(DEBUGOROPTIMALIZE)


all: rational.cc rational.h
	$(CC) $(CFLAGS) rational.cc -o rational.o

test: tescik.cc
	$(CC) $(CFLAGS) tescik.cc -o tescik.o
	$(CC) tescik.o rational.o -o $@

clean:
	rm -f *.o *~ *.swp *.gch

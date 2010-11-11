CC = g++
DEBUGOROPTIMALIZE = -DNDEBUG -O2
ALL = rational
ifeq ($(debuglevel),1)
	DEBUGOROPTIMALIZE = -g
endif
CFLAGS = -Wall -c $(DEBUGOROPTIMALIZE)


all: $(ALL)
	$(CC) $(CFLAGS) -o $<


%.o : %.cc %.h
	$(CC) $(CFLAGS) $< -o $@

$(ALL) : % : %.o

clean:
	rm -f *.o $(ALL) *~ *.swp *.gch

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

NonReserved : mainNonReserved.o NonReserved.o
	$(CC) $(LFLAGS) mainNonReserved.o NonReserved.o -o NonReserved

mainNonReserved.o : mainNonReserved.cpp NonReserved.cpp
	$(CC) $(CFLAGS) mainNonReserved.cpp

NonReserved.o : NonReserved.cpp NonReserved.h
	$(CC) $(CFLAGS) NonReserved.cpp

clean:
	\rm *.o NonReserved


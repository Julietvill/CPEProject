CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Reserved : mainReserved.o Reserved.o
	$(CC) $(LFLAGS) mainReserved.o Reserved.o -o Reserved

mainReserved.o : mainReserved.cpp Reserved.cpp
	$(CC) $(CFLAGS) mainReserved.cpp

Reserved.o : Reserved.cpp Reserved.h
	$(CC) $(CFLAGS) Reserved.cpp

clean:
	\rm *.o Reserved

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

CPE400 : main.o Graph.o
	$(CC) $(LFLAGS) main.o Graph.o -o CPE400

main.o : main.cpp Graph.cpp
	$(CC) $(CFLAGS) main.cpp

Graph.o : Graph.cpp Graph.h
	$(CC) $(CFLAGS) Graph.cpp

clean:
	\rm *.o CPE400

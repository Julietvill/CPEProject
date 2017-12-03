CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

CPE400 : main.o graph.o
	$(CC) $(LFLAGS) main.o graph.o -o CPE400

main.o : main.cpp graph.cpp
	$(CC) $(CFLAGS) main.cpp

graph.o : graph.cpp graph.h
	$(CC) $(CFLAGS) graph.cpp

clean:
	\rm *.o CPE400


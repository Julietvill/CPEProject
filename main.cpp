#include <iostream>
#include <fstream>
#include "Graph.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]){
	srand(time(NULL));
	MainNetwork simulation(argv[1]);
	Car testing;

	for( int i = 0; i < 1000; i++)
	{
		testing.source = rand() % 8;
		testing.destination = rand() % 8;
		while( testing.source == testing.destination)
		{
			testing.destination = rand() % 8;
		}
		//cout << "From: " << testing.source << " To: " << testing.destination << endl;
		simulation.addCar( testing );
	}
	/*
	
		testing.source = 6;
		testing.destination = 7;
		testing.crash = false;
		testing.congested = false;
		cout << "From: " << testing.source << " To: " << testing.destination << endl;
		simulation.addCar( testing );
	*/	
		simulation.sendPath();
	

	return 0;
}
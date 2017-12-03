#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]){

	MainNetwork simulation(argv[1]);
	Car testing;
	testing.source = 2;
	testing.destination = 7;
	testing.crash = false;
	testing.congested = false;
	simulation.addCar( testing );

	return 0;
}
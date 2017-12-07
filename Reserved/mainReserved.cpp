#include <iostream>
#include <fstream>
#include "Reserved.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
/**
 * @brief  main for program
 *
 * @details  Takes in file from command line, loops through statically choosen
 *			 number of cars which will traverse the graph
 * 
 * @pre  Properly formated text file, in the form of a 2D array. 
 *
 * @post  full program ran, with activly changing edge values for car to take
 * 
 * @exception None.
 *
 * @param [in]  char* argv[]
 *				  char pointer to array of chars containing command line 
 *				  arguments
 *
 * @return return 0
 * 
 **/
int main(int argc, char* argv[]){
	
	srand(time(NULL));
	MainNetwork simulation(argv[1]);
	Car testing;


	for( int i = 0; i < 10000; i++)
	{
		testing.source = rand() % simulation.getSize();
		cout << testing.source << endl;
		testing.destination = rand() % simulation.getSize();
		while( testing.source == testing.destination)
		{
			testing.destination = rand() % simulation.getSize();
		}
		simulation.addCar( testing );
	}
	simulation.sendPath();
	
	

	return 0;
}

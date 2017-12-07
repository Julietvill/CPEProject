#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int randomNumber = rand() % 35 + 15;
	int edge = 0;
	int graph[randomNumber][randomNumber];


	for(int i = 0; i < randomNumber; i++)
	{
		for( int j = 0; j < randomNumber; j++)
		{
			edge = rand() % 35 + 1;
			graph[i][j] = edge;
			graph[j][i] = edge;
		}
	}



	ofstream testFile;
	testFile.open( argv[1] );
	testFile << randomNumber << endl;
	for( int i = 0; i < randomNumber; i++)
	{
		for(int j = 0; j < randomNumber; j++)
		{
			testFile << graph[i][j] << " ";
		}
		testFile << endl;
	}

	testFile.close();
	return 0;
}

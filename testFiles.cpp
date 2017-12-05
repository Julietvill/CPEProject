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
	int x = 0;
	int y = 0;
	int graph[randomNumber][randomNumber];


	for( int i = 0; i < randomNumber; i++)
	{
		for(int j = 0; j < randomNumber; j++)
			graph[i][j] = 0;
	}
	int index = rand() % randomNumber/4 + (randomNumber/4*3);

	for( int i = 0; i < index; i++)
	{
		x = rand() % randomNumber;
		y = rand() % randomNumber;
		while( x == y )
			y = rand() % randomNumber;
		edge = rand() % 100 + 15;
		graph[x][y] = edge;
		graph[y][x] = edge;
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

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>		
#include <limits.h>		//creates really small numbers
#include <time.h> 		//Keep track of cars and create random numbers

#include <vector>		//To use Vectors
#include <queue>		//To use Queues

#include <fstream>

using namespace std;


/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
MainNetwork::MainNetwork(char* textFile){
	ifstream inFile(textFile);
	
	while( !inFile.eof() )
	{
		for( int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				inFile >> graph[i][j].dist;
			}
		}

	}
	inFile.close();
}

/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
void MainNetwork::addCar( Car newCar ){
	listOfCars.push_back( newCar );
	sendPath( newCar );
}


void printSolution(int dist[], int n)
{
printf("Vertex Distance from Source\n");
for (int i = 0; i < n; i++)
	printf("%d tt %d\n", i, dist[i]);
}

/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
void MainNetwork::sendPath(Car &workingCar ){
	int dist[9];
	vector<int> paths[9];

	dijkstra( dist, paths, workingCar.source);
	workingCar.CurrentPath = paths[ workingCar.destination ];

	//This is just for debugging purposes
	printSolution( dist, 9 );
	for(int i = 0; i < 9; i++)
	{
		cout << "Path " << i << ": " << endl;
		for(vector<int>::iterator iterate = paths[i].begin(); iterate != paths[i].end(); iterate++)
		{
			cout << *iterate << ' ';
		}
		cout << endl;
	}
}


/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
int MainNetwork::minDistance(int dist[], bool sptSet[]){
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < 9; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	}

	return min_index;
}


/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
void MainNetwork::dijkstra(int dist[9], vector<int> paths[9], int src)
{

	bool sptSet[9]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < 9; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < 9-1; count++)
	{
	// Pick the minimum distance vertex from the set of vertices not
	// yet processed. u is always equal to src in first iteration.
	int u = minDistance(dist, sptSet);

	// Mark the picked vertex as processed
	sptSet[u] = true;

	// Update dist value of the adjacent vertices of the picked vertex.
	for (int v = 0; v < 9; v++)

		// Update dist[v] only if is not in sptSet, there is an edge from 
		// u to v, and total weight of path from src to v through u is 
		// smaller than current value of dist[v]
		if (!sptSet[v] && graph[u][v].dist && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v].dist < dist[v])
		{
			dist[v] = dist[u] + graph[u][v].dist;
			paths[v].push_back( u );
		}

	}
	for(int i = 0; i < 9; i++)
	{
		paths[i].push_back( i );
	}
}

/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
void MainNetwork::updatePath(Car &working, bool newSource){

}

/**
 * @brief 
 *
 * @details 
 *          
 * @pre 
 *
 * @post 
 * 
 * @exception 
 *
 * @param [in] 
 *
 * @return 
 * 
 **/
void MainNetwork::updateSource(){

}
#include "graph.h"
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;


MainNetwork::MainNetwork(){
	
}

void MainNetwork::SendPath(Car &workingCar){

	queue<int> bestPath = CalculateBestPath( workingCar );
	workingCar.CurrentPath = bestPath;
}


void MainNetwork::updatePath(Car &workingCar, bool newSource){

}

queue<int> MainNetwork::CalculateBestPath(Car workingCar ){
//this will run dijkstra's or A* which ever one we choose

}


/*
This will add a new car to the list of cars that the MainNetwork is currently working with
*/
void MainNetwork::addCar( Car newCar ){
	
	listOfCars.push_back( newCar );
	SendPath( listOfCars[listOfCars.size()-1] );

}

void updateSource(Car &workingCar){

	

}

int MainNetwork::minDistance(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < 9; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

void MainNetwork::dijkstra( int src)
{
	int dist[V];	 // The output array. dist[i] will hold the shortest
					// distance from src to i

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V-1; count++)
	{
	// Pick the minimum distance vertex from the set of vertices not
	// yet processed. u is always equal to src in first iteration.
	int u = minDistance(dist, sptSet);

	// Mark the picked vertex as processed
	sptSet[u] = true;

	// Update dist value of the adjacent vertices of the picked vertex.
	for (int v = 0; v < V; v++)

		// Update dist[v] only if is not in sptSet, there is an edge from 
		// u to v, and total weight of path from src to v through u is 
		// smaller than current value of dist[v]
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}
}
*/

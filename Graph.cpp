// Program Information ////////////////////////////////////////////////////////
/**
 * @file Graph.cpp
 *
 * @brief Implementation file for Graph
 * 
 * @details Implements all member functions of the Graph clas
 *
 * @version 1.00 
 *          Juliet Villanueva, Casey Garrett, Aaron Dartt (3 December 2017)
 *
 * @Note requires Graph.h
 */

// Header files ///////////////////////////////////////////////////////////////

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>		
#include <limits.h>		
#include <time.h> 		

#include <vector>		
#include <queue>		

#include <fstream>

using namespace std;


/**
 * @brief  Reads in text file to create graph.
 *
 * @details  Takes in pointer to an array of chars which contains the data to
 *			 create the graph which will be used throughout the program.
 * 
 * @pre  Properly formated text file, in the form of a 2D array. 
 *
 * @post  Creates a graph with statically set dementions. Later in the program
 *		  Values for the graph are filled in.
 * 
 * @exception None.
 *
 * @param [in]  textFile
 *				  Array of chars containing data for the creation of the graph.
 *
 * @return none
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
				inFile >> graph[i][j];
			}
		}

	}
	inFile.close();
}

/**
 * @brief Will add a car to the listOfCars private varaible.
 *
 * @details Using standard STL vectors will push_back additional car variables
 *			to the listOfCars private variable.
 *          
 * @pre listOfCars is created.
 *
 * @post listOfCars adds one more "car" to its list.
 * 
 * @exception none.
 *
 * @param [in]  newCar
 *			      New car vaible to be added to the listOfCars which all will be
 *				  "diving" on the graph via dijkstra's algorithm.
 *
 * @return void
 * 
 **/
void MainNetwork::addCar( Car newCar ){
	listOfCars.push_back( newCar );
}

/**
 * @brief Prints out start and end values as well as begin dijkstras 
 *		  calculations.
 *
 * @details Using the already set listOfCars and graph calls dijkstras to find
 *			the best path for the current car. Also prints our the start and end
 *			values of the currentCar, and later prints the path the car will
 *			take.
 *          
 * @pre Variables graph and listofCars have been created.
 *
 * @post The paths each car in listOfCars will take for the entire program life.
 * 
 * @exception none
 *
 * @param [in] none
 *
 * @return void
 * 
 **/
void MainNetwork::sendPath(){

	int destination = -99;

	for( int i  = 0; i < 1000; i++)
	{
		cout << "Source: " << listOfCars[i].source << " destination: " 
											<< listOfCars[i].destination << endl;
		dijkstra(listOfCars[i]);


		if(listOfCars[i].CurrentPath.empty())
		{
			destination = listOfCars[i].destination;
			cout << "Path: " << destination << endl;
		}
		else
		{
			destination = listOfCars[i].CurrentPath.front();
			
			cout << "Path: ";
			for(unsigned int j = 0; j < listOfCars[i].CurrentPath.size(); j++)
			{
				cout << listOfCars[i].CurrentPath[j] << " ";
			}
			cout << endl;
			
		}


		updatePath(listOfCars[i]);
	}

}


/**
 * @brief Help fucntion for dijkstra's algorithm.
 *
 * @details Finds the minimum distance array for vertices that have not yet been
 *			tested yet.
 *          
 * @pre sptSet values which have been seen are set to true, otherwise false.
 *
 * @post returns the min_index which is used for boolean operation in 
 *		 dijkstra.
 * 
 * @exception none
 *
 * @param [in] int dist[]
 *			     array of distance values used for comparison.
 *			   bool sptSet[]
 *				 Array of bools which have been visited or no.
 *
 * @return min_index which is the minimum index value used in the rows of the 
 *		   columns.
 * 
 **/
int MainNetwork::minDistance(int dist[], bool sptSet[]){
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < 9; v++)
	{
		if (sptSet[v] == false && dist[v] <= min )
		{
			min = dist[v], min_index = v;
		}
	}
	return min_index;
}


/**
 * @brief Search algorithm
 *
 * @details Finds the shortest path from the source to the destination
 *          
 * @pre There must be a graph that has data in it
 *
 * @post Will find the shortest path from one vertex to the destination
 * 		 The search algorithm uses the dijkstra's algorithm, which will
 *		 find the shortest path to each vertex of the entire tree, given
 *		 the source
 * 
 * @exception none
 *
 * @param [in] currentCar
 *			   The current car that needs a path from its source to its
 *			   destination 
 *
 * @return none
 *
 * @note the dijkstra's algorithm uses the minDistance function, to
 * 		 determine the minimun distance from the current vetex it is at.
 * 
 **/
void MainNetwork::dijkstra(Car &currentCar)
{
	vector<int> paths[9];
	int dist[9];
	bool sptSet[9]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < 9; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	dist[currentCar.source] = 0;

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
		{

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
						   && dist[u] != INT_MAX 
						   && dist[u]+graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];

				if( graph[u][currentCar.source] == 0 && u != currentCar.source)
				{
					paths[v] = paths[u];
				}

				if( u != currentCar.source)
				{

					paths[v].push_back( u );
				}
			}
		}
	}
	currentCar.CurrentPath = paths[currentCar.destination];
}

/**
 * @brief Updates the graph
 *
 * @details Updates the graph with larger edges causing cars to take differnt
 *			paths based on dijkstras newly updated graph edges.
 *          
 * @pre Already created graph, CurrentPath for currentCar created.
 *
 * @post Updated graph with increased edges for the CurrentPath currentCar will
 *				 take.
 * 
 * @exception none
 *
 * @param [in] Car CurrentCar
 *				currentCar which is holding source, destination, and CurrentPath
 *				whcih will updates the graph with larger edge values.
 *
 * @return none
 * 
 **/
void MainNetwork::updatePath(Car currentCar){
	if( !currentCar.CurrentPath.empty() )
	{
		graph[currentCar.source][currentCar.CurrentPath[0]]++;
		graph[currentCar.CurrentPath[0]][currentCar.source]++;
		for( unsigned int i = 0; i < currentCar.CurrentPath.size() - 1; i++)
		{
			graph[currentCar.CurrentPath[i]][currentCar.CurrentPath[i+1]]++;
			graph[currentCar.CurrentPath[i+1]][currentCar.CurrentPath[i]]++;
		}
		graph[currentCar.CurrentPath[currentCar.CurrentPath.size() - 1]][currentCar.destination]++;
		graph[currentCar.destination][currentCar.CurrentPath[currentCar.CurrentPath.size() - 1]]++;
	}
	else
	{
		graph[currentCar.source][currentCar.destination]++;
	}
	for( int i = 0; i < 9; i++)
	{
		for( int j = 0; j < 9; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	
}
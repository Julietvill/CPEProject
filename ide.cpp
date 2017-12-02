// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

// Number of vertices in the graph
#define V 9

struct edges{
    int distance;
    int numberOfcars;
    
};

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
printf("Vertex Distance from Source\n");
for (int i = 0; i < V; i++)
	printf("%d tt %d\n", i, dist[i]);
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(edges graph[V][V], int src)
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
		if (!sptSet[v] && graph[u][v].distance && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v].distance < dist[v])
			dist[v] = dist[u] + graph[u][v].distance;
	}

	// print the constructed distance array
	printSolution(dist, V);
}

// driver program to test above function
int main()
{
    srand(time(NULL));
/* Let us create the example graph discussed above */
edges graph[V][V];

    for(int x= 0; x < V; x++)
    {
        for(int y = 0; y < V; y++)
        {
            graph[x][y].distance = rand() % 10;
            graph[x][y].numberOfcars = rand() % 10 + 1;
        }
        
    }

	dijkstra(graph, 0);

	return 0;
}


#include <queue>
#include <vector>

using namespace std;

// Struct for each car that enters the graph
// When cars enter the graph they increase the value of the edge
// Possible changing the best path dijkstra's will pick
// source: where the car begins
// destination: where the car wants to go
// CurrentPath: The route the car will take to go from source-to-destination
struct Car{

	int source;
	int destination;
	vector<int> CurrentPath;
};


class MainNetwork{

	public:
		MainNetwork(char* fileName); //this will create the graph
		void addCar( Car newCar );	 //to add cars to the private variable listOfCars
		void sendPath( );			 //To get the path for the car to take
		void updatePath(Car currentCar); //updates the graph 
			//with larger edge values based on the path previous cars will take


	private:
		int graph[9][9];		//Current static graph as our "MAP/GPS" for the cars
		vector<Car> listOfCars; //List of cars that are entering the graph

		int minDistance(int dist[9], bool sptSet[9]);//dijkstras helper function
		void dijkstra(Car &currentCar); //Algorithm to find best path for cars to take

};
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
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
	long long initTime;
	long long timeStart;
	long long timeToEnd;
	long long totalTime;
	vector<int> CurrentPath;
	int currentSource;
	int currentDestination;
	int currentIncrement;
	bool removed;
	vector< vector<int> > paths;
	vector<int> pathTimes;
};


class MainNetwork{

	public:
		MainNetwork(char* fileName); 		//this will create the graph
		~MainNetwork();
		void addCar( Car newCar );	 		//to add cars to the private variable listOfCars
		void sendPath( );					//To get the path for the car to take
		int updatePath(Car currentCar); 	//updates the graph 
											//with larger edge values based on the path previous cars will take
		void removeCar(Car currentCar);
		int getSize();						//retruns the size of the graph, to create random data
		void getListOfCars(vector<Car> *);
		ofstream outFile;
		


	private:
		int size;				//the size of the graph
		int **graph;			//Current static graph as our "MAP/GPS" for the cars
		vector<Car> listOfCars; //List of cars that are entering the graph

		int minDistance(int dist[9], bool sptSet[9]);//dijkstras helper function
		void dijkstra(Car &currentCar); //Algorithm to find best path for cars to take

};

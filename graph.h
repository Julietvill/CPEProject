#include <queue>
#include <vector>

using namespace std;


struct Car{

	int source;
	int destination;
	bool crash;
	bool congested;
	queue<int> CurrentPath;
};


class MainNetwork{

	public:
		MainNetwork();							//this will create the graph
		void SendPath(Car &workingCar);
		void updatePath(Car &workingCar, bool newSource);
		void addCar( Car newCar );
		void updateSource();

	private:
		vector<Car> listOfCars;
		int graph[9][9];
		queue<int> CalculateBestPath(Car workingCar );		//this will be dikstra's or any algorithm
		int minDistance(int dist[], bool sptSet[]);
		void MainNetwork::dijkstra(int graph[V][V], int src);

};

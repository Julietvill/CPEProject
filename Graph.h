#include <queue>
#include <vector>

using namespace std;


struct Car{

	int source;
	int destination;
	vector<int> CurrentPath;
};


class MainNetwork{

	public:
		MainNetwork(char* fileName);							//this will create the graph
		void addCar( Car newCar );
		void sendPath( );
		void updatePath(Car currentCar, bool newSource);


	private:
		int graph[9][9];
		vector<Car> listOfCars;

		int minDistance(int dist[9], bool sptSet[9]);
		void dijkstra(Car &currentCar);

};
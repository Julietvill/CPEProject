#include <queue>
#include <vector>

using namespace std;


struct Car{

	int source;
	int destination;
	bool crash;
	bool congested;
	vector<int> CurrentPath;
};

struct Edges{
	int dist;
	int carCount;
};


class MainNetwork{

	public:
		MainNetwork(char* fileName);							//this will create the graph
		void addCar( Car newCar );
		void sendPath( Car &workingCar );
		void updatePath(int source, int dest, bool newSource);
		void updateSource();


	private:
		Edges graph[9][9];
		vector<Car> listOfCars;

		int minDistance(Edges dist[9], bool sptSet[9]);
		void dijkstra(vector<int> paths[9], int src);

};
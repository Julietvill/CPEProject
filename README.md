In order to run the code, you need to have the .txt file, which holds the edges for the graph.
Include the .txt file in the command line. So the code should be run as follows: ./CPE400 fileName.txt.

Once the code has been run, then the file will be loaded into an adjacency matrix for the program.
The adjacency matrix represents the length of time it takes to reach one vertex from another.
There is zero time for the vetices that are not directly connected, since they cannot be reached unless
you travel through another vertex. The main function will randomly generate a number of "cars", which for
our simulation represents,the cars that are going to be re-routed in the case of congestion. These cars
are loaded into a vector within the mainNetwork class. After all the cars have been pushed into the
vector, the main function will run the sendPath function in the mainNetwork. This will loop through
each of the cars that are in the vector and find the shortest path from their source to destination.
Each car will decide the best path to take based on the edges using dijkstra's algorithm. Dijkstra's 
algorithm finds the shortest path to each vertex given a source. Once the shorest path to the destination
vetrex is know, that path is given to the car and that path's weight will increase, simulating more time
when more cars are added to that edge. When the edges increase, then other edges become more practical to
take, which simulates the re-routing for cars due to congestion.

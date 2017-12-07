CPE400_Project
This project will simulate a car re-routing due to congestion within the graph. The reserved program will reserve the entire path that the car is going to take and then recalculate the path after the car reaches each new vertex. The nonresevered program, will only reserve the current edge that the car is going to take and not the entire path. The path's are also re-calcualted once the car reaches each vertex.
Functions:
dijkstra()
This function is the dijkstra's algorithm. It will find the shortest path to each vertex within the graph.
sendPath()
The sendPath fucntion will send the shortest path to the car and will update the path based on the new vertex that the car is located at.
It will also be the function that reroutes the car if a new path is shorter or faster then it's previous path.
updatePath()
This function will update the time variable within the car struct, as well as update the graph with the new edge weights.

Running the code
The reserved program will be run: ./Reserved fileName.txt
The nonreserved program will be run: ./NonReserved fileName.txt
In order to run each test, you will need to replace fileName.txt with: test2.txt, test3.txt, test4.txt, test5.txt, test6.txt, test7.txt
Each of the tests hold an bi-directional Adjacency matrix. The matrix holds the edges from each vertex, which represend the time it takes to move from one vertex to the next.

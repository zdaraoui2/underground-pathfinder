# London Underground Pathfinding

This project includes a C++ implementation of a pathfinding algorithm for the London Underground network. It utilises Dijkstra's algorithm, a priority queue, and various utility functions to find the shortest path between stations. Additionally, the project includes a set of tests to ensure the correctness and efficiency of the implementation.

## Prerequisites

Make sure you have `clang++` installed on your Mac. You can install it using Xcode Command Line Tools:

```sh
xcode-select --install

```

## Files

- `main.cpp`: Contains the main application code.
- `test.cpp`: Contains the test runner code.
- `Graph.h`: Header file for the graph data structure.
- `Dijkstra.h`: Header file for Dijkstra's algorithm implementation.
- `PriorityQueue.h`: Header file for the priority queue implementation.
- `Utils.h`: Header file for utility functions (e.g., bubble sort, binary search).
- `Test.h`: Header file for the test definitions.
- `Connection.h`: Header file for the connection class used within the graph.
- `Lines.h`: Header file for initialising the London Underground network.

## Compile and run the Application

To compile the main application, run the following command:

```sh
clang++ -std=c++17 -o main main.cpp

```

Run the application by using

```sh
./main

```

To compile the test application, run the following command:

```sh
clang++ -std=c++17 -o test test.cpp

```

Run the tests by using

```sh
./test

```

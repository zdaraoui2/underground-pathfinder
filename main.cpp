#include "Graph.h"
#include "Utils.h"
#include "PriorityQueue.h"
#include "Test.h"
#include <iostream>

void initialiseGraph(Graph &graph)
{
    // Initialise Vertices
    graph.addStation("Oxford Circus");
    graph.addStation("Green Park");
    graph.addStation("Victoria");

    // Initialise Edges
    graph.addConnection("Oxford Circus", "Green Park", 1);
    graph.addConnection("Oxford Circus", "Bond Stret", 1);
    graph.addConnection("Victoria", "Green Park", 1);
}

int main()
{
    Graph londonUnderground;
    // Initialise Graph
    initialiseGraph(londonUnderground);
    // londonUnderground.printGraph();

    // // Sort and print stations
    // std::vector<std::string> stations = londonUnderground.getAllStations();
    // BubbleSort(stations);
    // londonUnderground.printSortedStations(stations);

    // // User input for station search
    // std::string targetStation;
    // std::cout << "Enter the station name to search: ";
    // std::cin >> targetStation;

    // // Perform search for the station
    // londonUnderground.searchStation(targetStation);

    // Test PriorityQueue
    testPriorityQueue();

    // Test getConnections method
    testGetConnections(londonUnderground, "Oxford Circus");

    // C++ convention to return zero from main
    return 0;
}

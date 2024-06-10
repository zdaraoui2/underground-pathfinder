#include "Graph.h"
#include "Utils.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"
#include "Test.h"
#include <iostream>

void initialiseGraph(Graph &graph)
{
    // Initialise Vertices
    graph.addStation("Oxford Circus");
    graph.addStation("Green Park");
    graph.addStation("Victoria");
    graph.addStation("Bond Street");

    // Initialise Edges
    graph.addConnection("Oxford Circus", "Green Park", 1);
    graph.addConnection("Oxford Circus", "Bond Street", 1);
    graph.addConnection("Victoria", "Green Park", 1);
}

void findShortestPath(Graph graph, std::string startStation, std::string endStation)
{

    std::vector<std::string> path = Dijkstra::findShortestPath(graph, startStation, endStation);

    if (!path.empty())
    {
        std::cout << "Shortest path from " << startStation << " to " << endStation << " is: ";
        for (const auto &station : path)
        {
            std::cout << station << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No path found from " << startStation << " to " << endStation << "." << std::endl;
    }
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

    // // Test PriorityQueue
    // testPriorityQueue();

    // // Test getConnections method
    // testGetConnections(londonUnderground, "Oxford Circus");

    // User input for finding path
    std::string startStation, endStation;
    std::cout << "Enter the station you are starting at: ";
    std::getline(std::cin, startStation);
    std::cout << "Enter the station you are going to: ";
    std::getline(std::cin, endStation);

    // Use Dijsktra's algorithm
    findShortestPath(londonUnderground, startStation, endStation);

    // C++ convention to return zero from main
    return 0;
}

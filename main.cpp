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

std::string getValidStation(const std::vector<std::string> stations, const std::string &type)
{
    std::string station;
    while (true)
    {
        std::cout << "Enter the " << type << " station: ";
        std::getline(std::cin, station);
        if (std::binary_search(stations.begin(), stations.end(), station))
        {
            return station;
        }
        else
        {
            std::cout << "The station " << station << " is not present in the graph. Please try again." << std::endl;
        }
    }
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

    // Get all stations and sort them
    std::vector<std::string> stations = londonUnderground.getAllStations();
    BubbleSort(stations);

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
    std::string startStation = getValidStation(stations, "start");
    std::string endStation = getValidStation(stations, "end");

    // Use Dijkstra's algorithm
    findShortestPath(londonUnderground, startStation, endStation);

    // C++ convention to return zero from main
    return 0;
}

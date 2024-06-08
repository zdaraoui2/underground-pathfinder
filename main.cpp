#include "Graph.h"
#include "Utils.h"
#include "PriorityQueue.h"
#include <string>
#include <iostream>

// Test for PriorityQueue
void testPriorityQueue()
{
    PriorityQueue pq(10);

    // Add objects into priority queue
    pq.Insert(new StationDistance("Oxford Circus", 10));
    pq.Insert(new StationDistance("Green Park", 5));
    pq.Insert(new StationDistance("Victoria", 15));
    pq.Insert(new StationDistance("Piccadilly Circus", 3));
    pq.Insert(new StationDistance("Paddington", 1));

    // Print elements in priority queue in order of priority
    std::cout << "Priority Queue Contents (in priority order):" << std::endl;
    while (!pq.IsEmpty())
    {
        StationDistance *sd = pq.Remove();
        std::cout << "Station: " << sd->station << ", Distance: " << sd->distance << std::endl;
        delete sd;
    }
}

void testGetConnections(const Graph &graph, const std::string &station)
{
    const auto &connections = graph.getConnections(station);
    std::cout << "Connections for station " << station << ":" << std::endl;
    for (const auto &connection : connections)
    {
        std::cout << "  - To: " << connection.station << ", Travel Time: " << connection.travelTime << std::endl;
    }
}

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

#include <iostream>
#include "Graph.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"

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

void testDijkstra(Graph graph, std::string startStation, std::string endStation)
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
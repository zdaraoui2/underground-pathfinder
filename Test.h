#include <iostream>
#include "Graph.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"

// Test for PriorityQueue
void testPriorityQueue()
{
    PriorityQueue pq(10);

    // Add objects into priority queue
    pq.Insert(new StationTime("Oxford Circus", 10));
    pq.Insert(new StationTime("Green Park", 5));
    pq.Insert(new StationTime("Victoria", 15));
    pq.Insert(new StationTime("Piccadilly Circus", 3));
    pq.Insert(new StationTime("Paddington", 1));

    // Print elements in priority queue in order of priority
    std::cout << "Priority Queue Contents (in priority order):" << std::endl;
    while (!pq.IsEmpty())
    {
        StationTime *st = pq.Remove();
        std::cout << "Station: " << st->station << ", Time: " << st->time << std::endl;
        delete st;
    }
}

void testGetConnections(const Graph &graph, const std::string &station)
{
    const auto &connections = graph.getConnections(station);
    std::cout << "Connections for station " << station << ":" << std::endl;
    for (const auto &connection : connections)
    {
        std::cout << "  - To: " << connection.station << ", Travel Time: " << connection.travelTime << ", Line: " << connection.line << std::endl;
    }
}
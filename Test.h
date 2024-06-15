#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Graph.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"

// Test for PriorityQueue
void testPriorityQueue()
{
    PriorityQueue pq(10);

    // Add objects into priority queue
    pq.Insert(new Connection("Oxford Circus", 10));
    pq.Insert(new Connection("Green Park", 5));
    pq.Insert(new Connection("Victoria", 15));
    pq.Insert(new Connection("Piccadilly Circus", 3));
    pq.Insert(new Connection("Paddington", 1));

    // Print elements in priority queue in order of priority
    std::cout << "Priority Queue Contents (in priority order):" << std::endl;
    while (!pq.IsEmpty())
    {
        Connection *conn = pq.Remove();
        std::cout << "Station: " << conn->startStation << ", Time: " << conn->travelTime << std::endl;
        delete conn;
    }
}

void testGetConnections(const Graph &graph, const std::string &station)
{
    const auto &connections = graph.getConnections(station);
    std::cout << "Connections for station " << station << ":" << std::endl;
    for (const auto &connection : connections)
    {
        std::cout << "  - To: " << connection.endStation << ", Travel Time: " << connection.travelTime << ", Line: " << connection.line << std::endl;
    }
}

#endif // TEST_H

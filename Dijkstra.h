#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "PriorityQueue.h"

class Dijkstra
{
public:
    static std::vector<std::string> findShortestPath(const Graph &graph, const std::string &start, const std::string &goal)
    {
        // Store shortest distance from start to each node
        std::unordered_map<std::string, int> distancesToStart;
        // Store previous node in shortest path
        std::unordered_map<std::string, std::string> previousStation;
        // Priority Queue
        PriorityQueue pq(100);
    }
};

#endif // DIJKSTRA_H

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "PriorityQueue.h"

class Dijkstra
{
public:
    static std::vector<std::string> findShortestPath(const Graph &graph, const std::string &startingStation, const std::string &endStation)
    {
        // Store shortest distance from start to each node
        std::unordered_map<std::string, int> distancesToStart;
        // Store previous node in shortest path
        std::unordered_map<std::string, std::string> previousStation;
        // Priority Queue
        PriorityQueue pq(100);

        // Initialise distances
        for (const auto &station : graph.getAllStations())
        {
            distancesToStart[station] = INT_MAX;
        }
        distancesToStart[startingStation] = 0;

        // Adds starting station to priority queue
        pq.Insert(new StationDistance(startingStation, 0));

        return {};
    }
};

#endif // DIJKSTRA_H

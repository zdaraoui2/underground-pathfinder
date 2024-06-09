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

        while (!pq.IsEmpty())
        {
            StationDistance *current = pq.Remove();
            if (current->station == endStation)
            {
                break; // Ends once end station has been reached
            }

            for (const auto &connection : graph.adjacencyList.at(current->station))
            {
                int newDistance = current->distance + connection.travelTime;
                if (newDistance < distancesToStart[connection.station])
                {
                    distancesToStart[connection.station] = newDistance;
                    previousStation[connection.station] = current->station;
                    pq.Insert(new StationDistance(connection.station, newDistance));
                }
            }

            delete current;
        }

        return {};
    }
};

#endif // DIJKSTRA_H

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "PriorityQueue.h"

class Dijkstra
{
public:
    static std::vector<std::string> findShortestPath(const Graph &graph, const std::string &startingStation, const std::string &endStation, int &totalTravelTime)
    {
        // Store shortest distance from start to each node
        std::unordered_map<std::string, int> timesToStart;
        // Store previous node in shortest path
        std::unordered_map<std::string, std::string> previousStation;
        // Priority Queue
        PriorityQueue pq(100);

        // Initialise times
        for (const auto &station : graph.getAllStations())
        {
            timesToStart[station] = INT_MAX;
        }
        timesToStart[startingStation] = 0;

        // Adds starting station to priority queue
        pq.Insert(new StationTime(startingStation, 0));

        while (!pq.IsEmpty())
        {
            StationTime *current = pq.Remove();
            if (current->station == endStation)
            {
                totalTravelTime = current->time; // Sets total travel time once end station has been reached
                break;                           // Ends once end station has been reached
            }

            for (const auto &connection : graph.adjacencyList.at(current->station))
            {
                int newTime = current->time + connection.travelTime;
                if (newTime < timesToStart[connection.station])
                {
                    timesToStart[connection.station] = newTime;
                    previousStation[connection.station] = current->station;
                    pq.Insert(new StationTime(connection.station, newTime));
                }
            }

            delete current;
        }

        // Construct path
        std::vector<std::string> path;
        for (std::string at = endStation; at != ""; at = previousStation[at])
        {
            path.push_back(at);
            if (at == startingStation)
            {
                break;
            }
        }
        std::reverse(path.begin(), path.end());

        return path;
    }
};

#endif // DIJKSTRA_H

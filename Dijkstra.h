#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "PriorityQueue.h"

struct PathStep
{
    std::string station;
    std::string line;

    PathStep(const std::string &station, const std::string &line)
        : station(station), line(line) {}
};

class Dijkstra
{
public:
    static std::vector<PathStep> findShortestPath(const Graph &graph, const std::string &startingStation, const std::string &endStation, int &totalTravelTime)
    {
        // Store shortest distance from start to each node
        std::unordered_map<std::string, int> timesToStart;
        // Store previous node and line in shortest path
        std::unordered_map<std::string, std::pair<std::string, std::string>> previousStation;
        // Priority Queue
        PriorityQueue pq(100);

        // Initialise times
        for (const auto &station : graph.getAllStations())
        {
            timesToStart[station] = INT_MAX;
        }
        timesToStart[startingStation] = 0;

        // Adds starting station to priority queue
        pq.Insert(new Connection(startingStation, 0));

        while (!pq.IsEmpty())
        {
            Connection *current = pq.Remove();
            if (current->startStation == endStation)
            {
                totalTravelTime = current->travelTime; // Sets total travel time once end station has been reached
                break;                                 // Ends once end station has been reached
            }

            for (const auto &connection : graph.adjacencyList.at(current->startStation))
            {
                int newTime = current->travelTime + connection.travelTime;
                if (newTime < timesToStart[connection.endStation])
                {
                    timesToStart[connection.endStation] = newTime;
                    previousStation[connection.endStation] = {current->startStation, connection.line};
                    pq.Insert(new Connection(connection.endStation, newTime));
                }
            }

            delete current;
        }

        // Construct path
        std::vector<PathStep> path;
        for (std::string at = endStation; at != ""; at = previousStation[at].first)
        {
            std::string line = previousStation[at].second;
            path.emplace_back(at, line);
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

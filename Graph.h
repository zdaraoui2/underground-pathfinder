#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <unordered_map>
#include "Connection.h"
#include "Utils.h"

class Graph
{
public:
    std::unordered_map<std::string, std::list<Connection>> adjacencyList;

    // Method to add a vertex to the graph
    void addStation(const std::string &station)
    {
        adjacencyList[station] = std::list<Connection>();
    }

    // Method to add an edge to the graph
    void addConnection(const std::string &from, const std::string &to, int travelTime, const std::string &line)
    {
        adjacencyList[from].emplace_back(from, to, travelTime, line);
        adjacencyList[to].emplace_back(to, from, travelTime, line);
    }

    // Method to output the graph as text
    void printGraph() const
    {
        for (const auto &station : adjacencyList)
        {
            std::cout << "Station: " << station.first << std::endl;
            std::cout << "Connections:" << std::endl;

            for (const auto &connection : station.second)
            {
                std::cout << "  - To: " << connection.getEndStation() << ", Travel Time: " << connection.getTravelTime() << ", Line: " << connection.getLine() << std::endl;
            }

            std::cout << std::endl;
        }
    }

    // Method to get all stations
    std::vector<std::string> getAllStations() const
    {
        std::vector<std::string> stations;
        for (const auto &station : adjacencyList)
        {
            stations.push_back(station.first);
        }
        return stations;
    }

    // Method to print sorted stations
    void printSortedStations(const std::vector<std::string> &stations) const
    {
        std::cout << "Sorted Stations:" << std::endl;
        for (const auto &station : stations)
        {
            std::cout << station << std::endl;
        }
    }

    // Method to search for a station using binary search
    void searchStation(const std::string &targetStation) const
    {
        std::vector<std::string> stations = getAllStations();
        BubbleSort(stations);
        int result = BinarySearch(stations, targetStation);
        if (result != -1)
        {
            std::cout << "Station " << targetStation << " is present in the graph." << std::endl;
        }
        else
        {
            std::cout << "Station " << targetStation << " is not present in the graph." << std::endl;
        }
    }

    // Method to get connections from a station
    const std::list<Connection> &getConnections(const std::string &station) const
    {
        return adjacencyList.at(station);
    }
};

#endif // GRAPH_H

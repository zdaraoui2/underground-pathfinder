#include <list>
#include <string>
#include <iostream>
#include <unordered_map>

struct Connection
{
    std::string station; // Other vertex that this node is connected to
    int travelTime;      // Weighting of the edge
};

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
    void addConnection(const std::string &from, const std::string &to, int travelTime)
    {
        adjacencyList[from].push_back({to, travelTime});
        adjacencyList[to].push_back({from, travelTime});
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
                std::cout << "  - To: " << connection.station << ", Travel Time: " << connection.travelTime << std::endl;
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
};
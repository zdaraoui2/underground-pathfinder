#include "Graph.h"
#include "Utils.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"
#include "Test.h"
#include "Lines.h"
#include <iostream>

void initialiseGraph(Graph &graph)
{
    // Initialise Vertices
    initialiseStations(graph);

    // Initialise Edges
    initialiseCentralLine(graph);
    initialiseVictoriaLine(graph);
    initialiseBakerlooLine(graph);
    initialisePiccadillyLine(graph);
    initialiseJubileeLine(graph);
    initialiseCircleLine(graph);
    initialiseDistrictLine(graph);
    initialiseNorthernLine(graph);
    initialiseMetropolitanLine(graph);
    initialiseElizabethLine(graph);
}

std::string getValidStation(const std::vector<std::string> &stations, const std::string &type)
{
    std::string station;
    while (true)
    {
        std::cout << "Enter the " << type << " station: ";
        std::getline(std::cin, station);
        if (std::binary_search(stations.begin(), stations.end(), station))
        {
            return station;
        }
        else
        {
            std::cout << "The station " << station << " is not present in the graph. Please try again." << std::endl;
        }
    }
}

void findShortestPath(Graph graph, const std::string &startStation, const std::string &endStation)
{
    int totalTravelTime = 0;
    std::vector<Connection> path = Dijkstra::findShortestPath(graph, startStation, endStation, totalTravelTime);

    if (!path.empty())
    {
        std::cout << "To get to " << endStation << " from " << startStation << ":" << std::endl;

        std::string currentLine = path[1].getLine();
        std::vector<std::string> stops;
        int numberOfStops = 0;

        for (size_t i = 1; i < path.size(); ++i)
        {
            if (path[i].getLine() != currentLine)
            {
                std::cout << "Catch the " << currentLine << " line for " << numberOfStops << " stops." << std::endl;
                std::cout << "Stops: ";
                for (const auto &stop : stops)
                {
                    std::cout << stop << " ";
                }
                std::cout << std::endl;
                std::cout << "Then..." << std::endl;

                currentLine = path[i].getLine();
                stops.clear();
                numberOfStops = 0;
            }

            stops.push_back(path[i].getStartStation());
            numberOfStops++;
        }

        std::cout << "Catch the " << currentLine << " line for " << numberOfStops << " stops." << std::endl;
        std::cout << "Stops: ";
        for (const auto &stop : stops)
        {
            std::cout << stop << " ";
        }
        std::cout << std::endl;
        std::cout << "The total journey time is " << totalTravelTime << " minutes." << std::endl;
    }
    else
    {
        std::cout << "No path found from " << startStation << " to " << endStation << "." << std::endl;
    }
}

int main()
{
    Graph londonUnderground;
    // Initialise Graph
    initialiseGraph(londonUnderground);
    // londonUnderground.printGraph();

    // Get all stations and sort them
    std::vector<std::string> stations = londonUnderground.getAllStations();
    BubbleSort(stations);

    // User input for finding path
    std::string startStation = getValidStation(stations, "start");
    std::string endStation = getValidStation(stations, "end");

    // Use Dijkstra's algorithm
    findShortestPath(londonUnderground, startStation, endStation);

    // C++ convention to return zero from main
    return 0;
}

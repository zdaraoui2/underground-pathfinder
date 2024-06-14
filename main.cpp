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

std::string getValidStation(const std::vector<std::string> stations, const std::string &type)
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

void findShortestPath(Graph graph, std::string startStation, std::string endStation)
{
    int totalTravelTime = 0;
    std::vector<PathStep> path = Dijkstra::findShortestPath(graph, startStation, endStation, totalTravelTime);

    if (!path.empty())
    {
        std::cout << "To get to " << endStation << " from " << startStation << ":" << std::endl;

        std::string currentLine = path[1].line;
        std::vector<std::string> stops;
        int numberOfStops = 0;

        for (size_t i = 1; i < path.size(); ++i)
        {
            if (path[i].line != currentLine)
            {
                std::cout << "Catch the " << currentLine << " line for " << numberOfStops << " stops." << std::endl;
                std::cout << "Stops: ";
                for (const auto &stop : stops)
                {
                    std::cout << stop << " ";
                }
                std::cout << std::endl;
                std::cout << "Then..." << std::endl;

                currentLine = path[i].line;
                stops.clear();
                numberOfStops = 0;
            }

            stops.push_back(path[i].station);
            numberOfStops++;
        }

        std::cout << "Catch the " << currentLine << " for " << numberOfStops << " stops." << std::endl;
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

    // // Sort and print stations
    // std::vector<std::string> stations = londonUnderground.getAllStations();
    // BubbleSort(stations);
    // londonUnderground.printSortedStations(stations);

    // Get all stations and sort them
    std::vector<std::string> stations = londonUnderground.getAllStations();
    BubbleSort(stations);

    // // User input for station search
    // std::string targetStation;
    // std::cout << "Enter the station name to search: ";
    // std::cin >> targetStation;

    // // Perform search for the station
    // londonUnderground.searchStation(targetStation);

    // // Test PriorityQueue
    // testPriorityQueue();

    // // Test getConnections method
    // testGetConnections(londonUnderground, "Oxford Circus");

    // User input for finding path
    std::string startStation = getValidStation(stations, "start");
    std::string endStation = getValidStation(stations, "end");

    // Use Dijkstra's algorithm
    findShortestPath(londonUnderground, startStation, endStation);

    // C++ convention to return zero from main
    return 0;
}

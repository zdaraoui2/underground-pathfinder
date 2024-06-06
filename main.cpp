#include "Graph.h"
#include "Utils.h"
#include <string>
#include <iostream>

void initialiseGraph(Graph &graph)
{
    // Initialise Vertices
    graph.addStation("Oxford Circus");
    graph.addStation("Green Park");
    graph.addStation("Victoria");

    // Initialise Edges
    graph.addConnection("Oxford Circus", "Green Park", 1);
    graph.addConnection("Victoria", "Green Park", 1);
}

int main()
{
    Graph londonUnderground;
    // Initialise Graph
    initialiseGraph(londonUnderground);
    londonUnderground.printGraph();

    // Sort and print stations
    std::vector<std::string> stations = londonUnderground.getAllStations();
    BubbleSort(stations);
    londonUnderground.printSortedStations(stations);
}

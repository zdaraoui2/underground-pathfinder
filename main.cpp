#include "Graph.h"
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
    initialiseGraph(londonUnderground);
    londonUnderground.printGraph();
}

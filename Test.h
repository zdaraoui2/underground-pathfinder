#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "Graph.h"
#include "PriorityQueue.h"
#include "Dijkstra.h"

// Test result
struct TestResult
{
    std::string testName;
    bool passed;
    double duration;
    std::string blockName;

    TestResult(const std::string &block, const std::string &name, bool pass, double time)
        : blockName(block), testName(name), passed(pass), duration(time) {}
};

// Set up a simple graph
Graph *setupSimpleGraph()
{
    Graph *graph = new Graph();
    graph->addStation("Oxford Circus");
    graph->addStation("Green Park");
    graph->addStation("Victoria");
    graph->addStation("Bond Street");

    graph->addConnection("Oxford Circus", "Green Park", 1, "Victoria");
    graph->addConnection("Oxford Circus", "Bond Street", 1, "Central");
    graph->addConnection("Green Park", "Victoria", 2, "Victoria");

    return graph;
}

// Test graph connections
TestResult testGraphConnections(const std::string &blockName, Graph *graph, const std::string &station, bool expectConnections = true)
{
    auto start = std::chrono::high_resolution_clock::now();

    const auto &connections = graph->getConnections(station);
    bool passed = expectConnections ? !connections.empty() : connections.empty();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return TestResult(blockName, "Get Connections Test", passed, duration.count());
}

// Test Dijkstra's algorithm
TestResult testDijkstra(const std::string &blockName, Graph *graph, const std::string &start, const std::string &end)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int totalTravelTime = 0;
    auto path = Dijkstra::findShortestPath(*graph, start, end, totalTravelTime);
    bool passed = !path.empty();

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

    return TestResult(blockName, "Dijkstra's Algorithm Test", passed, duration.count());
}

// Set up a large graph
Graph *setupLargeGraph()
{
    Graph *largeGraph = new Graph();
    for (int i = 0; i < 1000000; ++i)
    {
        largeGraph->addStation("Station" + std::to_string(i));
        if (i > 0)
        {
            largeGraph->addConnection("Station" + std::to_string(i - 1), "Station" + std::to_string(i), 1, "TestLine");
        }
    }
    return largeGraph;
}

// Test Priority Queue
TestResult testPriorityQueueInsertAndRemove(const std::string &blockName)
{
    auto start = std::chrono::high_resolution_clock::now();

    PriorityQueue pq(10);
    pq.Insert(new Connection("TestStation1", 5));
    pq.Insert(new Connection("TestStation2", 3));
    pq.Insert(new Connection("TestStation3", 8));

    bool passed = pq.Remove()->getTravelTime() == 3;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return TestResult(blockName, "Priority Queue Insert and Remove Test", passed, duration.count());
}

// Run all tests
void runTests()
{
    std::vector<TestResult> results;

    // Simple Graph Tests
    {
        Graph *simpleGraph = setupSimpleGraph();
        results.push_back(testGraphConnections("Simple Graph Tests", simpleGraph, "Oxford Circus"));
        results.push_back(testDijkstra("Simple Graph Tests", simpleGraph, "Victoria", "Bond Street"));
        delete simpleGraph;
    }

    // Large Graph Tests
    {
        Graph *largeGraph = setupLargeGraph();
        results.push_back(testGraphConnections("Large Graph Tests", largeGraph, "Station0"));
        results.push_back(testDijkstra("Large Graph Tests", largeGraph, "Station0", "Station999999"));
        delete largeGraph;
    }

    // Priority Queue Tests
    {
        results.push_back(testPriorityQueueInsertAndRemove("Priority Queue Tests"));
    }

    // Output test results
    std::vector<std::string> failedTests;
    for (const auto &result : results)
    {
        std::cout << result.blockName << " - " << result.testName << ": " << (result.passed ? "Passed" : "Failed") << " (Duration: " << result.duration << "s)" << std::endl;
        if (!result.passed)
        {
            failedTests.push_back(result.blockName + " - " + result.testName);
        }
    }

    // List all failed tests
    if (!failedTests.empty())
    {
        std::cout << "\nFailed Tests:\n";
        for (const auto &testName : failedTests)
        {
            std::cout << testName << std::endl;
        }
    }
    else
    {
        std::cout << "\nAll tests passed!" << std::endl;
    }
}

#endif // TEST_H

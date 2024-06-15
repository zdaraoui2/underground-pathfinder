#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

struct Connection
{
    std::string startStation;
    std::string endStation;
    int travelTime;
    std::string line;

    // Constructor for priority queue
    Connection(const std::string &station, int time)
        : startStation(station), endStation(""), travelTime(time), line("") {}

    // Constructor for graph
    Connection(const std::string &start, const std::string &end, int time, const std::string &line)
        : startStation(start), endStation(end), travelTime(time), line(line) {}

    // Overloaded operators for priority queue
    bool operator>(const Connection &other) const
    {
        return travelTime > other.travelTime;
    }

    bool operator<(const Connection &other) const
    {
        return travelTime < other.travelTime;
    }

    bool operator==(const Connection &other) const
    {
        return travelTime == other.travelTime;
    }
};

#endif // CONNECTION_H

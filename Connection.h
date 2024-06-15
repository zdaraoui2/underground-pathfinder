#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

class Connection
{
private:
    std::string startStation;
    std::string endStation;
    int travelTime;
    std::string line;

public:
    // Constructor for priority queue
    Connection(const std::string &station, int time)
        : startStation(station), endStation(""), travelTime(time), line("") {}

    // Constructor for graph
    Connection(const std::string &start, const std::string &end, int time, const std::string &line)
        : startStation(start), endStation(end), travelTime(time), line(line) {}

    // Constructor for Dijkstra
    Connection(const std::string &station, const std::string &line)
        : startStation(station), endStation(""), travelTime(0), line(line) {}

    std::string getStartStation() const { return startStation; }
    std::string getEndStation() const { return endStation; }
    int getTravelTime() const { return travelTime; }
    std::string getLine() const { return line; }

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

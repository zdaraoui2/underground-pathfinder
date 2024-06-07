#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>

struct StationDistance
{
    std::string station;
    int distance;

    StationDistance(const std::string &station, int distance)
        : station(station), distance(distance) {}

    bool operator>(const StationDistance &other) const
    {
        return distance > other.distance;
    }

    bool operator<(const StationDistance &other) const
    {
        return distance < other.distance;
    }

    bool operator==(const StationDistance &other) const
    {
        return distance == other.distance;
    }
};

class PriorityQueue
{
    int size;
    StationDistance **data;
    int count;

public:
    PriorityQueue(int size)
    {
        data = new StationDistance *[size];
        this->size = size;
        count = 0;
    }
    ~PriorityQueue()
    {
        delete[] data;
    }
    void Insert(StationDistance *item)
    {
        if (count == 0)
        {
            data[count++] = item;
        }
        else
        {
            int j;
            for (j = (count - 1); j >= 0; j--)
            {
                if (*item > *data[j])
                {
                    data[j + 1] = data[j];
                }
                else
                {
                    break;
                }
            }
            data[j + 1] = item;
            count++;
        }
    }
    StationDistance *Remove()
    {
        return data[--count];
    }
    StationDistance *PeakMin()
    {
        return data[count - 1];
    }
    bool IsEmpty()
    {
        return count == 0;
    }
    bool IsFull()
    {
        return count == size;
    }
    int Size()
    {
        return size;
    }
};

#endif // PRIORITY_QUEUE_H

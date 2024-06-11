#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct StationTime
{
    std::string station;
    int time;

    StationTime(const std::string &station, int time)
        : station(station), time(time) {}

    bool operator>(const StationTime &other) const
    {
        return time > other.time;
    }

    bool operator<(const StationTime &other) const
    {
        return time < other.time;
    }

    bool operator==(const StationTime &other) const
    {
        return time == other.time;
    }
};

class PriorityQueue
{
    int size;
    StationTime **data;
    int count;

public:
    PriorityQueue(int size)
    {
        data = new StationTime *[size];
        this->size = size;
        count = 0;
    }
    ~PriorityQueue()
    {
        delete[] data;
    }
    void Insert(StationTime *item)
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
    StationTime *Remove()
    {
        return data[--count];
    }
    StationTime *PeakMin()
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

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

// Swap function to swap two string values
void swap(std::string *a, std::string *b)
{
    std::string temp = *b;
    *b = *a;
    *a = temp;
}

// Bubble Sort algorithm
void BubbleSort(std::vector<std::string> &stations)
{
    for (size_t i = 0; i < stations.size(); i++)
    {
        for (size_t j = 0; j < stations.size() - 1; j++)
        {
            if (stations[j] > stations[j + 1])
            {
                swap(&stations[j], &stations[j + 1]);
            }
        }
    }
}

#endif // UTILS_H

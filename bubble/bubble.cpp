#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "bubble.h"

using namespace std;

void BubbleSort::sort(int *array, int length)
{
    clock_t start = clock();
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < length - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
    clock_t end = clock();

    double timeDifference = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << "Difference in ms: " << timeDifference << " ms" << std::endl;
    timelist.push_back(timeDifference);
}

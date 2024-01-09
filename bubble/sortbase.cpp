#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "sortbase.h"
#include <numeric>

using namespace std;

void SortBase::myswap(int *array, int pos1, int pos2)
{
    int temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int SortBase::partition(int array[], int low, int high, int pivot)
{
    int i = low;
    int j = low;
    while (i <= high)
    {
        if (array[i] > pivot)
        {
            i++;
        }
        else
        {
            myswap(array, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
}

vector<int> SortBase::listgenarray(int count)
{
    int num;
    if (count <= 0)
    {

        cout << "How many numbers should be generated?: ";
        cin >> num;
    }
    else
    {
        num = count;
    }

    vector<int> v;
    for (int i = 0; i < num; i++)
    {
        v.push_back(rand() % num);
    }
    // int arr[v.size()];
    // copy(v.begin(), v.end(), arr);
    return v;
}

void SortBase::print(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << endl;
    }
}

void SortBase::printmean()
{
    cout << "Mean of " << timelist.size() << " rounds: " << std::accumulate(timelist.begin(), timelist.end(), 0.0) / timelist.size() << " ms" << endl;
}
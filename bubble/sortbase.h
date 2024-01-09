
#ifndef __SORTBASE__
#define __SORTBASE__

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class SortBase

{
private:
    void myswap(int *array, int pos1, int pos2);

protected:
    vector<double> timelist;
    int partition(int array[], int low, int high, int pivot);

public:
    void print(int *array, int size);
    void printmean();
    static int listgenfile(int count = 0)
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
        ofstream NumList("list.txt");

        for (int i = 0; i < num; i++)
        {
            NumList << rand() % num << "\n";
        }
        NumList.close();
        return 0;
    }
    vector<int> listgenarray(int count = 0);
};

#endif

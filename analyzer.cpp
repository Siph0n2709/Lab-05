#include <iostream>
#include <list>
#include <chrono>
#include "StringData.h"
using namespace std;

int linear_search(vector<string> container, string element)
{
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<string> container, string element)
{
    int left_val = 0;
    int right_val = container.size() - 1;

    while (left_val <= right_val)
    {
        int mid = (left_val + right_val) / 2;
        auto mid_val = container[mid];

        if (mid_val == element)
        {
            return mid;
        }

        else if (element < mid_val)
        {
            right_val = mid - 1;
        }

        else
        {
            left_val = mid + 1;
        }
    }

    return -1;
}

vector<string> dataset = getStringData();

int main()
{
    auto start = chrono::steady_clock::now();
    cout << linear_search(dataset, "mzzzz") << endl;
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Linear Search Time: " + to_string(duration.count()) + " microseconds" << endl;

    auto start2 = chrono::steady_clock::now();
    cout << binary_search(dataset, "mzzzz") << endl;
    auto end2 = chrono::steady_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    cout << "Binary Search Time: " + to_string(duration2.count()) + " microseconds" << endl;
}
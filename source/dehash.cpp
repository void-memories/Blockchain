#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "../headers/database.h"
#include "../headers/dehash.h"
#include "../headers/hash.h"
#include "../headers/read.h"
#include "../headers/verification.h"
#include "../headers/write.h"

using namespace std;

DeHash::DeHash() {}

map<string, int> DeHash::init(vector<string> keys, vector<string> genuine)
{
    int n = keys.size();

    for (int i = 0; i < keys.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < genuine.size(); j++)
        {
            if (keys[i] == genuine[j])
                flag = 1;
        }
        if (flag)
            keyresult[keys[i]] = 1;
        else
            keyresult[keys[i]] = 0;
    }
    return keyresult;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

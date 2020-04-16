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
#include "../imports/sha256.h"
using namespace std;

CreateHash::CreateHash(vector<string> to_be_hashed1)
{
    to_be_hashed = to_be_hashed1;
}
vector<string> CreateHash::init()
{

    for (int i = 0; i < to_be_hashed.size(); i++)
    {
        string input = to_be_hashed[i];
        string output = sha256(input);
        hashkeys.push_back(output);
    }

    return hashkeys;
}

//Don't need this anymore, hashing is working properly
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

void h2(int arr[], int n, int i)
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

        h2(arr, n, largest);
    }
}

void h3(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        h2(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);

        h2(arr, i, 0);
    }
}
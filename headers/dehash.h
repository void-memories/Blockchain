#ifndef DEHASH_H
#define DEHASH_H
#include <vector>
#include <map>
#include "read.h"

using namespace std;
class DeHash
{
    map<string, int> keyresult;

public:
    DeHash();
    map<string, int> init(vector<string> keys, vector<string> genuine);
};
#endif
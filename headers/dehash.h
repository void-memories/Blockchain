#ifndef DEHASH_H
#define DEHASH_H
#include <vector>
#include <map>
using namespace std;
class DeHash
{
    map<string, int> keyresult;

public:
    map<string, int> init(vector<string> keys, vector<string> genuine);
};
#endif
#ifndef VERIFICATION_H
#define VERIFICATION_H
#include <vector>
#include <map>
#include <string>
#include "dehash.h"
using namespace std;

class Verification
{
    vector<string> final_keys;

public:
    Verification();
    vector<string> verify(map<string, int> m);
};
#endif
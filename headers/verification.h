#ifndef VERIFICATION_H
#define VERIFICATION_H
#include <vector>
#include <map>
#include <string>
using namespace std;

class Verification
{
    vector<string> final_keys;

public:
    vector<string> verify(map<string, int> m);
};
#endif
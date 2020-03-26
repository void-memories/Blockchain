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

Verification::Verification() {}
vector<string> Verification::verify(map<string, int> m)
{
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (it->second == 1)
            final_keys.push_back(it->first);
    }
    return final_keys;
}
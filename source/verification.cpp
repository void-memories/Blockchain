#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Verification
{
    vector<string> final_keys;

public:
    vector<string> verify(map<string,int> m)
    {
        for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            if(it->second==1)
            final_keys.push_back(it->first);

        }
        return final_keys;
    }
};
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class DeHash
{
    map<string, int> keyresult;

public:
    map<string, int> init(vector<string> keys, vector<string> genuine)
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
};
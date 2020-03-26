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

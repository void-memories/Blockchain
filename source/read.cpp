#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Read
{
    ifstream myfile;
    string data[8];
    string temp;
    vector<string> v;

public:
    Read(string name)
    {
        myfile.open(name);
    }

    vector<string> init()
    {
        int i=0;
        while (getline(myfile, temp))
        {
            v.push_back(temp);

        }
        return v;
    }
};
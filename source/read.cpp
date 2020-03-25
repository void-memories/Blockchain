#include <iostream>
#include <fstream>
using namespace std;

class Read
{
    ifstream myfile;
    string data;

public:
    Read(string name)
    {
        myfile.open(name);
    }

    string init()
    {
        while (getline(myfile, data))
        {
            cout << data << '\n';
        }
    }
};
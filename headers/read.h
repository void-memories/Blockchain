#ifndef READ_H
#define READ_H
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

class Read
{
    ifstream myfile;
    string data[8];
    string temp;
    vector<string> v;

public:
    Read();
    Read(string name);
    vector<string> init();
};
#endif
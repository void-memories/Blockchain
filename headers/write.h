#ifndef WRITE_H
#define WRITE_H
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

class Write
{
    ofstream myfile;

public:
    Write(string name);

    void init(string data);
};
#endif

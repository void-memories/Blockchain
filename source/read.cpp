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

Read::Read() {}
Read::Read(string name)
{
    myfile.open(name);
}

vector<string> Read::init()
{
    int i = 0;
    v.clear();
    while (getline(myfile, temp))
    {
        v.push_back(temp);
    }
    myfile.close();
    return v;
}
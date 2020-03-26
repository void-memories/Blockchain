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

Write::Write(string name)
{
    myfile.open(name);
}

void Write::init(string data)
{
    myfile << data << endl;
}

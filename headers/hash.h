#ifndef HASH_H
#define HASH_H
#include <vector>
#include <map>
#include <string>
#include "database.h"
using namespace std;

class CreateHash:public Database
{
    vector<string> to_be_hashed;
    vector<string> hashkeys;

public:
    CreateHash(vector<string> to_be_hashed);
    vector<string> init();
};
#endif
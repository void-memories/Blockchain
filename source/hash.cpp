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
#include "../imports/sha256.h"
using namespace std;

CreateHash::CreateHash(vector<string> to_be_hashed1)
{
    to_be_hashed = to_be_hashed1;
}
vector<string> CreateHash::init()
{

    for (int i = 0; i < to_be_hashed.size(); i++)
    {
        string input = to_be_hashed[i];
        string output = sha256(input);
        hashkeys.push_back(output);
    }

    return hashkeys;
}

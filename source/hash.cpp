#include <iostream>
#include "../imports/sha256.h"
using namespace std;
class CreateHash
{
    string name, dob;

public:
    CreateHash(string name, string dob)
    {
        this->name = name;
        this->dob = dob;
    }
    string init(string name, string dob)
    {
        string input = name + dob;
        string output = sha256(input);

        return output;
    }
};


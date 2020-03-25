#include <iostream>
#include "../imports/sha256.h"
#include <vector>
using namespace std;
class CreateHash
{
    vector<string> to_be_hashed;
    vector<string> hashkeys;

public:
    CreateHash(vector<string> to_be_hashed)
    {
        this->to_be_hashed=to_be_hashed;
    }
    vector<string> init()
    {
        

        for(int i=0;i<to_be_hashed.size();i++)
        {
            string input=to_be_hashed[i];
            string output=sha256(input);
            hashkeys.push_back(output);
        }

        return hashkeys;
    }
};


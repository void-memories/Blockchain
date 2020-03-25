#include <iostream>
#include <vector>
#include <map>
#include "read.cpp"
#include "hash.cpp"
using namespace std;

class Database
{

    vector<string> temp;
    vector<string> marks_card[5];
    vector<string> to_be_hashed;
    vector<string> hashkeys;
    map<string, int> db;
    int n;

public:
    Database()
    {
        n = 1;
        string filename = "data/students_report.txt";
        Read rx(filename);

        for (int i = 0; i < n; i++)
        {
            temp = rx.init();
            marks_card[i] = temp;

            string s1 = temp[0];
            string s2 = temp[1];
            to_be_hashed.push_back(s1 + s2);
        }
        CreateHash hash(to_be_hashed);
        hashkeys = hash.init();

        for (int i = 0; i < hashkeys.size(); i++)
        {
            db[hashkeys[i]] = i;
            cout << hashkeys[i] << " " << i << endl;
            
            vector<string> temp2=marks_card[i];
            
            for(int j=0;j<temp2.size();j++)
            cout<<temp2[j]<<endl;
        }
    }
};

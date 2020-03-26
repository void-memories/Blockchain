#include <iostream>
#include <vector>
#include <map>
#include "read.cpp"
#include "hash.cpp"
#include "write.cpp"
#include "dehash.cpp"
#include "verification.cpp"
#include "list.cpp"
using namespace std;
class Database
{
    vector<string> temp;
    vector<string> temp2;
    vector<string> marks_card[100];
    vector<string> to_be_hashed;
    vector<string> hashkeys;
    vector<string> all;
    vector<string> accepted_keys;
    map<string, int> db;
    map<string, int> results;
    string filename;
    string s1;
    string s2;
    int n;

public:
    Database(int number_of_entries)
    {

        n = number_of_entries;
        filename = "data/students_report.txt";
        Read rx(filename);
        temp = rx.init();

        for (int i = 0; i < n; i++)
        {
            temp2.clear();
            for(int j=0;j<7;j++)
            temp2.push_back(temp[7*i+j]);

            marks_card[i] = temp2;
            s1 = temp[7*i];
            s2 = temp[7*i+1];
            to_be_hashed.push_back(s1 + s2);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<7;j++)
        //     cout<<marks_card[i][j]<<" ";
        // }
        CreateHash hash(to_be_hashed);
        hashkeys = hash.init();

        for(int i=0;i<hashkeys.size();i++)
        db[hashkeys[i]]=i;

        Write f1("output/hash_keys.txt");
        for (int i = 0; i < hashkeys.size(); i++)
            f1.init(hashkeys[i]);
    }

    void start_read()
    {
        Read rd("output/hash_keys.txt");

        all = rd.init();
        // for(int i=0;i<all.size();i++)
        // cout<<"--"<<all[i]<<"--";

        DeHash dh;
        results = dh.init(all);

        Verification vf;

        accepted_keys = vf.verify(results);

        for (int i = 0; i < accepted_keys.size(); i++)
        {
            cout << accepted_keys[i]<<endl;
        }

        List lst;
        lst.CreateBlockChain(accepted_keys, db, marks_card);
    }
};

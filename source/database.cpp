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
#include "list.cpp"
using namespace std;

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
char choice;

Database::Database(int number_of_entries)
{

    n = number_of_entries;
    filename = "data/students_report.txt";
    Read rx(filename);
    temp = rx.init();
    cout << endl
         << "*********Marks Sheet Has Been Read*********" << endl;
    cout << "Hit ENTER to continue" << endl;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        temp2.clear();
        for (int j = 0; j < 7; j++)
            temp2.push_back(temp[7 * i + j]);

        marks_card[i] = temp2;
        s1 = temp[7 * i];
        s2 = temp[7 * i + 1];
        to_be_hashed.push_back(s1 + s2);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<7;j++)
    //     cout<<marks_card[i][j]<<" ";
    // }
    CreateHash hash(to_be_hashed);
    hashkeys = hash.init();

    cout << endl
         << "*********Hash Keys Has Been Generated*********" << endl;
    cout << "Press 'y' to display them or 'n' to proceed" << endl;
    cin >> choice;
    if (choice == 'y')
        for (int i = 0; i < hashkeys.size(); i++)
            cout << i + 1 << "." << hashkeys[i] << endl;

    for (int i = 0; i < hashkeys.size(); i++)
        db[hashkeys[i]] = i;

    Write f1("output/hash_keys.txt");
    for (int i = 0; i < hashkeys.size(); i++)
        f1.init(hashkeys[i]);
}

void Database::start_read()
{
    Read rd("output/hash_keys.txt");

    all = rd.init();
    // for(int i=0;i<all.size();i++)
    // cout<<"--"<<all[i]<<"--";

    DeHash dh;
    results = dh.init(all, hashkeys);

    cin.ignore();

    Verification vf;

    accepted_keys = vf.verify(results);

    cout << endl
         << "*********Verification is complete*********" << endl;
    cout << "Press 'y' to show the valid and invalid keys or press'n' to continue" << endl;
    cin >> choice;
    if (choice == 'y')
    {
        for (int i = 0; i < all.size(); i++)
        {
            int flag = 0;
            for (int j = 0; j < accepted_keys.size(); j++)
            {
                if (all[i] == accepted_keys[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << all[i] << " : INVALID" << endl;
            else
                cout << all[i] << " : VALID" << endl;
        }
    }

    // for (int i = 0; i < accepted_keys.size(); i++)
    // {
    //     cout << accepted_keys[i] << endl;
    // }
    cout << "Hit ENTER to form the blockchain" << endl;
    cin.ignore();
    cin.ignore();

    List lst;
    lst.CreateBlockChain(accepted_keys, db, marks_card);
}

#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include <map>
#include <string>
using namespace std;

class Database
{
protected:
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

public:
    Database() {}
    Database(int number_of_entries);
    void stage2();
    void start_read();
};
#endif
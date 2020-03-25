#include <iostream>
#include <fstream>
using namespace std;

class Write{
    ofstream myfile;

    public:
    Write(string name){
        myfile.open(name);
    }

    void init(string data){
        myfile<<data<<endl;
    }
};
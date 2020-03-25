#include <iostream>
#include <../imports/map.h>
using namespace std;

class DeHash{
    map<string, int> keyresult;

    public:
    map<string,int> init(string keys[]){
        int n=(sizeof(keys)/sizeof(keys[0]));
        for(int i=0;i<n;i++){
            try{
                keyresult[keys[i]]=1;
            }
            catch(int e){
                keyresult[keys[i]]=0;
            }
        }
        return keyresult;
    }
};
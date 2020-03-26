#include <iostream>
#include <vector>
#include <map>
using namespace std;

class DeHash{
    map<string, int> keyresult;

    public:
    map<string,int> init(vector<string> keys){
        int n=keys.size();
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
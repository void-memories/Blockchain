#include <iostream>
#include "source/database.cpp"
using namespace std;

int main()
{
    int ch,n;
    while(1){
        cout<<"********************"<<endl;
        cout<<"Select An Option"<<endl;
        cout<<"1.Form The Blockchain"<<endl;
        cout<<"********************"<<endl;

        cin>>ch;
        switch(ch){
            case 1:
            cout<<"enter the number of entries"<<endl;
            cin>>n;
            Database db(n);
            cout<<"Database is being created"<<endl;
            db.start_read();


        }
    }return 0;
}
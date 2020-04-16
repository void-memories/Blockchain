#include <iostream>
#include <limits>
#include "headers/database.h"
#include "headers/exceptions.h"
using namespace std;

int main()
{
    int ch, n, halt;
    FILE *art;

    art = fopen("title.txt", "r");
    char read_string[500];

    while (!feof(art))
    {
        fgets(read_string, 500, art);
        printf("                               ");
        printf("%s", read_string);
    }
    printf("\n");

    while (1)
    {
        cout << "********************" << endl;
        cout << "1.Press 1 For The Process To Commence" << endl;
        cout << "2.Print Team Details" << endl;
        cout << "********************" << endl;

        cin >> ch;
        Exceptions ex;

        switch (ch)
        {
        
        case 1:
            cout << "Enter The Number Of Entries" << endl;
            cin >> n;
            

            try
            {
                if (n == 0)
                    throw(0);

                cout << endl
                     << "*********Database is being created*********" << endl;
                cout << "Hit ENTER to continue" << endl;
                cin.ignore();
                cin.ignore();

                Database db(n);

                cout << endl
                     << "*********Hashing has been completed*********" << endl
                     << "Hash Keys has been saved to an external file /output/hash_keys.txt" << endl
                     << "You can add invalid hashkeys to the file right now" << endl;
                cout << "Hit ENTER to start the VERIFICATION of the Hash Keys" << endl;
                cin.ignore();
                cin.ignore();

                db.start_read();
            }

            catch (int error)
            {
                ex.Exception(error);
            }
            break;

            case 2:
            cout<<"*******************************"<<endl;
            cout<<"Naman Anand       01FE18BCS119"<<endl;
            cout<<"Kirti Kunj Bajpai 01FE18BCS094"<<endl;
            cout<<"Karthik Joshi     01FE18BCS087"<<endl;
            cout<<"Koustav Ghosh     01FE18BCS099"<<endl;
            cout<<"Himanshu Mishra   01FE18BCS081"<<endl;
            cout<<"Kuljeet Singh     01FE18BCS100"<<endl;
            cout<<"Karthik M.S       01FE18BCS088"<<endl;
            cout<<"Kartik Prajapat   01FE18BCS089"<<endl;
            cout<<"Karnika Bhardwaj  01FE18BCS085"<<endl;
            cout<<"Jinesh Nagda      01FE18BCS083"<<endl;
            cout<<"Akhilesh          01FE17BCS023"<<endl;
            cout<<"*******************************"<<endl;
            break;
        }
    }
    return 0;
}
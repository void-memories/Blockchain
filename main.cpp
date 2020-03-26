#include <iostream>
#include <limits>
#include "source/database.cpp"
using namespace std;

int main()
{
    int ch, n, halt;
    while (1)
    {
        cout << "********************" << endl;
        cout << "Select An Option" << endl;
        cout << "1.Form The Blockchain" << endl;
        cout << "********************" << endl;

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "enter the number of entries" << endl;
            cin >> n;
            cout << endl
                 << "*********Database is being created*********" << endl;
            cout << "Hit ENTER to continue" << endl;
            cin.ignore();cin.ignore();


            Database db(n);

            cout << endl
             << "*********Hashing has been completed*********" << endl
             << "Hash Keys has been saved to an external file" << endl
             << "You can add invalid hashkeys to the file right now" << endl;
        cout << "Hit ENTER to start the VERIFICATION of the Hash Keys" << endl;
        cin.ignore();cin.ignore();

            db.start_read();
        }
    }
    return 0;
}
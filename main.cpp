#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin;
    ofstream fout;
    fin.open("database.csv");
    fout.open("database.csv");

    List theList(fin);

    int choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        cout << "1: Insert" << endl
             << "2: Search" << endl
             << "3: Print" << endl
             << "4: Delete" << endl
             << "5: Exit" << endl
             << "Enter your choice:" << endl;
        cout.flush();
        cin >> choice;

        if (choice == 1)
            theList.InsertPerson();
        else if (choice == 2);
        else if (choice == 3);
        else if (choice == 4);
        else if (choice == 5);
        else
            cout << "Invalid choice!" << endl;

    }while(choice != 5);

    return a.exec();
}


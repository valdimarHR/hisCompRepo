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

    list theList();

    int choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        cout << "1: Insert" << endl
             << "2: Print" << endl
             << "3: Delete" << endl
             << "4: Exit" << endl
             << "Enter your choice:" << endl;
        cout.flush();
        cin >> choice;

        if (choice == 1);
        else if (choice == 2);
        else if (choice == 3);
        else if (choice == 4);
        else
            cout << "Invalid choice!" << endl;

    }while(choice != 4);

    return a.exec();
}


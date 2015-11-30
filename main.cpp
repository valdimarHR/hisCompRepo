#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "people.h"
#include <string>
#include <vector>

using namespace std;

int theMenuChoice();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin("database.csv");
    ofstream fout("database.csv", fstream::app);

    List theList(fin);
    fin.close();

    int choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        choice = theMenuChoice();

        if (choice == 1)
            theList.InsertPersonInfo(fout);
        else if (choice == 2);
        else if (choice == 3)
            theList.Print();
        else if (choice == 4);
        else if (choice == 5);
        else
            cout << "Invalid choice!" << endl;

    }while(choice != 5);

    fout.close();

    cout << "Thank you for your visit, hope to see you again soon." << endl;

    return a.exec();
}

int theMenuChoice()
{
    int choice;

    cout << "1: Insert" << endl
         << "2: Search" << endl
         << "3: Print" << endl
         << "4: Delete" << endl
         << "5: Exit" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> choice;
    return choice;
}

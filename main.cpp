#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "people.h"
#include <vector>

using namespace std;

string theMenuChoice();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin("database.csv");
    List theList(fin);
    fin.close();

    string choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        choice = theMenuChoice();

        if (choice.size() != 1)
            cout << "Invalid choice!" << endl;
        else if (choice == "1")
        {
            ofstream fout("database.csv", fstream::app);
            theList.InsertPersonInfo(fout);
            fout.close();
        }
        else if (choice == "2");
        else if (choice == "3")
            theList.Print();
        else if (choice == "4");
        else if (choice == "5");
        else
            cout << "Invalid choice!" << endl;

    }while(choice != "5");

    cout << "Thank you for your visit, hope to see you again soon." << endl;

    return a.exec();
}

string theMenuChoice()
{
    string choice;

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

#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include <string>
#include <vector>

using namespace std;

void InsertPersonInfo(ostream& outs);
int theMenuChoice();
vector<string> dbList(ifstream& file);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin("database.csv");
    ofstream fout("database.csv", fstream::app);

    List theList(fin);

    int choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        choice = theMenuChoice();

        if (choice == 1)
            InsertPersonInfo(fout);
        else if (choice == 2);
        else if (choice == 3)
            theList.Print();
        else if (choice == 4);
        else if (choice == 5);
        else
            cout << "Invalid choice!" << endl;

    }while(choice != 5);

    cout << "Thank you for your visit, hope to see you again soon." << endl;

    fin.close();
    fout.close();

    return a.exec();
}

void InsertPersonInfo(ostream& outs)
{
    string Name, gender;
    int born, death;
    cout << "Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Gender: ";
    cin >> gender;
    cout << "Year of birth: ";
    cin >> born;
    cout << "Year of death (-1 if still alive): ";
    cin >> death;

    outs << Name << ", " << gender << ", " << born << ", " << death << endl;

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

#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

void InsertPersonInfo(ostream& outs);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin;
    ofstream fout;
    fin.open("database.txt");
    fout.open("database.txt", fstream::app);

    //List theList(fin);

    int choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        cout << "1: Insert" << endl
             << "2: Search" << endl
             << "3: Print" << endl
             << "4: Delete" << endl
             << "5: Exit" << endl
             << "Enter your choice: ";
        cout.flush();
        cin >> choice;

        if (choice == 1)
            InsertPersonInfo(fout);
        else if (choice == 2);
        else if (choice == 3);
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

    outs << Name << ", " << gender << ", " << born << "-";
    if (death == notDead)
        outs << " ." << endl;
    else
        outs << death << "." << endl;


}

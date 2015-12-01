#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "people.h"
#include <vector>
#include <algorithm>

using namespace std;

const int invalidChoice = 0;

int theMenuChoice();
void printTree();
void printError();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin("database.csv");
    if (fin.fail( ))
        {
             printError();
             return 0;
        }
    List theList(fin);
    fin.close();

    printTree();
    cout << "Welcome to Computer Sciense DB." << endl;
    int choice;
    do{
        choice = theMenuChoice();

        switch(choice)
        {
        case 1 :
         {
            ofstream fout("database.csv", fstream::app);
            theList.InsertPersonInfo(fout);
            fout.close();
         }      break;
         case 2 :
                break;
         case 3 :
             theList.Print();
         case 4 :
                break;
         case 5 :
                break;
         default:
             cout << "Invalid choice!" << endl;
        }
    }while(choice != 5);

    cout << "Thank you for your visit, hope to see you again soon." << endl;
    return a.exec();
}

int theMenuChoice()
{
    string choicestr;
    int choice;

    cout << "-----------------------" << endl;
    cout << "---Main menu---" << endl;
    cout << endl;
    cout << "1: Insert" << endl
         << "2: Search" << endl
         << "3: Print" << endl
         << "4: Delete" << endl
         << "5: Exit" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> choicestr;
    if (choicestr.size() != 1)
        choice = invalidChoice;
    else
    choice = static_cast<int>(choicestr[0]);
    choice -= '0';
    return choice;
}

void printError()
{
    cout << endl << "ERROR" << endl
         << "Please make a file with the name database.csv and put it in the right folder"
         << endl << "then open the program again." << endl << endl;
}

void printTree()
{
    cout << "----Merry christmas!!----" << endl;
    cout << endl;

    int star = 1, size = 10;
    int Height = size / 3, Width = size / 2;

    for(int total = size; total > 0; --total)
    {
        for(int i = (total - 1); i > 0; --i)
            cout << " ";

        for(int j = 0; j < star ; ++j)
            cout << "*";

        star += 2;
        cout << '\n';
    }

    for(int i = 0; i < Height; ++i)
    {
        for(int j = 0; j < (size - (Width - (Width / 2))); ++j)
             cout << " ";

        for(int k = 0; k < Width; ++k)
             cout << "|";

        cout << '\n';
    }

    cout << endl;
}

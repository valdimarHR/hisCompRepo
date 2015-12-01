#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "people.h"
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

const int invalidChoice = 0;

int theMenuChoice();
void printTree();
void printError();
void eraseEverything(List& list);

int main()
{
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
            theList.searchPerson();
                break;
         case 3 :
             theList.Print();
                break;
         case 4 :
            eraseEverything(theList);
                break;
         case 5 :
                break;
         default:
        {
            cout << "Invalid choice!" << endl;
            sleep(2);
            system("cls");
        }
        }
    }while(choice != 5);

    system("cls");
    cout << "Thank you for your visit, hope to see you again soon." << endl << endl;
    return 0;
}

int theMenuChoice()
{
    string choicestr;
    int choice;

    cout << "//-------------------------\\\\" << endl
         << "||        MAIN MENU        ||" << endl
         << "||                         ||" << endl
         << "||     1: Insert           ||" << endl
         << "||     2: Search           ||" << endl
         << "||     3: Print            ||" << endl
         << "||     4: Erase Database   ||" << endl
         << "||     5: Exit             ||" << endl
         << "||                         ||" << endl
         << "\\\\-------------------------//" << endl
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
         << endl << "then run the program again." << endl << endl;
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


//------------------------------ choice 4 -------------------------------
void eraseEverything(List& list)
{
    string warning;
    system("cls");
    cout << "This will erase everything in the database permanently!!" << endl;
    cout    << "Type the following to confirm \"continue\" (anything else to cancel)" << endl;
        cin >> warning;

        if(warning != "continue")
        {
            cout << "Good!";
            sleep(1);
            system("cls");
            return;
        }
        else
        {
            system("cls");
            list.eraseListOfVector();
            ofstream fout("database.csv");
            fout.close();

            cout << "Deleting";
            sleep(1);
            system("cls");
            cout << "Deleting.";
            sleep(1);
            system("cls");
            cout << "Deleting..";
            sleep(1);
            system("cls");
        }
};

#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include "people.h"
#include <vector>

using namespace std;

string theMenuChoice();
void printTree();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ifstream fin("database.csv");

    if (fin.fail( ))
        {
             cout << endl << "ERROR" << endl
                  << "Please make a file with the name database.csv and put it in the right folder"
                  << endl << "then open the program again." << endl << endl;
             return 0;
         }

    List theList(fin);
    fin.close();

    string choice;
    printTree();
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
    cin >> choice;
    return choice;
}

void printTree()
{
    cout << "----Merry christmas!!----" << endl;
        cout << endl;

        int star = 1;

            int size = 10;

            int Height = size / 3;
            int Width = size / 2;

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

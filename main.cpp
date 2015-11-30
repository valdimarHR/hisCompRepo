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
<<<<<<< HEAD

    if (fin.fail( ))
    {
         cout << endl << "ERROR" << endl
              << "Please make a file with the name database.csv and put it in the right folder"
              << endl << "then open the program again." << endl << endl;
         return 0;
     }
=======
>>>>>>> 646e490d736daed0d9189ddea8ced65f50af5e6c
    List theList(fin);
    fin.close();

    string choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        choice = theMenuChoice();

        if (choice.size() != 1)
            cout << "Invalid choice!" << endl;
<<<<<<< HEAD

        if (choice == "1")
=======
        else if (choice == "1")
>>>>>>> 646e490d736daed0d9189ddea8ced65f50af5e6c
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

<<<<<<< HEAD
=======
    //fout.close();

>>>>>>> 646e490d736daed0d9189ddea8ced65f50af5e6c
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

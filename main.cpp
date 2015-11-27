#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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
    }while(choice != 4);

    return a.exec();
}


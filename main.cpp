#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //Merge purfa
    QCoreApplication a(argc, argv);

    int choice = 0;
    cout << "Welcome to Computer Sciense DB." << endl;
    while(choice != 4){
        cout << "1: Insert\n2: Print\n3: Delete\n4: Exit\nEnter your choice:";
        cout.flush();
        cin >> choice;
        cout << choice;
    }

    return a.exec();
}

//comment

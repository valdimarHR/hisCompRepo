#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Hello world" << endl;
    cout << "Hello friends &co";

    return a.exec();
}


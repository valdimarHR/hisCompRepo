#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
using namespace std;

const int notDead = -1;

class List
{
public:
    List();
    List(ostream& fin);
    void InsertPerson();

};

#endif // LIST_H

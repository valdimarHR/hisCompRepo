#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "people.h"

using namespace std;

const int notDead = -1;

class List
{
public:
    List();
    List(ostream& fin);
    void InsertPerson(people person);
private:
    vector<people> People;
};

#endif // LIST_H

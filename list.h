#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
#include <string>
#include "people.h"
using namespace std;

class List
{
public:
    List();
    List(istream& fin);
    void InsertPerson();
    int stringToInt(string str) const;
    void Print();
private:
    vector <people> listOfPeople;

};

#endif // LIST_H

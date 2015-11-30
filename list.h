#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "people.h"
#include <vector>
#include <string>
#include "people.h"

using namespace std;

class List
{
public:
    List();
    List(istream& fin);
    void InsertPersonInfo(ostream& outs);
    void Print();
private:
    vector<people> People;
    void InsertPerson();
    int stringToInt(string str) const;
private:
    vector <people> listOfPeople;

};

#endif // LIST_H

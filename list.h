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
    void InsertPerson(people person);
    void InsertPersonInfo(ostream& outs);
private:
    vector<people> People;
    void InsertPerson();
    int stringToInt(string str) const;
private:
    vector <people> listOfPeople;

};

#endif // LIST_H

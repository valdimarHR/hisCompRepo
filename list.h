#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "people.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class List
{
public:
    List();
    List(istream& fin);
    void InsertPersonInfo(ostream& outs);
    void Print();
    void searchPerson(vector<people>& listOfPeople);
private:
    int stringToInt(const string& str) const;
    vector<people> listOfPeople;
    bool checkIfpersonOnList(people person);

};

#endif // LIST_H

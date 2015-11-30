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
private:
    vector<people> People;
    void InsertPerson();
    int stringToInt(string str) const;
    static bool sortName(people a, people b);
    static bool sortGender(people a, people b);
    static bool sortBirth(people a, people b);
    static bool sortDeath(people a, people b);
    void searchPerson(istream& fin);
    int stringToInt(const string& str) const;
    vector <people> listOfPeople;
    bool checkIfpersonOnList(people person);

};

#endif // LIST_H

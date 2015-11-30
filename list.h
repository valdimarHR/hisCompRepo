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
    static bool sortName(people a, people b);
    static bool sortGender(people a, people b);
    static bool sortBirth(people a, people b);
    static bool sortDeath(people a, people b);
    bool checkIfpersonOnList(const people& person);
    vector <people> listOfPeople;
};

#endif // LIST_H

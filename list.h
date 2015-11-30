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
<<<<<<< HEAD
    bool checkIfpersonOnList(const people& person);
    vector <people> listOfPeople;
=======
    void searchPerson(istream& fin);
    int stringToInt(const string& str) const;
    vector <people> listOfPeople;
    bool checkIfpersonOnList(people person);

>>>>>>> 646e490d736daed0d9189ddea8ced65f50af5e6c
};

#endif // LIST_H

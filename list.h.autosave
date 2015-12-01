#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "people.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>

using namespace std;

class List
{
public:
    List();
    List(std::istream& fin);
    void InsertPersonInfo(std::ostream& outs);
    void Print();
    void searchPerson(std::vector<people>& listOfPeople);
private:
    int stringToInt(const std::string& str) const;
    std::vector<people> listOfPeople;
    bool checkIfpersonOnList(people person);
    void searchPerson(std::istream& fin);
    void eraseListOfVector();
private:
    //std::vector<people> listOfPeople;
    static bool sortName(people a, people b);
    static bool sortGender(people a, people b);
    static bool sortBirth(people a, people b);
    static bool sortDeath(people a, people b);
    bool checkIfpersonOnList(const people& person);

#endif // LIST_H

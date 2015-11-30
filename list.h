#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "people.h"
#include <vector>
#include <string>

using namespace std;

class List
{
public:
    List();
    List(istream& fin);
    void InsertPersonInfo(ostream& outs);
    void Print();
    void searchPerson(istream& fin);
    virtual string getName(istream& fin);
    virtual string getGender(istream& fin);
    virtual int getBirthYear(istream& fin);
    virtual int getDeathYear(istream& fin);
private:
    int stringToInt(const string& str) const;
    vector <people> listOfPeople;
    bool checkIfpersonOnList(people person);

};

#endif // LIST_H

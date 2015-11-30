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
    void searchPerson();
    virtual string getName(istream& fin) = 0;
    virtual string getGender(istream& fin) = 0;
    virtual int getBirthYear(istream& fin) = 0;
    virtual int getDeathYear(istream& fin) = 0;
private:
    int stringToInt(const string& str) const;
    vector <people> listOfPeople;
    bool checkIfpersonOnList(people person);

};

#endif // LIST_H

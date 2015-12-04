#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "people.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <typeinfo>
#include <stdio.h>

using namespace std;

class List
{
public:
    List();
    List(vector <people> list);
    void InsertPersonInfo(ostream& outs);
    void Print() const;
    void searchPerson();
    bool eraseListOfVector();
private:
    vector<people> theList;
    static bool sortName(const people& a, const people& b);
    static bool sortGender(const people& a, const people& b);
    static bool sortBirth(const people& a, const people& b);
    static bool sortDeath(const people& a, const people& b);
    bool checkIfpersonOnList(const people& person) const;
    void getInsertedInfo(string& name, string& gender, int& born, int& death)const;
    void printerMenu(int& orderBy, bool& ascending)const;
};

#endif // LIST_H

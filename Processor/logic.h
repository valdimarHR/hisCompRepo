#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "Models/people.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <typeinfo>
#include <stdio.h>

using namespace std;

class logic
{
public:
    logic();
    bool insertPerson(string& name, string& gender, int& born, int& death);
    bool insertComputer(string& name, string& type, int& created, bool& built);
    vector<people> findByPeopleName(string name);
    vector<people> findByPeopleGender(string gender);
    vector<people> findByPeopleBirth(int birthYear);
    vector<people> findByPeopleDeath(int deathYear);
    vector<people> printerSortPeople(int orderBy, int ascending) const;
    void searchPerson();
    bool eraseListOfVector();
private:
    static bool sortName(const people& a, const people& b);
    static bool sortGender(const people& a, const people& b);
    static bool sortBirth(const people& a, const people& b);
    static bool sortDeath(const people& a, const people& b);
    bool checkIfpersonOnList(const people& person) const;
    void getInsertedInfo(string& name, string& gender, int& born, int& death)const;
};

#endif // LIST_H

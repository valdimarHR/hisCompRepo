#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "Models/people.h"
#include "DataFetch/datafetch.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <typeinfo>
#include <stdio.h>
#include <QSqlQuery>
#include <QSql>
#include <QString>
#include <QVariant>

using namespace std;

class logic
{
public:
    logic();
    bool insertPerson(string& name, string& gender, int& born, int& death);
    bool insertComputer(string& name, int& created, string& type, bool& built);
    vector<people> findByPeopleName(string name);
    vector<people> findByPeopleGender(string gender);
    vector<people> findByPeopleBirth(int birthYear);
    vector<people> findByPeopleDeath(int deathYear);
    vector<people> printerSortPeople(int orderBy, int ascending) const;
    void searchPerson();
    bool eraseListOfVector();
private:
    dataFetch theData;
    static bool sortName(const people& a, const people& b);
    static bool sortGender(const people& a, const people& b);
    static bool sortBirth(const people& a, const people& b);
    static bool sortDeath(const people& a, const people& b);
    bool checkIfpersonOnList(const people& person) const;
    void getInsertedInfo(string& name, string& gender, int& born, int& death)const;

};

#endif // LIST_H

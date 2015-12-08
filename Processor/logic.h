#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "Models/people.h"
#include "Models/computers.h"
#include "Models/peoplewithcomputers.h"
#include "Models/computerswithpeople.h"
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
    bool insertConnection(const int& sid, const int& cid);
    vector<peopleWithComputers> printerSortPeople(int orderBy, int ascending);
    vector<computersWithPeople> printerSortComputers(int orderBy, int ascending);
    vector<peopleWithComputers> findPeople(string column, string searchValue);
    vector<computersWithPeople> findComputer(string column, string searchValue);
    void searchPerson();
    vector<people> printerPeople();
    vector<computers> printerComputers();
    void eraseChosenPeople(const vector<people>& p, const int& index);
    void eraseChosenComputer(const vector<computers>& c, const int& index);
private:
    dataFetch theData;
    static bool sortPeopleName(const peopleWithComputers& a, const peopleWithComputers& b);
    static bool sortPeopleGender(const peopleWithComputers& a, const peopleWithComputers& b);
    static bool sortPeopleBirth(const peopleWithComputers& a, const peopleWithComputers& b);
    static bool sortPeopleDeath(const peopleWithComputers& a, const peopleWithComputers& b);
    static bool sortComputersName(const computersWithPeople& a, const computersWithPeople& b);
    static bool sortComputersType(const computersWithPeople& a, const computersWithPeople& b);
    static bool sortComputersYear(const computersWithPeople& a, const computersWithPeople& b);
    static bool sortComputersBuilt(const computersWithPeople& a, const computersWithPeople& b);
    bool checkIfpersonOnList(const people& person) const;
    void getInsertedInfo(string& name, string& gender, int& born, int& death)const;


};

#endif // LIST_H

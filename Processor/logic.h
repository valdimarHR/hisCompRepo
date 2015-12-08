#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "Models/people.h"
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
    /*
     * findPeople function is used so the user can find a person in the database by name, gender,
     * year of death and year of birth and returns said information
     */
    vector<computersWithPeople> findComputer(string column, string searchValue);
    /*
     * findComputer function is used so the user can find a computer in the database by name, type,
     * year of creation and whether it was built or not and returns said information
     */
    bool eraseListOfVector();
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

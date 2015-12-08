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
    vector<computersWithPeople> findComputer(string column, string searchValue);
    void searchPerson();
    bool eraseListOfVector();
private:
    dataFetch theData;
    bool checkIfpersonOnList(const people& person) const;
    void getInsertedInfo(string& name, string& gender, int& born, int& death)const;

};

#endif // LIST_H

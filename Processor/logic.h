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
    bool insertPerson(string& name, string& gender, int& born, int& death);//Prepares to insert person to SQL DB.(already excisting etc.)
    bool insertComputer(string& name, int& created, string& type, bool& built);//Prepares to insert computer to SQL DB.
    bool insertConnection(const int& sid, const int& cid);
    vector<peopleWithComputers> printerSortPeople(int orderBy, int ascending);
    vector<computersWithPeople> printerSortComputers(int orderBy, int ascending);
    vector<peopleWithComputers> findPeople(string column, string searchValue);//Finds person in the database
    vector<computersWithPeople> findComputer(string column, string searchValue);//Finds computer in the database
    bool eraseListOfVector();
    void searchPerson();
    vector<people> printerPeople();//Creates a vector of people and calls dataFetch for all the info.
    vector<computers> printerComputers();//Creates a vector of computers and calls dataFetch for all the info.
    void eraseChosenPeople(const vector<people>& p, const int& index);//Finds id of Scientist to delete and sends to datafetch.
    void eraseChosenComputer(const vector<computers>& c, const int& index);//Finds id of computer to delete and sends to datafetch.
    void eraseDB();//Calls datafetch to erase everything.
private:
    dataFetch theData;
    bool checkIfpersonOnList(const people& person);
    bool checkIfcomputerOnList(const computers& computer);

};

#endif // LIST_H

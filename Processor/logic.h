#ifndef LIST_H
#define LIST_H

#include <iostream>
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

/**
 * @brief The logic is the link between the UI and the data.
 * The logic also manipulates the data e.g. sorts it as the
 * user wants before returning it to the UI.
 */

using namespace std;

class logic
{
public:
    logic();
    bool insertPerson(string& name, string& gender, int& born, int& death);//Prepares to insert person to SQL DB.(already excisting etc.)
    bool insertComputer(string& name, int& created, string& type, bool& built);//Prepares to insert computer to SQL DB.
    bool insertConnection(const int& sid, const int& cid);
    /**
     * @brief sends a request for a people vector from data and then sorts that vector as the
     * user has requested.
     * @return returns a sorted vector with people to the ui for it to display.
     */
    vector<peopleWithComputers> printerSortPeople(int orderBy, int ascending);
    /**
     * @brief sends a request for a computer vector from data and then sorts that vector as the
     * user has requested.
     * @return returns a sorted vector with computers to the ui for it to display.
     */
    vector<computersWithPeople> printerSortComputers(int orderBy, int ascending);
    /**
     * @brief finds people in database using vector and sorts them as the user wants to sort them
     * @return returns the found people in a sorted list
     */
    vector<peopleWithComputers> findPeople(string column, string searchValue);
    /**
     * @brief find coumputers in database using vector and sorts them as the user wants to sort them
     * @return returns the found computers in a sorted list
     */
    vector<computersWithPeople> findComputer(string column, string searchValue);
    bool eraseListOfVector();
    void searchPerson();
    void eraseChosenPeople(const vector<peopleWithComputers>& p, const int& index);//Finds id of Scientist to delete and sends to datafetch.
    void eraseChosenComputer(const vector<computersWithPeople>& c, const int& index);//Finds id of computer to delete and sends to datafetch.
    void eraseDB();//Calls datafetch to erase everything.
private:
    dataFetch theData;
    bool checkIfpersonOnList(const people& person);
    bool checkIfcomputerOnList(const computers& computer);

};

#endif // LIST_H

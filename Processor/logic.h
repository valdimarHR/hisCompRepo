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
#include <QDebug>

using namespace std;

/**
 * @brief The logic is the link between the UI layer and the data layer.
 * The logic also manipulates the data e.g. sorts it as the
 * user wants before returning it to the UI.
 */

class logic
{
public:
    logic();
    /**
     * @brief Prepares to insert person to SQL DB.(already excisting etc.)
     * @param the information needed to make an object of people.
     * @return a bool, true if the person was already in database.
     */
    bool insertPerson(string& name, string& gender, int& born, int& death);
    /**
     * @brief Prepares to insert computer to SQL DB.(already excisting etc.)
     * @param the information needed to make an object of computers.
     * @return a bool, true if the computer was already in database.
     */
    bool insertComputer(string& name, int& created, string& type, bool& built);
    /**
     * @brief Prepares to insert connection to SQL DB.(already excisting etc.)
     * @param the id for the scientist and the id for the computer that will be connected.
     * @return a bool, true if the connection was already in database.
     */
    bool insertConnection(const int& sid, const int& cid);
    /**
     * @brief
     *
     */
    bool editPerson(const int &id, const string &name, const string &gender, const int &birth, const int &death, const string &info);
    /**
     * @brief editComputer
     * @param
     * @return
     */
    bool editComputer(const int &id, const string & name, const int &year, const string &type, const bool & wasBuilt);
    /**
     * @brief printerSortPeople sends a request for a people vector from data and then sorts that vector as the
     * user has requested.
     * @param orderBy is to what column should the table be ordered by.
     * @param ascending order or not.
     * @return returns a sorted vector with people to the ui for it to display.
     */
    vector<peopleWithComputers> printerSortPeople(int orderBy, int ascending);
    /**
     * @brief printerSortComputers sends a request for a computer vector from data and then sorts that vector as the
     * user has requested.
     * @param orderBy is to what column should the table be ordered by.
     * @param ascending order or not.
     * @return returns a sorted vector with computers to the ui for it to display.
     */
    vector<computersWithPeople> printerSortComputers(int orderBy, int ascending);
    /**
     * @brief finds people in database using vector and sorts them as the
     * user wants to sort them
     * @param column is to know in field in the Scientist table to look for (name, birth etc)
     * @param searchValue is a string which content will be looked for.
     * @return returns the found people in a sorted list
     */
    vector<peopleWithComputers> findPeople(string column, string searchValue);
    /**
     * @brief find coumputers in database using vector and sorts them
     * as the user wants to sort them
     * @param the same as in the function on top of this except for computer
     * @return returns the found computers in a sorted list
     */
    vector<computersWithPeople> findComputer(string column, string searchValue);
    /**
     * @brief eraseChosenPeople finds id of Scientist to delete and sends to datafetch.
     * @param p is a pass by reference vector that will be filled with all the people in the database.
     * @param index is the index of the person to be deleted.
     */
    void eraseChosenPeople(const int& id);
    /**
     * @brief eraseChosenComputer finds id of computer to delete and sends to datafetch.
     * @param id of the computer to be deleted.
     */
    void eraseChosenComputer(const int& index);
    /**
     * @brief eraseDB calls datafetch to erase everything.
     */
    void eraseDB();
private:
    dataFetch theData;
    /**
     * @brief person is sent on to database to check if is already on list.
     * @param the person that is to be checked if is on list.
     * @return returns bool, true if person was on list.
     */
    bool checkIfpersonOnList(const people& person);
    /**
     * @brief computer is sent on to database to check if is already on list.
     * @param the computer that is to be checked if is on list.
     * @return returns bool, true if computer was on list.
     */
    bool checkIfcomputerOnList(const computers& computer);

};

#endif // LIST_H

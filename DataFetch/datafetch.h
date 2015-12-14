#ifndef DATAFETCH_H
#define DATAFETCH_H

#include "Models/people.h"
#include "Models/computers.h"
#include "Models/peoplewithcomputers.h"
#include "Models/computerswithpeople.h"
#include <vector>
#include <QSqlQuery>
#include <QSql>
#include <QString>
#include <QVariant>
#include <QFile>

using namespace std;

/**
 * @brief The dataFetch reads into and from the database, depending on the inputs it gets from the logic layer.
 * It also checks if something is already in the database or creates a database with all the tables needed if
 * one is not already here.
 */

class dataFetch
{
public:
    /**
     * @brief Creates a connection to the database.
     */
    dataFetch();
    ~dataFetch();
    /**
     * @brief fetchPeople queries the database for people dependant on the search input.
     * @param columnName is column that should be searched in if there is a search requirement.
     * @param searchString is the string that is beeing looked for in the search column.
     * @return a vector with people that matched the search requirements.
     */
    vector<peopleWithComputers> fetchPeople(string columnName, string searchString);
    /**
     * @brief fetchComputers queries the database for computers dependant on the search input.
     * @param columnName is column that should be searched in if there is a search requirement.
     * @param seartchString is the string that is beeing looked for in the search column.
     * @return a vector with computers that matched the search requirements.
     */
    vector<computersWithPeople> fetchComputers(string columnName, string searchString);
    /**
     * @brief insertPersonToDatabase inserts a person into the database.
     * @param a is the people object that holds the information that will be added to the database.
     */
    void insertPersonToDatabase(const people& a);
    /**
     * @brief insertComputerToDatabase inserts a computer into the database.
     * @param c is the computer object that holds the information that will be added to the database.
     */
    void insertComputerToDatabase(const computers& c);
    /**
     * @brief insertConnectionToDatabase will insert a connection into the database.
     * @param sid is the Scientists id to connect.
     * @param cid is the Computer id to connect.
     */
    void insertConnectionToDatabase(const int& sid, const int& cid);
    /**
     * @brief checks if connection between scientist and a computer is already in DB.
     * @param the id from the scientist and the computer.
     * @return a bool that is true if the connection was already in DB.
     */
    bool alreadyConnnected(const int sid, const int cid);
    /**
     * @brief checks if person is already in DB.
     * @param the person that is being checked.
     * @return a bool that is true if the person was already in DB.
     */
    bool personAlreadyOnList(const people& person);
    /**
     * @brief checks if computer is already in DB.
     * @param the computer that is being checked.
     * @return a bool that is true if the computer was already in DB.
     */
    bool computerAlreadyOnList(const computers& computer);
    /**
     * @brief deletePeople sets isDeleted on the person to true with matching id.
     * @brief editPersonDb
     * @param
     * @return
     */
    bool editPersonDb(const int &id, const string &name, const string &gender, const int &birth, const int &death, const string &info);
    /**
     * @brief editComputerDB
     * @param
     * @return
     */
    bool editComputerDb(const int &id, const string &name, const int &year, const string &type, const bool &wasBuilt, const string &info);
    /**
     * @brief deletePeople hides the person in the SQL DB with matching id.
     * @param id of the person.
     */
    void deletePeople(const int& id);
    /**
     * @brief deleteComputer hides the computer in SQL DB with matching id.
     * @param id of the computer.
     */
    void deleteComputer(const int& id);
    /**
     * @brief deleteConnectionDb
     * @param sid
     * @param cid
     * @return
     */
    bool deleteConnectionDb(const int &sid, const int &cid);
    /**
     * @brief eraseEverything deletes all the data in the DB (scientists, computers and connections).
     */
    void eraseEverything();
private:
    /**
     * @brief convertPeopleTable converts the query data from the database to a vector of people.
     * @param query holds the data from the database after it has been queried.
     * @return a vector of people and the computers they worked on.
     */
    vector<peopleWithComputers> convertPeopleTable(QSqlQuery& query);
    /**
     * @brief convertComputersTable converts the query data from the database to a vector of computers.
     * @param query holds the data from the database after it has been queried.
     * @return a vector of computers and their creators.
     */
    vector<computersWithPeople> convertComputersTable(QSqlQuery& query);

    void createDatabase();
    QSqlDatabase db;
};

#endif // DATAFETCH_H

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
 * @brief The dataFetch reads to and from database, depending on the query what it returns.
 * Also checks if something is already in database.
 */

class dataFetch
{
public:
    /**
     * @brief Creates a connection to the database.
     */
    dataFetch();
    vector<peopleWithComputers> fetchPeople(string columnName, string searchString);
    vector<computersWithPeople> fetchComputers(string columnName, string seartchString);
    void insertPersonToDatabase(const people& a);
    void insertComputerToDatabase(const computers& c);
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
    bool personAlreadyOnList(const people& person); //Checks if person sent from logic is already in DB.
    /**
     * @brief checks if computer is already in DB.
     * @param the computer that is being checked.
     * @return a bool that is true if the computer was already in DB.
     */
    bool computerAlreadyOnList(const computers& computer);
    void deletePeople(const int& id);//Takes in id number. Deletes the person in the SQL DB with matching id.
    void deleteComputer(const int& id);//Takes in id number. Deletes the computer in SQL DB with matching id.
    void eraseEverything();//Deletes everything inside all the SQL DB (scientists, computers and connections).
private:
    vector<peopleWithComputers> convererPeopleTable(QSqlQuery& query);
    vector<computersWithPeople> convererComputersTable(QSqlQuery& query);
    vector<people> convererCombinedTable(QSqlQuery& query);

    void createDatabase();
    QSqlDatabase db;
};

#endif // DATAFETCH_H

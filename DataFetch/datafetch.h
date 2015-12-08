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


class dataFetch
{
public:
    dataFetch();
    vector<peopleWithComputers> fetchPeople(string columnName, string searchString);
    vector<computersWithPeople> fetchComputers(string columnName, string seartchString);
    void insertPersonToDatabase(const people& a);//Add all info to new person to SQL Database.
    void insertComputerToDatabase(const computers& c);//Add all info to new computer to SQL Database
    void insertConnectionToDatabase(const int& sid, const int& cid);
    void fetchPeopleOnly(vector<people>& p);//Takes info of all people from SQL DB and pushes in the vector p.
    void fetchComputersOnly(vector<computers>& c);//Takes info of all computer from SQL DB and pushes in the vector c.
    bool alreadyConnnected(const int sid, const int cid);
    bool personAlreadyOnList(const people& person);
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

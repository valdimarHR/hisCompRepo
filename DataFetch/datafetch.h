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

using namespace std;


class dataFetch
{
public:
    dataFetch();
    vector<peopleWithComputers> fetchPeople(string columnName, string seartchString);
    vector<computersWithPeople> fetchComputers(string columnName, string seartchString);
    void insertPersonToDatabase(const people& a);
    void insertComputerToDatabase(const computers& c);
    void insertConnectionToDatabase(const int& sid, const int& cid);
private:
    vector<peopleWithComputers> convererPeopleTable(QSqlQuery& query);
    vector<computersWithPeople> convererComputersTable(QSqlQuery& query);
    vector<people> convererCombinedTable(QSqlQuery& query);
    QSqlDatabase db;
};

#endif // DATAFETCH_H

#ifndef DATAFETCH_H
#define DATAFETCH_H

#include "Models/people.h"
#include "Models/computers.h"
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
    vector<people> fetch(QString sqlCommand);
    void insertPersonToDatabase(const people& a);
    void insertComputerToDatabase(const computers& c);
private:
    vector<people> convererPeopleTable(QSqlQuery& query);
    vector<people> convererComputerTable(QSqlQuery& query);
    vector<people> convererCombinedTable(QSqlQuery& query);
    QSqlDatabase db;
};

#endif // DATAFETCH_H

#ifndef DATAFETCH_H
#define DATAFETCH_H

#include "Models/people.h"
#include "Models/computers.h"
#include <vector>
#include <QString>
#include <QSqlQuery>


class DataFetch
{
public:
    DataFetch();
    vector<people> fetch(QString sqlCommand);
private:
    vector<people> convererPeopleTable(QSqlQuery& query);
    vector<people> convererComputerTable(QSqlQuery& query);
    vector<people> convererCombinedTable(QSqlQuery& query);
    QSqlDatabase db;
};

#endif // DATAFETCH_H

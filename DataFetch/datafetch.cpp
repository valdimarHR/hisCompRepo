#include "datafetch.h"
#include "Models/people.h"
#include "Models/computers.h"
#include "string"
#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <QString>
#include <QSqlQuery>
#include <QSql>

using namespace std;

DataFetch::DataFetch()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "database.sqlite";
    db.setDatabaseName(dbName);

}

vector<people> DataFetch::fetch(QString sqlCommand)
{

    db.open();
    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists"); //"sqlCommand" will be used here
    return convererPeopleTable(query);

}

vector<people> DataFetch::convererPeopleTable(QSqlQuery& query)
{
//    vector<people> peopleVector;
//    while(query.next())
//    {
//        string name = query.value("name").toString().toStdString();
//        string gender = query.value("gender").toString().toStdString();
//        int born = query.value("born").toUInt();
//        int death = query.value("death").toUInt();

//        people per;
//        per.setName(name);
//        per.setGender(gender);
//        per.setBirth(born);
//        per.setDeath(death);

//        peopleVector.push_back(per);
//    }
//    return peopleVector;
}

vector<people> DataFetch::convererComputerTable(QSqlQuery& query)
{
    //NEED TO IMPLEMENT
    vector<people> peopleVector;
    return peopleVector;

}

vector<people> DataFetch::convererCombinedTable(QSqlQuery& query)
{
    //NEED TO IMPLEMENT
    vector<people> peopleVector;
    return peopleVector;

}


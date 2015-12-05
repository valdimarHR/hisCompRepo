#include "DataFetch/datafetch.h"

dataFetch::dataFetch()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "database.sqlite";
    db.setDatabaseName(dbName);

}

vector<people> dataFetch::fetch(QString sqlCommand)
{

    db.open();
    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists"); //"sqlCommand" will be used here
    return convererPeopleTable(query);

}

vector<people> dataFetch::convererPeopleTable(QSqlQuery& query)
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

vector<people> dataFetch::convererComputerTable(QSqlQuery& query)
{
    //NEED TO IMPLEMENT
    vector<people> peopleVector;
    return peopleVector;

}

vector<people> dataFetch::convererCombinedTable(QSqlQuery& query)
{
    //NEED TO IMPLEMENT
    vector<people> peopleVector;
    return peopleVector;

}



void dataFetch::inserPersonToDatabase(const people& a)
{

    db.open();
    QSqlQuery query(db);

    int birth = a.getBirth();
    int death = a.getDeath();
    string gender = a.getGender();
    string name = a.getName();

    query.prepare("INSERT INTO Scientists (name, gender, death, birth) VALUES (:name, :gender, :death, :birth)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":gender", QString::fromStdString(gender));
    query.bindValue(":birth", birth);
    query.bindValue(":death", death );
    query.exec();
    db.close();

}

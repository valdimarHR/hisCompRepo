#include "DataFetch/datafetch.h"
#include <QVariant>

dataFetch::dataFetch()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "database.sqlite";
    db.setDatabaseName(dbName);

}

vector<peopleWithComputers> dataFetch::fetchPeople(QString columnName, QString seartchString)
{
    db.open();
    QSqlQuery query(db);

    QString command = "SELECT * FROM Scientists AS S ";
    command += "LEFT JOIN (SELECT * FROM Computers AS C ";
    command += "LEFT JOIN Invents AS I ";
    command += "ON I.cid = C.id) AS T ";
    command += "ON T.sid = S.id WHERE S." + columnName + " LIKE '%" + seartchString + "%'";

    query.prepare(command);
    query.bindValue(":columnName", columnName);
    query.bindValue(":seartchString", seartchString);
    query.exec();

    vector<peopleWithComputers> pepVector = convererPeopleTable(query);

    db.close();

    return pepVector;

}

vector<peopleWithComputers> dataFetch::convererPeopleTable(QSqlQuery& query)
{
    vector<peopleWithComputers> peopleVector;
    int lastId = -1;
    while(query.next())
    {
        int currentPersonId = query.value(0).toUInt();

        computers comp;
        if(query.value(5).toUInt() != 0)
        {
            string Cname = query.value(6).toString().toStdString();
            int CyearCreated = query.value("yearCreated").toUInt();
            string Ctype = query.value("type").toString().toStdString();
            bool CwasBuilt = query.value("wasBuilt").toUInt();

            comp.setName(Cname);
            comp.setYearCreated(CyearCreated);
            comp.setType(Ctype);
            comp.setWasBuilt(CwasBuilt);

            if(currentPersonId == lastId){
                peopleVector.back().creations.push_back(comp);
                continue;
            }
        }

        string Pname = query.value(1).toString().toStdString();
        string Pgender = query.value("gender").toString().toStdString();
        int Pborn = query.value("birth").toUInt();
        int Pdeath = query.value("death").toUInt();

        peopleWithComputers per;
        per.p.setName(Pname);
        per.p.setGender(Pgender);
        per.p.setBirth(Pborn);
        per.p.setDeath(Pdeath);
        per.p.setId(currentPersonId);
        per.creations.push_back(comp);

        peopleVector.push_back(per);

        lastId = currentPersonId;
    }
    return peopleVector;
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
    //Þurfum við nokkuð þetta fall?
}



void dataFetch::insertPersonToDatabase(const people& a)
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


void dataFetch::insertComputerToDatabase(const computers& c)
{

    db.open();
    QSqlQuery query(db);

    string name = c.getName();
    int yearCreated = c.getYearCreated();
    string type = c.getType();
    bool wasBuilt = c.getWasBuilt();


    query.prepare("INSERT INTO Computers (name, yearCreated, type, wasBuilt) VALUES (:name, :yearCreated, :type, :wasBuilt)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":yearCreated", yearCreated);
    query.bindValue(":type", QString::fromStdString(type));
    query.bindValue(":wasBuilt", wasBuilt );
    query.exec();
    db.close();
}

void dataFetch::insertConnectionToDatabase(const int& sid, const int& cid)
{
    db.open();
    QSqlQuery query(db);

    query.prepare("INSERT INTO Invents (sid, cid) VALUES (:sid, :cid)");
    query.bindValue(":sid", sid);
    query.bindValue(":cid", cid);
    query.exec();
    db.close();
}

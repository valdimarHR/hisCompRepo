#include "DataFetch/datafetch.h"
#include <QVariant>
#include <QFile>

dataFetch::dataFetch()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QFile dbfile;
    if(!dbfile.exists("database.sqlite")) createDatabase();
    QString dbName = "database.sqlite";
    db.setDatabaseName(dbName);

}

vector<peopleWithComputers> dataFetch::fetchPeople(string columnName, string seartchString)
{
    db.open();
    QSqlQuery query(db);

    QString command = "SELECT * FROM Scientists AS S ";
    command += "LEFT JOIN (SELECT * FROM Computers AS C ";
    command += "LEFT JOIN Invents AS I ";
    command += "ON I.cid = C.id) AS T ";
    command += "ON T.sid = S.id WHERE S." + QString::fromStdString(columnName) + " LIKE '%" + QString::fromStdString(seartchString) + "%'";

    query.prepare(command);
    //query.bindValue(":columnName", columnName);
    //query.bindValue(":seartchString", seartchString);
    query.exec();

    vector<peopleWithComputers> pepVector = convererPeopleTable(query);

    db.close();

    return pepVector;

}

vector<computersWithPeople> dataFetch::fetchComputers(string columnName, string seartchString)
{
    db.open();
    QSqlQuery query(db);

    QString command = "SELECT * FROM Computers AS C ";
    command += "LEFT JOIN (SELECT * FROM Scientists AS S ";
    command += "LEFT JOIN Invents AS I ";
    command += "ON I.sid = S.id) AS T ";
    command += "ON T.cid = C.id WHERE C." + QString::fromStdString(columnName) + " LIKE '%" + QString::fromStdString(seartchString) + "%'";

    query.prepare(command);
    //query.bindValue(":columnName", columnName);
    //query.bindValue(":seartchString", seartchString);
    query.exec();

    vector<computersWithPeople> comVector = convererComputersTable(query);

    db.close();

    return comVector;

}

bool dataFetch::alreadyConnnected(const int sid, const int cid)
{
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Invents");

    bool connected = false;

    while(query.next())
    {
        int tableSid = query.value("sid").toUInt();
        int tableCid = query.value("cid").toUInt();
        if ((sid == tableSid)&&(cid == tableCid))
            connected = true;
    }

    return connected;
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

vector<computersWithPeople> dataFetch::convererComputersTable(QSqlQuery& query)
{
    vector<computersWithPeople> computersVector;
    int lastId = -1;
    while(query.next())
    {
        int currentComputerId = query.value(0).toUInt();

        people per;
        if(query.value(5).toUInt() != 0)
        {
            string Pname = query.value(6).toString().toStdString();
            string Pgender = query.value("gender").toString().toStdString();
            int Pborn = query.value("birth").toUInt();
            int Pdeath = query.value("death").toUInt();

            per.setName(Pname);
            per.setGender(Pgender);
            per.setBirth(Pborn);
            per.setDeath(Pdeath);

            if(currentComputerId == lastId){
                computersVector.back().creators.push_back(per);
                continue;
            }
        }

        computersWithPeople comp;
        string Cname = query.value(1).toString().toStdString();
        int CyearCreated = query.value("yearCreated").toUInt();
        string Ctype = query.value("type").toString().toStdString();
        bool CwasBuilt = query.value("wasBuilt").toUInt();

        comp.c.setId(currentComputerId);
        comp.c.setName(Cname);
        comp.c.setYearCreated(CyearCreated);
        comp.c.setType(Ctype);
        comp.c.setWasBuilt(CwasBuilt);
        comp.creators.push_back(per);

        computersVector.push_back(comp);

        lastId = currentComputerId;
    }
    return computersVector;

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

void dataFetch::fetchPeopleOnly(vector<people>& p)
{
    db.open();
    QSqlQuery query(db);

    query.prepare("SELECT * FROM Scientists");
    query.exec();

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int birth = query.value("birth").toUInt();
        int death = query.value("death").toUInt();
        people temp(id,name,gender,birth,death);
        p.push_back(temp);
    }
    db.close();
}

void dataFetch::fetchComputersOnly(vector<computers>& c)
{
    db.open();
    QSqlQuery query(db);

    query.prepare("SELECT * FROM Computers");
    query.exec();

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        int yearcreated = query.value("yearCreated").toUInt();
        string type = query.value("type").toString().toStdString();
        int wasBuilt = query.value("wasBuilt").toUInt();
        computers temp(id,name,yearcreated,type,wasBuilt);
        c.push_back(temp);
    }
    db.close();
}

void dataFetch::deletePeople(const int& id)
{
    db.open();
    QSqlQuery query(db);

    string comm = "DELETE FROM Scientists WHERE id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();

    string comm2 = "DELETE FROM Invents WHERE sid = " +to_string(id);
    QString command2 = QString::fromStdString(comm2);
    query.prepare(command2);
    query.exec();

    db.close();
}

void dataFetch::deleteComputer(const int& id)
{
    db.open();
    QSqlQuery query(db);

    string comm = "DELETE FROM Computers WHERE id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();

    string comm2 = "DELETE FROM Invents WHERE cid = " +to_string(id);
    QString command2 = QString::fromStdString(comm2);
    query.prepare(command2);
    query.exec();

    db.close();
}

void dataFetch::createDatabase()
{
    db.setDatabaseName("database.sqlite");
    db.open();
    QSqlQuery query(db);

    query.prepare("CREATE TABLE 'Computers' ('id' INTEGER PRIMARY KEY  "
                  "NOT NULL ,'name' VARCHAR NOT NULL ,'yearCreated' "
                  "INTEGER NOT NULL ,'type' VARCHAR NOT NULL ,"
                  "'wasBuilt' BOOL NOT NULL  DEFAULT (null) )");
    query.exec();

    query.prepare("CREATE TABLE 'Scientists' ('id' INTEGER PRIMARY KEY  AUTOINCREMENT  "
                  "NOT NULL , 'name' VARCHAR NOT NULL , 'gender' VARCHAR NOT NULL , "
                  "'birth' INTEGER NOT NULL , 'death' INTEGER)");
    query.exec();

    query.prepare("CREATE TABLE Invents(sid INTEGER,cid INTEGER,"
                  "FOREIGN KEY (sid) REFERENCES Scientists(id),"
                  "FOREIGN KEY (cid) REFERENCES Computers(id) "
                  "PRIMARY KEY (sid, cid))");
    query.exec();
    db.close();
}

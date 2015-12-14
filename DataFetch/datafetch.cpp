#include "DataFetch/datafetch.h"

dataFetch::dataFetch()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QFile dbfile;
    if(!dbfile.exists(constants::NAME_OF_DATABASE)) createDatabase();
    QString dbName = constants::NAME_OF_DATABASE;
    db.setDatabaseName(dbName);
}

vector<peopleWithComputers> dataFetch::fetchPeople(string columnName, string searchString)
{
    db.open();
    QSqlQuery query(db);

    QString command = "SELECT * FROM Scientists AS S "
            "LEFT JOIN (SELECT * FROM Computers AS C "
            "LEFT JOIN Invents AS I "
            "ON I.cid = C.id) AS T "
            "ON T.sid = S.id WHERE S." + QString::fromStdString(columnName) + " LIKE ";
    if(searchString != "male" && searchString != "Male")
    {
        command += "'%" + QString::fromStdString(searchString) + "%'";
    }
    else
    {
        command += "'" + QString::fromStdString(searchString) + "%'";
    }


    query.prepare(command);
    query.exec();

    vector<peopleWithComputers> pepVector = convertPeopleTable(query);

    db.close();

    return pepVector;

}

vector<computersWithPeople> dataFetch::fetchComputers(string columnName, string seartchString)
{
    db.open();
    QSqlQuery query(db);

    QString command = "SELECT * FROM Computers AS C "
            "LEFT JOIN (SELECT * FROM Scientists AS S "
            "LEFT JOIN Invents AS I "
            "ON I.sid = S.id) AS T "
            "ON T.cid = C.id WHERE C." + QString::fromStdString(columnName) + " LIKE '%" + QString::fromStdString(seartchString) + "%'";

    query.prepare(command);
    query.exec();

    vector<computersWithPeople> comVector = convertComputersTable(query);

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
    db.close();

    return connected;
}

bool dataFetch::personAlreadyOnList(const people& person)
{
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists");

    bool onList = false;

    while(query.next())
    {
        string name = query.value("name").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int birth = query.value("birth").toUInt();
        int death = query.value("death").toUInt();

        people personCheck(name, gender, birth, death);
        if (personCheck == person)
            return onList = true;
    }
    db.close();
    return onList;
}

bool dataFetch::computerAlreadyOnList(const computers& computer)
{
    db.open();

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    bool onList = false;

    while(query.next())
    {
        string name = query.value("name").toString().toStdString();
        int yearCreated = query.value("yearCreated").toUInt();
        string type = query.value("type").toString().toStdString();
        bool wasBuilt = query.value("wasBuilt").toUInt();

        computers computerCheck(name, yearCreated, type, wasBuilt);
        if (computerCheck == computer)
            return onList = true;
    }
    db.close();
    return onList;
}

bool dataFetch::editPersonDb(const int &id, const string &name, const string &gender, const int &birth, const int &death, const string &info)
{
    people person(id, name, gender, birth, death, info);
    bool alreadyOnList = personAlreadyOnList(person);
    if(alreadyOnList)
        return false;

    db.open();
    QSqlQuery query(db);
    string comm = "UPDATE Scientists SET name=\"" + name + "\", gender=\"" + gender + "\", birth=" + to_string(birth) + ", death=" + to_string(death) + ", info=\""+ info + "\" WHERE id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    db.close();
    return true;
}

bool dataFetch::editComputerDb(const int &id, const string &name, const int &year, const string &type, const bool &wasBuilt)
{
    db.open();
    computers computer(name, year, type, wasBuilt);
    bool alreadyOnList = computerAlreadyOnList(computer);
    if(alreadyOnList)
        return false;
    QSqlQuery query(db);
    string comm = "UPDATE Computers SET name=\"" + name + "\", yearCreated=" + to_string(year) + ", type=\"" + type + ", wasbuilt=" + to_string(wasBuilt) + " WHERE id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    db.close();
    return true;
}

vector<peopleWithComputers> dataFetch::convertPeopleTable(QSqlQuery& query)
{
    vector<peopleWithComputers> peopleVector;
    int lastId = -1;
    while(query.next())
    {
        bool isDeleted = query.value("isDeleted").toBool();
        
        if (isDeleted) 
        {
            continue;
        }
        
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

            if(currentPersonId == lastId)
            {
                peopleVector.back().creations.push_back(comp);
                continue;
            }
        }

        string Pname = query.value(1).toString().toStdString();
        string Pgender = query.value("gender").toString().toStdString();
        int Pborn = query.value("birth").toUInt();
        int Pdeath = query.value("death").toUInt();
        string Pinfo = query.value("info").toString().toStdString();

        peopleWithComputers per;
        per.p.setName(Pname);
        per.p.setGender(Pgender);
        per.p.setBirth(Pborn);
        per.p.setDeath(Pdeath);
        per.p.setInfo(Pinfo);
        per.p.setId(currentPersonId);
        per.creations.push_back(comp);

        peopleVector.push_back(per);

        lastId = currentPersonId;
    }
    return peopleVector;
}

vector<computersWithPeople> dataFetch::convertComputersTable(QSqlQuery& query)
{
    vector<computersWithPeople> computersVector;
    int lastId = -1;
    while(query.next())
    {
        bool isDeleted = query.value("isDeleted").toBool();

        if (isDeleted)
        {
            continue;
        }

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

            if(currentComputerId == lastId)
            {
                computersVector.back().creators.push_back(per);
                continue;
            }
        }

        computersWithPeople comp;
        string Cname = query.value(1).toString().toStdString();
        int CyearCreated = query.value("yearCreated").toUInt();
        string Ctype = query.value("type").toString().toStdString();
        bool CwasBuilt = query.value("wasBuilt").toUInt();
        string Cinfo = query.value("info").toString().toStdString();

        comp.c.setId(currentComputerId);
        comp.c.setName(Cname);
        comp.c.setYearCreated(CyearCreated);
        comp.c.setType(Ctype);
        comp.c.setWasBuilt(CwasBuilt);
        comp.c.setInfo(Cinfo);
        comp.creators.push_back(per);

        computersVector.push_back(comp);

        lastId = currentComputerId;
    }
    return computersVector;
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

void dataFetch::deletePeople(const int& id)
{
    db.open();
    QSqlQuery query(db);

    string comm = "UPDATE Scientists SET isDeleted = 1 WHERE id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    
    

//    string comm2 = "DELETE FROM Invents WHERE sid = " +to_string(id);
//    QString command2 = QString::fromStdString(comm2);
//    query.prepare(command2);
//    query.exec();

    db.close();
}

void dataFetch::deleteComputer(const int& id)
{
    db.open();
    QSqlQuery query(db);

    string comm = "UPDATE Computers SET isDeleted = 1 WHERE id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();

//    string comm2 = "DELETE FROM Invents WHERE cid = " + to_string(id);
//    QString command2 = QString::fromStdString(comm2);
//    query.prepare(command2);
//    query.exec();

    db.close();
}

bool dataFetch::deleteConnectionDb(const int &sid, const int &cid)
{
    db.open();
    QSqlQuery query(db);

    string comm = "DELETE FROM Invents WHERE sid = " + to_string(sid) + " AND cid = " + to_string(cid);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    db.close();
    return true;
}

void dataFetch::eraseEverything()
{
    db.open();
    QSqlQuery query(db);

    query.prepare("DELETE FROM Scientists");
    query.exec();

    query.prepare("DELETE FROM Computers");
    query.exec();

    query.prepare("DELETE FROM Invents");
    query.exec();

    db.close();
}

void dataFetch::createDatabase()
{
    db.setDatabaseName(constants::NAME_OF_DATABASE);
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

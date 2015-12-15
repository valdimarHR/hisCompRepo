#include "DataFetch/datafetch.h"

dataFetch::dataFetch()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QFile dbfile;
    if(!dbfile.exists(constants::NAME_OF_DATABASE))
    {
        createDatabase();
        return;
    }
    QString dbName = constants::NAME_OF_DATABASE;
    db.setDatabaseName(dbName);
    db.open();
}

dataFetch::~dataFetch()
{
    db.close();
}

vector<peopleWithComputers> dataFetch::fetchPeople(string columnName, string searchString)
{
    QSqlQuery query(db);

    QString command = "SELECT * FROM Scientists AS S "
            "LEFT JOIN (SELECT * FROM Computers AS C "
            "LEFT JOIN Invents AS I "
            "ON I.cid = C.c_id AND I.isDeleted != 1) AS T "
            "ON T.sid = S.s_id WHERE S." + QString::fromStdString(columnName) + " LIKE ";
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


    return pepVector;

}

vector<computersWithPeople> dataFetch::fetchComputers(string columnName, string seartchString)
{
    QSqlQuery query(db);

    QString command = "SELECT * FROM Computers AS C "
            "LEFT JOIN (SELECT * FROM Scientists AS S "
            "LEFT JOIN Invents AS I "
            "ON I.sid = S.s_id AND I.isDeleted != 1) AS T "
            "ON T.cid = C.c_id WHERE C." + QString::fromStdString(columnName) + " LIKE '%" + QString::fromStdString(seartchString) + "%'";

    query.prepare(command);
    query.exec();

    vector<computersWithPeople> comVector = convertComputersTable(query);


    return comVector;

}

bool dataFetch::alreadyConnnected(const int sid, const int cid)
{

    QSqlQuery query(db);

    query.exec("SELECT * FROM Invents");

    bool connected = false;

    //Checks the whole query if connection already exists if it does sets connected = true.
    while(query.next())
    {
        int tableSid = query.value("sid").toUInt();
        int tableCid = query.value("cid").toUInt();
        if ((sid == tableSid)&&(cid == tableCid))
        {
            connected = true;
            editConnectionDb(sid, cid, 0);
            break;
        }
    }

    return connected;
}

bool dataFetch::personAlreadyOnList(const people& person)
{

    QSqlQuery query(db);

    query.exec("SELECT * FROM Scientists");

    bool onList = false;

    //Checks the whole query if a person is already in the DB, sets onList = true if so.
    while(query.next())
    {
        string name = query.value("sName").toString().toStdString();
        string gender = query.value("gender").toString().toStdString();
        int birth = query.value("birth").toUInt();
        int death = query.value("death").toUInt();

        people personCheck(name, gender, birth, death);
        if (personCheck == person)
            return onList = true;
    }
    return onList;
}

bool dataFetch::computerAlreadyOnList(const computers& computer)
{

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    bool onList = false;

    //Checks if computer is already in the DB, sets onList = true if it is.
    while(query.next())
    {
        string name = query.value("cName").toString().toStdString();
        int yearCreated = query.value("yearCreated").toUInt();
        string type = query.value("type").toString().toStdString();
        bool wasBuilt = query.value("wasBuilt").toUInt();

        computers computerCheck(name, yearCreated, type, wasBuilt);
        if (computerCheck == computer)
            return onList = true;
    }
    return onList;
}

bool dataFetch::editPersonDb(const int &id, const string &name, const string &gender, const int &birth, const int &death, const string &info)
{
    QSqlQuery query(db);
    string comm = "UPDATE Scientists SET sName=\"" + name + "\", gender=\"" + gender + "\", birth=" + to_string(birth) + ", death=" + to_string(death) + ", sInfo=\""+ info + "\" WHERE s_id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    return true;
}

bool dataFetch::editComputerDb(const int &id, const string &name, const int &year, const string &type, const bool &wasBuilt, const string &info)
{
    QSqlQuery query(db);
    string comm = "UPDATE Computers SET cName=\"" + name + "\", yearCreated=" + to_string(year) + ", type=\"" + type + "\", wasbuilt=" + to_string(wasBuilt) + ", cInfo=\""+ info + "\" WHERE c_id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    return true;
}

bool dataFetch::editConnectionDb(const int &sid, const int &cid, const bool &isDeleted)
{
    QSqlQuery query(db);
    string comm = "UPDATE Invents SET isDeleted=" + to_string(isDeleted) + " WHERE sid=" + to_string(sid) + " AND cid=" + to_string(cid);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    return true;
}

vector<peopleWithComputers> dataFetch::convertPeopleTable(QSqlQuery& query)
{
    vector<peopleWithComputers> peopleVector;
    int lastId = -1;
    while(query.next())
    {
        bool isDeleted = query.value("sIsDeleted").toBool();
        
        if (isDeleted) 
        {
            continue;
        }
        
        int currentPersonId = query.value("s_id").toUInt();

        computers comp;
        if(query.value("c_id").toUInt() != 0)
        {
            bool connectionDeleted = query.value("isDeleted").toBool();
            if(connectionDeleted) continue;
            int Cid = query.value("c_id").toUInt();
            string Cname = query.value("cName").toString().toStdString();
            int CyearCreated = query.value("yearCreated").toUInt();
            string Ctype = query.value("type").toString().toStdString();
            bool CwasBuilt = query.value("wasBuilt").toUInt();
            string Cinfo = query.value("cInfo").toString().toStdString();

            comp.setId(Cid);
            comp.setName(Cname);
            comp.setYearCreated(CyearCreated);
            comp.setType(Ctype);
            comp.setWasBuilt(CwasBuilt);
            comp.setInfo(Cinfo);

            if(currentPersonId == lastId)
            {
                peopleVector.back().creations.push_back(comp);
                continue;
            }
        }

        string Pname = query.value("sName").toString().toStdString();
        string Pgender = query.value("gender").toString().toStdString();
        int Pborn = query.value("birth").toUInt();
        int Pdeath = query.value("death").toUInt();
        string Pinfo = query.value("sInfo").toString().toStdString();

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
        bool isDeleted = query.value("cIsDeleted").toBool();

        if (isDeleted)
        {
            continue;
        }

        int currentComputerId = query.value("c_id").toUInt();

        people per;
        if(query.value("s_id").toUInt() != 0)
        {
            bool connectionDeleted = query.value("isDeleted").toBool();
            if(connectionDeleted) continue;
            int Pid = query.value("s_id").toUInt();
            string Pname = query.value("sName").toString().toStdString();
            string Pgender = query.value("gender").toString().toStdString();
            int Pborn = query.value("birth").toUInt();
            int Pdeath = query.value("death").toUInt();
            string Pinfo = query.value("sInfo").toString().toStdString();

            per.setId(Pid);
            per.setName(Pname);
            per.setGender(Pgender);
            per.setBirth(Pborn);
            per.setDeath(Pdeath);
            per.setInfo(Pinfo);

            if(currentComputerId == lastId)
            {
                computersVector.back().creators.push_back(per);
                continue;
            }
        }

        computersWithPeople comp;
        string Cname = query.value("cName").toString().toStdString();
        int CyearCreated = query.value("yearCreated").toUInt();
        string Ctype = query.value("type").toString().toStdString();
        bool CwasBuilt = query.value("wasBuilt").toUInt();
        string Cinfo = query.value("cInfo").toString().toStdString();

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

    QSqlQuery query(db);

    int birth = a.getBirth();
    int death = a.getDeath();
    string gender = a.getGender();
    string name = a.getName();

    query.prepare("INSERT INTO Scientists (sName, gender, death, birth) VALUES (:name, :gender, :death, :birth)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":gender", QString::fromStdString(gender));
    query.bindValue(":birth", birth);
    query.bindValue(":death", death );
    query.exec();
}


void dataFetch::insertComputerToDatabase(const computers& c)
{

    QSqlQuery query(db);

    string name = c.getName();
    int yearCreated = c.getYearCreated();
    string type = c.getType();
    bool wasBuilt = c.getWasBuilt();


    query.prepare("INSERT INTO Computers (cName, yearCreated, type, wasBuilt) VALUES (:name, :yearCreated, :type, :wasBuilt)");
    query.bindValue(":name", QString::fromStdString(name));
    query.bindValue(":yearCreated", yearCreated);
    query.bindValue(":type", QString::fromStdString(type));
    query.bindValue(":wasBuilt", wasBuilt );
    query.exec();
}

void dataFetch::insertConnectionToDatabase(const int& sid, const int& cid)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Invents (sid, cid) VALUES (:sid, :cid)");
    query.bindValue(":sid", sid);
    query.bindValue(":cid", cid);
    query.exec();
}

void dataFetch::deletePeople(const int& id)
{
    QSqlQuery query(db);

    string comm = "UPDATE Scientists SET sIsDeleted = 1 WHERE s_id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();

}

void dataFetch::deleteComputer(const int& id)
{
    QSqlQuery query(db);

    string comm = "UPDATE Computers SET cIsDeleted = 1 WHERE c_id = " + to_string(id);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();

}

bool dataFetch::deleteConnectionDb(const int &sid, const int &cid)
{
    QSqlQuery query(db);

    string comm = "UPDATE Invents SET isDeleted = 1 WHERE sid = " + to_string(sid) + " AND cid = " + to_string(cid);
    QString command = QString::fromStdString(comm);
    query.prepare(command);
    query.exec();
    return true;
}

void dataFetch::eraseEverything()
{
    QSqlQuery query(db);

    query.prepare("DELETE FROM Scientists");
    query.exec();

    query.prepare("DELETE FROM Computers");
    query.exec();

    query.prepare("DELETE FROM Invents");
    query.exec();

}

void dataFetch::createDatabase()
{
    db.setDatabaseName(constants::NAME_OF_DATABASE);
    db.open();
    QSqlQuery query(db);

    query.prepare("CREATE TABLE 'Computers' ('c_id' INTEGER PRIMARY KEY  "
                  "NOT NULL ,'cName' VARCHAR NOT NULL ,'yearCreated' "
                  "INTEGER NOT NULL ,'type' VARCHAR NOT NULL ,"
                  "'wasBuilt' BOOL NOT NULL  DEFAULT (null), 'cInfo' TEXT, 'cIsDeleted' BOOL NOT NULL DEFAULT 0)");
    query.exec();

    query.prepare("CREATE TABLE 'Scientists' ('s_id' INTEGER PRIMARY KEY  AUTOINCREMENT  "
                  "NOT NULL , 'sName' VARCHAR NOT NULL , 'gender' VARCHAR NOT NULL , "
                  "'birth' INTEGER NOT NULL , 'death' INTEGER, 'sInfo' TEXT, 'sIsDeleted' BOOL NOT NULL  DEFAULT 0)");
    query.exec();

    query.prepare("CREATE TABLE Invents(sid INTEGER,cid INTEGER, "
                  "'isDeleted' BOOL NOT NULL  DEFAULT 0, "
                  "FOREIGN KEY (sid) REFERENCES Scientists(id),"
                  "FOREIGN KEY (cid) REFERENCES Computers(id) "
                  "PRIMARY KEY (sid, cid))");
    query.exec();
}

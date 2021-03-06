#include "logic.h"

logic::logic()
{

}

vector<peopleWithComputers> logic::allPeopleSorted(int orderBy, int ascending)
{
    vector<peopleWithComputers> sortedVector = theData.fetchPeople("sName", "");

    // Here is a sorting switch dependant on the user input "orderBy" and "ascending".
    // The switch uses sort() with 3 inputs. Start of sort, end of sort,
    // and sort methood using lambda.
    if (orderBy < 5)
    {
        sort(sortedVector.begin(), sortedVector.end(), [](peopleWithComputers const &a, peopleWithComputers const &b)
        {return (a.p.getName() < b.p.getName());});
    }
    switch(orderBy)
    {
    case 1 :
        break;
    case 2 :
        sort(sortedVector.begin(), sortedVector.end(), [](peopleWithComputers const &a, peopleWithComputers const &b)
        {return (a.p.getGender() < b.p.getGender());});
        break;
    case 3 :
        sort(sortedVector.begin(), sortedVector.end(), [](peopleWithComputers const &a, peopleWithComputers const &b)
        {return (a.p.getBirth() < b.p.getBirth());});
        break;
    case 4 :
        sort(sortedVector.begin(), sortedVector.end(), [](peopleWithComputers const &a, peopleWithComputers const &b)
        {
            if(b.p.getDeath() == -1 && a.p.getDeath() != -1)
                return true;
            if(a.p.getDeath() == -1 && b.p.getDeath() != -1)
                return false;
            return (a.p.getDeath() < b.p.getDeath());
         });
         break;
    default :
         break;
    }

    if(!ascending)
        reverse(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}

vector<computersWithPeople> logic::allComputersSorted(int orderBy, int ascending)
{
    vector<computersWithPeople> sortedVector = theData.fetchComputers("cName", "");

    // Here is a sorting switch dependant on the user input "orderBy" and "ascending".
    // The switch uses sort() with 3 inputs. Start of sort, end of sort,
    // and sort methood using lambda.
    if (orderBy < 5)
    {
        sort(sortedVector.begin(), sortedVector.end(), [](computersWithPeople const &a, computersWithPeople const &b)
        {return (a.c.getName() < b.c.getName());});
    }
    switch(orderBy)
    {
    case 1 :
        break;
    case 2 :
        sort(sortedVector.begin(), sortedVector.end(), [](computersWithPeople const &a, computersWithPeople const &b)
        {return (a.c.getType() < b.c.getType());});
        break;
    case 3 :
        sort(sortedVector.begin(), sortedVector.end(), [](computersWithPeople const &a, computersWithPeople const &b)
        {return (a.c.getYearCreated() < b.c.getYearCreated());});
        break;
    case 4 :
        sort(sortedVector.begin(), sortedVector.end(), [](computersWithPeople const &a, computersWithPeople const &b)
        {return (a.c.getWasBuilt() < b.c.getWasBuilt());});
        break;
    default :
        break;
    }
    if(!ascending)
        reverse(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}

bool logic::insertPerson(string& name, string& gender, int& born, int& death)
{
    bool dataExisted = false;
    people per(name,gender,born,death);

    if (checkIfpersonOnList(per))
        dataExisted = true;
    else
        theData.insertPersonToDatabase(per);

    return dataExisted;//Returns true if person is already on the list.
}

bool logic::insertComputer(string& name, int& created, string& type, bool& built)
{
    bool dataExisted = false;
    computers comp(name,created,type,built);

    if (checkIfcomputerOnList(comp))
        dataExisted = true;
    else
        theData.insertComputerToDatabase(comp);

    return dataExisted;//Returns true if computer is already on the list.
}

bool logic::insertConnection(const int& sid, const int& cid)
{
    bool dataExisted;
    if (theData.alreadyConnnected(sid, cid))
        dataExisted = true;
    else
        theData.insertConnectionToDatabase(sid, cid);

    return dataExisted;//Returns true if computer is already on the list.
}

peopleWithComputers logic::getPerson(const int &id)
{
    vector<peopleWithComputers> p = theData.fetchPeople("s_id",to_string(id));
    return p[0];
}

computersWithPeople logic::getComputer(const int &id)
{
    vector<computersWithPeople> c = theData.fetchComputers("c_id",to_string(id));
    return c[0];
}

bool logic::deleteConnection(const int &sid, const int &cid)
{
    bool success = theData.deleteConnectionDb(sid, cid);
    return success;
}

bool logic::editPerson(const people& personCanged)
{
    int id = personCanged.getId();
    string name = personCanged.getName();
    string gender = personCanged.getGender();
    int birth = personCanged.getBirth();
    int death = personCanged.getDeath();
    string info = personCanged.getInfo();

    bool success = theData.editPersonDb(id, name, gender, birth, death, info);
    return success;
}


bool logic::editComputer(const computers& computer)
{
    int id = computer.getId();
    string name = computer.getName();
    int year = computer.getYearCreated();
    string type = computer.getType();
    bool wasBuilt = computer.getWasBuilt();
    string info = computer.getInfo();

    bool success = theData.editComputerDb(id,name,year,type,wasBuilt, info);
    return success;
}

bool logic::checkIfpersonOnList(const people& person)
{
   bool alreadyOnList = theData.personAlreadyOnList(person);
   return alreadyOnList;
}

bool logic::checkIfcomputerOnList(const computers& computer)
{
   bool alreadyOnList = theData.computerAlreadyOnList(computer);
   return alreadyOnList;
}

void logic::eraseChosenPeople(const int& id)
{
    theData.deletePeople(id);
}

void logic::eraseChosenComputer(const int& id)
{
    theData.deleteComputer(id);
}

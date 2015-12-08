#include "logic.h"

logic::logic()
{

}

vector<peopleWithComputers> logic::printerSortPeople(int orderBy, int ascending)
{
    vector<peopleWithComputers> sortedVector = theData.fetchPeople("name", "");

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
    if(!ascending) reverse(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}

vector<computersWithPeople> logic::printerSortComputers(int orderBy, int ascending)
{
    vector<computersWithPeople> sortedVector = theData.fetchComputers("name", "");

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
    if(!ascending) reverse(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}

//Creates a class of people with the user inputted info.
bool logic::insertPerson(string& name, string& gender, int& born, int& death)
{
    bool dataExisted = false;
    people per(name,gender,born,death);

    if (checkIfpersonOnList(per))
        return dataExisted = true;
    else
        theData.insertPersonToDatabase(per);//Adds the people item to the database.

    return dataExisted;//Returns true if person is already on the list.
}


//Creates a class of computer with the user inputted info.
bool logic::insertComputer(string& name, int& created, string& type, bool& built)
{
    bool dataExisted = false;
    computers comp(name,created,type,built);

    if (checkIfcomputerOnList(comp))
        return dataExisted = true;
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

vector<peopleWithComputers> logic::findPeople(string column, string searchValue)
{
    return theData.fetchPeople(column, searchValue);
}

vector<computersWithPeople> logic::findComputer(string column, string searchValue)
{
    return theData.fetchComputers(column, searchValue);
}

vector<people> logic::printerPeople()
{
    vector<people> p;
    theData.fetchPeopleOnly(p);
    return p;
}

vector<computers> logic::printerComputers()
{
    vector<computers> c;
    theData.fetchComputersOnly(c);
    return c;
}

void logic::eraseChosenPeople(const vector<people>& p, const int& index)
{
    int id = p[index-1].getId();
    theData.deletePeople(id);
}

void logic::eraseChosenComputer(const vector<computers>& c, const int& index)
{
    int id = c[index-1].getId();
    theData.deleteComputer(id);
}

void logic::eraseDB()
{
    theData.eraseEverything();
}

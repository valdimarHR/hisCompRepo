#include "logic.h"

logic::logic()
{

}

vector<peopleWithComputers> logic::printerSortPeople(int orderBy, int ascending)
{
    vector<peopleWithComputers> sortedVector = theData.fetchPeople("name", "");

    if (orderBy < 5) sort(sortedVector.begin(), sortedVector.end(), sortPeopleName);
    switch(orderBy)
       {
       case 1 :
          break;
       case 2 :
          sort(sortedVector.begin(), sortedVector.end(), sortPeopleGender);
          break;
       case 3 :
          sort(sortedVector.begin(), sortedVector.end(), sortPeopleBirth);
          break;
       case 4 :
          sort(sortedVector.begin(), sortedVector.end(), sortPeopleDeath);
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

    if (orderBy < 5) sort(sortedVector.begin(), sortedVector.end(), sortComputersName);
    switch(orderBy)
       {
       case 1 :
          break;
       case 2 :
          sort(sortedVector.begin(), sortedVector.end(), sortComputersType);
          break;
       case 3 :
          sort(sortedVector.begin(), sortedVector.end(), sortComputersYear);
          break;
       case 4 :
          sort(sortedVector.begin(), sortedVector.end(), sortComputersBuilt);
          break;
       default :
          break;
       }
    if(!ascending) reverse(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}

bool logic::sortPeopleName(const peopleWithComputers &a, const peopleWithComputers &b)
{
    return (a.p.getName() < b.p.getName());
}

bool logic::sortPeopleGender(const peopleWithComputers& a, const peopleWithComputers& b)
{
    return (a.p.getGender() < b.p.getGender());
}

bool logic::sortPeopleBirth(const peopleWithComputers& a, const peopleWithComputers& b)
{
    return (a.p.getBirth() < b.p.getBirth());
}

bool logic::sortPeopleDeath(const peopleWithComputers& a, const peopleWithComputers& b)
{
    if(b.p.getDeath() == -1 && a.p.getDeath() != -1)
        return true;
    if(a.p.getDeath() == -1 && b.p.getDeath() != -1)
        return false;
    return (a.p.getDeath() < b.p.getDeath());
}

bool logic::sortComputersName(const computersWithPeople &a, const computersWithPeople &b)
{
    return (a.c.getName() < b.c.getName());
}

bool logic::sortComputersType(const computersWithPeople& a, const computersWithPeople& b)
{
    return (a.c.getType() < b.c.getType());
}

bool logic::sortComputersYear(const computersWithPeople& a, const computersWithPeople& b)
{
    return (a.c.getYearCreated() < b.c.getYearCreated());
}

bool logic::sortComputersBuilt(const computersWithPeople& a, const computersWithPeople& b)
{
    return (a.c.getWasBuilt() < b.c.getWasBuilt());
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

    //if (checkIfcomputerOnList(per))
    //    return dataExisted = true;
    //else
        theData.insertComputerToDatabase(comp);//Adds the comp item to the database.

    return dataExisted;//Returns true if computer is already on the list.
}

bool logic::insertConnection(const int& sid, const int& cid)
{

    bool dataExisted;
    if (theData.alreadyConnnected(sid, cid))
        dataExisted = true;
    else
        theData.insertConnectionToDatabase(sid, cid);//Adds the connection to the DB.

    return dataExisted;//Returns true if computer is already on the list.
}

bool logic::checkIfpersonOnList(const people &person) const
{
    //MAKE NEW IMPLEMENTATION
//    bool isOnList = false;
//    int size = listOfPeople.size();
//    for(int i=0; i<size; i++)
//    {
//        if(listOfPeople[i] == person)
//            isOnList = true;
//    }
//    return isOnList;
    return 0;
}

vector<peopleWithComputers> logic::findPeople(string column, string searchValue)
{
    return theData.fetchPeople(column, searchValue);
}

vector<computersWithPeople> logic::findComputerByName(string name)
{
    return theData.fetchComputers("name", name);
}

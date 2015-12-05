#include "logic.h"

logic::logic()
{

}

vector<people> logic::printerSortPeople(int orderBy, int ascending) const
{
    vector<people> sortedVector;// = datafetch.SOMETHING();

    if (orderBy < 5) sort(sortedVector.begin(), sortedVector.end(), sortName);
    switch(orderBy)
       {
       case 1 :
          break;
       case 2 :
          sort(sortedVector.begin(), sortedVector.end(), sortGender);
          break;
       case 3 :
          sort(sortedVector.begin(), sortedVector.end(), sortBirth);
          break;
       case 4 :
          sort(sortedVector.begin(), sortedVector.end(), sortDeath);
          break;
       default :
          break;
       }
    if(!ascending) reverse(sortedVector.begin(), sortedVector.end());

    return sortedVector;
}

bool logic::sortName(const people &a, const people &b)
{
    return (a.getName() < b.getName());
}

bool logic::sortGender(const people& a, const people& b)
{
    return (a.getGender() < b.getGender());
}

bool logic::sortBirth(const people& a, const people& b)
{
    return (a.getBirth() < b.getBirth());
}

bool logic::sortDeath(const people& a, const people& b)
{
    if(b.getDeath() == -1 && a.getDeath() != -1)
        return true;
    if(a.getDeath() == -1 && b.getDeath() != -1)
        return false;
    return (a.getDeath() < b.getDeath());
}
//Creates a class of people with the user inputted info.
bool logic::insertPerson(string& name, string& gender, int& born, int& death)
{
<<<<<<< HEAD
    //NO "listOfPeople" NEEDS NEW IMPLEMENTATION.
    //NO "listOfPeople" NEEDS NEW IMPLEMENTATION.
    //NO "listOfPeople" NEEDS NEW IMPLEMENTATION.
=======
>>>>>>> f93cdba0bcc02bad2285263c9d34b5c7ef7b7eea

    bool dataExisted = false;
    people per;

    per.setName(name);
    per.setGender(gender);
    per.setBirth(born);
    per.setDeath(death);
    if (checkIfpersonOnList(per))
        return dataExisted = true;
    else
        theData.inserPersonToDatabase(per);//Adds the people item to the database.

    return dataExisted;//Returns true if person is already on the list.
}


//Creates a class of people with the user inputted info.
bool logic::insertComputer(string& name, string& type, int& created, bool& built)
{
    return 0;
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

vector<people> logic::findByPeopleName(string name)
{
//    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
//        [&name](const people& per){
//            string objName = per.getName();
//            std::transform(objName.begin(), objName.end(), objName.begin(), ::tolower);
//            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
//            return objName.find(name) != string::npos;
//        });

    vector<people> found;

//    while(it != listOfPeople.end()) {
//        found.push_back(*it);
//        it = find_if(++it, listOfPeople.end(),
//            [&name](const people& per) {
//                string objName = per.getName();
//                std::transform(objName.begin(), objName.end(), objName.begin(), ::tolower);
//                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
//                return objName.find(name) != string::npos;
//            });
//    }

    return found;
}

vector<people> logic::findByPeopleGender(string gender)
{
//    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
//        [&gender](const people& per) {
//            string objGender = per.getGender();
//            std::transform(objGender.begin(), objGender.end(), objGender.begin(), ::tolower);
//            std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
//            return objGender == gender;
//        });

    vector<people> found;

//    while(it != listOfPeople.end()) {
//        found.push_back(*it);
//        it = find_if(++it, listOfPeople.end(),
//            [&gender](const people& per) {
//                string objGender = per.getGender();
//                std::transform(objGender.begin(), objGender.end(), objGender.begin(), ::tolower);
//                std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
//                return objGender == gender;
//            });
//    }

    return found;
}

vector<people> logic::findByPeopleBirth(int birthYear)
{
//    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
//        [&birthYear](const people& per){return per.getBirth() == birthYear;});

    vector<people> found;

//    while(it != listOfPeople.end()) {
//        found.push_back(*it);
//        it = find_if(++it, listOfPeople.end(),
//            [&birthYear](const people& per){return per.getBirth() == birthYear;});
//    }

    return found;
}

vector<people> logic::findByPeopleDeath(int deathYear)
{
//    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
//        [&deathYear](const people& per){return per.getDeath() == deathYear;});

    vector<people> found;

//    while(it != listOfPeople.end()) {
//        found.push_back(*it);
//        it = find_if(++it, listOfPeople.end(),
//            [&deathYear](const people& per){return per.getDeath() == deathYear;});
//    }
    return found;
}

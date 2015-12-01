#include "list.h"
#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

List::List()
{

}

List::List(istream& fin)
{
    string line, year;
    int indexStart, indexEnd;
    people peoplePush;

    while(getline(fin, line))
    {
        indexEnd = line.find(",");
        peoplePush.setName(line.substr(0, indexEnd));
        indexStart = indexEnd + 2;
        indexEnd = line.find("," , indexStart);
        peoplePush.setGender(line.substr(indexStart, (indexEnd-indexStart)));
        indexStart = indexEnd + 2;
        indexEnd = line.find("," , indexStart);
        year = line.substr(indexStart, (indexEnd-indexStart));
        peoplePush.setBirth(stringToInt(year));
        indexStart = indexEnd + 2;
        indexEnd = line.size();
        year = line.substr(indexStart, (indexEnd-indexStart));
        peoplePush.setDeath(stringToInt(year));
        listOfPeople.push_back(peoplePush);
    }
}

void List::Print()
{
    int orderBy;
    char sorted;

    cout << endl << "Printing" << endl
         << "Ordered  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Gender" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;
    cout << "\ta: Asending" << endl
         << "\td: Desending" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> sorted;
    cout << endl;

    for(const auto person:listOfPeople)
        cout << "Name: " << person.getName()
             << " |Gender: " << person.getGender() << endl;

    cout << endl;
}

int List::stringToInt(const string &str)
const
{
    int year = 0, decimals, place = 1;
    char number;
    if (str == "-1")
        return notDead;
    else
    {
        decimals = str.size();
        for (int i = decimals; i > 0; i--)
        {
            number = str[i-1];
            year += (number - '0')*place;
            place *= 10;
        }
        return year;
    }
}

void List::InsertPersonInfo(ostream& outs)
{
    string Name, gender;
    int born, death;
    cout << "Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Gender (please write male or female): ";
    cin >> gender;
    cout << "Year of birth: ";
    cin >> born;
    cout << "Year of death (-1 if still alive): ";
    cin >> death;

    people per;
    per.setName(Name);
    per.setGender(gender);
    per.setBirth(born);
    per.setDeath(death);
    if (checkIfpersonOnList(per))
    {
        cout << "This person was aldready on the list and was therefore not added again."
             << endl;
        return;
    }

    outs << Name << ", " << gender << ", " << born << ", " << death << endl;
    listOfPeople.push_back(per);
}

bool List::checkIfpersonOnList(people person)
{
    bool isOnList = false;
    int size = listOfPeople.size();
    for(int i=0; i<size; i++)
    {
        if(listOfPeople[i] == person)
            isOnList = true;
    }
    return isOnList;
}

void printSearchResult(vector<people>& foundPeople)
{
    if (foundPeople.size() == 0)
        cout << "Search result not found!";
    else {
        for (int i = 0; i < foundPeople.size(); i++) {
            foundPeople[i].printPerson();
        }
    }
}

vector<people> findByName(vector<people>& listOfPeople, string name)
{
    auto it = (find_if(listOfPeople.begin(), listOfPeople.end(), [&name](const people& per){return per.getName() == name;}));

    vector<people> found;

    while(it != listOfPeople.end()) {
        cout << typeid(*it).name() << endl;
        found.push_back(*it);
    }

    return found;
}

vector<people> findByGender(vector<people>& listOfPeople, string gender)
{
    auto it = (find_if(listOfPeople.begin(), listOfPeople.end(), [&gender](const people& per){return per.getGender() == gender;}));

    vector<people> found;

    while(it != listOfPeople.end()) {
        cout << typeid(*it).name() << endl;
        found.push_back(*it);
    }

    return found;
}

vector<people> findByBirth(vector<people>& listOfPeople, int birthYear)
{
    auto it = (find_if(listOfPeople.begin(), listOfPeople.end(), [&birthYear](const people& per){return per.getBirth() == birthYear;}));

    vector<people> found;

    while(it != listOfPeople.end()) {
        cout << typeid(*it).name() << endl;
        found.push_back(*it);
    }

    return found;
}

vector<people> findByDeath(vector<people>& listOfPeople, int deathYear)
{
    auto it = (find_if(listOfPeople.begin(), listOfPeople.end(), [&deathYear](const people& per){return per.getDeath() == deathYear;}));

    vector<people> found;

    while(it != listOfPeople.end()) {
        cout << typeid(*it).name() << endl;
        found.push_back(*it);
    }

    return found;
}

int getSearchAttribute()
{
    int n;

    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Gender" << endl
         << "3. Year of birth" << endl
         << "4. Year of death" << endl
         << "Enter your choice: ";
    cin >> n;

    return n;
}

string getSearchValue()
{
    string value;

    cout << "What would you like to search for?" << endl;
    cin >> value;

    return value;
}

void List::searchPerson(vector<people>& listOfPeople)
{

    int n = getSearchAttribute();

    string searchValue = getSearchValue();
    int searchV = stoi(getSearchValue());

    vector<people> foundPeople;

    switch(n) {
        case 1: {
            foundPeople = findByName(listOfPeople, searchValue);
            break;
        }
        case 2: {
            foundPeople = findByGender(listOfPeople, searchValue);
        }
        case 3: {
            foundPeople = findByBirth(listOfPeople, searchV);
            break;
        }
        case 4: {
            foundPeople = findByDeath(listOfPeople, searchV);
            break;
        }
    }
    printSearchResult(foundPeople);
}



#include "list.h"
#include <stdio.h>

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
        peoplePush.setBirth(stoi(year));
        indexStart = indexEnd + 2;
        indexEnd = line.size();
        year = line.substr(indexStart, (indexEnd-indexStart));
        peoplePush.setDeath(stoi(year));
        listOfPeople.push_back(peoplePush);
    }
}

void List::Print()
{
    int orderBy;
    bool ascending;
    system("cls");

    cout << "* PRINTING *" << endl
         << "Ordered  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Gender" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death" << endl
         << "\t5: As in file" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;

    while(cin.fail() || orderBy > 5 || orderBy < 1) {
            cout << "Invalid choice!" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Try again: ";
            cin >> orderBy;
        }
    system("cls");

    if(orderBy != 2){
        cout << "Do you want this list in ascending or descending order?" << endl
             << "\t0: descending" << endl
             << "\t1: ascending" << endl;
    } else {
        cout << "Do you want this list to be ordered by females or males first?" << endl
             << "\t0: males" << endl
             << "\t1: females" << endl;
    }

    cout << "Enter your choice: ";
    cout.flush();
    cin >> ascending;

    while(cin.fail()) {
            cout << "Invalid choice!" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout << "Try again:";
            cin >> ascending;
        }

    vector<people> sortedList = listOfPeople;

    if (orderBy < 5) sort(sortedList.begin(), sortedList.end(), sortName);
    switch(orderBy)
       {
       case 1 :
          break;
       case 2 :
          sort(sortedList.begin(), sortedList.end(), sortGender);
          break;
       case 3 :
          sort(sortedList.begin(), sortedList.end(), sortBirth);
          break;
       case 4 :
          sort(sortedList.begin(), sortedList.end(), sortDeath);
          break;
        case 5 :
           break;
       default :
          cout << "Invalid input" << endl;
       }
    if(!ascending) reverse(sortedList.begin(), sortedList.end());
    system("cls");

    cout << "+------------------------------------------------------+" << endl;
    printf("|%25s|%10s|%8s|%8s|\n", "NAME", "GENDER", "BIRTH", "DEATH");
    cout << "+------------------------------------------------------+" << endl;
    for(const auto person:sortedList){
        person.printPerson();
    }
    cout << "+------------------------------------------------------+" << endl;
    system("pause");
    system("cls");
}

bool List::sortName(people a, people b)
{
    return (a.getName() < b.getName());
}

bool List::sortGender(people a, people b)
{
    return (a.getGender() < b.getGender());
}

bool List::sortBirth(people a, people b)
{
    return (a.getBirth() < b.getBirth());
}

bool List::sortDeath(people a, people b)
{
    if(b.getDeath() == -1 && a.getDeath() != -1)
        return true;
    if(a.getDeath() == -1 && b.getDeath() != -1)
        return false;
    return (a.getDeath() < b.getDeath());
}

void List::InsertPersonInfo(ostream& outs)
{
    string Name, gender;
    int born, death;
    getInsertedInfo(Name, gender, born, death);

    people per;
    per.setName(Name);
    per.setGender(gender);
    per.setBirth(born);
    per.setDeath(death);
    if (checkIfpersonOnList(per))
    {
        cout << endl << "This person was already on the list and was therefore not added again."
             << endl << endl;
        sleep(3);
        system("cls");
        return;
    }

    outs << Name << ", " << gender << ", " << born << ", " << death << endl;
    listOfPeople.push_back(per);
    cout << endl << "Person was added to the list.";
    sleep(2);
    system("cls");
}

bool List::checkIfpersonOnList(const people &person)
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
        cout << "No search results found!" << endl;
    else {
        cout << "+------------------------------------------------------+" << endl;
        printf("|%25s|%10s|%8s|%8s|\n", "NAME", "GENDER", "BIRTH", "DEATH");
        cout << "+------------------------------------------------------+" << endl;
        for (unsigned long i = 0; i < foundPeople.size(); i++) {
            foundPeople[i].printPerson();
        }
        cout << "+------------------------------------------------------+" << endl;
    }
    system("pause");
    system("cls");
}

vector<people> findByName(vector<people>& listOfPeople, string name)
{
    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
        [&name](const people& per){
            string objName = per.getName();
            std::transform(objName.begin(), objName.end(), objName.begin(), ::tolower);
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            return objName.find(name) != string::npos;
        });

    vector<people> found;

    while(it != listOfPeople.end()) {
        found.push_back(*it);
        it = find_if(++it, listOfPeople.end(),
            [&name](const people& per) {
                string objName = per.getName();
                std::transform(objName.begin(), objName.end(), objName.begin(), ::tolower);
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                return objName.find(name) != string::npos;
            });
    }

    return found;
}

vector<people> findByGender(vector<people>& listOfPeople, string gender)
{
    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
        [&gender](const people& per) {
            string objGender = per.getGender();
            std::transform(objGender.begin(), objGender.end(), objGender.begin(), ::tolower);
            std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
            return objGender == gender;
        });

    vector<people> found;

    while(it != listOfPeople.end()) {
        found.push_back(*it);
        it = find_if(++it, listOfPeople.end(),
            [&gender](const people& per) {
                string objGender = per.getGender();
                std::transform(objGender.begin(), objGender.end(), objGender.begin(), ::tolower);
                std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
                return objGender == gender;
            });
    }

    return found;
}

vector<people> findByBirth(vector<people>& listOfPeople, int birthYear)
{
    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
        [&birthYear](const people& per){return per.getBirth() == birthYear;});

    vector<people> found;

    while(it != listOfPeople.end()) {
        found.push_back(*it);
        it = find_if(++it, listOfPeople.end(),
            [&birthYear](const people& per){return per.getBirth() == birthYear;});
    }

    return found;
}

vector<people> findByDeath(vector<people>& listOfPeople, int deathYear)
{
    auto it = find_if(listOfPeople.begin(), listOfPeople.end(),
        [&deathYear](const people& per){return per.getDeath() == deathYear;});

    vector<people> found;

    while(it != listOfPeople.end()) {
        found.push_back(*it);
        it = find_if(++it, listOfPeople.end(),
            [&deathYear](const people& per){return per.getDeath() == deathYear;});
    }

    return found;
}

int getSearchAttribute()
{
    int n;
    system("cls");

    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Gender" << endl
         << "3. Year of birth" << endl
         << "4. Year of death" << endl
         << "Enter your choice: ";
    cin >> n;
    while (cin.fail() || n < 1 || n > 4) {
            cout << "Invalid choice! Choose again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
    }



    return n;
}

string getStringSearchValue()
{
    string value;

    cout << "What would you like to search for?" << endl;
    cin >> value;

    return value;
}

int getIntSearchValue()
{
    int value;

    cout << "What would you like to search for?" << endl;
    cin >> value;

    while(cin.fail()) {
        cout << "A year can only be a numer! Try again: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> value;
    }

    return value;
}

void List::searchPerson()
{
    int n = getSearchAttribute();

    vector<people> foundPeople;
    switch(n) {
        case 1: {
            string searchValue = getStringSearchValue();
            foundPeople = findByName(listOfPeople, searchValue);
            break;
        }
        case 2: {
            string searchValue = getStringSearchValue();
            foundPeople = findByGender(listOfPeople, searchValue);
            break;
        }
        case 3: {
            int searchValue = getIntSearchValue();
            foundPeople = findByBirth(listOfPeople, searchValue);
            break;
        }
        case 4: {
            int searchValue = getIntSearchValue();
            foundPeople = findByDeath(listOfPeople, searchValue);
            break;
        }
        default: {
            break;
        }
    }

    printSearchResult(foundPeople);

}

void List::eraseListOfVector()
{
    listOfPeople.clear();
}

void List::getInsertedInfo(string& name, string& gender, int& born, int& death)
{
    system("cls");
    cout << "* INSERTING PERSON *" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Gender (please write male or female): ";
    cin >> gender;
    while(!((gender == "female")||(gender == "male")))
    {
        cout << "Invalid choice!" << endl << "Try again: ";
        cin >> gender;
    }
    cout << "Year of birth: ";
    cin >> born;
    while(cin.fail())
    {
        cout << "Invalid choice!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Try again: ";
        cin >> born;
    }
    cout << "Year of death (-1 if still alive): ";
    cin >> death;
    while(cin.fail())
    {
        cout << "Invalid choice!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Try again: ";
        cin >> death;
    }
}

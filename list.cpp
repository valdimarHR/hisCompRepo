#include "list.h"

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

    cout << endl << "Printing" << endl
         << "Ordered  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Gender" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death" << endl
         << "\t5: As in file" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;
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

    for(const auto person:sortedList)
        person.printPerson();

    cout << endl;
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
    return (a.getDeath() < b.getDeath());
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
        cout << endl << "This person was aldready on the list and was therefore not added again."
             << endl << endl;
        return;
    }

    outs << Name << ", " << gender << ", " << born << ", " << death << endl;
    listOfPeople.push_back(per);
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

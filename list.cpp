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

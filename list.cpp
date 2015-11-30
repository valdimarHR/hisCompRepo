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

void List::InsertPerson()
{

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

int List::stringToInt(string str)
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
    cout << "Gender: ";
    cin >> gender;
    cout << "Year of birth: ";
    cin >> born;
    cout << "Year of death (-1 if still alive): ";
    cin >> death;

    outs << Name << ", " << gender << ", " << born << ", " << death << endl;

    /*people per = new people();
    per.setName(Name);
    per.setGender(gender);
    per.setBirth(born);
    per.setDeath(death);*/
}

string getName(istream& fin)
{
    string name, line;

    cout << "Please enter a name: ";
    cin >> name;

    while(getline(fin, line)) {
        if (line.find(name) != string::npos)
            cout << line << endl;
    }

    return name;
}

string getGender(istream& fin)
{
    string gender, line;

    cout << "Please enter a gender (male or female): ";
    cin >> gender;

    while(getline(fin, line)) {
        if (line.find(gender) != string::npos)
            cout << line << endl;
    }

    return gender;
}

int getBirthYear(istream& fin)
{
    int yearOfBirth, line;

    cout << "Please enter year of birth";
    cin >> yearOfBirth;

    while(getline(fin, line)) {
        if (line.find(yearOfBirth) != string::npos)
            cout << line << endl;
    }

    return yearOfBirth;
}

int getDeathYear(istream& fin)
{
    int yearOfDeath, line;

    cout << "Please enter year of death";
    cin >> yearOfDeath;

    while(getline(fin, line)) {
        if (line.find(yearOfDeath) != string::npos)
            cout << line << endl;
    }

    return yearOfDeath;
}


void List::searchPerson()
{
    int n, yearOfBirth, yearOfDeath;
    string name, gender;

    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Gender" << endl
         << "3. Year of birth" << endl
         << "4. Year of death" << endl
         << "Enter your choice: ";
    cin >> n;

    if (n == 1) {
        getName(fin);
    }
    if (n == 2) {
        getGender(fin);
    }
    if (n == 3) {
        getBirthYear(fin);
    }
    if (n == 4) {
        getDeathYear(fin);
    }
}

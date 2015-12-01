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
    bool desending;
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
    system("cls");
    cout << "Do you want this list in descending order?" << endl
         << "\t0: No" << endl
         << "\t1: Yes" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> desending;

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
    if(desending) reverse(sortedList.begin(), sortedList.end());
    system("cls");

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
    string yearOfBirth, line;

    cout << "Please enter year of birth";
    cin >> yearOfBirth;

    while(getline(fin, line)) {
        if (line.find(yearOfBirth) != string::npos)
            cout << line << endl;
    }

    int birthYear = std::stoi(yearOfBirth);

    return birthYear;
}

int getDeathYear(istream& fin)
{
    string yearOfDeath, line;

    cout << "Please enter year of death";
    cin >> yearOfDeath;

    while(getline(fin, line)) {
        if (line.find(yearOfDeath) != string::npos)
            cout << line << endl;
    }

    int deathYear = std::stoi(yearOfDeath);

    return deathYear;
}


void List::searchPerson(istream& fin)
{
    int n;
    string name, gender;
    bool wrong;
    do{
        wrong = false;

        cout << "Would you like to search by" << endl
            << "\t1. Name" << endl
            << "\t2. Gender" << endl
            << "\t3. Year of birth" << endl
            << "\t4. Year of death" << endl
            << "Enter your choice: ";
        cin >> n;

        switch(n)
        {
            case 1:
            {
                getName(fin);
                break;
            }
            case 2:
            {
                getGender(fin);
                break;
            }
            case 3:
            {
                getBirthYear(fin);
                break;
            }
            case 4:
            {
                getDeathYear(fin);
                break;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
                wrong = true;

            }
        }
    }while(wrong);
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
    do
    {
        cout << "Gender (please write male or female): ";
        cin >> gender;
    } while(!((gender == "female")||(gender == "male")));
    cout << "Year of birth: ";
    string yearstr;
    cin >> yearstr;
    born = stoi(yearstr);
    cout << "Year of death (-1 if still alive): ";
    cin >> yearstr;
    death = stoi(yearstr);
}

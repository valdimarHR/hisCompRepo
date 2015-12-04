#include "display.h"
#include "people.h"
#include "constants.h"

Display::Display()
{

}

void Display::printPerson(const people& person) const
{
    string death = to_string(person.getDeath());
    if(person.getDeath() == notDead) death = "Alive";
    printf("|%25s|%10s|%8i|%8s|\n", name.c_str(), gender.c_str(), yearOfBirth, death.c_str());
}

void Display::printVector(const vector<people>& list) const
{
    system("cls");
    cout << "+------------------------------------------------------+" << endl;
    printf("|%25s|%10s|%8s|%8s|\n", "NAME", "GENDER", "BIRTH", "DEATH");
    cout << "+------------------------------------------------------+" << endl;
    for(const auto person:list){
        person.printPerson();
    }
    cout << "+------------------------------------------------------+" << endl;
    system("pause");
    system("cls");
}

void Display::title()
{
    cout << "Welcome to Computer Sciense DB." << endl;
}

int Display::theMenuChoice()
{
    string choicestr;
    int choice;

    cout << "//-------------------------\\\\" << endl
         << "||        MAIN MENU        ||" << endl
         << "||                         ||" << endl
         << "||     1: Insert           ||" << endl
         << "||     2: Search           ||" << endl
         << "||     3: Print            ||" << endl
         << "||     4: Erase Database   ||" << endl
         << "||     5: Exit             ||" << endl
         << "||                         ||" << endl
         << "\\\\-------------------------//" << endl
         << "Enter your choice: ";

    cout.flush();
    cin >> choicestr;
    if (choicestr.size() != 1)
        choice = invalidChoice;
    else
    choice = static_cast<int>(choicestr[0]);
    choice -= '0';
    return choice;
}

void Display::printTree()
{
    cout << "----Merry Christmas!!----" << endl;
    cout << endl;

    int star = 1, size = 10;
    int Height = size / 3, Width = size / 2;

    for(int total = size; total > 0; --total)
    {
        for(int i = (total - 1); i > 0; --i)
            cout << " ";

        for(int j = 0; j < star ; ++j)
            cout << "*";

        star += 2;
        cout << '\n';
    }

    for(int i = 0; i < Height; ++i)
    {
        for(int j = 0; j < (size - (Width - (Width / 2))); ++j)
             cout << " ";

        for(int k = 0; k < Width; ++k)
             cout << "|";

        cout << '\n';
    }

    cout << endl;
}


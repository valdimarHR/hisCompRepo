#include "UI/ui.h"


ui::ui()
{
    choice = 0;
}

bool ui::start()
{
    cout << "Welcome to Computer Sciense DB." << endl;

    do{
        mainMenu();
        menuSwitch();
    }while(choice != 5);

    system("cls");
    cout << "Thank you for your visit, hope to see you again soon." << endl << endl;
    return 0;
}

void ui::mainMenu()
{
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
    cin >> choice;
    inputIntCheck(cin.fail(), choice, 1, 5);
    clear();
}

void ui::menuSwitch()
{
    switch(choice)
    {
        case 1 :
        {
            insertMenu();
            break;
        }
        case 2 :
        {
            searchMenu();
            break;
        }
        case 3 :
        {
            printerMenu();
            break;
        }
        case 4 :
        {
            deleteMenu();
            break;
        }
        default:
        {
            break;
        }
    }
}

void ui::insertMenu()
{
    int n;

    cout << "* INSERT *" << endl << endl;
    cout << "Would you like in insert a:" << endl
         << "\t0. Person" << endl
         << "\t1. Computer" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 0, 1);

    clear();
    if(n == 0) insertMenuPerson();
    else insertMenuComputer();

}

void ui::insertMenuPerson()
{
    string name, gender;
    int born, death;

    cout << "* INSERTING PERSON *" << endl << endl;
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
    inputIntCheck(cin.fail(), born);

    cout << "Year of death (-1 if still alive): ";
    cin >> death;
    inputIntCheck(cin.fail(), death);

    bool exists = theLogic.insertPerson(name, gender, born, death);

    if(exists)
    {
        cout << endl << "This person was already on the list and was therefore not added again."
             << endl << endl;
        sleep(3);
        system("cls");
        return;
    }

    cout << endl << "Person was added to the list.";
    sleep(2);
    system("cls");

}

void ui::insertMenuComputer()
{
    string name, type, builtCheck;
    int created;
    bool built;

    cout << "* INSERTING COMPUTER *" << endl << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Year Created (invented): ";
    cin >> created;
    inputIntCheck(cin.fail(), created);
    cout << "What type of computer: ";
    cin.ignore();
    getline(cin, type);
    cout << "Was it built (Y/N): ";
    cin >> builtCheck;
    built = inputStrToBool(builtCheck);

    bool exists = theLogic.insertComputer(name, created, type, built);

    if(exists)
    {
        cout << endl << "This computer was already on the list and was therefore not added again."
             << endl << endl;
        sleep(3);
        system("cls");
        return;
    }

    cout << endl << "Computer was added to the list.";
    sleep(2);
    system("cls");

}

void ui::searchMenu()
{
    int n;

    cout << "* SEARCH *" << endl;
    cout << "Would you like to search by" << endl
         << "0. Person" << endl
         << "1. Computer" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 0, 1);
    clear();

    if(n == 0) searchMenuPerson();
    else searchMenuComputer();

}

void ui::searchMenuPerson()
{
    //findBy föllin notar ekki lengur "listOfPeople" -> breyta yfir í SQL fyrirspurn í logic.cpp.
    //findBy föllin notar ekki lengur "listOfPeople" -> breyta yfir í SQL fyrirspurn í logic.cpp.
    //findBy föllin notar ekki lengur "listOfPeople" -> breyta yfir í SQL fyrirspurn í logic.cpp.

    int n;

    cout << "* SEARCH PERSON *" << endl;
    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Gender (male or female)" << endl
         << "3. Year of birth" << endl
         << "4. Year of death (write -1 for alive)" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    vector<people> foundPeople;
    switch(n) {
        case 1: {
            string searchValue = getStringSearchValue("What would you like to search for?");
            foundPeople = theLogic.findByPeopleName(searchValue);
            break;
        }
        case 2: {
            string searchValue = getStringSearchValue("What would you like to search for? (male or female)");
            foundPeople = theLogic.findByPeopleGender(searchValue);
            break;
        }
        case 3: {
            int searchValue = getIntSearchValue();
            foundPeople = theLogic.findByPeopleBirth(searchValue);
            break;
        }
        case 4: {
            int searchValue = getIntSearchValue();
            foundPeople = theLogic.findByPeopleDeath(searchValue);
            break;
        }
        default: {
            break;
        }

        if (foundPeople.size() == 0){
            cout << "No search results found!" << endl;
            system("pause");
            system("cls");

        } else {
            printVector(foundPeople);
        }
    }
}

void ui::searchMenuComputer()
{
    //IMPLEMENT....
    //IMPLEMENT....
    //IMPLEMENT....

    int n;

    cout << "* SEARCH COMPUTER *" << endl;
    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Year created" << endl
         << "3. Type" << endl
         << "4. Ever built or not" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    cout << " ... implement swith like in search people ... ";
}

void ui::printerMenu()
{
    int printChoice;
    cout << "* PRINTING *" << endl
         << "Do you want to print:" << endl
         << "\t1: All" << endl
         << "\t2: People only" << endl
         << "\t3: Computers only" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> printChoice;
    inputIntCheck(cin.fail(), printChoice, 1, 3);

    if(printChoice == 1)printerMenuAll();
    else if(printChoice == 2)printerMenuPeople();
    else printerMenuComputers();
    clear();

}

void ui::printerMenuAll()
{
    //IMPLEMENT UI....
    //IMPLEMENT UI....
    //IMPLEMENT UI....
}

void ui::printerMenuPeople()
{
    int orderBy, ascending;
    cout << "* PRINTING PEOPLE *" << endl
         << "Order  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Gender" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death" << endl
         << "\t5: As in file" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;

    inputIntCheck(cin.fail(), orderBy, 1, 5);
    clear();

    if(orderBy != 2){
        cout << "Do you want this list in descending or ascending order?" << endl
             << "\t0: Descending" << endl
             << "\t1: Ascending" << endl;
    } else {
        cout << "Do you want this list to be ordered by males or females first?" << endl
             << "\t0: Males" << endl
             << "\t1: Females" << endl;
    }

    cout << "Enter your choice: ";
    cout.flush();
    cin >> ascending;
    inputIntCheck(cin.fail(), ascending, 0, 1);

    vector<people> sortedVector = theLogic.printerSortPeople(orderBy, ascending);
    printVector(sortedVector);
}

void ui::printerMenuComputers()
{
    int orderBy, ascending;
    cout << "* PRINTING COMPUTERS *" << endl
         << "Order  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Type" << endl
         << "\t3: Year of Creation" << endl
         << "\t4: Whether it was Built" << endl
         << "\t5: As in file" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;
    
    inputIntCheck(cin.fail(), orderBy, 1, 5);
    clear();
    
    if (orderBy != 4) {
        cout << "Do you this lest in ascending or descending order?" << endl
             << "\t0: descending" << endl
             << "\t1: ascending" << endl;
    }
    else {
        cout << "Do you want this list to be ordered by whether it was built or not built first" << endl
             << "\t0: built" << endl
             << "\t1: not built" << endl;
    }
    
    cout << "Enter your choice: ";
    cout.flush();
    cin >> ascending;

    inputIntCheck(cin.fail(), orderBy, 1, 5);
    clear();

    if (orderBy != 4) {
        cout << "Do you this list in descending or ascending order?" << endl
             << "\t0: Descending" << endl
             << "\t1: Ascending" << endl;
    }
    else {
        cout << "Do you want this list to be ordered by whether it was built or not built first" << endl
             << "\t0: Built" << endl
             << "\t1: Not built" << endl;
    }

    cout << "Enter your choice: ";
    cout.flush();
    cin >> ascending;
    inputIntCheck(cin.fail(), ascending, 0, 1);
}

void ui::deleteMenu()
{
    //IMPLEMENT UI....
    //IMPLEMENT UI....
    //IMPLEMENT UI....
}

void ui::printVector(const vector<people>& list) const
{
    clear();
    cout << "+------------------------------------------------------+" << endl;
    printf("|%25s|%10s|%8s|%8s|\n", "NAME", "GENDER", "BIRTH", "DEATH");
    cout << "+------------------------------------------------------+" << endl;
    for(const auto person:list){
        string name = person.getName();
        string gender = person.getGender();
        int yearOfBirth = person.getBirth();
        string death = to_string(person.getDeath());
        if(person.getDeath() == constants::notDead) death = "Alive";
        printf("|%25s|%10s|%8i|%8s|\n", name.c_str(), gender.c_str(), yearOfBirth, death.c_str());
    }
    cout << "+------------------------------------------------------+" << endl;
    system("pause");
    clear();
}

string ui::getStringSearchValue(string question)
{
    string value;

    cout << question << endl;
    cin >> value;

    return value;
}

int ui::getIntSearchValue()
{
    int value;

    cout << "What would you like to search for?" << endl;
    cin >> value;

    inputIntCheck(cin.fail(), value);

    return value;
}

void ui::inputIntCheck(bool inputFail, int& var)
{
    while(inputFail)
    {
        cout << "Input needs to be an integer." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Try again: ";
        cin >> var;
        inputFail = cin.fail();
    }
}

void ui::inputIntCheck(bool inputFail, int& var, int low, int high)
{
    while(inputFail || var < low || var > high)
    {
        cout << "Input needs to be an integer and within range." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Try again: ";
        cin >> var;
        inputFail = cin.fail();
    }
}

bool ui::inputStrToBool(string& built)
{
    do
    {
    if (built == "Y" || built == "y" || built == "Yes" || built == "yes" )
        return true;
    else if (built == "N" || built == "n" || built == "No" || built == "no")
        return false;
    else
        cout << "Invalid input!" << endl
             << "Try again: ";
        cin.clear();
        cin >> built;
    }while(true);
}

void ui::printTree()const
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

void ui::clear() const
{
    #ifdef Q_OS_WIN32 //All Windows versions
        system("cls");
    #else //In any other OS
        system("clear");
    #endif
}

